#ifndef _AI_H_
#define _AI_H_

#include "CRandom.h"
#include "typedefs.h"
#include <vector>
#include <string>

using namespace std;

enum weedunkState { WEEDUNK_FUCKED=0, WEEDUNK_IDLE, WEEDUNK_WORKING, WEEDUNK_WALKING, WEEDUNK_DANCING };      // the states which an AI weedunk can be in

struct aiWeedunk    // data about a weedunk
{
    bool alive;
    int odeID;
    int type;       // must be >= 2
    SGZVECTOR pos;  // updated each frame
    SGZVECTOR dir;  // the dirrection the weedunk is walking in, used when idle
    weedunkState state;
    int idleCnt;    // shows how long the weedunk has been idle
    float rot;
};

struct aiWaypoint
{
    SGZVECTOR pos;
    int type;       // if 1 all weedunks can be at else is only for specific weedunks
    string name;
    bool hasWeedunk;
    int idleCnt;        // shows how long the waypoint hasn't had a weedunk for
    float rot;
};

class AIClass
{
public:
    AIClass(){ random.Randomise();};
    ~AIClass(){};

    void update(void);      // update the AI system

    void reset(void);       // reset the system, deletes everything

    // methods for adding items to the system
    int addWeedunk(const int _weedunnkType, const int _odeID);
    int addWayPoint(const int _waypointType, const char* _name, const SGZVECTOR _pos, const float _rot);

    // methods for removing items from the system
    void removeWeedunk(const int _weedunkID);
    void removeWaypoint(const int _waypointID);

    // methods for interigating the system
    weedunkState getWeedunkState(const int _weedunkID);
    float getWeedunkRot(const int _weedunkID);

    //tweeking stuff
    void setWeedunkMoveForce(const float _f) { mWeedunkMoveForce = _f; };
    void setWaypointSize(const float _s) { mWaypointSize = _s*_s; };
    void setMaxDistToWalk(const float _s) { mMaxDistToWalk = _s*_s; };
    void setIdleDanceTime(const int _t) { mIdleDanceTime = _t; };
    void setIdleChangeDir(const int _t) { mIdleChangeDir = _t; };
    void setWeedunkHeight(const float _h) { mWeedunkY = _h/2; };     // doesn't actually set height but a value used for deciding if weedunks are level

protected:
    // methods for code redability
    void setWeedunkState(const int _weedunk);
    void moveWeedunk(const int _weedunk);

    vector<aiWeedunk> mWeedunks;        // weedunks
    vector<aiWaypoint> mWaypoints;      // waypoints

    // varibles for allowing tweeking
    float mWeedunkMoveForce;            // the force which a weedunk moves with
    float mWaypointSize;                // is squared to speed up calculations
    float mMaxDistToWalk;               // again squared to make calculations faster
    int mIdleDanceTime;                 // the time the weedunk will be idle before dancing
    int mIdleChangeDir;                 // the time that the weedunk will walk in a direction before changing when idle
    float mWeedunkY;                    // used to find if weedunks are level, is half height + 1 to allow for mild bumps etc

    CRandom random;
};

#endif // _AI_H_
