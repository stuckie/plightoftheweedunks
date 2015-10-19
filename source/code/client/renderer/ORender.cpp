/** --------------------------------------------------------------------------------
* \file ORender.cpp
* \brief The Interface for the Renderer
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#include "ORender.h"

int ORender::CreateRenderer ( void )
{
    /** This creates and sets up the Renderer */
    SGZLogger.debug("Renderer Starting.\n");
    return Renderer.CreateRenderer();
}

int ORender::StartRenderer( void )
{
    return Renderer.StartRenderer();
}

int ORender::UpdateScreen( void )
{
    /** This updates the screen */
    return Renderer.UpdateScreen();
}

int ORender::StopRenderer( void )
{
    /** This stops the Renderer */
    SGZLogger.debug("Renderer Stopping.\n");
    return Renderer.StopRenderer();
}

int ORender::SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP )
{
    /** Creates the Window */
    return Renderer.SGZCreateWindow( title, WindowWidth, WindowHeight, WindowBPP );
}

int ORender::SGZCloseWindow( void )
{
    /** Closes The Window */
    return Renderer.SGZCloseWindow();
}

int ORender::SetFullScreen( bool set )
{
    /** Set Fullscreen */
    return Renderer.SetFullScreen(set);
}

void* ORender::GetScreen( void )
{
    /** Get the Screen for drawing on */
    return Renderer.GetScreen();
}

int ORender::TakeScreenshot( void )
{
    return Renderer.TakeScreenshot();
}

/** Changelog for this file:
*/

