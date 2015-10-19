#ifndef _SDLGLTEXTURE_H_
#define _SDLGLTEXTURE_H_

#include "arch.h"
#include "ITexture.h"
#include "CDebug.h"

#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class SDLGLTexture : public ITexture
{
    public:
    SDLGLTexture() {};
    ~SDLGLTexture() {};

    bool CreateTexture ( void );
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */

    bool LoadTexture ( std::string Filename );
    /** This loads in a texture */

    bool LoadTextureMask ( std::string Filename );
    /** This loads in a texture mask */

    void* GetTexture( void );
    /** This returns the texture, which since it could be anything, is a void pointer */

    void* GetTextureMask( void );
    /** This returns the texture, which since it could be anything, is a void pointer */

    bool DeleteTexture( void );
    /** Deletes the memory used by this texture */

    bool SetColourKey( SGZCOLOUR colkey );
    /** Sets transparency */

    bool SetColour( SGZCOLOUR colour );

    bool BlitTexture(SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h);
    /** Blit Texture straight to Screen */

    private:

    SDL_Surface *SDLTexture;
    GLuint GLTexture, GLTextureMask;

    int width, height;

    SGZCOLOUR colour;
};

#endif
