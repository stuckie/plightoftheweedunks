#include "MLevel.h"
#include "../../../common/engine/CInterpret.h"

MLevel::MLevel()
{
    LevelMap = new Array3D<SGZTile*>(0,0,0);
    SGZLogger.debug("Level Manager Initialised\n");
}

MLevel::~MLevel()
{
}

bool MLevel::NewLevel ( int x, int y, int z )
{
    LevelMap->Resize( x, y, z );
    Clear();
    return true;
}

bool MLevel::Clear( void )
{
    int tempx, tempy, tempz,x,y,z;
    tempx = LevelMap->Width();
    tempy = LevelMap->Height();
    tempz = LevelMap->Depth();
    delete LevelMap;

    LevelMap = new Array3D<SGZTile*>(tempx, tempy, tempz);

    for( z = 0; z < tempz; z++ )
    {
        for( y = 0; y < tempy; y++ )
        {
            for( x = 0; x < tempx; x++ )
            {
                SGZTile *NewTile = new SGZTile;
                NewTile->Name = "none";
                NewTile->VarITR = NewTile->VarList.GetIterator();

                LevelMap->Get(x,y,z) = NewTile;

            }
        }
    }

    return true;
}

bool MLevel::AddTile( std::string Name, std::string Type, int x, int y, int z)
{
    LevelMap->Get(x,y,z)->Name = Name;
    LevelMap->Get(x,y,z)->Type = Type;
    return true;
}

bool MLevel::DelTile ( std::string Name )
{
    int sizex, sizey, sizez, x,y,z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();
    for( z = 0; z < sizez; z++ )
    {
        for( y = 0; y < sizey; y++ )
        {
            for( x = 0; x < sizex; x++ )
            {
                if (LevelMap->Get( x, y, z )->Name.compare(Name)==0)
                {
                    delete LevelMap->Get(x,y,z);
                    return true;
                }
            }
        }
    }

    SGZLogger.warn("Tile %s does not exist!\n", Name.c_str());
    return false;
}

bool MLevel::SetSize ( int x, int y, int z )
{
    LevelMap->Resize( x, y, z );
    Clear();
    return true;
}

bool MLevel::TexTile(std::string Name, std::string TexName, std::string MaskName, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h, SGZCOLOUR key)
{
    int sizex, sizey, sizez, x,y,z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();
    for( z = 0; z < sizez; z++ )
    {
        for( y = 0; y < sizey; y++ )
        {
            for( x = 0; x < sizex; x++ )
            {
                if (LevelMap->Get( x, y, z )->Name.compare(Name)==0)
                {
                    LevelMap->Get(x,y,z)->TexName = TexName;
                    LevelMap->Get(x,y,z)->MaskName = MaskName;
                    LevelMap->Get(x,y,z)->u = u;
                    LevelMap->Get(x,y,z)->v = v;
                    LevelMap->Get(x,y,z)->w = w;
                    LevelMap->Get(x,y,z)->h = h;
                    SGZInterpret.accessServer()->World()->accessTextureManager()->SetColourKey(TexName, key);
                    return true;
                }
            }
        }
    }

    SGZLogger.warn("Tile %s does not exist!\n", Name.c_str());
    return false;
}

bool MLevel::NewVar( std::string Name, std::string VarName )
{
    int sizex, sizey, sizez, x,y,z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();
    for( z = 0; z < sizez; z++ )
    {
        for( y = 0; y < sizey; y++ )
        {
            for( x = 0; x < sizex; x++ )
            {
                if (LevelMap->Get( x, y, z )->Name.compare(Name)==0)
                {
                    SGZVarGroup *Variable = new SGZVarGroup;
                    Variable->Name = VarName;
                    Variable->Variable = "none";
                    LevelMap->Get(x,y,z)->VarList.Append(Variable);

                    return true;
                }
            }
        }
    }

    SGZLogger.warn("Tile %s does not exist!\n", Name.c_str());
    return false;
}

bool MLevel::DeleteVar( std::string Name, std::string VarName )
{
    int sizex, sizey, sizez, x, y, z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();
    for( z = 0; z < sizez; z++ )
    {
        for( y = 0; y < sizey; y++ )
        {
            for( x = 0; x < sizex; x++ )
            {
                if (LevelMap->Get( x, y, z )->Name.compare(Name)==0)
                {
                    LevelMap->Get( x, y, z )->VarITR = LevelMap->Get( x, y, z )->VarList.GetIterator();

                    for( LevelMap->Get( x, y, z )->VarITR.Start(); LevelMap->Get( x, y, z )->VarITR.Valid(); LevelMap->Get( x, y, z )->VarITR.Forth() )
                        if(LevelMap->Get( x, y, z )->VarITR.Item()->Name.compare(VarName)==0)
                        {
                            LevelMap->Get( x, y, z )->VarList.Remove(LevelMap->Get( x, y, z )->VarITR);
                            return true;
                        }
                    SGZLogger.warn("Variable \"%s\" does not exist!\n",VarName.c_str());
                }
            }
        }
    }

    SGZLogger.warn("Tile %s does not exist!\n", Name.c_str());
    return false;
}

bool MLevel::ChangeVar ( std::string Name, std::string VarName, std::string Value )
{
    int sizex, sizey, sizez, x,y,z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();
    for( z = 0; z < sizez; z++ )
    {
        for( y = 0; y < sizey; y++ )
        {
            for( x = 0; x < sizex; x++ )
            {
                if (LevelMap->Get( x, y, z )->Name.compare(Name)==0)
                {
                    LevelMap->Get( x, y, z )->VarITR = LevelMap->Get( x, y, z )->VarList.GetIterator();

                    for( LevelMap->Get( x, y, z )->VarITR.Start(); LevelMap->Get( x, y, z )->VarITR.Valid(); LevelMap->Get( x, y, z )->VarITR.Forth() )
                        if((LevelMap->Get( x, y, z )->VarITR.Item()->Name.compare(VarName))==0)
                        {
                            LevelMap->Get( x, y, z )->VarITR.Item()->Variable = Value;
                            return true;
                        }
                    SGZLogger.warn("Variable \"%s\" does not exist!\n",VarName.c_str());
                }
            }
        }
    }

    SGZLogger.warn("Tile \"%s\" does not exist!\n",Name.c_str());
    return false;
}

std::string MLevel::CheckVar( std::string Name, std::string VarName )
{
    int sizex, sizey, sizez, x,y,z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();
    for( z = 0; z < sizez; z++ )
    {
        for( y = 0; y < sizey; y++ )
        {
            for( x = 0; x < sizex; x++ )
            {
                if (LevelMap->Get( x, y, z )->Name.compare(Name)==0)
                {
                    LevelMap->Get( x, y, z )->VarITR = LevelMap->Get( x, y, z )->VarList.GetIterator();

                    for( LevelMap->Get( x, y, z )->VarITR.Start(); LevelMap->Get( x, y, z )->VarITR.Valid(); LevelMap->Get( x, y, z )->VarITR.Forth() )
                        if((LevelMap->Get( x, y, z )->VarITR.Item()->Name.compare(VarName))==0)
                            return LevelMap->Get( x, y, z )->VarITR.Item()->Variable;

                    SGZLogger.warn("Variable \"%s\" does not exist!\n",VarName.c_str());
                }
            }
        }
    }

    SGZLogger.warn("Tile \"%s\" does not exist!\n",Name.c_str());

    return "none";
}

bool MLevel::CheckExist( std::string TileName )
{
    int sizex, sizey, sizez, x,y,z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();

    for( z = 0; z < sizez; z++ )
        for( y = 0; y < sizey; y++ )
            for( x = 0; x < sizex; x++ )
                if (LevelMap->Get( x, y, z )->Name.compare(TileName)==0)
                    return true;

    return false;
}

bool MLevel::RenderLevel( void )
{
    int sizex, sizey, sizez, x,y,z;
    sizex = LevelMap->Width();
    sizey = LevelMap->Height();
    sizez = LevelMap->Depth();

    for( z = 0; z < sizez; z++ )
        for( y = 0; y < sizey; y++ )
            for( x = 0; x < sizex; x++ )
                if (!LevelMap->Get( x, y, z )->Name.compare("none")==0)
                    {
                        SGZVECTOR position;
                        position.x = x * LevelMap->Get(x,y,z)->w;
                        position.y = y * LevelMap->Get(x,y,z)->h;
                        position.z = z;
                        SGZInterpret.accessServer()->World()->accessTextureManager()->BlitTexture(
                        LevelMap->Get(x,y,z)->TexName, position, LevelMap->Get(x,y,z)->u, LevelMap->Get(x,y,z)->v,
                        LevelMap->Get(x,y,z)->w, LevelMap->Get(x,y,z)->h  );
                    }

    return true;
}

std::string MLevel::GetType(int x, int y, int z )
{
    return LevelMap->Get(x,y,z)->Type;
}
