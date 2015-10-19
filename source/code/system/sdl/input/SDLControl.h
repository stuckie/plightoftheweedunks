/** -------------------------------------------------------------------------------
* \file SDLControl.h
* \brief The SDL Controller Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#ifndef _SDLCONTROL_H_
#define _SDLCONTROL_H_

#include "../../../arch.h"
#include "../../../client/input/IControl.h"
#include "../../../common/debug/CDebug.h"
#include "../../../common/engine/OEvent.h"
#include <SDL/SDL.h>

class SDLControl : public IControl
{
    public:
    SDLControl() { buttons = SDL_GetKeyState(0); }
    ~SDLControl() {}

    bool CreateInterface(void);
    /** Create a client interface to talk on */

    bool DestroyInterface(void);
    /** Destroy a client interface */

    bool UpdateControls(void);
    /** Update The Controls */

    bool KeyPress(std::string Key);
    /** Checks for a Key Press */

    bool Get_Up( void );
    bool Get_Down( void );
    bool Get_Left( void );
    bool Get_Right( void );
    bool Get_Fire1( void );
    bool Get_Fire2( void );
    bool Get_Fire3( void );
    bool Get_Fire4( void );
    bool Get_L( void );
    bool Get_R( void );
    bool Get_SELECT( void );
    bool Get_START( void );
    bool Get_PadButton ( int pad, int button );
    int Get_PadAxis ( int pad, int axis );
    int Get_PadHat ( int pad, int hat );

    bool Get_1( void );
    bool Get_2( void );
    bool Get_3( void );
    bool Get_4( void );
    bool Get_5( void );
    bool Get_6( void );
    bool Get_7( void );
    bool Get_8( void );
    bool Get_9( void );
    bool Get_0( void );

    bool Get_q( void );
    bool Get_w( void );
    bool Get_e( void );
    bool Get_r( void );
    bool Get_t( void );
    bool Get_y( void );
    bool Get_u( void );
    bool Get_i( void );
    bool Get_o( void );
    bool Get_p( void );
    bool Get_a( void );
    bool Get_s( void );
    bool Get_d( void );
    bool Get_f( void );
    bool Get_g( void );
    bool Get_h( void );
    bool Get_j( void );
    bool Get_k( void );
    bool Get_l( void );
    bool Get_z( void );
    bool Get_x( void );
    bool Get_c( void );
    bool Get_v( void );
    bool Get_b( void );
    bool Get_n( void );
    bool Get_m( void );

    bool Get_lshift( void );
    bool Get_lctrl( void );
    bool Get_lalt( void );
    bool Get_rshift( void );
    bool Get_rctrl( void );
    bool Get_ralt( void );
    bool Get_space( void );
    bool Get_return( void );
    bool Get_backspace( void );
    bool Get_plus( void );
    bool Get_minus( void );

    bool Get_F1( void );
    bool Get_F2( void );
    bool Get_F3( void );
    bool Get_F4( void );
    bool Get_F5( void );
    bool Get_F6( void );
    bool Get_F7( void );
    bool Get_F8( void );
    bool Get_F9( void );
    bool Get_F10( void );
    bool Get_F11( void );
    bool Get_F12( void );

    bool Get_ESC( void );

    #ifdef PLAT_GP2X                //!< GP2X Specific Defines
        #define GP2X_BUTTON_UP              (0)
        #define GP2X_BUTTON_DOWN            (4)
        #define GP2X_BUTTON_LEFT            (2)
        #define GP2X_BUTTON_RIGHT           (6)
        #define GP2X_BUTTON_UPLEFT          (1)
        #define GP2X_BUTTON_UPRIGHT         (7)
        #define GP2X_BUTTON_DOWNLEFT        (3)
        #define GP2X_BUTTON_DOWNRIGHT       (5)
        #define GP2X_BUTTON_CLICK           (18)
        #define GP2X_BUTTON_A               (12)
        #define GP2X_BUTTON_B               (13)
        #define GP2X_BUTTON_X               (14)
        #define GP2X_BUTTON_Y               (15)
        #define GP2X_BUTTON_L               (10)
        #define GP2X_BUTTON_R               (11)
        #define GP2X_BUTTON_START           (8)
        #define GP2X_BUTTON_SELECT          (9)
        #define GP2X_BUTTON_VOLUP           (16)
        #define GP2X_BUTTON_VOLDOWN         (17)

        bool GP2X_UP( void )
            {    return buttons[GP2X_BUTTON_UP]; }
        bool GP2X_DOWN( void )
            {    return buttons[GP2X_BUTTON_DOWN];}
        bool GP2X_LEFT( void )
            {    return buttons[GP2X_BUTTON_LEFT];}
        bool GP2X_RIGHT( void )
            {    return buttons[GP2X_BUTTON_RIGHT];}
        bool GP2X_UPLEFT( void )
            {    return buttons[GP2X_BUTTON_UPLEFT];}
        bool GP2X_UPRIGHT( void )
            {    return buttons[GP2X_BUTTON_UPRIGHT];}
        bool GP2X_DOWNLEFT( void )
            {    return buttons[GP2X_BUTTON_DOWNLEFT];}
        bool GP2X_DOWNRIGHT( void )
            {    return buttons[GP2X_BUTTON_DOWNRIGHT];}
        bool GP2X_BUTTONCLICK( void )
            {    return buttons[GP2X_BUTTON_CLICK];}
        bool GP2X_A( void )
            {    return buttons[GP2X_BUTTON_A];}
        bool GP2X_B( void )
            {    return buttons[GP2X_BUTTON_B];}
        bool GP2X_X( void )
            {    return buttons[GP2X_BUTTON_X];}
        bool GP2X_Y( void )
            {    return buttons[GP2X_BUTTON_Y];}
        bool GP2X_L( void )
            {    return buttons[GP2X_BUTTON_L];}
        bool GP2X_R( void )
            {    return buttons[GP2X_BUTTON_R];}
        bool GP2X_START( void )
            {    return buttons[GP2X_BUTTON_START];}
        bool GP2X_SELECT( void )
            {    return buttons[GP2X_BUTTON_SELECT];}
        bool GP2X_VOLUP( void )
            {    return buttons[GP2X_BUTTON_VOLUP];}
        bool GP2X_VOLDOWN( void )
            {    return buttons[GP2X_BUTTON_VOLDOWN];}
    #endif

    #ifdef PLAT_PSPDEV                      //!< PSPDEV Specific Defines
    /*
    The PSP's controls provide a joystick with a two axes on the analog
    stick and 14 independent buttons.  The button mapping is fixed:
    */
        #define PSP_BUTTON_TRIANGLE        (0)
        #define PSP_BUTTON_CIRCLE          (1)
        #define PSP_BUTTON_CROSS           (2)
        #define PSP_BUTTON_SQUARE          (3)
        #define PSP_BUTTON_L               (4)
        #define PSP_BUTTON_R               (5)
        #define PSP_BUTTON_DOWN            (6)
        #define PSP_BUTTON_LEFT            (7)
        #define PSP_BUTTON_UP              (8)
        #define PSP_BUTTON_RIGHT           (9)
        #define PSP_BUTTON_SELECT          (10)
        #define PSP_BUTTON_START           (11)
        #define PSP_BUTTON_HOME            (12)
        #define PSP_BUTTON_HOLD            (13)

        bool PSP_TRIANGLE( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_TRIANGLE); }
        bool PSP_CIRCLE( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_CIRCLE); }
        bool PSP_CROSS( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_CROSS); }
        bool PSP_SQUARE( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_SQUARE); }
        bool PSP_UP( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_UP); }
        bool PSP_DOWN( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_DOWN); }
        bool PSP_LEFT( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_LEFT); }
        bool PSP_RIGHT( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_RIGHT); }
        bool PSP_L( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_L); }
        bool PSP_R( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_R); }
        bool PSP_START( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_START); }
        bool PSP_SELECT( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_SELECT); }
        bool PSP_HOME( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_HOME); }
        bool PSP_HOLD( void )
            {    return (bool)SDL_JoystickGetButton(Joypad, PSP_BUTTON_HOLD); }
    #endif

    private:
    SDL_Event Event;                        //!< Our SDL Event
    Uint8 *buttons;                         //!< Our button pointer
    std::string lastKey;                    //!< String to hold the last key pressed
    SDL_Joystick *Joypad1, *Joypad2;         //!< A Joypad to play with!

    int mousex, mousey;                     //!< Mouse X/Y

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/


