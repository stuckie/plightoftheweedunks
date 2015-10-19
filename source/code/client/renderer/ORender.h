/** --------------------------------------------------------------------------------
* \file ORender.h
* \brief The Renderer Object
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _ORENDER_H_
#define _ORENDER_H_

#include "IRender.h"
#include "arch.h"
#include "CDebug.h"

/** Don't you just love the cross-platform multi-platform goodness?
    Here we go with a large complicated whack of system renderers!
    There is no doubt a FAR better way to do this...              */

#ifdef REND_SDL
    #include "SDLRenderer.h"
#endif
#ifdef REND_SDLGL
    #include "SDLGLRenderer.h"
#endif
#ifdef REND_OPENGL
    #include "GLRenderer.h"
#endif
#ifdef REND_DIRECTX
    #include "DXRenderer.h"
#endif
#ifdef REND_WINAPI
    #include "WINRenderer.h"
#endif
#ifdef REND_SPS2
    #include "PS2Renderer.h"
#endif
#if defined(REND_SDLOGRE) || defined(REND_OGRE)
    #include "OGRERenderer.h"
#endif
#if defined(REND_HORDE) || defined(REND_SDLHORDE)
    #include "HordeRender.h"
#endif

class ORender : public IRender
{
    public:
    ORender() {}
    ~ORender() {}

    int CreateRenderer ( void );
    /** This creates and sets up the Renderer */

    int UpdateScreen( void );
    /** This updates the screen */

    int StopRenderer( void );
    /** This stops the Renderer */

    int StartRenderer( void );
    /** This starts the Renderer */

    int SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP );
    /** Create a Window for the Renderer to play with */

    int SGZCloseWindow( void );
    /** Closes the Window */

    int SetFullScreen( bool set );
    /** Set FullScreen Mode */

    void* GetScreen( void );
    /** Get the current Window's screen to draw on */

    int TakeScreenshot ( void );
    /** takes a screenshot */

    private:

    #ifdef REND_SDL
        SDLRender       Renderer;
    #endif
    #ifdef REND_SDLGL
        SDLGLRender     Renderer;
    #endif
    #ifdef REND_OPENGL
        GLRender        Renderer;
    #endif
    #ifdef REND_DIRECTX
        DXRender        Renderer;
    #endif
    #ifdef REND_WINAPI
        WINRender       Renderer;
    #endif
    #ifdef REND_SPS2
        SPS2Render      Renderer;
    #endif
    #if defined(REND_OGRE) || defined(REND_SDLOGRE)
        OGRERender      Renderer;
    #endif
    #if defined(REND_HORDE) || defined(REND_SDLHORDE)
        HordeRender     Renderer;
    #endif

};

#endif

/** Changelog for this file:
*/

