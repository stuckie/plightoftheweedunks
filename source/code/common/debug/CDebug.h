/** -------------------------------------------------------------------------------
    \file debug.h
    \brief Contains debug error codes and prototypes

    File Maintainer - Steven "Stuckie" Campbell

   =============================================================================== */

#ifndef _DEBUG_H_
#define _DEBUG_H_
#include <time.h>                   //!< Include the Time header
#include <stdio.h>		    //!< include STanDard Input/Output functions
#include <stdarg.h>         //!< include STanDard ARGument functions
#include "CSingleton.h"           //!< Include the Singleton Class
#include <string>

class CDebug : public CSingleton<CDebug>
{
    public:

        CDebug();                       //!< Debug Constructor
        ~CDebug();                      //!< Debug Destructor

        /// Prints a DEBUG message to debug.txt and stdout (console) -- appends to whatever was there
        int debug ( std::string message, ... );

        /// Prints a QUIT message to error.txt and stdout (console) -- overwrites whatever was there
        int quit ( std::string message, ... );

        /// Prints a WARNING message to stdout regardless of verbose settings -- and to a warnings.txt
        int warn ( std::string message, ... );

        /// Sets verbose on and off, basically
        void setVerbose ( bool setting ) { verbose = setting; }

    private:
        /// Whether we print out debug messages or not
        bool verbose;
        FILE *errorfile, *warnfile, *debugfile;
};

#define SGZLogger CDebug::GetSingleton()  //!< Macro to call this function easily

#endif

/** Changelog for this file:

    -------- 4th August 2007

    Debug Class is now a singleton.. not entirely sure why I DIDN'T do that to begin with, actually

    -------- 28th July 2007

    Added the Warn function
    Also, classified the debug stuff... just cause I can ;) -- Stuckie

    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    This is still the original revision of this file. Nothing has been changed. -- Stuckie

*/
