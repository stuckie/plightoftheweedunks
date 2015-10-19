#include "SGZInterpret.h"
#include "../../../arch.h"

int SGZInterpret_Proxy::NextEvent(lua_State *Lua)
{
    SGZInterpret.NextEvent();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZInterpret_Proxy::Quit(lua_State *Lua)
{
    QuitEvent *NewEvent;
    NewEvent = new QuitEvent;
    SGZInterpret.AddEvent( NewEvent );
    SGZLogger.debug("Quit Received from Lua\n");

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZInterpret_Proxy::UpdateInterfaces(lua_State *Lua)
{
    SGZInterpret.UpdateInterfaces();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZInterpret_Proxy::Running(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.Running());

    return 1;
}

int SGZInterpret_Proxy::GetFps(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, (int)SGZInterpret.accessServer()->World()->getFps());

    return 1;
}

int SGZInterpret_Proxy::RenderInfo(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    #if (defined(REND_SDL))
    lua_pushstring(Lua, "REND_SDL");
    #endif
    #if (defined(REND_SDLGL))
    lua_pushstring(Lua, "REND_SDLGL");
    #endif
    #if (defined(REND_HORDE))
    std::string HordeDetails;
    HordeDetails.insert(0,"REND_");
    HordeDetails.insert(5,Horde3D::getVersionString());
    lua_pushstring(Lua, HordeDetails.c_str());
    #endif
    #if (defined(REND_SDLHORDE))
    std::string HordeDetails;
    HordeDetails.insert(0,"REND_SDL");
    HordeDetails.insert(8,Horde3D::getVersionString());
    lua_pushstring(Lua, HordeDetails.c_str());
    #endif
    #if (defined(REND_OGRE))
    lua_pushstring(Lua, "REND_OGRE");
    #endif
    #if (defined(REND_SDLDX))
    lua_pushstring(Lua, "REND_SDLDX");
    #endif
    #if (defined(REND_DIRECTX))
    lua_pushstring(Lua, "REND_DIRECTX");
    #endif
    #if (defined(REND_SPS2))
    lua_pushstring(Lua, "REND_SPS2");
    #endif
    #if (defined(REND_WINAPI))
    lua_pushstring(Lua, "REND_WINAPI");
    #endif

    return 1;
}

int SGZInterpret_Proxy::SystemInfo(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    #if (defined(PLAT_GP32))
    lua_pushstring(Lua, "PLAT_GP32");
    #endif
    #if (defined(PLAT_GP2X))
    lua_pushstring(Lua, "PLAT_GP2X");
    #endif
    #if (defined(PLAT_GBA))
    lua_pushstring(Lua, "PLAT_GBA");
    #endif
    #if (defined(PLAT_DS))
    lua_pushstring(Lua, "PLAT_DS");
    #endif
    #if (defined(PLAT_GC))
    lua_pushstring(Lua, "PLAT_GC");
    #endif
    #if (defined(PLAT_DC))
    lua_pushstring(Lua, "PLAT_DC");
    #endif
    #if (defined(PLAT_PSX))
    lua_pushstring(Lua, "PLAT_PSX");
    #endif
    #if (defined(PLAT_PS2LINUX))
    lua_pushstring(Lua, "PLAT_PS2LINUX");
    #endif
    #if (defined(PLAT_PS3LINUX))
    lua_pushstring(Lua, "PLAT_PS3LINUX");
    #endif
    #if (defined(PLAT_PS2DEV))
    lua_pushstring(Lua, "PLAT_PS2DEV");
    #endif
    #if (defined(PLAT_PS3DEV))
    lua_pushstring(Lua, "PLAT_PS3DEV");
    #endif
    #if (defined(PLAT_PSPDEV))
    lua_pushstring(Lua, "PLAT_PSPDEV");
    #endif
    #if (defined(PLAT_MACOSX))
    lua_pushstring(Lua, "PLAT_MACOSX");
    #endif
    #if (defined(PLAT_MACOSCLASSIC))
    lua_pushstring(Lua, "PLAT_MACOSCLASSIC");
    #endif
    #if (defined(OS_LINUX))
    lua_pushstring(Lua, "PLAT_LINUX");
    #endif
    #if (defined(OS_WIN32))
    lua_pushstring(Lua, "PLAT_WIN32");
    #endif

    return 1;
}

int SGZInterpret_Proxy::LogWarning ( lua_State *Lua )
{
    SGZLogger.warn("LUA: %s", lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZInterpret_Proxy::LogDebug ( lua_State *Lua )
{
    SGZLogger.debug("LUA: %s", lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZInterpret_Proxy::LogError ( lua_State *Lua )
{
    SGZLogger.quit("LUA: %s", lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZInterpret_Proxy::Debug ( lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    #ifdef DEBUG_ON
        lua_pushboolean(Lua, true);
    #else
        lua_pushboolean(Lua, false);
    #endif

    return 1;
}

#include <fstream>

int SGZInterpret_Proxy::WriteIngameConfig ( lua_State *Lua )
{
    fstream file;

    file.open ("data/scripts/ingameConfig.lua", fstream::out);
    file << "musicVolume = " << (float)lua_tonumber(Lua, 1) << ";" << endl;
    file << "soundVolume = " << (float)lua_tonumber(Lua, 2) << ";" << endl;
    file << flush;
    file.close();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZInterpret_Proxy::className[] = "SGZInterpreter";
Lunar<SGZInterpret_Proxy>::RegType SGZInterpret_Proxy::methods[] =
{
    {"Running", &SGZInterpret_Proxy::Running},
    {"Quit", &SGZInterpret_Proxy::Quit},
    {"NextEvent",  &SGZInterpret_Proxy::NextEvent},
    {"Update", &SGZInterpret_Proxy::UpdateInterfaces},
    {"SystemInfo", &SGZInterpret_Proxy::SystemInfo},
    {"RenderInfo", &SGZInterpret_Proxy::RenderInfo},
    {"LogWarning", &SGZInterpret_Proxy::LogWarning},
    {"LogError", &SGZInterpret_Proxy::LogError},
    {"LogDebug", &SGZInterpret_Proxy::LogDebug},
    {"Debug", &SGZInterpret_Proxy::Debug},
    {"GetFps", &SGZInterpret_Proxy::GetFps},
    {"WriteIngameConfig", &SGZInterpret_Proxy::WriteIngameConfig},
    {0,0}
};
