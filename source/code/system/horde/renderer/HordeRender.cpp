#include "HordeRender.h"
#include "Horde3D.h"
#include "Horde3DUtils.h"

HordeRender::HordeRender()
{

}

HordeRender::~HordeRender()
{
    Horde3D::release();
}

int HordeRender::CreateRenderer ( void )
{
    /** This creates and sets up the Renderer */


    if (SDL_Init(SDL_INIT_VIDEO==-1))
    {
        SGZLogger.warn("Couldn't init SDL.\n");
        return -1;
    }
    else SGZLogger.debug("SDL initialised!\n");

    SDL_ShowCursor(SDL_DISABLE);

    Window = new SDLGLWindow;

    return 0;
}

int HordeRender::UpdateScreen( void )
{
    /** This updates the screen */
    Horde3DUtils::dumpMessages();

    Window->UpdateWindow();

    return 0;
}

int HordeRender::StartRenderer( void )
{


    return 0;
}

int HordeRender::TakeScreenshot( void )
{
    /** Takes a screenshot */
    return Window->TakeScreenshot();
}

int HordeRender::StopRenderer( void )
{
    /** This stops the Renderer */
    Horde3DUtils::dumpMessages();
    Window->DestroyWindow();

    return 0;
}

int HordeRender::SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP )
{
    /** Creates a Window */
    return Window->SGZCreateWindow(title, WindowWidth, WindowHeight, WindowBPP);
}

int HordeRender::SGZCloseWindow( void )
{
    /** Closes a Window */
    return Window->DestroyWindow();
}

int HordeRender::SetFullScreen( bool set )
{
    /** Toggles fullscreen ( for those that support it ) */
    return Window->SetFullScreen(set);
}

void* HordeRender::GetScreen( void )
{
    /** Returns the current Window Screen to draw */

    return NULL;
}

