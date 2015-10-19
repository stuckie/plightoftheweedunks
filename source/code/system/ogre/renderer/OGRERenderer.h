#ifndef _OGRERENDERER_H_
#define _OGRERENDERER_H_

#include "../../../arch.h"
#include "../../../common/debug/CDebug.h"
#include "../../../client/renderer/IRender.h"

#if defined (REND_OGRE) || defined (REND_SDLOGRE)

#include "Ogre.h"
#include "ois/OIS.h"

#ifdef REND_SDLOGRE
    #include "SDL.h"
#endif

using namespace Ogre;

class ExitListener : public FrameListener
{
public:
    ExitListener(OIS::Keyboard *keyboard)
        : mKeyboard(keyboard)
    {
    }

    bool frameStarted(const FrameEvent& evt)
    {
        mKeyboard->capture();
        return !mKeyboard->isKeyDown(OIS::KC_ESCAPE);
    }

private:
    OIS::Keyboard *mKeyboard;
};

class OGRERender : public IRender
{
    public:
    OGRERender() { OgreRoot = NULL; };
    ~OGRERender() {};

    int CreateRenderer ( void );
    /** This creates and sets up the Renderer */

    int UpdateScreen( void );
    /** This updates the screen */

    int StopRenderer( void );
    /** This stops the Renderer */

    int SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP );
    /** Creates a Window */

    int SGZCloseWindow( void );
    /** Closes a Window */

    int SetFullScreen( bool set );
    /** Toggles fullscreen ( for those that support it ) */

    bool initOgreCore( void );
    /** Sets up Ogre's core stuff */

    /** Create the Scene Manager */
    void createSceneManager();

    /** Create the Camera */
    void createCamera();

    /** Create the View Ports */
    void createViewports();

    /** Create the Resource Listener */
    void createResourceListener();

    /** Parse the Resources */
    void parseResources();

    /** Init the Resources */
    void initResources();

    void* GetScreen( void );
    /** Returns the current Window Screen to draw */

    Ogre::Root* GetRoot( void ) { return OgreRoot; }
    /** Return the Ogre Root Node */

    private:
    /** Instance of the MAIN OGRE class. */
    Ogre::Root* OgreRoot;

    /** Instance of OGRE's SceneManager */
    Ogre::SceneManager* OgreSceneMgr;

    /** Instance of the OGRE RenderWindow class. */
    Ogre::RenderWindow* OgreWindow;

    /** Instance of the OGRE Camera */
    Ogre::Camera* OgreCamera;
};

#endif

#endif
