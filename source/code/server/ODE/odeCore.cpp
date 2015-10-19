#include "odeCore.h"
#include "typedefs.h"
#include "CDebug.h"
#include "OEvent.h"
#include "CInterpret.h"

bool odeWorld::init(void)
{
    // start ode
    dInitODE();

    // create the worlds
    mPhysicsWorld = dWorldCreate();
    mDynamicGeomSpace = dHashSpaceCreate (0);
    mStaticGeomSpace = dHashSpaceCreate (0);
    mjumpRayWorld = dHashSpaceCreate (0);
    mCollisionJointGroup = dJointGroupCreate(0);

    mPaused = false;
    mPhysicsStepsPerFrame = 5;
    return true;
}

bool odeWorld::kill(void)
{
    mNoJumpMaterials.clear();
    mJumpRays.clear();
    mDeadDynamics.clear();
    mStaticOAs.clear();
    mMovingOAs.clear();
    mObjectOAs.clear();
    mOffSet.clear();
    mMovingSize.clear();
    mDynamicSize.clear();
    mDynamicsToKill.clear();
    mMovingsToKill.clear();
    mObjectMass.clear();
    mDynamicsToReuse.clear();
    mMovingOriginalPos.clear();

    for (unsigned int cnt = 0; cnt< mStaticGeoms.size(); cnt++)
        dGeomDestroy(mStaticGeoms[cnt]);
    mStaticGeoms.clear();
    for (unsigned int cnt = 0; cnt< mMovingGeoms.size(); cnt++)
        dGeomDestroy(mMovingGeoms[cnt]);
    mMovingGeoms.clear();
    for (unsigned int cnt = 0; cnt< mObjectGeoms.size(); cnt++)
    {
        if (mObjectGeoms[cnt] != NULL)
            dGeomDestroy(mObjectGeoms[cnt]);
    }
    mObjectGeoms.clear();

    for (unsigned int cnt = 0; cnt< mObjectBodys.size(); cnt++)
    {
        if (mObjectBodys[cnt] != NULL)
            dBodyDestroy(mObjectBodys[cnt]);
    }
    mObjectBodys.clear();

    dJointGroupEmpty(mCollisionJointGroup);
    dWorldDestroy(mPhysicsWorld);
    dSpaceDestroy(mDynamicGeomSpace);
    dSpaceDestroy(mStaticGeomSpace);
    dSpaceDestroy(mjumpRayWorld);

    dCloseODE();
    return true;
}

bool odeWorld::runFrame(void)
{
    if (mPaused == true)
        return true;

    for (unsigned int cnt=0; cnt< mJumpRays.size(); cnt++)  // reset all jumps rays to show jumps can't be done unless collishions happen
    {
        mJumpRays[cnt].hasHit = false;
        mJumpRays[cnt].hitDepth = 9999.9f;
    }

    for (int cnt=0; cnt<mPhysicsStepsPerFrame ; cnt++)  // loop multiple times for each frame, prevents
    {
        dSpaceCollide(mDynamicGeomSpace, this, staticCollisionCallback);        // check which dynamic objects hit each other
        dSpaceCollide2((dGeomID)mDynamicGeomSpace, (dGeomID)mStaticGeomSpace, this, staticCollisionCallback); // check which dynamic objects hit static objects

        dWorldStep(mPhysicsWorld, (1.0/SGZ_FRAME_LOCK)/(dReal)mPhysicsStepsPerFrame);

        dJointGroupEmpty(mCollisionJointGroup);
    }
    // check and set for if jump rays hit stuff
    dSpaceCollide2((dGeomID)mjumpRayWorld, (dGeomID)mStaticGeomSpace, this, staticRayCollisionCallback);
    dSpaceCollide2((dGeomID)mjumpRayWorld, (dGeomID)mDynamicGeomSpace, this, staticRayCollisionCallback);

    for (unsigned int cnt=0; cnt< mDynamicsToKill.size(); cnt++)
    {
        if (mObjectBodys[mDynamicsToKill[cnt]] == NULL || mObjectGeoms[mDynamicsToKill[cnt]] == NULL)
            continue;
        else if (dSpaceQuery(mDynamicGeomSpace, mObjectGeoms[mDynamicsToKill[cnt]]) != 0)
        {
            dSpaceRemove(mDynamicGeomSpace, mObjectGeoms[mDynamicsToKill[cnt]]);
            dBodyDestroy(mObjectBodys[mDynamicsToKill[cnt]]);
            dGeomDestroy(mObjectGeoms[mDynamicsToKill[cnt]]);
            mObjectGeoms[mDynamicsToKill[cnt]] = NULL;
            mObjectBodys[mDynamicsToKill[cnt]] = NULL;
            mDynamicsToReuse.push_back(mDynamicsToKill[cnt]);
        }
    }
    mDynamicsToKill.clear();
    for (unsigned int cnt=0; cnt< mMovingsToKill.size(); cnt++)
    {
        dGeomSetPosition(mMovingGeoms[mMovingsToKill[cnt]], 99999,99999,99999);
        if (dSpaceQuery(mStaticGeomSpace, mMovingGeoms[mMovingsToKill[cnt]]) != 0)
            dSpaceRemove(mStaticGeomSpace, mMovingGeoms[mMovingsToKill[cnt]]);
    }
    mMovingsToKill.clear();

    return true;
}

ODEobjectDetails odeWorld::geomInList(const dGeomID _in)
{
    for (unsigned int cnt=0; cnt< mStaticGeoms.size(); cnt++)
    {
        if (_in == (dGeomID)mStaticGeoms[cnt])
            return ODEobjectDetails(cnt, mStaticOAs[cnt], ODE_SOLID, _in);
    }
    for (unsigned int  cnt=0; cnt< mMovingGeoms.size(); cnt++)
    {
        if (_in == (dGeomID)mMovingGeoms[cnt])
            return ODEobjectDetails(cnt, mMovingOAs[cnt], ODE_ANIMATED, _in);
    }
    for (unsigned int  cnt=0; cnt< mObjectGeoms.size(); cnt++)
    {
        if (_in == (dGeomID)mObjectGeoms[cnt])
            return ODEobjectDetails(cnt, mObjectOAs[cnt], ODE_DYNAMIC, _in);
    }

    return ODEobjectDetails(-1, "None", ODE_NONE, _in);
}

int odeWorld::findRayIndex(const dGeomID _in)
{
    for (unsigned int cnt=0; cnt< mJumpRays.size(); cnt++)
    {
        if (mJumpRays[cnt].geom == _in)
            return cnt;
    }

    return -1;
}

dGeomID odeWorld::getDynamicGeomID(const int _index)
{
    return (dGeomID)mObjectGeoms[_index];
}
