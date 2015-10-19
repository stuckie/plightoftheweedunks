#include "odeCore.h"
#include "typedefs.h"
#include "CDebug.h"
#include "OEvent.h"
#include "CInterpret.h"

void odeWorld::staticCollisionCallback (void *_pData, const dGeomID _o1, const dGeomID _o2)
{
    odeWorld* pThis = (odeWorld*) _pData;
    pThis->collisionCallback (_o1, _o2);
}

void odeWorld::collisionCallback (const dGeomID _o1, const dGeomID _o2)
{
    if (dCollide (_o1, _o2, 1, &mLastContact.geom, sizeof(dContact)) <= 0)
        return;

    // get details about the two objects colliding
    mLastObjColishion[0] = geomInList(_o1);
    mLastObjColishion[1] = geomInList(_o2);

    // check the bodys connected to the genoms arn't jointed
    if (mLastObjColishion[0].list == ODE_DYNAMIC && mLastObjColishion[1].list == ODE_DYNAMIC)
        dAreConnected((dBodyID)mObjectBodys[mLastObjColishion[0].id], (dBodyID)mObjectBodys[mLastObjColishion[1].id]);

    int cmpVal = strcmp(mLastObjColishion[0].oa.c_str(), mLastObjColishion[1].oa.c_str());
    std::string callFunction;

    if (cmpVal <= 0)
        callFunction = mLastObjColishion[0].oa + "Hits" + mLastObjColishion[1].oa;
    else
        callFunction = mLastObjColishion[1].oa + "Hits" + mLastObjColishion[0].oa;

    SGZInterpret.accessScript()->CallFunctionNoError(callFunction.c_str());
    /*if (SGZInterpret.accessScript()->CallFunctionNoError(callFunction.c_str()) == false)
        SGZLogger.debug("function for collision wasn't found or isn't correct- %s\n", callFunction.c_str());
*/
}

void odeWorld::staticRayCollisionCallback (void *_pData, const dGeomID _o1, const dGeomID _o2)
{
    odeWorld* pThis = (odeWorld*) _pData;
    pThis->rayCollisionCallback (_o1, _o2);
}

void odeWorld::rayCollisionCallback (const dGeomID _o1, const dGeomID _o2)
{
    dContact contact;
    if (dCollide (_o1, _o2, 1, &contact.geom, sizeof(dContact)) <= 0)
        return;
    // get details about the two objects colliding
    int index1 = findRayIndex(_o1);
    int index2 = findRayIndex(_o2);
    int index;
    dGeomID hitID;

    if (index1 < 0 && index2<0)
        return;
    else if (index1>=0)
    {
        ODEobjectDetails objDetails = geomInList(_o2);
        for (unsigned int cnt=0; cnt< mNoJumpMaterials.size(); cnt++)
        {
            if (strcmp(objDetails.oa.c_str(), mNoJumpMaterials[cnt].c_str()) == 0)
                return;
        }
        index = index1;
        hitID = _o2;
    }
    else
    {
        ODEobjectDetails objDetails = geomInList(_o1);
        for (unsigned int cnt=0; cnt< mNoJumpMaterials.size(); cnt++)
        {
            if (strcmp(objDetails.oa.c_str(), mNoJumpMaterials[cnt].c_str()) == 0)
                return;
        }
        index = index2;
        hitID = _o1;
    }

    if (mJumpRays[index].ignore == hitID)
        return;

    mJumpRays[index].hasHit = true;
    dVector3 pos, dir;
    dGeomRayGet(mJumpRays[index].geom, pos, dir);
    mJumpRays[index].hitDepth = pos[1] - contact.geom.pos[1];
}


void odeWorld::hit(void)
{
    dBodyID b1 = dGeomGetBody(mLastObjColishion[0].geom);
    dBodyID b2 = dGeomGetBody(mLastObjColishion[1].geom);

    mLastContact.surface.mode = dContactBounce;
    mLastContact.surface.bounce = 0;

    dJointID c = dJointCreateContact (mPhysicsWorld, mCollisionJointGroup, &mLastContact);
    dJointAttach (c,b1,b2);
}

void odeWorld::bounce(const float _friction, const float _bounce, const float _minV)
{
    dBodyID b1 = dGeomGetBody(mLastObjColishion[0].geom);
    dBodyID b2 = dGeomGetBody(mLastObjColishion[1].geom);

    dContact contact;

    contact.surface.mode = dContactBounce | dContactApprox1_1;
    if (_friction >= 0.0f)
        contact.surface.mu = _friction;
    else
        contact.surface.mu = dInfinity;
    contact.surface.bounce = _bounce;
    contact.surface.bounce_vel = _minV;
    contact.surface.soft_cfm = 0.001f;

    if (dCollide (mLastObjColishion[0].geom, mLastObjColishion[1].geom, 1, &contact.geom, sizeof(dContact)) > 0)
    {
        dJointID c = dJointCreateContact (mPhysicsWorld, mCollisionJointGroup, &contact);
        dJointAttach (c,b1,b2);
    }
}

void odeWorld::applyHitForce(const SGZVECTOR _f)
{
    dBodyID b1 = dGeomGetBody(mLastObjColishion[0].geom);
    dBodyID b2 = dGeomGetBody(mLastObjColishion[1].geom);

    if (b1)
        dBodyAddForce(b1, _f.x, _f.y, _f.z);
    if (b2)
        dBodyAddForce(b2, _f.x, _f.y, _f.z);
}

void odeWorld::applyHitForce(const int _notHit, const float _f)
{
    dBodyID b1 = dGeomGetBody(mLastObjColishion[0].geom);
    dBodyID b2 = dGeomGetBody(mLastObjColishion[1].geom);

    const dReal* g1Pos = dGeomGetPosition(mLastObjColishion[0].geom);
    const dReal* g2Pos = dGeomGetPosition(mLastObjColishion[1].geom);

    SGZVECTOR fV;

    fV.x = g2Pos[0] - g1Pos[0];
    fV.y = g2Pos[1] - g1Pos[1];
    fV.z = g2Pos[2] - g1Pos[2];

    float m = sqrt(fV.x*fV.x + fV.y*fV.y + fV.z*fV.z);

    fV.x /= m;
    fV.y /= m;
    fV.z /= m;

    fV.x *= _f;
    fV.y *= _f;
    fV.z *= _f;

    if (b1 && b1!=mObjectBodys[_notHit])
        dBodyAddForce(b1, -fV.x, -fV.y, -fV.z);
    if (b2 && b2!=mObjectBodys[_notHit])
        dBodyAddForce(b2, fV.x, fV.y, fV.z);
}

int odeWorld::KillerHit(const int _notKill)
{
    dBodyID b1 = dGeomGetBody(mLastObjColishion[0].geom);
    dBodyID b2 = dGeomGetBody(mLastObjColishion[1].geom);
    dBodyID dontKill;

    if (_notKill>=0)
        dontKill = mObjectBodys[_notKill];
    else
        dontKill = (dBodyID)-1;

    int id = -1;

    if (b1 && dontKill!=b1)
    {
        ODEobjectDetails tmp = geomInList(mLastObjColishion[0].geom);
        if (killDynamic(tmp.id))
            id = tmp.id;
    }
    if (b2 && dontKill!=b2)
    {
        ODEobjectDetails tmp = geomInList(mLastObjColishion[1].geom);
        killDynamic(tmp.id);
        if (killDynamic(tmp.id))
            id = tmp.id;
    }

    return id;
}

SGZVECTOR odeWorld::GetPointOfContact(void)
{
    return SGZVECTOR(mLastContact.geom.pos[0], mLastContact.geom.pos[1], mLastContact.geom.pos[2]);
}

void odeWorld::hitKillVVel(void)
{
    if (dGeomGetBody(mLastObjColishion[0].geom))
    {
        ODEobjectDetails tmp = geomInList(mLastObjColishion[0].geom);
        killVVel(tmp.id);
    }
    if (dGeomGetBody(mLastObjColishion[1].geom))
    {
        ODEobjectDetails tmp = geomInList(mLastObjColishion[1].geom);
        killVVel(tmp.id);
    }
}

int odeWorld::getDynamicID(void)
{
    if (mLastObjColishion[0].list == ODE_DYNAMIC)
    {
        return mLastObjColishion[0].id;
    }
    return mLastObjColishion[1].id;
}
