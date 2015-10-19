#include "ITexture.h"
#include <Horde3D.h>
#include <Horde3DUtils.h>

class HordeTexture : public ITexture
{
    public:
    HordeTexture();
    ~HordeTexture();

    bool CreateTexture ( void );
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */

    bool LoadTexture ( std::string Filename );
    /** This loads in a texture */

    bool LoadTextureMask ( std::string Filename );
    /** This loads in a texture */

    void* GetTexture( void );
    /** This returns the texture, which since it could be anything, is a void pointer */

    void* GetTextureMask( void );
    /** This returns the texture mask, which since it could be anything, is a void pointer */

    bool DeleteTexture( void );
    /** Deletes the memory used by this texture */

    bool SetColourKey( SGZCOLOUR colkey );
    /** Sets Colour Key */

    bool SetColour( SGZCOLOUR colour );
    /** Sets Colour */

    bool BlitTexture( SGZVECTOR vector , SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h );
    /** Blits a texture STRAIGHT to the screen */

    bool BlitTexture(           float x1, float y1, float u1, float v1,
                                float x2, float y2, float u2, float v2,
                                float x3, float y3, float u3, float v3,
                                float x4, float y4, float u4, float v4,
                                int layer );
    /** Horde-specific Overlay Fun! */

    private:
    ResHandle Texture, TextureMask;

    SGZCOLOUR ColourKey, Colour;


};
