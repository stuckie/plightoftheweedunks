/** --------------------------------------------------------------------------------
* \file ITexture.h
* \brief The Interface for Textures
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _OTEXTURE_H_
#define _OTEXTURE_H_

#include "ITexture.h"
#include "arch.h"

#ifdef REND_SDL
#include "SDLTexture.h"
#endif

#ifdef REND_SDLGL
#include "SDLGLTexture.h"
#endif

#ifdef REND_OPENGL
#include "GLTexture.h"
#endif

#if defined(REND_OGRE) || defined(REND_SDLOGRE)
#include "OGRETexture.h"
#endif

#if defined(REND_HORDE) || defined(REND_SDLHORDE)
#include "HordeTexture.h"
#endif

class OTexture : ITexture
{
    public:
    OTexture();
    ~OTexture();

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
    /** Sets transparency */

    bool BlitTexture( SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h);
    /** Blits straight to screen */

    bool BlitTexture(   float x1, float y1, float u1, float v1,
                        float x2, float y2, float u2, float v2,
                        float x3, float y3, float u3, float v3,
                        float x4, float y4, float u4, float v4,
                                                    int layer );

    /** Blits the Horde Way */

    bool SetColour( SGZCOLOUR colour );
    /** Sets the Colour */

    private:
    #ifdef REND_SDL
        SDLTexture       Texture;
    #endif
    #ifdef REND_SDLGL
        SDLGLTexture     Texture;
    #endif
    #ifdef REND_OPENGL
        GLTexture        Texture;
    #endif
    #if defined(REND_OGRE) || defined(REND_SDLOGRE)
        OGRETexture     Texture;
    #endif
    #if defined(REND_HORDE) || defined(REND_SDLHORDE)
        HordeTexture    Texture;
    #endif
};

#endif

/** Changelog for this file:
*/

