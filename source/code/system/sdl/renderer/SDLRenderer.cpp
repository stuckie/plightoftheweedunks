/** --------------------------------------------------------------------------------
* \file SDLRender.cpp
* \brief SDL Interface for the Renderer
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#include "SDLRenderer.h"
#include "../../../common/engine/CInterpret.h"

int SDLRender::CreateRenderer ( void )
{
    /** This creates and sets up the Renderer */
    if (SDL_Init(SDL_INIT_VIDEO==-1))
    {
        SGZLogger.warn("Couldn't init SDL Renderer.\n");
        return -1;
    }
	else SGZLogger.debug("SDL Renderer initialised!\n");

	Window = new SDLWindow;

    return 0;
}

int SDLRender::UpdateScreen( void )
{
    /** This updates the screen */
    SDL_Delay(1);
    Window->UpdateWindow();
    return 0;
}

int SDLRender::StopRenderer( void )
{
    /** This stops the Renderer */
    Window->DestroyWindow();
    Window=NULL;

    return 0;
}

int SDLRender::StartRenderer( void )
{
    /// already started!
    return 0;
}

int SDLRender::SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP )
{
    /** Tell the renderer to create a window */
    return Window->SGZCreateWindow(title, WindowWidth, WindowHeight, WindowBPP);
}

int SDLRender::SGZCloseWindow( void )
{
    /** Close The Window - We can't DO this in SDL until the end! */
    return 0;
}

int SDLRender::SetFullScreen( bool set )
{
    /** Setup Fullscreen mode */
    return Window->SetFullScreen(set);
}

void* SDLRender::GetScreen( void )
{
    /** Get the screen to draw on from the Window */
    return Window->ScreenAccess();
}

int SDLRender::TakeScreenshot( void )
{
    return Window->TakeScreenshot();
}
