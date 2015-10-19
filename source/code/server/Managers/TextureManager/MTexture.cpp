#include "MTexture.h"
#include "../../../common/debug/CDebug.h"

MTexture::MTexture()
{
    /** Constructor */
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    SGZLogger.debug("SGZTextureManager Started\n");
}

MTexture::~MTexture()
{
    /** Destructor */
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();

    TextureITR.Start();
    while (TextureITR.Valid())
    {
        TextureList.Remove(TextureITR);
        TextureITR.Forth();
    }
}

bool MTexture::AddTexture( std::string TexName, std::string Filename )
{
    TextureObj* Texture = new TextureObj;
    Texture->Name = TexName;
    Texture->Data->CreateTexture();
    Texture->Data->LoadTexture(Filename);
    TextureList.Append(Texture);

    return true;
}
bool MTexture::AddTexMask( std::string Name, std::string Maskname )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            TextureITR.Item()->Data->LoadTextureMask(Maskname);
            return true;
        }

    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return false;
}
bool MTexture::DelTexture( std::string Name )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            TextureList.Remove(TextureITR);
            return true;
        }

    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return false;
}

TextureObj* MTexture::GetObj ( std::string Name )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            return TextureITR.Item();
        }

    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return NULL;
}

void* MTexture::GetTexture( std::string Name )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            return TextureITR.Item()->Data->GetTexture();
        }

    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return NULL;
}

void* MTexture::GetTextureMask( std::string Name )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            return TextureITR.Item()->Data->GetTextureMask();
        }

    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return NULL;
}

bool MTexture::SetColour ( std::string Name, SGZCOLOUR colour )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            TextureITR.Item()->Data->SetColour(colour);
            return true;
        }

    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return false;
}

bool MTexture::CheckExist ( std::string Name )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
            return true;

    return false;
}

bool MTexture::BlitTexture ( std::string Name, SGZVECTOR vector, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            TextureITR.Item()->Data->BlitTexture(vector,u,v,w,h);
            return true;
        }
    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return false;
}

#if defined(REND_HORDE) || defined(REND_SDLHORDE)
bool MTexture::BlitTexture ( std::string Name,  float x1, float y1, float u1, float v1,
                                                float x2, float y2, float u2, float v2,
                                                float x3, float y3, float u3, float v3,
                                                float x4, float y4, float u4, float v4,
                                                                            int layer )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
        {
            TextureITR.Item()->Data->BlitTexture(   x1, y1, u1, v1,
                                                    x2, y2, u2, v2,
                                                    x3, y3, u3, v3,
                                                    x4, y4, u4, v4,
                                                    layer);
            return true;
        }
    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return false;
}
#endif


bool MTexture::SetColourKey ( std::string Name, SGZCOLOUR key )
{
    SListIterator<TextureObj*> TextureITR = TextureList.GetIterator();
    for( TextureITR.Start(); TextureITR.Valid(); TextureITR.Forth() )
        if(TextureITR.Item()->Name.compare(Name)==0)
            TextureITR.Item()->Data->SetColourKey(key);


    SGZLogger.warn("Texture %s does not exist!\n", Name.c_str());
    return false;
}



