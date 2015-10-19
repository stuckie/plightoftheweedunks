#ifndef _SGZNETWORK_PROXY_H_
#define _SGZNETWORK_PROXY_H_

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

class SGZNetwork_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZNetwork_Proxy>::RegType methods[];

        int OpenConnection(lua_State *Lua);
        int CloseConnection(lua_State *Lua);

        SGZNetwork_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZNetwork_Proxy() {}


    private:
};

#endif
