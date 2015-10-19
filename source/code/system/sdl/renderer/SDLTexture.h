/** --------------------------------------------------------------------------------
* \file SDLTexture.h
* \brief The SDL Interface for Textures
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _SDLTEXTURE_H_
#define _SDLTEXTURE_H_

#include "../../../arch.h"
#include "../../../client/renderer/texture/ITexture.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class SDLTexture : ITexture
{
    public:
    SDLTexture();
    ~SDLTexture();

    bool CreateTexture ( void );
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */

    bool LoadTexture ( std::string Filename );
    /** This loads in a texture */

    bool SetColour( SGZCOLOUR colour );
    bool BlitTexture(SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h);

    bool SetColourKey( SGZCOLOUR colkey );
    /** Sets the colour key -- transparancy */

    void* GetTexture( void );
    /** This returns the texture, which since it could be anything, is a void pointer */

    void* GetTextureMask ( void ) {return NULL;};
    bool LoadTextureMask ( std::string Filename ) {return true;};

    bool DeleteTexture( void );
    /** Deletes the memory used by this texture */

    private:
    SDL_Surface *Texture;
    SGZCOLOUR TexCol, ColKey;
    SDL_Rect offset;

};

#endif

/** Changelog for this file:
*/


