#ifndef __SGZCONTROL_H_
#define __SGZCONTROL_H_

#ifdef pedanticGCC
extern "C"
{
#endif
    #include "../../../system/lua/lualib.h"
#ifdef pedanticGCC
}
#endif

#include "../lunar.h"
#include "../../../arch.h"
#include "../../../common/debug/CDebug.h"
#include "../../../common/engine/CInterpret.h"

class SGZControl_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZControl_Proxy>::RegType methods[];

        SGZControl_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZControl_Proxy() {}

        int UpdateControls(lua_State *Lua);
        int GetKey(lua_State *Lua);
        int GetJoysticks(lua_State *Lua);
        int GetJoystickDetails(lua_State *Lua);
        int GetJoystickAxis(lua_State *Lua);
        int GetJoystickButton(lua_State *Lua);
        int GetJoystickHat(lua_State *Lua);

        int Get_UP(lua_State *Lua);
        int Get_DOWN(lua_State *Lua);
        int Get_LEFT(lua_State *Lua);
        int Get_RIGHT(lua_State *Lua);
        int Get_Fire1(lua_State *Lua);
        int Get_Fire2(lua_State *Lua);
        int Get_Fire3(lua_State *Lua);
        int Get_Fire4(lua_State *Lua);
        int Get_L(lua_State *Lua);
        int Get_R(lua_State *Lua);
        int Get_SELECT(lua_State *Lua);
        int Get_START(lua_State *Lua);

        int Get_1( lua_State *Lua );
        int Get_2( lua_State *Lua );
        int Get_3( lua_State *Lua );
        int Get_4( lua_State *Lua );
        int Get_5( lua_State *Lua );
        int Get_6( lua_State *Lua );
        int Get_7( lua_State *Lua );
        int Get_8( lua_State *Lua );
        int Get_9( lua_State *Lua );
        int Get_0( lua_State *Lua );

        int Get_q( lua_State *Lua );
        int Get_w( lua_State *Lua );
        int Get_e( lua_State *Lua );
        int Get_r( lua_State *Lua );
        int Get_t( lua_State *Lua );
        int Get_y( lua_State *Lua );
        int Get_u( lua_State *Lua );
        int Get_i( lua_State *Lua );
        int Get_o( lua_State *Lua );
        int Get_p( lua_State *Lua );
        int Get_a( lua_State *Lua );
        int Get_s( lua_State *Lua );
        int Get_d( lua_State *Lua );
        int Get_f( lua_State *Lua );
        int Get_g( lua_State *Lua );
        int Get_h( lua_State *Lua );
        int Get_j( lua_State *Lua );
        int Get_k( lua_State *Lua );
        int Get_l( lua_State *Lua );
        int Get_z( lua_State *Lua );
        int Get_x( lua_State *Lua );
        int Get_c( lua_State *Lua );
        int Get_v( lua_State *Lua );
        int Get_b( lua_State *Lua );
        int Get_n( lua_State *Lua );
        int Get_m( lua_State *Lua );

        int Get_lshift( lua_State *Lua );
        int Get_lctrl( lua_State *Lua );
        int Get_lalt( lua_State *Lua );
        int Get_rshift( lua_State *Lua );
        int Get_rctrl( lua_State *Lua );
        int Get_ralt( lua_State *Lua );
        int Get_space( lua_State *Lua );
        int Get_return( lua_State *Lua );
        int Get_backspace( lua_State *Lua );
        int Get_plus( lua_State *Lua );
        int Get_minus( lua_State *Lua );

        int Get_F1( lua_State *Lua );
        int Get_F2( lua_State *Lua );
        int Get_F3( lua_State *Lua );
        int Get_F4( lua_State *Lua );
        int Get_F5( lua_State *Lua );
        int Get_F6( lua_State *Lua );
        int Get_F7( lua_State *Lua );
        int Get_F8( lua_State *Lua );
        int Get_F9( lua_State *Lua );
        int Get_F10( lua_State *Lua );
        int Get_F11( lua_State *Lua );
        int Get_F12( lua_State *Lua );

        int Get_ESC( lua_State *Lua );

        #ifdef PLAT_GP2X
            int Get_UPLEFT(lua_State *Lua);
            int Get_UPRIGHT(lua_State *Lua);
            int Get_DOWNLEFT(lua_State *Lua);
            int Get_DOWNRIGHT(lua_State *Lua);
            int Get_VOLUP(lua_State *Lua);
            int Get_VOLDOWN(lua_State *Lua);
            int Get_A(lua_State *Lua);
            int Get_B(lua_State *Lua);
            int Get_X(lua_State *Lua);
            int Get_Y(lua_State *Lua);
            int Get_CLICK(lua_State *Lua);
        #endif

        #ifdef PLAT_PSPDEV
            int Get_TRI(lua_State *Lua);
            int Get_SQUARE(lua_State *Lua);
            int Get_CROSS(lua_State *Lua);
            int Get_CIRCLE(lua_State *Lua);
            int Get_VOLUP(lua_State *Lua);
            int Get_VOLDOWN(lua_State *Lua);
            int Get_HOME(lua_State *Lua);
            int Get_STICK_X(lua_State *Lua);
            int Get_STICK_Y(lua_State *Lua);
        #endif

        #if defined(PLAT_PS2LINUX) || defined (PLAT_PS2DEV) || defined(PLAT_PS3LINUX) || defined(PLAT_PS3DEV)
            int Get_L1(lua_State *Lua);
            int Get_R1(lua_State *Lua);
            int Get_L2(lua_State *Lua);
            int Get_R2(lua_State *Lua);
            int Get_L3(lua_State *Lua);
            int Get_R3(lua_State *Lua);
            int Get_TRI(lua_State *Lua);
            int Get_SQUARE(lua_State *Lua);
            int Get_CROSS(lua_State *Lua);
            int Get_CIRCLE(lua_State *Lua);
            int Get_LSTICK_X(lua_State *Lua);
            int Get_LSTICK_Y(lua_State *Lua);
            int Get_LSTICK_X(lua_State *Lua);
            int Get_LSTICK_Y(lua_State *Lua);
        #endif

        #ifdef PLAT_DS
            int Get_A(lua_State *Lua);
            int Get_B(lua_State *Lua);
            int Get_X(lua_State *Lua);
            int Get_Y(lua_State *Lua);
        #endif

        #ifdef PLAT_GP32
            int Get_A(lua_State *Lua);
            int Get_B(lua_State *Lua);
        #endif

        #ifdef PLAT_WII
            int Get_1(lua_State *Lua);
            int Get_2(lua_State *Lua);
            int Get_PLUS(lua_State *Lua);
            int Get_MINUS(lua_State *Lua);
            int Get_A(lua_State *Lua);
            int Get_B(lua_State *Lua);
            int Get_NUN_Z(lua_State *Lua);
            int Get_NUN_C(lua_State *Lua);
            int Get_NUN_X(lua_State *Lua);
            int Get_NUN_Y(lua_State *Lua);
        #endif

    private:
};

#endif
