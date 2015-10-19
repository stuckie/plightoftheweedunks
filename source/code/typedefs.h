/** --------------------------------------------------------------------------------
* \file typedef.h
* \brief Controls some pre-defined variables and their inner values
*
* File Maintainer - Stuckie
*
* -----------------------------------------------------------------------------------
*
* In an attempt to try and make the code as cross-platform as possible,
* the code contains platform specific areas that are masked depending on defines.
*
* This enables support for other platforms to be added without mangling existing ones.
*
* Examples being the recent addition of DS and PSP support in the main tree.
*
* Also means that while testing non-graphic code via PC, I can just comment out
* the following defines and it will compile without a problem.
*
* This file lists a set of pre-defined variables and controls their content depending upon
* the architecture underneath - which you've set in arch.h
*
* -------------------------------------------------------------------------------------
*
* Please ensure that ARCH.H is included in EVERY FILE in order to access platform info!
*
* -------------------------------------------------------------------------------------
*
*/

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_
#include "arch.h"
//#include "math.h"
//#include "CInterpret.h"

#ifdef REND_SDL
#include "SDL/SDL.h"
#endif

struct SGZCOLOUR
{
#if defined(PLAT_DS) || defined(PLAT_GBA) || defined(PLAT_GP32) || defined(PLAT_GP2X)
    int r, g, b;
#elif defined (REND_SDL)
    Uint32 r, g, b;
#else
    float r, g, b;
#endif
};

struct SGZVECTOR
{
    SGZVECTOR(void)
    {
        x = y = z= 0;
    };
#if defined(PLAT_DS) || defined(PLAT_GBA) || defined(PLAT_GP32) || defined(PLAT_GP2X)
    SGZVECTOR(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    };
    int x, y, z;
#else
    SGZVECTOR(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    };
    float x, y, z;
#endif
};

#if defined(PLAT_DS) || defined(PLAT_GBA) || defined(PLAT_GP32) || defined(PLAT_GP2X)
typedef int SGZSCALER;
#else
typedef float SGZSCALER;
#endif

#if defined(PLAT_DS) || defined(PLAT_GBA) || defined(PLAT_GP32) || defined(PLAT_GP2X)
typedef int SGZVECTORVAL;
#else
typedef float SGZVECTORVAL;
#endif

#if defined(PLAT_DS) || defined(PLAT_GBA) || defined(PLAT_GP32) || defined(PLAT_GP2X)
typedef int SGZCOLOURVAL;
#elif defined(REND_SDL)
typedef Uint32 SGZCOLOURVAL;
#else
typedef float SGZCOLOURVAL;
#endif

#define SGZ_FRAME_LOCK (50.0)
#define PS2_ON_WINDOWS_AXIS_MAX (32768)

typedef enum
{
    NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST
}ECompassPoint;

#endif

#ifndef ODEWorld
#define ODEWorld (SGZInterpret.accessServer()->World()->accessPhysics())
#endif

#ifndef AIWorld
#define AIWorld (SGZInterpret.accessServer()->World()->accessAI())
#endif
