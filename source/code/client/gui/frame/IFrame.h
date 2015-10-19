#ifndef _IFRAME_H_
#define _IFRAME_H_

#include <string>
#include "CDebug.h"
#include "OButton.h"

class IFrame
{
    public:
    virtual ~IFrame() {}

    virtual bool UpdateFrame ( void ) = 0;
    virtual bool DestroyFrame ( void ) = 0;

    virtual bool SetName ( std::string FrameName ) = 0;
    virtual std::string GetName ( void ) = 0;

    virtual bool AddButton ( OButton *Button ) = 0;
    virtual OButton* GetButton ( std::string ButtonName ) = 0;

    virtual bool IsSelected ( void ) = 0;
    virtual bool Select ( bool value ) = 0;

};

#endif
