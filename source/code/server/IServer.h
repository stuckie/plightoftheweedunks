/** -------------------------------------------------------------------------------
* \file IServer.h
* \brief The Server Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

/**
    We use a Server interface as there's several types of Servers we can create.
    For example, Remote/Local Server as well as Listen/Dedicated Server
*/

#ifndef _ISERVER_H_
#define _ISERVER_H_

class IServer
{
    public:
    virtual ~IServer() {}

    virtual bool CreateInterface(void) = 0;
    /** Create a Server interface to talk on */

    virtual bool DestroyInterface(void) = 0;
    /** Destroy a Server interface */

    virtual bool UpdateServer(void) = 0;
    /** Update the Server interface */

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

