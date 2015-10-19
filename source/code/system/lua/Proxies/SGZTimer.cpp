#include "SGZTimer.h"

int SGZTimer_Proxy::Start(lua_State *Lua)
{
    Timer.start();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTimer_Proxy::Stop(lua_State *Lua)
{
    Timer.stop();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTimer_Proxy::Reset(lua_State *Lua)
{
    Timer.reset();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTimer_Proxy::Running(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, !Timer.stopped());

    return 1;
}

int SGZTimer_Proxy::Time(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, Timer.currenttime());

    return 1;
}

const char SGZTimer_Proxy::className[] = "SGZTimer";
Lunar<SGZTimer_Proxy>::RegType SGZTimer_Proxy::methods[] =
{
    {"Start", &SGZTimer_Proxy::Start},
    {"Stop", &SGZTimer_Proxy::Stop},
    {"Reset", &SGZTimer_Proxy::Reset},
    {"Running", &SGZTimer_Proxy::Running},
    {"Time", &SGZTimer_Proxy::Time},
    {0,0}
};


