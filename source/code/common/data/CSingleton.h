/** -------------------------------------------------------------------------------
    \file singleton.h
    \brief Singleton Class

    File Maintainer - Steven "Stuckie" Campbell

    This Singleton Class was shamelessy ripped from Dr Henry Fortuna's PS2 tutorials.

    It has been modified slightly to work with newer versions of GCC by Stuckie.

    ------------------------------------------------------------------------------- */

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <assert.h>

// This class may seem a little strange if you have never seen a
// singleton before. But it is a very useful, and increasingly
// common data structure, particularly in games.

// You can think of a singleton as a nice way to have a "global"
// object, without the hassle of actually making the variable global
// and then externing it all over the place.

// If you derive your class from CSingleton, and then create a single
// instance of the object in the source file, you can then access that
// object from anywhere by calling the GetSingleton method of your class

template <typename T> class CSingleton
{
	// The one and only instance of this class
	static T * ms_Singleton;

public:
	// Sets up the one and only instance
	CSingleton()
	{
		assert(!ms_Singleton);
		//int offset = (T*)1 - (CSingleton<T>*)(T*)1;
		ms_Singleton = (T*)(this);// + offset);
	}

	// Destroys the one and only instance
	~CSingleton()
	{
		assert(ms_Singleton);
		ms_Singleton = 0;
	}

	// Returns the singleton
	static T& GetSingleton()
	{
		assert(ms_Singleton);
		return (*ms_Singleton);
	}

	// Returns a pointer to the singleton
	static T* GetSingletonPtr()
	{
		return ms_Singleton;
	}
};

// This might look a bit confusing, but all it does is for each new singleton type that is created
// it initialises it's static T * ms_Singleton member.
template <typename T> T * CSingleton <T>::ms_Singleton = 0;

#endif

/** Changelog for this file:
    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    The constructor was modified slightly so that it would compile cleanly under Linux with GCC4. -- Stuckie

*/
