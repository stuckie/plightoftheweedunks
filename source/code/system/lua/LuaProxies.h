#ifndef __LUAPROXIES_H_
#define __LUAPROXIES_H_

#ifdef pedanticGCC
extern "C"
{
#endif
    #include "../../system/lua/lualib.h"
#ifdef pedanticGCC
}
#endif

#include "lunar.h"
#include "../../arch.h"
#include "../../common/debug/CDebug.h"
#include "../../common/engine/CInterpret.h"
#include "../../client/renderer/texture/OTexture.h"
#include "Proxies/SGZAudio.h"
#include "Proxies/SGZInterpret.h"
#include "Proxies/SGZControl.h"
#include "Proxies/SGZNetwork.h"
#include "Proxies/SGZRender.h"
#include "Proxies/SGZEntityMan.h"
#include "Proxies/SGZEntity2D.h"
#include "Proxies/SGZEntity3D.h"
#include "Proxies/SGZTexture.h"
#include "Proxies/SGZTextureMan.h"
#include "Proxies/SGZLevelMan.h"
#include "Proxies/SGZamBX.h"
#include "Proxies/SGZODE.h"
#include "Proxies/SGZTimer.h"
#include "Proxies/SGZHorde.h"
#include "Proxies/SGZCamera.h"
#include "Proxies/SGZAI.h"
#include "Proxies/SGZEvent.h"

/**
    Put TESTING proxies in here, before moving them to proper locations later
*/

#endif
