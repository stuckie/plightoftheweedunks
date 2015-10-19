#include "SDLGLTexture.h"
#include "glext.h"

bool SDLGLTexture::CreateTexture( void )
{
    SDLTexture = NULL;
    return true;
}

bool SDLGLTexture::LoadTexture(std::string Filename)
{
    glEnable(GL_TEXTURE_2D);
    GLenum texture_format = GL_RGBA;
    GLint  nOfColors;

    /** This loads in a texture */
    SDL_Surface *temp = NULL;
    SGZLogger.debug("Attempting to load: %s\n",Filename.c_str());
    temp = IMG_Load(Filename.c_str());

    if (!temp)
        /** IF it fails though, return false */
        return false;

    /** Convert it to the current display format if different */
    SDLTexture = SDL_DisplayFormat( temp );

    /** Clean up the temp surface */
    SDL_FreeSurface( temp );

	if (!SDLTexture)
		return false;

    // Check that the image's width is a power of 2
	if ( (SDLTexture->w & (SDLTexture->w - 1)) != 0 ) {
		SGZLogger.debug("warning: %s's width is not a power of 2\n", Filename.c_str());
	}

	// Also check if the height is a power of 2
	if ( (SDLTexture->h & (SDLTexture->h - 1)) != 0 ) {
		SGZLogger.debug("warning: %s's height is not a power of 2\n", Filename.c_str());
	}

    // get the number of channels in the SDL surface
        nOfColors = SDLTexture->format->BytesPerPixel;
        if (nOfColors == 4)     // contains an alpha channel
        {
                if (SDLTexture->format->Rmask == 0x000000ff)
                        texture_format = GL_RGBA;
                else
                        texture_format = GL_BGRA;
        } else if (nOfColors == 3)     // no alpha channel
        {
                if (SDLTexture->format->Rmask == 0x000000ff)
                        texture_format = GL_RGB;
                else
                        texture_format = GL_BGR;
        } else {
                SGZLogger.debug("warning: %s is not truecolor..  this will probably break\n", Filename.c_str());
                // this error should not go unhandled
        }

    /// Now for the OpenGL aspect of things
	glGenTextures(1, &GLTexture);
	// Bind our SDL Texture to our GL Texture
	glBindTexture( GL_TEXTURE_2D, GLTexture );
	// Do some filtering on it.. Nearest Filtering
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Build MipMaps and push the actual SDLTexture Data to the GLTexture
	glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, SDLTexture->w, SDLTexture->h, 0, texture_format, GL_UNSIGNED_BYTE, SDLTexture->pixels );


    width = SDLTexture->w;
    height = SDLTexture->h;
	// We can free up the SDLTexture now, since we're using OpenGL we don't need it now.
	if (SDLTexture)
		SDL_FreeSurface(SDLTexture);

	return true;
}

bool SDLGLTexture::LoadTextureMask(std::string Filename)
{
    glEnable(GL_TEXTURE_2D);
    GLenum texture_format = GL_RGBA;
    GLint  nOfColors;

    /** This loads in a texture */
    SDL_Surface *temp = NULL;
    SGZLogger.debug("Attempting to load: %s\n",Filename.c_str());
    temp = IMG_Load(Filename.c_str());

    if (!temp)
        /** IF it fails though, return false */
        return false;

    /** Convert it to the current display format if different */
    SDLTexture = SDL_DisplayFormat( temp );

    /** Clean up the temp surface */
    SDL_FreeSurface( temp );

	if (!SDLTexture)
		return false;

    // Check that the image's width is a power of 2
	if ( (SDLTexture->w & (SDLTexture->w - 1)) != 0 ) {
		SGZLogger.debug("warning: %s's width is not a power of 2\n", Filename.c_str());
	}

	// Also check if the height is a power of 2
	if ( (SDLTexture->h & (SDLTexture->h - 1)) != 0 ) {
		SGZLogger.debug("warning: %s's height is not a power of 2\n", Filename.c_str());
	}

    // get the number of channels in the SDL surface
        nOfColors = SDLTexture->format->BytesPerPixel;
        if (nOfColors == 4)     // contains an alpha channel
        {
                if (SDLTexture->format->Rmask == 0x000000ff)
                        texture_format = GL_RGBA;
                else
                        texture_format = GL_BGRA;
        } else if (nOfColors == 3)     // no alpha channel
        {
                if (SDLTexture->format->Rmask == 0x000000ff)
                        texture_format = GL_RGB;
                else
                        texture_format = GL_BGR;
        } else {
                SGZLogger.debug("warning: %s is not truecolor..  this will probably break\n", Filename.c_str());
                // this error should not go unhandled
        }

    /// Now for the OpenGL aspect of things
	glGenTextures(1, &GLTextureMask);
	// Bind our SDL Texture to our GL Texture
	glBindTexture( GL_TEXTURE_2D, GLTextureMask );
	// Do some filtering on it.. Nearest Filtering
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Build MipMaps and push the actual SDLTexture Data to the GLTexture
	glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, SDLTexture->w, SDLTexture->h, 0, texture_format, GL_UNSIGNED_BYTE, SDLTexture->pixels );


    width = SDLTexture->w;
    height = SDLTexture->h;
	// We can free up the SDLTexture now, since we're using OpenGL we don't need it now.
	if (SDLTexture)
		SDL_FreeSurface(SDLTexture);

	return true;
}


void* SDLGLTexture::GetTexture( void )
{
    /** This returns the texture, which since it could be anything, is a void pointer */
    glBindTexture( GL_TEXTURE_2D, GLTexture );
    return NULL;
}

void* SDLGLTexture::GetTextureMask( void )
{
    /** This returns the texture, which since it could be anything, is a void pointer */
    glBindTexture( GL_TEXTURE_2D, GLTextureMask );
    return NULL;
}

bool SDLGLTexture::DeleteTexture( void )
{
    /** Deletes the memory used by this texture */
    glDeleteTextures(1, &GLTexture);
    glDeleteTextures(1, &GLTextureMask);

    return true;
}

bool SDLGLTexture::BlitTexture ( SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h )
{
    glPushMatrix();
		glEnable(GL_BLEND);
			glDisable(GL_DEPTH_TEST);
				glDisable(GL_LIGHTING);
                    glColor3f(1, 1, 1);
					glLoadIdentity();
					glTranslatef(vector.x, vector.y, vector.z);
					glBlendFunc( GL_DST_COLOR, GL_ZERO );
					glBindTexture( GL_TEXTURE_2D, GLTextureMask );
					glBegin ( GL_QUADS );
                        glNormal3f(0.0f, 0.0f, 1.0f);
                        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  0.0f);	// Point 1
                        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  0.0f);	// Point 2
                        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  0.0f);	// Point 3
                        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  0.0f);	// Point 4
                    glEnd();
                    glColor3f(colour.r, colour.g, colour.b);
                    glBlendFunc( GL_ONE, GL_ONE );
                    glBindTexture( GL_TEXTURE_2D, GLTexture );
                    glBegin ( GL_QUADS );
                        glNormal3f(0.0f, 0.0f, 1.0f);
                        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  0.0f);	// Point 1
                        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  0.0f);	// Point 2
                        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  0.0f);	// Point 3
                        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  0.0f);	// Point 4
                    glEnd();
				glEnable(GL_LIGHTING);
			glEnable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
	glPopMatrix();

    return true;
}

bool SDLGLTexture::SetColour( SGZCOLOUR col )
{
    /** Sets the colour in this case */
    colour = col;
    return true;
}

bool SDLGLTexture::SetColourKey(SGZCOLOUR colkey)
{
    /** Not Used */
    return true;
}
