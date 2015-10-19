#include "cameraClass.h"
#include "CInterpret.h"
#include <Horde3D.h>

void cameraClass::Create(const ResHandle PipeLine, const float _fov, const float _aspect, const float _near, const float _far, const std::string _name)
{
    mCamMode = GAMECAM;
    mGameRealPos = SGZVECTOR(0,0,0);
    mFreePos = SGZVECTOR(0,0,0);
    mFreeRot = SGZVECTOR(0,0,0);
    mIntMult = 0.1;

    mRand.Randomise();

    mCamNode = Horde3D::addCameraNode(RootNode, _name.c_str(), PipeLine);
    Horde3D::setupCameraView( mCamNode, _fov, _aspect,  _near, _far );
    Horde3D::setNodeParami( mCamNode, CameraNodeParams::OcclusionCulling, 1 );
}

void cameraClass::Update(void)
{
    SGZVECTOR desiredPos, desiredRot;
    switch (mCamMode)
    {
    case FREECAM:
    {
        desiredPos = mFreePos;
        desiredRot = mFreeRot;
    }
    break;
    case GAMECAM:
    case SHAKECAM:
    {
        switch (mFacingIn)
        {
        case NORTH:
            getGameCamNorth(desiredPos, desiredRot);
            break;
        case SOUTH:
            getGameCamSouth(desiredPos, desiredRot);
            break;
        case EAST:
            getGameCamEast(desiredPos, desiredRot);
            break;
        case WEST:
            getGameCamWest(desiredPos, desiredRot);
            break;
        default:
            SGZLogger.warn("Camera was facing in incorrect dirrection, resorting to free cam\n");
            mCamMode = FREECAM;
            break;
        }
    }
    break;
    default:
        SGZLogger.warn("Unknown camera state\n");
        break;
    };

    mCurPos.x = mCurPos.x + (desiredPos.x-mCurPos.x)*mIntMult;
    mCurPos.y = mCurPos.y + (desiredPos.y-mCurPos.y)*mIntMult;
    mCurPos.z = mCurPos.z + (desiredPos.z-mCurPos.z)*mIntMult;
    mCurRot.x = mCurRot.x + (desiredRot.x-mCurRot.x)*mIntMult;
    mCurRot.y = mCurRot.y + (desiredRot.y-mCurRot.y)*mIntMult;
    mCurRot.z = mCurRot.z + (desiredRot.z-mCurRot.z)*mIntMult;

    if (mCamMode == SHAKECAM)
    {
        mShakeCnt--;

        if (mShakeCnt<=0)
            mCamMode=GAMECAM;

        mCurPos.x += -mShake+(mShake*2*mRand.Random());
        mCurPos.y += -mShake+(mShake*2*mRand.Random());
        mCurPos.z += -mShake+(mShake*2*mRand.Random());
    }

    Horde3D::setNodeTransform(mCamNode, mCurPos.x, mCurPos.y, mCurPos.z,  mCurRot.x, mCurRot.y, mCurRot.z, 1,1,1);
    Horde3D::render(mCamNode);
}

void cameraClass::RotateAroundX(const float _in)
{
    mFreeRot.x += _in;
}

void cameraClass::RotateAroundY(const float _in)
{
    mFreeRot.y += _in;
}

void cameraClass::RotateAroundZ(const float _in)
{
    mFreeRot.z += _in;
}

void cameraClass::Forward(const float _in)
{
    float sinY = sin(degToRad(mFreeRot.y));
    float cosX = cos(degToRad(mFreeRot.x));
    float sinX = sin(degToRad(mFreeRot.x));
    float cosY = cos(degToRad(mFreeRot.y));

    mFreePos.x -= _in*sinY*cosX;
    mFreePos.y += _in*sinX;
    mFreePos.z -= _in*cosY*cosX;
}

void cameraClass::Up(const float _in)
{
    mFreePos.y += _in;
}

void cameraClass::Right(const float _in)
{
    mFreePos.z -= _in*sin(degToRad(mFreeRot.y));
    mFreePos.x += _in*cos(degToRad(mFreeRot.y));
}

void cameraClass::SetCameraParams(const float _out, const float _up, const float _upRat, const float _outRat)
{
    float m = 1/sqrt( _upRat* _upRat+_outRat*_outRat);
    mOut = _out;
    mGameOffsetPos.x = _up;
    mGameOffsetPos.y = _upRat*m;
    mGameOffsetPos.z = _outRat*m;
}

void cameraClass::SetLookingIn(const ECompassPoint _facing)
{
    mFacingIn = _facing;
}

ECompassPoint cameraClass::GetLookingIn(void)
{
    return mFacingIn;
}

void cameraClass::FitPointsInView(const SGZVECTOR _pnt1, const SGZVECTOR _pnt2)
{
    mGameFitPnt1 = _pnt1;
    mGameFitPnt2 = _pnt2;

    mGameLookAt.x = _pnt1.x + 0.5f*(_pnt2.x-_pnt1.x);
    mGameLookAt.y = _pnt1.y + 0.5f*(_pnt2.y-_pnt1.y);
    mGameLookAt.z = _pnt1.z + 0.5f*(_pnt2.z-_pnt1.z);
}

void cameraClass::TurnOnFreeCam(void)
{
    mCamMode = FREECAM;
}

void cameraClass::TurnOnGameCam(void)
{
    mCamMode = GAMECAM;
}

void cameraClass::TurnOnShakeCam(const int _frames, const float _shake)
{
    mCamMode = SHAKECAM;
    mShakeCnt = _frames;
    mShake = _shake;
}

void cameraClass::SetIntMult(const float _mult)
{
    mIntMult = _mult;
}

SGZVECTOR cameraClass::GetCamPos(void)
{
    return mCurPos;
}

