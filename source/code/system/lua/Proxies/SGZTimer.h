#ifndef _SGZTIMER_H_
#define _SGZTIMER_H_

#ifdef pedanticGCC
extern "C" {
#endif
    #include "../lualib.h"
#ifdef pedanticGCC
}
#endif

#include "lunar.h"
#include "arch.h"
#include "CDebug.h"
#include "CTimer.h"

class SGZTimer_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZTimer_Proxy>::RegType methods[];

        int Start(lua_State *L);
        int Stop(lua_State *L);
        int Reset(lua_State *L);
        int Running(lua_State *L);
        int Time(lua_State *L);

        SGZTimer_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZTimer_Proxy() {}

    private:

    CTimer Timer;

};

#endif

