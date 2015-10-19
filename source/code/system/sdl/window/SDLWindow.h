/** --------------------------------------------------------------------------------
* \file SDLWindow.h
* \brief SDL Interface for launching a Window
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _SDLWINDOW_H_
#define _SDLWINDOW_H_

#include "../../../arch.h"
#include "../../../client/renderer/window/IWindow.h"
#include "../../../common/engine/OEvent.h"
#include "SDL/SDL.h"

class SDLWindow : public IWindow
{
    public:
    SDLWindow() { Screen = NULL; }
    ~SDLWindow() {}

    int SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP );
    /** This creates a window with the title named. */

    int DestroyWindow( void );
    /** This destroys the window. */

    bool UpdateWindow( void );
    /** Update the Window */

    int SetFullScreen(bool set);
    /** Setup Fullscreen Mode */

    void* ScreenAccess( void );
    /** Returns the surface to the Window */

    bool TakeScreenshot ( void );

    private:

    SDL_Surface *Screen;    //!< Pointer to our Screen
    SDL_Rect BackBuffer;    //!< Our Back Buffer
    SDL_Event Event;        //!< For checking Window Events
    bool screenshot;        //!< Check if we're taking a screenshot

};

#endif

/** Changelog for this file:
*/
