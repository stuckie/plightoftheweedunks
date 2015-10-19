#include "OFrame.h"

OFrame::OFrame()
{
    // clear button lists
}

OFrame::~OFrame()
{
    //clear button lists
}

bool OFrame::UpdateFrame ( void )
{
    return true;
}

bool OFrame::DestroyFrame ( void )
{
    return true;
}

bool OFrame::SetName ( std::string FrameName )
{
    Name = FrameName;
    return true;
}

std::string OFrame::GetName ( void )
{
    return Name;
}

bool OFrame::AddButton(OButton *Button)
{
    ButtonList.Append(Button);
    return true;
}

OButton* OFrame::GetButton ( std::string ButtonName )
{
    SListIterator<OButton*> ButtonITR = ButtonList.GetIterator();

    for( ButtonITR.Start(); ButtonITR.Valid(); ButtonITR.Forth() )
        if((ButtonITR.Item()->GetName().compare(Name))==0)
            return ButtonITR.Item();

    SGZLogger.warn("Button \"%s\" does not exist!\n",ButtonName.c_str());
    return NULL;
}

bool OFrame::IsSelected ( void )
{
    return Selected;
}

bool OFrame::Select ( bool value )
{
    Selected = value;
    return true;
}
