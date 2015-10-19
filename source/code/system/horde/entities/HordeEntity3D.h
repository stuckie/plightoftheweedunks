#include "IEntity.h"
#include <Horde3D.h>

class HordeEntity3D : public IEntity
{
    public:
    HordeEntity3D();
    ~HordeEntity3D();

    bool Update ( void );
    /** Update our beloved entity */

    bool Cleanup ( void );
    /** Cleanup our mess */

    bool MoveTo ( SGZVECTOR move );
    /** Move to direct co-ordinates */

    bool LookTo ( SGZVECTOR look );
    /** Move towards co-ordinates */

    bool MoveDelta  ( SGZVECTOR amount );
    bool MoveDeltaX ( SGZVECTORVAL amount );
    bool MoveDeltaY ( SGZVECTORVAL amount );
    bool MoveDeltaZ ( SGZVECTORVAL amount );
    /** Move a certain amount in a certain axis */

    SGZSCALER GetX ( void );
    SGZSCALER GetY ( void );
    SGZSCALER GetZ ( void );
    /** Return position data */

    SGZSCALER GetWidth  ( void );
    SGZSCALER GetHeight ( void );
    SGZSCALER GetDepth  ( void );
    bool SetWidth  ( SGZSCALER value );
    bool SetHeight ( SGZSCALER value );
    bool SetDepth  ( SGZSCALER value );
    /** Get some basic width/height info */

    SGZSCALER GetLookX ( void );
    SGZSCALER GetLookY ( void );
    SGZSCALER GetLookZ ( void );
    /** Return what we're looking at on specific axis */

    bool Scale ( SGZSCALER value );
    bool ScaleX ( SGZSCALER value );
    bool ScaleY ( SGZSCALER value );
    bool ScaleZ ( SGZSCALER value );
    bool ScaleXYZ( SGZVECTOR value );
    /** Scale overall or in a specified axis */

    bool RotateX ( SGZSCALER value );
    bool RotateY ( SGZSCALER value );
    bool RotateZ ( SGZSCALER value );
    bool Rotate  ( SGZVECTOR value );
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

    bool LoadFrame ( std::string Name, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey );
    /** Load in a Texture */

    bool CreateAnimation( std::string Name );
    bool SetAnimation( std::string Name );
    bool DeleteAnimation( std::string Name );
    std::string GetAnimation( void );

    bool SetName( std::string Name );
    std::string GetName ( void );

    bool Colour ( SGZCOLOUR col );

    std::string CheckVar ( std::string VarName );
    bool NewVar( std::string VarName );
    bool DeleteVar( std::string VarName );
    bool ChangeVar( std::string VarName, std::string Value );

    private:
    std::string entityName, animName;

    SGZSCALER entitySpeed, entityMaxSpeed, entityAccel, entityMaxAccel, entityWidth, entityDepth, entityHeight;

    SGZVECTOR position, looking, scale, rotation;

    int entityType;

    SGZCOLOUR colkey;

    NodeHandle entityNode;


};
