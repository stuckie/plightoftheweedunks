/** -------------------------------------------------------------------------------
* \file WINNetwork.h
* \brief The WIN Network Interface
*
* File Maintainer - Stuckie
*
* Credits - Somewhat based on the CUDPSocket class by Henry Fortuna
*
* ===============================================================================
*/

#ifndef _WINNETWORK_H_
#define _WINNETWORK_H_

typedef int socklen_t;                                  //!< Windows doesn't have a typedef for socket length normally

#include "../../../common/network/INetwork.h"           //!< Network Interface Information
#include "../../../common/debug/CDebug.h"               //!< Debug Information
#include "../../../common/engine/OEvent.h"              //!< Event Information

#include <winsock2.h>                                   //!< The all important winsock header

class WINNetwork : public INetwork
{
    public:
    WINNetwork() {}
    ~WINNetwork() {}

    bool CreateInterface();
    /** Create a network interface to talk on */

    bool DestroyInterface();
    /** Destroy a network interface */

    bool UpdateInterface();
    /** Update the network interface */

    bool StartUpInterface( int Port, int Mode );
    /** Start the interface up properly */

	int MakeNonBlocking(void);
	/** Make the Socket a non-blocking socket */

	int Bind(const int Port);
	/** Bind the Socket to a Port number */

	int Receive(char * Buffer);
	/** Get us to receive some data */

	int Send(char * Buffer);
	/** Send some data! */

	void SetDestinationAddress(char * IP, const int Port);
	/** Set our Destination */

	sockaddr_in GetDestinationAddress(void);
	/** Check our Destination Address */

    private:

    SOCKET Socket;                      //!< Our Socket we will be sending/receiving on

	socklen_t AddressLength;            //!< Size of our Socket
	struct sockaddr_in  LocalAddress,   //!< A struct to hold our local address details
                        RemoteAddress;  //!< And another one for the remote address

    char PacketBuffer[512];             //!< Our Packet Buffer for receiving data (no more than 512bytes)
    int PacketSize;                     //!< The actual size of the packet
    char *PacketDelim;                  //!< Our Packet Delimiter;

    WSADATA WSData;                     //!< Winsock's Data
};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

