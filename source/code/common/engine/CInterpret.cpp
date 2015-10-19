/** -------------------------------------------------------------------------------
// \file CInterpret.cpp
// \brief nterpretor Code
//
// File Maintainer - Stuckie
//
// CREDITS     : Based on Dr Henry Fortuna's PS2 Game Framework Code
// =============================================================================== */


/// System Includes
#include "../../arch.h"		            //!< Include Arch dependant info
#include "../debug/CDebug.h"		    //!< Include debug functions
#include "CInterpret.h"			        //!< Include the gameClass info

CInterpret::CInterpret( void )
{
}

CInterpret::~CInterpret( void )
{
}


bool CInterpret::Start( )
{
    SGZLogger.warn("SGZEngine Launched.\n");
    runStatus = true;
    SGZLogger.debug("Starting up SGZInterpretor!\n");

    ServerObject = new OServer;
    if(!ServerObject->CreateInterface())
    {
        SGZLogger.warn("Error Creating our Server Interface\n");
        return false;
    }

    ClientObject = new OClient;
    if(!ClientObject->CreateInterface())
    {
        SGZLogger.warn("Error Creating Our Client Interface\n");
        return false;
    }

    ScriptObject = new OScript;
    if(!ScriptObject->CreateInterface())
    {
        SGZLogger.warn("Error Starting Scripting Interface\n");
        return false;
    }

    if(!ScriptObject->LoadConfigScript())
    {
        FirstRun();
        return false;
    }

    SGZLogger.debug("SGZInterpretor Start Code Complete\n");

	return true;
}

void CInterpret::Loop()

{
    if(!ScriptObject->UpdateScripts())
    {
        SGZLogger.warn("Script Failed to Update! BAIL\n");
        Quit();
    }
    /** we do nothing more, script handles it all */
}

void CInterpret::Stop( void )
{
    SGZLogger.debug("SGZInterpretor Stopping...\n");
    if(ClientObject)
    {
        SGZLogger.debug("Bringing down Client Object\n");
        ClientObject->DestroyInterface();
        ClientObject=NULL;
    }

    if(ServerObject)
    {
        SGZLogger.debug("Bringing down Server Object\n");
        ServerObject->DestroyInterface();
        ServerObject=NULL;
    }

    if(ScriptObject)
    {
        SGZLogger.debug("Bringing down Script Object\n");
        ScriptObject->DestroyInterface();
        ScriptObject=NULL;
    }

    SGZLogger.debug("Removing remaining Events\n");

    SListIterator<IEvent*> EventListITR = EventList.GetIterator();

    EventListITR.Start();
    while (EventListITR.Valid())
    {
        EventList.Remove(EventListITR);
        EventListITR.Forth();
    }

    runStatus = false;
    SGZLogger.debug("SGZInterpretor Stopped Successfully\n");
    SGZLogger.warn("SGZEngine Closed.\n");
}

void CInterpret::FirstRun( void )
{
    SGZLogger.warn("Config was Mangled/Non-existant.\nGenerating Default Config.\n");
    ScriptObject->SaveConfigScript("640:480:32:\"SGZEngine\":data/scripts/engine.sgz:main:");
    ScriptObject->LoadConfigScript();
}

bool CInterpret::AddEvent( IEvent *Event )
{
    EventList.Append(Event);
    return true;
}

void CInterpret::NextEvent( void )
{
    SListIterator<IEvent*> EventListITR = EventList.GetIterator();
    for( EventListITR.Start(); EventListITR.Valid(); EventListITR.Forth() )
    {
        if(EventListITR.Item()->doEvent())
            EventListITR.Item()->handled(true);
    }
    CleanEvents();
}

void CInterpret::CleanEvents( void )
{
    SListIterator<IEvent*> EventListITR = EventList.GetIterator();
    for( EventListITR.Start(); EventListITR.Valid(); EventListITR.Forth() )
    {
        if(EventListITR.Item()->handled(false))
            EventList.Remove(EventListITR);
    }
}

bool CInterpret::UpdateInterfaces ( void )
{
    NextEvent();

    if(ServerObject)
        if(!ServerObject->UpdateServer())
            return false;

    if(ClientObject)
        if(!ClientObject->UpdateClient())
            return false;

    return true;
}

CInterpret Interpretor;

/** Changelog for this file:

    ------- 23rd November 2007
    Added the Configuration routines

    ------- 22nd November 2007
    Added the Event Management stuff

    ------- 20th November 2007

    First revision of this file
    -- Stuckie

*/
