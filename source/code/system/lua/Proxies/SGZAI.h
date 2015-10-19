#ifndef _SGZAI_H_
#define _SGZAI_H_

#include "arch.h"

#ifdef pedanticGCC
extern "C" {
#endif
    #include "../lualib.h"
#ifdef pedanticGCC
}
#endif

#include "../lunar.h"
#include "../../../common/debug/CDebug.h"
#include "AI.h"
#include "CInterpret.h"
#include "typedefs.h"


// enum weedunkType = { WEEDUNK=1, BERT = 2, ERNIE = 3};
// special case for WEEDUNK as it is for any weedunk going to a portal, should not be used in addWeedunk

class SGZAI_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZAI_Proxy>::RegType methods[];

        int reset(lua_State *Lua);              // deletes and resets the AI system

        int addWayPoint(lua_State *Lua);        // add a waypoint. in = weedunkType, name,  pos. out = waypoint ID
        int addWeedunk(lua_State *Lua);         // add a weedunk to the system. in = weedunkType, odeID, pos. out = AI ID

        int killWeedunk(lua_State *Lua);        // remove a weedunk from the AI system, in = AI ID
        int killWaypoint(lua_State *Lua);       // remove a waypoint from the AI system, in = waypoint ID

        int getWeedunkState(lua_State *Lua);
        int getWeedunkRot(lua_State *Lua);

        int setWeedunkMoveForce(lua_State *Lua);
        int setWaypointSize(lua_State *Lua);
        int setMaxDistToWalk(lua_State *Lua);
        int setIdleDanceTime(lua_State *Lua);
        int setIdleChangeDir(lua_State *Lua);
        int setWeedunkHeight(lua_State *Lua);

        SGZAI_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZAI_Proxy() {}

    private:
};

#endif // _SGZAI_H_

