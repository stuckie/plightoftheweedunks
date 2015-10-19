#include "SGZNetwork.h"

int SGZNetwork_Proxy::OpenConnection(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZNetwork_Proxy::CloseConnection(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZNetwork_Proxy::className[] = "SGZNetwork";
Lunar<SGZNetwork_Proxy>::RegType SGZNetwork_Proxy::methods[] =
{
    {"OpenConnection", &SGZNetwork_Proxy::OpenConnection},
    {"CloseConnection",  &SGZNetwork_Proxy::CloseConnection},
    {0,0}
};
