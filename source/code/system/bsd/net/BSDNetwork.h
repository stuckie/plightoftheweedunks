/** -------------------------------------------------------------------------------
* \file BSDNetwork.h
* \brief The BSD Network Interface
*
* File Maintainer - Stuckie
*
* Credits - Somewhat based on the CUDPSocket class by Henry Fortuna
*
* ===============================================================================
*/

#ifndef _BSDNETWORK_H_
#define _BSDNETWORK_H_

#include "../../../arch.h"
#ifdef NET_BSD
#include "../../../common/network/INetwork.h"           //!< Network Interface Information
#include "../../../common/debug/CDebug.h"               //!< Debug Information
#include "../../../common/engine/OEvent.h"              //!< Event Information

#include <sys/types.h>                                  //!< Networking Header File
#include <sys/socket.h>                                 //!< Another Networking Header File
#include <netinet/in.h>                                 //!< Yep, it's a Networking Header file
#include <arpa/inet.h>                                  //!< More Networking Header Goodness

class BSDNetwork : public INetwork
{
    public:
    BSDNetwork() {}
    ~BSDNetwork() {}

    bool CreateInterface();
    /** Create a network interface to talk on */

    bool DestroyInterface();
    /** Destroy a network interface */

    bool UpdateInterface();
    /** Update the network interface */

    bool MakeNonBlocking(void);
	/** Make the Socket a non-blocking socket */

	bool Bind(const int Port);
	/** Bind the Socket to a Port number */

	int Receive(char * Buffer);
	/** Get us to receive some data */

	int Send(char * Buffer);
	/** Send some data! */

	bool SetDestinationAddress(char * IP, const int Port);
	/** Set our Destination */

	sockaddr_in GetDestinationAddress(void);
	/** Check our Destination Address */

    private:

    int Socket;                                         //!< The Socket we will be communicting on
    int AUXSocket;                                      //!< This is really so we can use the same socket for sending and receiving in TCP

    struct sockaddr_in LocalAddress;                    //!< Our Address struct
    struct sockaddr_in RemoteAddress;                   //!< Their Address struct
    socklen_t AddressLength;                            //!< Size of the Address

    char PacketBuffer[512];                             //!< Our Packet Buffer for receiving data (no more than 512bytes)
    int PacketSize;                                     //!< The actual size of the packet
    char *PacketDelim;                                  //!< Our Packet Delimiter;
};

#endif
#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/
