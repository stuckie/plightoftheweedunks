/** -----------------------------------------------------------------------------
* \file OClient.h                                                                 *
* \brief The Client Object                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Event Interface is literally used as a generic struct for all events.
*/

#ifndef _OCLIENT_H_
#define _OCLIENT_H_

#include "IClient.h"
#include "CDebug.h"
#include "arch.h"

#include "ORender.h"
#include "OAudio.h"
#include "OControl.h"
#include "particles.h"


class OClient : public IClient
{
    public:

    OClient() {}
    ~OClient() {}

    /** Particle Engine */
    CParticles mParticleEngine;

    bool CreateInterface(void);
    /** Create a Client interface */

    bool DestroyInterface(void);
    /** Destroy a Client interface */

    bool UpdateClient(void);
    /** Update This Client */

    bool OpenWindow(std::string Name, int Width, int Height, int BPP);
    /** Opens a Window */

    bool CloseWindow(void);
    /** Closes a Window */

    bool SetFullScreen(bool set);
    /** Set Fullscreen */

    bool UpdateMousePos( int *X, int *Y);
    /** Update The Mouse Position */

    bool UpdateMouseButtons( bool down, int button);
    /** Update The Mouse Buttons */

    bool UpdateKeys( Uint8 &key, bool down );
    /** Update The Keyboard */

    bool UpdateJoyButtons( Uint8 &button, bool down );
    /** Update the Joystick/Joypad Buttons */

    bool UpdateJoyAxis( Sint16 XAxis, Sint16 YAxis );
    /** Update the Joystick X/Y Axis */

    ORender *accessRenderer( void )
    {   return RenderObject;   }

    OControl *accessController( void )
    {   return ControlObject;   }

    OAudio *accessAudio( void )
    {   return AudioObject; }

    private:

    OControl    *ControlObject;     //!< Our Controller Object
    OAudio      *AudioObject;       //!< Our Audio Object
    ORender     *RenderObject;      //!< Our Renderer

    /** Mouse Information */
    int MouseX;
    int MouseY;
    bool MouseButtons[5];

    /** Key Information */
    Uint8 *Keyboard;

    /** Joypad/stick Information */
    Uint8 *JoyButtons;
    Sint16 JoyStickX;
    Sint16 JoyStickY;
};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/
