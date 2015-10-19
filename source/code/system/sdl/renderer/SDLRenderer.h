/** --------------------------------------------------------------------------------
* \file SDLRender.h
* \brief SDL Interface for the Renderer
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _SDLRENDERER_H_
#define _SDLRENDERER_H_

/// Include any needed Interfaces
#include "../../../client/renderer/IRender.h"
#include "../window/SDLWindow.h"

/// Include the SDL Header
#include "SDL/SDL.h"

class SDLRender : public IRender
{
    public:

    SDLRender() {};
    ~SDLRender() {};

    int CreateRenderer ( void );
    /** This creates and sets up the Renderer */

    int StartRenderer ( void );
    /** Starts the Renderer */

    int UpdateScreen( void );
    /** This updates the screen */

    int StopRenderer( void );
    /** This stops the Renderer */

    int SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP );
    /** We create a window to play with */

    int SGZCloseWindow( void );
    /** Closes The Window */

    int SetFullScreen( bool set );
    /** Set Fullscreen mode */

    void* GetScreen( void );

    int TakeScreenshot( void );

    private:

    SDLWindow *Window;      //!< Our Window to Render to

};

#endif

/** Changelog for this file:
*/
