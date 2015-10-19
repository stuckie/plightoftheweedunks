/** -------------------------------------------------------------------------------
* \file PS2Audio.h
* \brief The PS2 Audio Object
*
* File Maintainer - Stuckie
* Contains code pinched from Dr Henry Fortuna
*
* ===============================================================================
*/

#ifndef _PS2AUDIO_H_
#define _PS2AUDIO_H_

#include "../../../client/audio/IAudio.h"
#include "../../../arch.h"
#include "../../../common/data/CSLinkedlist.h"
#include "../../../common/debug/CDebug.h"

#ifdef PLAT_PS2LINUX

class SoundSample;

class AudioDevice
{
public:
	AudioDevice(const int Which);
	~AudioDevice();

	int Open(const int which);
	void Close(void);
	void HandleAudio(void);
	void SetSoundSample(SoundSample * const Sample);
	int GetFragmentSize(void) const;
	bool silence;

protected:
	int GetFreeFragments(void) const;

	SoundSample * m_Current;
	int m_AudioFD;
	int m_FragmentSize;
	unsigned char * m_Silence;
};

class SoundSample
{
public:
	SoundSample(char * Filename, AudioDevice * const pAD);
	~SoundSample();

	void Load(char * Filename);
	void Reset();
	void Play(void);
	unsigned char * GetNextFragment();

protected:

	AudioDevice * m_pAD;
	unsigned char * m_Stream;
	long m_Location;
	int m_FragSize;
	long m_NumFragments;
	char m_SampleName[32];
};

struct SGZMusic
{
    std::string Name;
    SoundSample *Data;
};

struct SGZSound
{
    std::string Name;
    SoundSample *Data;
};

class PS2Audio : IAudio
{
    public:
    PS2Audio() {}
    ~PS2Audio() {}

    bool CreateInterface(void);
    /** Create a client interface to talk on */

    bool DestroyInterface(void);
    /** Destroy a client interface */

    bool UpdateAudio(void);
    /** Update/Poll Audio where applicable */

    bool LoadSFXFile( std::string Filename, std::string SFXName );
    bool LoadMUSFile( std::string Filename, std::string MUSName );
    /** Load a file to play */

    bool RemoveSFX( std::string SFXName );
    bool RemoveMUS( std::string MUSName );
    /** Remove a file from the list */

    bool PlaySFX( std::string SFXName, int loops = 0, int channels = -1 );
    bool PlayMUS( std::string MUSName, int loops = 0 );
    /** Play file */

    bool FadeInSFX(std::string SFXName, int time, int loops = 0, int channel = -1);
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


    private:

    SLinkedList<SGZMusic*> MusicList;         //!< List of Musics
	SListIterator<SGZMusic*> MusicListITR;    //!< Iterator to the Music List

	SLinkedList<SGZSound*> SFXList;         //!< List of SFX
	SListIterator<SGZSound*> SFXListITR;    //!< Iterator to the SFX List

	AudioDevice DSP0(0), DSP1(1);

};

#endif
#endif

