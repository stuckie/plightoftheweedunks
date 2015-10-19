#include "HordeEntity2D.h"

HordeEntity2D::HordeEntity2D()
{
}

HordeEntity2D::~HordeEntity2D()
{
}

bool HordeEntity2D::Update ( void )
{
    /** Update our beloved entity */
    return true;
}

bool HordeEntity2D::Cleanup ( void )
{
    /** Clean up our entity mess! */
    return true;
}

bool HordeEntity2D::MoveTo ( SGZVECTOR move )
{
    /** Move to direct co-ordinates */
    position = move;
    return true;
}

bool HordeEntity2D::LookTo ( SGZVECTOR look )
{
    /** Direction to look at ( move towards ) */
    looking = look;
    return true;
}

bool HordeEntity2D::MoveDeltaX ( SGZVECTORVAL amount )
{
    /** Move a certain amount in X axis */
    position.x += amount;
    return true;
}

bool HordeEntity2D::MoveDeltaY ( SGZVECTORVAL amount )
{
    /** Move a certain amount in Y axis */
    position.y += amount;
    return true;
}

bool HordeEntity2D::MoveDeltaZ ( SGZVECTORVAL amount )
{
    /** Move a certain amout in Z axis */
    position.z += amount;
    return true;
}

bool HordeEntity2D::MoveDelta ( SGZVECTOR vector )
{
    position.x += vector.x;
    position.y += vector.y;
    position.z += vector.z;

    return true;
}

bool HordeEntity2D::Scale ( SGZSCALER value )
{
    /** Scale the entity overall */
    scale.x = value;
    scale.y = value;
    scale.z = value;

    return true;
}

bool HordeEntity2D::ScaleX ( SGZSCALER value )
{
    /** Scale in X-axis */
    scale.x = value;

    return true;
}

bool HordeEntity2D::ScaleY ( SGZSCALER value )
{
    /** Scale in Y-Axis */
    scale.y = value;

    return true;
}

bool HordeEntity2D::ScaleZ ( SGZSCALER value )
{
    /** Scale in Z axis */
    scale.z = value;

    return true;
}

bool HordeEntity2D::ScaleXYZ( SGZVECTOR vector )
{
    scale = vector;

    return true;
}

bool HordeEntity2D::RotateX ( SGZSCALER value )
{
    /** Rotate in X Axis */
    rotation.x += value;

    return true;
}

bool HordeEntity2D::RotateY ( SGZSCALER value )
{
    /** Rotate in Y axis */
    rotation.y += value;

    return true;
}

bool HordeEntity2D::RotateZ ( SGZSCALER value )
{
    rotation.z += value;

    return true;
}

bool HordeEntity2D::Rotate( SGZVECTOR vector)
{
    rotation = vector;

    return true;
}

bool HordeEntity2D::MaxAccel ( SGZSCALER value )
{
    entityMaxAccel = value;

    return true;
}

bool HordeEntity2D::SetAccel ( SGZSCALER value )
{
    entityAccel = value;

    return true;
}

bool HordeEntity2D::MaxSpeed ( SGZSCALER value )
{
    entityMaxSpeed = value;

    return true;
}

bool HordeEntity2D::SetSpeed ( SGZSCALER value )
{
    entitySpeed = value;

    return true;
}

bool HordeEntity2D::SetWidth ( SGZSCALER value )
{
    entityWidth = value;

    return true;
}

bool HordeEntity2D::SetHeight ( SGZSCALER value )
{
    entityHeight = value;

    return true;
}

bool HordeEntity2D::SetDepth ( SGZSCALER value )
{
    entityDepth = value;

    return true;
}

bool HordeEntity2D::Stop ( void )
{
    /** Stop moving/rotating/scaling immediately */
    entitySpeed = 0;

    return true;
}

bool HordeEntity2D::SetCollisionGeom ( int type )
{
    /** Set the collision type */
    entityType = type;

    return true;
}

bool HordeEntity2D::SetAnimation( std::string Name )
{
    animName = Name;

    return true;
}

bool HordeEntity2D::CreateAnimation( std::string Name )
{
    SGZLogger.warn("CreateAnim in 2D Entity not created.. anim name would've been %s\n", Name.c_str());

    return true;
}

bool HordeEntity2D::DeleteAnimation( std::string Name )
{
    SGZLogger.warn("DelAnim in 2D Entity not created.. anim name would've been %s\n", Name.c_str());
    return true;
}

bool HordeEntity2D::LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey )
{
    SGZLogger.warn("LoadFrame in 2D Entity not created..\n%s %s %s %d %d %d %f %f %f", Name.c_str(), TexName.c_str(), MaskName.c_str(), FrameDelay, u, v, ColourKey.r, ColourKey.g, ColourKey.b);
    return true;
}


bool HordeEntity2D::Colour ( SGZCOLOUR col )
{
    colkey = col;
    return true;
}

std::string HordeEntity2D::CheckVar(std::string VarName)
{
    SGZLogger.warn("CheckVar in 2D Entity not created.. val would've been %s\n", VarName.c_str());
    return "none";
}

bool HordeEntity2D::NewVar(std::string VarName)
{
    SGZLogger.warn("NewVar in 2D Entity not created.. val would've been %s\n", VarName.c_str());
    return true;
}

bool HordeEntity2D::DeleteVar(std::string VarName)
{
    SGZLogger.warn("DeleteVar in 2D Entity not created.. val would've been %s\n", VarName.c_str());
    return true;
}

bool HordeEntity2D::ChangeVar(std::string VarName, std::string Value)
{
    SGZLogger.warn("ChangeVar in 2D Entity not created.. val would've been %s as %s\n", VarName.c_str(), Value.c_str());
    return true;
}

std::string HordeEntity2D::GetName( void )
{
    return entityName;
}

bool HordeEntity2D::SetName(std::string Name)
{
    entityName = Name;
    return true;
}

std::string HordeEntity2D::GetAnimation( void )
{
    return animName;
}

SGZSCALER HordeEntity2D::GetAccel( void )
{
    return entityAccel;
}

SGZSCALER HordeEntity2D::GetSpeed( void )
{
    return entitySpeed;
}

SGZSCALER HordeEntity2D::GetLookX( void )
{
    return looking.x;
}

SGZSCALER HordeEntity2D::GetLookY( void )
{
    return looking.y;
}

SGZSCALER HordeEntity2D::GetLookZ( void )
{
    return looking.z;
}

SGZSCALER HordeEntity2D::GetDepth( void )
{
    return entityDepth;
}

SGZSCALER HordeEntity2D::GetWidth( void )
{
    return entityWidth;
}


SGZSCALER HordeEntity2D::GetHeight( void )
{
    return entityHeight;
}

SGZSCALER HordeEntity2D::GetX( void )
{
    return position.x;
}

SGZSCALER HordeEntity2D::GetY( void )
{
    return position.y;
}

SGZSCALER HordeEntity2D::GetZ( void )
{
    return position.z;
}


