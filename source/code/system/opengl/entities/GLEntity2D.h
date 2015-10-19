#ifndef _GLENTITY2D_H_
#define _GLENTITY2D_H_

#include "../../../arch.h"
#include "../../../common/entities/IEntity.h"
#include "../../../client/renderer/texture/OTexture.h"
#include "../../../common/data/CSLinkedlist.h"
#include "../../../common/debug/CDebug.h"
#include "../../../common/engine/CInterpret.h"
#include "../../../common/data/CTimer.h"

#include "GL/gl.h"

struct AnimGroup
{
    std::string AnimName;
    int AnimNum;
    int CurAnim;
    SLinkedList<OTexture*> TEXList;         //!< List of SFX
	SListIterator<OTexture*> TEXListITR;    //!< Iterator to the SFX List
};

class GLEntity2D : public IEntity
{
    public:
    GLEntity2D();
    GLEntity2D( std::string Name );
    ~GLEntity2D() {};

    bool Update ( void );
    /** Update our beloved entity */

    bool Cleanup ( void );
    /** Clean up our entity mess! */

    bool MoveTo ( SGZVECTOR move );
    /** Move to direct co-ordinates */

    bool LookTo ( SGZVECTOR look );
    /** Direction to look at ( move towards ) */

    bool MoveDelta  ( SGZVECTOR amount );
    bool MoveDeltaX ( SGZSCALER amount );
    bool MoveDeltaY ( SGZSCALER amount );
    bool MoveDeltaZ ( SGZSCALER amount );
    /** Move a certain amount in a certain axis */

    SGZSCALER GetX ( void );
    SGZSCALER GetY ( void );
    SGZSCALER GetZ ( void );
    /** Return position data */

    SGZSCALER GetWidth  ( void );
    SGZSCALER GetHeight ( void );
    SGZSCALER GetDepth  ( void );

    bool SetWidth(SGZSCALER value);
    bool SetHeight(SGZSCALER value);
    bool SetDepth(SGZSCALER value);

    SGZSCALER GetLookX ( void );
    SGZSCALER GetLookY ( void );
    SGZSCALER GetLookZ ( void );

    bool Scale ( SGZSCALER value );
    bool ScaleX ( SGZSCALER value );
    bool ScaleY ( SGZSCALER value );
    bool ScaleZ ( SGZSCALER value );
    bool ScaleXYZ ( SGZVECTOR value );
    /** Scale overall or in a specified axis */

    bool Rotate  ( SGZVECTOR value );
    bool RotateX ( SGZSCALER value );
    bool RotateY ( SGZSCALER value );
    bool RotateZ ( SGZSCALER value );
    /** Rotate on a specific axis */

    bool MaxAccel ( SGZSCALER value );
    bool MaxSpeed ( SGZSCALER value );
    bool SetSpeed ( SGZSCALER value );
    SGZSCALER GetSpeed ( void );
    SGZSCALER GetAccel ( void );
    bool SetAccel ( SGZSCALER value );
    /** Accelerate a certain value "forward" */

    bool Stop ( void );
    /** Stop moving/rotating/scaling immediately */

    bool SetCollisionGeom ( int type );
    /** Set the collision type */

    std::string GetAnimation( void );
    bool SetAnimation( std::string Name );
    bool CreateAnimation( std::string Name );
    bool DeleteAnimation( std::string Name );
    bool LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey );

    bool SetName( std::string Name );
    std::string GetName ( void );
    /** Reset Name, or Return the Name */

    bool Colour ( SGZCOLOUR col );

    std::string CheckVar ( std::string VarName );
    bool NewVar( std::string VarName );
    bool DeleteVar( std::string VarName );
    bool ChangeVar( std::string VarName, std::string Value );

    private:

    std::string entityName;
    /** Entity's Name */

    std::string CurrentAnim;
    /** Currently Playing Animation */

    SGZVECTOR position;
    /** Our Position in the world! */

    SGZVECTOR looking;
    /** Where we're looking */

    SGZSCALER entitySpeed, entityAccel, maxEntityAccel, maxEntitySpeed;
    /** Our speed and acceleration */

    SGZVECTOR size;
    /** Our size */

    SGZVECTOR rotation;

    SGZCOLOUR col;

    SGZSCALER entityWidth, entityHeight, entityDepth;

    SLinkedList<SGZAnimGroup2D*> AnimList;         //!< List of Animations
	SListIterator<SGZAnimGroup2D*> AnimListITR;    //!< Iterator to the Animation List

	SLinkedList<SGZVarGroup*> VarList;         //!< list of custom variables for this entity
	SListIterator<SGZVarGroup*> VarITR;     //!< interator for the custom variables

};

#endif
