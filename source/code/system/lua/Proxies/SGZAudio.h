#ifndef __SGZAUDIO_H_
#define __SGZAUDIO_H_

#ifdef pedanticGCC
extern "C" {
#endif
    #include "../lualib.h"
#ifdef pedanticGCC
}
#endif

#include "../lunar.h"
#include "../../../arch.h"
#include "../../../common/debug/CDebug.h"
#include "../../../common/engine/CInterpret.h"

class SGZAudio_Proxy
{
    public:
        static const char className[];
        static Lunar<SGZAudio_Proxy>::RegType methods[];

        int LoadMUS(lua_State *Lua);
        int LoadSFX(lua_State *Lua);
        int RemoveMUS(lua_State *Lua);
        int RemoveSFX(lua_State *Lua);
        int PlayMUS(lua_State *Lua);
        int PlaySFX(lua_State *Lua);
        int FadeInMUS(lua_State *Lua);
        int FadeInSFX(lua_State *Lua);
        int FadeOutCHAN(lua_State *Lua);
        int FadeOutMUS(lua_State *Lua);
        int StopCHAN(lua_State *Lua);
        int StopMUS(lua_State *Lua);
        int PauseCHAN(lua_State *Lua);
        int PauseMUS(lua_State *Lua);
        int ResumeMUS(lua_State *Lua);
        int ResumeCHAN(lua_State *Lua);
        int RewindMUS(lua_State *Lua);
        int SetMUSPOS(lua_State *Lua);
        int SetMUSVolume(lua_State *Lua);
        int SetSFXVolume(lua_State *Lua);
        int MUSPlaying(lua_State *Lua);
        int CHANPlaying(lua_State *Lua);
        int SetChannels(lua_State *Lua);
        int SetPanning(lua_State *Lua);
        int SetDistance(lua_State *Lua);
        int SetPosition(lua_State *Lua);
        int SetReverse(lua_State *Lua);
        int Update(lua_State *Lua);
        int CreateGROUP(lua_State *Lua);
        int ReserveCHANS(lua_State *Lua);
        int GroupCHAN(lua_State *Lua);
        int GroupCHANS(lua_State *Lua);
        int CountGROUP(lua_State *Lua);
        int CHANinGROUP(lua_State *Lua);
        int OldestGROUP(lua_State *Lua);
        int NewestGROUP(lua_State *Lua);
        int FadeGROUP(lua_State *Lua);
        int HaltGROUP(lua_State *Lua);
        int RemoveGROUP(lua_State *Lua);

        SGZAudio_Proxy(lua_State *L)
        {
            for (int cnt=1; cnt<=lua_gettop(L); cnt++)
                lua_pop(L, cnt);
        }
        ~SGZAudio_Proxy() {}

    private:
};

#endif
