/**
// \file CTimer.h
// \brief Timer Class
//
// File Maintainer - Stuckie
//
// Not too sure who wrote this actually, hehe
//
// It's a collaberation between Steven Campbell and Bryan Morgan.
//
*/

#ifndef _CTIMER_H_
#define _CTIMER_H_

#include "arch.h"    //!< Include the architecture information

#ifdef IN_SDL
#include "SDL/SDL.h"    //!< SDL has better time keeping stuff
#else
#include <ctime>       //!< We're going to be hacky with things otherwise
#endif

class CTimer
{
private:
  int startTime;        //!< starting time of the timer
  int baseTime;         //!< base time of the timer (current time)
  bool running;         //!< if the timer is running or not.

public:

/** CTimer Constructor
// resets all variables to 0 or false
*/
  CTimer()
  {
    startTime = 0;
    baseTime = 0;
    running = false;
  }

/** start function
// starts the timer
*/
  void start()
  {
    if (!running)
    {
        #ifdef IN_SDL
            startTime = SDL_GetTicks();
        #else
            startTime = clock();
        #endif

        running = true;
    }
  }

/** stop function
// stops the timer
*/
  void stop()
  {
    if (running)
    {
        #ifdef IN_SDL
        baseTime = baseTime + (SDL_GetTicks() - startTime);
        #else
        baseTime = baseTime + (clock() - startTime);
        #endif

        running = false;
    }
  }

/** reset function
// resets the timer
*/
  void reset()
  {
    startTime = SDL_GetTicks();
    startTime = clock();
    baseTime = 0;
  }

/** stopped function
// returns whether the timer is running or not
*/
  bool stopped()
  {
    return !running;
  }

/** currenttime function
// returns the current time of this timer
*/
  int currenttime()
  {
    if (running)
    {
        #ifdef IN_SDL
        return baseTime + (SDL_GetTicks() - startTime);
        #else
        return baseTime + (clock() - startTime);
        #endif
    }
    else
    {
      return baseTime;
    }
  }
};

#endif

/** Changelog for this file:

    -------- 27th September 2007

    I've probably butchered this pretty well.. attempting rather badly to get it working with and without SDL
    Actually, more of a better idea would be to rip the code out of this and shove it in a CPP file rather than having
        it all in the header file... but I'm lazy :P

    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    This is still the original revision of this file. Nothing has been changed. -- Stuckie

*/
