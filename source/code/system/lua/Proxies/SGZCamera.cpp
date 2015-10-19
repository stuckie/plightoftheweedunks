#include "SGZCamera.h"
#include "../../../arch.h"

int SGZCamera_Proxy::Create(lua_State *Lua)
{
    if (lua_gettop(Lua)!=6 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isstring(Lua, 6)==0)
    {
        SGZLogger.warn("Create takes 5 numbers and 1 string\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.Create((int)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4), (float)lua_tonumber(Lua, 5), lua_tostring(Lua, 6));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;
}

int SGZCamera_Proxy::Update(lua_State *Lua)
{

    cam.Update();

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::RotateAroundX(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("RotateX takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.RotateAroundX((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::RotateAroundY(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("RotateY takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.RotateAroundY((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::RotateAroundZ(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("RotateZ takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.RotateAroundZ((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::Forward(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("Forward takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.Forward((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::Up(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("Up takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.Up((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::Right(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("Right takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.Right((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::Backward(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("Backward takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.Forward(0.0f-(float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}


int SGZCamera_Proxy::Down(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("Down takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.Up(0.0f-(float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::Left(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("Left takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.Right(0.0f-(float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::SetCameraParams(lua_State *Lua)
{
    if (lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("SetCameraParams takes 4 numbers\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.SetCameraParams((float)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::FitPointsInView(lua_State *Lua)
{
    if (lua_gettop(Lua)!=6 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0|| lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isnumber(Lua, 6)==0)
    {
        SGZLogger.warn("FitPointsInView takes 3 numbers\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.FitPointsInView(SGZVECTOR((float)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3)),
                        SGZVECTOR((float)lua_tonumber(Lua, 4), (float)lua_tonumber(Lua, 5), (float)lua_tonumber(Lua, 6)));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::TurnOnFreeCam(lua_State *Lua)
{
    cam.TurnOnFreeCam();

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::TurnOnGameCam(lua_State *Lua)
{
    cam.TurnOnGameCam();

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::TurnOnShakeCam(lua_State *Lua)
{
    if (lua_gettop(Lua)!=2 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0)
    {
        SGZLogger.warn("TurnOnShakeCam takes 2 numbers\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.TurnOnShakeCam((int)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::LookNorth(lua_State *Lua)
{
    cam.SetLookingIn(NORTH);

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::LookSouth(lua_State *Lua)
{
    cam.SetLookingIn(SOUTH);

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::LookEast(lua_State *Lua)
{
    cam.SetLookingIn(EAST);

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::LookWest(lua_State *Lua)
{
    cam.SetLookingIn(WEST);

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::GetCamLookDir(lua_State *Lua)
{
    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    switch (cam.GetLookingIn())
    {
    case NORTH:
        lua_pushstring(Lua, "N");
        return 1;
    case SOUTH:
        lua_pushstring(Lua, "S");
        return 1;
    case EAST:
        lua_pushstring(Lua, "E");
        return 1;
    case WEST:
        lua_pushstring(Lua, "W");
        return 1;
    default:
        SGZLogger.warn("Unknown camera mode in GetCamLookDir\n");
        return 0;
    }
}

int SGZCamera_Proxy::SetInterpolation(lua_State *Lua)
{
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("SetInterpolation takes 1 number\n");
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
            lua_pop(Lua, cnt);

        return 0;
    }

    cam.SetIntMult((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;

}

int SGZCamera_Proxy::GetCamPos(lua_State *Lua)
{
    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    SGZVECTOR pos = cam.GetCamPos();
    lua_pushnumber(Lua, pos.x);
    lua_pushnumber(Lua, pos.y);
    lua_pushnumber(Lua, pos.z);

    return 3;
}

const char SGZCamera_Proxy::className[] = "SGZCamera";
Lunar<SGZCamera_Proxy>::RegType SGZCamera_Proxy::methods[] =
{
    {"Create", &SGZCamera_Proxy::Create},
    {"Update", &SGZCamera_Proxy::Update},
    {"TurnOnFreeCam", &SGZCamera_Proxy::TurnOnFreeCam},
    {"TurnOnGameCam", &SGZCamera_Proxy::TurnOnGameCam},
    {"TurnOnShakeCam", &SGZCamera_Proxy::TurnOnShakeCam},
    {"RotateAroundX", &SGZCamera_Proxy::RotateAroundX},
    {"RotateAroundY", &SGZCamera_Proxy::RotateAroundY},
    {"RotateAroundZ", &SGZCamera_Proxy::RotateAroundZ},
    {"Up", &SGZCamera_Proxy::Up},
    {"Right", &SGZCamera_Proxy::Right},
    {"Forward", &SGZCamera_Proxy::Forward},
    {"Backward", &SGZCamera_Proxy::Backward},
    {"Down", &SGZCamera_Proxy::Down},
    {"Left", &SGZCamera_Proxy::Left},
    {"SetCameraParams", &SGZCamera_Proxy::SetCameraParams},
    {"LookNorth", &SGZCamera_Proxy::LookNorth},
    {"LookSouth", &SGZCamera_Proxy::LookSouth},
    {"LookEast", &SGZCamera_Proxy::LookEast},
    {"LookWest", &SGZCamera_Proxy::LookWest},
    {"GetCamLookDir", &SGZCamera_Proxy::GetCamLookDir},
    {"FitPointsInView", &SGZCamera_Proxy::FitPointsInView},
    {"SetInterpolation", &SGZCamera_Proxy::SetInterpolation},
    {"GetCamPos", &SGZCamera_Proxy::GetCamPos},
    {0,0}
};
