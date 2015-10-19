#include "WINNetwork.h"

bool WINNetwork::CreateInterface()
{
    SGZLogger.debug("WinSock Interface Created\n");
    return true;
}

bool WINNetwork::DestroyInterface()
{
    SGZLogger.debug("WinSock Interface Destroyed\n");
    return true;
}

bool WINNetwork::UpdateInterface()
{
    return true;
}

bool StartUpInterface( int Port, int Mode )
{
    SGZLogger.debug("WinSock Interface Started\n");
    return true;
}
