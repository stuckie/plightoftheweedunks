#include "AI.h"

weedunkState AIClass::getWeedunkState(const int _weedunkID)
{
    if (_weedunkID<0 || (unsigned int)_weedunkID>=mWeedunks.size())
        return WEEDUNK_FUCKED;

    return mWeedunks[_weedunkID].state;
}

float AIClass::getWeedunkRot(const int _weedunkID)
{
    if (_weedunkID<0 || (unsigned int)_weedunkID>=mWeedunks.size())
        return 0.0f;

    return mWeedunks[_weedunkID].rot;
}
