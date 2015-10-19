/* Texture Manager
*/

#ifndef _MTEXTURE_H_
#define _MTEXTURE_H_

#include "arch.h"
#include "OTexture.h"
#include "CSLinkedlist.h"

class TextureObj
{
    public:
    TextureObj() { Data = new OTexture; };
    ~TextureObj() { Data->DeleteTexture(); delete Data; };

    std::string Name;
    OTexture *Data;
};

class MTexture
{
    public:
        MTexture();
        ~MTexture();

        bool    AddTexture( std::string Name, std::string Filename );
        bool    AddTexMask( std::string Name, std::string Maskname );
        bool    DelTexture( std::string Name );
        TextureObj* GetObj( std::string Name );
        void*   GetTexture( std::string Name );
        void*   GetTextureMask(std::string Name);
        bool    BlitTexture( std::string Name, SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h );
        bool    BlitTexture( std::string Name,  float x1, float y1, float u1, float v1,
                                                float x2, float y2, float u2, float v2,
                                                float x3, float y3, float u3, float v3,
                                                float x4, float y4, float u4, float v4,
                                                                            int layer );

        bool    SetColour ( std::string Name, SGZCOLOUR colour );
        bool    SetColourKey ( std::string Name, SGZCOLOUR key );
        bool    CheckExist( std::string Name );

    private:
        SLinkedList<TextureObj*> TextureList;
        SListIterator<TextureObj*> TextureITR;
};

#endif
