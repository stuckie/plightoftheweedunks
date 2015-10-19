/** --------------------------------------------------------------------------------
* \file SDLGLWindow.cpp
* \brief SDLGL Interface for launching a Window
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#include "SDLGLWindow.h"
#include "../../../common/engine/CInterpret.h"

int SDLGLWindow::SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP )
{
    /** This creates a window with the title named. */

    /// Creating Window
	Screen = SDL_SetVideoMode(WindowWidth, WindowHeight, WindowBPP, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE | SDL_HWSURFACE | SDL_HWACCEL);
    if(!Screen)
    {
        SGZLogger.warn("Could not create SDL Screen.\n");
        return -1;
    }
    SGZLogger.debug("SDLWindow Created\n");

    /// Set the Window Title
	SDL_WM_SetCaption(title.c_str(),title.c_str());

	/// Set Double Buffering on for GL
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	screenshot = false;

	return 0;
}

int SDLGLWindow::DestroyWindow( void )
{
    /** This destroys the window. */
    Screen = NULL;
    return 0;
}

void* SDLGLWindow::ScreenAccess( void )
{
    /** Returns the surface to the Window */
    return Screen;
}

bool SDLGLWindow::UpdateWindow( void )
{
    if(Screen)
    {
        SDL_GL_SwapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        return true;
    }
    else
        return false;

}

bool SDLGLWindow::TakeScreenshot( void )
{
    screenshot = true;
    return true;
}

int SDLGLWindow::SetFullScreen( bool set )
{
    if(set)
        Screen = SDL_SetVideoMode(Screen->w, Screen->h, Screen->format->BitsPerPixel, SDL_FULLSCREEN | SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE | SDL_HWSURFACE | SDL_HWACCEL);
    else
        Screen = SDL_SetVideoMode(Screen->w, Screen->h, Screen->format->BitsPerPixel, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE | SDL_HWSURFACE | SDL_HWACCEL);

    return 0;
}

