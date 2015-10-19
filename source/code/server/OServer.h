/** -----------------------------------------------------------------------------
* \file OServer.h                                                                 *
* \brief The Server Object                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Server Interface is a link to the Local Game Server and Networked Server
*/

#ifndef _OSERVER_H_
#define _OSERVER_H_

#include "IServer.h"
#include "CDebug.h"
#include "GameServer.h"
#include "NetworkServer.h"

class OServer : public IServer
{
    public:

    OServer() {}
    ~OServer() {}

    bool CreateInterface(void);
    /** Create a script interface */

    bool DestroyInterface(void);
    /** Destroy a script interface */

    bool UpdateServer(void);
    /** Update the server interface */

    bool CreateHostServer(void);
    /** Create a Host Server */

    GameServer* World() { return GameWorld; };

    private:
    GameServer* GameWorld;
    NetworkServer* HostServer;

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/
