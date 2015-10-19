/** -------------------------------------------------------------------------------
* \file INetwork.h
* \brief The Network Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

/**
    The Network Interface is an interesting object as it's meant to deal with both Client and Server calls.
    It will closely relate to the Event Interface, in that it has a couple of lists to deal with everything.
    This interface is the only thing that knows where the Server and Client is.

    So how is the networking done between Players?
    We do the same sortof thing as Torque does - we link the Servers up to let them do their own simulation and keep in check.
*/

#ifndef _INETWORK_H_
#define _INETWORK_H_

class INetwork
{
    public:
    virtual ~INetwork() {}

    virtual bool CreateInterface() = 0;
    /** Create a network interface to talk on */

    virtual bool DestroyInterface() = 0;
    /** Destroy a network interface */

    virtual bool UpdateInterface() = 0;
    /** Update the Interface */

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

