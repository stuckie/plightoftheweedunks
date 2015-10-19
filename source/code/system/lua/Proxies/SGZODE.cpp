#include "SGZODE.h"
#include "../../../arch.h"
#include "utMath.h"

int SGZode_Proxy::Bounce(lua_State *Lua)    // used to make colliding objects bounce off each other
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=3 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0)
    {
        SGZLogger.warn("the values ode:Bounce where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->bounce((float)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 2));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::Hit(lua_State *Lua)    // used to make colliding objects bounce off each other
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=0)
    {
        SGZLogger.warn("the values ode:Hit where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->hit();

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::KillerHit(lua_State *Lua)
{
    int tmp = 0;
    /// if inputs are not valid exit
    if (lua_gettop(Lua)==0)
    {
        tmp = ODEWorld->KillerHit(-1);
    }
    else if (lua_gettop(Lua)==1 && lua_isnumber(Lua, 1))
    {
        tmp = ODEWorld->KillerHit((int)lua_tonumber(Lua, 1));
    }
    else
    {
        SGZLogger.warn("the values ode:KillerHit where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, tmp);

    return 1;
}

int SGZode_Proxy::HitKillVVel(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)==0)
    {
        ODEWorld->hitKillVVel();
    }
    else
    {
        SGZLogger.warn("the values ode:HitKillVVel where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::ApplyHitForce(lua_State *Lua)    // used to make colliding objects bounce off each other
{
    /// if inputs are not valid exit
    if (!(lua_gettop(Lua)==3 && lua_isnumber(Lua, 1) && lua_isnumber(Lua, 2) && lua_isnumber(Lua, 3)) &&
            !(lua_gettop(Lua)==2 && lua_isnumber(Lua, 1) && lua_isnumber(Lua, 2)))
    {
        SGZLogger.warn("the values ode:ApplyHitForce where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    if (lua_gettop(Lua)==3)
    {
        ODEWorld->applyHitForce(SGZVECTOR((float)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3)));
    }
    else if (lua_gettop(Lua)==2)
    {
        ODEWorld->applyHitForce((int)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2));
    }
    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::SetGravity(lua_State *Lua) //used to set the gravity
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("the values ode:bounce where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->setGravity((float)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::applyForce(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)==4 && lua_isnumber(Lua, 1)!=0 && lua_isnumber(Lua, 2)!=0 && lua_isnumber(Lua, 3)!=0 && lua_isnumber(Lua, 4)!=0)
    {
        ODEWorld->applyForce((int)lua_tonumber(Lua, 1), SGZVECTOR((float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3),(float)lua_tonumber(Lua, 4)));
    }
    else if (lua_gettop(Lua)==3 && lua_isnumber(Lua, 1)!=0 && lua_isnumber(Lua, 2)!=0 && lua_isnumber(Lua, 3)!=0)
    {
        float angle = (float)lua_tonumber(Lua, 2);
        float f = (float)lua_tonumber(Lua, 3);
        ODEWorld->applyForce((int)lua_tonumber(Lua, 1), SGZVECTOR( -sin(degToRad(angle))*f,0, cos(degToRad(angle))*f));
    }
    else
    {
        SGZLogger.warn("the values ode:ApplyForce where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::applyForceWithRot(lua_State *Lua)
{
    if (lua_gettop(Lua)==4 && lua_isnumber(Lua, 1)!=0 && lua_isnumber(Lua, 2)!=0 && lua_isnumber(Lua, 3)!=0 && lua_isnumber(Lua, 4)!=0)
    {
        int node = (int)lua_tonumber(Lua, 1);
        float hAngle = (float)lua_tonumber(Lua, 2);
        float vAngle = (float)lua_tonumber(Lua, 3);
        float f = (float)lua_tonumber(Lua, 4);
        float fh = 0.0f, fv = 0.0f;

        fh = f*cos(degToRad(vAngle));
        fv = f*cos(degToRad(vAngle-90.0f));


        ODEWorld->applyForce(node, SGZVECTOR( -sin(degToRad(hAngle))*fh, fv, cos(degToRad(hAngle))*fh));
    }
    else
    {
        SGZLogger.warn("the values ode:ApplyForceWithRot where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::applyDampingForceHorizontally(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=2 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0)
    {
        SGZLogger.warn("the values ode:applyDampingForceHorizontally where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->applyDampingForceHorizontally((int)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::removeForces(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("the values ode:removeForces where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->removeForces((int)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::setMovingPos(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("the values ode:setMovingPos where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->setMovingPos((int)lua_tonumber(Lua, 1), SGZVECTOR((float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3),(float)lua_tonumber(Lua, 4)));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::setMovingRot(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("the values ode:setMovingRot where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->setMovingRot((int)lua_tonumber(Lua, 1), degToRad((float)lua_tonumber(Lua, 2)), degToRad((float)lua_tonumber(Lua, 3)), degToRad((float)lua_tonumber(Lua, 4)));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::setDynamicPos(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("the values ode:setDynamicPos where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->setDynamicPos((int)lua_tonumber(Lua, 1), SGZVECTOR((float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3),(float)lua_tonumber(Lua, 4)));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::setDynamicRot(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("the values ode:setDynamicRot where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->setDynamicRot((int)lua_tonumber(Lua, 1), degToRad((float)lua_tonumber(Lua, 2)), degToRad((float)lua_tonumber(Lua, 3)), degToRad((float)lua_tonumber(Lua, 4)));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::getDynamicPos(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("the values ode:getDynamicPos where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    SGZVECTOR tmp = ODEWorld->getDynamicPos((int)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, tmp.x);
    lua_pushnumber(Lua, tmp.y);
    lua_pushnumber(Lua, tmp.z);

    return 3;
}

int SGZode_Proxy::getVelocity(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("the values ode:getVelocity where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    SGZVECTOR tmp = ODEWorld->getVelocity((int)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, tmp.x);
    lua_pushnumber(Lua, tmp.y);
    lua_pushnumber(Lua, tmp.z);

    return 3;
}

int SGZode_Proxy::enableDynamicObject(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=2 || lua_isnumber(Lua, 1)==0 || lua_isboolean(Lua, 2)==0)
    {
        SGZLogger.warn("the values ode:enableDynamicObject where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->enableDynamicObject((int)lua_tonumber(Lua, 1), (bool)lua_toboolean(Lua, 2));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::killEverything(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=0)
    {
        SGZLogger.warn("the values ode:killEverything where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->kill();
    ODEWorld->init();

    return 0;
}

int SGZode_Proxy::killDynamic(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1) == 0)
    {
        SGZLogger.warn("the values ode:killDynamic where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->killDynamic((int)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }
    return 0;
}

int SGZode_Proxy::killMoving(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1) == 0)
    {
        SGZLogger.warn("the values ode:killDynamic where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->killMoving((int)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }
    return 0;
}

int  SGZode_Proxy::createDynamicBox(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=11 ||
            lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 ||
            lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isnumber(Lua, 6)==0 ||
            lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isnumber(Lua, 6)==0 ||
            lua_isnumber(Lua, 10)==0 || lua_isstring(Lua, 11)==0)
    {
        SGZLogger.warn("the values ode:createDynamicBox where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    int index = ODEWorld->createDynamicBox(
                    SGZVECTOR((float)lua_tonumber(Lua, 1),(float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3)),
                    SGZVECTOR((float)lua_tonumber(Lua, 4),(float)lua_tonumber(Lua, 5),(float)lua_tonumber(Lua, 6)),
                    SGZVECTOR(degToRad((float)lua_tonumber(Lua, 7)),degToRad((float)lua_tonumber(Lua, 8)),degToRad((float)lua_tonumber(Lua, 9))),
                    (float)lua_tonumber(Lua, 10),lua_tostring(Lua, 11));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, index);

    return 1;
}

int  SGZode_Proxy::createDynamicSphere(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=6 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isstring(Lua, 6)==0)
    {
        SGZLogger.warn("the values ode:createDynamicSphere where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    int index = ODEWorld->createDynamicSphere(
                    (float)lua_tonumber(Lua, 1),
                    SGZVECTOR((float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3),(float)lua_tonumber(Lua, 4)),
                    (float)lua_tonumber(Lua, 5),lua_tostring(Lua, 6));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, index);

    return 1;
}

int  SGZode_Proxy::createDynamicCapsule(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=7 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isnumber(Lua, 6)==0 || lua_isstring(Lua, 7)==0)
    {
        SGZLogger.warn("the values ode:createDynamicCapsule where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    int index = ODEWorld->createDynamicCapsule( (float)lua_tonumber(Lua, 1),(float)lua_tonumber(Lua, 2),
                SGZVECTOR((float)lua_tonumber(Lua, 3),(float)lua_tonumber(Lua, 4),(float)lua_tonumber(Lua, 5)),
                (float)lua_tonumber(Lua, 6),lua_tostring(Lua, 7));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, index);

    return 1;
}

int SGZode_Proxy::createMovingBox(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=10 ||
            lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 ||
            lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isnumber(Lua, 6)==0 ||
            lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isnumber(Lua, 6)==0 ||
            lua_isstring(Lua, 10)==0)
    {
        SGZLogger.warn("the values ode:createMovingBox where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    int index = ODEWorld->createMovingBoxGeom(
                    SGZVECTOR((float)lua_tonumber(Lua, 1),(float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3)),
                    SGZVECTOR((float)lua_tonumber(Lua, 4),(float)lua_tonumber(Lua, 5),(float)lua_tonumber(Lua, 6)),
                    SGZVECTOR(degToRad((float)lua_tonumber(Lua, 7)),degToRad((float)lua_tonumber(Lua, 8)),degToRad((float)lua_tonumber(Lua, 9))),
                    lua_tostring(Lua, 10));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, index);

    return 1;
}

int SGZode_Proxy::createStaticBox(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=10 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isnumber(Lua, 6)==0 || lua_isnumber(Lua, 7)==0 || lua_isnumber(Lua, 8)==0 || lua_isnumber(Lua, 9)==0)
    {
        SGZLogger.warn("the values ode:createStaticBox where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    int index = ODEWorld->createStaticBoxGeom(
                    SGZVECTOR((float)lua_tonumber(Lua, 1),(float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3)),
                    SGZVECTOR((float)lua_tonumber(Lua, 4),(float)lua_tonumber(Lua, 5),(float)lua_tonumber(Lua, 6)),
                    SGZVECTOR(degToRad((float)lua_tonumber(Lua, 7)),degToRad((float)lua_tonumber(Lua, 8)),degToRad((float)lua_tonumber(Lua, 9))),
                    lua_tostring(Lua, 10));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, index);

    return 1;
}

int SGZode_Proxy::createStaticPlane(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=5 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("the values ode:createStaticPlane where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    int index = ODEWorld->createStaticPlaneGeom((float)lua_tonumber(Lua, 1),(float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3),(float)lua_tonumber(Lua, 4),
                lua_tostring(Lua, 5));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, index);

    return 1;
}

int SGZode_Proxy::moveMoving(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("the values ode:moveMoving where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    SGZVECTOR tmp = ODEWorld->getMovingPos((int)lua_tonumber(Lua, 1));
    tmp.x += (float)lua_tonumber(Lua, 1);
    tmp.y += (float)lua_tonumber(Lua, 2);
    tmp.z += (float)lua_tonumber(Lua, 3);
    ODEWorld->setMovingPos((int)lua_tonumber(Lua, 1), tmp);

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::jump(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=2 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0)
    {
        SGZLogger.warn("the values ode:jump where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->applyForce((int)lua_tonumber(Lua, 1), SGZVECTOR(0,(float)lua_tonumber(Lua, 2),0));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::setOffset(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=4 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0)
    {
        SGZLogger.warn("the values ode:setOffset where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->setOffset((int)lua_tonumber(Lua, 1), SGZVECTOR((float)lua_tonumber(Lua, 2),(float)lua_tonumber(Lua, 3),(float)lua_tonumber(Lua, 4)));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::ApplyAnalogueControl(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=6 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0 || lua_isnumber(Lua, 3)==0 || lua_isnumber(Lua, 4)==0 || lua_isnumber(Lua, 5)==0 || lua_isstring(Lua, 6)==0)
    {
        SGZLogger.warn("the values ode:setOffset where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    // get data
    int odeHandel = (int)lua_tonumber(Lua, 1);
    float xAxis = ((float)lua_tonumber(Lua, 2))/PS2_ON_WINDOWS_AXIS_MAX;    //normalize the axis values between 0 and 1
    float zAxis = ((float)lua_tonumber(Lua, 3))/PS2_ON_WINDOWS_AXIS_MAX;
    float f = (float)lua_tonumber(Lua,4);
    float deadZone = (float)lua_tonumber(Lua, 5);

    // if both axis are in the deadZones return, is basically saying that its not being used
    if (xAxis<deadZone&&xAxis>-deadZone&&zAxis<deadZone&&zAxis>-deadZone)
    {
        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }

        lua_pushboolean(Lua, false);
        lua_pushnumber(Lua, 0.0f);
        return 2;
    }
    if (xAxis<deadZone&&xAxis>-deadZone)
        xAxis = 0.0f;
    if (zAxis<deadZone&&zAxis>-deadZone)
        zAxis = 0.0f;

    float m = sqrt(xAxis*xAxis+zAxis*zAxis);    // get the magnitude of the axis, used to make sure the force is always the same

    float xForce = (xAxis/m) * f;
    float zForce = (zAxis/m) * f;

    float rot = radToDeg(atan2(-xAxis,zAxis));

    /// TODO fix so not a hack from passing in camera facing direction
    if (strcmp((char*)lua_tostring(Lua, 6),"N") == 0)
    {
        ODEWorld->applyForce(odeHandel, SGZVECTOR(xForce, 0.0f, zForce));
    }
    else if (strcmp((char*)lua_tostring(Lua, 6),"E") == 0)
    {
        ODEWorld->applyForce(odeHandel, SGZVECTOR(-zForce, 0.0f, xForce));
        rot += 90.0f;
    }
    else if (strcmp((char*)lua_tostring(Lua, 6),"S") == 0)
    {
        ODEWorld->applyForce(odeHandel, SGZVECTOR(-xForce, 0.0f, -zForce));
        rot += 180.0f;
    }
    else
    {
        ODEWorld->applyForce(odeHandel, SGZVECTOR(zForce, 0.0f, -xForce));
        rot += 270.0f;
    }

    if (rot>360)
        rot -= 360;

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushboolean(Lua, true);
    lua_pushnumber(Lua, rot);
    return 2;
}

int SGZode_Proxy::TurnOffGravityFor(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("the values ode:TurnOffGravityFor where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->turnOffGravityFor((int)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::TurnOnGravityFor(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=1 || lua_isnumber(Lua, 1)==0)
    {
        SGZLogger.warn("the values ode:TurnOffGravityFor where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    ODEWorld->turnOnGravityFor((int)lua_tonumber(Lua, 1));

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::GetRotationToFace(lua_State *Lua)
{
    /// if inputs are not valid exit
    if (lua_gettop(Lua)!=2 || lua_isnumber(Lua, 1)==0 || lua_isnumber(Lua, 2)==0)
    {
        SGZLogger.warn("the values ode:GetRotationToFace where not correct\n");

        /// clear any messages passed with this
        for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        {
            lua_pop(Lua, cnt);
        }
        return 0;
    }

    SGZVECTOR pos = ODEWorld->getDynamicPos((int)lua_tonumber(Lua, 1));
    SGZVECTOR target = ODEWorld->getDynamicPos((int)lua_tonumber(Lua, 2));
    SGZVECTOR dir;

    dir.x = pos.x - target.x;
    dir.y = pos.y - target.y;
    dir.z = pos.z - target.z;

    float tmp = sqrt(dir.x*dir.x + dir.z*dir.z);
    float rot = radToDeg(atan2(dir.z,dir.x))+90.0;
    float up = radToDeg(atan2(tmp, dir.y))-90.0;

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, rot);
    lua_pushnumber(Lua,  up);

    return 2;
}

int SGZode_Proxy::GetPointOfContact(lua_State *Lua)
{
    SGZVECTOR point;
    /// if inputs are not valid exit
    if (lua_gettop(Lua)==0)
    {
        point = ODEWorld->GetPointOfContact();
    }
    else
    {
        SGZLogger.warn("the values ode:GetPointOfContact where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, point.x);
    lua_pushnumber(Lua, point.y);
    lua_pushnumber(Lua, point.z);

    return 3;
}

int SGZode_Proxy::AddJumpRay(lua_State *Lua)
{
    int index = 0;
    if (lua_gettop(Lua)==5 && lua_isnumber(Lua,1) && lua_isnumber(Lua,2) && lua_isnumber(Lua,3) && lua_isnumber(Lua,4) && lua_isnumber(Lua,5))
    {
        dGeomID tmp = ODEWorld->getDynamicGeomID((int)lua_tonumber(Lua,5));
        index = ODEWorld->createJumpRay((float)lua_tonumber(Lua,1), SGZVECTOR((float)lua_tonumber(Lua,2),(float)lua_tonumber(Lua,3),(float)lua_tonumber(Lua,4)), tmp);
    }
    else
    {
        SGZLogger.warn("the values ode:AddJumpRay where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, index);

    return 1;
}

int SGZode_Proxy::AddNoJumpMaterial(lua_State *Lua)
{
    if (lua_gettop(Lua)==1)
    {
        ODEWorld->addNoJumpMaterial((char*)lua_tostring(Lua,1));
    }
    else
    {
        SGZLogger.warn("the values ode:AddNoJumpMaterial where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::SetJumpRayPos(lua_State *Lua)
{
    if (lua_gettop(Lua)==4 && lua_isnumber(Lua,1) && lua_isnumber(Lua,2) && lua_isnumber(Lua,3) && lua_isnumber(Lua,4))
    {
        ODEWorld->setRayPos((int)lua_tonumber(Lua,1), SGZVECTOR((float)lua_tonumber(Lua,2),(float)lua_tonumber(Lua,3),(float)lua_tonumber(Lua,4)));
    }
    else
    {
        SGZLogger.warn("the values ode:SetJumpRayPos where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }
    return 0;
}

int SGZode_Proxy::HasJumpRayHit(lua_State *Lua)
{
    bool hit = false;
    float depth = 9999.9f;

    if (lua_gettop(Lua)==1 && lua_isnumber(Lua,1))
    {
        hit = ODEWorld->hasJumpRayHit((int)lua_tonumber(Lua,1), depth);
    }
    else
    {
        SGZLogger.warn("the values ode:HasJumpRayHit where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushboolean(Lua, hit);
    lua_pushnumber(Lua, depth);

    return 2;
}

int SGZode_Proxy::Pause(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isboolean(Lua,1))
    {
        ODEWorld->setPause((bool)lua_toboolean(Lua,1));
    }
    else
    {
        SGZLogger.warn("the values ode:Pause where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::SetStepsPerFrame(lua_State *Lua)
{
    if (lua_gettop(Lua)==1 && lua_isnumber(Lua,1))
    {
        ODEWorld->setStepsPerFrame((int)lua_tonumber(Lua,1));
    }
    else
    {
        SGZLogger.warn("the values ode:SetStepsPerFrame where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    return 0;
}

int SGZode_Proxy::LimitVertVel(lua_State *Lua)
{
    float tmp = 0.0f;
    if (lua_gettop(Lua)==2 && lua_isnumber(Lua,1) && lua_isnumber(Lua,2))
    {
        tmp = ODEWorld->limitVertVel((int)lua_tonumber(Lua,1), (float)lua_tonumber(Lua,2));
    }
    else
    {
        SGZLogger.warn("the values ode:LimitVertVel where not correct\n");
    }

    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, tmp);

    return 1;
}

int SGZode_Proxy::GetDynamicID(lua_State *Lua)
{
    /// clear any messages passed with this
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
    {
        lua_pop(Lua, cnt);
    }

    lua_pushnumber(Lua, ODEWorld->getDynamicID());

    return 1;
}
const char SGZode_Proxy::className[] = "SGZODE";
Lunar<SGZode_Proxy>::RegType SGZode_Proxy::methods[] =
{
    {"Bounce", &SGZode_Proxy::Bounce},
    {"Hit", &SGZode_Proxy::Hit},
    {"ApplyHitForce", &SGZode_Proxy::ApplyHitForce},
    {"KillerHit", &SGZode_Proxy::KillerHit},
    {"HitKillVVel", &SGZode_Proxy::HitKillVVel},
    {"GetDynamicID", &SGZode_Proxy::GetDynamicID},

    {"SetGravity", &SGZode_Proxy::SetGravity},

    {"ApplyForce", &SGZode_Proxy::applyForce},
    {"ApplyForceWithRot", &SGZode_Proxy::applyForceWithRot},
    {"ApplyDampingForceHorizontally", &SGZode_Proxy::applyDampingForceHorizontally},
    {"RemoveForces", &SGZode_Proxy::removeForces},

    {"EnableDynamicObject", &SGZode_Proxy::enableDynamicObject},

    {"KillEverything", &SGZode_Proxy::killEverything},
    {"KillDynamic", &SGZode_Proxy::killDynamic},
    {"KillMoving", &SGZode_Proxy::killMoving},

    {"CreateMovingBox", &SGZode_Proxy::createMovingBox},
    {"CreateStaticBox", &SGZode_Proxy::createStaticBox},
    {"CreateStaticPlane", &SGZode_Proxy::createStaticPlane},
    {"CreateDynamicBox", &SGZode_Proxy::createDynamicBox},
    {"CreateDynamicSphere", &SGZode_Proxy::createDynamicSphere},
    {"CreateDynamicCapsule", &SGZode_Proxy::createDynamicCapsule},
    {"SetOffset", &SGZode_Proxy::setOffset},

    {"MoveMoving", &SGZode_Proxy::moveMoving},
    {"SetMovingPos", &SGZode_Proxy::setMovingPos},
    {"SetMovingRot", &SGZode_Proxy::setMovingRot},

    {"SetDynamicPos", &SGZode_Proxy::setDynamicPos},
    {"SetDynamicRot", &SGZode_Proxy::setDynamicRot},

    {"GetDynamicPos", &SGZode_Proxy::getDynamicPos},
    {"GetVelocity", &SGZode_Proxy::getVelocity},

    {"Jump", &SGZode_Proxy::jump},
    {"ApplyAnalogueControl", &SGZode_Proxy::ApplyAnalogueControl},
    {"TurnOffGravityFor", &SGZode_Proxy::TurnOffGravityFor},
    {"TurnOnGravityFor", &SGZode_Proxy::TurnOnGravityFor},

    {"GetRotationToFace", &SGZode_Proxy::GetRotationToFace},

    {"GetPointOfContact", &SGZode_Proxy::GetPointOfContact},

    {"AddJumpRay", &SGZode_Proxy::AddJumpRay},
    {"AddNoJumpMaterial", &SGZode_Proxy::AddNoJumpMaterial},
    {"SetJumpRayPos", &SGZode_Proxy::SetJumpRayPos},
    {"HasJumpRayHit", &SGZode_Proxy::HasJumpRayHit},

    {"Pause", &SGZode_Proxy::Pause},
    {"SetStepsPerFrame", &SGZode_Proxy::SetStepsPerFrame},
    {"LimitVertVel", &SGZode_Proxy::LimitVertVel},
    {0,0}
};
