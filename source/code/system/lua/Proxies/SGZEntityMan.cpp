#include "SGZEntityMan.h"

int SGZEntityMan_Proxy::Add2DEntity( lua_State *Lua )
{
    int values = lua_gettop(Lua);
    if (SGZInterpret.accessServer()->World()->accessEntityManager()->EntityCount() < SGZInterpret.accessServer()->World()->accessEntityManager()->CurrentMax())
    {
        if (values>0)
        {
            OEntity2D *NewEntity = new OEntity2D(lua_tostring(Lua, -1) );
            SGZInterpret.accessServer()->World()->accessEntityManager()->AddEntity(NewEntity);
        }
    }
    else SGZLogger.warn("Max Entities Reached!\n");

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

#ifdef SGZ3D
int SGZEntityMan_Proxy::Add3DEntity( lua_State *Lua )
{
    int values = lua_gettop(Lua);
    if (values>0)
    {
        OEntity3D *NewEntity = new OEntity3D(lua_tostring(Lua, -1) );
        SGZInterpret.accessServer()->World()->accessEntityManager()->AddEntity(NewEntity);

        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    }

    return 0;
}
#endif

int SGZEntityMan_Proxy::DelEntity( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->DelEntity(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::Update(lua_State *Lua)
{
    /** Update our beloved entity */
    SGZInterpret.accessServer()->World()->accessEntityManager()->UpdateEntities();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::MoveTo (lua_State *Lua)
{
    /** Move to direct co-ordinates */
    SGZVECTOR move;
    move.x = (SGZVECTORVAL)lua_tonumber(Lua, -3);
    move.y = (SGZVECTORVAL)lua_tonumber(Lua, -2);
    move.z = (SGZVECTORVAL)lua_tonumber(Lua, -1);
    SGZInterpret.accessServer()->World()->accessEntityManager()->MoveTo( lua_tostring(Lua, -4), move );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::LookTo (lua_State *Lua)
{
    /** Direction to look at ( move towards ) */
    SGZVECTOR look;
    look.x = (SGZVECTORVAL)lua_tonumber(Lua, -3);
    look.y = (SGZVECTORVAL)lua_tonumber(Lua, -2);
    look.z = (SGZVECTORVAL)lua_tonumber(Lua, -1);
    SGZInterpret.accessServer()->World()->accessEntityManager()->LookTo( lua_tostring(Lua, -4), look );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
    return 0;
}

int SGZEntityMan_Proxy::MoveDeltaX (lua_State *Lua)
{
    /** Move a certain amount in a certain axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->MoveDeltaX( lua_tostring(Lua, -2), (SGZVECTORVAL)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::MoveDeltaY (lua_State *Lua)
{
    /** Move a certain amount in a certain axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->MoveDeltaY( lua_tostring(Lua, -2), (SGZVECTORVAL)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::MoveDeltaZ ( lua_State *Lua)
{
    /** Move a certain amount in a certain axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->MoveDeltaZ( lua_tostring(Lua, -2), (SGZVECTORVAL)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::GetWidth ( lua_State *Lua )
{
    /** Get the Width of the entity */

    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetWidth(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetHeight ( lua_State *Lua )
{
    /** Get the Width of the entity */

    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetHeight(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetDepth ( lua_State *Lua )
{
    /** Get the Width of the entity */

    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetDepth(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetX ( lua_State *Lua )
{
    /** Return position data */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetX(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetY ( lua_State *Lua )
{
    /** Return position data */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetY(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetZ ( lua_State *Lua )
{
    /** Return position data */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetZ(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetLookX ( lua_State *Lua )
{
    /** Return look data */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetLookX(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetLookY ( lua_State *Lua )
{
    /** Return look data */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetLookY(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetLookZ ( lua_State *Lua )
{
    /** Return look data */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetLookZ(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::Scale ( lua_State *Lua )
{
    /** Scale overall */
    SGZInterpret.accessServer()->World()->accessEntityManager()->Scale( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::ScaleX ( lua_State *Lua )
{
    /** Scale in a specified axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->ScaleX( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);


    return 0;
}

int SGZEntityMan_Proxy::ScaleY( lua_State *Lua )
{
    /** Scale in a specified axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->ScaleY( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);


    return 0;
}

int SGZEntityMan_Proxy::ScaleZ( lua_State *Lua )
{
    /** Scale in a specified axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->ScaleZ( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);


    return 0;
}

int SGZEntityMan_Proxy::RotateX ( lua_State *Lua )
{
    /** Rotate in a specified axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->RotateX( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);


    return 0;
}

int SGZEntityMan_Proxy::RotateY( lua_State *Lua )
{
    /** Rotate in a specified axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->RotateY( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);


    return 0;
}

int SGZEntityMan_Proxy::RotateZ( lua_State *Lua )
{
    /** Rotate in a specified axis */
    SGZInterpret.accessServer()->World()->accessEntityManager()->RotateZ( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);


    return 0;
}

int SGZEntityMan_Proxy::MaxAccel(lua_State *Lua )
{
    /** Set Max Accel */
    SGZInterpret.accessServer()->World()->accessEntityManager()->MaxAccel ( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::SetSpeed(lua_State *Lua )
{
    /** Set Max Accel */
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetSpeed ( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::MaxSpeed(lua_State *Lua )
{
    /** Set Max Accel */
    SGZInterpret.accessServer()->World()->accessEntityManager()->MaxSpeed ( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::GetSpeed(lua_State *Lua )
{
    /** Return Current Speed */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetSpeed(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::GetAccel(lua_State *Lua )
{
    /** Return Current Accel */
    SGZSCALER value = SGZInterpret.accessServer()->World()->accessEntityManager()->GetAccel(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::SetAccel(lua_State *Lua )
{
    /** Set Accel */
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetAccel ( lua_tostring(Lua, -2), (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::Stop ( lua_State *Lua )
{
    /** Stop moving/rotating/scaling immediately */
    SGZInterpret.accessServer()->World()->accessEntityManager()->Stop(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::SetCollisionGeom ( lua_State *Lua )
{
    /** Set the collision type */
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetCollisionGeom( lua_tostring(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::GetAnimation( lua_State *Lua )
{
    /** Get Current Animation Name */
    std::string AnimName = SGZInterpret.accessServer()->World()->accessEntityManager()->GetAnimation(lua_tostring(Lua,-1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, AnimName.c_str());
    return 1;
}

int SGZEntityMan_Proxy::SetAnimation( lua_State *Lua )
{
    /** Set the current Animation */
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetAnimation( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::CreateAnimation( lua_State *Lua )
{
    /** Create a new Animation Group */
    SGZInterpret.accessServer()->World()->accessEntityManager()->CreateAnimation( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::DeleteAnimation( lua_State *Lua )
{
    /** Delete an Animation Group */
    SGZInterpret.accessServer()->World()->accessEntityManager()->DeleteAnimation( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::LoadTexture ( lua_State *Lua )
{
    /** Load an Animation Frame */
    if(luaL_checkstring(Lua, -10)==NULL)
    {
        SGZLogger.warn("SCRIPT ERROR! Call to SGZEntityMan:LoadFrame FAILED!\n");
        return 0;
    }
    SGZCOLOUR col;
    col.r = (SGZCOLOURVAL)lua_tonumber(Lua, -3);
    col.g = (SGZCOLOURVAL)lua_tonumber(Lua, -2);
    col.b = (SGZCOLOURVAL)lua_tonumber(Lua, -1);
    SGZInterpret.accessServer()->World()->accessEntityManager()->LoadFrame( lua_tostring(Lua, -10), lua_tostring(Lua, -9), lua_tostring(Lua, -8), lua_tostring(Lua, -7), (int)lua_tonumber(Lua, -6), (int)lua_tonumber(Lua, -5), (int)lua_tonumber(Lua, -4), col );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::Colour ( lua_State *Lua )
{
    SGZCOLOUR col;
    col.r = (SGZCOLOURVAL)lua_tonumber(Lua, -3);
    col.g = (SGZCOLOURVAL)lua_tonumber(Lua, -2);
    col.b = (SGZCOLOURVAL)lua_tonumber(Lua, -1);
    SGZInterpret.accessServer()->World()->accessEntityManager()->Colour( lua_tostring(Lua, -4), col );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::NewVar ( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->NewVar( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::DeleteVar ( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->DeleteVar( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::ChangeVar ( lua_State *Lua )
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->ChangeVar( lua_tostring(Lua, -3), lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::CheckVar ( lua_State *Lua )
{
    std::string value = SGZInterpret.accessServer()->World()->accessEntityManager()->CheckVar( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, value.c_str());

    return 1;
}

int SGZEntityMan_Proxy::CheckExist(lua_State *Lua)
{
    bool value = SGZInterpret.accessServer()->World()->accessEntityManager()->CheckExist( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::CountEntities(lua_State *Lua)
{
    int value = SGZInterpret.accessServer()->World()->accessEntityManager()->EntityCount( );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);
    return 1;
}

int SGZEntityMan_Proxy::SetMaxEntities(lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetMaxEntities( (int)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::GetMaxEntities(lua_State *Lua)
{
    int value = SGZInterpret.accessServer()->World()->accessEntityManager()->CurrentMax( );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, value);

    return 1;
}

int SGZEntityMan_Proxy::SetWidth(lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetWidth( lua_tostring(Lua, -2) , (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::SetHeight(lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetHeight( lua_tostring(Lua, -2) , (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntityMan_Proxy::SetDepth(lua_State *Lua)
{
    SGZInterpret.accessServer()->World()->accessEntityManager()->SetDepth( lua_tostring(Lua, -2) , (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZEntityMan_Proxy::className[] = "SGZEntityManager";
Lunar<SGZEntityMan_Proxy>::RegType SGZEntityMan_Proxy::methods[] =
{
    {"Add2DEntity",         &SGZEntityMan_Proxy::Add2DEntity},
    #ifdef SGZ3D
    {"Add3DEntity",         &SGZEntityMan_Proxy::Add3DEntity},
    #endif
    {"Colour",              &SGZEntityMan_Proxy::Colour},
    {"DelEntity",           &SGZEntityMan_Proxy::DelEntity},
    {"Update",              &SGZEntityMan_Proxy::Update},
    {"MoveTo",              &SGZEntityMan_Proxy::MoveTo},
    {"LookTo",              &SGZEntityMan_Proxy::LookTo},
    {"MoveDeltaX",          &SGZEntityMan_Proxy::MoveDeltaX},
    {"MoveDeltaY",          &SGZEntityMan_Proxy::MoveDeltaY},
    {"MoveDeltaZ",          &SGZEntityMan_Proxy::MoveDeltaZ},
    {"GetLookX",            &SGZEntityMan_Proxy::GetLookX},
    {"GetLookY",            &SGZEntityMan_Proxy::GetLookY},
    {"GetLookZ",            &SGZEntityMan_Proxy::GetLookZ},
    {"GetX",                &SGZEntityMan_Proxy::GetX},
    {"GetY",                &SGZEntityMan_Proxy::GetY},
    {"GetZ",                &SGZEntityMan_Proxy::GetZ},
    {"GetWidth",            &SGZEntityMan_Proxy::GetWidth},
    {"GetHeight",           &SGZEntityMan_Proxy::GetHeight},
    {"GetDepth",            &SGZEntityMan_Proxy::GetDepth},
    {"ScaleX",              &SGZEntityMan_Proxy::ScaleX},
    {"ScaleY",              &SGZEntityMan_Proxy::ScaleY},
    {"ScaleZ",              &SGZEntityMan_Proxy::ScaleZ},
    {"Scale",               &SGZEntityMan_Proxy::Scale},
    {"RotateX",             &SGZEntityMan_Proxy::RotateX},
    {"RotateY",             &SGZEntityMan_Proxy::RotateY},
    {"RotateZ",             &SGZEntityMan_Proxy::RotateZ},
    {"MaxAccel",            &SGZEntityMan_Proxy::MaxAccel},
    {"SetAccel",            &SGZEntityMan_Proxy::SetAccel},
    {"MaxSpeed",            &SGZEntityMan_Proxy::MaxSpeed},
    {"SetSpeed",            &SGZEntityMan_Proxy::SetSpeed},
    {"GetSpeed",            &SGZEntityMan_Proxy::GetSpeed},
    {"GetAccel",            &SGZEntityMan_Proxy::GetAccel},
    {"Stop",                &SGZEntityMan_Proxy::Stop},
    {"SetCollisionGeom",    &SGZEntityMan_Proxy::SetCollisionGeom},
    {"GetAnimation",        &SGZEntityMan_Proxy::GetAnimation},
    {"SetAnimation",        &SGZEntityMan_Proxy::SetAnimation},
    {"CreateAnimation",     &SGZEntityMan_Proxy::CreateAnimation},
    {"DeleteAnimation",     &SGZEntityMan_Proxy::DeleteAnimation},
    {"LoadFrame",           &SGZEntityMan_Proxy::LoadTexture},
    {"NewVar",              &SGZEntityMan_Proxy::NewVar},
    {"CheckVar",            &SGZEntityMan_Proxy::CheckVar},
    {"DeleteVar",           &SGZEntityMan_Proxy::DeleteVar},
    {"ChangeVar",           &SGZEntityMan_Proxy::ChangeVar},
    {"CheckExist",          &SGZEntityMan_Proxy::CheckExist},
    {"CountEntities",       &SGZEntityMan_Proxy::CountEntities},
    {"GetMaxEntities",      &SGZEntityMan_Proxy::GetMaxEntities},
    {"SetMaxEntities",      &SGZEntityMan_Proxy::SetMaxEntities},
    {"SetHeight",           &SGZEntityMan_Proxy::SetHeight},
    {"SetWidth",            &SGZEntityMan_Proxy::SetWidth},
    {"SetDepth",            &SGZEntityMan_Proxy::SetDepth},
    {0,0}
};
