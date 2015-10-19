/** -----------------------------------------------------------------------------
* \file OServer.cpp                                                               *
* \brief The Server Object                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */


#include "OServer.h"

bool OServer::CreateInterface(void)
{
    /** Create a script interface */
    GameWorld = new GameServer;
    GameWorld->CreateInterface();
    SGZLogger.debug("Server Interface Created.\n");

    /**Create a Host Server */
    HostServer = new NetworkServer;
    HostServer->CreateInterface();
    SGZLogger.debug("Host Server Created.\n");
    return true;
}

bool OServer::CreateHostServer(void)
{
    /**Create a Host Server */
    HostServer->Activate();
    return true;
}

bool OServer::DestroyInterface(void)
{
    /** Destroy a script interface */
    SGZLogger.debug("Server Interface Destroyed.\n");
    return true;
}

bool OServer::UpdateServer(void)
{
    /** Update the server interface */
    if(GameWorld)
        GameWorld->UpdateServer();
    if(HostServer)
        HostServer->UpdateServer();

    return true;
}

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

