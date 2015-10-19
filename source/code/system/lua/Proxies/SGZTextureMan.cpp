#include "SGZTextureMan.h"

int SGZTextureMan_Proxy::AddTexture( lua_State *Lua )
{
    SGZLogger.debug("%s as %s\n",lua_tostring(Lua, 1), lua_tostring(Lua, 2));
    SGZInterpret.accessServer()->World()->accessTextureManager()->AddTexture( lua_tostring(Lua, 1), lua_tostring(Lua, 2) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTextureMan_Proxy::AddTexMask( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessTextureManager()->AddTexMask( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTextureMan_Proxy::DelTexture( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessTextureManager()->DelTexture( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTextureMan_Proxy::SetColour( lua_State *Lua )
{
    SGZCOLOUR col;
    col.r = (SGZCOLOURVAL)lua_tonumber(Lua, -3);
    col.g = (SGZCOLOURVAL)lua_tonumber(Lua, -2);
    col.b = (SGZCOLOURVAL)lua_tonumber(Lua, -1);
    SGZInterpret.accessServer()->World()->accessTextureManager()->SetColour ( lua_tostring(Lua, -4), col );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTextureMan_Proxy::CheckExist( lua_State *Lua )
{
    bool value = SGZInterpret.accessServer()->World()->accessTextureManager()->CheckExist(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, value);

    return 1;
}

int SGZTextureMan_Proxy::BlitTexture( lua_State *Lua )
{
    int values = lua_gettop(Lua);
    if (values>8)
    {
         SGZInterpret.accessServer()->World()->accessTextureManager()->BlitTexture(lua_tostring(Lua, 1),
         (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4), (float)lua_tonumber(Lua, 5),
         (float)lua_tonumber(Lua, 6), (float)lua_tonumber(Lua, 7), (float)lua_tonumber(Lua, 8), (float)lua_tonumber(Lua, 9),
         (float)lua_tonumber(Lua,10), (float)lua_tonumber(Lua,11), (float)lua_tonumber(Lua,12), (float)lua_tonumber(Lua,13),
         (float)lua_tonumber(Lua,14), (float)lua_tonumber(Lua,15), (float)lua_tonumber(Lua,16), (float)lua_tonumber(Lua,17),
         (int)lua_tonumber(Lua,18));

    }
    else
    {

        SGZVECTOR position;
        position.x = (SGZVECTORVAL)lua_tonumber(Lua, 2);
        position.y = (SGZVECTORVAL)lua_tonumber(Lua, 3);
        position.z = (SGZVECTORVAL)lua_tonumber(Lua, 4);
        SGZInterpret.accessServer()->World()->accessTextureManager()->BlitTexture(lua_tostring(Lua, 1), position,
            (SGZSCALER)lua_tonumber(Lua, 5), (SGZSCALER)lua_tonumber(Lua, 6), (SGZSCALER)lua_tonumber(Lua, 7), (SGZSCALER)lua_tonumber(Lua, 8));

    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZTextureMan_Proxy::className[] = "SGZTextureManager";
Lunar<SGZTextureMan_Proxy>::RegType SGZTextureMan_Proxy::methods[] =
{
    {"AddTexture",          &SGZTextureMan_Proxy::AddTexture},
    {"AddTexMask",          &SGZTextureMan_Proxy::AddTexMask},
    {"DelTexture",          &SGZTextureMan_Proxy::DelTexture},
    {"SetColour",           &SGZTextureMan_Proxy::SetColour},
    {"CheckExist",          &SGZTextureMan_Proxy::CheckExist},
    {"BlitTexture",         &SGZTextureMan_Proxy::BlitTexture},
    {0,0}
};
