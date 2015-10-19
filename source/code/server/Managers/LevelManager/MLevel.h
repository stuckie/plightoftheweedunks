#ifndef _MLEVEL_H_
#define _MLEVEL_H_

#include "arch.h"
#include "CDebug.h"
#include "IEntity.h"
#include "CArray3D.h"
#include "OTexture.h"

struct SGZTile
{
    std::string Name;

    std::string TexName;
    std::string MaskName;
    std::string Type;
    SGZSCALER u,v,w,h;
    SGZCOLOUR key;

    SLinkedList<SGZVarGroup*> VarList;
    SListIterator<SGZVarGroup*> VarITR;
};

class MLevel
{
    public:

    MLevel();
    ~MLevel();

    bool NewLevel( int x, int y, int z);
    bool SetSize( int x, int y, int z );
    bool AddTile( std::string Name, std::string Type, int x, int y, int z );
    bool TexTile( std::string Name, std::string TexName, std::string MaskName, SGZSCALER u, SGZSCALER v, SGZSCALER w, SGZSCALER h, SGZCOLOUR key );
    bool DelTile( std::string Name );

    bool Clear( void );
    bool RenderLevel( void );
    std::string GetType(int x, int y, int z);

    std::string CheckVar ( std::string Name, std::string VarName );
    bool NewVar( std::string Name, std::string VarName );
    bool DeleteVar( std::string Name, std::string VarName );
    bool ChangeVar( std::string Name, std::string VarName, std::string Value );
    bool CheckExist( std::string Name );

    private:

    Array3D<SGZTile*> *LevelMap;


};

#endif

