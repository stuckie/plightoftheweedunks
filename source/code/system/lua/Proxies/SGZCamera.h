#ifndef _SGZCAMERA_H_
#define _SGZCAMERA_H_

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
#include "cameraClass.h"

class SGZCamera_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZCamera_Proxy>::RegType methods[];

        int Create(lua_State *Lua);
        int Update(lua_State *Lua);
        int TurnOnFreeCam(lua_State *Lua);
        int TurnOnGameCam(lua_State *Lua);
        int TurnOnShakeCam(lua_State *Lua);

        int RotateAroundX(lua_State *Lua);
        int RotateAroundY(lua_State *Lua);
        int RotateAroundZ(lua_State *Lua);
        int Forward(lua_State *Lua);
        int Up(lua_State *Lua);
        int Right(lua_State *Lua);
        int Backward(lua_State *Lua);
        int Down(lua_State *Lua);
        int Left(lua_State *Lua);

        int SetCameraParams(lua_State *Lua);
        int SetLookAtPoint(lua_State *Lua);
        int LookNorth(lua_State *Lua);
        int LookSouth(lua_State *Lua);
        int LookEast(lua_State *Lua);
        int LookWest(lua_State *Lua);
        int GetCamLookDir(lua_State *Lua);
        int FitPointsInView(lua_State *Lua);
        int SetInterpolation(lua_State *Lua);
        int GetCamPos(lua_State *Lua);

        SGZCamera_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZCamera_Proxy() {}

    private:

    cameraClass cam;
};


#endif // _SGZCAMERA_H_
