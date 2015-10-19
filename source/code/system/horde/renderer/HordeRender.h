#include "../../../arch.h"

#ifndef _HORDERENDER_H_
#define _HORDERENDER_H_

#if defined(REND_HORDE) || defined(REND_SDLHORDE)

#include "IRender.h"
#include "SDLGLWindow.h"

class HordeRender : public IRender
{
    public:
    HordeRender();
    ~HordeRender();

    int CreateRenderer ( void );
    /** This creates and sets up the Renderer */

    int UpdateScreen( void );
    /** This updates the screen */

    int TakeScreenshot( void );
    /** Takes a screenshot */

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

    int StartRenderer( void );

    private:

	/// Engine objects
	SDLGLWindow *Window;

};

#endif
#endif
