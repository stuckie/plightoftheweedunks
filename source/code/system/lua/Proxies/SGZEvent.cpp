#include "SGZEvent.h"

int SGZEvent_Proxy::Save(lua_State *Lua)
{
    std::string temp = lua_tostring(Lua, 1);
    EventList.SaveToDisk(temp.c_str());

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEvent_Proxy::Load(lua_State *Lua)
{
    std::string temp = lua_tostring(Lua, 1);
    EventList.ReadFromDisk(temp.c_str());
    SListIterator<SGZEvent*> EventListITR = EventList.GetIterator();
    Timer.reset();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEvent_Proxy::Record(lua_State *Lua)
{
    SGZEvent *newEvent = new SGZEvent;
    newEvent->event = (int)lua_tonumber(Lua, 1);
    newEvent->startTime = Timer.currenttime();

    SGZLogger.debug("Added: %d at Time %d | Current %d\n", newEvent->event, newEvent->startTime, Timer.currenttime());

    EventList.Append(newEvent);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEvent_Proxy::Playback(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    SListIterator<SGZEvent*> EventListITR = EventList.GetIterator();
    for( EventListITR.Start(); EventListITR.Valid(); EventListITR.Forth() )
    {
        SGZLogger.debug("Event: %d at Time %d | Current %d\n", EventListITR.Item()->event, EventListITR.Item()->startTime, Timer.currenttime());
        if(EventListITR.Item()->startTime == Timer.currenttime())
        {
            lua_pushnumber(Lua, EventListITR.Item()->event);
            return 1;
        }
    }

    return 0;
}

int SGZEvent_Proxy::Stop(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    Timer.stop();

    return 0;
}

int SGZEvent_Proxy::GetTime(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, Timer.currenttime());

    return 1;
}

const char SGZEvent_Proxy::className[] = "SGZEvent";
Lunar<SGZEvent_Proxy>::RegType SGZEvent_Proxy::methods[] =
{
    {"Save", &SGZEvent_Proxy::Save},
    {"Load", &SGZEvent_Proxy::Load},
    {"Playback", &SGZEvent_Proxy::Playback},
    {"Record", &SGZEvent_Proxy::Record},
    {"Stop", &SGZEvent_Proxy::Stop},
    {"GetTime", &SGZEvent_Proxy::GetTime},
    {0,0}
};

