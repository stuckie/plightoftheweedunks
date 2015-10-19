#include "SGZRender.h"

int SGZRender_Proxy::NewWindow(lua_State* Lua)
{
    std::string WindowName = lua_tostring(Lua, -4);
    int WindowWidth = (int)lua_tonumber(Lua, -3);
    int WindowHeight = (int)lua_tonumber(Lua, -2);
    int WindowBPP = (int)lua_tonumber(Lua, -1);

    SGZInterpret.accessClient()->OpenWindow(WindowName, WindowWidth, WindowHeight, WindowBPP);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZRender_Proxy::CloseWindow(lua_State* Lua)
{
    SGZInterpret.accessClient()->CloseWindow();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZRender_Proxy::StartRenderer(lua_State* Lua)
{
    SGZInterpret.accessClient()->accessRenderer()->StartRenderer();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZRender_Proxy::StopRenderer(lua_State* Lua)
{
    SGZInterpret.accessClient()->accessRenderer()->StopRenderer();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZRender_Proxy::UpdateScreen(lua_State* Lua)
{
    SGZInterpret.accessClient()->accessRenderer()->UpdateScreen();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZRender_Proxy::SetFullScreen ( lua_State *Lua )
{
    SGZInterpret.accessClient()->accessRenderer()->SetFullScreen( lua_toboolean(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZRender_Proxy::className[] = "SGZRenderer";
Lunar<SGZRender_Proxy>::RegType SGZRender_Proxy::methods[] =
{
    {"NewWindow",  &SGZRender_Proxy::NewWindow},
    {"CloseWindow",  &SGZRender_Proxy::CloseWindow},
    {"UpdateScreen",  &SGZRender_Proxy::UpdateScreen},
    {"SetFullScreen", &SGZRender_Proxy::SetFullScreen},
    {"Start", &SGZRender_Proxy::StartRenderer},
    {"Stop", &SGZRender_Proxy::StopRenderer},
    {0,0}
};
