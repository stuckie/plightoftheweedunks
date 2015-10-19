#include "PS2Render.h"

#ifdef PLAT_PS2LINUX

#include "../../../common/engine/CInterpret.h"

int SPS2Render::CreateRenderer ( void )
{
    SPS2Manager.Initialise(1024);				// 1024 * 4K Pages = 4MB Total
    VIFStaticDMA.Initialise(512);				// 512 * 4K Pages = 2MB Static DMA
    VIFDynamicDMA.Initialise(256);				// 256 * 4K Pages * 2 Buffers = 2MB Dynamic DMA##
    SPS2Manager.InitScreenClear(0, 0, 0);			// Set screen to Black

    return 0;
}

int SPS2Render::UpdateScreen( void )
{
    /** This updates the screen */

    return 0;
}

int SPS2Render::StopRenderer( void )
{
    /** This stops the Renderer */


    return 0;
}

int SPS2Render::StartRenderer( void )
{
    /// already started!
    return 0;
}

int SPS2Render::SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP )
{
    /** Tell the renderer to create a window */
    return 0;
}

int SDLRender::SGZCloseWindow( void )
{
    /** Close The Window - We can't DO this in SDL until the end! */
    return 0;
};

int SDLRender::SetFullScreen( bool set )
{
    /** Setup Fullscreen mode */
    return  0;
}

void* SDLRender::GetScreen( void )
{
    /** Get the screen to draw on from the Window */
    return NULL;
}

int SPS2Render::TakeScreenshot( void )
{
    return 0;
}


#endif
