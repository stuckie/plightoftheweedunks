/** -------------------------------------------------------------------------------
* \file IClient.h
* \brief The Client Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

/**
    We use a Client interface as there's several types of Clients we can create.
    For example, we can use a client for "demo record/playback", AI, or whatever else.
*/

#ifndef _ICLIENT_H_
#define _ICLIENT_H_

#include <string>

class IClient
{
    public:
    virtual ~IClient() {}

    virtual bool CreateInterface(void) = 0;
    /** Create a client interface to talk on */

    virtual bool DestroyInterface(void) = 0;
    /** Destroy a client interface */

    virtual bool UpdateClient(void) = 0;
    /** Update This Client */

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

