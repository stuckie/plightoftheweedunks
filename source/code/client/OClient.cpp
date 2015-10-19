/** -----------------------------------------------------------------------------
* \file OClient.cpp                                                               *
* \brief The Client Object                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Event Interface is literally used as a generic struct for all events.
*/

#include "OClient.h"

bool OClient::CreateInterface()
{
    /** Create a client interface */
    SGZLogger.debug("Creating Client Interface...\n");

    RenderObject = new ORender;
    RenderObject->CreateRenderer();

    SGZLogger.debug("Renderer Running...\n");

    ControlObject = new OControl;
    ControlObject->CreateInterface();

    SGZLogger.debug("Controller Running...\n");

    AudioObject = new OAudio;
    AudioObject->CreateInterface();

    SGZLogger.debug("Audio Running...\n");

    SGZLogger.debug("Client Object Created\n");

    return true;
}

bool OClient::DestroyInterface()
{
    /** Destroy a script interface */

    AudioObject->DestroyInterface();
    AudioObject=NULL;

    ControlObject->DestroyInterface();
    ControlObject=NULL;

    RenderObject->StopRenderer();
    RenderObject=NULL;

    SGZLogger.debug("Client Object Destroyed\n");

    return true;
}

bool OClient::OpenWindow(std::string Name, int Width, int Height, int BPP)
{
    /** Open a Window up */
    return RenderObject->SGZCreateWindow( Name, Width, Height, BPP );
}

bool OClient::CloseWindow( void )
{
    return RenderObject->SGZCloseWindow();
}

bool OClient::SetFullScreen( bool set )
{
    /** Set Fullscreen */
    return RenderObject->SetFullScreen(set);
}

bool OClient::UpdateMousePos( int *X, int *Y )
{
    /** Update Mouse Co-Ords */
    MouseX = *X;
    MouseY = *Y;
    return true;
}

bool OClient::UpdateMouseButtons( bool down, int button )
{
    /** Update Mouse Buttons */
    MouseButtons[button]=down;
    return true;
}

bool OClient::UpdateKeys( Uint8 &key, bool down )
{
    Keyboard[key]=down;
    printf("Caught key!\n");
    return true;
}

bool OClient::UpdateJoyButtons( Uint8 &button, bool down )
{
    JoyButtons[button]=down;
    return true;
}

bool OClient::UpdateJoyAxis( Sint16 XAxis, Sint16 YAxis )
{
    JoyStickX = XAxis;
    JoyStickY = YAxis;
    return true;
}

bool OClient::UpdateClient(void)
{
    if(RenderObject)
        RenderObject->UpdateScreen();

    if(ControlObject)
        ControlObject->UpdateControls();

    if(AudioObject)
        AudioObject->UpdateAudio();

    mParticleEngine.updateParticles();

    return true;
}

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/
