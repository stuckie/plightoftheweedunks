#ifndef _3DENTITY_H_
#define _3DENTITY_H_

#ifdef SGZ3D

#include "IEntity.h"
#include "arch.h"

#if defined(REND_OGRE) || defined(REND_SDLOGRE)
    #include "OGREEntity3D.h"
#endif

#if defined(REND_OPENGL) || defined(REND_SDLGL)
    #include "GLEntity3D.h"
#endif

#if defined(REND_HORDE) || defined(REND_SDLHORDE)
    #include "HordeEntity3D.h"
#endif

class OEntity3D : public IEntity
{
    public:
    OEntity3D() { };
    OEntity3D( std::string Name ) { Entity.SetName(Name); };
    ~OEntity3D() { Cleanup(); };

    bool Update ( void );
    /** Update our beloved entity */

    bool Cleanup ( void );
    /** Clean up our entity mess! */

    bool MoveTo ( SGZVECTOR move );
    /** Move to direct co-ordinates */

    bool LookTo ( SGZVECTOR look );
    /** Direction to look at ( move towards ) */

    bool MoveDelta  ( SGZVECTOR amount );
    bool MoveDeltaX ( SGZVECTORVAL amount );
    bool MoveDeltaY ( SGZVECTORVAL amount );
    bool MoveDeltaZ ( SGZVECTORVAL amount );
    /** Move a certain amount in a certain axis */

    SGZSCALER GetX ( void ) { return Entity.GetX(); };
    SGZSCALER GetY ( void ) { return Entity.GetY(); };
    SGZSCALER GetZ ( void ) { return Entity.GetZ(); };
    /** Return position data */

    SGZSCALER GetWidth  ( void ) { return Entity.GetWidth(); };
    SGZSCALER GetHeight ( void ) { return Entity.GetHeight(); };
    SGZSCALER GetDepth  ( void ) { return Entity.GetDepth(); };

    bool SetWidth ( SGZSCALER value );
    bool SetHeight ( SGZSCALER value );
    bool SetDepth ( SGZSCALER value );

    SGZSCALER GetLookX ( void ) { return Entity.GetLookX(); };
    SGZSCALER GetLookY ( void ) { return Entity.GetLookY(); };
    SGZSCALER GetLookZ ( void ) { return Entity.GetLookZ(); };

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
    SGZSCALER GetSpeed ( void ) { return Entity.GetSpeed(); };
    SGZSCALER GetAccel ( void ) { return Entity.GetAccel(); };
    bool SetAccel ( SGZSCALER value );
    /** Accelerate a certain value "forward" */

    bool Stop ( void );
    /** Stop moving/rotating/scaling immediately */

    bool SetCollisionGeom ( int type );
    /** Set the collision type */

    std::string GetAnimation( void ) { return Entity.GetAnimation(); };
    bool SetAnimation( std::string Name );
    bool CreateAnimation( std::string Name );
    bool DeleteAnimation( std::string Name );
    bool LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey );
    /** Load up a Texture into an Animation*/

    bool SetName( std::string Name ) { return Entity.SetName(Name); };
    std::string GetName ( void ) { return Entity.GetName(); };
    /** Reset Name, or Return the Name */

    bool Colour ( SGZCOLOUR col );

    std::string CheckVar ( std::string VarName );
    bool NewVar( std::string VarName );
    bool DeleteVar( std::string VarName );
    bool ChangeVar( std::string VarName, std::string Value );


    private:
    #if defined(REND_OGRE) || defined(REND_SDLOGRE)
        OGREEntity3D Entity;
    #endif

    #if defined(REND_OPENGL) || defined(REND_SDLGL)
        GLEntity3D Entity;
    #endif

    #if defined(REND_HORDE) || defined (REND_SDLHORDE)
        HordeEntity3D Entity;
    #endif

};

#endif

#endif
