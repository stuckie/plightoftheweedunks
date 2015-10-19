/** -------------------------------------------------------------------------------
* \file OControl.h
* \brief The Controller Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#ifndef _OCONTROL_H_
#define _OCONTROL_H_

#include "IControl.h"
#include "CDebug.h"
#include "arch.h"

/** API dependant thingies from hell! */
#ifdef IN_SDL
    #include "SDLControl.h"
#endif
#ifdef IN_OIS
    #include "OISControl.h"
#endif
#ifdef IN_WINAPI
    #include "WINControl.h"
#endif
#ifdef IN_DIRECTX
    #include "DXControl.h"
#endif

/** Now onto the consoles... */
#ifdef PLAT_PS2LINUX
    #include "../../system/ps2linux/input/PS2LControl.h"
#endif

class OControl
{
    public:
    OControl() {}
    ~OControl() {}

    bool CreateInterface(void);
    /** Create a client interface to talk on */

    bool DestroyInterface(void);
    /** Destroy a client interface */

    bool UpdateControls(void);
    /** Update The Controls */

    bool KeyPress(std::string Key);
    /** Check for a Key Press */

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
    int Get_PadAxis( int, int );
    bool Get_PadButton ( int, int );
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

    private:
    /** API dependant thingies from hell! */
    #ifdef IN_SDL
        SDLControl  ControlObject;
    #endif
    #ifdef IN_OIS
        OISControl  ControlObject;
    #endif
    #ifdef IN_WINAPI
        WINControl  ControlObject;
    #endif
    #ifdef IN_DIRECTX
        DXControl   ControlObject;
    #endif

    /** Now onto the consoles... */
    #ifdef PLAT_PS2LINUX
        PS2LControl ControlObject;
    #endif
};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/


