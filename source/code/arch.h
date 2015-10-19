/** --------------------------------------------------------------------------------
* \file arch.h
* \brief Just sets the defines as to what we're building for
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
* -------------------------------------------------------------------------------------
*
* Please ensure that ARCH.H is included in EVERY FILE in order to access platform info!
*
* -------------------------------------------------------------------------------------
*
*/

#ifndef ARCH_H
    #define ARCH_H                  //!< Make sure we do NOT include this multiple times

    // PLATFORM DEFINES             //!< What platform we're going for..
    //#define PLAT_GP32             //!< GP32 Handheld -- http://en.wikipedia.org/wiki/GP32 -- Uses devkitARM kit
    //#define PLAT_GP2X             //!< GP2X Handheld -- http://www.gp2x.co.uk -- Uses Open2X kit
    //#define PLAT_GBA              //!< Gameboy Advance -- Using the devkitARM kit
    //#define PLAT_DS               //!< Nintendo DS -- Using the devkitARM kit
    //#define PLAT_GC               //!< Nintendo Gamecube -- Uses the devkitPPC kit
    //#define PLAT_DC               //!< SEGA Dreamcast -- Uses the KallistiOS setup
    //#define PLAT_PSX              //!< PSX Console -- It's a GCC compiler setup again, it's here for fun :)
    //#define PLAT_PS2LINUX         //!< PS2 Console -- Using PS2Linux kit
    //#define PLAT_PS3LINUX         //!< PS3 Console -- Using Linux (YellowDog)
    //#define PLAT_PS2DEV           //!< PS2 Console -- Using PS2DEV Homebrew kit -- http://www.ps2dev.org
    //#define PLAT_PSPDEV           //!< PSP Handheld -- Using PSPDEV Homebrew kit -- http://www.ps2dev.org
    //#define PLAT_PS3DEV           //!< PS3 Console -- Using PS3DEV Homebrew kit -- http://www.ps2dev.org
    //#define PLAT_MACOSX           //!< Mac OS X -- It's BSD based so should get away with Linux code, use XCode and stick to SDL
    //#define PLAT_MACCLASSIC       //!< Mac OS 9< -- Stick to SDL and should be ok.. MPW seems to work with SDL quite happily too
    #define PLAT_PC                 //!< PC -- Remember to pick the OS below!

    /** DEVKIT AVAILABILITY -- Remember, these are homebrew, so some form of using homebrew may be required - flashcart/modchip/etc
    PS2/PSP/PS3 - www.ps2dev.org
    GP2X - http://wiki.open2x.org
    GP32/GBA/DS/Gamecube/PSP - http://www.devkitpro.org
    Dreamcast - http://gamedev.allusion.net/softprj/kos
    PSX - http://www.hitmen-console.org for compiler/assemblers and http://jum.pdroms.de has some info on stuff
    */

    /** API COMPATIBILITY -- To aid your madness of figuring out what works on what
    SDL - GP32, GP2X, Dreamcast, PS2Linux( VERY POORLY ), Windows, Mac OS / X, PSPDEV, DS, Linux
    OpenGL - Windows, Linux, Mac OS / X, PSPDEV ( of sorts ), DS ( of sorts ), probably PS3 too but not looked (think its GL ES)
    OIS - Windows, Linux, Mac OS X
    MikMod - GP2X, Linux, PS2Linux( VERY POORLY )
    OpenAL - Linux, Windows, Mac OS X
    OGRE - Linux, Windows, Mac OS X
    Direct X and WinAPI - Windows
    SPS2 - PS2Linux
    GP32, GP2X, DS, GBA, GC, PSX, PS2DEV, PSPDEV and DC all have their own little APIs too.. which may have flags at a later date

    Shader Support > CG/GLSL - Windows, Linux, Mac OS X | HLSL - Windows
    */

    // ENGINE DEFINE                    //!< These should be taken care of by build targets - these are for make file targets
    //#define SGZ_2D                   //!< Specifically define 2D Support
    //#define SGZ_3D                   //!< Specifically define 3D Support

    // 2D RENDERER DEFINES
    #ifdef SGZ2D
        #define REND_SDL              //!< Render just through SDL -- http://www.libsdl.org -- SGZ2D Default for Desktop Systems
        //#define REND_OPENGL           //!< Render just through OpenGL -- http://www.opengl.org
        //#define REND_SDLGL            //!< Render OpenGL through an SDL window -- SGZ3D Default for Desktop Systems
        //#define REND_DIRECTX          //!< Render just through DirectX
        //#define REND_SDLDX            //!< Render DirectX through an SDL window ;)
        //#define REND_SPS2             //!< Render through SPS2 (PS2 only, this is the 2D optimised version)
        //#define REND_WINAPI           //!< And why, exactly, would you want to use this?
    #endif

    // 3D RENDERER DEFINES
    #ifdef SGZ3D
        //#define REND_OGRE             //!< Render using OGRE -- MUST use IN_OIS
        //#define REND_HORDE              //!< Render using HORDE -- need to set up window yourself
        #define REND_SDLHORDE           //!< Render using HORDE with SDL to back things up
        //#define REND_OPENGL           //!< Render just through OpenGL -- http://www.opengl.org
        //#define REND_SDLGL            //!< Render OpenGL through an SDL window -- SGZ3D Default for Desktop Systems
        //#define REND_DIRECTX          //!< Render just through DirectX
        //#define REND_SDLDX            //!< Render DirectX through an SDL window ;)
        //#define REND_SPS2             //!< Render through SPS2 (PS2 only, 3D optimised)
    #endif

    // SOUND DEFINES                //!< Which sound engine to use, SDL, Mikmod, DirectX
    //#define SND_MIKMOD            //!< Music through MikMod -- GP2X likes this better than SDL for example, no MP3/OGG support though
    //#define SND_DIRECTX           //!< Sound and Music through DirectX
    #define SND_SDL                 //!< Sound and Music through SDL (requires SDL_mixer compiled in)
    //#define SND_OPENAL            //!< Sound and Music through OpenAL
    //#define SND_PS2               //!< "automatically" pulled in via PLAT_PS2 but just for completeness

    // INPUT DEFINES                //!< Which Input Engine to use, SDL, OIS, DirectX
    #define IN_SDL                  //!< Use SDL for Input (requires an SDL-compat renderer as we need the window for events!)
    //#define IN_OIS                //!< Use Open Input System for Input
    //#define IN_DIRECTX            //!< Use DirectX for Input
    //#define IN_WINAPI             //!< Use WinAPI for Input

    // OS DEFINES                   //!< Which Operating System we're compiling for, Win32/64, Linux
    /**   These should be already defined in the project file... use only if not using project file! ie: Makefile */
    //#define OS_WIN32              //!< Yay for Windows needing some extra crap to play nice at times
    //#define OS_WIN64              //!< Placeholder .. may need at some point..
    //#define OS_LINUX              //!< Mainly for OGRE+SDL's different windowing system

    // NETWORKING DEFINES           //!< Which Networking Library we will use
    //#define NET_SDL               //!< Use SDL'S Networking library .. takes care of endian issues ;)
    //#define NET_BSD               //!< Bash the BSD Sockets manually!! rarrr
    //#define NET_WIN               //!< Use WinSock type stuff
    #define NET_OFF                 //!< Turn networking OFF

    // SHADER SUPPORT               //!< Which define for shaders to use
    //#define SHADER_CG             //!< Use CG Shaders
    //#define SHADER_GLSL           //!< Use GLSL Shaders (GSlang)
    //#define SHADER_HLSL           //!< Use HLSL Shaders (FX Shaders) - Windows Only

    // GUI SUPPORT
    //#define GUI_CEGUI             //!< Use CEGUI
    //#define GUI_QT                //!< Use QT for gui stuff
    //#define GUI_MOTIF             //!< Use MOTIF
    //#define GUI_GTK               //!< Use GTK
    #define GUI_SGZ                 //!< Use own gui

    // SCRIPT SUPPORT
    #define SCRIPT_LUA              //!< Use Lua
    //#define SCRIPT_PYTHON         //!< Use Python
    //#define SCRIPT_RUBY           //!< Use Ruby

    // PHYSICS SUPPORT              //!< Which Physics library to use... there are a few multi platform ones
    #define PHYSICS_ODE             //!< ODE - Open Dynamics Engine -- http://www.ode.org
    //#define PHYSICS_SGZ           //!< SGZ Physics .. probably not done and never will be, but would be nice!

    // EXTRAS SUPPORT               //!< Random things to support
    //#define amBX_ON                 //!< Use amBX!
    /** May add more when I have time to even attempt to support them... */


    // ARCH SPECIFIC DEFINES        //!< Any global defines such as the PS2 includes

    #ifdef PLAT_PS2LINUX            //!< PS2Linux Specific Defines -- they're in here cause they're "global" of sorts
        #ifndef _PS2_H              // Including all the PS2 header stuff multiple
            #define _PS2_H          // times will probably be a bad idea, so don't!

            #include <sps2lib.h>
            #include <sps2tags.h>
            #include <sps2util.h>
            #include <sps2regstructs.h>
            #include <assert.h>
            #include <memory.h>
            #include <signal.h>
            #include <time.h>
            #include "system/ps2linux/PS2Defines.h"
            #include "system/ps2linux/ps2maths.h"
            #include "system/ps2linux/ps2matrix4x4.h"
            #include "system/ps2linux/pad.h"
            #include "system/ps2linux/sps2wrap.h"
            #include "system/ps2linux/dma.h"
            #include "system/ps2linux/texture.h"
        #endif
    #endif
#endif

#include "typedefs.h"

/** Changelog for this file:

    ------- 29th April 2008

    Typedefs!
    Due to the multi-platform nature of everything .. some platforms aren't happy with floats, for example .. I've created a typedef
    system that allows me to just call generic values to hold specific things, and change the inner values dependent upon the architecture!

    Not quite sure why I didn't think of this before ....

    ------- 10th February 2008

    More clean up and readded SDLOGRE switch.. reason being that I forgot by default OGRE uses OIS for input.. which is nasty!
    Also deprecated SPS2_2D/3D as the SGZ2D/3D define will set this up automagically!
    Yes, we're combining SGZ2D and SGZ3D now... one engine to rule them all!

    ------- 26th September 2007

    Dropped a few more deprecated things.. OGRE for example takes care of whether it's rendering to a SDL/GLX context itself now.
    Tidied up the file a bit and added a comment block for where to grab dev kits and api info for future reference.

    -------- 12th August 2007

    Networking Engine's getting an overhaul.. dropping HawkNL and having a switch between SDL_Net and straight BSD/WinSock Sockets
    SDL_Net has some of it's own error checking and will do a bit more stuff than what I can do with bashing sockets straight, reason
    why it's still there.

    -------- 30th July 2007

    Seeing as devkitPRO has support for a wide range of things anyway, I defaulted to that for GP32, DS, GC and GBA
    They DO have a PSP setup, but I much prefer the PS2DEV guys one.. not that it matters much as devkitPRO pulls that in anyway!

    -------- 20th July 2007

    Added in support for DS and PSP.. they've got OpenGL-alike 3D APIs so wasn't too difficult to get basic support..
    DS' second CPU is a bugger though, so will require a LOT more work!
    PSPDEV and PS2DEV chains are almost identical, which is nice, meant I could add them both in without much of a problem :)

    -------- 9th April 2007

    Decided to keep a changelog of this file, anyone that adds anything to this file should amend here with what they've done.
    Adding in support for a few things outside of Labyrinth (this is my all-purpose engine after all, I do use it for other things :P

    Consider WinAPI deprecated by SDL.. shouldn't really need to ever use it. The implementation still isn't done yet anyway,
    and I really cannot be arsed with it.
    Option is still there, and there will be a pluggable render path for it should it become a necessity to have it at a later point.
    -- Stuckie
*/
