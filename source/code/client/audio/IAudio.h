/** -------------------------------------------------------------------------------
* \file IAudio.h
* \brief The Audio Interface
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#ifndef _IAUDIO_H_
#define _IAUDIO_H_

#include <string>

class IAudio
{
    public:
    virtual ~IAudio() {}

    virtual bool CreateInterface(void) = 0;
    /** Create a client interface to talk on */

    virtual bool DestroyInterface(void) = 0;
    /** Destroy a client interface */

    virtual bool UpdateAudio(void) = 0;
    /** Update/Poll Audio where applicable */

    virtual bool LoadSFXFile( std::string Filename, std::string SFXName ) = 0;
    virtual bool LoadMUSFile( std::string Filename, std::string MUSName ) = 0;
    /** Load a file to play */

    virtual bool RemoveMUS( std::string MUSName ) = 0;
    virtual bool RemoveSFX( std::string SFXName ) = 0;
    /** Remove file from List */

    virtual int PlaySFX(std::string SFXName, int loops = 0, int channel = -1) = 0;
    virtual bool PlayMUS(std::string MUSName, int loops = 0 ) = 0;
    /** Play loaded file */

    virtual int FadeInSFX(std::string SFXName, int time, int loops = 0, int channel = -1) = 0;
    virtual bool FadeInMUS(std::string MUSName, int time, int loops = 0) = 0;
    /** Fade in loaded file */

    virtual bool FadeOutCHAN( int channel, int time) = 0;
    virtual bool FadeOutMUS( int time ) = 0;
    /** Fade Out loaded file */

    virtual bool StopMUS(void) = 0;
    virtual bool StopCHAN(int channel) = 0;
    /** Stop Playing */

    virtual bool PauseMUS(void) = 0;
    virtual bool PauseCHAN(int channel) = 0;
    /** Pause the stream */

    virtual bool ResumeMUS(void) = 0;
    virtual bool ResumeCHAN(int channel) = 0;
    /** Resume the stream */

    virtual bool RewindMUS(void) = 0;
    virtual bool SetMUSPOS(double position) = 0;
    /** Rewind/Fast Forward Music */

    virtual bool SetVolumeMUS(int volume) = 0;
    virtual bool SetVolumeSFX(std::string SFXName, int volume) = 0;
    /** Adjust Volumes */

    virtual int CHANPlaying(int channel) = 0;
    virtual bool MUSPlaying(void) = 0;
    /** What's playing */

    virtual bool SetChannels(int channels) = 0;
    /** Set amount of SFX Channels */

    virtual bool SetPanning(int channel, int left, int right) = 0;
    virtual bool SetDistance(int channel, int distance) = 0;
    virtual bool SetPosition(int channel, int angle, int distance) = 0;
    virtual bool SetReverseStereo(int channel, bool flip) = 0;
    /** Some Effects */

    virtual bool CreateGROUP(int num, std::string name) = 0;
    virtual bool ReserveCHANS(int num) = 0;
    virtual bool GroupCHAN(int chan, std::string name) = 0;
    virtual bool GroupCHANS(int from, int to, std::string name) = 0;
    virtual int CountGROUP(std::string name) = 0;
    virtual int CHANinGROUP(std::string name) = 0;
    virtual int OldestGROUP(std::string name) = 0;
    virtual int NewestGROUP(std::string name) = 0;
    virtual bool FadeGROUP(std::string name, int time) = 0;
    virtual bool HaltGROUP(std::string name) = 0;
    virtual bool RemoveGROUP(std::string name) = 0;


};


#endif

/** Changelog for this file:
    -------- 20th November 2007

    First revision of this file.

    -- Stuckie

*/

