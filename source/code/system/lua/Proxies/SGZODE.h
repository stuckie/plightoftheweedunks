#ifndef _SGZODE_H_
#define _SGZODE_H_

#include "arch.h"

#ifdef pedanticGCC
extern "C" {
#endif
    #include "../lualib.h"
#ifdef pedanticGCC
}
#endif

#include "../lunar.h"
#include "../../../common/debug/CDebug.h"
#include "CInterpret.h"

class SGZode_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZode_Proxy>::RegType methods[];

        int Hit(lua_State *Lua);
        int Bounce(lua_State *Lua);
        int KillerHit(lua_State *Lua);
        int HitKillVVel(lua_State *Lua);
        int ApplyHitForce(lua_State *Lua);
        int SetGravity(lua_State *Lua);
        int applyForce(lua_State *Lua);
        int applyForceWithRot(lua_State *Lua);
        int applyDampingForceHorizontally(lua_State *Lua);
        int removeForces(lua_State *Lua);
        int setMovingPos(lua_State *Lua);
        int setMovingRot(lua_State *Lua);
        int setDynamicPos(lua_State *Lua);
        int setDynamicRot(lua_State *Lua);
        int enableDynamicObject(lua_State *Lua);
        int killEverything(lua_State *Lua);
        int killDynamic(lua_State *Lua);
        int killMoving(lua_State *Lua);

        int createMovingBox(lua_State *Lua);
        int createStaticBox(lua_State *Lua);
        int createStaticPlane(lua_State *Lua);
        int createDynamicBox(lua_State *Lua);
        int createDynamicSphere(lua_State *Lua);
        int createDynamicCapsule(lua_State *Lua);
        int moveMoving(lua_State *Lua);

        int jump(lua_State *Lua);
        int setOffset(lua_State *Lua);
        int ApplyAnalogueControl(lua_State *Lua);
        int TurnOffGravityFor(lua_State *Lua);
        int TurnOnGravityFor(lua_State *Lua);
        int getDynamicPos(lua_State *Lua);
        int getVelocity(lua_State *Lua);

        int GetRotationToFace(lua_State *Lua);
        int GetPointOfContact(lua_State *Lua);

        int AddJumpRay(lua_State *Lua);
        int AddNoJumpMaterial(lua_State *Lua);
        int SetJumpRayPos(lua_State *Lua);
        int HasJumpRayHit(lua_State *Lua);

        int Pause(lua_State *Lua);
        int SetStepsPerFrame(lua_State *Lua);
        int LimitVertVel(lua_State *Lua);
        int GetDynamicID(lua_State *Lua);

        SGZode_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZode_Proxy() {}
};


#endif // _SGZODE_H_
