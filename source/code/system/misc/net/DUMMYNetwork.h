#ifndef _DUMMYNETWORK_H_
#define _DUMMYNETWORK_H_

#include "../../../arch.h"
#include "../../../common/network/INetwork.h"

class DUMMYNetwork : public INetwork
{
    public:
    DUMMYNetwork() {}
    ~DUMMYNetwork() {}

    bool CreateInterface() {return true;}
    /** Create a network interface to talk on */

    bool DestroyInterface() {return true;}
    /** Destroy a network interface */

    bool UpdateInterface() {return true;}
    /** Update the network interface */

};

#endif
