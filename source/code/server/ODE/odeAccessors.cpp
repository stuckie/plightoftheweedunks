#include "odeCore.h"
#include "typedefs.h"
#include "CDebug.h"
#include "OEvent.h"
#include "CInterpret.h"
#include "utMath.h"
const dReal blankQ[4] = {0,0,0,0};

SGZVECTOR odeWorld::getMovingPos(const int _index)
{
    const dReal * pos = dGeomGetPosition(mMovingGeoms[_index]);

    return SGZVECTOR(pos[0], pos[1], pos[2]);
}

SGZVECTOR odeWorld::getDynamicPos(const int _index)
{
    if (mObjectBodys[_index] == NULL)
        return SGZVECTOR();

    const dReal * pos = dBodyGetPosition(mObjectBodys[_index]);

    return SGZVECTOR(pos[0], pos[1], pos[2]);
}

SGZVECTOR odeWorld::getVelocity(const int _index)
{
    if (mObjectBodys[_index] == NULL)
        return SGZVECTOR();

    const dReal * v = dBodyGetLinearVel(mObjectBodys[_index]);

    return SGZVECTOR(v[0], v[1], v[2]);
}

const dReal* odeWorld::getQuaternion(const int _index)
{
    if (mObjectBodys[_index] == NULL)
    {
        return blankQ;
    }

    return dBodyGetQuaternion(mObjectBodys[_index]);
}
Quaternion odeWorld::getMovingQuaternion(const int _index)
{
    dQuaternion tmp;
    dGeomGetQuaternion(mMovingGeoms[_index], tmp);
    Quaternion q(tmp[1], tmp[2], tmp[3], tmp[0]);
    return q;
}

void odeWorld::setGravity(const float _g)
{
    dWorldSetGravity(mPhysicsWorld, 0, _g, 0);
}

void odeWorld::applyForce(const int _index, const SGZVECTOR _f)
{
    if (mObjectBodys[_index] == NULL)
        return;

    dBodyAddForce(mObjectBodys[_index], _f.x*mPhysicsStepsPerFrame, _f.y*mPhysicsStepsPerFrame, _f.z*mPhysicsStepsPerFrame);
}

void odeWorld::applyDampingForceHorizontally(const int _index, const float _damp)
{
    if (mObjectBodys[_index] == NULL)
        return;
    const dReal*tmp = dBodyGetForce(mObjectBodys[_index]);
    dBodySetForce(mObjectBodys[_index], tmp[0]*_damp, tmp[1], tmp[2]*_damp);
    const dReal* tmp2 = dBodyGetLinearVel(mObjectBodys[_index]);
    dBodySetLinearVel(mObjectBodys[_index], tmp2[0]*_damp, tmp2[1], tmp2[2]*_damp);
}

void odeWorld::removeForces(const int _index)
{
    if (mObjectBodys[_index] == NULL)
        return;
    dBodySetForce(mObjectBodys[_index], 0, 0, 0);
    dBodySetTorque(mObjectBodys[_index], 0, 0, 0);
    dBodySetAngularVel(mObjectBodys[_index], 0, 0, 0);
    dBodySetLinearVel(mObjectBodys[_index], 0, 0, 0);
}

void odeWorld::setMovingPos(const int _index, const SGZVECTOR _pos)
{
    dGeomSetPosition(mMovingGeoms[_index], _pos.x, _pos.y, _pos.z);
}

void odeWorld::setMovingRot(const int _index, const float _x, const float _y, const float _z)
{
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, _x, _y, _z);

    dGeomSetRotation(mMovingGeoms[_index], rotMat);
}

void odeWorld::setDynamicPos(const int _index, const SGZVECTOR _pos)
{
    if (mObjectBodys[_index] == NULL)
        return;
    dBodySetAngularVel(mObjectBodys[_index], 0.0f, 0.0f, 0.0f);
    dBodySetPosition(mObjectBodys[_index], _pos.x, _pos.y, _pos.z);
}

void odeWorld::setDynamicRot(const int _index, const float _x, const float _y, const float _z)
{
    if (mObjectBodys[_index] == NULL)
        return;
    dMatrix3 rotMat;
    dRFromEulerAngles(rotMat, _x, _y, _z);
    dBodySetRotation(mObjectBodys[_index], rotMat);
}

void odeWorld::enableDynamicObject(const int _index, const bool _active)
{
    if (mObjectBodys[_index] == NULL)
        return;
    if (_active)
    {
        dBodyEnable(mObjectBodys[_index]);
        dGeomEnable(mMovingGeoms[_index]);
    }
    else
    {
        dBodyDisable(mObjectBodys[_index]);
        dGeomDisable(mMovingGeoms[_index]);
    }
}

SGZVECTOR odeWorld::getOffset(const int _index)
{
    return mOffSet[_index];
}

void odeWorld::setOffset(const int _index, const SGZVECTOR _offset)
{
    mOffSet[_index] = _offset;
}

SGZVECTOR odeWorld::getMovingSize(const int _index)
{
    return mMovingSize[_index];
}

SGZVECTOR odeWorld::getDynamicSize(const int _index)
{
    return mDynamicSize[_index];
}

void odeWorld::turnOffGravityFor(const int _index)
{
    if (mObjectBodys[_index] != NULL)
        dBodySetGravityMode(mObjectBodys[_index], 0);
}

void odeWorld::turnOnGravityFor(const int _index)
{
    if (mObjectBodys[_index] != NULL)
        dBodySetGravityMode(mObjectBodys[_index], 1);
}

bool odeWorld::killDynamic(const int _index)
{
    for (unsigned int cnt=0; cnt<mDynamicsToKill.size(); cnt++)
    {
        if (mDynamicsToKill[cnt] == _index)
            return false;
    }
    mDynamicsToKill.push_back(_index);
    return true;
}

bool odeWorld::killMoving(const int _index)
{
    for (unsigned int cnt=0; cnt<mMovingsToKill.size(); cnt++)
    {
        if (mMovingsToKill[cnt] == _index)
            return false;
    }
    mMovingsToKill.push_back(_index);
    return true;
}

void odeWorld::setRayPos(const int _index, const SGZVECTOR _pos)
{
    dGeomRaySet(mJumpRays[_index].geom, _pos.x, _pos.y, _pos.z, 0, -1, 0);
}

bool odeWorld::hasJumpRayHit(const int _index, float &_depth)
{
    _depth = mJumpRays[_index].hitDepth;
    return mJumpRays[_index].hasHit;
}

void odeWorld::setPause(const bool _pause)
{
    mPaused = _pause;
}

void odeWorld::addNoJumpMaterial(const string _mat)
{
    mNoJumpMaterials.push_back(_mat);
}

void odeWorld::killVVel(const int _index)
{
    if (mObjectBodys[_index] == NULL)
        return;
    const dReal *tmp = dBodyGetLinearVel(mObjectBodys[_index]);
    dBodySetLinearVel(mObjectBodys[_index], tmp[0], 0, tmp[2]);
}

void odeWorld::setStepsPerFrame(const int _steps)
{
    mPhysicsStepsPerFrame = _steps;
}

float odeWorld::limitVertVel(const int _index, const float _v)
{
    if (mObjectBodys[_index] == NULL)
        return 0.0f;
    const dReal *tmp = dBodyGetLinearVel(mObjectBodys[_index]);
    float upV = tmp[1];
    if (upV > _v)
        upV = _v;
    else if (upV < -_v)
        upV = -_v;
    dBodySetLinearVel(mObjectBodys[_index], tmp[0], upV, tmp[2]);

    return upV;
}

SGZVECTOR odeWorld::getOriginalPos(const int _index)
{
    return mMovingOriginalPos[_index];
}
