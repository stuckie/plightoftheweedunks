#include "OGRERenderer.h"

#if defined (REND_OGRE) || defined (REND_SDLOGRE)
int OGRERender::CreateRenderer(void)
{
    OgreRoot = new Root("data/scripts/plugins.cfg", "data/scripts/ogre.cfg");

    parseResources();

    if (initOgreCore())
    {

        OgreRoot->initialise(false);

        SGZCreateWindow("SGZEngine Loading...", 640, 1, 0);

        createSceneManager();
        createCamera();
        createViewports();

        // Set default mipmap level (NB some APIs ignore this)
        TextureManager::getSingleton().setDefaultNumMipmaps(5);

        createResourceListener();

        initResources();

        SGZLogger.debug("OGRE Renderer initialised!\n");

        return true;
    }
    else return false;
}

void OGRERender::parseResources(void)
{
    SGZLogger.debug("Parsing Resources...\n");
    // Load resource paths from config file
    ConfigFile cf;
    cf.load("data/scripts/resources.cfg");

    // Go through all sections & settings in the file
    ConfigFile::SectionIterator seci = cf.getSectionIterator();

    String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        ConfigFile::SettingsMultiMap *settings = seci.getNext();
        ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
        }
    }
    SGZLogger.debug("done!\n");
}

bool OGRERender::initOgreCore(void)
{
    SGZLogger.debug("Initialising Ogre Core\n");
    if(OgreRoot->restoreConfig() || OgreRoot->showConfigDialog())
      return true;
   else
      return false;
}

void OGRERender::createSceneManager(void)
{
    SGZLogger.debug("Creating Ogre Scene Manager\n");
    // Create the SceneManager, in this case a generic one - octree I think
    OgreSceneMgr = OgreRoot->createSceneManager(ST_GENERIC);
}

void OGRERender::createCamera(void)
{
    SGZLogger.debug("Creating Camera\n");
    // Create a default camera
    OgreCamera = OgreSceneMgr->createCamera("DefaultCam");

    // Position it at 500 in Z direction
    OgreCamera->setPosition(Vector3(0,0,500));
    // Look back along -Z
    OgreCamera->lookAt(Vector3(0,0,-300));
    OgreCamera->setNearClipDistance(5);
}

void OGRERender::createViewports(void)
{
    SGZLogger.debug("Creating View Ports\n");
    // Create one viewport, entire window
    Viewport* vp = OgreWindow->addViewport(OgreCamera);
    vp->setBackgroundColour(ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    OgreCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
}

void OGRERender::createResourceListener(void)
{
    SGZLogger.debug("Creating Resource Listener\n");
}

void OGRERender::initResources(void)
{
    SGZLogger.debug("Initialising Resources\n");
    // Initialise, parse scripts etc
    ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

int OGRERender::StopRenderer(void)
{
    if (OgreRoot)
        delete OgreRoot;

    return true;
}

int OGRERender::UpdateScreen(void)
{
    OgreRoot->renderOneFrame();
    return true;
}

int OGRERender::SGZCreateWindow( std::string title, int WindowWidth, int WindowHeight, int WindowBPP )
{
    if(OgreWindow)
        SGZCloseWindow();
    OgreWindow = OgreRoot->createRenderWindow(title, (unsigned int)WindowWidth, (unsigned int)WindowHeight, 0, NULL);
    return 0;
}

int OGRERender::SGZCloseWindow( void )
{
    OgreWindow->destroy();
    return 0;
}

int OGRERender::SetFullScreen( bool set )
{
    return false;
}

void* OGRERender::GetScreen( void )
{
    return NULL;
}
#endif
