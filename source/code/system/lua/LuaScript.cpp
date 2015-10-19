/** -----------------------------------------------------------------------------
* \file LuaScript.cpp                                                             *
* \brief The Lua Script Object                                                    *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Lua Script Object is for communicating with the Scripting Language Lua
*/

#include "LuaScript.h"
#include "LuaProxies.h"
#include "lunar.h"
#include "../../common/engine/CInterpret.h"

bool LuaScript::CreateInterface()
{
    /** Create a script interface */
    Lua = lua_open();
    if (NULL == Lua)
    {
        SGZLogger.warn("Error Initializing lua\n");
        return false;
    }
    else
        SGZLogger.debug("Lua Initialised\n");

    luaL_openlibs(Lua);
    Lunar<SGZRender_Proxy>::Register(Lua);
    Lunar<SGZControl_Proxy>::Register(Lua);
    Lunar<SGZInterpret_Proxy>::Register(Lua);
    Lunar<SGZAudio_Proxy>::Register(Lua);
    Lunar<SGZEntityMan_Proxy>::Register(Lua);
    Lunar<SGZTextureMan_Proxy>::Register(Lua);
    Lunar<SGZLevelMan_Proxy>::Register(Lua);
    Lunar<SGZamBX_Proxy>::Register(Lua);
    Lunar<SGZTimer_Proxy>::Register(Lua);
    Lunar<SGZHorde_Proxy>::Register(Lua);
    Lunar<SGZode_Proxy>::Register(Lua);
    Lunar<SGZCamera_Proxy>::Register(Lua);
    Lunar<SGZAI_Proxy>::Register(Lua);
    Lunar<SGZEvent_Proxy>::Register(Lua);

    return true;
}

bool LuaScript::DestroyInterface()
{
    /** Destroy a script interface */
    lua_close(Lua);

    SGZLogger.debug("Lua DeInitialised\n");

    return true;
}

bool LuaScript::LoadExternalScript( std::string ScriptFile )
{
    /** Let's us load an external script file */
    if (luaL_loadfile(Lua, ScriptFile.c_str()) || lua_pcall(Lua, 0, 0, 0))
    {
        SGZLogger.debug("Cannot read file: %s\n", lua_tostring(Lua, -1));
        return false;
    }

    return true;

}

bool LuaScript::LoadConfigScript()
{
    /** Let's load up our configuration script */
    std::string WindowName,
                MainScript;
                //MainFunc;

    int WindowWidth,
        WindowHeight,
        WindowBPP;

    if (luaL_loadfile(Lua, "data/scripts/config.sgz") || lua_pcall(Lua, 0, 0, 0))
    {
        SGZLogger.warn("Cannot read configuration file: %s\n", lua_tostring(Lua, -1));
        return false;
    }

    lua_getglobal(Lua, "MainScript");
    lua_getglobal(Lua, "MainFunc");

    lua_getglobal(Lua, "WindowName");
    lua_getglobal(Lua, "WindowWidth");
    lua_getglobal(Lua, "WindowHeight");
    lua_getglobal(Lua, "WindowBPP");

    if (!lua_isstring(Lua, -6))
    {
        SGZLogger.warn("'MainScript' in main.sgz should be a string\n");
        return false;
    }
    if (!lua_isstring(Lua, -5))
    {
        SGZLogger.warn("'MainFunc' in main.sgz should be a string\n");
        return false;
    }
    if (!lua_isstring(Lua, -4))
        SGZLogger.warn("'WindowName' in main.sgz should be a string\n");
    if (!lua_isnumber(Lua, -3))
        SGZLogger.warn("'WindowWidth' in main.sgz should be a number\n");
    if (!lua_isnumber(Lua, -2))
        SGZLogger.warn("'WindowHeight' in main.sgz should be a number\n");
    if (!lua_isnumber(Lua, -1))
        SGZLogger.warn("'WindowBPP' in main.sgz should be a number\n");

    MainScript.insert(0, lua_tostring(Lua, -6));
    MainFunc.insert(0, lua_tostring(Lua, -5));

    WindowName.insert(0, lua_tostring(Lua, -4));
    WindowWidth = (int)lua_tonumber(Lua, -3);
    WindowHeight = (int)lua_tonumber(Lua, -2);
    WindowBPP = (int)lua_tonumber(Lua, -1);

    SGZLogger.debug("Window Name: %s, Width: %d, Height: %d, BPP: %d\n", WindowName.c_str(), WindowWidth, WindowHeight, WindowBPP);
    SGZLogger.debug("Game Function: %s in %s\n", MainFunc.c_str(), MainScript.c_str());

    LoadExternalScript(MainScript);

    return true;
}

bool LuaScript::SaveConfigScript( std::string config )
{
    /** Save the configuration script */
    FILE *configscript;
    const char delimiters[] = ":";
    char *token, *cp;

    configscript = fopen ("data/scripts/config.sgz","w");
    if (configscript==NULL)
    {
        SGZLogger.warn("Can't create data/scripts/main.sgz config file!\n");
        return false;
    }

    fprintf(configscript,"-- This is the main SGZEngine script file \n-- We basically just set some things up and call our \"main function\" from here\n\n");

    cp = strdup (config.c_str());                   /** store a writable copy of the C-String
                                                        reason for this is that token has the habit
                                                        of mangling the original stream.
                                                        If we only feed it the copy of the string,
                                                        we still retain the original incase we need it.

                                                        WE don't, but it's good practice, and might need it later...
                                                    */

        /***************** Window Configuration ****************/
    fprintf(configscript,"--Window Creation\n");

    token = strtok (cp, delimiters);              /** WindowWidth */
    if(token)
        fprintf(configscript,"WindowWidth = %s\n",token);
    else
    {
        SGZLogger.warn("Problem creating the config script -- WindowWidth is mangled.\n");
        fclose(configscript);
        return false;
    }

    token = strtok (NULL, delimiters);                /** WindowHeight */
    if(token)
        fprintf(configscript,"WindowHeight = %s\n",token);
    else
    {
        SGZLogger.warn("Problem creating the config script -- WindowHeight is mangled.\n");
        fclose(configscript);
        return false;
    }

    token = strtok (NULL, delimiters);              /** WindowBPP */
    if(token)
        fprintf(configscript,"WindowBPP = %s\n",token);
    else
    {
        SGZLogger.warn("Problem creating the config script -- WindowBPP is mangled.\n");
        fclose(configscript);
        return false;
    }

    token = strtok (NULL, delimiters);              /** WindowName */
    if(token)
        fprintf(configscript,"WindowName = %s\n",token);
    else
    {
        SGZLogger.warn("Problem creating the config script -- WindowName is mangled.\n");
        fclose(configscript);
        return false;
    }

        /***************** Script Configuration ****************/

    fprintf(configscript,"--Script Configuration\n");

    token = strtok (NULL, delimiters);              /** MainScript */
    if(token)
        fprintf(configscript,"MainScript = \"%s\"\n",token);
    else
    {
        SGZLogger.warn("Problem creating the config script -- MainScript is mangled.\n");
        return false;
    }

    token = strtok (NULL, delimiters);              /** MainFunc */
    if(token)
        fprintf(configscript,"MainFunc = \"%s\"\n",token);
    else
    {
        SGZLogger.warn("Problem creating the config script -- MainFunc is mangled.\n");
        return false;
    }

    time_t curtime;                                     //!< To hold the Current Time
    struct tm *loctime;                                 //!< Structure for the Local System Time

    curtime = time (NULL);                              //!< This grabs the current time
    loctime = localtime (&curtime);                     //!< Changes it to Local System Time

    fprintf (configscript, "--Last edited on %s ",      //!< Prints the current time to the config script
                asctime(loctime));

    fclose(configscript);

    SGZLogger.warn("Config file data/scripts/config.sgz was (re)created.\n");

    return true;
}

bool LuaScript::UpdateScripts()
{
    lua_getglobal (Lua, "main");
    if(lua_pcall(Lua, 0, 0, 0))
    {
        SGZLogger.warn("LUA: %s\n", lua_tostring(Lua, -1));
        return false;
    }
    return true;
}

bool LuaScript::CallFunction(std::string Function)
{
    lua_getglobal(Lua, Function.c_str());
    if(lua_pcall(Lua, 0, 0, 0))
    {
        SGZLogger.warn("LUA: %s\n", lua_tostring(Lua, -1));
        return false;
    }
    return true;
}

bool LuaScript::CallFunctionNoError(std::string Function)
{
    lua_getglobal(Lua, Function.c_str());
    if(lua_pcall(Lua, 0, 0, 0))
        return false;
    return true;
}

bool LuaScript::CallFunction(std::string Function, char* VarList, ... )
{
    va_list vars;
    int numArgs, numRes;

    va_start(vars, VarList);
    lua_getglobal(Lua, Function.c_str());

    for(numArgs = 0; *VarList; numArgs++)
    {
        luaL_checkstack(Lua, 1, "Too Many Arguments");

        switch(*VarList++)
        {
            case 'd':
                lua_pushnumber(Lua, va_arg(vars, double));
                break;

            case 'i':
                lua_pushinteger(Lua, va_arg(vars, int));
                break;

            case 's':
                lua_pushstring(Lua, va_arg(vars, char *));
                break;

            case '>':
                goto endargs;

            default:
                SGZLogger.warn("invalid option (%c)", *(VarList - 1));
        }
    }
    endargs:

    numRes = strlen(VarList);

    if (lua_pcall(Lua, numArgs, numRes, 0) != 0 )
        SGZLogger.warn("Error calling '%s': %s", Function.c_str(), lua_tostring(Lua, -1));

    numRes = -numRes;
    while (*VarList)
    {
        switch (*VarList++)
        {
            case 'd':
                if(!lua_isnumber(Lua, numRes))
                    SGZLogger.warn("Wrong Result Type");

                *va_arg(vars, double *) = lua_tonumber(Lua, numRes);
                break;

            case 'i':
                if(!lua_isnumber(Lua, numRes))
                    SGZLogger.warn("Wrong Result Type");

                *va_arg(vars, int *) = (int)lua_tonumber(Lua, numRes);
                break;

            case 's':
                if(!lua_isstring(Lua, numRes))
                    SGZLogger.warn("Wrong Result Type");

                *va_arg(vars, const char **) = lua_tostring(Lua, numRes);
                break;

            default:
                SGZLogger.debug("invalid option (%c)", *(VarList -1 ));
        }

        numRes++;
    }

    va_end(vars);

    return true;
}

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

