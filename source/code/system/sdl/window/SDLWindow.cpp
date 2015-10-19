/** --------------------------------------------------------------------------------
* \file SDLWindow.cpp
* \brief SDL Interface for launching a Window
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#include "SDLWindow.h"
#include "../../../common/engine/CInterpret.h"

int SDLWindow::SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP )
{
    /** This creates a window with the title named. */

    #ifndef PLAT_GP2X
    /// Creating Window
	Screen = SDL_SetVideoMode(WindowWidth, WindowHeight, WindowBPP, SDL_ANYFORMAT | SDL_DOUBLEBUF);
    if(!Screen)
    {
        SGZLogger.warn("Could not create SDL Screen.\n");
        return -1;
    }

    /// Set the Window Title
	SDL_WM_SetCaption(title.c_str(),title.c_str());
	#endif

	#ifdef PLAT_GP2X
	WindowWidth=320;
	WindowHeight=340;
	Screen = SDL_SetVideoMode(WindowWidth, WindowHeight, 16, SDL_DOUBLEBUF | SDL_HWSURFACE);
	#endif

    /// Setup the Back Buffer Rect
	BackBuffer.x=0;
	BackBuffer.y=0;
	BackBuffer.w=WindowWidth;
	BackBuffer.h=WindowHeight;

	screenshot = false;

	return 0;
}

int SDLWindow::DestroyWindow( void )
{
    /** This destroys the window. */
    Screen = NULL;
    return 0;
}

void* SDLWindow::ScreenAccess( void )
{
    /** Returns the surface to the Window */
    return Screen;
}

bool SDLWindow::TakeScreenshot( void )
{
    screenshot = true;
    return true;
}

bool SDLWindow::UpdateWindow( void )
{
    if(Screen)
    {
        if(screenshot)
        {
            char screenshotName[64];
            sprintf(screenshotName, "screenshot%d.bmp", (int)time(NULL));
            SDL_SaveBMP(Screen, screenshotName);
            screenshot = false;
        }
        SDL_Flip(Screen);
        SDL_FillRect(Screen, &BackBuffer, 0);
        return true;
    }
    else
        return false;

}

int SDLWindow::SetFullScreen( bool set )
{
    if(set)
        Screen = SDL_SetVideoMode(Screen->w, Screen->h, Screen->format->BitsPerPixel, SDL_ANYFORMAT|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    else
        Screen = SDL_SetVideoMode(Screen->w, Screen->h, Screen->format->BitsPerPixel, SDL_ANYFORMAT|SDL_DOUBLEBUF);

    return 0;
}
