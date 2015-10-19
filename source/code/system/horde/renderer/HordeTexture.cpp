#include "HordeTexture.h"

HordeTexture::HordeTexture()
{

}

HordeTexture::~HordeTexture()
{

}

bool HordeTexture::CreateTexture ( void )
{
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */

    return true;
}

bool HordeTexture::LoadTexture ( std::string Filename )
{
    /** This loads in a texture */
    Texture = Horde3D::addResource( ResourceTypes::Material, Filename.c_str(), 0 );
    Horde3DUtils::loadResourcesFromDisk( "data" );

    return true;
}

bool HordeTexture::LoadTextureMask ( std::string Filename )
{
    /** This loads in a texture */
    Texture = Horde3D::addResource( ResourceTypes::Material, Filename.c_str(), 0 );
    Horde3DUtils::loadResourcesFromDisk( "data" );

    return true;
}

void* HordeTexture::GetTexture( void )
{
    /** This returns the texture, which since it could be anything, is a void pointer */

    return &Texture;
}

void* HordeTexture::GetTextureMask( void )
{
    /** This returns the texture mask, which since it could be anything, is a void pointer */

    return &TextureMask;
}

bool HordeTexture::DeleteTexture( void )
{
    /** Deletes the memory used by this texture */
    Horde3D::unloadResource(Texture);
    Horde3D::removeResource(Texture);

    Horde3D::releaseUnusedResources();

    return true;
}

bool HordeTexture::SetColourKey( SGZCOLOUR colkey )
{
    /** Sets Colour Key */
    ColourKey = colkey;

    return true;
}

bool HordeTexture::SetColour( SGZCOLOUR colour )
{
    /** Sets Colour */
    Colour = colour;

    return true;
}

bool HordeTexture::BlitTexture( SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h )
{
    /** Blits a texture STRAIGHT to the screen .. in a somewhat botched way! */
    Horde3D::showOverlay(	(float)vector.x,            (float)vector.y,            (float)u,           (float)v,
                            (float)vector.x +(float)w,  (float)vector.y,            (float)u+(float)w,  (float)v,
                            (float)vector.x +(float)w,  (float)vector.y+(float)h,   (float)u+(float)w,  (float)v+(float)h,
                            (float)vector.x,            (float)vector.y+(float)h,   (float)u,           (float)v+(float)h,
                            (int) vector.z, Texture);

    return true;
}

bool HordeTexture::BlitTexture( float x1, float y1, float u1, float v1,
                                float x2, float y2, float u2, float v2,
                                float x3, float y3, float u3, float v3,
                                float x4, float y4, float u4, float v4,
                                int layer )
{
    /** Blits a texture STRAIGHT to the screen  The HORDE way! */
    Horde3D::showOverlay(	x1, y1, u1, v1,
                            x2, y2, u2, v2,
                            x3, y3, u3, v3,
                            x4, y4, u4, v4,
                            layer, Texture);

    /*  (x,y) 1 = bottom left quad   | (u,v) 1 = bottom left tex co-ords
        (x,y) 2 = bottom right quad  | (u,v) 2 = bottom right tex co-ords
        (x,y) 3 = upper right quad   | (u,v) 3 = upper right tex co-ords
        (x,y) 4 = upper left quad    | (u,v) 4 = upper left tex co-ords */

    return true;
}
