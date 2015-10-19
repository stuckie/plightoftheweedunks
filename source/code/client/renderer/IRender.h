/** --------------------------------------------------------------------------------
* \file IRender.h
* \brief The Interface for the Renderer
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _IRENDER_H_
#define _IRENDER_H_

#include <string>

class IRender
{
    public:
    virtual ~IRender() {}

    virtual int CreateRenderer ( void ) = 0;
    /** This creates and sets up the Renderer */

    virtual int UpdateScreen( void ) = 0;
    /** This updates the screen */

    virtual int TakeScreenshot( void ) = 0;
    /** Takes a screenshot */

    virtual int StopRenderer( void ) = 0;
    /** This stops the Renderer */

    virtual int StartRenderer( void ) = 0;
    /** This starts the Renderer */

    virtual int SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP ) = 0;
    /** Creates a Window */

    virtual int SGZCloseWindow( void ) = 0;
    /** Closes a Window */

    virtual int SetFullScreen( bool set ) = 0;
    /** Toggles fullscreen ( for those that support it ) */

    virtual void* GetScreen( void ) = 0;
    /** Returns the current Window Screen to draw */

};

#endif

/** Changelog for this file:
*/
