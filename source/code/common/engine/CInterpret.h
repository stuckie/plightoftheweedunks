/** -------------------------------------------------------------------------------
// \file CInterpret.h
// \brief This file contains the Engine Interpretor
//
// File Maintainer - Stuckie
//
// =============================================================================== */

#ifndef _CINTERPRET_H_
#define _CINTERPRET_H_

#include "arch.h"                     //!< Any Architecture specific stuff we may need
#include "CSingleton.h"             //!< Singleton Class
#include "CSLinkedlist.h"           //!< Linked List Class
#include "OEvent.h"                         //!< Give us access to the Event Objects
#include "OClient.h"           //!< Give us access to the Client Objects
#include "OServer.h"           //!< Give us access to the Server Objects
#include "OScript.h"              //!< Give us access to the Scripting Objects

class CInterpret : public CSingleton<CInterpret>
{
public:

	CInterpret(void);						//!< CInterpret Constructor
	~CInterpret(void);						//!< CInterpret DeConstructor

	bool Start(void);   				    //!< return CInterpret Start (TRUE|FALSE)
	void Loop(void);					    //!< CInterpret Loop
	void Stop(void);					    //!< CInterpret Stop
	void FirstRun(void);                    //!< Called when no Config Exists yet...

	void NextEvent(void);                   //!< Grab the next event
	bool AddEvent(IEvent* NewEvent);        //!< Add an event to the list
	void CleanEvents(void);                 //!< Clean Event List
	bool UpdateInterfaces(void);            //!< Update the current Interfaces

    OClient *accessClient( void )           //!< Gain access to the Client
        { return ClientObject; }

    OServer *accessServer( void )           //!< Gain access to the Server
        { return ServerObject; }

    OScript *accessScript( void )           //!< Gain access to the Script
        { return ScriptObject; }

	inline bool Running(void)				//!< CInterpret Running (TRUE|FALSE)
		{ return runStatus; }

    inline void Quit(void)                  //!< Quit the engine
        { runStatus = false; }

protected:

	bool runStatus;					        //!< CInterpret runStatus -- (TRUE|FALSE)

private:

    SLinkedList<IEvent*> EventList;         //!< List of Events
	SListIterator<IEvent*> EventListITR;    //!< Iterator to the Event List

    OScript     *ScriptObject;              //!< Handle to our Script Interface
    OClient     *ClientObject;              //!< Handle to our Client Interface
    OServer     *ServerObject;              //!< Handle to our Server Interface

};

#define SGZInterpret CInterpret::GetSingleton() //!< Macro to call this function easily

#endif

/** Changelog for this file:

    ------- 20th November 2007
    First revision of this file.

    -- Stuckie

*/
