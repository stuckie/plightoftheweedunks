#include "SDLEntity2D.h"
#include "../../../dependencies/SDL/SDL_gfxBlitFunc.h"
#include "../../../dependencies/SDL/SDL_rotozoom.h"
#include "../../../dependencies/SDL/SDL_gfxPrimitives.h"
#include "../../../common/engine/CInterpret.h"

SDLEntity2D::SDLEntity2D(std::string Name)
{
    entityName = Name;
    entityAccel = entitySpeed = 0.0;
    entityDepth = 0;
    entityWidth = 32; entityHeight = 32;
    angle = 0; zoomX=1; zoomY=1;
}

SDLEntity2D::SDLEntity2D()
{
}

SDLEntity2D::~SDLEntity2D()
{
    Cleanup();
}

bool SDLEntity2D::Update ( void )
{
    /// Update our beloved entity
    SListIterator<SGZAnimGroup2D*> AnimListITR = AnimList.GetIterator();

    for( AnimListITR.Start(); AnimListITR.Valid(); AnimListITR.Forth() )
        if((AnimListITR.Item()->AnimName.compare(CurrentAnim))==0)
        {
            if(AnimListITR.Item()->FrameITR.Valid())
            {
                frame.x = (Uint16)AnimListITR.Item()->FrameITR.Item()->u;
                frame.y = (Uint16)AnimListITR.Item()->FrameITR.Item()->v;
                frame.w = (Uint16)entityWidth;
                frame.h = (Uint16)entityHeight;
                offset.x = 0;
                offset.y = 0;
                offset.w = (Uint16)entityWidth;
                offset.h = (Uint16)entityHeight;

                CurrentFrame = static_cast<SDL_Surface*>(SGZInterpret.accessServer()->World()->accessTextureManager()->GetTexture(AnimListITR.Item()->FrameITR.Item()->TextureName));

                //                SDL_BlitSurface(temp, &frame, TempFrame, &offset );


                //CurrentFrame = rotozoomSurfaceXY (TempFrame, angle, zoomX, zoomY, 0);


                SDL_SetColorKey(CurrentFrame, SDL_SRCCOLORKEY, SDL_MapRGB(CurrentFrame->format,
                                                                            (Uint32)AnimListITR.Item()->FrameITR.Item()->colkey.r,
                                                                            (Uint32)AnimListITR.Item()->FrameITR.Item()->colkey.g,
                                                                            (Uint32)AnimListITR.Item()->FrameITR.Item()->colkey.b));

                offset.w = (Uint16)entityWidth;
                offset.h = (Uint16)entityHeight;
                offset.x = (Sint16)position.x;
                offset.y = (Sint16)position.y;
                SDL_BlitSurface(CurrentFrame, &frame, SDL_GetVideoSurface(), &offset );
                //SDL_FreeSurface(CurrentFrame);
                //SDL_FreeSurface(TempFrame);
            }
            if(AnimListITR.Item()->AnimTimer.currenttime() >= AnimListITR.Item()->FrameITR.Item()->delay)
            {
                AnimListITR.Item()->FrameITR.Forth();
                AnimListITR.Item()->CurAnim++;
                AnimListITR.Item()->AnimTimer.reset();
            }

            if (AnimListITR.Item()->FrameList.Size() == AnimListITR.Item()->CurAnim)
            {
                AnimListITR.Item()->CurAnim = 0;
                AnimListITR.Item()->FrameITR.Start();
            }
        }

    return true;
}

SGZSCALER SDLEntity2D::GetWidth ( void )
{
    return entityWidth;
}

SGZSCALER SDLEntity2D::GetHeight( void )
{
    return entityHeight;
}

SGZSCALER SDLEntity2D::GetDepth( void )
{
    return entityDepth;
}

bool SDLEntity2D::SetWidth( SGZSCALER width )
{
    entityWidth = width;
    return true;
}

bool SDLEntity2D::SetHeight( SGZSCALER height )
{
    entityHeight = height;
    return true;
}

bool SDLEntity2D::SetDepth( SGZSCALER depth )
{
    entityDepth = depth;
    return true;
}

bool SDLEntity2D::Cleanup ( void )
{
    /** Clean up our entity mess! */
    return true;
}

bool SDLEntity2D::MoveTo ( SGZVECTOR vector )
{
    /** Move to direct co-ordinates */
    position = vector;
    return true;
}

bool SDLEntity2D::LookTo ( SGZVECTOR vector )
{
    /** Direction to look at ( move towards ) */
    looking = vector;
    return true;
}

bool SDLEntity2D::MoveDelta ( SGZVECTOR amount )
{
    position.x += amount.x;
    position.y += amount.y;
    position.z += amount.z;
    return true;
}

bool SDLEntity2D::MoveDeltaX ( SGZVECTORVAL amount )
{
    position.x += amount;
    return true;
}

bool SDLEntity2D::MoveDeltaY ( SGZVECTORVAL amount )
{
    position.y += amount;
    return true;
}

bool SDLEntity2D::MoveDeltaZ ( SGZVECTORVAL amount )
{
    position.z += amount;
    return true;
}

bool SDLEntity2D::Scale ( SGZSCALER value )
{
    zoomX=value;
    zoomY=value;

    return true;
}

bool SDLEntity2D::ScaleX ( SGZSCALER value )
{
    zoomX = value;
    return true;
}

bool SDLEntity2D::ScaleY ( SGZSCALER value )
{
    zoomY = value;
    return true;
}

bool SDLEntity2D::ScaleZ ( SGZSCALER value )
{
    return true;
}

bool SDLEntity2D::RotateX ( SGZSCALER value )
{
    angle=value;
    return true;
}

bool SDLEntity2D::ScaleXYZ ( SGZVECTOR value )
{
    return true;
}

bool SDLEntity2D::Rotate ( SGZVECTOR value )
{
    return true;
}

bool SDLEntity2D::RotateY ( SGZSCALER value )
{
    angle=value;
    return true;
}

bool SDLEntity2D::RotateZ ( SGZSCALER value )
{
    angle=value;
    return true;
}

bool SDLEntity2D::MaxAccel ( SGZSCALER value )
{
    maxEntityAccel = value;
    return true;
}

bool SDLEntity2D::SetAccel ( SGZSCALER value )
{
    entityAccel = value;
    return true;
}

bool SDLEntity2D::Stop ( void )
{
    /** Stop moving/rotating/scaling immediately */
    entitySpeed = 0;
    entityAccel = 0;

    return true;
}

bool SDLEntity2D::SetCollisionGeom ( int type )
{
    /** Set the collision type */

    return true;
}

bool SDLEntity2D::SetAnimation( std::string Name )
{
    CurrentAnim = Name;

    return true;
}

bool SDLEntity2D::CreateAnimation( std::string Name )
{
    SGZAnimGroup2D *Animation = new SGZAnimGroup2D;
    Animation->AnimTimer.start();
    Animation->AnimName = Name;
    Animation->AnimNum = 0;
    Animation->CurAnim = 0;
    AnimList.Append(Animation);

    return true;
}

bool SDLEntity2D::DeleteAnimation( std::string Name )
{
    SListIterator<SGZAnimGroup2D*> AnimListITR = AnimList.GetIterator();

    for( AnimListITR.Start(); AnimListITR.Valid(); AnimListITR.Forth() )
        if((AnimListITR.Item()->AnimName.compare(Name))==0)
        {
            AnimListITR.Item()->FrameITR.Start();
            while (AnimListITR.Item()->FrameITR.Valid())
            {
                AnimListITR.Item()->FrameList.Remove(AnimListITR.Item()->FrameITR);
                AnimListITR.Item()->FrameITR.Forth();
            }

            AnimList.Remove(AnimListITR);
            return true;
        }

    SGZLogger.warn("Animation \"%s\" does not exist!\n",Name.c_str());
    return false;
}

bool SDLEntity2D::LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int x, int y, SGZCOLOUR ColourKey )
{
    /// Load up a Texture into an Animation
    SListIterator<SGZAnimGroup2D*> AnimListITR = AnimList.GetIterator();

    for( AnimListITR.Start(); AnimListITR.Valid(); AnimListITR.Forth() )
        if((AnimListITR.Item()->AnimName.compare(Name))==0)
        {
            SGZAnimFrame2D *Frame = new SGZAnimFrame2D;
            Frame->TextureName = TexName;
            Frame->MaskName = "none";
            Frame->delay = FrameDelay;
            Frame->u = x;
            Frame->v = y;
            Frame->colkey = ColourKey;
            AnimListITR.Item()->FrameList.Append(Frame);
            AnimListITR.Item()->AnimNum++;
            AnimListITR.Item()->FrameITR = AnimListITR.Item()->FrameList.GetIterator();

            if(!SGZInterpret.accessServer()->World()->accessTextureManager()->CheckExist(TexName))
                SGZLogger.warn("Texture %s has not been loaded yet.. make sure it is before calling this frame!", TexName.c_str());
            return true;
        }

    SGZLogger.warn("Animation \"%s\" does not exist!\n",Name.c_str());
    return false;
}

bool SDLEntity2D::SetName( std::string Name )
{
    entityName = Name;
    return true;
}

SGZSCALER SDLEntity2D::GetX(void)
{
    return position.x;
}

SGZSCALER SDLEntity2D::GetY(void)
{
    return position.y;
}

SGZSCALER SDLEntity2D::GetZ(void)
{
    return position.z;
}

SGZSCALER SDLEntity2D::GetLookX(void)
{
    return looking.x;
}

SGZSCALER SDLEntity2D::GetLookY(void)
{
    return looking.y;
}

SGZSCALER SDLEntity2D::GetLookZ(void)
{
    return looking.z;
}

SGZSCALER SDLEntity2D::GetAccel(void)
{
    return entityAccel;
}

SGZSCALER SDLEntity2D::GetSpeed(void)
{
    return entitySpeed;
}

std::string SDLEntity2D::GetAnimation(void)
{
    return CurrentAnim;
}

std::string SDLEntity2D::GetName(void)
{
    return entityName;
}

bool SDLEntity2D::Colour ( SGZCOLOUR input )
{
    col = input;
    return true;
}

bool SDLEntity2D::SetSpeed ( SGZSCALER value )
{
    entitySpeed = value;
    return true;
}

bool SDLEntity2D::MaxSpeed ( SGZSCALER value )
{
    maxEntitySpeed = value;
    return true;
}

bool SDLEntity2D::NewVar( std::string Name )
{
    SGZVarGroup *Variable = new SGZVarGroup;
    Variable->Name = Name;
    Variable->Variable = "none";
    VarList.Append(Variable);

    return true;
}

bool SDLEntity2D::DeleteVar( std::string Name )
{
    SListIterator<SGZVarGroup*> VarITR = VarList.GetIterator();

    for( VarITR.Start(); VarITR.Valid(); VarITR.Forth() )
        if((VarITR.Item()->Name.compare(Name))==0)
        {
            VarList.Remove(VarITR);
            return true;
        }

    SGZLogger.warn("Variable \"%s\" does not exist!\n",Name.c_str());
    return false;
}

bool SDLEntity2D::ChangeVar ( std::string Name, std::string Value )
{
    /** Load up a Texture into an Animation*/
    SListIterator<SGZVarGroup*> VarITR = VarList.GetIterator();

    for( VarITR.Start(); VarITR.Valid(); VarITR.Forth() )
        if((VarITR.Item()->Name.compare(Name))==0)
        {
            VarITR.Item()->Variable = Value;
            return true;
        }

    SGZLogger.warn("Variable \"%s\" does not exist!\n",Name.c_str());
    return false;
}

std::string SDLEntity2D::CheckVar( std::string Name )
{
    SListIterator<SGZVarGroup*> VarITR = VarList.GetIterator();

    for( VarITR.Start(); VarITR.Valid(); VarITR.Forth() )
        if((VarITR.Item()->Name.compare(Name))==0)
            return VarITR.Item()->Variable;

    return "none";
}

