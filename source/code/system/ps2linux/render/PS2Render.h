#include "../../../arch.h"
#include "../../../client/renderer/IRender.h"

#ifndef _PS2RENDER_H_
#define _PS2RENDER_H_
#ifdef PLAT_PS2

class SPS2Render : public IRender
{
    public:
    SPS2Render() {}
    ~SPS2Render() {}

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
};

#endif
#endif
