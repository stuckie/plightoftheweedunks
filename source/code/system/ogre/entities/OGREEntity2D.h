#ifndef _OGREENTITY2D_H_
#define _OGREENTITY2D_H_

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
    CTimer AnimTimer;
    int AnimDelay;
    SLinkedList<OTexture*> TEXList;         //!< List of SFX
	SListIterator<OTexture*> TEXListITR;    //!< Iterator to the SFX List
};

class OGREEntity2D : public IEntity
{
    public:
    OGREEntity2D() { };
    OGREEntity2D( std::string Name ) { entityName = Name; };
    ~OGREEntity2D() { Cleanup(); };

    bool Update ( void );
    /** Update our beloved entity */

    bool Cleanup ( void );
    /** Clean up our entity mess! */

    bool MoveTo ( SGZVECTOR vector );
    /** Move to direct co-ordinates */

    bool LookTo ( SGZVECTOR vector );
    /** Direction to look at ( move towards ) */

    bool MoveDeltaX ( SGZSCALER amount );
    bool MoveDeltaY ( SGZSCALER amount );
    bool MoveDeltaZ ( SGZSCALER amount );
    /** Move a certain amount in a certain axis */

    SGZSCALER GetX ( void ) { return position.x; };
    SGZSCALER GetY ( void ) { return position.y; };
    SGZSCALER GetZ ( void ) { return position.z; };
    /** Return position data */

    SGZSCALER GetLookX ( void ) { return looking.x; };
    SGZSCALER GetLookY ( void ) { return looking.y; };
    SGZSCALER GetLookZ ( void ) { return looking.z; };

    bool Scale ( SGZSCALER value );
    bool ScaleX ( SGZSCALER value );
    bool ScaleY ( SGZSCALER value );
    bool ScaleZ ( SGZSCALER value );
    /** Scale overall or in a specified axis */

    bool RotateX ( SGZSCALER value );
    bool RotateY ( SGZSCALER value );
    bool RotateZ ( SGZSCALER value );
    /** Rotate on a specific axis */

    bool MaxAccel ( SGZSCALER value );
    SGZSCALER GetSpeed ( void ) { return entitySpeed; };
    SGZSCALER GetAccel ( void ) { return entityAccel; };
    bool SetAccel ( SGZSCALER value );
    /** Accelerate a certain value "forward" */

    bool Stop ( void );
    /** Stop moving/rotating/scaling immediately */

    bool SetCollisionGeom ( int type );
    /** Set the collision type */

    std::string GetAnimation( void ) { return CurrentAnim; };
    bool SetAnimation( std::string Name );
    bool CreateAnimation( std::string Name );
    bool DeleteAnimation( std::string Name );
    bool LoadTexture ( std::string Name, std::string Filename );
    /** Load up a Texture into an Animation*/

    bool SetName( std::string Name ) { entityName = Name; return true; };
    std::string GetName ( void ) { return entityName; };
    /** Reset Name, or Return the Name */

    private:
    std::string entityName;
    /** Our Name */

    std::string CurrentAnim;
    /** Currently Playing Animation */

    SGZVECTOR position;
    /** Our Position in the world! */

    SGZVECTOR looking;
    /** Where we're looking */

    SGZSCALER entitySpeed, entityAccel, maxEntityAccel;
    /** Our speed and acceleration */

    SGZVECTOR size;
    /** Our size */

    SLinkedList<AnimGroup*> AnimList;         //!< List of Animations
	SListIterator<AnimGroup*> AnimListITR;    //!< Iterator to the Animation List

};

#endif

