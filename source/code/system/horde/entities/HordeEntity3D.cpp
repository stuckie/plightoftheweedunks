#include "HordeEntity3D.h"

HordeEntity3D::HordeEntity3D()
{
}

HordeEntity3D::~HordeEntity3D()
{
}

bool HordeEntity3D::Update ( void )
{
    /** Update our beloved entity */
    return true;
}

bool HordeEntity3D::Cleanup ( void )
{
    /** Clean up our entity mess! */
    return true;
}

bool HordeEntity3D::MoveTo ( SGZVECTOR move )
{
    /** Move to direct co-ordinates */
    position = move;
    return true;
}

bool HordeEntity3D::LookTo ( SGZVECTOR look )
{
    /** Direction to look at ( move towards ) */
    looking = look;
    return true;
}

bool HordeEntity3D::MoveDeltaX ( SGZVECTORVAL amount )
{
    /** Move a certain amount in X axis */
    position.x += amount;
    return true;
}

bool HordeEntity3D::MoveDeltaY ( SGZVECTORVAL amount )
{
    /** Move a certain amount in Y axis */
    position.y += amount;
    return true;
}

bool HordeEntity3D::MoveDeltaZ ( SGZVECTORVAL amount )
{
    /** Move a certain amout in Z axis */
    position.z += amount;
    return true;
}

bool HordeEntity3D::MoveDelta ( SGZVECTOR vector )
{
    position.x += vector.x;
    position.y += vector.y;
    position.z += vector.z;

    return true;
}

bool HordeEntity3D::Scale ( SGZSCALER value )
{
    /** Scale the entity overall */
    scale.x = value;
    scale.y = value;
    scale.z = value;

    return true;
}

bool HordeEntity3D::ScaleX ( SGZSCALER value )
{
    /** Scale in X-axis */
    scale.x = value;

    return true;
}

bool HordeEntity3D::ScaleY ( SGZSCALER value )
{
    /** Scale in Y-Axis */
    scale.y = value;

    return true;
}

bool HordeEntity3D::ScaleZ ( SGZSCALER value )
{
    /** Scale in Z axis */
    scale.z = value;

    return true;
}

bool HordeEntity3D::ScaleXYZ( SGZVECTOR vector )
{
    scale = vector;

    return true;
}

bool HordeEntity3D::RotateX ( SGZSCALER value )
{
    /** Rotate in X Axis */
    rotation.x += value;

    return true;
}

bool HordeEntity3D::RotateY ( SGZSCALER value )
{
    /** Rotate in Y axis */
    rotation.y += value;

    return true;
}

bool HordeEntity3D::RotateZ ( SGZSCALER value )
{
    rotation.z += value;

    return true;
}

bool HordeEntity3D::Rotate( SGZVECTOR vector)
{
    rotation = vector;

    return true;
}

bool HordeEntity3D::MaxAccel ( SGZSCALER value )
{
    entityMaxAccel = value;

    return true;
}

bool HordeEntity3D::SetAccel ( SGZSCALER value )
{
    entityAccel = value;

    return true;
}

bool HordeEntity3D::MaxSpeed ( SGZSCALER value )
{
    entityMaxSpeed = value;

    return true;
}

bool HordeEntity3D::SetSpeed ( SGZSCALER value )
{
    entitySpeed = value;

    return true;
}

bool HordeEntity3D::SetWidth ( SGZSCALER value )
{
    entityWidth = value;

    return true;
}

bool HordeEntity3D::SetHeight ( SGZSCALER value )
{
    entityHeight = value;

    return true;
}

bool HordeEntity3D::SetDepth ( SGZSCALER value )
{
    entityDepth = value;

    return true;
}

bool HordeEntity3D::Stop ( void )
{
    /** Stop moving/rotating/scaling immediately */
    entitySpeed = 0;

    return true;
}

bool HordeEntity3D::SetCollisionGeom ( int type )
{
    /** Set the collision type */
    entityType = type;

    return true;
}

bool HordeEntity3D::SetAnimation( std::string Name )
{
    animName = Name;

    return true;
}

bool HordeEntity3D::CreateAnimation( std::string Name )
{
    SGZLogger.warn("CreateAnim in 3D Entity not created.. anim name would've been %s\n", Name.c_str());

    return true;
}

bool HordeEntity3D::DeleteAnimation( std::string Name )
{
    SGZLogger.warn("DelAnim in 3D Entity not created.. anim name would've been %s\n", Name.c_str());
    return true;
}

bool HordeEntity3D::LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey )
{
    SGZLogger.warn("LoadFrame in 3D Entity not created..\n%s %s %s %d %d %d %f %f %f", Name.c_str(), TexName.c_str(), MaskName.c_str(), FrameDelay, u, v, ColourKey.r, ColourKey.g, ColourKey.b);
    return true;
}


bool HordeEntity3D::Colour ( SGZCOLOUR col )
{
    colkey = col;
    return true;
}

std::string HordeEntity3D::CheckVar(std::string VarName)
{
    SGZLogger.warn("CheckVar in 3D Entity not created.. val would've been %s\n", VarName.c_str());
    return "none";
}

bool HordeEntity3D::NewVar(std::string VarName)
{
    SGZLogger.warn("NewVar in 3D Entity not created.. val would've been %s\n", VarName.c_str());
    return true;
}

bool HordeEntity3D::DeleteVar(std::string VarName)
{
    SGZLogger.warn("DeleteVar in 3D Entity not created.. val would've been %s\n", VarName.c_str());
    return true;
}

bool HordeEntity3D::ChangeVar(std::string VarName, std::string Value)
{
    SGZLogger.warn("ChangeVar in 3D Entity not created.. val would've been %s as %s\n", VarName.c_str(), Value.c_str());
    return true;
}

std::string HordeEntity3D::GetName( void )
{
    return entityName;
}

bool HordeEntity3D::SetName(std::string Name)
{
    entityName = Name;
    return true;
}

std::string HordeEntity3D::GetAnimation( void )
{
    return animName;
}

SGZSCALER HordeEntity3D::GetAccel( void )
{
    return entityAccel;
}

SGZSCALER HordeEntity3D::GetSpeed( void )
{
    return entitySpeed;
}

SGZSCALER HordeEntity3D::GetLookX( void )
{
    return looking.x;
}

SGZSCALER HordeEntity3D::GetLookY( void )
{
    return looking.y;
}

SGZSCALER HordeEntity3D::GetLookZ( void )
{
    return looking.z;
}

SGZSCALER HordeEntity3D::GetDepth( void )
{
    return entityDepth;
}

SGZSCALER HordeEntity3D::GetWidth( void )
{
    return entityWidth;
}


SGZSCALER HordeEntity3D::GetHeight( void )
{
    return entityHeight;
}

SGZSCALER HordeEntity3D::GetX( void )
{
    return position.x;
}

SGZSCALER HordeEntity3D::GetY( void )
{
    return position.y;
}

SGZSCALER HordeEntity3D::GetZ( void )
{
    return position.z;
}


