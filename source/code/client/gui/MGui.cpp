#include "MGui.h"

MGui::MGui()
{
    // clean lists
}

MGui::~MGui()
{
    // clean lists
}

bool MGui::CreateFrame(std::string FrameName)
{
    OFrame* Frame = new OFrame;
    Frame->SetName(FrameName);
    FrameList.Append(Frame);

    return true;
}

bool MGui::DestroyFrame(std::string FrameName)
{
    SListIterator<OFrame*> FrameITR = FrameList.GetIterator();
    for( FrameITR.Start(); FrameITR.Valid(); FrameITR.Forth() )
        if(FrameITR.Item()->GetName().compare(FrameName)==0)
            FrameList.Remove(FrameITR);

    return true;
}

OFrame* MGui::GetFrame(std::string FrameName)
{
    SListIterator<OFrame*> FrameITR = FrameList.GetIterator();
    for( FrameITR.Start(); FrameITR.Valid(); FrameITR.Forth() )
        if(FrameITR.Item()->GetName().compare(FrameName)==0)
            return FrameITR.Item();

    return NULL;
}
