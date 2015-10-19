#ifndef _IENTITY_H_
#define _IENTITY_H_

#include <string>
#include "arch.h"
#include "CDebug.h"
#include "CTimer.h"
#include "CSLinkedlist.h"

struct SGZAnimFrame2D
{
    int frameNum,
        delay,
        u,
        v;

    SGZCOLOUR colkey;

    std::string TextureName;
    std::string MaskName;
};

struct SGZAnimGroup2D
{
    std::string AnimName;
    int AnimNum;
    int CurAnim;
    CTimer AnimTimer;
    SLinkedList<SGZAnimFrame2D*> FrameList;
	SListIterator<SGZAnimFrame2D*> FrameITR;
};

struct SGZVarGroup
{
    std::string Name, Variable;
};

class IEntity
{
    public:
    virtual ~IEntity() {}

    virtual bool Update ( void ) = 0;
    /** Update our beloved entity */

    virtual bool Cleanup ( void ) = 0;
    /** Cleanup our mess */

    virtual bool MoveTo ( SGZVECTOR move ) = 0;
    /** Move to direct co-ordinates */

    virtual bool LookTo ( SGZVECTOR look ) = 0;
    /** Move towards co-ordinates */

    virtual bool MoveDelta  ( SGZVECTOR amount ) = 0;
    virtual bool MoveDeltaX ( SGZVECTORVAL amount ) = 0;
    virtual bool MoveDeltaY ( SGZVECTORVAL amount ) = 0;
    virtual bool MoveDeltaZ ( SGZVECTORVAL amount ) = 0;
    /** Move a certain amount in a certain axis */

    virtual SGZSCALER GetX ( void ) = 0;
    virtual SGZSCALER GetY ( void ) = 0;
    virtual SGZSCALER GetZ ( void ) = 0;
    /** Return position data */

    virtual SGZSCALER GetWidth  ( void ) = 0;
    virtual SGZSCALER GetHeight ( void ) = 0;
    virtual SGZSCALER GetDepth  ( void ) = 0;
    virtual bool SetWidth  ( SGZSCALER value ) = 0;
    virtual bool SetHeight ( SGZSCALER value ) = 0;
    virtual bool SetDepth  ( SGZSCALER value ) = 0;
    /** Get some basic width/height info */

    virtual SGZSCALER GetLookX ( void ) = 0;
    virtual SGZSCALER GetLookY ( void ) = 0;
    virtual SGZSCALER GetLookZ ( void ) = 0;
    /** Return what we're looking at on specific axis */

    virtual bool Scale ( SGZSCALER value ) = 0;
    virtual bool ScaleX ( SGZSCALER value ) = 0;
    virtual bool ScaleY ( SGZSCALER value ) = 0;
    virtual bool ScaleZ ( SGZSCALER value ) = 0;
    virtual bool ScaleXYZ( SGZVECTOR value ) = 0;
    /** Scale overall or in a specified axis */

    virtual bool RotateX ( SGZSCALER value ) = 0;
    virtual bool RotateY ( SGZSCALER value ) = 0;
    virtual bool RotateZ ( SGZSCALER value ) = 0;
    virtual bool Rotate  ( SGZVECTOR value ) = 0;
    /** Rotate on a specific axis */

    virtual bool MaxAccel ( SGZSCALER value ) = 0;
    virtual bool MaxSpeed ( SGZSCALER value ) = 0;
    virtual bool SetSpeed ( SGZSCALER value ) = 0;
    virtual SGZSCALER GetSpeed ( void ) = 0;
    virtual SGZSCALER GetAccel ( void ) = 0;
    virtual bool SetAccel ( SGZSCALER value ) = 0;
    /** Accelerate a certain value "forward" */

    virtual bool Stop ( void ) = 0;
    /** Stop moving/rotating/scaling immediately */

    virtual bool SetCollisionGeom ( int type ) = 0;
    /** Set the collision type */

    virtual bool LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey ) = 0;
    /** Load in a Texture */

    virtual bool CreateAnimation( std::string Name ) = 0;
    virtual bool SetAnimation( std::string Name ) = 0;
    virtual bool DeleteAnimation( std::string Name ) = 0;
    virtual std::string GetAnimation( void ) = 0;

    virtual bool SetName( std::string Name ) = 0;
    virtual std::string GetName ( void ) = 0;

    virtual bool Colour ( SGZCOLOUR col ) = 0;

    virtual std::string CheckVar ( std::string VarName ) = 0;
    virtual bool NewVar( std::string VarName ) = 0;
    virtual bool DeleteVar( std::string VarName ) = 0;
    virtual bool ChangeVar( std::string VarName, std::string Value ) = 0;
};

#endif
