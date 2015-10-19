#ifndef _OFRAME_H_
#define _OFRAME_H_

#include "IFrame.h"
#include "OButton.h"
#include "OTexture.h"
#include "arch.h"
#include "CSLinkedlist.h"

class OFrame : public IFrame
{
    public:
    OFrame();
    ~OFrame();

    bool UpdateFrame ( void );
    bool DestroyFrame ( void );

    bool SetName ( std::string FrameName );
    std::string GetName ( void );

    bool AddButton ( OButton *Button );
    OButton* GetButton ( std::string ButtonName );

    bool IsSelected ( void );
    bool Select ( bool value );

    private:

    std::string Name;

    float posX, posY, posZ;
    float frameWidth, frameHeight, frameDepth;
    float colR, colG, colB;

    bool Selected;

    OTexture *FrameSkin;

    SLinkedList<OButton*> ButtonList;
    SListIterator<OButton*> ButtonITR;

};

#endif
