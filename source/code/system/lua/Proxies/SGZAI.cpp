#include "SGZAI.h"
#include "typedefs.h"
#include "CInterpret.h"
#include <string>

using namespace std;

int SGZAI_Proxy::reset(lua_State *Lua)              ///deletes and resets the AI system
{
    if (lua_gettop(Lua)==0)
    {
        // kill and reset everything in the AI
        AIWorld->reset();
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::reset was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAI_Proxy::addWayPoint(lua_State *Lua)        ///add a waypoint. in = weedunkType, name, pos. out = waypoint ID
{
    int ID = 0;

    if (lua_gettop(Lua)==6 && lua_isnumber(Lua, 1)==1 && lua_isstring(Lua, 2)==1 && lua_isnumber(Lua, 3)==1 && lua_isnumber(Lua, 4)==1 && lua_isnumber(Lua, 5)==1 && lua_isnumber(Lua, 6)==1)
    {
        // add the waypoint to the system
        ID = AIWorld->addWayPoint((int)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), SGZVECTOR((float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4), (float)lua_tonumber(Lua, 5)), (float)lua_tonumber(Lua, 6));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::addWayPoint was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, ID);

    return 1;
}

int SGZAI_Proxy::addWeedunk(lua_State *Lua)         ///add a weedunk to the system. in = weedunkType, odeID; out = AI ID
{
    int ID = 0;

    if (lua_gettop(Lua)==2 && lua_isnumber(Lua, 1)==1 && lua_isnumber(Lua, 2)==1)
    {
        // add the weedunk to the system
        ID = AIWorld->addWeedunk((int)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::addWeedunk was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, ID);

    return 1;
}

int SGZAI_Proxy::killWeedunk(lua_State *Lua)        /// remove a weedunk from the AI system, in = AI ID
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a weedunk from the system to the system
        if ((int)lua_tonumber(Lua, 1)>=0)
            AIWorld->removeWeedunk((int)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::killWeedunk was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAI_Proxy::killWaypoint(lua_State *Lua)        /// remove a waypoint from the AI system, in = AI ID
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        AIWorld->removeWaypoint((int)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::killWaypoint was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAI_Proxy::getWeedunkState(lua_State *Lua)
{
    string state;

    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        weedunkState tmp = AIWorld->getWeedunkState((int)lua_tonumber(Lua, 1));

        switch (tmp)
        {
            case WEEDUNK_IDLE:
                state = "Idle";
            break;
            case WEEDUNK_WORKING:
                state = "Working";
            break;
            case WEEDUNK_WALKING:
                state = "Walking";
            break;
            case WEEDUNK_DANCING:
                state = "Dancing";
            break;
            default:
                state = "Fucked";
            break;
        }
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::getWeedunkState was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, state.c_str());

    return 1;
}

int SGZAI_Proxy::setWeedunkMoveForce(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        AIWorld->setWeedunkMoveForce((float)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::setWeedunkMoveForce was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAI_Proxy::setWaypointSize(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        AIWorld->setWaypointSize((float)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::setWaypointSize was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAI_Proxy::setMaxDistToWalk(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        AIWorld->setMaxDistToWalk((float)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::setMaxDistToWalk was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}


int SGZAI_Proxy::setIdleDanceTime(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        AIWorld->setIdleDanceTime((int)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::setIdleDanceTime was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAI_Proxy::setIdleChangeDir(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        AIWorld->setIdleChangeDir((int)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::setIdleChangeDir was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}


int SGZAI_Proxy::setWeedunkHeight(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        AIWorld->setWeedunkHeight((float)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::setWeedunkHeight was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAI_Proxy::getWeedunkRot(lua_State *Lua)
{
    float rot = 0;
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1)==1)
    {
        // remove a waypoint from the system to the system
        rot = AIWorld->getWeedunkRot((int)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("SGZAI_Proxy::getWeedunkRot was not passed correct arguments\n");
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, rot);

    return 1;
}

const char SGZAI_Proxy::className[] = "SGZAI";
Lunar<SGZAI_Proxy>::RegType SGZAI_Proxy::methods[] =
{
    {"Reset", &SGZAI_Proxy::reset},

    {"AddWayPoint", &SGZAI_Proxy::addWayPoint},
    {"AddWeedunk", &SGZAI_Proxy::addWeedunk},

    {"KillWeedunk", &SGZAI_Proxy::killWeedunk},
    {"KillWaypoint", &SGZAI_Proxy::killWaypoint},

    {"GetWeedunkState", &SGZAI_Proxy::getWeedunkState},
    {"GetWeedunkRot", &SGZAI_Proxy::getWeedunkRot},

    {"SetWeedunkMoveForce", &SGZAI_Proxy::setWeedunkMoveForce},
    {"SetWaypointSize", &SGZAI_Proxy::setWaypointSize},
    {"SetMaxDistToWalk", &SGZAI_Proxy::setMaxDistToWalk},
    {"SetIdleDanceTime", &SGZAI_Proxy::setIdleDanceTime},
    {"SetIdleChangeDir", &SGZAI_Proxy::setIdleChangeDir},
    {"SetWeedunkHeight", &SGZAI_Proxy::setWeedunkHeight},

    {0,0}
};

