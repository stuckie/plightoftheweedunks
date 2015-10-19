#include "SGZamBX.h"
#include "../../../arch.h"

int SGZamBX_Proxy::Start(lua_State *Lua)
{
    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZamBX_Proxy::End(lua_State *Lua)
{

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}


int SGZamBX_Proxy::Update(lua_State *Lua)
{
    /// if amBX isn't initalized exit without doing anything
    if (!ambxInit)
    {
        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);
        return 0;
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZamBX_Proxy::SetLight(lua_State *Lua)
{
    /// if amBX isn't initalized exit without doing anything
    if (!ambxInit || lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0)
    {
        if (ambxInit)
            SGZLogger.warn("the values passed to SetLight where not correct\n");


        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZamBX_Proxy::SetFan(lua_State *Lua)
{
    /// if amBX isn't initalized exit without doing anything
    if (!ambxInit || lua_gettop(Lua)!=2 || lua_isnumber(Lua, 1)==0 || lua_isstring(Lua, 2)==0)
    {
        if (ambxInit)
            SGZLogger.warn("the values passed to SetFan where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZamBX_Proxy::SetFade(lua_State *Lua)
{
    /// if amBX isn't initalized exit without doing anything
    if (!ambxInit || lua_gettop(Lua)!=2 || lua_isnumber(Lua, 1)==0 || lua_isstring(Lua, 2)==0)
    {
        if (ambxInit)
            SGZLogger.warn("the values passed to SetFade where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZamBX_Proxy::className[] = "SGZamBX";
Lunar<SGZamBX_Proxy>::RegType SGZamBX_Proxy::methods[] =
{
    {"Start", &SGZamBX_Proxy::Start},
    {"End",  &SGZamBX_Proxy::End},
    {"Update", &SGZamBX_Proxy::Update},
    {"SetLight", &SGZamBX_Proxy::SetLight},
    {"SetFan", &SGZamBX_Proxy::SetFan},
    {"SetFade", &SGZamBX_Proxy::SetFade},
    {0,0}
};
