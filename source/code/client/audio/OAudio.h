/** -------------------------------------------------------------------------------
* \file OAudio.h
* \brief The Audio Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#ifndef _OAUDIO_H_
#define _OAUDIO_H_

#include "IAudio.h"
#include "arch.h"

#ifdef SND_SDL
#include "SDLAudio.h"
#endif

#ifdef SND_MIKMOD
#include "MMAudio.h"
#endif

#ifdef SND_DIRECTX
#include "DXAudio.h"
#endif

#ifdef SND_OPENAL
#include "ALAudio.h"
#endif

#ifdef PLAT_PS2LINUX
#include "../../system/ps2linux/audio/PS2Audio.h"
#endif

class OAudio : IAudio
{
    public:
    OAudio() {}
    ~OAudio() {}

    bool CreateInterface(void);
    /** Create a client interface to talk on */

    bool DestroyInterface(void);
    /** Destroy a client interface */

    bool UpdateAudio(void);
    /** Update/Poll Audio where applicable */

    bool LoadSFXFile( std::string Filename, std::string SFXName );
    bool LoadMUSFile( std::string Filename, std::string MUSName );
    /** Load a file to play */

    bool RemoveMUS( std::string MUSName );
    bool RemoveSFX( std::string SFXName );
    /** Remove file from List */

    int PlaySFX( std::string SFXName, int loops = 0, int channels = -1 );
    bool PlayMUS( std::string MUSName, int loops = 0 );
    /** Play file */

    int FadeInSFX(std::string SFXName, int time, int loops = 0, int channel = -1);
    bool FadeInMUS(std::string MUSName, int time, int loops = 0);
    /** Fade in loaded file */

    bool FadeOutCHAN( int channel, int time);
    bool FadeOutMUS( int time );
    /** Fade Out loaded file */

    bool StopMUS(void);
    bool StopCHAN(int channel);
    /** Stop Playing */

    bool PauseMUS(void);
    bool PauseCHAN(int channel);
    /** Pause the file */

    bool ResumeMUS(void);
    bool ResumeCHAN(int channel);
    /** Resume the stream */

    bool RewindMUS(void);
    bool SetMUSPOS(double position);
    /** Rewind/Fast Forward Music */

    bool SetVolumeMUS(int volume);
    bool SetVolumeSFX(std::string SFXName, int volume);
    /** Adjust Volumes */

    int CHANPlaying(int channel);
    bool MUSPlaying(void);
    /** What's playing */

    bool SetChannels(int channels);
    /** Set Audio Channels */

    bool SetPanning(int channel, int left, int right);
    bool SetDistance(int channel, int distance);
    bool SetPosition(int channel, int angle, int distance);
    bool SetReverseStereo(int channel, bool flip);
    /** Some Effects */

    bool CreateGROUP(int num, std::string name);
    bool ReserveCHANS(int num);
    bool GroupCHAN(int chan, std::string name);
    bool GroupCHANS(int from, int to, std::string name);
    int CountGROUP(std::string name);
    int CHANinGROUP(std::string name);
    int OldestGROUP(std::string name);
    int NewestGROUP(std::string name);
    bool FadeGROUP(std::string name, int time);
    bool HaltGROUP(std::string name);
    bool RemoveGROUP(std::string name);


    private:

    #ifdef SND_SDL
        SDLAudio    AudioObject;
    #endif

    #ifdef SND_MIKMOD
        MMAudio    AudioObject;
    #endif

    #ifdef SND_DIRECTX
        DXAudio     AudioObject;
    #endif

    #ifdef SND_OPENAL
        ALAudio     AudioObject;
    #endif

    #ifdef PLAT_PS2LINUX
        PS2Audio    AudioObject;
    #endif

};

#endif
