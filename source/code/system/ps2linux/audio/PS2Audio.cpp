/** -------------------------------------------------------------------------------
* \file PS2Audio.h
* \brief The PS2 Audio Object
*
* File Maintainer - Stuckie
* Contains bits by Dr Henry Fortuna
*
* ===============================================================================
*/

#include "PS2Audio.h"

#ifdef PLAT_PS2LINUX

#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/soundcard.h>
#include <malloc.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>

#define AUDIO_DSP0 "/dev/dsp"
#define AUDIO_DSP1 "/dev/dsp1"
#define AUDIO_DIR ""

bool PS2Audio::CreateInterface(void)
{
    /** Create a client interface to talk on */
    //DSP0.Open(0);
    //DSP1.Open(1);

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

	DSP1.Close();
	DSP0.Close();

	return true;
}

bool SDLAudio::UpdateAudio(void)
{
    /** Update/Poll Audio where applicable */
    DSP0.HandleAudio();
    DSP1.HandleAudio();
    return true;
}

bool SDLAudio::LoadSFXFile( std::string Filename, std::string SFXName )
{
    /** Load a sound effect to play */
    SGZLogger.debug("Loading SFX: %s as %s\n", Filename.c_str(), SFXName.c_str());
    SGZSound *Effect;
    Effect = new SGZSound;
    Effect->Name = SFXName;
    Effect->Data = new SoundSample(Filename.c_str(), &DSP1);
    if(Effect->Data == NULL)
    {
        SGZLogger.warn("Failed to load SFX: %s\n", Filename.c_str());
        delete Effect;
        return false;
    }
    else
        SFXList.Append(Effect);
    return true;
}

bool SDLAudio::LoadMUSFile( std::string Filename, std::string MUSName )
{
    /** Load a music to play */
    SGZLogger.debug("Loading MUS: %s as %s\n", Filename.c_str(), MUSName.c_str());
    SGZMusic *Music;
    Music = new SGZMusic;
    Music->Name = MUSName;
    Music->Data = new SoundSample(Filename.c_str(), &DSP0);
    if(Music->Data == NULL)
    {
        SGZLogger.warn("Failed to load MUS: %s\n", Filename.c_str());
        delete Music;
        return false;
    }
    else
        MusicList.Append(Music);
    return true;
}

bool SDLAudio::PlaySFX( std::string SFXName, int loops, int channel )
{
    /** Play sound effect */
    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
        if((SFXListITR.Item()->Name.compare(SFXName))==0)
            SFXListITR.Item()->Data.Play();

    return true;
}

bool SDLAudio::PlayMUS( std::string MUSName, int loops )
{
    /** Play Music */
    SListIterator<SGZMusic*> MusicListITR = MusicList.GetIterator();

    for( MusicListITR.Start(); MusicListITR.Valid(); MusicListITR.Forth() )
        if((MusicListITR.Item()->Name.compare(MUSName))==0)
            MusicListITR.Item()->Data.Play();

    return true;
}

bool SDLAudio::RemoveSFX( std::string SFXName )
{
    /** Remove sound effect */
    SListIterator<SGZSound*> SFXListITR = SFXList.GetIterator();

    for( SFXListITR.Start(); SFXListITR.Valid(); SFXListITR.Forth() )
        if((SFXListITR.Item()->Name.compare(SFXName))==0)
        {
            delete (SFXListITR.Item()->Data);
            SFXList.Remove(SFXListITR);
        }

    return true;
}

bool SDLAudio::RemoveMUS( std::string MUSName )
{
    /** Remove Music */
    SGZLogger.debug("Removing %s\n", MUSName.c_str());
    SListIterator<SGZMusic*> MusicListITR = MusicList.GetIterator();

    for( MusicListITR.Start(); MusicListITR.Valid(); MusicListITR.Forth() )
        if((MusicListITR.Item()->Name.compare(MUSName))==0)
        {
            delete (MusicListITR.Item()->Data);
            MusicList.Remove(MusicListITR);
        }

    return true;
}

bool SDLAudio::FadeInSFX( std::string SFXName, int time, int loops, int channel)
{


    return true;
}

bool SDLAudio::FadeInMUS( std::string MUSName, int time, int loops)
{


    return true;
}

bool SDLAudio::FadeOutCHAN( int channel, int time)
{


    return true;
}

bool SDLAudio::FadeOutMUS( int time )
{


    return true;
}

bool SDLAudio::StopMUS(void)
{
    /** Stop Playing */

    return true;
}

bool SDLAudio::StopCHAN(int channel)
{


    return true;
}

bool SDLAudio::PauseMUS(void)
{
    /** Pause the file */

    return true;
}

bool SDLAudio::PauseCHAN(int channel)
{

    return true;
}

bool SDLAudio::ResumeMUS(void)
{

    return true;
}

bool SDLAudio::ResumeCHAN(int channel)
{

    return true;
}

bool SDLAudio::RewindMUS(void)
{

    return true;
}

bool SDLAudio::SetMUSPOS(double position)
{

    return true;
}

bool SDLAudio::SetVolumeMUS(int volume)
{

    return true;
}

bool SDLAudio::SetVolumeSFX(std::string SFXName, int volume)
{

    return true;
}

int SDLAudio::CHANPlaying(int channel)
{
    return 0;
}

bool SDLAudio::MUSPlaying(void)
{
    if(DSP0.silence))
        return false;
    else
        return true;
}

bool SDLAudio::SetChannels(int chans)
{

    return true;
}

bool SDLAudio::SetPanning(int channel, int left, int right)
{

    return true;
}

bool SDLAudio::SetDistance(int channel, int distance)
{

    return true;
}

bool SDLAudio::SetPosition(int channel, int angle, int distance)
{

    return true;
}

bool SDLAudio::SetReverseStereo(int channel, bool flip)
{

    return true;
}


AudioDevice::AudioDevice(const int Which)
{
	m_Current = NULL;
	m_AudioFD = 0;
	m_FragmentSize = 0;
	m_Silence = NULL;
	silence = false;

	// open the audio device
	Open(Which);
}


AudioDevice::~AudioDevice()
{
	if(m_AudioFD)
	{
		close(m_AudioFD);
		m_AudioFD = 0;
	}

	if(m_Silence)
	{
		free(m_Silence);
		m_Silence = 0;
	}
}



int AudioDevice::GetFreeFragments(void) const
{
	audio_buf_info info;

	if(ioctl(m_AudioFD, SNDCTL_DSP_GETOSPACE, &info) == -1) return 0;
	return info.fragments;
}

void AudioDevice::Close(void)
{
	if(m_AudioFD)
	{
		close(m_AudioFD);
		m_AudioFD = 0;
	}

	if(m_Silence)
	{
		free(m_Silence);
		m_Silence = 0;
	}
}

int AudioDevice::Open(const int Which)
{
	int format = AFMT_U8;
	int stereo = 0;
	int speed = 11025;

	if(!Which)
	{
		m_AudioFD = open(AUDIO_DSP0,O_WRONLY,0);
		if(m_AudioFD == -1)
		{
			perror(AUDIO_DSP0);
			exit(1);
		}
	}
	else
	{
		//fprintf(stderr,"Using alternate device\n");
		m_AudioFD = open(AUDIO_DSP1,O_WRONLY,0);
		if(m_AudioFD == -1)
		{
			perror(AUDIO_DSP1);
			exit(1);
		}
	}
/*
	int arg = 0xMMMMSSSS

	Argument of this call is an integer encoded as 0xMMMMSSSS (in hex).
	The 16 least significant bits determine the fragment size. The size is 2SSSS.
	For example SSSS=0008 gives fragment size of 256 bytes (28).
	The minimum is 16 bytes (SSSS=4) and the maximum is total_buffer_size/2.
	Some devices or processor architectures may require larger fragments in this
	case the requested fragment size is automatically increased.
	The 16 most significant bits (MMMM) determine maximum number of fragments.
	By default the deriver computes this based on available buffer space.
	The minimum value is 2 and the maximum depends on the situation.
	Set MMMM=0x7fff if you don't want to limit the number of fragments.

	int arg = 0xfFFF0008;
	if(ioctl(audio_fd, SNDCTL_DSP_SETFRAGMENT, &arg)==-1)
	{
		 perror("SNDCTL_DSP_SETFRAGMENT");
		 exit(20);
	}
*/
	if(ioctl(m_AudioFD,SNDCTL_DSP_SETFMT,&format)==-1)
	{
		perror("SNDCTL_DSP_SETFMT");
		exit(2);
	}

	if(ioctl(m_AudioFD,SNDCTL_DSP_STEREO,&stereo)==-1)
	{
		perror("SNDCTL_DSP_STEREO");
		exit(3);
	}

	if(ioctl(m_AudioFD,SNDCTL_DSP_SPEED,&speed)==-1)
	{
		perror("SNDCTL_DSP_SPEED");
		exit(4);
	}

	if(ioctl(m_AudioFD,SNDCTL_DSP_GETBLKSIZE,&m_FragmentSize)==-1)
	{
		perror("SNDCTL_DSP_GETBLKSIZE");
		exit(5);
	}

	//printf("Fragment size: %d\n", m_FragmentSize);

	m_Silence = (unsigned char *)malloc(m_FragmentSize);
	for(int i=0;i<m_FragmentSize;i++) m_Silence[i]=0x80;


	return m_AudioFD;
}

void AudioDevice::SetSoundSample( SoundSample * const Sample)
{
	m_Current = Sample;
}


void AudioDevice::HandleAudio(void)
{
	unsigned char * audiobuf;
	int ff,i;


	ff = GetFreeFragments();

	if(!ff) return;

	if(m_Current == NULL)
	{
		audiobuf = m_Silence;
		silence = true;
		for(i=0;i<ff;i++)
		{
			write(m_AudioFD, audiobuf, m_FragmentSize);
		}
		return;
	}

	for(i=0;i<ff;i++)
	{
    	if(m_Current)
    	{
		silence=false;
    		audiobuf = m_Current->GetNextFragment();
    		if(!audiobuf)
    		{
    			m_Current = NULL;
    			audiobuf = m_Silence;
    		}
    	}
    	else
    	{
    		audiobuf = m_Silence;
    	}

    	write(m_AudioFD, audiobuf, m_FragmentSize);
	 }
}

int AudioDevice::GetFragmentSize(void) const
{
	return m_FragmentSize;
}


SoundSample::SoundSample(char * Filename, AudioDevice * const pAD)
{
	m_Location = 0;
	m_Stream = NULL;
	m_FragSize = 0;
	m_NumFragments = 0;
	m_pAD = pAD;

	Load(Filename);
}


SoundSample::~SoundSample()
{
	if(m_Stream)
	{
		free(m_Stream);
		m_Stream = NULL;
	}
}


void SoundSample::Reset()
{
	m_Location = 0;
}

unsigned char * SoundSample::GetNextFragment()
{
	if(m_Location >= m_NumFragments) return NULL;
	return &m_Stream[(m_Location++) * m_FragSize];
}

void SoundSample::Load(char * Filename)
{
	struct stat file_stat;
	FILE * fp;
	int i;
	long filesize;
	char buf[100];

	m_FragSize = m_pAD->GetFragmentSize();

	strncpy(m_SampleName, Filename, 32);
	sprintf(buf, "%s%s.raw", AUDIO_DIR, Filename);
	printf("Loading file %s\n",buf);

	if(stat(buf, &file_stat) <0 )
		{
		printf("Failed to stat file -> %s!\n", buf);
		exit(1);
		}

	//printf("Finished with the file stat.\n");
	filesize = file_stat.st_size;
	//printf("File size: %ld\n", filesize);

	// Sanity check at this point
	assert(m_FragSize > 0);

	m_NumFragments = filesize/m_FragSize;
	m_NumFragments++;
	//printf("Number of fragments: %ld\n\n", m_NumFragments);

	// Allocate memory for sound
	m_Stream = (unsigned char *)malloc(m_NumFragments*m_FragSize);

	// Open sound file
	fp=fopen(buf,"r");
	if(!fp)
		{
		printf("Failed to open file -> %s!\n", buf);
		exit(1);
		}

	// Fill sound buffer
	for(i=0;i<filesize;i++)
		{
		m_Stream[i]=fgetc(fp);
		}

	// Fill buffer to end with silence
	for(i=filesize;i<m_NumFragments*m_FragSize;i++) m_Stream[i]=0x80;

	// Close the sound file
	fclose(fp);
}


void SoundSample::Play(void)
{
	m_Location = 0;
	m_pAD->SetSoundSample(this);
}




#endif
