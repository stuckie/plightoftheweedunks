/** -------------------------------------------------------------------------------
* \file SDLAudio.h
* \brief The SDL Audio Object
*
* File Maintainer - Stuckie
*
* ===============================================================================
*/

#include "SDLAudio.h"

bool SDLAudio::CreateInterface(void)
{
    /** Create a client interface to talk on */
    if(SDL_Init(SDL_INIT_AUDIO)==-1)
    {
        SGZLogger.warn("AudioMAN: Error setting up SDL Audio!\n");
        return false;
    }

    #ifdef PLAT_PC
    if(Mix_OpenAudio(44100,AUDIO_S16,2,4096)==-1)
    #endif
    #ifdef PLAT_GP2X
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16, MIX_DEFAULT_CHANNELS, 4096)==-1)
    #endif
    {
        SGZLogger.warn("AudioMAN: Error Opening Mixer!\n");
        return false;
    }
    SGZLogger.debug("AudioMAN: SDLAudio Initialised!\n");

    /** Give us 10 channels to play with from the outset */
    Mix_AllocateChannels(10);

    return true;
}

bool SDLAudio::DestroyInterface(void)
{
    /** Destroy a client interface */
    SListIterator<SGZMusic*> MusicListITR = MusicList.GetIterator();

    MusicListITR.Start();
    while (MusicListITR.Valid())
    {
        Mix_FreeMusic(MusicListITR.Item()->Data);
        MusicList.Remove(MusicListITR);
        MusicListITR.Forth();
    }

    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    SFXListITR.Start();
    while (SFXListITR.Valid())
    {
        Mix_FreeChunk(SFXListITR.Item()->Data);
        SFXList.Remove(SFXListITR);
        SFXListITR.Forth();
    }

	Mix_CloseAudio();

	return true;
}

bool SDLAudio::UpdateAudio(void)
{
    /** Update/Poll Audio where applicable */
    /** SDL does not poll audio */
    return true;
}

bool SDLAudio::LoadSFXFile( std::string Filename, std::string SFXName )
{
    /** Check to see if we've already loaded it */
    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
        if((SFXListITR.Item()->Name.compare(SFXName))==0)
        {
            SGZLogger.debug("AudioMAN: SFX \"%s\" already loaded!\n", SFXName.c_str());
            return false;
        }

    /** Load a sound effect to play */
    SGZLogger.debug("AudioMAN: Loading SFX \"%s\" as %s\n", Filename.c_str(), SFXName.c_str());
    SGZSound *Effect;
    Effect = new SGZSound;
    Effect->Name = SFXName;
    Effect->Data = Mix_LoadWAV(Filename.c_str());
    if(Effect->Data == NULL)
    {
        SGZLogger.warn("AudioMAN: Failed to load SFX: %s\n", Filename.c_str());
        delete Effect;
        return false;
    }
    else
        SFXList.Append(Effect);
    return true;
}

bool SDLAudio::LoadMUSFile( std::string Filename, std::string MUSName )
{
    /** Check to see if we've already loaded it */
    SListIterator<SGZMusic*> MusicListITR = MusicList.GetIterator();

    for( MusicListITR.Start(); MusicListITR.Valid(); MusicListITR.Forth() )
        if((MusicListITR.Item()->Name.compare(MUSName))==0)
        {
            SGZLogger.debug("AudioMAN: SFX: %s already loaded!\n", MUSName.c_str());
            return false;
        }

    /** Load a music to play */
    SGZLogger.debug("AudioMAN: Loading MUS: %s as %s\n", Filename.c_str(), MUSName.c_str());
    SGZMusic *Music;
    Music = new SGZMusic;
    Music->Name = MUSName;
    Music->Data = Mix_LoadMUS(Filename.c_str());
    if(Music->Data == NULL)
    {
        SGZLogger.warn("AudioMAN: Failed to load MUS: %s\n", Filename.c_str());
        delete Music;
        return false;
    }
    else
        MusicList.Append(Music);
    return true;
}

int SDLAudio::PlaySFX( std::string SFXName, int loops, int channel )
{
    /** Play sound effect */
    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
        if((SFXListITR.Item()->Name.compare(SFXName))==0)
        {
            return Mix_PlayChannel(channel, SFXListITR.Item()->Data, loops);
        }

    SGZLogger.warn("AudioMAN: Can't find SFX \"%s\" to play! Is it loaded?\n", SFXName.c_str());
    return -1;
}

bool SDLAudio::PlayMUS( std::string MUSName, int loops )
{
    /** Play Music */
    SListIterator<SGZMusic*> MusicListITR = MusicList.GetIterator();

    for( MusicListITR.Start(); MusicListITR.Valid(); MusicListITR.Forth() )
        if((MusicListITR.Item()->Name.compare(MUSName))==0)
        {
            Mix_PlayMusic(MusicListITR.Item()->Data, loops);
            SGZLogger.debug("AudioMAN: Playing %s, %d times\n", MUSName.c_str(), loops);
            return true;
        }

    SGZLogger.warn("AudioMAN: Can't find MUS \"%s\" to play! Is it loaded?\n", MUSName.c_str());
    return false;
}

bool SDLAudio::RemoveSFX( std::string SFXName )
{
    /** Remove sound effect */
    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
        if((SFXListITR.Item()->Name.compare(SFXName))==0)
        {
            Mix_FreeChunk(SFXListITR.Item()->Data);
            SFXList.Remove(SFXListITR);
            return true;
        }

    SGZLogger.warn("AudioMAN: Can't find SFX \"%s\" to unload!\n", SFXName.c_str());
    return false;
}

bool SDLAudio::RemoveMUS( std::string MUSName )
{
    /** Remove Music */
    SGZLogger.debug("AudioMAN: Removing %s\n", MUSName.c_str());
    SListIterator<SGZMusic*> MusicListITR = MusicList.GetIterator();

    for( MusicListITR.Start(); MusicListITR.Valid(); MusicListITR.Forth() )
        if((MusicListITR.Item()->Name.compare(MUSName))==0)
        {
            Mix_FreeMusic(MusicListITR.Item()->Data);
            MusicList.Remove(MusicListITR);
            return true;
        }

    SGZLogger.warn("AudioMAN: Can't find MUS \"%s\" to unload!\n", MUSName.c_str());
    return false;
}

int SDLAudio::FadeInSFX( std::string SFXName, int time, int loops, int channel)
{
    /** Play SFX */
    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
        if((SFXListITR.Item()->Name.compare(SFXName))==0)
        {
            return Mix_FadeInChannel(channel, SFXListITR.Item()->Data, loops, time);
        }

    SGZLogger.warn("AudioMAN: Can't find SFX \"%s\" to Fade In!\n", SFXName.c_str());
    return -1;
}

bool SDLAudio::FadeInMUS( std::string MUSName, int time, int loops)
{
    /** Play Music */
    SListIterator<SGZMusic*> MusicListITR = MusicList.GetIterator();

    for( MusicListITR.Start(); MusicListITR.Valid(); MusicListITR.Forth() )
        if((MusicListITR.Item()->Name.compare(MUSName))==0)
        {
            Mix_FadeInMusic(MusicListITR.Item()->Data, loops, time);
            return true;
        }

    SGZLogger.warn("AudioMAN: Can't find MUS \"%s\" to Fade In!\n", MUSName.c_str());
    return false;
}

bool SDLAudio::FadeOutCHAN( int channel, int time)
{
    Mix_FadeOutChannel(channel, time);

    return true;
}

bool SDLAudio::FadeOutMUS( int time )
{
    Mix_FadeOutMusic(time);

    return true;
}

bool SDLAudio::StopMUS(void)
{
    /** Stop Playing */
    Mix_HaltMusic();
    return true;
}

bool SDLAudio::StopCHAN(int channel)
{
    Mix_HaltChannel(channel);

    return true;
}

bool SDLAudio::PauseMUS(void)
{
    /** Pause the file */
    Mix_PauseMusic();
    return true;
}

bool SDLAudio::PauseCHAN(int channel)
{
    Mix_Pause(channel);
    return true;
}

bool SDLAudio::ResumeMUS(void)
{
    Mix_ResumeMusic();
    return true;
}

bool SDLAudio::ResumeCHAN(int channel)
{
    Mix_Resume(channel);
    return true;
}

bool SDLAudio::RewindMUS(void)
{
    Mix_RewindMusic();
    return true;
}

bool SDLAudio::SetMUSPOS(double position)
{
    Mix_SetMusicPosition(position);
    return true;
}

bool SDLAudio::SetVolumeMUS(int volume)
{
    Mix_VolumeMusic(volume);
    return true;
}

bool SDLAudio::SetVolumeSFX(std::string SFXName, int volume)
{
    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    if((SFXName.compare("-1"))==0)
    {
        for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
            Mix_VolumeChunk(SFXListITR.Item()->Data, volume);

        return true;
    }
    else
    {
        for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
            if((SFXListITR.Item()->Name.compare(SFXName))==0)
            {
                Mix_VolumeChunk(SFXListITR.Item()->Data, volume);
                return true;
            }
    }

    SGZLogger.warn("AudioMAN: Can't find SFX \"%s\" to Set Volume!\n", SFXName.c_str());
    return false;
}

int SDLAudio::CHANPlaying(int channel)
{
    return Mix_Playing(channel);
}

bool SDLAudio::MUSPlaying(void)
{
    if(Mix_PlayingMusic())
        return true;
    else
        return false;
}

bool SDLAudio::SetChannels(int chans)
{
    Mix_AllocateChannels(chans);
    return true;
}

bool SDLAudio::SetPanning(int channel, int left, int right)
{
    Mix_SetPanning(channel, left, right);
    return true;
}

bool SDLAudio::SetDistance(int channel, int distance)
{
    Mix_SetDistance(channel, distance);
    return true;
}

bool SDLAudio::SetPosition(int channel, int angle, int distance)
{
    Mix_SetPosition(channel, angle, distance);
    return true;
}

bool SDLAudio::SetReverseStereo(int channel, bool flip)
{
    Mix_SetReverseStereo(channel, flip);
    return true;
}

bool SDLAudio::CreateGROUP(int num, std::string name)
{
    /** Check to see if we've already created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            SGZLogger.debug("AudioMAN: Group \"%s\" already created!\n", name.c_str());
            return false;
        }

    /** Create a channel group */
    SGZLogger.debug("AudioMAN: Creating SFX Group \"%s\"\n", name.c_str());
    SGZChanGroup *Group;
    Group = new SGZChanGroup;
    Group->Name = name;
    Group->groupNum = num;
    GroupList.Append(Group);
    return true;
}

bool SDLAudio::RemoveGROUP(std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            GroupList.Remove(GroupListITR);
            return true;
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return false;
}

bool SDLAudio::ReserveCHANS(int num)
{
    Mix_ReserveChannels(num);
    return true;
}

bool SDLAudio::GroupCHAN(int chan, std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            Mix_GroupChannel(chan, GroupListITR.Item()->groupNum);
            return true;
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return false;
}

bool SDLAudio::GroupCHANS(int from, int to, std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            Mix_GroupChannels(from, to, GroupListITR.Item()->groupNum);
            return true;
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return false;
}

int SDLAudio::CountGROUP(std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            return Mix_GroupCount(GroupListITR.Item()->groupNum);
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return 0;
}

int SDLAudio::CHANinGROUP(std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();
    if (name.compare("all")==0) { return Mix_GroupAvailable(-1); }

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            return Mix_GroupAvailable(GroupListITR.Item()->groupNum);
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return 0;
}

int SDLAudio::OldestGROUP(std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            return Mix_GroupOldest(GroupListITR.Item()->groupNum);
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return 0;
}

int SDLAudio::NewestGROUP(std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            return Mix_GroupNewer(GroupListITR.Item()->groupNum);
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return 0;
}

bool SDLAudio::FadeGROUP(std::string name, int time)
{
     /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            Mix_FadeOutGroup(GroupListITR.Item()->groupNum, time);
            return true;
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return false;
}

bool SDLAudio::HaltGROUP(std::string name)
{
    /** Check to see if we've created it */
    SListIterator<SGZChanGroup*> GroupListITR = GroupList.GetIterator();

    for( GroupListITR.Start(); GroupListITR.Valid(); GroupListITR.Forth() )
        if((GroupListITR.Item()->Name.compare(name))==0)
        {
            Mix_HaltGroup(GroupListITR.Item()->groupNum);
            return true;
        }

    SGZLogger.warn("AudioMAN: Group \"%s\" doesn't exist!\n", name.c_str());
    return false;
}
