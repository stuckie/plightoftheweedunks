/** -------------------------------------------------------------------------------
* \file ONetwork.h
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

#ifndef _ONETWORK_H_
#define _ONETWORK_H_

#include "INetwork.h"
#include "../../arch.h"
#include "../debug/CDebug.h"

#ifdef NET_BSD
    #include "../../system/bsd/net/BSDNetwork.h"
#endif
#ifdef NET_WIN
    #include "../../system/winapi/net/WINNetwork.h"
#endif
#ifdef NET_SDL
    #include "../../system/sdl/net/SDLNetwork.h"
#endif
#ifdef NET_OFF
    #include "../../system/misc/net/DUMMYNetwork.h"
#endif

class ONetwork : public INetwork
{
    public:
    ONetwork() {}
    ~ONetwork() {}

    bool CreateInterface();
    /** Create a network interface to talk on */

    bool DestroyInterface();
    /** Destroy a network interface */

    bool UpdateInterface();
    /** Update the network interface */

    private:
    #ifdef NET_BSD
        BSDNetwork      NetworkObj;
    #endif
    #ifdef NET_WIN
        WINNetwork      NetworkObj;
    #endif
    #ifdef NET_SDL
        SDLNetwork      NetworkObj;
    #endif
    #ifdef NET_OFF
        DUMMYNetwork    NetworkObj;
    #endif
};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

