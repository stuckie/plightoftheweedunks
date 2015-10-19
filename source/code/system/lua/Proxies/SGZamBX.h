#ifndef _SGZAMBX_H_
#define _SGZAMBX_H_

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
#include "amBXcore.h"

class SGZamBX_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZamBX_Proxy>::RegType methods[];

        int Start(lua_State *Lua);
        int End(lua_State *Lua);
        int Update(lua_State *Lua);
        int SetLight(lua_State *Lua);
        int SetFan(lua_State *Lua);
        int SetFade(lua_State *Lua);

        SGZamBX_Proxy(lua_State *L)
        {
            ambxInit = false;
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZamBX_Proxy() {}

    private:

    #if defined(OS_WIN32) && defined(amBX_ON)
        amBXcntClass ambx;
    #endif
    bool ambxInit;
};

#endif // _SGZAMBX_H_
