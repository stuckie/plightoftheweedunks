/** -------------------------------------------------------------------------------
* \file CPacket.cpp
* \brief The Game's Packet Structures
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

/**
    This file contains the Packet Manager whos job it is to convert between stream and packet data.

    Just makes it easier for the Client/Server to do it's job, and abstracts the Networking Code
    as far away as possible.

    ... and can I just say OMFG how much of a bastard was this to code?
    strcpy and c++ strings do not mix
    hell it doesn't even like dealing with char* !!
    But I tamed the damn thing -- Stuckie - 6th April 2007
*/

/// Global Includes for ALL!
#include "../../arch.h"                     //!< Include the Architecture settings
#include "../debug/debug.h"                 //!< Include the Debug Functions
#include "CPackets.h"                       //!< Include this system's header file
#include <string>

CPacket_Manager::CPacket_Manager()
{
    /// Constructor
}

CPacket_Manager::~CPacket_Manager()
{
    /// Destructor
}

std::string CPacket_Manager::CreateNetworkStream( CPacket Packet )
{
    std::string temp;
    std::string Buffer;

    SGZLogger.debug("Clearing Buffer\n");
    Buffer.clear();

    SGZLogger.debug("Checking Packet Type\n");
    if(Packet.type==PACKID_KEEPALIVE)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "keepalive");
        Buffer.insert(Buffer.length(), temp);
    }

    else if(Packet.type==PACKID_CREATE_ENTITY)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%f:", Packet.x);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%f:", Packet.y);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%f:", Packet.z);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%s:", Packet.Name.c_str());
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d", Packet.entity_type);
        Buffer.insert(Buffer.length(), temp);
    }

    else if(Packet.type==PACKID_DESTROY_ENTITY)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%s", Packet.Name.c_str());
        Buffer.insert(Buffer.length(), temp);
    }

    else if(Packet.type==PACKID_MOVE_ENTITY)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%s", Packet.Name.c_str());
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%f", Packet.forwardSpeed);
        Buffer.insert(Buffer.length(), temp);
    }

    else if(Packet.type==PACKID_STOP_ENTITY)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%s", Packet.Name.c_str());
        Buffer.insert(Buffer.length(), temp);
    }

    else if(Packet.type==PACKID_ROTATECW_ENTITY)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%s", Packet.Name.c_str());
        Buffer.insert(Buffer.length(), temp);

        /*sprintf(temp, "%f", Packet.rotateAngle);
        Buffer.insert(Buffer.length(), temp);*/
    }

    else if(Packet.type==PACKID_ROTATECCW_ENTITY)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%s", Packet.Name.c_str());
        Buffer.insert(Buffer.length(), temp);

        /*sprintf(temp, "%f", Packet.rotateAngle);
        Buffer.insert(Buffer.length(), temp);*/
    }

    else if(Packet.type==PACKID_LOGIN)
    {
        SGZLogger.debug("Login Packet Detected\n");
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);
        SGZLogger.debug("Packet ID Inserted\n");

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);
        SGZLogger.debug("Packet Type Inserted\n");

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);
        SGZLogger.debug("Packet PlayerID Inserted\n");

//        sprintf(temp, "%x:", Packet.sender.host);
//        Buffer.insert(Buffer.length(), temp);
//        SGZLogger.debug("Packet Host Inserted\n");

        sprintf(temp, "6870:");//, Packet.sender.port);
        Buffer.insert(Buffer.length(), temp);
        SGZLogger.debug("Packet Port Inserted\n");

        sprintf(temp, "Bob");//, Packet.Name.c_str());
        Buffer.insert(Buffer.length(), temp);
        SGZLogger.debug("Packet Built\n");
    }

    else if(Packet.type==PACKID_CHAT)
    {
        sprintf(temp, "%d:", Packet.id);
        Buffer.insert(0, temp);

        sprintf(temp, "%d:", Packet.type);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%d:", Packet.playerid);
        Buffer.insert(Buffer.length(), temp);

        sprintf(temp, "%s", Packet.Chat.c_str());
        Buffer.insert(Buffer.length(), temp);
    }

    else
        SGZLogger.debug("WTF? NULL PACKET DEFINED!!!\n");

    return Buffer;
}

CPacket* CPacket_Manager::CreatePacketData ( std::string Stream )
{
    const char delimiters[] = ":";
    char *token, *cp;
    CPacket *Packet;
    Packet = new CPacket;

    SGZLogger.debug("String copied\n");
    cp = strdup (Stream.c_str());                  /** store a writable copy of the C-String
                                                        reason for this is that token has the habit
                                                        of mangling the original stream.
                                                        If we only feed it the copy of the string,
                                                        we still retain the original incase we need it.

                                                        WE don't, but it's good practice, and might need it later...
                                                    */

    token = strtok (cp, delimiters);                /** PACKET ID */
    SGZLogger.debug("grabbed packet id token\n");
    if(token==NULL)
    {
        Packet->id=-1;
        Packet->type=0;
        Packet->playerid=-1;
        return Packet;
    } else Packet->id = atoi(token);

    token = strtok (NULL, delimiters);              /** PACKET TYPE */
    if(token==NULL)
    {
        Packet->id=-1;
        Packet->type=0;
        Packet->playerid=-1;
        return Packet;
    } else Packet->type = atoi(token);

    token = strtok (NULL, delimiters);              /** PACKET PLAYERID */
    if(token==NULL)
    {
        Packet->id=-1;
        Packet->type=0;
        Packet->playerid=-1;
        return Packet;
    } else Packet->playerid = atoi(token);

    if (Packet->type==PACKID_KEEPALIVE)
    {
        token = strtok (NULL, delimiters);          /** "keepalive" */
    }
    else if (Packet->type==PACKID_CREATE_ENTITY)
    {
        token = strtok (NULL, delimiters);          /** Position X */
        Packet->x = atof (token);

        token = strtok (NULL, delimiters);          /** Position Y */
        Packet->y = atof (token);

        token = strtok (NULL, delimiters);          /** Position Z */
        Packet->z = atof (token);

        token = strtok (NULL, delimiters);          /** Entity Name */
        Packet->Name.insert(0, token);

        token = strtok (NULL, delimiters);          /** Entity Type */
        Packet->entity_type = atoi (token);
    }
    else if (Packet->type==PACKID_CHAT)
    {
        token = strtok (NULL, delimiters);          /** Chat Message */
        Packet->Chat.insert(0, token);
    }
    else if (Packet->type==PACKID_LOGIN)            /** Client LogIn */
    {
//        token = strtok (NULL, delimiters);          /** IPaddress Host */
//        Packet->sender.host = atoi (token);

//        token = strtok (NULL, delimiters);          /** IPaddress Port */
//        Packet->sender.port = atoi (token);

        token = strtok (NULL, delimiters);
        Packet->Name.insert(0, token);
    }

    return Packet;
}

/** Changelog for this file:
    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    This file was only really started a few days ago and has been in major flux since then.
    This has used everything from char strings to using strcpy and memcpy, to sprintf, to bashing C++ strings manually, before
    eventually figuring out that the above code works.
    Messing about with it other than to add new packet types would be a VERY bad idea.
    LEAVE IT ALONE! it was a nightmare to do and has taken about a week to get right!
    -- Stuckie

*/
