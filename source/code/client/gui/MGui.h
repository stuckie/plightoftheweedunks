/** MGUI - Gui Manager */

#ifndef _MGUI_H_
#define _MGUI_H_

#include "arch.h"
#include "CSLinkedlist.h"
#include "OFrame.h"
#include "OButton.h"

class MGui
{
    public:
    MGui();
    ~MGui();

    bool CreateGui ( void );
    bool DestroyGui ( void );

    bool CreateFrame ( std::string FrameName );
    bool DestroyFrame ( std::string FrameName );
    OFrame* GetFrame ( std::string FrameName );


    bool CreateButton ( std::string FrameName, std::string ButtonName );
    bool DestroyButton ( std::string FrameName, std::string ButtonName );
    bool ButtonTexture ( std::string FrameName, std::string ButtonName, std::string FileName, std::string MaskName );
    OButton* GetButton ( std::string FrameName, std::string ButtonName );


    private:
    SLinkedList<OFrame*> FrameList;
    SListIterator<OFrame*> FrameITR;

};

#endif
