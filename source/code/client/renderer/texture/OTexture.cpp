/** --------------------------------------------------------------------------------
* \file OTexture.cpp
* \brief The Texture Object
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#include "OTexture.h"

OTexture::OTexture()
{
    CreateTexture();
}

OTexture::~OTexture()
{
    DeleteTexture();
}

bool OTexture::CreateTexture ( void )
{
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */
    return Texture.CreateTexture();
}

bool OTexture::LoadTexture ( std::string Filename )
{
    /** This loads in a texture */
    return Texture.LoadTexture(Filename);
}

bool OTexture::LoadTextureMask ( std::string Filename )
{
    /** This loads in a texture */
    return Texture.LoadTextureMask(Filename);
}

void* OTexture::GetTexture( void )
{
    /** This returns the texture, which since it could be anything, is a void pointer */
    return Texture.GetTexture();
}

bool OTexture::DeleteTexture( void )
{
    /** Deletes the memory used by this texture */
    return Texture.DeleteTexture();
}

bool OTexture::SetColourKey( SGZCOLOUR colkey )
{
    /** Sets transparency */
    return Texture.SetColourKey(colkey);
}

bool OTexture::BlitTexture( SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h )
{
    /** Blits texture straight to scren */
    return Texture.BlitTexture(vector,u,v,w,h);
}

bool OTexture::SetColour( SGZCOLOUR colour )
{
    return Texture.SetColour(colour);
}

void* OTexture::GetTextureMask( void )
{
    return Texture.GetTextureMask();
}

#if defined(REND_HORDE) || defined(REND_SDLHORDE)
bool OTexture::BlitTexture( float x1, float y1, float u1, float v1,
                            float x2, float y2, float u2, float v2,
                            float x3, float y3, float u3, float v3,
                            float x4, float y4, float u4, float v4,
                                                        int layer )
{
    return Texture.BlitTexture( x1, y1, u1, v1,
                                x2, y2, u2, v2,
                                x3, y3, u3, v3,
                                x4, y4, u4, v4,
                                        layer);
}
#endif
