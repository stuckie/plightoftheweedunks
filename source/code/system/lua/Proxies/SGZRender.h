#ifndef __SGZRENDER_H_
#define __SGZRENDER_H_

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

class SGZRender_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZRender_Proxy>::RegType methods[];

        SGZRender_Proxy(lua_State* L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZRender_Proxy() {}

        int NewWindow(lua_State* Lua);
        int CloseWindow(lua_State* Lua);
        int UpdateScreen(lua_State* Lua);
        int StartRenderer(lua_State* Lua);
        int StopRenderer(lua_State* Lua);
        int SetFullScreen(lua_State *Lua);

    private:

};

#endif
