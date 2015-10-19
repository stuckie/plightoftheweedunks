#include "SGZODE.h"         // to allow macro for accessing the physics engine
#include "SGZHorde.h"
#include "CInterpret.h"
#include <string>
#include "utMath.h"

//#define THROW_PLAYER_POSITIONS

int SGZHorde_Proxy::GetResourcePath(lua_State *Lua)
{
    std::string tmp;
    std::string check = lua_tostring(Lua, 1);

    if (check.compare("SceneGraph")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::SceneGraph));
    else if (check.compare("Geometry")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Geometry));
    else if (check.compare("Animation")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Animation));
    else if (check.compare("Material")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Material));
    else if (check.compare("Code")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Code));
    else if (check.compare("Shader")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Shader));
    else if (check.compare("Texture2D")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Texture2D));
    else if (check.compare("TextureCube")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::TextureCube));
    else if (check.compare("Effect")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Effect));
    else if (check.compare("Pipeline")==0)
        tmp.insert(0, Horde3DUtils::getResourcePath(ResourceTypes::Pipeline));
    else
        SGZLogger.warn("Trying to get Unknown Resource Path.\n");

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, tmp.c_str());

    return 1;
}

int SGZHorde_Proxy::SetResourcePath(lua_State *Lua)
{
    std::string check = lua_tostring(Lua, 1);

    if (check.compare("SceneGraph")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::SceneGraph, lua_tostring(Lua, 2));
    else if (check.compare("Geometry")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Geometry, lua_tostring(Lua, 2));
    else if (check.compare("Animation")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Animation, lua_tostring(Lua, 2));
    else if (check.compare("Material")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Material, lua_tostring(Lua, 2));
    else if (check.compare("Code")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Code, lua_tostring(Lua, 2));
    else if (check.compare("Shader")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Shader, lua_tostring(Lua, 2));
    else if (check.compare("Texture2D")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Texture2D, lua_tostring(Lua, 2));
    else if (check.compare("TextureCube")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::TextureCube, lua_tostring(Lua, 2));
    else if (check.compare("Effect")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Effect, lua_tostring(Lua, 2));
    else if (check.compare("Pipeline")==0)
        Horde3DUtils::setResourcePath(ResourceTypes::Pipeline, lua_tostring(Lua, 2));
    else
        SGZLogger.warn("Trying to Set Unknown Resource Path.\n");

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::LoadResourcesFromDisk(lua_State *Lua)
{
    Horde3DUtils::loadResourcesFromDisk(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::PickNode(lua_State *Lua)
{

    int tmp = Horde3DUtils::pickNode( Horde3D::findNodes( RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Camera ), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, tmp);

    return 1;
}

int SGZHorde_Proxy::ShowText(lua_State *Lua)
{
    Horde3DUtils::showText(lua_tostring(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4), (int)lua_tonumber(Lua, 5),
                           (ResHandle)lua_tonumber(Lua, 6));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::FrameInfo(lua_State *Lua)
{
    //Horde3DUtils::showFrameStats( (ResHandle)lua_tonumber(Lua, 1), (float)SGZInterpret.accessServer()->World()->getFps() );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::GetStats(lua_State *Lua)
{

/*    float temp = 0;
    std::string check = lua_tostring(Lua, 1);

    if (check.compare("TriCount")==0)
        temp = Horde3D::getStat( EngineStats::TriCount, (bool)lua_toboolean(Lua, 2) );
    else if (check.compare("BatchCount")==0)
		temp = Horde3D::getStat( EngineStats::BatchCount, (bool)lua_toboolean(Lua, 2) );
    else if (check.compare("LightPassCount")==0)
        temp = Horde3D::getStat( EngineStats::LightPassCount, (bool)lua_toboolean(Lua, 2) );
    else
        temp = 0;

    lua_pushnumber(Lua, temp);

    return 1;*/
    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::SetOption(lua_State *Lua)
{
    std::string check = lua_tostring(Lua, 1);

    if (check.compare("MaxLogLevel")==0)
        Horde3D::setOption( EngineOptions::MaxLogLevel, (float)lua_tonumber(Lua, 2));
    if (check.compare("TrilinearFiltering")==0)
        Horde3D::setOption( EngineOptions::TrilinearFiltering, (float)lua_tonumber(Lua, 2));
    if (check.compare("AnisotropyFactor")==0)
        Horde3D::setOption( EngineOptions::AnisotropyFactor, (float)lua_tonumber(Lua, 2));
    if (check.compare("TexCompression")==0)
        Horde3D::setOption( EngineOptions::TexCompression, (float)lua_tonumber(Lua, 2));
    if (check.compare("LoadTextures")==0)
        Horde3D::setOption( EngineOptions::LoadTextures, (float)lua_tonumber(Lua, 2));
    if (check.compare("FastAnimation")==0)
        Horde3D::setOption( EngineOptions::FastAnimation, (float)lua_tonumber(Lua, 2));
    if (check.compare("ShadowMapSize")==0)
        Horde3D::setOption( EngineOptions::ShadowMapSize, (float)lua_tonumber(Lua, 2));
    if (check.compare("SampleCount")==0)
        Horde3D::setOption( EngineOptions::SampleCount, (float)lua_tonumber(Lua, 2));
    if (check.compare("WireframeMode")==0)
        Horde3D::setOption( EngineOptions::WireframeMode, (float)lua_tonumber(Lua, 2));
    if (check.compare("DebugViewMode")==0)
        Horde3D::setOption( EngineOptions::DebugViewMode, (float)lua_tonumber(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::AddResource(lua_State *Lua)
{
    std::string check = lua_tostring(Lua, 1);

    ResHandle temp = 0;

    if (check.compare("SceneGraph")==0)
        temp = Horde3D::addResource( ResourceTypes::SceneGraph, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Geometry")==0)
        temp = Horde3D::addResource( ResourceTypes::Geometry, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Animation")==0)
        temp = Horde3D::addResource( ResourceTypes::Animation, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Material")==0)
        temp = Horde3D::addResource( ResourceTypes::Material, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Code")==0)
        temp = Horde3D::addResource( ResourceTypes::Code, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Shader")==0)
        temp = Horde3D::addResource( ResourceTypes::Shader, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Texture2D")==0)
        temp = Horde3D::addResource( ResourceTypes::Texture2D, lua_tostring(Lua, 2), 0 );
    else if (check.compare("TextureCube")==0)
        temp = Horde3D::addResource( ResourceTypes::TextureCube, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Effect")==0)
        temp = Horde3D::addResource( ResourceTypes::Effect, lua_tostring(Lua, 2), 0 );
    else if (check.compare("Pipeline")==0)
        temp = Horde3D::addResource( ResourceTypes::Pipeline, lua_tostring(Lua, 2), 0 );
    else
        SGZLogger.warn("Trying to Set Unknown Resource Path.\n");

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::Version(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, Horde3D::getVersionString());

    return 1;
}

int SGZHorde_Proxy::CheckForExtension(lua_State *Lua)
{

    bool temp = Horde3D::checkExtension(lua_tostring(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::EmptySceneGraph(lua_State *Lua)
{

    Horde3D::clear();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::GetMessage(lua_State *Lua)
{
    int level = (int)lua_tonumber(Lua, 1);
    float time = (float)lua_tonumber(Lua, 2);

    std::string temp = Horde3D::getMessage(&level, &time);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, temp.c_str());

    return 1;
}

int SGZHorde_Proxy::GetOption(lua_State *Lua)
{

    std::string check = lua_tostring(Lua, 1);
    float temp = 0;

    if (check.compare("MaxLogLevel")==0)
        temp = Horde3D::getOption( EngineOptions::MaxLogLevel );
    if (check.compare("TrilinearFiltering")==0)
        temp = Horde3D::getOption( EngineOptions::TrilinearFiltering );
    if (check.compare("AnisotropyFactor")==0)
        temp = Horde3D::getOption( EngineOptions::AnisotropyFactor );
    if (check.compare("TexCompression")==0)
        temp = Horde3D::getOption( EngineOptions::TexCompression );
    if (check.compare("LoadTextures")==0)
        temp = Horde3D::getOption( EngineOptions::LoadTextures );
    if (check.compare("FastAnimation")==0)
        temp = Horde3D::getOption( EngineOptions::FastAnimation );
    if (check.compare("ShadowMapSize")==0)
        temp = Horde3D::getOption( EngineOptions::ShadowMapSize );
    if (check.compare("SampleCount")==0)
        temp = Horde3D::getOption( EngineOptions::SampleCount );
    if (check.compare("WireframeMode")==0)
        temp = Horde3D::getOption( EngineOptions::WireframeMode );
    if (check.compare("DebugViewMode")==0)
        temp = Horde3D::getOption( EngineOptions::DebugViewMode );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::ShowOverlay(lua_State *Lua)
{

    Horde3D::showOverlay(   (float)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4),
                            (float)lua_tonumber(Lua, 5), (float)lua_tonumber(Lua, 6), (float)lua_tonumber(Lua, 7), (float)lua_tonumber(Lua, 8),
                            (float)lua_tonumber(Lua, 9), (float)lua_tonumber(Lua,10), (float)lua_tonumber(Lua,11), (float)lua_tonumber(Lua,12),
                            (float)lua_tonumber(Lua,13), (float)lua_tonumber(Lua,14), (float)lua_tonumber(Lua,15), (float)lua_tonumber(Lua,16),
                            (int)lua_tonumber(Lua,17), (ResHandle)lua_tonumber(Lua, 18));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::ClearOverlays(lua_State *Lua)
{

    Horde3D::clearOverlays();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::GetResourceType(lua_State *Lua)
{
    std::string tmp;

    if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::SceneGraph)
        tmp.insert(0,"SceneGraph");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Geometry)
        tmp.insert(0,"Geometry");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Animation)
        tmp.insert(0,"Animation");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Material)
        tmp.insert(0,"Material");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Code)
        tmp.insert(0,"Code");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Shader)
        tmp.insert(0,"Shader");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Texture2D)
        tmp.insert(0,"Texture2D");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::TextureCube)
        tmp.insert(0,"TextureCube");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Effect)
        tmp.insert(0,"Effect");
    else if (Horde3D::getResourceType((ResHandle)lua_tonumber(Lua, 1))==ResourceTypes::Pipeline)
        tmp.insert(0,"Pipeline");
    else
        SGZLogger.warn("Unknown Resource Type.\n");

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, tmp.c_str());

    return 1;
}

int SGZHorde_Proxy::GetResourceName(lua_State *Lua)
{
    std::string tmp = Horde3D::getResourceName((ResHandle)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushstring(Lua, tmp.c_str());

    return 1;
}

int SGZHorde_Proxy::FindResource(lua_State *Lua)
{

    std::string check = lua_tostring(Lua, 1);
    ResHandle temp = 0;

    if (check.compare("SceneGraph")==0)
        temp = Horde3D::findResource( ResourceTypes::SceneGraph, lua_tostring(Lua, 2) );
    else if (check.compare("Geometry")==0)
        temp = Horde3D::findResource( ResourceTypes::Geometry, lua_tostring(Lua, 2) );
    else if (check.compare("Animation")==0)
        temp = Horde3D::findResource( ResourceTypes::Animation, lua_tostring(Lua, 2) );
    else if (check.compare("Material")==0)
        temp = Horde3D::findResource( ResourceTypes::Material, lua_tostring(Lua, 2) );
    else if (check.compare("Code")==0)
        temp = Horde3D::findResource( ResourceTypes::Code, lua_tostring(Lua, 2) );
    else if (check.compare("Shader")==0)
        temp = Horde3D::findResource( ResourceTypes::Shader, lua_tostring(Lua, 2) );
    else if (check.compare("Texture2D")==0)
        temp = Horde3D::findResource( ResourceTypes::Texture2D, lua_tostring(Lua, 2) );
    else if (check.compare("TextureCube")==0)
        temp = Horde3D::findResource( ResourceTypes::TextureCube, lua_tostring(Lua, 2) );
    else if (check.compare("Effect")==0)
        temp = Horde3D::findResource( ResourceTypes::Effect, lua_tostring(Lua, 2) );
    else if (check.compare("Pipeline")==0)
        temp = Horde3D::findResource( ResourceTypes::Pipeline, lua_tostring(Lua, 2) );
    else
        SGZLogger.warn("Unknown Resource Type.\n");

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::CloneResource(lua_State *Lua)
{

    ResHandle temp = Horde3D::cloneResource( (ResHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::RemoveResource(lua_State *Lua)
{

    int temp = Horde3D::removeResource((ResHandle)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::LoadResource(lua_State *Lua)
{

    bool temp = Horde3D::loadResource( (ResHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), (int)lua_tonumber(Lua, 3) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::UnloadResource(lua_State *Lua)
{

    bool temp = Horde3D::unloadResource( (ResHandle)lua_tonumber(Lua, 1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetResourceParamInt(lua_State *Lua)
{

    int temp = Horde3D::getResourceParami( (ResHandle)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetResourceParamFloat(lua_State *Lua)
{
    float temp = Horde3D::getResourceParamf( (ResHandle)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetResourceData(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::UpdateResourceData(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::QueryUnloadedResources(lua_State *Lua)
{
    lua_pushnumber(Lua, Horde3D::queryUnloadedResource((int)lua_tonumber(Lua, 1)));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 1;
}

int SGZHorde_Proxy::ReleaseUnusedResources(lua_State *Lua)
{

    Horde3D::releaseUnusedResources();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::Create2DTexture(lua_State *Lua)
{

    int temp = Horde3D::createTexture2D(lua_tostring(Lua, 1), (int)lua_tonumber(Lua, 2), (int)lua_tonumber(Lua, 3), (int)lua_tonumber(Lua, 4), lua_toboolean(Lua, 5));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetShaderPreambles(lua_State *Lua)
{

    Horde3D::setShaderPreambles(lua_tostring(Lua, 1), lua_tostring(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::SetMaterialUniform(lua_State *Lua)
{
    bool temp = Horde3D::setMaterialUniform( (ResHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4), (float)lua_tonumber(Lua, 5), (float)lua_tonumber(Lua, 6) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetPipelineStageActivation(lua_State *Lua)
{

    bool temp = Horde3D::setPipelineStageActivation(  (ResHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), lua_toboolean(Lua, 3) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetPipelineRenderTargetData(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::Render(lua_State *Lua)
{

    Horde3D::render((NodeHandle)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::Resize(lua_State *Lua)
{
    Horde3D::resize((int)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2), (int)lua_tonumber(Lua, 3), (int)lua_tonumber(Lua, 4));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::AddNodes(lua_State *Lua)
{
    NodeHandle Node = 0;
    if (lua_tonumber(Lua, 1) == 0)
        Node = RootNode;
    else Node = (NodeHandle)lua_tonumber(Lua, 1);

    NodeHandle temp = Horde3D::addNodes( Node, (ResHandle)lua_tonumber(Lua, 2) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::AddCameraNode(lua_State *Lua)
{
    NodeHandle Node = 0;
    if (lua_tonumber(Lua, 1) == 0)
        Node = RootNode;
    else Node = (NodeHandle)lua_tonumber(Lua, 1);
    NodeHandle temp = Horde3D::addCameraNode( Node, lua_tostring(Lua, 2), (ResHandle)lua_tonumber(Lua, 3) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetNodeType(lua_State *Lua)
{
    int temp = Horde3D::getNodeType( (NodeHandle)lua_tonumber(Lua, 1) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    if (temp==SceneNodeTypes::Camera)
        lua_pushstring(Lua, "Camera");
    else if (temp==SceneNodeTypes::Emitter)
        lua_pushstring(Lua, "Emitter");
    else if (temp==SceneNodeTypes::Group)
        lua_pushstring(Lua, "Group");
    else if (temp==SceneNodeTypes::Joint)
        lua_pushstring(Lua, "Joint");
    else if (temp==SceneNodeTypes::Light)
        lua_pushstring(Lua, "Light");
    else if (temp==SceneNodeTypes::Mesh)
        lua_pushstring(Lua, "Mesh");
    else if (temp==SceneNodeTypes::Model)
        lua_pushstring(Lua, "Model");
    else lua_pushstring(Lua, "Undefined");

    return 1;
}

int SGZHorde_Proxy::GetNodeName(lua_State *Lua)
{
    //std::string temp = Horde3D::getNodeName((NodeHandle)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

//    lua_pushstring(Lua, temp.c_str());

    return 1;
}

int SGZHorde_Proxy::SetNodeName(lua_State *Lua)
{

//    bool temp = Horde3D::setNodeName((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

//    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetNodeParent(lua_State *Lua)
{

    NodeHandle temp = Horde3D::getNodeParent((NodeHandle)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeParent(lua_State *Lua)
{

    bool temp = Horde3D::setNodeParent((NodeHandle)lua_tonumber(Lua, 1), (NodeHandle)lua_tonumber(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetNodeChild(lua_State *Lua)
{
    NodeHandle temp = Horde3D::getNodeChild((NodeHandle)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetNodeAttachmentString(lua_State *Lua)
{
//    std::string temp = Horde3D::getNodeAttachmentString((NodeHandle)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

//    lua_pushstring(Lua, temp.c_str());

    return 1;
}

int SGZHorde_Proxy::RemoveNodes(lua_State *Lua)
{
    bool temp = Horde3D::removeNode((NodeHandle)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeActivation(lua_State *Lua)
{
    bool temp = Horde3D::setNodeActivation((NodeHandle)lua_tonumber(Lua, 1), lua_toboolean(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::CheckNodeTransformFlag(lua_State *Lua)
{

    bool temp = Horde3D::checkNodeTransformFlag((NodeHandle)lua_tonumber(Lua, 1), lua_toboolean(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetNodeTransform(lua_State *Lua)
{
    SGZVECTOR pos, rot, scale;

    Horde3D::getNodeTransform((NodeHandle)lua_tonumber(Lua, 1), &pos.x,  &pos.y,  &pos.z,  &rot.x,  &rot.y,  &rot.z,  &scale.x,  &scale.y,  &scale.z);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, pos.x);
    lua_pushnumber(Lua, pos.y);
    lua_pushnumber(Lua, pos.z);

    lua_pushnumber(Lua, rot.x);
    lua_pushnumber(Lua, rot.y);
    lua_pushnumber(Lua, rot.z);

    lua_pushnumber(Lua, scale.x);
    lua_pushnumber(Lua, scale.y);
    lua_pushnumber(Lua, scale.z);

    return 9;
}

int SGZHorde_Proxy::SetNodeTransform(lua_State *Lua)
{

    bool temp = Horde3D::setNodeTransform(  (NodeHandle)lua_tonumber(Lua, 1),
                                            (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4),
                                            (float)lua_tonumber(Lua, 5), (float)lua_tonumber(Lua, 6), (float)lua_tonumber(Lua, 7),
                                            (float)lua_tonumber(Lua, 8), (float)lua_tonumber(Lua, 9), (float)lua_tonumber(Lua,10) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeTransformODEDynamic(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getDynamicPos(odeIndex);
    SGZVECTOR offset = ODEWorld->getOffset(odeIndex);
    SGZVECTOR scale = ODEWorld->getDynamicSize(odeIndex);

    const dReal* ODEq = ODEWorld->getQuaternion(odeIndex);
    Quaternion q(ODEq[1], ODEq[2], ODEq[3], ODEq[0]);

    Matrix4f mat, qMat(q), sMat;

    mat.translate(-offset.x, -offset.y, -offset.z);
    mat.scale(scale.x,scale.y,scale.z);
    mat = qMat * mat;
    mat.translate(pos.x, pos.y, pos.z);

    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeTransformODEScripted(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getMovingPos(odeIndex);
    SGZVECTOR size = ODEWorld->getMovingSize(odeIndex);
    Quaternion q = ODEWorld->getMovingQuaternion(odeIndex);

    Matrix4f mat, qMat(q);

    mat.scale(size.x,size.y,size.z);
    mat = qMat * mat;
    mat.translate(pos.x, pos.y, pos.z);
    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}
int SGZHorde_Proxy::SetNodeTransformODEDynamicWithScale(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getDynamicPos(odeIndex);
    SGZVECTOR offset = ODEWorld->getOffset(odeIndex);
    float scale = (float)lua_tonumber(Lua, 3);

    const dReal* ODEq = ODEWorld->getQuaternion(odeIndex);
    Quaternion q(ODEq[1], ODEq[2], ODEq[3], ODEq[0]);

    Matrix4f mat, qMat(q), sMat;

    mat.translate(-offset.x, -offset.y, -offset.z);
    mat.scale(scale, scale, scale);
    mat = qMat * mat;
    mat.translate(pos.x, pos.y, pos.z);

    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeTransformODEScriptedWithScale(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getMovingPos(odeIndex);
    float scale = (float)lua_tonumber(Lua, 3);
    Quaternion q = ODEWorld->getMovingQuaternion(odeIndex);

    Matrix4f mat, qMat(q);

    mat.scale(scale, scale, scale);
    mat = qMat * mat;
    mat.translate(pos.x, pos.y, pos.z);
    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeTransformODEDynamicNoScale(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getDynamicPos(odeIndex);
    SGZVECTOR offset = ODEWorld->getOffset(odeIndex);

    const dReal* ODEq = ODEWorld->getQuaternion(odeIndex);
    Quaternion q(ODEq[1], ODEq[2], ODEq[3], ODEq[0]);

    Matrix4f mat, qMat(q), sMat;

    mat.translate(-offset.x, -offset.y, -offset.z);
    mat = qMat * mat;
    mat.translate(pos.x, pos.y, pos.z);

    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeTransformODEScriptedNoScale(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getMovingPos(odeIndex);
    Quaternion q = ODEWorld->getMovingQuaternion(odeIndex);

    Matrix4f mat, qMat(q);

    mat = qMat * mat;
    mat.translate(pos.x, pos.y, pos.z);
    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeTransformODEScriptedNoScaleUsingOriginalPos(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getMovingPos(odeIndex);
    SGZVECTOR originalPos = ODEWorld->getOriginalPos(odeIndex);
    Quaternion q = ODEWorld->getMovingQuaternion(odeIndex);

    Matrix4f mat, qMat(q);

    mat.translate(-originalPos.x, -originalPos.y, -originalPos.z);
    mat = qMat * mat;
    mat.translate(pos.x, pos.y, pos.z);
    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeTransformODEScriptedNoScaleNoRot(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);
    SGZVECTOR originalPos = ODEWorld->getOriginalPos(odeIndex);

    SGZVECTOR pos = ODEWorld->getMovingPos(odeIndex);

    Matrix4f mat;
    mat.translate(-originalPos.x, -originalPos.y, -originalPos.z);
    mat.translate(pos.x, pos.y, pos.z);
    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetPlayerTransform(lua_State *Lua)
{
    NodeHandle hordeHandel;
    if (lua_isnumber(Lua,1))
        hordeHandel = (NodeHandle)lua_tonumber(Lua, 1);
    else
    {
        int result = Horde3D::findNodes(RootNode, lua_tostring(Lua, 1), SceneNodeTypes::Mesh);
        if (result <= 0)
        {
            SGZLogger.warn("Unable to find node - %s\n", lua_tostring(Lua, 1));
            for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
                lua_pop(Lua, cnt);
            return 0;
        }

        hordeHandel = Horde3D::getNodeFindResult(0);
    }

    int odeIndex = (int)lua_tonumber(Lua, 2);

    SGZVECTOR pos = ODEWorld->getDynamicPos(odeIndex);
    SGZVECTOR offset = ODEWorld->getOffset(odeIndex);

    Matrix4f mat;
    mat.translate(-offset.x, -offset.y, -offset.z);
    mat.scale((float)lua_tonumber(Lua,4),(float)lua_tonumber(Lua,4),(float)lua_tonumber(Lua,4));
    mat.rotate(0.0f, degToRad(-(float)lua_tonumber(Lua, 3)), 0.0f);
    mat.translate(pos.x, pos.y, pos.z);
    bool temp = Horde3D::setNodeTransformMatrix( hordeHandel, mat.x);

#ifdef THROW_PLAYER_POSITIONS
    SGZLogger.debug("horde ID = %d, pos = (%.3f, %.3f, %.3f)\n", odeIndex, pos.x, pos.y, pos.z);
#endif

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}


int SGZHorde_Proxy::GetNodeTransformMatrices(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::SetNodeTransformMatrices(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::GetNodeParamFloat(lua_State *Lua)
{

    float temp = Horde3D::getNodeParamf((NodeHandle)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeParamFloat(lua_State *Lua)
{
    bool temp = false;
    std::string check = lua_tostring(Lua, 2);

    if (check.compare("MinDist")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), GroupNodeParams::MinDist ,(float)lua_tonumber(Lua, 3));
    if (check.compare("MaxDist")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), GroupNodeParams::MaxDist ,(float)lua_tonumber(Lua, 3));
    if (check.compare("Radius")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::Radius ,(float)lua_tonumber(Lua, 3));
    if (check.compare("FOV")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::FOV ,(float)lua_tonumber(Lua, 3));
    if (check.compare("Col_R")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::Col_R ,(float)lua_tonumber(Lua, 3));
    if (check.compare("Col_G")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::Col_G ,(float)lua_tonumber(Lua, 3));
    if (check.compare("Col_B")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::Col_B ,(float)lua_tonumber(Lua, 3));
    if (check.compare("ShadowSplitLambda")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::ShadowSplitLambda ,(float)lua_tonumber(Lua, 3));
    if (check.compare("ShadowMapBias")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::ShadowMapBias ,(float)lua_tonumber(Lua, 3));
    if (check.compare("LeftPlane")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::LeftPlane ,(float)lua_tonumber(Lua, 3));
    if (check.compare("RightPlane")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::RightPlane ,(float)lua_tonumber(Lua, 3));
    if (check.compare("BottomPlane")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::BottomPlane ,(float)lua_tonumber(Lua, 3));
    if (check.compare("TopPlane")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::TopPlane ,(float)lua_tonumber(Lua, 3));
    if (check.compare("NearPlane")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::NearPlane ,(float)lua_tonumber(Lua, 3));
    if (check.compare("FarPlane")==0)
        temp = Horde3D::setNodeParamf((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::FarPlane ,(float)lua_tonumber(Lua, 3));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetNodeParamInt(lua_State *Lua)
{

    int temp = Horde3D::getNodeParami((NodeHandle)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetNodeParamInt(lua_State *Lua)
{

    bool temp = false;
    std::string check = lua_tostring(Lua, 2);

    if (check.compare("GeometryRes")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), ModelNodeParams::GeometryRes ,(int)lua_tonumber(Lua, 3));
    if (check.compare("SoftwareSkinning")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), ModelNodeParams::SoftwareSkinning ,(int)lua_tonumber(Lua, 3));
    if (check.compare("MeshMaterialRes")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), MeshNodeParams::MaterialRes ,(ResHandle)lua_tonumber(Lua, 3));
    if (check.compare("LightMaterialRes")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::MaterialRes ,(ResHandle)lua_tonumber(Lua, 3));
    if (check.compare("EmitterMaterialRes")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), EmitterNodeParams::MaterialRes ,(ResHandle)lua_tonumber(Lua, 3));
    if (check.compare("BatchStart")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), MeshNodeParams::BatchStart ,(int)lua_tonumber(Lua, 3));
    if (check.compare("BatchCount")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), MeshNodeParams::BatchCount ,(int)lua_tonumber(Lua, 3));
    if (check.compare("VertRStart")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), MeshNodeParams::VertRStart ,(int)lua_tonumber(Lua, 3));
    if (check.compare("VertREnd")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), MeshNodeParams::VertREnd ,(int)lua_tonumber(Lua, 3));
    if (check.compare("JointIndex")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), JointNodeParams::JointIndex ,(int)lua_tonumber(Lua, 3));
    if (check.compare("PipelineRes")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::PipelineRes ,(int)lua_tonumber(Lua, 3));
    if (check.compare("OutputTex")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::OutputTex ,(int)lua_tonumber(Lua, 3));
    if (check.compare("OutputBufferIndex")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::OutputBufferIndex ,(int)lua_tonumber(Lua, 3));
    if (check.compare("Orthographic")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::Orthographic ,(int)lua_tonumber(Lua, 3));
    if (check.compare("OcclusionCulling")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), CameraNodeParams::OcclusionCulling ,(int)lua_tonumber(Lua, 3));
    if (check.compare("ShadowMapCount")==0)
        temp = Horde3D::setNodeParami((NodeHandle)lua_tonumber(Lua, 1), LightNodeParams::ShadowMapCount ,(int)lua_tonumber(Lua, 3));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::GetNodeAABB(lua_State *Lua)
{

    SGZVECTOR min, max;

    Horde3D::getNodeAABB((NodeHandle)lua_tonumber(Lua, 1), &min.x, &min.y, &min.z, &max.x, &max.y, &max.z);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, min.x);
    lua_pushnumber(Lua, min.y);
    lua_pushnumber(Lua, min.z);

    lua_pushnumber(Lua, max.x);
    lua_pushnumber(Lua, max.y);
    lua_pushnumber(Lua, max.z);

    return 6;
}

int SGZHorde_Proxy::FindNodes(lua_State *Lua)
{
    int tmp = SceneNodeTypes::Undefined;
    std::string check = lua_tostring(Lua, 3);

    if (check.compare("Camera")==0)
        tmp = SceneNodeTypes::Camera;
    else if (check.compare("Emitter")==0)
        tmp = SceneNodeTypes::Emitter;
    else if (check.compare("Group")==0)
        tmp = SceneNodeTypes::Group;
    else if (check.compare("Joint")==0)
        tmp = SceneNodeTypes::Joint;
    else if (check.compare("Light")==0)
        tmp = SceneNodeTypes::Light;
    else if (check.compare("Mesh")==0)
        tmp = SceneNodeTypes::Mesh;
    else if (check.compare("Model")==0)
        tmp = SceneNodeTypes::Model;
    else
        SGZLogger.warn("Trying to find Unknown Resource.\n");

    NodeHandle node = (int)lua_tonumber(Lua, 1);
    if (node == 0) node = RootNode;
    int temp = Horde3D::findNodes(node, lua_tostring(Lua, 2), tmp);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::GetNodeFindResult(lua_State *Lua)
{

    NodeHandle temp = Horde3D::getNodeFindResult((int)lua_tonumber(Lua, 1));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::CastRay(lua_State *Lua)
{

    NodeHandle temp = Horde3D::castRay((NodeHandle)lua_tonumber(Lua, 1),    (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4),
                                       (float)lua_tonumber(Lua, 5), (float)lua_tonumber(Lua, 6), (float)lua_tonumber(Lua, 7), (int)lua_tonumber(Lua, 8));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::AddGroupNode(lua_State *Lua)
{

    NodeHandle temp = Horde3D::addGroupNode((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::AddModelNode(lua_State *Lua)
{

    NodeHandle temp = Horde3D::addModelNode((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), (ResHandle)lua_tonumber(Lua, 3));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetupModelAnimStage(lua_State *Lua)
{

    bool temp = Horde3D::setupModelAnimStage((NodeHandle)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2), (ResHandle)lua_tonumber(Lua, 3), lua_tostring(Lua, 4), lua_toboolean(Lua, 5));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetModelAnimParams(lua_State *Lua)
{

    bool temp = Horde3D::setModelAnimParams((NodeHandle)lua_tonumber(Lua, 1), (int)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetModelMorpher(lua_State *Lua)
{

    bool temp = Horde3D::setModelMorpher((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), (float)lua_tonumber(Lua, 3));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::AddMeshNode(lua_State *Lua)
{

    NodeHandle temp = Horde3D::addMeshNode((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), (ResHandle)lua_tonumber(Lua, 3),
                                           (int)lua_tonumber(Lua, 4), (int)lua_tonumber(Lua, 5), (int)lua_tonumber(Lua, 6), (int)lua_tonumber(Lua, 7));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::AddJointNode(lua_State *Lua)
{

    NodeHandle temp = Horde3D::addJointNode((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), (int)lua_tonumber(Lua, 3));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::AddLightNode(lua_State *Lua)
{

    NodeHandle Node = 0;
    if (lua_tonumber(Lua, 1) == 0)
        Node = RootNode;
    else Node = (NodeHandle)lua_tonumber(Lua, 1);

    NodeHandle temp = Horde3D::addLightNode( Node, lua_tostring(Lua, 2), (ResHandle)lua_tonumber(Lua, 3), lua_tostring(Lua, 4), lua_tostring(Lua, 5) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetLightContexts(lua_State *Lua)
{

    bool temp = Horde3D::setLightContexts((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), lua_tostring(Lua, 3));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::SetupCameraView(lua_State *Lua)
{

    bool temp = Horde3D::setupCameraView((NodeHandle)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3), (float)lua_tonumber(Lua, 4), (float)lua_tonumber(Lua, 5) );

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::CalcCameraProjectionMatrix(lua_State *Lua)
{

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::AddEmitterNode(lua_State *Lua)
{

    NodeHandle temp = Horde3D::addEmitterNode((NodeHandle)lua_tonumber(Lua, 1), lua_tostring(Lua, 2), (ResHandle)lua_tonumber(Lua, 3), (ResHandle)lua_tonumber(Lua, 4), (int)lua_tonumber(Lua, 5), (int)lua_tonumber(Lua, 6));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::AdvanceEmitterTime(lua_State *Lua)
{
    bool temp = Horde3D::advanceEmitterTime((NodeHandle)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2));

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushboolean(Lua, temp);

    return 1;
}

int SGZHorde_Proxy::Init(lua_State *Lua)
{

    Horde3D::init();

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

int SGZHorde_Proxy::AddParticleEffect(lua_State *Lua)
{
    int tmp=0;

    if (lua_gettop(Lua) == 2)
    {
        if (lua_isnumber(Lua, 1))
            tmp = SGZInterpret.accessClient()->mParticleEngine.addStream((NodeHandle)lua_tonumber(Lua, 1), (ResHandle)lua_tonumber(Lua, 2));
        else
            tmp = SGZInterpret.accessClient()->mParticleEngine.addStream(lua_tostring(Lua, 1), (ResHandle)lua_tonumber(Lua, 2));
    }
    else if (lua_gettop(Lua) == 4)
    {
        tmp = SGZInterpret.accessClient()->mParticleEngine.addStream(SGZVECTOR((float)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3)), (ResHandle)lua_tonumber(Lua, 4));
    }

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    lua_pushnumber(Lua, tmp);

    return 1;
}

int SGZHorde_Proxy::AddParticleBox(lua_State *Lua)
{
    SGZVECTOR pos((float)lua_tonumber(Lua, 1), (float)lua_tonumber(Lua, 2), (float)lua_tonumber(Lua, 3));
    SGZVECTOR size((float)lua_tonumber(Lua, 4), (float)lua_tonumber(Lua, 5), (float)lua_tonumber(Lua, 6));
    int numStreams = (int)lua_tonumber(Lua, 7);
    ResHandle partEff = (ResHandle)lua_tonumber(Lua, 8);

    SGZInterpret.accessClient()->mParticleEngine.addBox(pos, size, numStreams, partEff);

    for (int cnt=1; cnt<=lua_gettop(Lua); cnt++)
        lua_pop(Lua, cnt);

    return 0;
}

const char SGZHorde_Proxy::className[] = "SGZHorde";
Lunar<SGZHorde_Proxy>::RegType SGZHorde_Proxy::methods[] =
{
    {"ShowText", &SGZHorde_Proxy::ShowText},
    {"GetResourcePath", &SGZHorde_Proxy::GetResourcePath},
    {"SetResourcePath", &SGZHorde_Proxy::SetResourcePath},
    {"LoadResourcesFromDisk", &SGZHorde_Proxy::LoadResourcesFromDisk},
    {"PickNode", &SGZHorde_Proxy::PickNode},
    {"FrameInfo", &SGZHorde_Proxy::FrameInfo},
    {"GetStats", &SGZHorde_Proxy::GetStats},

    {"Version", &SGZHorde_Proxy::Version},
    {"CheckForExtension", &SGZHorde_Proxy::CheckForExtension},
    {"EmptySceneGraph", &SGZHorde_Proxy::EmptySceneGraph},
    {"GetMessage", &SGZHorde_Proxy::GetMessage},
    {"GetOption", &SGZHorde_Proxy::GetOption},
    {"SetOption", &SGZHorde_Proxy::SetOption},
    {"ShowOverlay", &SGZHorde_Proxy::ShowOverlay},
    {"ClearOverlays", &SGZHorde_Proxy::ClearOverlays},
    {"Render", &SGZHorde_Proxy::Render},
    {"Resize", &SGZHorde_Proxy::Resize},

    {"GetResourceType", &SGZHorde_Proxy::GetResourceType},
    {"GetResourceName", &SGZHorde_Proxy::GetResourceName},
    {"FindResource", &SGZHorde_Proxy::FindResource},
    {"AddResource", &SGZHorde_Proxy::AddResource},
    {"CloneResource", &SGZHorde_Proxy::CloneResource},
    {"RemoveResource", &SGZHorde_Proxy::RemoveResource},
    {"LoadResource", &SGZHorde_Proxy::LoadResource},
    {"UnloadResource", &SGZHorde_Proxy::UnloadResource},
    {"GetResourceParamInt", &SGZHorde_Proxy::GetResourceParamInt},
    {"GetResourceParamFloat", &SGZHorde_Proxy::GetResourceParamFloat},
    {"GetResourceData", &SGZHorde_Proxy::GetResourceData},
    {"UpdateResourceData", &SGZHorde_Proxy::UpdateResourceData},
    {"QueryUnloadedResources", &SGZHorde_Proxy::QueryUnloadedResources},
    {"ReleaseUnusedResources", &SGZHorde_Proxy::ReleaseUnusedResources},

    {"Create2DTexture", &SGZHorde_Proxy::Create2DTexture},
    {"SetShaderPreambles", &SGZHorde_Proxy::SetShaderPreambles},
    {"SetMaterialUniform", &SGZHorde_Proxy::SetMaterialUniform},
    {"SetPipelineStageActivation", &SGZHorde_Proxy::SetPipelineStageActivation},
    {"GetPipelineRenderTargetData", &SGZHorde_Proxy::GetPipelineRenderTargetData},

    {"GetNodeType", &SGZHorde_Proxy::GetNodeType},
    {"GetNodeName", &SGZHorde_Proxy::GetNodeName},
    {"SetNodeName", &SGZHorde_Proxy::SetNodeName},
    {"GetNodeParent", &SGZHorde_Proxy::GetNodeParent},
    {"SetNodeParent", &SGZHorde_Proxy::SetNodeParent},
    {"GetNodeChild", &SGZHorde_Proxy::GetNodeChild},
    {"GetNodeAttachmentString", &SGZHorde_Proxy::GetNodeAttachmentString},
    {"AddNodes", &SGZHorde_Proxy::AddNodes},
    {"RemoveNodes", &SGZHorde_Proxy::RemoveNodes},
    {"SetNodeActivation", &SGZHorde_Proxy::SetNodeActivation},
    {"CheckNodeTransformFlag", &SGZHorde_Proxy::CheckNodeTransformFlag},
    {"GetNodeTransform", &SGZHorde_Proxy::GetNodeTransform},
    {"SetNodeTransform", &SGZHorde_Proxy::SetNodeTransform},

    {"SetNodeTransformODEDynamic", &SGZHorde_Proxy::SetNodeTransformODEDynamic},
    {"SetNodeTransformODEScripted", &SGZHorde_Proxy::SetNodeTransformODEScripted},
    {"SetNodeTransformODEDynamicWithScale", &SGZHorde_Proxy::SetNodeTransformODEDynamicWithScale},
    {"SetNodeTransformODEScriptedWithScale", &SGZHorde_Proxy::SetNodeTransformODEScriptedWithScale},
    {"SetNodeTransformODEDynamicNoScale", &SGZHorde_Proxy::SetNodeTransformODEDynamicNoScale},
    {"SetNodeTransformODEScriptedNoScale", &SGZHorde_Proxy::SetNodeTransformODEScriptedNoScale},
    {"SetNodeTransformODEScriptedNoScaleUsingOriginalPos", &SGZHorde_Proxy::SetNodeTransformODEScriptedNoScaleUsingOriginalPos},
    {"SetNodeTransformODEScriptedNoScaleNoRot", &SGZHorde_Proxy::SetNodeTransformODEScriptedNoScaleNoRot},

    {"SetPlayerTransform", &SGZHorde_Proxy::SetPlayerTransform},

    {"GetNodeTransformMatrices", &SGZHorde_Proxy::GetNodeTransformMatrices},
    {"SetNodeTransformMatrices", &SGZHorde_Proxy::SetNodeTransformMatrices},
    {"GetNodeParamFloat", &SGZHorde_Proxy::GetNodeParamFloat},
    {"GetNodeParamInt", &SGZHorde_Proxy::GetNodeParamInt},
    {"SetNodeParamFloat", &SGZHorde_Proxy::SetNodeParamFloat},
    {"SetNodeParamInt", &SGZHorde_Proxy::SetNodeParamInt},
    {"GetNodeAABB", &SGZHorde_Proxy::GetNodeAABB},
    {"FindNodes", &SGZHorde_Proxy::FindNodes},
    {"GetNodeFindResult", &SGZHorde_Proxy::GetNodeFindResult},
    {"CastRay", &SGZHorde_Proxy::CastRay},

    {"AddGroupNode", &SGZHorde_Proxy::AddGroupNode},

    {"AddModelNode", &SGZHorde_Proxy::AddModelNode},
    {"SetupModelAnimStage", &SGZHorde_Proxy::SetupModelAnimStage},
    {"SetModelAnimParams", &SGZHorde_Proxy::SetModelAnimParams},
    {"SetModelMorpher", &SGZHorde_Proxy::SetModelMorpher},

    {"AddMeshNode", &SGZHorde_Proxy::AddMeshNode},

    {"AddJointNode", &SGZHorde_Proxy::AddJointNode},

    {"AddLightNode", &SGZHorde_Proxy::AddLightNode},
    {"SetLightContexts", &SGZHorde_Proxy::SetLightContexts},

    {"AddCameraNode", &SGZHorde_Proxy::AddCameraNode},
    {"SetupCameraView", &SGZHorde_Proxy::SetupCameraView},
    {"CalcCameraProjectionMatrix", &SGZHorde_Proxy::CalcCameraProjectionMatrix},

    {"AddEmitterNode", &SGZHorde_Proxy::AddEmitterNode},
    {"AdvanceEmitterTime", &SGZHorde_Proxy::AdvanceEmitterTime},

    {"AddParticleEffect", &SGZHorde_Proxy::AddParticleEffect},
    {"AddParticleBox", &SGZHorde_Proxy::AddParticleBox},

    {"Init", &SGZHorde_Proxy::Init},

    {0,0}
};
