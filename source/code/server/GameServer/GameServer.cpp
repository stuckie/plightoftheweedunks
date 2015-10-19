#include "GameServer.h"

bool GameServer::CreateInterface( void )
{
    /** Set up Managers and Clear them */

    /** Create a new Entity Manager */
    EntityManager = new MEntity;

    /** Create a new Texture Manager */
    TextureManager = new MTexture;

    /** Create a new Level Manager */
    LevelManager = new MLevel;

    /** Create a new physics world **/
    mOdeWorld = new odeWorld;
    mOdeWorld->init();

    /** Create the AI world **/
    mAI = new AIClass;

    /** Start The Timer */
    mLastTime = 0;

    return true;
}

bool GameServer::DestroyInterface( void )
{
    /** Clear Managers and Delete them */

    if(EntityManager)
        delete EntityManager;
    if(TextureManager)
        delete TextureManager;
    if(LevelManager)
        delete LevelManager;
    if(mOdeWorld)
    {
        mOdeWorld->kill();
        delete mOdeWorld;
    }
    if (mAI)
        delete mAI;

    return true;
}

bool GameServer::UpdateServer( void )
{
    /** Parse all Managers and Update them */
    Uint32 curTime = SDL_GetTicks();

    if (curTime==mLastTime)
        mFps = 1000.0f;
    else
        mFps  = 1000.0f/(curTime-mLastTime);

    while (curTime < mLastTime + (1000 / SGZ_FRAME_LOCK))
    {
        SDL_Delay(1);
        curTime = SDL_GetTicks();
    }

    mLastTime = curTime;

    mOdeWorld->runFrame();
    mAI->update();
    EntityManager->UpdateEntities();

    return true;
}

float GameServer::getFps( void )
{
    return mFps;
}
