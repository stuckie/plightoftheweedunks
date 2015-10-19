/** -------------------------------------------------------------------------------
* \file IScript.h
* \brief The Script Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

/**
    Although I'm only really going to be supporting Lua, if I create a generic Interface from the outset,
    it means that I might be able to support other scripting languages later.

    Would be useful if I have time to do a look at differences between Lua and Python, for instance.
*/

#ifndef _ISCRIPT_H_
#define _ISCRIPT_H_

#include <string>

class IScript
{
    public:
    virtual ~IScript() {}

    virtual bool CreateInterface() = 0;
    /** Create a script interface */

    virtual bool DestroyInterface() = 0;
    /** Destroy a script interface */

    virtual bool UpdateScripts() = 0;
    /** Update the Script interface */

    virtual bool LoadExternalScript( std::string ScriptFile ) = 0;
    /** Let's us load an external script file */

    virtual bool LoadConfigScript() = 0;
    /** Let's load up our configuration script */

    virtual bool SaveConfigScript( std::string config ) = 0;
    /** Save the configuration script */

    virtual bool CallFunction ( std::string Function ) = 0;
    virtual bool CallFunction ( std::string Function, char* ParamVars, ... ) = 0;
    /** Call a specific Function */

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

