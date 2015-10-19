/**  an ode to live with the worlds of physic and collisions collide to allow the weedunk plight to be completed **/

#ifndef _ODECORE_H_
#define _ODECORE_H_

#include "ode.h"
#include "typedefs.h"
#include <vector>
#include <string>
#include "utMath.h"

//#define SHOW_PHYSICS_PROPS

using namespace std;

typedef std::string EodeOA;

typedef enum
{
    ODE_NONE=0, ODE_SOLID, ODE_ANIMATED, ODE_DYNAMIC
} EodeObjectList;

struct ODEobjectDetails
{
    ODEobjectDetails() {};
    ODEobjectDetails(int _id, EodeOA _oa, EodeObjectList _list, dGeomID _geom)
    {
        id=_id;
        oa=_oa;
        list=_list;
        geom=_geom;
    };

    int id;
    EodeOA oa;
    EodeObjectList list;
    dGeomID geom;
};

struct jumpRayDataStruct
{
    dGeomID geom;       // the id of the rays geom
    bool hasHit;        // if the ray hit something
    float hitDepth;     // the depth the ray hit at
    dGeomID ignore;     // the players capsual
};

class odeWorld
{
public:
    bool init(void);    // calls setup functions, varibles are set in constructors but nothing else is
    bool kill(void);    // kills parts and returns if successfull, destructor will destroy everything though

    // collision callback functions
    static void staticCollisionCallback (void *_pData, const dGeomID _o1, const dGeomID _o2);
    void collisionCallback (const dGeomID _o1, const dGeomID _o2);
    static void staticRayCollisionCallback (void *_pData, const dGeomID _o1, const dGeomID _o2);
    void rayCollisionCallback (const dGeomID _o1, const dGeomID _o2);

    // called to move the physics world forward one frame, returns false on failure
    bool runFrame(void);

    // finds the list and other details about a genom
    ODEobjectDetails geomInList(const dGeomID _in);

    // create objects for the collisions in the physics world
    int createStaticPlaneGeom(const dReal _a, const dReal _b, const dReal _c, const dReal _d, const EodeOA _odeeo);               // create static solid plane geometry
    int createStaticBoxGeom(const SGZVECTOR _size, const SGZVECTOR _pos, const SGZVECTOR _rot,  const EodeOA _odeeo);       // create static solid box geometry
    int createStaticSphereGeom(const dReal _r, const SGZVECTOR _pos,  const EodeOA _odeeo);                           // create static solid sphere geometry

    int createMovingPlaneGeom(const dReal _a, const dReal _b, const dReal _c, const dReal _d, const EodeOA _odeeo);               // create moving solid plane geometry
    int createMovingBoxGeom(const SGZVECTOR _size, const SGZVECTOR _pos, const SGZVECTOR _rot, const EodeOA _odeeo);        // create moving solid box geometry
    int createMovingSphereGeom(const dReal _r, const SGZVECTOR _pos,  const EodeOA _odeeo);                           // create moving solid sphere geometry

    int createDynamicBox(const SGZVECTOR _size, const SGZVECTOR _pos, const SGZVECTOR _rot, const dReal _mass, const EodeOA _odeeo);             // create moving solid box geometry
    int createDynamicSphere(const dReal _r, const SGZVECTOR _pos, const dReal _mass, const EodeOA _odeeo);  // create moving solid sphere geometry
    int createDynamicCapsule(const float _r, const float _h, const SGZVECTOR _pos,  const dReal _mass, const EodeOA _odeeo);

    // used by lua proxies
    void hit(void);
    void bounce(const float _friction, const float _bounce, const float _minV);
    void applyHitForce(const SGZVECTOR _f);
    void applyHitForce(const int _notHit, const float _f);
    void setGravity(const float _g);
    void applyForce(const int _index, const SGZVECTOR _f);
    void applyDampingForceHorizontally(const int _index, const float _damp);
    void removeForces(const int _index);

    void moveMoving(const int _index, const SGZVECTOR _delta);
    void setMovingPos(const int _index, const SGZVECTOR _pos);
    void setMovingRot(const int _index, const float _x, const float _y, const float _z);

    void setDynamicPos(const int _index, const SGZVECTOR _pos);
    void setDynamicRot(const int _index, const float _x, const float _y, const float _z);

    void enableDynamicObject(const int _index, const bool _active);
    void setRayPos(const int _index, const SGZVECTOR _pos);

    SGZVECTOR getMovingPos(const int _index);
    SGZVECTOR getDynamicPos(const int _index);
    SGZVECTOR getVelocity(const int _index);
    SGZVECTOR getMovingSize(const int _index);
    SGZVECTOR getDynamicSize(const int _index);
    int findRayIndex(const dGeomID _in);

    const dReal* getQuaternion(const int _index);
    Quaternion getMovingQuaternion(const int _index);

    SGZVECTOR getOffset(const int _index);
    void setOffset(const int _index, const SGZVECTOR _offset);

    bool killDynamic(const int _index);
    bool killMoving(const int _index);
    int KillerHit(const int _notKill);
    SGZVECTOR GetPointOfContact(void);

    void turnOffGravityFor(const int _index);
    void turnOnGravityFor(const int _index);
    int createJumpRay(const float _l, const SGZVECTOR _pos, const dGeomID _ignore);
    bool hasJumpRayHit(const int _index, float &_depth);
    void setPause(const bool _pause);
    dGeomID getDynamicGeomID(const int _index);
    void addNoJumpMaterial(const string _mat);

    void killVVel(const int _index);
    void hitKillVVel(void);
    int getDynamicID(void);
    void setStepsPerFrame(const int _steps);
    float limitVertVel(const int _index, const float _v);
    SGZVECTOR getOriginalPos(const int _index);
protected:
    // the worlds of the physics enviroment
    dWorldID mPhysicsWorld;
    dSpaceID mjumpRayWorld;
    dSpaceID mDynamicGeomSpace;
    dSpaceID mStaticGeomSpace;

    bool mPaused;

    // used to store the joints of collisions
    dJointGroupID mCollisionJointGroup;

    // geoms, used in the collision world
    vector<dGeomID> mStaticGeoms;   // the objects in the world which do not move, ie static geometry
    vector<EodeOA> mStaticOAs;
    vector<dGeomID> mMovingGeoms;   // the objects in the world which are part of the world but do move but not under
    vector<EodeOA> mMovingOAs;
    vector<dGeomID> mObjectGeoms;   // the objects in the world, will be two for each as one in each world
    vector<EodeOA> mObjectOAs;

    // has the objects which move around the world effected by the physics, ie players, weedunks and falling objects
    vector<dBodyID> mObjectBodys;   // the objects of the world
    vector<dMass*> mObjectMass;     // pointers to the world

    vector<SGZVECTOR> mOffSet;

    vector<SGZVECTOR> mMovingSize;
    vector<SGZVECTOR> mDynamicSize;

    vector<SGZVECTOR> mMovingOriginalPos;

    vector<int> mDynamicsToKill;
    vector<int> mMovingsToKill;
    vector<unsigned int> mDeadDynamics;

    vector<jumpRayDataStruct> mJumpRays;

    dContact mLastContact;
    ODEobjectDetails mLastObjColishion[2];

    vector<string> mNoJumpMaterials;
    vector<unsigned int> mDynamicsToReuse;

    int mPhysicsStepsPerFrame;
};

#endif // _ODECORE_H_
