/** --------------------------------------------------------------------------------
* \file ITexture.h
* \brief The Interface for Textures
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _ITEXTURE_H_
#define _ITEXTURE_H_

#include <string>
#include "arch.h"

class ITexture
{
    public:
    virtual ~ITexture() {}

    virtual bool CreateTexture ( void ) = 0;
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */

    virtual bool LoadTexture ( std::string Filename ) = 0;
    /** This loads in a texture */

    virtual bool LoadTextureMask ( std::string Filename ) = 0;
    /** This loads in a texture */

    virtual void* GetTexture( void ) = 0;
    /** This returns the texture, which since it could be anything, is a void pointer */

    virtual void* GetTextureMask( void ) = 0;
    /** This returns the texture mask, which since it could be anything, is a void pointer */

    virtual bool DeleteTexture( void ) = 0;
    /** Deletes the memory used by this texture */

    virtual bool SetColourKey( SGZCOLOUR colkey ) = 0;
    /** Sets Colour Key */

    virtual bool SetColour( SGZCOLOUR colour ) = 0;
    /** Sets Colour */

    virtual bool BlitTexture( SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h ) = 0;
    /** Blits a texture STRAIGHT to the screen */
};

#endif

/** Changelog for this file:
*/

