#include "OEntity2D.h"

bool OEntity2D::Update ( void )
{
    /** Update our beloved entity */
    return Entity.Update();
}

bool OEntity2D::Cleanup ( void )
{
    /** Clean up our entity mess! */
    return Entity.Cleanup();
}

bool OEntity2D::MoveTo ( SGZVECTOR move )
{
    /** Move to direct co-ordinates */
    return Entity.MoveTo(move);
}

bool OEntity2D::LookTo ( SGZVECTOR look )
{
    /** Direction to look at ( move towards ) */
    return Entity.LookTo(look);
}

bool OEntity2D::MoveDeltaX ( SGZVECTORVAL amount )
{
    /** Move a certain amount in X axis */
    return Entity.MoveDeltaX(amount);
}

bool OEntity2D::MoveDeltaY ( SGZVECTORVAL amount )
{
    /** Move a certain amount in Y axis */
    return Entity.MoveDeltaY(amount);
}

bool OEntity2D::MoveDeltaZ ( SGZVECTORVAL amount )
{
    /** Move a certain amout in Z axis */
    return Entity.MoveDeltaZ(amount);
}

bool OEntity2D::MoveDelta ( SGZVECTOR vector )
{
    return Entity.MoveDelta(vector);
}

bool OEntity2D::Scale ( SGZSCALER value )
{
    /** Scale the entity overall */
    return Entity.Scale(value);
}

bool OEntity2D::ScaleX ( SGZSCALER value )
{
    /** Scale in X-axis */
    return Entity.ScaleX(value);
}

bool OEntity2D::ScaleY ( SGZSCALER value )
{
    /** Scale in Y-Axis */
    return Entity.ScaleY(value);
}

bool OEntity2D::ScaleZ ( SGZSCALER value )
{
    /** Scale in Z axis */
    return Entity.ScaleZ(value);
}

bool OEntity2D::ScaleXYZ( SGZVECTOR vector )
{
    return Entity.ScaleXYZ(vector);
}

bool OEntity2D::RotateX ( SGZSCALER value )
{
    /** Rotate in X Axis */
    return Entity.RotateX(value);
}

bool OEntity2D::RotateY ( SGZSCALER value )
{
    /** Rotate in Y axis */
    return Entity.RotateY(value);
}

bool OEntity2D::RotateZ ( SGZSCALER value )
{
    return Entity.RotateZ(value);
}

bool OEntity2D::Rotate( SGZVECTOR vector)
{
    return Entity.Rotate(vector);
}

bool OEntity2D::MaxAccel ( SGZSCALER value )
{
    return Entity.MaxAccel(value);
}

bool OEntity2D::SetAccel ( SGZSCALER value )
{
    return Entity.SetAccel(value);
}

bool OEntity2D::MaxSpeed ( SGZSCALER value )
{
    return Entity.MaxSpeed(value);
}

bool OEntity2D::SetSpeed ( SGZSCALER value )
{
    return Entity.SetSpeed(value);
}

bool OEntity2D::SetWidth ( SGZSCALER value )
{
    return Entity.SetWidth(value);
}

bool OEntity2D::SetHeight ( SGZSCALER value )
{
    return Entity.SetHeight(value);
}

bool OEntity2D::SetDepth ( SGZSCALER value )
{
    return Entity.SetDepth(value);
}

bool OEntity2D::Stop ( void )
{
    /** Stop moving/rotating/scaling immediately */
    return Entity.Stop();
}

bool OEntity2D::SetCollisionGeom ( int type )
{
    /** Set the collision type */
    return Entity.SetCollisionGeom(type);
}

bool OEntity2D::SetAnimation( std::string Name )
{
    return Entity.SetAnimation(Name);
}

bool OEntity2D::CreateAnimation( std::string Name )
{
    return Entity.CreateAnimation(Name);
}

bool OEntity2D::DeleteAnimation( std::string Name )
{
    return Entity.DeleteAnimation(Name);
}

bool OEntity2D::LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey )
{
    return Entity.LoadFrame(Name,TexName,MaskName,FrameDelay,u,v,ColourKey);
}


bool OEntity2D::Colour ( SGZCOLOUR col )
{
    return Entity.Colour(col);
}

std::string OEntity2D::CheckVar(std::string VarName)
{
    return Entity.CheckVar(VarName);
}

bool OEntity2D::NewVar(std::string VarName)
{
    return Entity.NewVar(VarName);
}

bool OEntity2D::DeleteVar(std::string VarName)
{
    return Entity.DeleteVar(VarName);
}

bool OEntity2D::ChangeVar(std::string VarName, std::string Value)
{
    return Entity.ChangeVar(VarName,Value);
}
