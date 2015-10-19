#include "AI.h"
#include <math.h>
#include "utMath.h"

void AIClass::setWeedunkState(const int _weedunk)
{
    mWeedunks[_weedunk].state = WEEDUNK_IDLE;       // if not idle this will be set latter
    float* dist = new float[mWaypoints.size()];     // stores the distance to each waypoint, all squared

    for (unsigned int waypointCnt = 0; waypointCnt < mWaypoints.size(); waypointCnt++)
    {
        float yDif = mWeedunks[_weedunk].pos.y - mWaypoints[waypointCnt].pos.y - mWeedunkY;
        float xDif = mWeedunks[_weedunk].pos.x - mWaypoints[waypointCnt].pos.x;   // get distance to waypoint
        float zDif = mWeedunks[_weedunk].pos.z - mWaypoints[waypointCnt].pos.z;
        dist[waypointCnt] = xDif*xDif + zDif*zDif;

        if (yDif < 1.0f && yDif > -1.0f)        //weedunks can't jump :), might need a little tweeking
        {
            // within range, doesn't have weedunk, weedunk is of correct type, then its at work
            if (dist[waypointCnt] < mWaypointSize && !mWaypoints[waypointCnt].hasWeedunk &&
                    (mWaypoints[waypointCnt].type == 1 || mWaypoints[waypointCnt].type == mWeedunks[_weedunk].type))
            {
                // weedunk is at waypoint
                mWaypoints[waypointCnt].hasWeedunk = true;
                mWaypoints[waypointCnt].idleCnt = 0;
                mWeedunks[_weedunk].state = WEEDUNK_WORKING;
                mWeedunks[_weedunk].idleCnt = 0;
                mWeedunks[_weedunk].dir = SGZVECTOR();
                mWeedunks[_weedunk].rot = mWaypoints[waypointCnt].rot;
                return;                                     // weedunk is working, nothing else to be done
            }
        }
    }

    float minDist = mMaxDistToWalk+1.0f;

    int closestWaypoint = -1;
    for (unsigned int cnt = 0; cnt < mWaypoints.size(); cnt++)  // find the closest waypoint
    {
        if (minDist > dist[cnt] && !mWaypoints[cnt].hasWeedunk &&
        (mWaypoints[cnt].type == 1 || mWaypoints[cnt].type == mWeedunks[_weedunk].type))
        {
            minDist = dist[cnt];
            closestWaypoint = cnt;
        }
    }

    if (minDist < mMaxDistToWalk && closestWaypoint >= 0)   // is there a waypoint within range
    {
        mWeedunks[_weedunk].state = WEEDUNK_WALKING;      // walk to waypoint
        mWeedunks[_weedunk].idleCnt = 0;

        float m = sqrt(minDist);    // get the normalized vector to the waypoint, used to walk toward waypoint
        mWeedunks[_weedunk].dir.x = (mWaypoints[closestWaypoint].pos.x - mWeedunks[_weedunk].pos.x)/m;
        mWeedunks[_weedunk].dir.z = (mWaypoints[closestWaypoint].pos.z - mWeedunks[_weedunk].pos.z)/m;
    }
    else if (mWeedunks[_weedunk].idleCnt > mIdleDanceTime)
    {
        mWeedunks[_weedunk].state = WEEDUNK_DANCING;
    }
    else if (mWeedunks[_weedunk].state == WEEDUNK_IDLE)
    {
        if (mWeedunks[_weedunk].idleCnt%mIdleChangeDir == 0)
        {
            float x = random.Random()-0.5f;      // get a random dirrection to walk in, normalized of course :p
            float z = random.Random()-0.5f;
            float m = sqrt(x*x + z*z);
            x/=m;
            z/=m;
            mWeedunks[_weedunk].dir.x = x;
            mWeedunks[_weedunk].dir.z = z;
        }
    }

    mWeedunks[_weedunk].rot = radToDeg(atan2(mWeedunks[_weedunk].dir.z, mWeedunks[_weedunk].dir.x))-90.0f;

    delete[] dist;
}
