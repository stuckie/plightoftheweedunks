#include "cameraClass.h"
#include "CInterpret.h"
#include <Horde3D.h>

void cameraClass::getGameCamNorth(SGZVECTOR &pos, SGZVECTOR &rot)
{
    pos = mGameLookAt;
    SGZVECTOR dif;
    float m = 0.0f;

    // get the distance between the two players
    dif.x = mGameFitPnt1.x-mGameFitPnt2.x;
    dif.y = mGameFitPnt1.y-mGameFitPnt2.y;
    dif.z = mGameFitPnt1.z-mGameFitPnt2.z;
    m = sqrt(dif.x*dif.x+dif.y*dif.y+dif.z*dif.z) + mOut;

    // move the camera out the size of the players
    pos.y += m*mGameOffsetPos.y + mGameOffsetPos.x;
    pos.z += m*mGameOffsetPos.z;

    // find the rotations of the camera
    rot.x = -radToDeg(atan2(mGameOffsetPos.y,mGameOffsetPos.z));
    rot.y=rot.z=0.0f;
}

void cameraClass::getGameCamSouth(SGZVECTOR &pos, SGZVECTOR &rot)
{
    pos = mGameLookAt;
    SGZVECTOR dif;
    float m = 0.0f;

    // get the distance between the two players
    dif.x = mGameFitPnt1.x-mGameFitPnt2.x;
    dif.y = mGameFitPnt1.y-mGameFitPnt2.y;
    dif.z = mGameFitPnt1.z-mGameFitPnt2.z;
    m = sqrt(dif.x*dif.x+dif.y*dif.y+dif.z*dif.z) + mOut;

    // move the camera out the size of the players
    pos.y += m*mGameOffsetPos.y + mGameOffsetPos.x;
    pos.z -= m*mGameOffsetPos.z;

    // find the rotations of the camera
    rot.x = -radToDeg(atan2(mGameOffsetPos.y,mGameOffsetPos.z));
    rot.y=180.0f;
    rot.z=0.0f;
}

void cameraClass::getGameCamEast(SGZVECTOR &pos, SGZVECTOR &rot)
{
    pos = mGameLookAt;
    SGZVECTOR dif;
    float m = 0.0f;

    // get the distance between the two players
    dif.x = mGameFitPnt1.x-mGameFitPnt2.x;
    dif.y = mGameFitPnt1.y-mGameFitPnt2.y;
    dif.z = mGameFitPnt1.z-mGameFitPnt2.z;
    m = sqrt(dif.x*dif.x+dif.y*dif.y+dif.z*dif.z) + mOut;

    // move the camera out the size of the players
    pos.x -= m*mGameOffsetPos.z;
    pos.y += m*mGameOffsetPos.y + mGameOffsetPos.x;

    // find the rotations of the camera
    rot.x = -radToDeg(atan2(mGameOffsetPos.y,mGameOffsetPos.z));
    rot.y=-90.0f;
    rot.z=0.0f;
}

void cameraClass::getGameCamWest(SGZVECTOR &pos, SGZVECTOR &rot)
{
    pos = mGameLookAt;
    SGZVECTOR dif;
    float m = 0.0f;

    // get the distance between the two players
    dif.x = mGameFitPnt1.x-mGameFitPnt2.x;
    dif.y = mGameFitPnt1.y-mGameFitPnt2.y;
    dif.z = mGameFitPnt1.z-mGameFitPnt2.z;
    m = sqrt(dif.x*dif.x+dif.y*dif.y+dif.z*dif.z) + mOut;

    // move the camera out the size of the players
    pos.x += m*mGameOffsetPos.z;
    pos.y += m*mGameOffsetPos.y + mGameOffsetPos.x;

    // find the rotations of the camera
    rot.x = -radToDeg(atan2(mGameOffsetPos.y,mGameOffsetPos.z));
    rot.y=90.0f;
    rot.z=0.0f;
}
