/** -------------------------------------------------------------------------------
* \file OControl.cpp
* \brief The Controller Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#include "OControl.h"

bool OControl::CreateInterface(void)
{
    /** Create a client interface to talk on */
    return ControlObject.CreateInterface();
}

bool OControl::DestroyInterface(void)
{
    /** Destroy a client interface */
    return ControlObject.DestroyInterface();
}

bool OControl::UpdateControls(void)
{
    /** Update The Controls */
    return ControlObject.UpdateControls();
}

bool OControl::KeyPress(std::string key)
{
    /** Check for KeyPress */
    return ControlObject.KeyPress(key);
}

bool OControl::Get_Left(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Left();
}

bool OControl::Get_Right(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Right();
}

bool OControl::Get_Up(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Up();
}

bool OControl::Get_Down(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Down();
}

bool OControl::Get_Fire1(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Fire1();
}

bool OControl::Get_Fire2(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Fire2();
}

bool OControl::Get_Fire3(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Fire3();
}

bool OControl::Get_Fire4(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_Fire4();
}

bool OControl::Get_START(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_START();
}

bool OControl::Get_SELECT(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_SELECT();
}

bool OControl::Get_L(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_L();
}

bool OControl::Get_R(void)
{
    /** Check for KeyPress */
    return ControlObject.Get_R();
}

int OControl::Get_PadAxis( int pad, int axis )
{
    return ControlObject.Get_PadAxis(pad, axis);
}
bool OControl::Get_PadButton ( int pad, int button )
{
    return ControlObject.Get_PadButton(pad, button);
}
int OControl::Get_PadHat( int pad, int hat )
{
    return ControlObject.Get_PadHat(pad, hat);
}


bool OControl::Get_1( void )
{
    return ControlObject.Get_1();
}

bool OControl::Get_2( void )
{
    return ControlObject.Get_2();
}

bool OControl::Get_3( void )
{
    return ControlObject.Get_3();
}

bool OControl::Get_4( void )
{
    return ControlObject.Get_4();
}

bool OControl::Get_5( void )
{
    return ControlObject.Get_5();
}

bool OControl::Get_6( void )
{
    return ControlObject.Get_6();
}

bool OControl::Get_7( void )
{
    return ControlObject.Get_7();
}

bool OControl::Get_8( void )
{
    return ControlObject.Get_8();
}

bool OControl::Get_9( void )
{
    return ControlObject.Get_9();
}

bool OControl::Get_0( void )
{
    return ControlObject.Get_0();
}


bool OControl::Get_q( void )
{
    return ControlObject.Get_q();
}

bool OControl::Get_w( void )
{
    return ControlObject.Get_w();
}

bool OControl::Get_e( void )
{
    return ControlObject.Get_e();
}

bool OControl::Get_r( void )
{
    return ControlObject.Get_r();
}

bool OControl::Get_t( void )
{
    return ControlObject.Get_t();
}

bool OControl::Get_y( void )
{
    return ControlObject.Get_y();
}

bool OControl::Get_u( void )
{
    return ControlObject.Get_u();
}

bool OControl::Get_i( void )
{
    return ControlObject.Get_i();
}

bool OControl::Get_o( void )
{
    return ControlObject.Get_o();
}

bool OControl::Get_p( void )
{
    return ControlObject.Get_p();
}

bool OControl::Get_a( void )
{
    return ControlObject.Get_a();
}

bool OControl::Get_s( void )
{
    return ControlObject.Get_s();
}

bool OControl::Get_d( void )
{
    return ControlObject.Get_d();
}

bool OControl::Get_f( void )
{
    return ControlObject.Get_f();
}

bool OControl::Get_g( void )
{
    return ControlObject.Get_g();
}

bool OControl::Get_h( void )
{
    return ControlObject.Get_h();
}

bool OControl::Get_j( void )
{
    return ControlObject.Get_j();
}

bool OControl::Get_k( void )
{
    return ControlObject.Get_k();
}

bool OControl::Get_l( void )
{
    return ControlObject.Get_l();
}

bool OControl::Get_z( void )
{
    return ControlObject.Get_z();
}

bool OControl::Get_x( void )
{
    return ControlObject.Get_x();
}

bool OControl::Get_c( void )
{
    return ControlObject.Get_c();
}

bool OControl::Get_v( void )
{
    return ControlObject.Get_v();
}

bool OControl::Get_b( void )
{
    return ControlObject.Get_b();
}

bool OControl::Get_n( void )
{
    return ControlObject.Get_n();
}

bool OControl::Get_m( void )
{
    return ControlObject.Get_m();
}


bool OControl::Get_lshift( void )
{
    return ControlObject.Get_lshift();
}

bool OControl::Get_lctrl( void )
{
    return ControlObject.Get_lctrl();
}

bool OControl::Get_lalt( void )
{
    return ControlObject.Get_lalt();
}

bool OControl::Get_rshift( void )
{
    return ControlObject.Get_rshift();
}

bool OControl::Get_rctrl( void )
{
    return ControlObject.Get_rctrl();
}

bool OControl::Get_ralt( void )
{
    return ControlObject.Get_ralt();
}

bool OControl::Get_space( void )
{
    return ControlObject.Get_space();
}

bool OControl::Get_return( void )
{
    return ControlObject.Get_return();
}

bool OControl::Get_backspace( void )
{
    return ControlObject.Get_backspace();
}

bool OControl::Get_plus( void )
{
    return ControlObject.Get_plus();
}

bool OControl::Get_minus( void )
{
    return ControlObject.Get_minus();
}

bool OControl::Get_F1( void )
{
    return ControlObject.Get_F1();
}

bool OControl::Get_F2( void )
{
    return ControlObject.Get_F2();
}

bool OControl::Get_F3( void )
{
    return ControlObject.Get_F3();
}

bool OControl::Get_F4( void )
{
    return ControlObject.Get_F4();
}

bool OControl::Get_F5( void )
{
    return ControlObject.Get_F5();
}

bool OControl::Get_F6( void )
{
    return ControlObject.Get_F6();
}

bool OControl::Get_F7( void )
{
    return ControlObject.Get_F7();
}

bool OControl::Get_F8( void )
{
    return ControlObject.Get_F8();
}

bool OControl::Get_F9( void )
{
    return ControlObject.Get_F9();
}

bool OControl::Get_F10( void )
{
    return ControlObject.Get_F10();
}

bool OControl::Get_F11( void )
{
    return ControlObject.Get_F11();
}

bool OControl::Get_F12( void )
{
    return ControlObject.Get_F12();
}

bool OControl::Get_ESC( void )
{
    return ControlObject.Get_ESC();
}


/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/
