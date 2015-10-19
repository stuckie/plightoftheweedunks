/** -------------------------------------------------------------------------------
* \file SDLControl.cpp
* \brief The SDL Controller Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#include "SDLControl.h"
#include "../../../common/engine/CInterpret.h"

bool SDLControl::CreateInterface(void)
{
    /** Create a control interface to talk on */
    mousex=0,mousey=0;
    SDL_EnableUNICODE( SDL_ENABLE );
    lastKey = "";
    SDL_Init(SDL_INIT_JOYSTICK);
	Joypad1 = SDL_JoystickOpen(0);
	Joypad2 = SDL_JoystickOpen(1);
	SDL_WM_GrabInput(SDL_GRAB_ON);
	SDL_ShowCursor(SDL_DISABLE);
    SGZLogger.debug("Control Interface Active. Mouse - %d\n", SDL_ShowCursor(SDL_QUERY));
    return true;
}

bool SDLControl::DestroyInterface(void)
{
    /** Destroy a control interface */
    SDL_EnableUNICODE( SDL_DISABLE );
    SGZLogger.debug("Control Interface Deactived.\n");
    return true;
}

bool SDLControl::KeyPress(std::string key)
{
    if (lastKey.compare(key)==0)
        return true;
    else
        return false;
}

bool SDLControl::UpdateControls(void)
{
    /** Update The Controls if there's an event waiting for us! */
    if(SDL_PollEvent(&Event))
    {
        /** Check to see if we've quit */
        if(Event.type==SDL_QUIT)
        {
            QuitEvent *NewEvent;
            NewEvent = new QuitEvent;
            SGZInterpret.AddEvent( NewEvent );
            SGZLogger.debug("Quit Received from SDL\n");
            atexit(SDL_Quit);
        }


        /** Check the keyboard */
        if (Event.type==SDL_KEYUP)
        {
            buttons[Event.key.keysym.sym]=0;
            lastKey = "";
        }
        if (Event.type==SDL_KEYDOWN)
        {
            buttons[Event.key.keysym.sym]=1;
            lastKey += (char)Event.key.keysym.sym;
        }

        if(buttons[SDLK_ESCAPE])
        {
            QuitEvent *Quit;
            Quit = new QuitEvent;
            SGZInterpret.AddEvent(Quit);
        }

        if(buttons[SDLK_F11])
        {
            SGZInterpret.accessClient()->accessRenderer()->TakeScreenshot();
        }

        /** Check the mouse */
        if (Event.type==SDL_MOUSEBUTTONDOWN)
        {
            SGZInterpret.accessClient()->UpdateMouseButtons(true, (int)Event.button.button);
            mousex=Event.button.x;
            mousey=Event.button.y;
            SGZInterpret.accessClient()->UpdateMousePos(&mousex, &mousey);
        }

        if (Event.type==SDL_MOUSEBUTTONUP)
        {
            SGZInterpret.accessClient()->UpdateMouseButtons(false, (int)Event.button.button);
            mousex=Event.button.x;
            mousey=Event.button.y;
            SGZInterpret.accessClient()->UpdateMousePos(&mousex, &mousey);
        }

        if (Event.type==SDL_MOUSEMOTION)
            if(mousex!=Event.motion.x && mousey!=Event.motion.y)
            {
                mousex=Event.motion.x;
                mousey=Event.motion.y;
                SGZInterpret.accessClient()->UpdateMousePos(&mousex, &mousey);
            }
    }

    SDL_JoystickUpdate();

    return true;
}

bool SDLControl::Get_PadButton ( int pad, int button )
{
    if (pad == 1)
        return SDL_JoystickGetButton(Joypad1, button);
    else if (pad == 2)
        return SDL_JoystickGetButton(Joypad2, button);
    else return 0;
}

int SDLControl::Get_PadAxis ( int pad, int axis )
{
    if (pad == 1)
        return SDL_JoystickGetAxis(Joypad1, axis);
    else if (pad == 2)
        return SDL_JoystickGetAxis(Joypad2, axis);
    else return 0;
}

int SDLControl::Get_PadHat ( int pad, int hat )
{
    if (pad == 1)
        return SDL_JoystickGetHat(Joypad1, hat);
    else if (pad == 2)
        return SDL_JoystickGetHat(Joypad2, hat);
    else return 0;
}


bool SDLControl::Get_Left( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_LEFT();
    #elif PLAT_GP2X
        return GP2X_LEFT();
    #endif
    if (buttons[SDLK_LEFT]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_Right( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_RIGHT();
    #elif PLAT_GP2X
        return GP2X_RIGHT();
    #endif
    if (buttons[SDLK_RIGHT]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_Up( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_UP();
    #elif PLAT_GP2X
        return GP2X_UP();
    #endif
    if (buttons[SDLK_UP]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_Down( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_DOWN();
    #elif PLAT_GP2X
        return GP2X_DOWN();
    #endif
    if (buttons[SDLK_DOWN]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_Fire1( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_TRIANGLE();
    #elif PLAT_GP2X
        return GP2X_Y();
    #endif
    if (buttons[SDLK_w]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_Fire2( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_CIRCLE();
    #elif PLAT_GP2X
        return GP2X_B();
    #endif
    if (buttons[SDLK_d]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_Fire3( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_CROSS();
    #elif PLAT_GP2X
        return GP2X_X();
    #endif
    if (buttons[SDLK_s]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_Fire4( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_SQUARE();
    #elif PLAT_GP2X
        return GP2X_A();
    #endif
    if (buttons[SDLK_a]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_START( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_START();
    #elif PLAT_GP2X
        return GP2X_START();
    #endif
    if (buttons[SDLK_RETURN]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_SELECT( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_SELECT();
    #elif PLAT_GP2X
        return GP2X_SELECT();
    #endif
    if (buttons[SDLK_SPACE]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_L( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_L();
    #elif PLAT_GP2X
        return GP2X_L();
    #endif
    if (buttons[SDLK_q]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_R( void )
{
    #ifdef PLAT_PSPDEV
        return PSP_R();
    #elif PLAT_GP2X
        return GP2X_R();
    #endif
    if (buttons[SDLK_e]==1)
        return true;
    else
        return false;
}

bool SDLControl::Get_1( void )
{
    return buttons[SDLK_1];
}

bool SDLControl::Get_2( void )
{
    return buttons[SDLK_2];
}

bool SDLControl::Get_3( void )
{
    return buttons[SDLK_3];
}

bool SDLControl::Get_4( void )
{
    return buttons[SDLK_4];
}

bool SDLControl::Get_5( void )
{
    return buttons[SDLK_5];
}

bool SDLControl::Get_6( void )
{
    return buttons[SDLK_6];
}

bool SDLControl::Get_7( void )
{
    return buttons[SDLK_7];
}

bool SDLControl::Get_8( void )
{
    return buttons[SDLK_8];
}

bool SDLControl::Get_9( void )
{
    return buttons[SDLK_9];
}

bool SDLControl::Get_0( void )
{
    return buttons[SDLK_0];
}


bool SDLControl::Get_q( void )
{
    return buttons[SDLK_q];
}

bool SDLControl::Get_w( void )
{
    return buttons[SDLK_w];
}

bool SDLControl::Get_e( void )
{
    return buttons[SDLK_e];
}

bool SDLControl::Get_r( void )
{
    return buttons[SDLK_r];
}

bool SDLControl::Get_t( void )
{
    return buttons[SDLK_t];
}

bool SDLControl::Get_y( void )
{
    return buttons[SDLK_y];
}

bool SDLControl::Get_u( void )
{
    return buttons[SDLK_u];
}

bool SDLControl::Get_i( void )
{
    return buttons[SDLK_i];
}

bool SDLControl::Get_o( void )
{
    return buttons[SDLK_o];
}

bool SDLControl::Get_p( void )
{
    return buttons[SDLK_p];
}

bool SDLControl::Get_a( void )
{
    return buttons[SDLK_a];
}

bool SDLControl::Get_s( void )
{
    return buttons[SDLK_s];
}

bool SDLControl::Get_d( void )
{
    return buttons[SDLK_d];
}

bool SDLControl::Get_f( void )
{
    return buttons[SDLK_f];
}

bool SDLControl::Get_g( void )
{
    return buttons[SDLK_g];
}

bool SDLControl::Get_h( void )
{
    return buttons[SDLK_h];
}

bool SDLControl::Get_j( void )
{
    return buttons[SDLK_j];
}

bool SDLControl::Get_k( void )
{
    return buttons[SDLK_k];
}

bool SDLControl::Get_l( void )
{
    return buttons[SDLK_l];
}

bool SDLControl::Get_z( void )
{
    return buttons[SDLK_z];
}

bool SDLControl::Get_x( void )
{
    return buttons[SDLK_x];
}

bool SDLControl::Get_c( void )
{
    return buttons[SDLK_c];
}

bool SDLControl::Get_v( void )
{
    return buttons[SDLK_v];
}

bool SDLControl::Get_b( void )
{
    return buttons[SDLK_b];
}

bool SDLControl::Get_n( void )
{
    return buttons[SDLK_n];
}

bool SDLControl::Get_m( void )
{
    return buttons[SDLK_m];
}


bool SDLControl::Get_lshift( void )
{
    return buttons[SDLK_LSHIFT];
}

bool SDLControl::Get_lctrl( void )
{
    return buttons[SDLK_LCTRL];
}

bool SDLControl::Get_lalt( void )
{
    return buttons[SDLK_LALT];
}

bool SDLControl::Get_rshift( void )
{
    return buttons[SDLK_RSHIFT];
}

bool SDLControl::Get_rctrl( void )
{
    return buttons[SDLK_RCTRL];
}

bool SDLControl::Get_ralt( void )
{
    return buttons[SDLK_RALT];
}

bool SDLControl::Get_space( void )
{
    return buttons[SDLK_SPACE];
}

bool SDLControl::Get_return( void )
{
    return buttons[SDLK_RETURN];
}

bool SDLControl::Get_backspace( void )
{
    return buttons[SDLK_BACKSPACE];
}

bool SDLControl::Get_plus( void )
{
    return buttons[SDLK_PLUS];
}

bool SDLControl::Get_minus( void )
{
    return buttons[SDLK_MINUS];
}

bool SDLControl::Get_F1( void )
{
    return buttons[SDLK_F1];
}

bool SDLControl::Get_F2( void )
{
    return buttons[SDLK_F2];
}

bool SDLControl::Get_F3( void )
{
    return buttons[SDLK_F3];
}

bool SDLControl::Get_F4( void )
{
    return buttons[SDLK_F4];
}

bool SDLControl::Get_F5( void )
{
    return buttons[SDLK_F5];
}

bool SDLControl::Get_F6( void )
{
    return buttons[SDLK_F6];
}

bool SDLControl::Get_F7( void )
{
    return buttons[SDLK_F7];
}

bool SDLControl::Get_F8( void )
{
    return buttons[SDLK_F8];
}

bool SDLControl::Get_F9( void )
{
    return buttons[SDLK_F9];
}

bool SDLControl::Get_F10( void )
{
    return buttons[SDLK_F10];
}

bool SDLControl::Get_F11( void )
{
    return buttons[SDLK_F11];
}

bool SDLControl::Get_F12( void )
{
    return buttons[SDLK_F12];
}

bool SDLControl::Get_ESC( void )
{
    return buttons[SDLK_ESCAPE];
}


/** Changelog for this file:

    -------- 25th June 2008

    Added in all the key defines for SDL!

    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/
