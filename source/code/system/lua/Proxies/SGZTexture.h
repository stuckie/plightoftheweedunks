#ifndef _SGZTEXTURE_H_
#define _SGZTEXTURE_H_

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
#include "../../../client/renderer/texture/OTexture.h"

class SGZTexture_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZTexture_Proxy>::RegType methods[];

        SGZTexture_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZTexture_Proxy() {}

        int LoadTexture(lua_State *Lua);
        int LoadTextureMask(lua_State *Lua);
        int SetColourKey(lua_State *Lua);
        int Blit(lua_State *Lua);
        int SetColour(lua_State *Lua);
        int Delete(lua_State *Lua);

    private:

        OTexture Texture;

};

#endif
