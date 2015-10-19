#ifndef __NETWORKSERVER_H_
#define __NETWORKSERVER_H_

#include "IServer.h"

class NetworkServer : public IServer
{
    public:
    NetworkServer() {};
    ~NetworkServer() {};

    bool CreateInterface(void);
    bool UpdateServer(void);
    bool DestroyInterface(void);
    bool Activate(void);

    private:
};

#endif
