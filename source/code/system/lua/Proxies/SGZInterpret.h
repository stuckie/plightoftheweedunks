#ifndef _SGZINTERPRET_PROXY_H_
#define _SGZINTERPRET_PROXY_H_

#ifdef pedanticGCC
extern "C" {
#endif
    #include "../lualib.h"
#ifdef pedanticGCC
}
#endif

#include "../lunar.h"
#include "../../../arch.h"
#include "../../../common/debug/CDebug.h"
#include "../../../common/engine/CInterpret.h"

class SGZInterpret_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZInterpret_Proxy>::RegType methods[];

        int Running(lua_State *Lua);
        int UpdateInterfaces(lua_State *Lua);
        int NextEvent(lua_State *Lua);
        int SystemInfo(lua_State *Lua);
        int RenderInfo(lua_State *Lua);
        int LogWarning(lua_State *Lua);
        int LogError(lua_State *Lua);
        int LogDebug(lua_State *Lua);
        int Debug(lua_State *Lua);
        int Quit(lua_State *Lua);
        int GetFps(lua_State *Lua);
        int WriteIngameConfig ( lua_State *Lua );

        SGZInterpret_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZInterpret_Proxy() {}


    private:
};

#endif
