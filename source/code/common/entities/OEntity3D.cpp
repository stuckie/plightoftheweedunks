#include "OEntity3D.h"

bool OEntity3D::Update ( void )
{
    /** Update our beloved entity */
    return Entity.Update();
}

bool OEntity3D::Cleanup ( void )
{
    /** Clean up our entity mess! */
    return Entity.Cleanup();
}

bool OEntity3D::MoveTo ( SGZVECTOR move )
{
    /** Move to direct co-ordinates */
    return Entity.MoveTo(move);
}

bool OEntity3D::LookTo ( SGZVECTOR look )
{
    /** Direction to look at ( move towards ) */
    return Entity.LookTo(look);
}

bool OEntity3D::MoveDeltaX ( SGZVECTORVAL amount )
{
    /** Move a certain amount in X axis */
    return Entity.MoveDeltaX(amount);
}

bool OEntity3D::MoveDeltaY ( SGZVECTORVAL amount )
{
    /** Move a certain amount in Y axis */
    return Entity.MoveDeltaY(amount);
}

bool OEntity3D::MoveDeltaZ ( SGZVECTORVAL amount )
{
    /** Move a certain amout in Z axis */
    return Entity.MoveDeltaZ(amount);
}

bool OEntity3D::MoveDelta ( SGZVECTOR vector )
{
    return Entity.MoveDelta(vector);
}

bool OEntity3D::Scale ( SGZSCALER value )
{
    /** Scale the entity overall */
    return Entity.Scale(value);
}

bool OEntity3D::ScaleX ( SGZSCALER value )
{
    /** Scale in X-axis */
    return Entity.ScaleX(value);
}

bool OEntity3D::ScaleY ( SGZSCALER value )
{
    /** Scale in Y-Axis */
    return Entity.ScaleY(value);
}

bool OEntity3D::ScaleZ ( SGZSCALER value )
{
    /** Scale in Z axis */
    return Entity.ScaleZ(value);
}

bool OEntity3D::ScaleXYZ( SGZVECTOR vector )
{
    return Entity.ScaleXYZ(vector);
}

bool OEntity3D::RotateX ( SGZSCALER value )
{
    /** Rotate in X Axis */
    return Entity.RotateX(value);
}

bool OEntity3D::RotateY ( SGZSCALER value )
{
    /** Rotate in Y axis */
    return Entity.RotateY(value);
}

bool OEntity3D::RotateZ ( SGZSCALER value )
{
    return Entity.RotateZ(value);
}

bool OEntity3D::Rotate( SGZVECTOR vector)
{
    return Entity.Rotate(vector);
}

bool OEntity3D::MaxAccel ( SGZSCALER value )
{
    return Entity.MaxAccel(value);
}

bool OEntity3D::SetAccel ( SGZSCALER value )
{
    return Entity.SetAccel(value);
}

bool OEntity3D::MaxSpeed ( SGZSCALER value )
{
    return Entity.MaxSpeed(value);
}

bool OEntity3D::SetSpeed ( SGZSCALER value )
{
    return Entity.SetSpeed(value);
}

bool OEntity3D::SetWidth ( SGZSCALER value )
{
    return Entity.SetWidth(value);
}

bool OEntity3D::SetHeight ( SGZSCALER value )
{
    return Entity.SetHeight(value);
}

bool OEntity3D::SetDepth ( SGZSCALER value )
{
    return Entity.SetDepth(value);
}

bool OEntity3D::Stop ( void )
{
    /** Stop moving/rotating/scaling immediately */
    return Entity.Stop();
}

bool OEntity3D::SetCollisionGeom ( int type )
{
    /** Set the collision type */
    return Entity.SetCollisionGeom(type);
}

bool OEntity3D::SetAnimation( std::string Name )
{
    return Entity.SetAnimation(Name);
}

bool OEntity3D::CreateAnimation( std::string Name )
{
    return Entity.CreateAnimation(Name);
}

bool OEntity3D::DeleteAnimation( std::string Name )
{
    return Entity.DeleteAnimation(Name);
}

bool OEntity3D::LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey )
{
    return Entity.LoadFrame(Name,TexName,MaskName,FrameDelay,u,v,ColourKey);
}


bool OEntity3D::Colour ( SGZCOLOUR col )
{
    return Entity.Colour(col);
}

std::string OEntity3D::CheckVar(std::string VarName)
{
    return Entity.CheckVar(VarName);
}

bool OEntity3D::NewVar(std::string VarName)
{
    return Entity.NewVar(VarName);
}

bool OEntity3D::DeleteVar(std::string VarName)
{
    return Entity.DeleteVar(VarName);
}

bool OEntity3D::ChangeVar(std::string VarName, std::string Value)
{
    return Entity.ChangeVar(VarName,Value);
}
