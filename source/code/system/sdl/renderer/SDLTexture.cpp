/** --------------------------------------------------------------------------------
* \file SDLTexture.cpp
* \brief The SDL Interface for Textures
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*/
    #include "SDLTexture.h"
    #include "../../../common/debug/CDebug.h"

    SDLTexture::SDLTexture()
    {
    }
    SDLTexture::~SDLTexture()
    {
    }

    bool SDLTexture::CreateTexture ( void )
    {
    /** This creates and sets up a blank texture, which we sometimes need, and gets it ready to load one in if we want. */
        Texture = NULL;
        return true;
    }

    bool SDLTexture::LoadTexture ( std::string Filename )
    {
    /** This loads in a texture */
        SDL_Surface *temp = NULL;
        SGZLogger.debug("SGZTexture: Attempting to load: %s\n",Filename.c_str());
        temp = IMG_Load(Filename.c_str());

        if (!temp)
            /** IF it fails though, return false */
            return false;

        /** Convert it to the current display format if different */
        Texture = SDL_DisplayFormat( temp );

        /** Clean up the temp surface */
        SDL_FreeSurface( temp );

        return true;
    }

    bool SDLTexture::SetColourKey( SGZCOLOUR colkey)
    {
        ColKey = colkey;
        return true;
    }

    void* SDLTexture::GetTexture( void )
    {
    /** This returns the texture, which since it could be anything, is a void pointer */
        return Texture;
    }

    bool SDLTexture::DeleteTexture( void )
    {
    /** Deletes the memory used by this texture */
        if (Texture)
        {
			SDL_FreeSurface(Texture);
            return true;
        }
        else return false;
    }

    bool SDLTexture::BlitTexture( SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h )
    {
        /// Now our Texture Rectangle
        SDL_Rect Rect;
        Rect.x=(Uint16)u;
        Rect.y=(Uint16)v;
        Rect.w=(Uint16)w;
        Rect.h=(Uint16)h;


        /// Make sure we know where we're going
        offset.x = (Sint16)(vector.x);
        offset.y = (Sint16)(vector.y);

        /// Set Colour Key
        SDL_SetColorKey(Texture, SDL_SRCCOLORKEY, SDL_MapRGB(Texture->format, (Uint32)ColKey.r, (Uint32)ColKey.g, (Uint32)ColKey.b));

        /// Blit from our Texture, to our Screen
        SDL_BlitSurface(Texture, &Rect, SDL_GetVideoSurface(), &offset);


        //SDL_BlitSurface(Texture, NULL, SDL_GetVideoSurface(), &offset );
        return true;
    }

    bool SDLTexture::SetColour( SGZCOLOUR colour )
    {
        TexCol = colour;
        return true;
    }
