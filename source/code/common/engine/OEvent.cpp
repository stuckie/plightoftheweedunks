/** -----------------------------------------------------------------------------
* \file OEvent.cpp                                                                *
* \brief The Event Objects                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Event Interface is literally used as a generic struct for all events.
*/

#include "OEvent.h"
#include "CInterpret.h"

bool WindowEvent::doEvent() const
{
    SGZInterpret.accessClient()->OpenWindow(WindowName, WindowWidth, WindowHeight, WindowBPP);
    return true;
}

void WindowEvent::setWindowParams( std::string Name, int Width, int Height, int BPP )
{
    /** Set up the Window */
    WindowName = Name;
    WindowWidth = Width;
    WindowHeight = Height;
    WindowBPP = BPP;
}

bool FullScreenEvent::doEvent() const
{
    SGZInterpret.accessClient()->SetFullScreen(fullscreen);
    return true;
}

bool QuitEvent::doEvent() const
{
    SGZInterpret.Quit();
    return true;
}

bool MouseEvent::doEvent() const
{
    SGZLogger.debug("X: %d Y: %d Button: %d\n", mouseX, mouseY, button);
    return true;
}

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

