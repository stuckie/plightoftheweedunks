#include "SGZControl.h"

int SGZControl_Proxy::UpdateControls(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessController()->UpdateControls();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZControl_Proxy::GetKey(lua_State *Lua)
{
    std::string key = lua_tostring(Lua, -1);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->KeyPress(key));
    return 1;
}

int SGZControl_Proxy::GetJoysticks( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZControl_Proxy::GetJoystickButton( lua_State *Lua)
{
    bool value = SGZInterpret.accessClient()->accessController()->Get_PadButton((int)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2));
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, value);

    return 1;
}

int SGZControl_Proxy::GetJoystickAxis( lua_State *Lua)
{
    int value = SGZInterpret.accessClient()->accessController()->Get_PadAxis((int)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2));
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);

    return 1;
}

int SGZControl_Proxy::GetJoystickHat( lua_State *Lua)
{
    int value = SGZInterpret.accessClient()->accessController()->Get_PadHat((int)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2));
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);

    return 1;
}

int SGZControl_Proxy::GetJoystickDetails( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZControl_Proxy::Get_LEFT( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Left());
    return 1;
}

int SGZControl_Proxy::Get_RIGHT( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Right());
    return 1;
}

int SGZControl_Proxy::Get_UP( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Up());
    return 1;
}

int SGZControl_Proxy::Get_DOWN( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Down());
    return 1;
}

int SGZControl_Proxy::Get_Fire1( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Fire1());
    return 1;
}

int SGZControl_Proxy::Get_Fire2( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Fire2());
    return 1;
}

int SGZControl_Proxy::Get_Fire3( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Fire3());
    return 1;
}

int SGZControl_Proxy::Get_Fire4( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_Fire4());
    return 1;
}

int SGZControl_Proxy::Get_START( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_START());
    return 1;
}

int SGZControl_Proxy::Get_SELECT( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_SELECT());
    return 1;
}

int SGZControl_Proxy::Get_L( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_L());
    return 1;
}

int SGZControl_Proxy::Get_R( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_R());
    return 1;
}

int SGZControl_Proxy::Get_1( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_1());
    return 1;
}

int SGZControl_Proxy::Get_2( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_2());
    return 1;
}

int SGZControl_Proxy::Get_3( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_3());
    return 1;
}

int SGZControl_Proxy::Get_4( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_4());
    return 1;
}

int SGZControl_Proxy::Get_5( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_5());
    return 1;
}

int SGZControl_Proxy::Get_6( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_6());
    return 1;
}

int SGZControl_Proxy::Get_7( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_7());
    return 1;
}

int SGZControl_Proxy::Get_8( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_8());
    return 1;
}

int SGZControl_Proxy::Get_9( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_9());
    return 1;
}

int SGZControl_Proxy::Get_0( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_0());
    return 1;
}

int SGZControl_Proxy::Get_q( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_q());
    return 1;
}

int SGZControl_Proxy::Get_w( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_w());
    return 1;
}

int SGZControl_Proxy::Get_e( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_e());
    return 1;
}

int SGZControl_Proxy::Get_r( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_r());
    return 1;
}

int SGZControl_Proxy::Get_t( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_t());
    return 1;
}

int SGZControl_Proxy::Get_y( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_y());
    return 1;
}

int SGZControl_Proxy::Get_u( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_u());
    return 1;
}

int SGZControl_Proxy::Get_i( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_i());
    return 1;
}

int SGZControl_Proxy::Get_o( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_o());
    return 1;
}

int SGZControl_Proxy::Get_p( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_p());
    return 1;
}

int SGZControl_Proxy::Get_a( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_a());
    return 1;
}

int SGZControl_Proxy::Get_s( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_s());
    return 1;
}

int SGZControl_Proxy::Get_d( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_d());
    return 1;
}

int SGZControl_Proxy::Get_f( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_f());
    return 1;
}

int SGZControl_Proxy::Get_g( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_g());
    return 1;
}

int SGZControl_Proxy::Get_h( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_h());
    return 1;
}

int SGZControl_Proxy::Get_j( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_j());
    return 1;
}

int SGZControl_Proxy::Get_k( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_k());
    return 1;
}

int SGZControl_Proxy::Get_l( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_l());
    return 1;
}

int SGZControl_Proxy::Get_z( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_z());
    return 1;
}

int SGZControl_Proxy::Get_x( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_x());
    return 1;
}

int SGZControl_Proxy::Get_c( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_c());
    return 1;
}

int SGZControl_Proxy::Get_v( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_v());
    return 1;
}

int SGZControl_Proxy::Get_b( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_b());
    return 1;
}

int SGZControl_Proxy::Get_n( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_n());
    return 1;
}

int SGZControl_Proxy::Get_m( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_m());
    return 1;
}

int SGZControl_Proxy::Get_lshift( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_lshift());
    return 1;
}

int SGZControl_Proxy::Get_lalt( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_lalt());
    return 1;
}

int SGZControl_Proxy::Get_lctrl( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_lctrl());
    return 1;
}

int SGZControl_Proxy::Get_space( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_space());
    return 1;
}

int SGZControl_Proxy::Get_return( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_return());
    return 1;
}

int SGZControl_Proxy::Get_ralt( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_ralt());
    return 1;
}

int SGZControl_Proxy::Get_rshift( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_rshift());
    return 1;
}

int SGZControl_Proxy::Get_rctrl( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_rctrl());
    return 1;
}

int SGZControl_Proxy::Get_F1( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F1());
    return 1;
}

int SGZControl_Proxy::Get_F2( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F2());
    return 1;
}

int SGZControl_Proxy::Get_F3( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F3());
    return 1;
}

int SGZControl_Proxy::Get_F4( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F4());
    return 1;
}

int SGZControl_Proxy::Get_F5( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F5());
    return 1;
}

int SGZControl_Proxy::Get_F6( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F6());
    return 1;
}

int SGZControl_Proxy::Get_F7( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F7());
    return 1;
}

int SGZControl_Proxy::Get_F8( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F8());
    return 1;
}

int SGZControl_Proxy::Get_F9( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F9());
    return 1;
}

int SGZControl_Proxy::Get_F10( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F10());
    return 1;
}

int SGZControl_Proxy::Get_F11( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F11());
    return 1;
}

int SGZControl_Proxy::Get_F12( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_F12());
    return 1;
}

int SGZControl_Proxy::Get_plus( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_plus());
    return 1;
}

int SGZControl_Proxy::Get_minus( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_minus());
    return 1;
}

int SGZControl_Proxy::Get_ESC( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_ESC());
    return 1;
}

int SGZControl_Proxy::Get_backspace( lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessController()->Get_backspace());
    return 1;
}


const char SGZControl_Proxy::className[] = "SGZControlManager";
Lunar<SGZControl_Proxy>::RegType SGZControl_Proxy::methods[] =
{
    {"UpdateControls",  &SGZControl_Proxy::UpdateControls},
    {"Get_Key", &SGZControl_Proxy::GetKey},
    {"Get_Pads", &SGZControl_Proxy::GetJoysticks},
    {"Get_PadButton", &SGZControl_Proxy::GetJoystickButton},
    {"Get_PadAxis", &SGZControl_Proxy::GetJoystickAxis},
    {"Get_PadDetails", &SGZControl_Proxy::GetJoystickDetails},
    {"Get_PadHat", &SGZControl_Proxy::GetJoystickHat},
    {"Get_Left", &SGZControl_Proxy::Get_LEFT},
    {"Get_Right", &SGZControl_Proxy::Get_RIGHT},
    {"Get_Up", &SGZControl_Proxy::Get_UP},
    {"Get_Down", &SGZControl_Proxy::Get_DOWN},
    {"Get_START", &SGZControl_Proxy::Get_START},
    {"Get_SELECT", &SGZControl_Proxy::Get_SELECT},
    {"Get_Fire1", &SGZControl_Proxy::Get_Fire1},
    {"Get_Fire2", &SGZControl_Proxy::Get_Fire2},
    {"Get_Fire3", &SGZControl_Proxy::Get_Fire3},
    {"Get_Fire4", &SGZControl_Proxy::Get_Fire4},
    {"Get_1", &SGZControl_Proxy::Get_1},
    {"Get_2", &SGZControl_Proxy::Get_2},
    {"Get_3", &SGZControl_Proxy::Get_3},
    {"Get_4", &SGZControl_Proxy::Get_4},
    {"Get_5", &SGZControl_Proxy::Get_5},
    {"Get_6", &SGZControl_Proxy::Get_6},
    {"Get_7", &SGZControl_Proxy::Get_7},
    {"Get_8", &SGZControl_Proxy::Get_8},
    {"Get_9", &SGZControl_Proxy::Get_9},
    {"Get_0", &SGZControl_Proxy::Get_0},
    {"Get_q", &SGZControl_Proxy::Get_q},
    {"Get_w", &SGZControl_Proxy::Get_w},
    {"Get_e", &SGZControl_Proxy::Get_e},
    {"Get_r", &SGZControl_Proxy::Get_r},
    {"Get_t", &SGZControl_Proxy::Get_t},
    {"Get_y", &SGZControl_Proxy::Get_y},
    {"Get_u", &SGZControl_Proxy::Get_u},
    {"Get_i", &SGZControl_Proxy::Get_i},
    {"Get_o", &SGZControl_Proxy::Get_o},
    {"Get_p", &SGZControl_Proxy::Get_p},
    {"Get_a", &SGZControl_Proxy::Get_a},
    {"Get_s", &SGZControl_Proxy::Get_s},
    {"Get_d", &SGZControl_Proxy::Get_d},
    {"Get_f", &SGZControl_Proxy::Get_f},
    {"Get_g", &SGZControl_Proxy::Get_g},
    {"Get_h", &SGZControl_Proxy::Get_h},
    {"Get_j", &SGZControl_Proxy::Get_j},
    {"Get_k", &SGZControl_Proxy::Get_k},
    {"Get_l", &SGZControl_Proxy::Get_l},
    {"Get_z", &SGZControl_Proxy::Get_z},
    {"Get_x", &SGZControl_Proxy::Get_x},
    {"Get_c", &SGZControl_Proxy::Get_c},
    {"Get_v", &SGZControl_Proxy::Get_v},
    {"Get_b", &SGZControl_Proxy::Get_b},
    {"Get_n", &SGZControl_Proxy::Get_n},
    {"Get_m", &SGZControl_Proxy::Get_m},
    {"Get_lshift", &SGZControl_Proxy::Get_lshift},
    {"Get_lctrl", &SGZControl_Proxy::Get_lctrl},
    {"Get_lalt", &SGZControl_Proxy::Get_lalt},
    {"Get_space", &SGZControl_Proxy::Get_space},
    {"Get_ralt", &SGZControl_Proxy::Get_ralt},
    {"Get_rctrl", &SGZControl_Proxy::Get_rctrl},
    {"Get_rshift", &SGZControl_Proxy::Get_rshift},
    {"Get_return", &SGZControl_Proxy::Get_return},
    {"Get_backspace", &SGZControl_Proxy::Get_backspace},
    {"Get_F1", &SGZControl_Proxy::Get_F1},
    {"Get_F2", &SGZControl_Proxy::Get_F2},
    {"Get_F3", &SGZControl_Proxy::Get_F3},
    {"Get_F4", &SGZControl_Proxy::Get_F4},
    {"Get_F5", &SGZControl_Proxy::Get_F5},
    {"Get_F6", &SGZControl_Proxy::Get_F6},
    {"Get_F7", &SGZControl_Proxy::Get_F7},
    {"Get_F8", &SGZControl_Proxy::Get_F8},
    {"Get_F9", &SGZControl_Proxy::Get_F9},
    {"Get_F10", &SGZControl_Proxy::Get_F10},
    {"Get_F11", &SGZControl_Proxy::Get_F11},
    {"Get_F12", &SGZControl_Proxy::Get_F12},
    {"Get_minus", &SGZControl_Proxy::Get_minus},
    {"Get_plus", &SGZControl_Proxy::Get_plus},
    {0,0}
};
