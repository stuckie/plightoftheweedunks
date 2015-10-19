/** -------------------------------------------------------------------------------
* \file ONetwork.cpp
* \brief The Network Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

/**
    The Network Object is what you reference from the engine to talk to the underlaying hardware/api.
    This is where we wrap all the dependancies up depending on the build of the engine.

    The important thing here is that this is just a further interface to the seperate layers themselves:
    be it Winsock, BSD Sockets, DirectPlay, SDL_net, etc.. the underlaying layers have all the dependant
    code, this is just packaging it so they can be called from the one Object.
*/

#include "ONetwork.h"

bool ONetwork::CreateInterface()
{
    return NetworkObj.CreateInterface();
}

bool ONetwork::DestroyInterface()
{
    return NetworkObj.DestroyInterface();
}

bool ONetwork::UpdateInterface()
{
    return NetworkObj.UpdateInterface();
}

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/


