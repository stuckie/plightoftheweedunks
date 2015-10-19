/** -----------------------------------------------------------------------------
* \file IEvent.h                                                                  *
* \brief The Event Interface                                                      *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Event Interface is literally used as a generic struct for all events.
*/

#ifndef _IEVENT_H_
#define _IEVENT_H_

#include "CDebug.h"
#include <string>

class IEvent
{
    public:
    virtual ~IEvent() {}

    virtual bool handled( bool ) = 0;
    /** If we have already been handled (incase the list hasn't been cleared yet) */

    virtual bool doEvent() const = 0;
    /** The only thing we really care about is doing an event */

    virtual int eventType() const = 0;
    /** Tell us what type of event this is */

    virtual int eventNum() const = 0;
    /** Tell us what event number this is */

};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/


