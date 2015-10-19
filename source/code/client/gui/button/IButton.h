#ifndef _IBUTTON_H_
#define _IBUTTON_H_

#include <string>
#include "arch.h"
#include "CDebug.h"

class IButton
{
    public:
    virtual ~IButton() {}

    virtual bool UpdateButton ( void ) = 0;
    virtual bool DestroyButton ( void ) = 0;

    virtual bool SetName ( std::string ButtonName ) = 0;
    virtual std::string GetName ( void ) = 0;

    virtual bool IsSelected ( void ) = 0;
    virtual bool Select ( bool value ) = 0;

    virtual bool CreateState ( std::string state ) = 0;
    virtual bool LoadTexture ( std::string state, std::string filename ) = 0;
    virtual bool DeleteState ( std::string state ) = 0;
    virtual bool ChangeState ( std::string state ) = 0;
    virtual std::string GetState ( void ) = 0;

    virtual bool Position ( SGZVECTOR vector ) = 0;
    virtual bool Colour ( SGZCOLOUR colour ) = 0;
    virtual bool Size ( SGZSCALER width, SGZSCALER height, SGZSCALER depth ) = 0;

};

#endif

