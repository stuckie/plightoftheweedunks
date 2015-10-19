/** -------------------------------------------------------------------------------
* \file IControl.h
* \brief The Controller Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#ifndef _ICONTROL_H_
#define _ICONTROL_H_

#include <string>

class IControl
{
    public:
    virtual ~IControl() {}

    virtual bool CreateInterface(void) = 0;
    /** Create a client interface to talk on */

    virtual bool DestroyInterface(void) = 0;
    /** Destroy a client interface */

    virtual bool UpdateControls(void) = 0;
    /** Update The Controls */

    virtual bool KeyPress(std::string key) = 0;
    /** Check for KeyPress */

    virtual bool Get_Up( void ) = 0;
    virtual bool Get_Down( void ) = 0;
    virtual bool Get_Left( void ) = 0;
    virtual bool Get_Right( void ) = 0;
    virtual bool Get_Fire1( void ) = 0;
    virtual bool Get_Fire2( void ) = 0;
    virtual bool Get_Fire3( void ) = 0;
    virtual bool Get_Fire4( void ) = 0;
    virtual bool Get_L( void ) = 0 ;
    virtual bool Get_R( void ) = 0;
    virtual bool Get_SELECT( void ) = 0;
    virtual bool Get_START( void ) = 0;
    virtual int Get_PadAxis( int, int ) = 0;
    virtual bool Get_PadButton ( int, int ) = 0;
    virtual int Get_PadHat ( int pad, int hat ) = 0;

    virtual bool Get_1( void ) = 0;
    virtual bool Get_2( void ) = 0;
    virtual bool Get_3( void ) = 0;
    virtual bool Get_4( void ) = 0;
    virtual bool Get_5( void ) = 0;
    virtual bool Get_6( void ) = 0;
    virtual bool Get_7( void ) = 0;
    virtual bool Get_8( void ) = 0;
    virtual bool Get_9( void ) = 0;
    virtual bool Get_0( void ) = 0;

    virtual bool Get_q( void ) = 0;
    virtual bool Get_w( void ) = 0;
    virtual bool Get_e( void ) = 0;
    virtual bool Get_r( void ) = 0;
    virtual bool Get_t( void ) = 0;
    virtual bool Get_y( void ) = 0;
    virtual bool Get_u( void ) = 0;
    virtual bool Get_i( void ) = 0;
    virtual bool Get_o( void ) = 0;
    virtual bool Get_p( void ) = 0;
    virtual bool Get_a( void ) = 0;
    virtual bool Get_s( void ) = 0;
    virtual bool Get_d( void ) = 0;
    virtual bool Get_f( void ) = 0;
    virtual bool Get_g( void ) = 0;
    virtual bool Get_h( void ) = 0;
    virtual bool Get_j( void ) = 0;
    virtual bool Get_k( void ) = 0;
    virtual bool Get_l( void ) = 0;
    virtual bool Get_z( void ) = 0;
    virtual bool Get_x( void ) = 0;
    virtual bool Get_c( void ) = 0;
    virtual bool Get_v( void ) = 0;
    virtual bool Get_b( void ) = 0;
    virtual bool Get_n( void ) = 0;
    virtual bool Get_m( void ) = 0;

    virtual bool Get_lshift( void ) = 0;
    virtual bool Get_lctrl( void ) = 0;
    virtual bool Get_lalt( void ) = 0;
    virtual bool Get_rshift( void ) = 0;
    virtual bool Get_rctrl( void ) = 0;
    virtual bool Get_ralt( void ) = 0;
    virtual bool Get_space( void ) = 0;
    virtual bool Get_return( void ) = 0;
    virtual bool Get_backspace( void ) = 0;
    virtual bool Get_plus( void ) = 0;
    virtual bool Get_minus( void ) = 0;

    virtual bool Get_F1( void ) = 0;
    virtual bool Get_F2( void ) = 0;
    virtual bool Get_F3( void ) = 0;
    virtual bool Get_F4( void ) = 0;
    virtual bool Get_F5( void ) = 0;
    virtual bool Get_F6( void ) = 0;
    virtual bool Get_F7( void ) = 0;
    virtual bool Get_F8( void ) = 0;
    virtual bool Get_F9( void ) = 0;
    virtual bool Get_F10( void ) = 0;
    virtual bool Get_F11( void ) = 0;
    virtual bool Get_F12( void ) = 0;

    virtual bool Get_ESC( void ) = 0;

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

