/** -----------------------------------------------------------------------------
* \file OScript.cpp                                                               *
* \brief The Script Object                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Script Object is for communicating with the Scripting Language
*/

#include "OScript.h"

bool OScript::CreateInterface()
{
    /** Create a script interface */
    Script.CreateInterface();

    SGZLogger.debug("Script Object Created\n");

    return true;
}

bool OScript::DestroyInterface()
{
    /** Destroy a script interface */
    Script.DestroyInterface();
    SGZLogger.debug("Script Object Destroyed\n");

    return true;
}

bool OScript::LoadExternalScript( std::string ScriptFile )
{
    /** Let's us load an external script file */
    SGZLogger.debug("Loading script %s\n",ScriptFile.c_str());
    if(!Script.LoadExternalScript(ScriptFile))
        return false;

    return true;

}

bool OScript::LoadConfigScript()
{
    /** Let's load up our configuration script */
    SGZLogger.debug("Loading Config Script\n");
    if (!Script.LoadConfigScript())
        return false;

    return true;
}

bool OScript::SaveConfigScript( std::string config )
{
    /** Save the configuration script */
    SGZLogger.debug("Saving Config Script\n");
    if (!Script.SaveConfigScript(config))
        return false;

    return true;
}

bool OScript::UpdateScripts()
{
    return Script.UpdateScripts();
}

bool OScript::CallFunction(std::string Function)
{
    return Script.CallFunction(Function);
}

bool OScript::CallFunctionNoError(std::string Function)
{
    return Script.CallFunctionNoError(Function);
}

bool OScript::CallFunction( std::string Function, char* ParamVars, ... )
{
    va_list vars;
    va_start( vars, ParamVars );
    bool test = Script.CallFunction(Function,ParamVars, vars );
    va_end ( vars );
    return test;
}

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

