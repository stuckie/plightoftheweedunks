/** -----------------------------------------------------------------------------
* \file OScript.h                                                                 *
* \brief The Script Object                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Script Object is for communicating and reading scripts.

    We're hardcoding to Lua for quickness just now
*/

#ifndef _OSCRIPT_H_
#define _OSCRIPT_H_

#include "IScript.h"
#include "arch.h"
#include "CDebug.h"

/** Now the fun bit, depending on what scripting language we use depends on what we call here */
#ifdef SCRIPT_LUA
    #include "LuaScript.h"
#endif
#ifdef SCRIPT_PYTHON
    #include "../../system/python/PythonScript.h"
#endif
#ifdef SCRIPT_RUBY
    #include "../../system/ruby/RubyScript.h"
#endif

class OScript : public IScript
{
    public:

    OScript() {}
    ~OScript() {}

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
    /** Call a Specific function */

    private:

    /** Again, depending on what scripting language we use depends on what we call here */
    #ifdef SCRIPT_LUA
        LuaScript Script;
    #endif
    #ifdef SCRIPT_PYTHON
        PythonScript Script;
    #endif
    #ifdef SCRIPT_RUBY
        RubyScript Script;
    #endif
};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/


