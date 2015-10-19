#ifndef _SGZEVENT_H_
#define _SGZEVENT_H_

#ifdef pedanticGCC
extern "C" {
#endif
    #include "../lualib.h"
#ifdef pedanticGCC
}
#endif

#include <string>
#include "lunar.h"
#include "arch.h"
#include "CDebug.h"
#include "CSLinkedlist.h"
#include "CTimer.h"

struct SGZEvent
{
    int event;
    int startTime;
};

class SGZEvent_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZEvent_Proxy>::RegType methods[];

        int Save(lua_State *L);
        int Load(lua_State *L);
        int Playback(lua_State *L);
        int Record(lua_State *L);
        int Stop(lua_State *L);
        int GetTime(lua_State *L);

        SGZEvent_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
            Timer.start();
            SListIterator<SGZEvent*> EventListITR = EventList.GetIterator();
        }
        ~SGZEvent_Proxy() {}

    private:

    SLinkedList<SGZEvent*> EventList;
    SListIterator<SGZEvent*> EventListITR;
    CTimer Timer;

};

#endif
