/** --------------------------------------------------------------------------------
* \file IWindow.h
* \brief The Interface for launching a Window
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _IWINDOW_H_
#define _IWINDOW_H_

#include <string>
#include "CDebug.h"

class IWindow
{
    public:
    virtual ~IWindow() {}

    virtual int SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP ) = 0;
    /** This creates a window with the title named. */

    virtual int DestroyWindow( void ) = 0;
    /** This destroys the window number defined. */

    virtual bool UpdateWindow( void ) = 0;
    /** Tell us to update the window */

    virtual int SetFullScreen(bool set) = 0;
    /** Setup Fullscreen mode */

    virtual bool TakeScreenshot( void ) = 0;
    /** Takes a screenshot */

};

#endif

/** Changelog for this file:
*/
