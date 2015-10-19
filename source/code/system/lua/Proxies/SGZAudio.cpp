#include "SGZAudio.h"

int SGZAudio_Proxy::LoadMUS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->LoadMUSFile(lua_tostring(Lua, -1), lua_tostring(Lua, -2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::LoadSFX(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->LoadSFXFile(lua_tostring(Lua, -1), lua_tostring(Lua, -2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);;

    return 0;
}

int SGZAudio_Proxy::RemoveMUS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->RemoveMUS(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::RemoveSFX(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->RemoveSFX(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::PlayMUS(lua_State *Lua)
{
    int values = lua_gettop(Lua);
    if (values>1)
        SGZInterpret.accessClient()->accessAudio()->PlayMUS(lua_tostring(Lua, -2), (int)lua_tonumber(Lua, -1));
    else
        SGZInterpret.accessClient()->accessAudio()->PlayMUS(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::PlaySFX(lua_State *Lua)
{
    int values = lua_gettop(Lua);
    int tmp = 0;
    if(values>2)
        tmp = SGZInterpret.accessClient()->accessAudio()->PlaySFX(lua_tostring(Lua, -3), (int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));
    else if (values>1)
        tmp = SGZInterpret.accessClient()->accessAudio()->PlaySFX(lua_tostring(Lua, -2), (int)lua_tonumber(Lua, -1));
    else
        tmp = SGZInterpret.accessClient()->accessAudio()->PlaySFX(lua_tostring(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, tmp);

    return 1;
}

int SGZAudio_Proxy::FadeInMUS(lua_State *Lua)
{
    int values = lua_gettop(Lua);
    if(values>2)
        SGZInterpret.accessClient()->accessAudio()->FadeInMUS(lua_tostring(Lua, -3), (int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));
    else
        SGZInterpret.accessClient()->accessAudio()->FadeInMUS(lua_tostring(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::FadeInSFX(lua_State *Lua)
{
    int values = lua_gettop(Lua);
    int tmp = 0;
    if(values>3)
        tmp = SGZInterpret.accessClient()->accessAudio()->FadeInSFX(lua_tostring(Lua, -4), (int)lua_tonumber(Lua, -3), (int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));
    else if (values>2)
        tmp = SGZInterpret.accessClient()->accessAudio()->FadeInSFX(lua_tostring(Lua, -3), (int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));
    else
        tmp = SGZInterpret.accessClient()->accessAudio()->FadeInSFX(lua_tostring(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, tmp);

    return 1;
}

int SGZAudio_Proxy::FadeOutMUS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->FadeOutMUS((int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::FadeOutCHAN(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->FadeOutCHAN((int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::StopMUS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->StopMUS();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::StopCHAN(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->StopCHAN((int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::PauseMUS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->PauseMUS();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::PauseCHAN(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->PauseCHAN((int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::ResumeMUS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->ResumeMUS();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::ResumeCHAN(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->ResumeCHAN((int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::RewindMUS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->RewindMUS();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::SetMUSPOS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetMUSPOS((double)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::SetMUSVolume(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetVolumeMUS((int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}


int SGZAudio_Proxy::SetSFXVolume(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetVolumeSFX(lua_tostring(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::CHANPlaying(lua_State *Lua)
{
    int channelinfo = SGZInterpret.accessClient()->accessAudio()->CHANPlaying((int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, channelinfo);

    return 1;
}

int SGZAudio_Proxy::MUSPlaying(lua_State *Lua)
{
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, SGZInterpret.accessClient()->accessAudio()->MUSPlaying());

    return 1;
}

int SGZAudio_Proxy::SetChannels(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetChannels((int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::SetPanning(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetPanning((int)lua_tonumber(Lua, -3), (int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::SetDistance(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetDistance((int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::SetPosition(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetPosition((int)lua_tonumber(Lua, -3), (int)lua_tonumber(Lua, -2), (int)lua_tonumber(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::SetReverse(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->SetReverseStereo((int)lua_tonumber(Lua, -2), lua_toboolean(Lua, -1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::Update(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->UpdateAudio();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::CreateGROUP(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->CreateGROUP((int)lua_tonumber(Lua, 2), lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::ReserveCHANS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->ReserveCHANS((int)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::GroupCHAN(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->GroupCHAN((int)lua_tonumber(Lua, 2), lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::GroupCHANS(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->GroupCHANS((int)lua_tonumber(Lua, 2), (int)lua_tonumber(Lua, 3), lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::CountGROUP(lua_State *Lua)
{
    int temp = SGZInterpret.accessClient()->accessAudio()->CountGROUP(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZAudio_Proxy::CHANinGROUP(lua_State *Lua)
{
    int temp = SGZInterpret.accessClient()->accessAudio()->CHANinGROUP(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);
    return 1;
}

int SGZAudio_Proxy::OldestGROUP(lua_State *Lua)
{
    int temp = SGZInterpret.accessClient()->accessAudio()->OldestGROUP(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);
    return 1;
}

int SGZAudio_Proxy::NewestGROUP(lua_State *Lua)
{
    int temp = SGZInterpret.accessClient()->accessAudio()->NewestGROUP(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);
    return 1;
}

int SGZAudio_Proxy::FadeGROUP(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->FadeGROUP(lua_tostring(Lua, 1), (int)lua_tonumber(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::HaltGROUP(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->HaltGROUP(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZAudio_Proxy::RemoveGROUP(lua_State *Lua)
{
    SGZInterpret.accessClient()->accessAudio()->RemoveGROUP(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZAudio_Proxy::className[] = "SGZAudioManager";
Lunar<SGZAudio_Proxy>::RegType SGZAudio_Proxy::methods[] =
{
    {"LoadMUS", &SGZAudio_Proxy::LoadMUS},
    {"LoadSFX", &SGZAudio_Proxy::LoadSFX},
    {"RemoveMUS", &SGZAudio_Proxy::RemoveMUS},
    {"RemoveSFX", &SGZAudio_Proxy::RemoveSFX},
    {"PlayMUS", &SGZAudio_Proxy::PlayMUS},
    {"PlaySFX", &SGZAudio_Proxy::PlaySFX},
    {"FadeInMUS", &SGZAudio_Proxy::FadeInMUS},
    {"FadeInSFX", &SGZAudio_Proxy::FadeInSFX},
    {"FadeOutMUS", &SGZAudio_Proxy::FadeOutMUS},
    {"FadeOutCHAN", &SGZAudio_Proxy::FadeOutCHAN},
    {"StopMUS", &SGZAudio_Proxy::StopMUS},
    {"StopCHAN", &SGZAudio_Proxy::StopCHAN},
    {"PauseMUS", &SGZAudio_Proxy::PauseMUS},
    {"PauseCHAN", &SGZAudio_Proxy::PauseCHAN},
    {"ResumeMUS", &SGZAudio_Proxy::ResumeMUS},
    {"ResumeCHAN", &SGZAudio_Proxy::ResumeCHAN},
    {"RewindMUS", &SGZAudio_Proxy::RewindMUS},
    {"SetMUSPOS", &SGZAudio_Proxy::SetMUSPOS},
    {"SetMUSVolume", &SGZAudio_Proxy::SetMUSVolume},
    {"SetSFXVolume", &SGZAudio_Proxy::SetSFXVolume},
    {"MUSPlaying", &SGZAudio_Proxy::MUSPlaying},
    {"CHANPlaying", &SGZAudio_Proxy::CHANPlaying},
    {"SetChannels", &SGZAudio_Proxy::SetChannels},
    {"SetPanning", &SGZAudio_Proxy::SetPanning},
    {"SetPosition", &SGZAudio_Proxy::SetPosition},
    {"SetDistance", &SGZAudio_Proxy::SetDistance},
    {"SetReverse", &SGZAudio_Proxy::SetReverse},
    {"Update", &SGZAudio_Proxy::Update},
    {"CreateGROUP", &SGZAudio_Proxy::CreateGROUP},
    {"ReserveCHANS", &SGZAudio_Proxy::ReserveCHANS},
    {"GroupCHAN", &SGZAudio_Proxy::GroupCHAN},
    {"GroupCHANS", &SGZAudio_Proxy::GroupCHANS},
    {"CountGROUP", &SGZAudio_Proxy::CountGROUP},
    {"CHANinGROUP", &SGZAudio_Proxy::CHANinGROUP},
    {"OldestGROUP", &SGZAudio_Proxy::OldestGROUP},
    {"NewestGROUP", &SGZAudio_Proxy::NewestGROUP},
    {"FadeGROUP", &SGZAudio_Proxy::FadeGROUP},
    {"HaltGROUP", &SGZAudio_Proxy::HaltGROUP},
    {"RemoveGROUP", &SGZAudio_Proxy::RemoveGROUP},
    {0,0}
};

