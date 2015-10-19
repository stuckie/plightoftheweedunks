#ifndef _SDLENTITY2D_H_
#define _SDLENTITY2D_H_

#include "../../../common/entities/IEntity.h"
#include "../../../arch.h"
#include "../../../client/renderer/texture/OTexture.h"
#include "../../../common/data/CSLinkedlist.h"
#include "../../../common/debug/CDebug.h"
#include "../../../common/engine/CInterpret.h"
#include "../../../common/data/CTimer.h"

struct AnimGroup
{
    std::string AnimName;
    int AnimNum;
    int CurAnim;
    SLinkedList<OTexture*> TEXList;         //!< List of SFX
	SListIterator<OTexture*> TEXListITR;    //!< Iterator to the SFX List
};

class SDLEntity2D : public IEntity
{
    public:
    SDLEntity2D();
    SDLEntity2D( std::string Name );
    ~SDLEntity2D();

    bool Update ( void );
    /** Update our beloved entity */

    bool Cleanup ( void );
    /** Clean up our entity mess! */

    bool MoveTo ( SGZVECTOR vector );
    /** Move to direct co-ordinates */

    bool LookTo ( SGZVECTOR vector );
    /** Direction to look at ( move towards ) */

    bool MoveDelta  ( SGZVECTOR vector );
    bool MoveDeltaX ( SGZVECTORVAL amount );
    bool MoveDeltaY ( SGZVECTORVAL amount );
    bool MoveDeltaZ ( SGZVECTORVAL amount );
    /** Move a certain amount in a certain axis */

    SGZSCALER GetWidth( void );
    SGZSCALER GetHeight( void );
    SGZSCALER GetDepth( void );
    bool SetWidth ( SGZSCALER value );
    bool SetHeight( SGZSCALER value );
    bool SetDepth ( SGZSCALER value );
    /** Grab the width/height of current frame */

    SGZSCALER GetX ( void );
    SGZSCALER GetY ( void );
    SGZSCALER GetZ ( void );
    /** Return position data */

    SGZSCALER GetLookX ( void );
    SGZSCALER GetLookY ( void );
    SGZSCALER GetLookZ ( void );

    bool Scale ( SGZSCALER value );
    bool ScaleX ( SGZSCALER value );
    bool ScaleY ( SGZSCALER value );
    bool ScaleZ ( SGZSCALER value );
    bool ScaleXYZ ( SGZVECTOR vector );
    /** Scale overall or in a specified axis */

    bool RotateX ( SGZSCALER value );
    bool RotateY ( SGZSCALER value );
    bool RotateZ ( SGZSCALER value );
    bool Rotate  ( SGZVECTOR vector );
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
    bool LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int x, int y, SGZCOLOUR ColourKey );
    /** Load up a Texture into an Animation*/

    bool SetName( std::string Name );
    std::string GetName ( void );
    /** Reset Name, or Return the Name */

    bool Colour(SGZCOLOUR colour);
    std::string CheckVar ( std::string VarName );
    bool NewVar( std::string VarName );
    bool DeleteVar( std::string VarName );
    bool ChangeVar( std::string VarName, std::string Value );

    private:
    std::string entityName;
    /** Our Name */

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

    SGZCOLOUR col;

    SDL_Rect offset, frame;

    SGZSCALER angle, zoomX, zoomY;

    SGZSCALER smooth, entityDepth, entityWidth, entityHeight;

    SDL_Surface *CurrentFrame, *TempFrame;                  //!< Current Frame to Render

    SLinkedList<SGZAnimGroup2D*> AnimList;         //!< List of Animations
	SListIterator<SGZAnimGroup2D*> AnimListITR;    //!< Iterator to the Animation List

    SLinkedList<SGZVarGroup*> VarList;         //!< list of custom variables for this entity
	SListIterator<SGZVarGroup*> VarITR;     //!< interator for the custom variables


};

#endif
