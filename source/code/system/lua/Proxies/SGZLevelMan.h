#ifndef _SGZLEVELMAN_PROXY_H_
#define _SGZLEVELMAN_PROXY_H_

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

class SGZLevelMan_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZLevelMan_Proxy>::RegType methods[];

        int     SetSize( lua_State *Lua );
        int     AddTile( lua_State *Lua );
        int     TexTile( lua_State *Lua );
        int     DelTile( lua_State *Lua );

        int     NewVar (lua_State *Lua);
        int     CheckVar (lua_State *Lua);
        int     DeleteVar (lua_State *Lua);
        int     ChangeVar (lua_State *Lua);

        int     CheckExist( lua_State *Lua );
        int     Clear( lua_State *Lua );
        int     Render( lua_State *Lua );
        int     GetType(lua_State *Lua);

        SGZLevelMan_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZLevelMan_Proxy() {};

};

#endif




