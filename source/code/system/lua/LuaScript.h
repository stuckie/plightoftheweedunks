/** -----------------------------------------------------------------------------
* \file LUAScript.h                                                                 *
* \brief The Lua Script Object                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Lua Script Object is for communicating and reading scripts.
    Specifically dealing with Lua
*/

#ifndef _LUASCRIPT_H_
#define _LUASCRIPT_H_

#include "../../arch.h"
#include "../../common/debug/CDebug.h"
#include "../../common/script/IScript.h"

#ifdef pedanticGCC
extern "C"
{
#endif
    #include "../../system/lua/lua.h"
    #include "../../system/lua/lauxlib.h"
    #include "../../system/lua/lualib.h"
#ifdef pedanticGCC
}
#endif

class LuaScript : public IScript
{
    public:

    LuaScript() {}
    ~LuaScript() {}

    bool CreateInterface();
    /** Create a script interface */

    bool DestroyInterface();
    /** Destroy a script interface */

    bool UpdateScripts();
    /** Update the Scripts */

    bool LoadExternalScript( std::string ScriptFile );
    /** Let's us load an external script file */

    bool LoadConfigScript();
    /** Let's load up our configuration script */

    bool SaveConfigScript( std::string config );
    /** Save the configuration script */

    bool CallFunction ( std::string Function );
    bool CallFunctionNoError ( std::string Function );
    bool CallFunction ( std::string Function, char* ParamVars, ... );

    /** Call Specific Function from File */

    private:
    lua_State *Lua;
    std::string MainFunc;
};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

