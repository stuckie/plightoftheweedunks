/**
Game Server Code
*/

#ifndef _GAMESERVER_H_
#define _GAMESERVER_H_

#include "arch.h"
#include "IServer.h"
#include "CDebug.h"
#include "MEntity.h"
#include "MTexture.h"
#include "MLevel.h"
#include "odeCore.h"
#include "CTimer.h"
#include "AI.h"

class GameServer : public IServer
{
public:
    GameServer() {};
    ~GameServer() {};

    bool CreateInterface ( void );
    bool UpdateServer ( void );
    bool DestroyInterface ( void );
    MEntity* accessEntityManager( void ) { return EntityManager; };
    MTexture* accessTextureManager( void ) { return TextureManager; };
    MLevel* accessLevelManager( void ) { return LevelManager; };
    odeWorld* accessPhysics( void ) { return mOdeWorld; };
    AIClass* accessAI( void ) { return mAI; };
    float getFps( void );

private:
    MEntity* EntityManager;
    MTexture* TextureManager;
    MLevel* LevelManager;
    odeWorld* mOdeWorld;
    AIClass* mAI;

    Uint32 mLastTime;
    float mFps;
};

#endif
