/** -------------------------------------------------------------------------------
* \file CPacket.h
* \brief The Game's Packet Structures
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

/**
    This file contains all of the Packet Structures, or in this case, Classes.
    Reason why they are classes is so that we can create a linked list of the CPacket type,
    And with everything derived from CPacket, we can add any type of packet we like to the
    list for the Client/Server to parse.

    These are STRUCTURED packets... the Interpretor's job is to build and parse these from
    and to the native char strings that are fed over the network.

    Just makes it easier for the Client/Server to do it's job, and abstracts the Networking Code
    as far away as possible.
*/

#ifndef _CPACKETS_H_
#define _CPACKETS_H_

/// Global Includes for ALL!
#include "../../arch.h"                     //!< Include the Architecture settings
#include "../debug/CDebug.h"                 //!< Include the Debug Functions

#include <string>                           //!< We send strings of information, not actual struct/class stuff
#include <stddef.h>                         //!< Include a bunch of standard definitions
#include <stdio.h>                          //!< Include the Standard Input/Output library
#include <stdlib.h>                         //!< Include the standard C library ( for sprintf and things )

/// Common Includes

/// Arch Dependant
#ifdef NET_SDL
#include "SDL/SDL_net.h"
#endif

/// Packet Defines
#define PACKID_KEEPALIVE (0)
#define PACKID_CREATE_ENTITY (1)
#define PACKID_DESTROY_ENTITY (2)
#define PACKID_MOVE_ENTITY (3)
#define PACKID_STOP_ENTITY (4)
#define PACKID_ROTATECW_ENTITY (5)
#define PACKID_ROTATECCW_ENTITY (6)
#define PACKID_LOGIN (7)
#define PACKID_CHAT (8)

class CPacket                                   //!< Internal Packet Structure
{
    public:
        int id;                                 //!< ID of this packet
        int type;                               //!< Type of this packet, check Packet Type list above class def
        int playerid;                           //!< Player ID that this came from ( 0 for server )

        float x, y, z;                          //!< X,Y,Z Co-Ords of where to create entity
        std::string Name;                       //!< Name of the Entity to reference later
        int entity_type;                        //!< Type of Entity to Create

        float forwardSpeed;                     //!< Velocity to move forward

        float rotateAngle;                      //!< Angle to rotate

        std::string AnimName;                   //!< Name of the Animation to Start

        std::string Chat;                       //!< Chat message

    #ifdef NET_SDL
        IPaddress sender;                       //!< IPaddress of where this packet came from
    #endif

};

class CPacket_Manager
{
    public:
        CPacket_Manager();                              //!< Packet Manager Constructor
        ~CPacket_Manager();                             //!< Packet Manager Destructor

        std::string CreateNetworkStream ( CPacket Packet );   //!< Create a Network Stream from Packet Data
        CPacket* CreatePacketData ( std::string Stream );     //!< Create Packet Data from a Network Stream
};

#endif

/** Changelog for this file:
    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    This file was only really started a few days ago and has been in major flux since then.
    Most major changes include changing use of char strings to ogre::strings back to C++ strings.
    The defines should probably be included somewhere else (such as arch.h perhaps? EVERYTHING includes that by default)
    This code should actually be pretty cross platform as it has no depandancies other than on C++ functions.
    -- Stuckie

*/

