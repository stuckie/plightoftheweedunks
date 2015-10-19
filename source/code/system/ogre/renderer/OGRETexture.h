/** --------------------------------------------------------------------------------
* \file OGRETexture.h
* \brief The OGRE Interface for Textures
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/

#ifndef _OGRETEXTURE_H_
#define _OGRETEXTURE_H_

#include "../../../arch.h"
#include "../../../client/renderer/texture/ITexture.h"
#include "Ogre.h"

class OGRETexture : ITexture
{
    public:
    OGRETexture() {};
    ~OGRETexture() {};

    bool CreateTexture ( void ) { return false; };
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */

    bool LoadTexture ( std::string Filename ) { return false; };
    /** This loads in a texture */

    bool SetColourKey( SGZCOLOUR colkey ) { return false; };
    /** Sets the colour key -- transparancy */

    void* GetTexture( void ) { return NULL; };
    /** This returns the texture, which since it could be anything, is a void pointer */

    bool DeleteTexture( void ) { return false; };
    /** Deletes the memory used by this texture */

    private:

};

#endif

/** Changelog for this file:
*/



