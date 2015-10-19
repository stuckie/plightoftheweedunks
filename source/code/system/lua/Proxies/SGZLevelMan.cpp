#include "SGZLevelMan.h"

int SGZLevelMan_Proxy::SetSize( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->SetSize((int)lua_tonumber(Lua, -3),(int)lua_tonumber(Lua, -2),(int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::AddTile( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->AddTile( lua_tostring(Lua, -5), lua_tostring(Lua, -4), (int)lua_tonumber(Lua, -3), (int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::TexTile( lua_State *Lua )
{
    SGZCOLOUR Colour;
    Colour.r = (SGZCOLOURVAL)lua_tonumber(Lua,8);
    Colour.g = (SGZCOLOURVAL)lua_tonumber(Lua,9);
    Colour.b = (SGZCOLOURVAL)lua_tonumber(Lua,10);
    SGZInterpret.accessServer()->World()->accessLevelManager()->TexTile( lua_tostring(Lua, 1), lua_tostring(Lua, 2), lua_tostring(Lua, 3),
                                                                        (SGZSCALER)lua_tonumber(Lua, 4), (SGZSCALER)lua_tonumber(Lua, 5),
                                                                        (SGZSCALER)lua_tonumber(Lua, 6), (SGZSCALER)lua_tonumber(Lua, 7),
                                                                        Colour);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::DelTile( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->DelTile( lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::NewVar (lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->NewVar( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::CheckVar (lua_State *Lua)
{
    std::string value = SGZInterpret.accessServer()->World()->accessLevelManager()->CheckVar( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, value.c_str());
    return 1;

}

int SGZLevelMan_Proxy::DeleteVar (lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->DeleteVar ( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::ChangeVar (lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->ChangeVar ( lua_tostring(Lua, -3), lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::CheckExist( lua_State *Lua )
{
    bool value = SGZInterpret.accessServer()->World()->accessLevelManager()->CheckExist ( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, value);

    return 1;
}

int SGZLevelMan_Proxy::Clear (lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->Clear();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::Render (lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessLevelManager()->RenderLevel();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZLevelMan_Proxy::GetType (lua_State *Lua)
{
    std::string value = SGZInterpret.accessServer()->World()->accessLevelManager()->GetType((int)lua_tonumber(Lua, 3), (int)lua_tonumber(Lua, 2), (int)lua_tonumber(Lua, 1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, value.c_str());
    return 1;
}

const char SGZLevelMan_Proxy::className[] = "SGZLevelManager";
Lunar<SGZLevelMan_Proxy>::RegType SGZLevelMan_Proxy::methods[] =
{
    {"NewVar",              &SGZLevelMan_Proxy::NewVar},
    {"CheckVar",            &SGZLevelMan_Proxy::CheckVar},
    {"DeleteVar",           &SGZLevelMan_Proxy::DeleteVar},
    {"ChangeVar",           &SGZLevelMan_Proxy::ChangeVar},
    {"CheckExist",          &SGZLevelMan_Proxy::CheckExist},
    {"SetSize",             &SGZLevelMan_Proxy::SetSize},
    {"AddTile",             &SGZLevelMan_Proxy::AddTile},
    {"TexTile",             &SGZLevelMan_Proxy::TexTile},
    {"DelTile",             &SGZLevelMan_Proxy::DelTile},
    {"Clear",               &SGZLevelMan_Proxy::Clear},
    {"Render",              &SGZLevelMan_Proxy::Render},
    {"GetTileType",         &SGZLevelMan_Proxy::GetType},
    {0,0}
};


