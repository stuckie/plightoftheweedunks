#include "SGZEntity2D.h"

SGZEntity2D_Proxy::SGZEntity2D_Proxy(lua_State *Lua)
{
    int values = lua_gettop(Lua);
    if (values>0)
    {
        Entity = new OEntity2D( lua_tostring(Lua, -1) );
    }
    else Entity = new OEntity2D;

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);
}

int SGZEntity2D_Proxy::Update(lua_State *Lua)
{
    /** Update our beloved entity */
    Entity->Update();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::MoveTo (lua_State *Lua)
{
    /** Move to direct co-ordinates */
    SGZVECTOR move;
    move.x = (SGZVECTORVAL)lua_tonumber(Lua, -3);
    move.y = (SGZVECTORVAL)lua_tonumber(Lua, -2);
    move.z = (SGZVECTORVAL)lua_tonumber(Lua, -1);
    Entity->MoveTo( move );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::LookTo (lua_State *Lua)
{
    /** Direction to look at ( move towards ) */
    SGZVECTOR look;
    look.x = (SGZVECTORVAL)lua_tonumber(Lua, -3);
    look.y = (SGZVECTORVAL)lua_tonumber(Lua, -2);
    look.z = (SGZVECTORVAL)lua_tonumber(Lua, -1);
    Entity->LookTo( look );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::MoveDeltaX (lua_State *Lua)
{
    /** Move a certain amount in a certain axis */
    Entity->MoveDeltaX( (SGZVECTORVAL)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::MoveDeltaY (lua_State *Lua)
{
    /** Move a certain amount in a certain axis */
    Entity->MoveDeltaY( (SGZVECTORVAL)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::MoveDeltaZ ( lua_State *Lua)
{
    /** Move a certain amount in a certain axis */
    Entity->MoveDeltaZ( (SGZVECTORVAL)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::GetX ( lua_State *Lua )
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return position data */
    lua_pushnumber(Lua, Entity->GetX());
    return 1;
}

int SGZEntity2D_Proxy::GetY ( lua_State *Lua )
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return position data */
    lua_pushnumber(Lua, Entity->GetY());
    return 1;
}

int SGZEntity2D_Proxy::GetZ ( lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return position data */
    lua_pushnumber(Lua, Entity->GetZ());
    return 1;
}

int SGZEntity2D_Proxy::GetLookX ( lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return look data */
    lua_pushnumber(Lua, Entity->GetLookX());
    return 1;
}

int SGZEntity2D_Proxy::GetLookY ( lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return look data */
    lua_pushnumber(Lua, Entity->GetLookY());
    return 1;
}

int SGZEntity2D_Proxy::GetLookZ ( lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return look data */
    lua_pushnumber(Lua, Entity->GetLookZ());
    return 1;
}

int SGZEntity2D_Proxy::Scale ( lua_State *Lua )
{
    /** Scale overall */
    Entity->Scale( (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::ScaleX ( lua_State *Lua )
{
    /** Scale in a specified axis */
    Entity->ScaleX( (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::ScaleY( lua_State *Lua )
{
    /** Scale in a specified axis */
    Entity->ScaleY( (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::ScaleZ( lua_State *Lua )
{
    /** Scale in a specified axis */
    Entity->ScaleZ( (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::RotateX ( lua_State *Lua )
{
    /** Rotate in a specified axis */
    Entity->RotateX( (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::RotateY( lua_State *Lua )
{
    /** Rotate in a specified axis */
    Entity->RotateY( (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::RotateZ( lua_State *Lua )
{
    /** Rotate in a specified axis */
    Entity->RotateZ( (SGZSCALER)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::MaxAccel(lua_State *Lua )
{
    /** Set Max Accel */
    Entity->MaxAccel ( (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::GetSpeed(lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return Current Speed */
    lua_pushnumber(Lua, Entity->GetSpeed());
    return 1;
}

int SGZEntity2D_Proxy::GetAccel(lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return Current Accel */
    lua_pushnumber(Lua, Entity->GetAccel());
    return 1;
}

int SGZEntity2D_Proxy::SetAccel(lua_State *Lua )
{
    /** Set Accel */
    Entity->SetAccel ( (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::SetSpeed(lua_State *Lua )
{
    /** Set Accel */
    Entity->SetSpeed ( (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::MaxSpeed(lua_State *Lua )
{
    /** Set Accel */
    Entity->MaxSpeed ( (SGZSCALER)lua_tonumber(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::Stop ( lua_State *Lua )
{
    /** Stop moving/rotating/scaling immediately */
    Entity->Stop();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::SetCollisionGeom ( lua_State *Lua )
{
    /** Set the collision type */
    Entity->SetCollisionGeom( (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::GetAnimation( lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Get Current Animation Name */
    lua_pushstring(Lua, Entity->GetAnimation().c_str());

    return 1;
}

int SGZEntity2D_Proxy::SetAnimation( lua_State *Lua )
{
    /** Set the current Animation */
    Entity->SetAnimation( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::CreateAnimation( lua_State *Lua )
{
    /** Create a new Animation Group */
    Entity->CreateAnimation( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::DeleteAnimation( lua_State *Lua )
{
    /** Delete an Animation Group */
    Entity->DeleteAnimation( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::LoadTexture ( lua_State *Lua )
{
    /** Load an Animation Frame */
    SGZCOLOUR colour;
    colour.r = (SGZCOLOURVAL)lua_tonumber(Lua, -3);
    colour.g = (SGZCOLOURVAL)lua_tonumber(Lua, -2);
    colour.b = (SGZCOLOURVAL)lua_tonumber(Lua, -1);
    Entity->LoadFrame( lua_tostring(Lua, -9), lua_tostring(Lua, -8), lua_tostring(Lua, -7), (int)lua_tonumber(Lua, -6), (int)lua_tonumber(Lua, -5), (int)lua_tonumber(Lua, -4), colour );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::SetName( lua_State *Lua )
{
    /** Reset Name */
    Entity->SetName( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::GetName ( lua_State *Lua )
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    /** Return the Name */
    lua_pushstring(Lua, Entity->GetName().c_str());
    return 1;
}

int SGZEntity2D_Proxy::Colour ( lua_State *Lua )
{
    SGZCOLOUR col;
    col.r = (SGZCOLOURVAL)lua_tonumber(Lua, -3);
    col.g = (SGZCOLOURVAL)lua_tonumber(Lua, -2);
    col.b = (SGZCOLOURVAL)lua_tonumber(Lua, -1);
    Entity->Colour( col );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::NewVar ( lua_State *Lua )
{
    Entity->NewVar( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::DeleteVar ( lua_State *Lua )
{
    Entity->DeleteVar(lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::ChangeVar ( lua_State *Lua )
{
    Entity->ChangeVar( lua_tostring(Lua, -2), lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZEntity2D_Proxy::CheckVar ( lua_State *Lua )
{
    std::string value = Entity->CheckVar( lua_tostring(Lua, -1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, value.c_str());

    return 1;
}

const char SGZEntity2D_Proxy::className[] = "SGZEntity2D";
Lunar<SGZEntity2D_Proxy>::RegType SGZEntity2D_Proxy::methods[] =
{
    {"Update", &SGZEntity2D_Proxy::Update},
    {"Colour", &SGZEntity2D_Proxy::Colour},
    {"MoveTo", &SGZEntity2D_Proxy::MoveTo},
    {"LookTo", &SGZEntity2D_Proxy::LookTo},
    {"MoveDeltaX", &SGZEntity2D_Proxy::MoveDeltaX},
    {"MoveDeltaY", &SGZEntity2D_Proxy::MoveDeltaY},
    {"MoveDeltaZ", &SGZEntity2D_Proxy::MoveDeltaZ},
    {"GetLookX", &SGZEntity2D_Proxy::GetLookX},
    {"GetLookY", &SGZEntity2D_Proxy::GetLookY},
    {"GetLookZ", &SGZEntity2D_Proxy::GetLookZ},
    {"GetX", &SGZEntity2D_Proxy::GetX},
    {"GetY", &SGZEntity2D_Proxy::GetY},
    {"GetZ", &SGZEntity2D_Proxy::GetZ},
    {"ScaleX", &SGZEntity2D_Proxy::ScaleX},
    {"ScaleY", &SGZEntity2D_Proxy::ScaleY},
    {"ScaleZ", &SGZEntity2D_Proxy::ScaleZ},
    {"Scale", &SGZEntity2D_Proxy::Scale},
    {"RotateX", &SGZEntity2D_Proxy::RotateX},
    {"RotateY", &SGZEntity2D_Proxy::RotateY},
    {"RotateZ", &SGZEntity2D_Proxy::RotateZ},
    {"MaxAccel", &SGZEntity2D_Proxy::MaxAccel},
    {"SetAccel", &SGZEntity2D_Proxy::SetAccel},
    {"MaxSpeed", &SGZEntity2D_Proxy::MaxSpeed},
    {"SetSpeed", &SGZEntity2D_Proxy::SetSpeed},
    {"GetSpeed", &SGZEntity2D_Proxy::GetSpeed},
    {"GetAccel", &SGZEntity2D_Proxy::GetAccel},
    {"Stop", &SGZEntity2D_Proxy::Stop},
    {"SetCollisionGeom", &SGZEntity2D_Proxy::SetCollisionGeom},
    {"GetAnimation", &SGZEntity2D_Proxy::GetAnimation},
    {"SetAnimation", &SGZEntity2D_Proxy::SetAnimation},
    {"CreateAnimation", &SGZEntity2D_Proxy::CreateAnimation},
    {"DeleteAnimation", &SGZEntity2D_Proxy::DeleteAnimation},
    {"LoadFrame", &SGZEntity2D_Proxy::LoadTexture},
    {"SetName", &SGZEntity2D_Proxy::SetName},
    {"GetName", &SGZEntity2D_Proxy::GetName},
    {"NewVar", &SGZEntity2D_Proxy::NewVar},
    {"ChangeVar", &SGZEntity2D_Proxy::ChangeVar},
    {"DeleteVar", &SGZEntity2D_Proxy::DeleteVar},
    {"CheckVar", &SGZEntity2D_Proxy::CheckVar},
    {0,0}
};
