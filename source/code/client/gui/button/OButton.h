#ifndef _OBUTTON_H_
#define _OBUTTON_H_

#include "IButton.h"
#include "OTexture.h"
#include "arch.h"
#include "CSLinkedlist.h"

struct ButtonStates
{
    std::string StateName;
    OTexture *Texture;
};


class OButton : public IButton
{
    public:

    OButton();
    ~OButton();

    bool UpdateButton ( void );
    bool DestroyButton ( void );

    bool SetName ( std::string ButtonName );
    std::string GetName ( void );

    bool IsSelected ( void );
    bool Select ( bool value );

    bool CreateState ( std::string state );
    bool LoadTexture ( std::string state, std::string filename );
    bool DeleteState ( std::string state );
    bool ChangeState ( std::string state );
    std::string GetState ( void );

    bool Position ( SGZVECTOR vector );
    bool Colour ( SGZCOLOUR colour );
    bool Size ( SGZSCALER width, SGZSCALER height, SGZSCALER depth );

    private:

    std::string Name;

    SGZVECTOR position;
    SGZCOLOUR colour;
    SGZSCALER butW, butH, butD;

    bool Selected;

    SLinkedList<ButtonStates*> StateList;
    SListIterator<ButtonStates*> StateITR;


};

#endif
