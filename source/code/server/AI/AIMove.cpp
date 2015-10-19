#include "AI.h"
#include "CInterpret.h"

void AIClass::moveWeedunk(const int _weedunk)
{
    if (mWeedunks[_weedunk].state == WEEDUNK_WALKING || mWeedunks[_weedunk].state == WEEDUNK_IDLE)
    {
        SGZVECTOR v = ODEWorld->getVelocity(mWeedunks[_weedunk].odeID);
        if (v.y<15 &&v.y>-15)
            ODEWorld->applyForce(mWeedunks[_weedunk].odeID, SGZVECTOR(mWeedunks[_weedunk].dir.x * mWeedunkMoveForce, 0, mWeedunks[_weedunk].dir.z * mWeedunkMoveForce));
    }
}
