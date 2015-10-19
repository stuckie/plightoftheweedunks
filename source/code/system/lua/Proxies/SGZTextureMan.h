#ifndef _SGZTEXTUREMAN_PROXY_H_
#define _SGZTEXTUREMAN_PROXY_H_

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

class SGZTextureMan_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZTextureMan_Proxy>::RegType methods[];

        int    AddTexture( lua_State *Lua );
        int    AddTexMask( lua_State *Lua );
        int    DelTexture( lua_State *Lua );
        int    BlitTexture( lua_State *Lua );

        int    SetColour ( lua_State *Lua );
        int    CheckExist( lua_State *Lua );

        SGZTextureMan_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZTextureMan_Proxy() {};

};

#endif


