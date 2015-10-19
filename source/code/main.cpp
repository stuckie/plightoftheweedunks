/** -------------------------------------------------------------------------------
// \file main.cpp
// \brief Contains the basic start-up code and "glue" for the game
//
// File Maintainer - Stuckie
//
// CREDITS     : Was originally based upon Dr Henry Fortuna's PS2 Game Framework Code
//
// =============================================================================== */

// HEADER INCLUDES
#include "main.h"					                        //!< Include this files header -- bit useless though
#include "arch.h"                                           //!< Really cheap hack to change defines for Arch specific stuff
#include "common/engine/CInterpret.h"    			        //!< Include the Interpretation Class
#include "common/debug/CDebug.h"		                    //!< Include header for debugging
#include <stdlib.h>

#ifdef PLAT_GP2X                                            //!< GP2X Specific Code Starts Here
	#include "unistd.h"			    	                    //!< Include for jumping back to the GP2X Menu
#endif                                                      //!< GP2X Specific Code Ends Herez

#ifdef OS_WIN32
    #define WIN32_LEAN_AND_MEAN
    #include "windows.h"
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
    #else
    int main( void )
#endif
{
    #ifdef OS_WIN32
        SGZLogger.debug("Windows gave us Instance %d with variables %s\n", hInst, strCmdLine);
    #endif
    try
    {
        SGZInterpret.Start ( );
    }
    catch (...)
    {
        SGZLogger.warn("We cannot startup!\n");
        SGZLogger.quit("We cannot startup!\n");
        return -1;
    }

    while( SGZInterpret.Running() )
        try
        {
            SGZInterpret.Loop();
        }
        catch (...)
        {
            SGZLogger.warn("Engine has crashed!\n");
            SGZLogger.quit("Engine has crashed!\n");
        }

    try
    {
        SGZInterpret.Stop();
    }
    catch (...)
    {
        SGZLogger.warn("We've crashed shutting down!\n");
        SGZLogger.quit("We've crashed shutting down!\n");
    }

    #ifdef PLAT_GP2X                                    //!< GP2X Specific Code Here
        /// The GP2X is a weird beastie, and we need to go back to put a callback to the menu cause it won't go there itself
        chdir("/usr/gp2x");                             //!< Change Directory to /usr/gp2x
        execl(  "/usr/gp2x/gp2xmenu",                   //!< Execute /usr/gp2x/gp2xmenu
                "/usr/gp2x/gp2xmenu", NULL);            //!< We have no params being passed to gp2xmenu, so NULL the arg list
    #endif                                              //!< End of GP2X Specific Code

    return 0;
}

/** Changelog for this file:

    -------- 15th July 2007

    Added in the WinAPI stuff salvaged from PowerOUT... should mean that I can finally update PowerOUT to run in SDL :)

    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    This has changed to include changing of which mode the game should be in from the command line a while ago.
    That's the only major change though.
    -- Stuckie

    Original Changelog Appended....

    // ---------------------------------------------------------
    // This is the MAIN function, obviously...
    // Trying to keep this as bare as possible.. shouldn't need
    // to really do ANYTHING here, have the rest of the scripts
    // deal with that. -- Stuckie 1/2/06
    // ---------------------------------------------------------
    // Well, let's totally destroy the above comment ;)
    // We're checking for a couple of commandline params and if
    // it finds any of them, DIRECTLY start that system, else
    // we should get CGame to call up a box asking what the user
    // wants us to do. But this will be added later, so for now
    // we will just default to Listen Mode. -- Stuckie 22/1/07
    // ---------------------------------------------------------

*/
