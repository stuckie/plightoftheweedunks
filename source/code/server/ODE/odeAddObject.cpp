#include "odeCore.h"
#include "typedefs.h"
#include "CDebug.h"
#include "OEvent.h"
#include "CInterpret.h"
#include "utMath.h"

int odeWorld::createStaticPlaneGeom(const dReal _a, const dReal _b, const dReal _c, const dReal _d, const EodeOA _odeeo)                  // create static solid plane geometry
{
    dGeomID tmpGeomID = dCreatePlane(mStaticGeomSpace, _a, _b, _c, _d);
    mStaticGeoms.push_back(tmpGeomID);
    mStaticOAs.push_back(_odeeo);

#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createStaticPlaneGeom Material Type was %s\n", _odeeo.c_str());
#endif
    return mStaticGeoms.size()-1;
}

int odeWorld::createStaticBoxGeom(const SGZVECTOR _size, const SGZVECTOR _pos,  const SGZVECTOR _rot, const EodeOA _odeeo)           // create static solid box geometry
{
    dGeomID tmpGeomID = dCreateBox(mStaticGeomSpace, _size.x, _size.y, _size.z);
    dGeomSetPosition(tmpGeomID, _pos.x, _pos.y, _pos.z);
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, _rot.x, _rot.y, _rot.z);
    dGeomSetRotation(tmpGeomID, rotMat);

    mStaticGeoms.push_back(tmpGeomID);
    mStaticOAs.push_back(_odeeo);

#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createStaticBoxGeom Material Type was %s\n", _odeeo.c_str());
#endif
    return mStaticGeoms.size()-1;
}

int odeWorld::createStaticSphereGeom(const dReal _r, const SGZVECTOR _pos,  const EodeOA _odeeo)               // create static solid sphere geometry
{
    dGeomID tmpGeomID = dCreateSphere(mStaticGeomSpace, _r);
    dGeomSetPosition(tmpGeomID, _pos.x, _pos.y, _pos.z);
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, 0, 0, 0);
    dGeomSetRotation(tmpGeomID, rotMat);

    mStaticGeoms.push_back(tmpGeomID);
    mStaticOAs.push_back(_odeeo);

#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createStaticSphereGeom Material Type was %s\n", _odeeo.c_str());
#endif
    return mStaticGeoms.size()-1;
}

int odeWorld::createMovingPlaneGeom(const dReal _a, const dReal _b, const dReal _c, const dReal _d, const EodeOA _odeeo)                  // create Moving solid plane geometry
{
    dGeomID tmpGeomID = dCreatePlane(mStaticGeomSpace, _a, _b, _c, _d);
    mMovingGeoms.push_back(tmpGeomID);
    mMovingOAs.push_back(_odeeo);
    mMovingSize.push_back(SGZVECTOR(0,0,0));
    mMovingOriginalPos.push_back(SGZVECTOR(0,0,0));

#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createMovingPlaneGeom Material Type was %s\n", _odeeo.c_str());
#endif
    return mMovingGeoms.size()-1;
}

int odeWorld::createMovingBoxGeom(const SGZVECTOR _size, const SGZVECTOR _pos, const SGZVECTOR _rot, const EodeOA _odeeo)           // create Moving solid box geometry
{
    dGeomID tmpGeomID = dCreateBox(mStaticGeomSpace, _size.x, _size.y, _size.z);
    dGeomSetPosition(tmpGeomID, _pos.x, _pos.y, _pos.z);
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, _rot.x, _rot.y, _rot.z);
    dGeomSetRotation(tmpGeomID, rotMat);

    mMovingGeoms.push_back(tmpGeomID);
    mMovingOAs.push_back(_odeeo);
    mMovingSize.push_back(_size);
    mMovingOriginalPos.push_back(_pos);
#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createMovingBoxGeom Material Type was %s\n", _odeeo.c_str());
#endif

    return mMovingGeoms.size()-1;
}

int odeWorld::createMovingSphereGeom(const dReal _r, const SGZVECTOR _pos,  const EodeOA _odeeo)                      // create Moving solid sphere geometry
{
    dGeomID tmpGeomID = dCreateSphere(mStaticGeomSpace, _r);
    dGeomSetPosition(tmpGeomID, _pos.x, _pos.y, _pos.z);
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, 0, 0, 0);
    dGeomSetRotation(tmpGeomID, rotMat);

    mMovingGeoms.push_back(tmpGeomID);
    mMovingOAs.push_back(_odeeo);
    mMovingSize.push_back(SGZVECTOR(_r,_r,_r));
    mMovingOriginalPos.push_back(_pos);
#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createMovingSphereGeom Material Type was %s\n", _odeeo.c_str());
#endif

    // returns the number for the first object, the one for the moving object will always be this +1
    return mMovingGeoms.size()-1;
}

int odeWorld::createDynamicBox(const SGZVECTOR _size, const SGZVECTOR _pos, const SGZVECTOR _rot, const dReal _mass, const EodeOA _odeeo)    // create physics controled solid box geometry
{
    // create the object
    dGeomID tmpGeomStaticID = dCreateBox(mDynamicGeomSpace, _size.x, _size.y, _size.z);
    dBodyID tmpBodyID = dBodyCreate(mPhysicsWorld);
    dGeomSetBody(tmpGeomStaticID, tmpBodyID);
    dGeomSetPosition(tmpGeomStaticID, _pos.x, _pos.y, _pos.z);
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, _rot.x, _rot.y, _rot.z);
    dGeomSetRotation(tmpGeomStaticID, rotMat);

    // set the mass of the body
    dMass *tmpMass = new dMass();
    dMassSetBoxTotal(tmpMass, _mass, _size.x, _size.y, _size.z);
    dBodySetMass(tmpBodyID, tmpMass);
    dBodySetAutoDisableFlag(tmpBodyID, 0);

#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createDynamicBox Material Type was %s\n", _odeeo.c_str());
#endif

    if (mDynamicsToReuse.size() > 0)
    {
        unsigned int tmp = mDynamicsToReuse[mDynamicsToReuse.size() - 1];
        mDynamicsToReuse.pop_back();
        // commit the object to the lists
        mObjectGeoms[tmp] = tmpGeomStaticID;
        mObjectOAs[tmp] = _odeeo;
        mObjectBodys[tmp] = tmpBodyID;
        mObjectMass[tmp] = tmpMass;
        mOffSet[tmp] = SGZVECTOR();
        mDynamicSize[tmp] = _size;
        // returns the number for the first object, the one for the moving object will always be this +1
        return tmp;

    }
    else
    {
        // commit the object to the lists
        mObjectGeoms.push_back(tmpGeomStaticID);
        mObjectOAs.push_back(_odeeo);
        mObjectBodys.push_back(tmpBodyID);
        mObjectMass.push_back(tmpMass);
        mOffSet.push_back(SGZVECTOR());
        mDynamicSize.push_back(_size);
        // returns the number for the first object, the one for the moving object will always be this +1
        return mObjectGeoms.size()-1;
    }
}

int odeWorld::createDynamicSphere(const dReal _r, const SGZVECTOR _pos,  const dReal _mass, const EodeOA _odeeo)               // create physics controled solid sphere geometry
{
    dGeomID tmpGeomStaticID;
    dBodyID tmpBodyID = dBodyCreate(mPhysicsWorld);

    // create the object in the static world
    tmpGeomStaticID = dCreateSphere(mDynamicGeomSpace, _r);
    dGeomSetBody(tmpGeomStaticID, tmpBodyID);
    dGeomSetPosition(tmpGeomStaticID, _pos.x, _pos.y, _pos.z);
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, 0, 0, 0);
    dGeomSetRotation(tmpGeomStaticID, rotMat);

    // set the mass of the body
    dMass *tmpMass = new dMass();
    dMassSetSphereTotal(tmpMass, _mass, _r);
    dBodySetMass(tmpBodyID, tmpMass);
    dBodySetAutoDisableFlag(tmpBodyID, 0);

#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createDynamicSphere Material Type was %s\n", _odeeo.c_str());
#endif
    if (mDynamicsToReuse.size() > 0)
    {
        unsigned int tmp = mDynamicsToReuse[mDynamicsToReuse.size() - 1];
        mDynamicsToReuse.pop_back();
        // commit the object to the lists
        mObjectGeoms[tmp] = tmpGeomStaticID;
        mObjectOAs[tmp] = _odeeo;
        mObjectBodys[tmp] = tmpBodyID;
        mObjectMass[tmp] = tmpMass;
        mOffSet[tmp] = SGZVECTOR();
        mDynamicSize[tmp] = SGZVECTOR(_r, _r, _r);
        // returns the number for the first object, the one for the moving object will always be this +1
        return tmp;
    }
    else
    {
        // commit the object to the lists
        mObjectGeoms.push_back(tmpGeomStaticID);
        mObjectOAs.push_back(_odeeo);
        mObjectBodys.push_back(tmpBodyID);
        mObjectMass.push_back(tmpMass);
        mOffSet.push_back(SGZVECTOR());
        mDynamicSize.push_back(SGZVECTOR(_r, _r, _r));
        // returns the number for the first object, the one for the moving object will always be this +1
        return mObjectGeoms.size()-1;
    }
}

int odeWorld::createDynamicCapsule(const float _r, const float _h, const SGZVECTOR _pos,  const dReal _mass, const EodeOA _odeeo)
{
    // create the object
    float realH = _h - (2.0f*_r);
    if (realH<0.001f)
        realH=0.001f;
    dGeomID tmpGeomStaticID = dCreateCapsule(mDynamicGeomSpace, _r, realH);
    dBodyID tmpBodyID = dBodyCreate(mPhysicsWorld);
    dGeomSetBody(tmpGeomStaticID, tmpBodyID);
    dGeomSetPosition(tmpGeomStaticID, _pos.x, _pos.y, _pos.z);
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, 0, 0, 0);
    dGeomSetRotation(tmpGeomStaticID, rotMat);

    // set the mass of the body
    dMass *tmpMass = new dMass();
    dMassSetCapsuleTotal(tmpMass, _mass, 2, _r, realH);
    dBodySetMass(tmpBodyID, tmpMass);
    dBodySetAutoDisableFlag(tmpBodyID, 0);

#ifdef SHOW_PHYSICS_PROPS
    SGZLogger.debug("createDynamicCapsule Material Type was %s\n", _odeeo.c_str());
#endif

    if (mDynamicsToReuse.size() > 0)
    {
        unsigned int tmp = mDynamicsToReuse[mDynamicsToReuse.size() - 1];
        mDynamicsToReuse.pop_back();
        mObjectGeoms[tmp] = tmpGeomStaticID;
        mObjectOAs[tmp] = _odeeo;
        mObjectBodys[tmp] = tmpBodyID;
        mObjectMass[tmp] = tmpMass;
        mOffSet[tmp] = SGZVECTOR();
        mDynamicSize[tmp] = SGZVECTOR(_r, realH, 0);
        return tmp;
    }
    else
    {
        mObjectGeoms.push_back(tmpGeomStaticID);
        mObjectOAs.push_back(_odeeo);
        mObjectBodys.push_back(tmpBodyID);
        mObjectMass.push_back(tmpMass);
        mOffSet.push_back(SGZVECTOR());
        mDynamicSize.push_back(SGZVECTOR(_r, realH, 0));
        return mObjectGeoms.size()-1;
    }
}

int odeWorld::createJumpRay(const float _l, const SGZVECTOR _pos, const dGeomID _ignore)
{
    jumpRayDataStruct tmp;
    tmp.geom = dCreateRay(mjumpRayWorld, _l);
    dGeomRaySet(tmp.geom, _pos.x, _pos.y, _pos.z, 0, -1, 0);
    tmp.hasHit = false;
    tmp.hitDepth = 9999.9f;
    tmp.ignore = _ignore;
    mJumpRays.push_back(tmp);

    return mJumpRays.size()-1;
}


