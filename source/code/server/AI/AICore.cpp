#include "AI.h"
#include "CInterpret.h"

void AIClass::update(void)
{
    for (unsigned int waypointCnt=0; waypointCnt < mWaypoints.size(); waypointCnt++)
    {
        mWaypoints[waypointCnt].hasWeedunk = false;     // set all waypoint to not have weedunk, all that have one will be set latter
        mWaypoints[waypointCnt].idleCnt ++;
    }

    // test if weedunk is close to waypoint, and then set states acordingly
    for (unsigned int weedunkCnt = 0; weedunkCnt < mWeedunks.size(); weedunkCnt++)
    {
        if (mWeedunks[weedunkCnt].alive)
        {
            mWeedunks[weedunkCnt].pos = ODEWorld->getDynamicPos(mWeedunks[weedunkCnt].odeID); // get the possition of the weedunk
            mWeedunks[weedunkCnt].idleCnt++;

            setWeedunkState(weedunkCnt);

            moveWeedunk(weedunkCnt);
        }
    }
}

void AIClass::reset(void)
{
    mWeedunks.clear();
    mWaypoints.clear();
}

int AIClass::addWeedunk(const int _weedunnkType, const int _odeID)
{
    aiWeedunk tmpWeedunk;               // create the weedunk
    tmpWeedunk.alive = true;
    tmpWeedunk.type = _weedunnkType;
    tmpWeedunk.odeID = _odeID;
    tmpWeedunk.idleCnt = -1;            // -1 cause's the weedunk to get a dirrection instantly

    for (unsigned int cnt=0; cnt< mWeedunks.size(); cnt++)
    {
        if (mWeedunks[cnt].alive == false)
        {
            mWeedunks[cnt] = tmpWeedunk;
            return cnt;
        }

    }

    mWeedunks.push_back(tmpWeedunk);    // add the weedunk
    return mWeedunks.size()-1;          // return the id of the weedunk
}

int AIClass::addWayPoint(const int _waypointType, const char* _name, const SGZVECTOR _pos, const float _rot)
{
    aiWaypoint tmpWaypoint;                 // create the waypoint
    tmpWaypoint.type = _waypointType;
    tmpWaypoint.name = _name;
    tmpWaypoint.pos = _pos;
    tmpWaypoint.rot = _rot;

    mWaypoints.push_back(tmpWaypoint);      // add the waypoint

    return mWaypoints.size()-1;             // return the id of the waypoint
}

void AIClass::removeWeedunk(const int _weedunkID)
{
    mWeedunks[_weedunkID].alive = false;
}

void AIClass::removeWaypoint(const int _waypointID)
{
    mWaypoints.erase(mWaypoints.begin() + _waypointID);
}

