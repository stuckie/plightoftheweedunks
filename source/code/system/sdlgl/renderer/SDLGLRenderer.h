#ifndef _SDLGLRENDERER_H_
#define _SDLGLRENDERER_H_

#include "../../../arch.h"

#ifdef REND_SDLGL

#include "IRender.h"
#include "SDLGLWindow.h"
#include "CDebug.h"

#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL/SDL.h"

class SDLGLRender : public IRender
{
    public:
     SDLGLRender() {};
    ~SDLGLRender() {};

    int CreateRenderer ( void );
    /** This creates and sets up the Renderer */

    int StartRenderer( void );
    /** Starts the renderer */

    int UpdateScreen( void );
    /** This updates the screen */

    int StopRenderer( void );
    /** This stops the Renderer */

    int SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP );
    /** Creates a Window */

    int SGZCloseWindow( void );
    /** Closes a Window */

    int SetFullScreen( bool set );
    /** Toggles fullscreen ( for those that support it ) */

    void* GetScreen( void );
    /** Returns the current Window Screen to draw */

    int TakeScreenshot ( void ) { return 0; };

    private:
    SDLGLWindow *Window;
};

#endif

#endif
