/** -------------------------------------------------------------------------------
* \file main.h
* \brief Contains Prototypes for the main.cpp file
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#include "arch.h"                           /** Seeing as sometimes we need a different entry point, we need to know which
                                                architecture we're currently using... damn you WinAPI!!!                */
#ifdef PLAT_PSP
    #include "SDL.h"
    #include "SDL_main.h"
    extern "C" int SDL_main(int nNumArgs,char **ppcArgs);
#endif

/// PROTOTYPE FUNCTIONS
#ifndef REND_WINAPI
    int main ( void );                          //!< Common Entry
#else
#include <windows.h>
    HWND ghwnd;
    void RegisterMyWindow(HINSTANCE hInstance); //!< For registering windows with Windows
    bool InitialiseMyWindow(HINSTANCE hInstance,//!< For Initialising the window
                            int nCmdShow);
    LRESULT CALLBACK WndProc (  HWND hwnd,      //!< Our Windows Message Processor
                                UINT message,
                                WPARAM wParam,
                                LPARAM lParam);
    int WINAPI WinMain (HINSTANCE hInstance,    //!< Not-so-common Main Entry ;)
                        HINSTANCE hPrevInstance,
                        PSTR szCmdLine,
                        int nCmdShow);
#endif


/** Changelog for this file:

    ------- 15th July 2007

    Finally added the WINAPI WinMain call... after much teeth gnashing... still don't like it here ;)

    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    This is still the original revision of this file. Nothing has been changed. -- Stuckie

*/
