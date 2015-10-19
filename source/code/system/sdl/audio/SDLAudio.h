/** -------------------------------------------------------------------------------
* \file SDLAudio.h
* \brief The SDL Audio Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#ifndef _SDLAUDIO_H_
#define _SDLAUDIO_H_

#include "../../../client/audio/IAudio.h"
#include "../../../arch.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "../../../common/data/CSLinkedlist.h"
#include "../../../common/debug/CDebug.h"

struct SGZMusic
{
    std::string Name;
    Mix_Music *Data;
};

struct SGZSound
{
    std::string Name;
    Mix_Chunk *Data;
};

struct SGZChanGroup
{
    std::string Name;
    int groupNum;
};

class SDLAudio : IAudio
{
    public:
    SDLAudio() {}
    ~SDLAudio() {}

    bool CreateInterface(void);
    /** Create a client interface to talk on */

    bool DestroyInterface(void);
    /** Destroy a client interface */

    bool UpdateAudio(void);
    /** Update/Poll Audio where applicable */

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

    bool LoadSFXFile( std::string Filename, std::string SFXName );
    bool LoadMUSFile( std::string Filename, std::string MUSName );
    /** Load a file to play */

    bool RemoveSFX( std::string SFXName );
    bool RemoveMUS( std::string MUSName );
    /** Remove a file from the list */

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


    private:

    SLinkedList<SGZMusic*> MusicList;         //!< List of Musics
	SListIterator<SGZMusic*> MusicListITR;    //!< Iterator to the Music List

	SLinkedList<SGZSound*> SFXList;         //!< List of SFX
	SListIterator<SGZSound*> SFXListITR;    //!< Iterator to the SFX List

	SLinkedList<SGZChanGroup*> GroupList;         //!< List of SFX
	SListIterator<SGZChanGroup*> GroupListITR;    //!< Iterator to the SFX List

};

#endif

