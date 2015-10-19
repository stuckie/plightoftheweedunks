/** -------------------------------------------------------------------------------
* \file OAudio.cpp
* \brief The Audio Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#include "OAudio.h"

bool OAudio::CreateInterface(void)
{
    /** Create a client interface to talk on */
    return AudioObject.CreateInterface();
}

bool OAudio::DestroyInterface(void)
{
    /** Destroy a client interface */
    return AudioObject.DestroyInterface();
}

bool OAudio::UpdateAudio(void)
{
    /** Update/Poll Audio where applicable */
    return AudioObject.UpdateAudio();
}

bool OAudio::LoadSFXFile( std::string Filename, std::string SFXName )
{
    /** Load a sound effect to play */
    return AudioObject.LoadSFXFile( Filename, SFXName );
}

bool OAudio::LoadMUSFile( std::string Filename, std::string MUSName )
{
    /** Load a music to play */
    return AudioObject.LoadMUSFile( Filename, MUSName );
}

bool OAudio::RemoveSFX( std::string SFXName )
{
    /** Load a sound effect to play */
    return AudioObject.RemoveSFX( SFXName );
}

bool OAudio::RemoveMUS( std::string MUSName )
{
    /** Load a music to play */
    return AudioObject.RemoveMUS( MUSName );
}

int OAudio::PlaySFX( std::string SFXName, int loops, int channels )
{
    /** Play sound effect */
    return AudioObject.PlaySFX( SFXName, loops, channels );
}

bool OAudio::PlayMUS( std::string MUSName, int loops )
{
    /** Play sound effect */
    return AudioObject.PlayMUS( MUSName, loops );
}

int OAudio::FadeInSFX(std::string SFXName, int time, int loops, int channel)
{
    /** Fade in loaded file */
    return AudioObject.FadeInSFX(SFXName, time, loops, channel);
}

bool OAudio::FadeInMUS(std::string MUSName, int time, int loops)
{
    /** Fade in loaded file */
    return AudioObject.FadeInMUS(MUSName, time, loops);
}

bool OAudio::FadeOutCHAN( int channel, int time)
{
    /** Fade Out loaded file */
    return AudioObject.FadeOutCHAN(channel, time);
}

bool OAudio::FadeOutMUS( int time )
{
    /** Fade Out loaded file */
    return AudioObject.FadeOutMUS(time);
}

bool OAudio::StopMUS(void)
{
    /** Stop Playing */
    return AudioObject.StopMUS();
}

bool OAudio::StopCHAN(int channel)
{
    /** Stop Playing */
    return AudioObject.StopCHAN(channel);
}

bool OAudio::PauseMUS(void)
{
    /** Pause the file */
    return AudioObject.PauseMUS();
}

bool OAudio::PauseCHAN(int channel)
{
    /** Pause the stream */
    return AudioObject.PauseCHAN(channel);
}

bool OAudio::ResumeMUS(void)
{
    /** Resume the stream */
    return AudioObject.ResumeMUS();
}

bool OAudio::ResumeCHAN(int channel)
{
    /** Resume the stream */
    return AudioObject.ResumeCHAN(channel);
}

bool OAudio::RewindMUS(void)
{
    /** Rewind Music Stream */
    return AudioObject.RewindMUS();
}

bool OAudio::SetMUSPOS(double position)
{
    /** Fast Forward Music */
    return AudioObject.SetMUSPOS(position);
}

bool OAudio::SetVolumeMUS(int volume)
{
    /** Adjust MUS Volume */
    return AudioObject.SetVolumeMUS(volume);
}

bool OAudio::SetVolumeSFX(std::string SFXName, int volume)
{
    /** Adjust Volumes */
    return AudioObject.SetVolumeSFX(SFXName, volume);
}

int OAudio::CHANPlaying(int channel)
{
    /** See what's playing */
    return AudioObject.CHANPlaying(channel);
}

bool OAudio::MUSPlaying(void)
{
    /** What's playing */
    return AudioObject.MUSPlaying();
}

bool OAudio::SetChannels(int chans)
{
    /**Sets Channels*/
    return AudioObject.SetChannels(chans);
}

bool OAudio::SetPanning(int channel, int left, int right)
{
    /**Sets channel panning*/
    return AudioObject.SetPanning(channel, left, right);
}

bool OAudio::SetDistance(int channel, int distance)
{
    /**Sets Channel Distance*/
    return AudioObject.SetDistance(channel, distance);
}

bool OAudio::SetPosition(int channel, int angle, int distance)
{
    /**Sets Channel Position*/
    return AudioObject.SetPosition(channel, angle, distance);
}

bool OAudio::SetReverseStereo(int channel, bool flip)
{
    /** Flips Stereo */
    return AudioObject.SetReverseStereo(channel, flip);
}

bool OAudio::CreateGROUP(int num, std::string name)
{
    return AudioObject.CreateGROUP(num, name);
}

bool OAudio::ReserveCHANS(int num)
{
    return AudioObject.ReserveCHANS(num);
}

bool OAudio::GroupCHAN(int chan, std::string name)
{
    return AudioObject.GroupCHAN(chan, name);
}

bool OAudio::GroupCHANS(int from, int to, std::string name)
{
    return AudioObject.GroupCHANS(from, to, name);
}

int OAudio::CountGROUP(std::string name)
{
    return AudioObject.CountGROUP(name);
}

int OAudio::CHANinGROUP(std::string name)
{
    return AudioObject.CHANinGROUP(name);
}

int OAudio::OldestGROUP(std::string name)
{
    return AudioObject.OldestGROUP(name);
}

int OAudio::NewestGROUP(std::string name)
{
    return AudioObject.NewestGROUP(name);
}

bool OAudio::FadeGROUP(std::string name, int time)
{
    return AudioObject.FadeGROUP(name, time);
}

bool OAudio::HaltGROUP(std::string name)
{
    return AudioObject.HaltGROUP(name);
}

bool OAudio::RemoveGROUP(std::string name)
{
    return AudioObject.RemoveGROUP(name);
}
