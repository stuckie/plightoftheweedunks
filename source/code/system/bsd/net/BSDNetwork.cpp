/** -------------------------------------------------------------------------------
* \file BSDNetwork.cpp
* \brief The BSD Network Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#include "BSDNetwork.h"
#ifdef NET_BSD
bool BSDNetwork::CreateInterface()
{
    /** Create a network interface to talk on */
    PacketDelim = "|";                                      //!< This is our Packet Delimiter
    AUXSocket = 1;                                          //!< This is our AUXSocket

    SGZLogger.debug("Initialising The Network Interface...");

    /// Let's open up a new Server TCP Socket
    if ((Socket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
        /// We have an error!
        SGZLogger.debug("We can't create a Server TCP Socket, bail!\n");
        return 1;
    }

    /// Set the Server Socket options up
    if (setsockopt(Socket, SOL_SOCKET, SO_REUSEADDR, &AUXSocket, sizeof(int)) == -1)
    {
        /// We have an error!
        SGZLogger.debug("We can't open the TCPSocket to accept multiple connections, bail!\n");
        return 1;
    }

    /// That's us, Init stuff all done!
    SGZLogger.debug("complete!\n");

    return true;
}

bool BSDNetwork::DestroyInterface()
{
    /** Destroy a network interface */

    SGZLogger.debug("Shutting down our Network Interface ...\n");

    /// Close the Server's Socket
    close(Socket);

    return true;
}

bool BSDNetwork::UpdateInterface()
{
    /** Update the Interface */
    return true;
}

bool BSDNetwork::Bind(const int Port)
{
    /// Now we setup the Server Address struct.
    LocalAddress.sin_family = AF_INET;                     //!< Host Byte Order
    LocalAddress.sin_addr.s_addr = INADDR_ANY;             //!< Automatically fill in the server's IP
    LocalAddress.sin_port = htons(Port);                   //!< Setup our Port number using short network byte order
    memset(LocalAddress.sin_zero, '\0',                    //!< Now we're filling up the zero address with, surprisingly,
            sizeof LocalAddress.sin_zero);                 /*** a zero end... basically padding the struct out a bit.
                                                            *    The reason we do this is to stop the compiler doing it...
                                                            *    We need to actually KNOW the size of it!
                                                            ***************************************************************/

    /// Bind the socket open and ready for receiving data
    if (bind(Socket, (struct sockaddr *)&LocalAddress, sizeof LocalAddress) == -1)
    {
        /// We have an error!
        SGZLogger.debug("We can't open the TCPSocket, bail!\n");
        return -1;
    }

    return 0;
}
#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/
