#ifndef _SGZENTITY2D_PROXY_H_
#define _SGZENTITY2D_PROXY_H_

#ifdef pedanticGCC
extern "C" {
#endif
    #include "../lualib.h"
#ifdef pedanticGCC
}
#endif

#include "../lunar.h"
#include "../../../arch.h"
#include "../../../common/debug/CDebug.h"
#include "../../../common/engine/CInterpret.h"
#include "../../../common/entities/OEntity2D.h"

class SGZEntity2D_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZEntity2D_Proxy>::RegType methods[];

        int Update(lua_State *Lua);
        /** Update our Entity */

        int MoveTo (lua_State *Lua);
        /** Move to direct co-ordinates */

        int LookTo (lua_State *Lua);
        /** Direction to look at ( move towards ) */

        int MoveDeltaX (lua_State *Lua);
        int MoveDeltaY (lua_State *Lua);
        int MoveDeltaZ (lua_State *Lua);
        /** Move a certain amount in a certain axis */

        int GetX (lua_State *Lua);
        int GetY (lua_State *Lua);
        int GetZ (lua_State *Lua);
        /** Return position data */

        int GetLookX (lua_State *Lua);
        int GetLookY (lua_State *Lua);
        int GetLookZ (lua_State *Lua);
        /** Get Where the entity is Looking */

        int Scale (lua_State *Lua);
        int ScaleX (lua_State *Lua);
        int ScaleY (lua_State *Lua);
        int ScaleZ (lua_State *Lua);
        /** Scale overall or in a specified axis */

        int RotateX (lua_State *Lua);
        int RotateY (lua_State *Lua);
        int RotateZ (lua_State *Lua);
        /** Rotate on a specific axis */

        int MaxAccel (lua_State *Lua);
        int MaxSpeed (lua_State *Lua);
        int SetSpeed (lua_State *Lua);
        int GetSpeed (lua_State *Lua);
        int GetAccel (lua_State *Lua);
        int SetAccel (lua_State *Lua);
        /** Accelerate a certain value "forward" */

        int Stop (lua_State *Lua);
        /** Stop moving/rotating/scaling immediately */

        int SetCollisionGeom (lua_State *Lua);
        /** Set the collision type */

        int GetAnimation (lua_State *Lua);
        int SetAnimation (lua_State *Lua);
        int CreateAnimation (lua_State *Lua);
        int DeleteAnimation (lua_State *Lua);
        int LoadTexture (lua_State *Lua);
        int LoadTextureMask (lua_State *Lua);
        /** Load up a Texture into an Animation*/

        int SetName (lua_State *Lua);
        int GetName (lua_State *Lua);
        /** Reset Name, or Return the Name */

        int Colour (lua_State *Lua);
        int NewVar (lua_State *Lua);
        int CheckVar (lua_State *Lua);
        int DeleteVar (lua_State *Lua);
        int ChangeVar (lua_State *Lua);

        SGZEntity2D_Proxy(lua_State *L);
        ~SGZEntity2D_Proxy() { delete Entity; }


    private:

        OEntity2D *Entity;
};

#endif
