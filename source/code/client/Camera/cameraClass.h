#ifndef _CAMERACLASS_H_INCLUDED
#define _CAMERACLASS_H_INCLUDED

#include <Horde3D.h>
#include <string>
#include "typedefs.h"
#include "utMath.h"
#include "CRandom.h"

typedef enum
{
    FREECAM, GAMECAM, SHAKECAM
}CameraState;

class cameraClass
{
    public:
        /* Used by all types of cameras */
        void Create(const ResHandle PipeLine, const float _fov, const float _aspect, const float _near, const float _far, const std::string _name);
        void Update(void);

        void TurnOnGameCam(void);
        void TurnOnFreeCam(void);
        void TurnOnShakeCam(const int _frames, const float _shake);

        /* Used by the free camera */
        void RotateAroundX(const float _in);
        void RotateAroundY(const float _in);
        void RotateAroundZ(const float _in);
        void Forward(const float _in);
        void Up(const float _in);
        void Right(const float _in);
        void SetIntMult(const float _mult);

        /* Used by the game camera */
        void SetCameraParams(const float _out, const float _up, const float upRat, const float outRat);
        void SetLookingIn(ECompassPoint _facing);
        ECompassPoint GetLookingIn(void);
        void FitPointsInView(const SGZVECTOR _pnt1, const SGZVECTOR _pnt2);
        SGZVECTOR GetCamPos(void);

    protected:
        void getGameCamNorth(SGZVECTOR &pos, SGZVECTOR &rot);
        void getGameCamSouth(SGZVECTOR &pos, SGZVECTOR &rot);
        void getGameCamEast(SGZVECTOR &pos, SGZVECTOR &rot);
        void getGameCamWest(SGZVECTOR &pos, SGZVECTOR &rot);

        NodeHandle mCamNode;
        CameraState mCamMode;
        SGZVECTOR mGameRealPos;

        SGZVECTOR mFreePos, mFreeRot;

        SGZVECTOR mGameOffsetPos, mGameLookAt;
        SGZVECTOR mGameFitPnt1, mGameFitPnt2;

        int mShakeCnt;
        float mOut;
        CRandom mRand;
        ECompassPoint mFacingIn;
        SGZVECTOR mCurPos, mCurRot;
        float mIntMult;
        float mShake;
};

#endif // _CAMERACLASS_H_INCLUDED
