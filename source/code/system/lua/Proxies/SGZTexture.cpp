#include "SGZTexture.h"

int SGZTexture_Proxy::LoadTexture(lua_State *Lua)
{
    Texture.LoadTexture(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTexture_Proxy::LoadTextureMask(lua_State *Lua)
{
    Texture.LoadTextureMask(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTexture_Proxy::SetColourKey(lua_State *Lua)
{
    SGZCOLOUR colour;
    colour.r = (SGZCOLOURVAL)lua_tonumber(Lua, -3);
    colour.g = (SGZCOLOURVAL)lua_tonumber(Lua, -2);
    colour.b = (SGZCOLOURVAL)lua_tonumber(Lua, -1);
    Texture.SetColourKey(colour);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTexture_Proxy::SetColour(lua_State *Lua)
{
    SGZCOLOUR colour;
    colour.r = (SGZCOLOURVAL)lua_tonumber(Lua, -3);
    colour.g = (SGZCOLOURVAL)lua_tonumber(Lua, -2);
    colour.b = (SGZCOLOURVAL)lua_tonumber(Lua, -1);
    Texture.SetColour(colour);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTexture_Proxy::Blit(lua_State *Lua)
{
    SGZVECTOR position;
    position.x = (SGZVECTORVAL)lua_tonumber(Lua, -3);
    position.y = (SGZVECTORVAL)lua_tonumber(Lua, -2);
    position.z = (SGZVECTORVAL)lua_tonumber(Lua, -1);
//    Texture.BlitTexture(position);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZTexture_Proxy::Delete(lua_State *Lua)
{
    Texture.DeleteTexture();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZTexture_Proxy::className[] = "SGZTexture";
Lunar<SGZTexture_Proxy>::RegType SGZTexture_Proxy::methods[] =
{
    {"Load", &SGZTexture_Proxy::LoadTexture},
    {"LoadMask", &SGZTexture_Proxy::LoadTextureMask},
    {"SetColourKey",  &SGZTexture_Proxy::SetColourKey},
    {"SetColour",  &SGZTexture_Proxy::SetColour},
    {"Blit",  &SGZTexture_Proxy::Blit},
    {"Delete", &SGZTexture_Proxy::Delete},
    {0,0}
};
