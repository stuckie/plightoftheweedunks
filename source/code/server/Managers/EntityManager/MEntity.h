/**
Entity Manager
*/

#ifndef _MENTITY_H_
#define _MENTITY_H_

#include "arch.h"
#include "CDebug.h"
#include "IEntity.h"
#include "CSLinkedlist.h"

class MEntity
{
    public:
    MEntity();
    ~MEntity();

    bool UpdateEntities ( void );
    bool AddEntity( IEntity *Entity );
    bool DelEntity( std::string Name );

    bool MoveTo ( std::string Name, SGZVECTOR moveto );
    /** Move to direct co-ordinates */

    bool LookTo ( std::string Name, SGZVECTOR lookto );
    /** Direction to look at ( move towards ) */

    bool MoveDelta  ( std::string Name, SGZVECTOR delta );
    bool MoveDeltaX ( std::string Name, SGZVECTORVAL amount );
    bool MoveDeltaY ( std::string Name, SGZVECTORVAL amount );
    bool MoveDeltaZ ( std::string Name, SGZVECTORVAL amount );
    /** Move a certain amount in a certain axis */

    SGZSCALER GetX ( std::string Name );
    SGZSCALER GetY ( std::string Name );
    SGZSCALER GetZ ( std::string Name );
    /** Return position data */

    SGZSCALER GetWidth ( std::string Name );
    SGZSCALER GetHeight ( std::string Name );
    SGZSCALER GetDepth ( std::string Name );

    SGZSCALER GetLookX ( std::string Name );
    SGZSCALER GetLookY ( std::string Name );
    SGZSCALER GetLookZ ( std::string Name );

    bool Scale      ( std::string Name, SGZSCALER value );
    bool ScaleXYZ   ( std::string Name, SGZVECTOR value );
    bool ScaleX     ( std::string Name, SGZSCALER value );
    bool ScaleY     ( std::string Name, SGZSCALER value );
    bool ScaleZ     ( std::string Name, SGZSCALER value );
    /** Scale overall or in a specified axis */

    bool Rotate  ( std::string Name, SGZVECTOR value );
    bool RotateX ( std::string Name, SGZSCALER value );
    bool RotateY ( std::string Name, SGZSCALER value );
    bool RotateZ ( std::string Name, SGZSCALER value );
    /** Rotate on a specific axis */

    bool MaxAccel ( std::string Name, SGZSCALER value );
    bool MaxSpeed ( std::string Name, SGZSCALER value );
    bool SetSpeed ( std::string Name, SGZSCALER value );
    SGZSCALER GetSpeed ( std::string Name );
    SGZSCALER GetAccel ( std::string Name );
    bool SetAccel ( std::string Name, SGZSCALER value );
    /** Accelerate a certain value "forward" */

    bool Stop ( std::string Name );
    /** Stop moving/rotating/scaling immediately */

    bool SetCollisionGeom ( std::string Name, int type );
    /** Set the collision type */

    std::string GetAnimation( std::string Name );
    bool SetAnimation( std::string Name, std::string AnimName );
    bool CreateAnimation( std::string Name, std::string AnimName );
    bool DeleteAnimation( std::string Name, std::string AnimName );
    bool LoadFrame ( std::string Name, std::string AnimName, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey );
    /** Load up a Texture into an Animation*/

    std::string CheckVar ( std::string Name, std::string VarName );
    bool NewVar( std::string Name, std::string VarName );
    bool DeleteVar( std::string Name, std::string VarName );
    bool ChangeVar( std::string Name, std::string VarName, std::string Value );
    bool CheckExist( std::string Name );

    bool Colour ( std::string Name, SGZCOLOUR colour );

    int EntityCount(void);
    void SetMaxEntities(int value);
    int CurrentMax(void);

    bool SetWidth( std::string Name, SGZSCALER value );
    bool SetHeight( std::string Name, SGZSCALER value );
    bool SetDepth( std::string Name, SGZSCALER value );

    private:
    int MaxEntities;
    SLinkedList<IEntity*> EntityList;
    SListIterator<IEntity*> EntityListITR;

};

#endif
