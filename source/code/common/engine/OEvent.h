/** -----------------------------------------------------------------------------
* \file OEvent.h                                                                  *
* \brief The Event Objects                                                        *
*                                                                                 *
* File Maintainer - Stuckie                                                       *
*                                                                                 *
* =============================================================================== */

/**
    The Event Interface is literally used as a generic struct for all events.
*/

#ifndef _OEVENT_H_
#define _OEVENT_H_

#include "IEvent.h"

class QuitEvent : public IEvent
{
    public:
    QuitEvent() { viewed = false; }
    ~QuitEvent() {}

    bool handled( bool done )
        {   if(done)
                viewed = done;
            return viewed; }
    /** If we have already been handled (incase the list hasn't been cleared yet) */

    bool doEvent() const;
    /** The only thing we really care about is doing an event */

    int eventType() const
        { return type; }
    /** Tell us what type of event this is */

    int eventNum() const
        { return number; }
    /** Tell us what event number this is */

    private:
    int number;
    int type;
    bool viewed;
};

class KeyEvent : public IEvent
{
    public:
    KeyEvent() { viewed = false; }
    ~KeyEvent() {}

    bool handled( bool done )
        {   if(done)
                viewed = done;
            return viewed; }
    /** If we have already been handled (incase the list hasn't been cleared yet) */

    bool doEvent() const;
    /** The only thing we really care about is doing an event */

    int eventType() const
        { return type; }
    /** Tell us what type of event this is */

    int eventNum() const
        { return number; }
    /** Tell us what event number this is */

    private:
    int number;
    int type;
    bool viewed;

    uint8_t buttons;
};

class MouseEvent : public IEvent
{
    public:
    MouseEvent() { viewed = false; }
    ~MouseEvent() {}

    bool handled( bool done )
        {   if(done)
                viewed = done;
            return viewed; }
    /** If we have already been handled (incase the list hasn't been cleared yet) */

    bool doEvent() const;
    /** The only thing we really care about is doing an event */

    void setInfo( int X, int Y, int butn, int relx = 0, int rely = 0 )
    { mouseX = X; mouseY = Y; button = butn; relX = relx; relY = rely; }

    int eventType() const
        { return type; }
    /** Tell us what type of event this is */

    int eventNum() const
        { return number; }
    /** Tell us what event number this is */

    private:
    int number;
    int type;
    bool viewed;

    int mouseX,
        mouseY,
        relX,
        relY;

    int button;
};

class WindowEvent : public IEvent
{
    public:
    WindowEvent() { viewed = false; }
    ~WindowEvent() {}

    bool handled( bool done )
        {   if(done)
                viewed = done;
            return viewed; }
    /** If we have already been handled (incase the list hasn't been cleared yet) */

    bool doEvent() const;
    /** The only thing we really care about is doing an event */

    int eventType() const
        { return type; }
    /** Tell us what type of event this is */

    int eventNum() const
        { return number; }
    /** Tell us what event number this is */

    void setWindowParams( std::string Name, int Width, int Height, int BPP );
    /** Set up the Window */

    void setFullScreen( bool set )
    {   fullscreen = set; }
    /** Set Fullscreen */

    private:
    int number;
    int type;
    bool viewed;

    int WindowWidth,
        WindowHeight,
        WindowBPP;

    bool fullscreen;

    std::string WindowName;
};

class FullScreenEvent : public IEvent
{
    public:
    FullScreenEvent() { viewed = false; }
    ~FullScreenEvent() {}

    bool handled( bool done )
        {   if(done)
                viewed = done;
            return viewed; }
    /** If we have already been handled (incase the list hasn't been cleared yet) */

    bool doEvent() const;
    /** The only thing we really care about is doing an event */

    int eventType() const
        { return type; }
    /** Tell us what type of event this is */

    int eventNum() const
        { return number; }
    /** Tell us what event number this is */

    void setFullScreen( bool set )
    {   fullscreen = set; }
    /** Set Fullscreen */

    private:
    bool fullscreen;
    bool viewed;
    int type,
        number;
};

#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

