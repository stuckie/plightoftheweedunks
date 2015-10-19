#ifndef _SDLGLWINDOW_H_
#define _SDLGLWINDOW_H_

#include "arch.h"
#include "IWindow.h"
#include "OEvent.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

class SDLGLWindow : public IWindow
{
    public:
    SDLGLWindow() { Screen = NULL; }
    ~SDLGLWindow() {}

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

    bool TakeScreenshot( void );

    private:

    SDL_Surface *Screen;    //!< Pointer to our Screen
    SDL_Rect BackBuffer;    //!< Our Back Buffer
    SDL_Event Event;        //!< For checking Window Events

    bool screenshot;

};


#endif
