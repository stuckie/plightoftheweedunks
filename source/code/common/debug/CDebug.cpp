/** -------------------------------------------------------------------------------
    \file debug.cpp
    \brief Contains debug functions

    File Maintainer - Steven "Stuckie" Campbell

   ===============================================================================*/

#include "CDebug.h"		    //!< include all the DEFINES for the error codes

CDebug::CDebug()
{
    /// Constructor

    verbose = false;        //!< By default, we want to be quiet! shhh...
    #ifdef DEBUG_ON
    verbose = true;
    #endif

    errorfile = fopen("error.txt", "w");        //!< Opens the error file, error.txt

    if ((warnfile = fopen("warning.txt", "a"))==NULL)   //!< If there's an error opening it..
	{
        printf("CAN'T OPEN WARNING.TXT !!!!\n");
        quit("Can't Write Device -- warning.txt");	//!< ABNORMAL QUIT!
    }		    			                            //!< ELSE:

    if(verbose)                                             //!< If we've got verbose turned on
    {
        debugfile = fopen("debug.txt", "a");                 //!< ELSE:
    }
}

CDebug::~CDebug()
{
    fclose(errorfile);                                      //!< Closes the file
    if(debugfile)
    fclose(debugfile);				                    //!< Close the debug file
    fclose(warnfile);				                    //!< Close the file

    /// Destructor
}

int CDebug::debug ( std::string message, ... )
/** ---------------------------------------------------------
    This function both prints a debug message to the console
    and to a "debug.txt" file that resides in the same dir.
    Hopefully this should aid debugging as there's a complete
    copy of all the debug messages in a txt file for easy
    reference.  -- Steven Campbell 1/2/06

    Fixed on 5th April 2007 -- now works exactly like f/printf
    ---------------------------------------------------------*/
{
    va_list args;                                           //!< Setup an argument list

    if(verbose)                                             //!< If we've got verbose turned on
    {
        if(!debugfile){
            printf("CAN'T OPEN DEBUG.TXT !!!!\n");
            quit("Can't Write Device -- Debug.txt");	//!< ABNORMAL QUIT!
            return 1;
        }
        va_start (args, message);                           //!< Add an arguments from the message to it (stuff like %d %f etc..)
        vfprintf (debugfile, message.c_str(), args);                //!< Print to the debug file the formatted message
        va_end (args);                                      //!< End the argument list

        fflush(debugfile);

        va_start (args, message);                           //!< Start the argument list again
        vprintf (message.c_str(), args);                            //!< This time, print it to the screen
        va_end (args);                                      //!< End the argument list
    }

	return 0;		    			                        //!< Return 0 - No Errors
}

int CDebug::quit ( std::string message, ... )
/** ---------------------------------------------------------
   This function prints a reason should the program quit
   for some strange reason.
   It could be a part of the debug function.. but I've
   seperated it as debugging doesn't always mean an error
   that causes the program to die.
   An "error.txt" is forcibly created and written to.
   Since this would be the last function before quitting,
   any contents are overwritten. -- Steven Campbell 1/2/06

   Fixed on 5th April 2007 -- now works exactly like f/printf
   ---------------------------------------------------------*/
{
    va_list args;                                           //!< Setup an Argument List

    va_start (args, message);                               //!< Starts the argument list
    vfprintf (errorfile, message.c_str(), args);            //!< Dumps to the error file the formatted message
    va_end (args);                                          //!< Ends the argument list

    fflush(errorfile);                                      //!< Closes the file

    if(verbose)                                             //!< If we've got verbose turned on
    {
        va_start (args, message);                           //!< Starts the argument list
        vprintf (message.c_str(), args);                    //!< Prints the message to the console
        va_end (args);                                      //!< Ends the argument list
    }

	return 0;                                               //!< Return 0 - No Errors
}

int CDebug::warn ( std::string message, ... )
/** ---------------------------------------------------------
    This function both prints a warning message to the console
    and to a "warning.txt" file that resides in the same dir.
    We print this message regardless of verbosity and debug on
    ---------------------------------------------------------*/
{
        time_t curtime;                                     //!< To hold the Current Time
        struct tm *loctime;                                 //!< Structure for the Local System Time

        curtime = time (NULL);                              //!< This grabs the current time
        loctime = localtime (&curtime);                     //!< Changes it to Local System Time

        if (!warnfile)   //!< If there's an error opening it..
		{
                printf("CAN'T OPEN WARNING.TXT !!!!\n");
                quit("Can't Write Device -- warning.txt");	//!< ABNORMAL QUIT!
                return 1;
		}		    			                            //!< ELSE:

        va_list args;                                       //!< Setup an argument list
        va_start (args, message);                           //!< Add an arguments from the message to it (stuff like %d %f etc..)
        fprintf (warnfile, "[!!]%s[!!]--> ",                //!< Prints the current time to the warning file
                asctime(loctime));
        vfprintf (warnfile, message.c_str(), args);                 //!< Print to the warning file the formatted message
        va_end (args);                                      //!< End the argument list

        fflush(warnfile);				                    //!< Close the file

        va_start (args, message);                           //!< Start the argument list again
        printf ("[!!]%s[!!]--> ",asctime(loctime));         //!< Prints the current time to the screen
        vprintf (message.c_str(), args);                            //!< Prints the rest of the message to the screen
        va_end (args);                                      //!< End the argument list

	return 0;		    			                        //!< Return 0 - No Errors
}

CDebug DebugLog;

/** Changelog for this file:

    -------- 30th April 2008

    Rejiggered some bits around as per suggestion of Bryan "DerUnterMensch"/"cefwyn" Morgan so it flushes logs rather than open/close
    files all the time.

    -------- 28th July 2007

    Added the Warn function
    Also, classified the debug stuff... just cause I can ;) -- Stuckie

    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    Only major change since the original was fixing a stupid bug so that it actually parsed the argument list properly.
    They now function more like PrintF than they used to.
    -- Stuckie

*/
