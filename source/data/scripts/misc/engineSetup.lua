-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

local SplashRes;

WeedunkWayPoint = 1;
BertWayPoint = 2;		--  used when setting up waypoints
ErnieWayPoint = 3;

function engineSetup()
	if renderingMode == RENDERING_FAST then
		Horde:SetResourcePath( "Material", "materials" );
	    Horde:SetResourcePath( "Pipeline", "pipelines" );
	    Horde:SetResourcePath( "Shader", "shaders/texPart" );
	elseif renderingMode == RENDERING_HDR then
		Horde:SetResourcePath( "Material", "materials" );
	    Horde:SetResourcePath( "Pipeline", "pipelines" );
	    Horde:SetResourcePath( "Shader", "shaders/hdr" );
	end
	Horde:SetResourcePath( "Texture2D", "textures" );
	Horde:SetResourcePath( "SceneGraph", "models" );
	Horde:SetResourcePath( "Geometry", "models" );
	Horde:SetResourcePath( "Animation", "models" );
	Horde:SetResourcePath( "Code", "shaders" );
	Horde:SetResourcePath( "TextureCube", "textures" );
	Horde:SetResourcePath( "Effect", "effects" );

	Horde:SetOption( "LoadTextures", HordeLoadTextures );
	Horde:SetOption( "TexCompression", HordeTexCompression );
	Horde:SetOption( "FastAnimation", HordeFastAnimation );
	Horde:SetOption( "AnisotropyFactor", HordeAnsiotropy );
	Horde:SetOption( "ShadowMapSize", HordeShadowMapSize );
	Horde:SetOption( "MaxLogLevel", HordeMaxLogLevel );

	Horde:SetOption("DebugViewMode", HordeDebugView );
	Horde:SetOption("WireframeMode", HordeWireframe );
		
  	AudioMan:SetMUSVolume(musicVolume*128);
end

function reloadMainResources()
    amBXLoadFade();
	if renderingMode == RENDERING_FAST then
	    PipeRes = Horde:AddResource( "Pipeline", "texPart.pipeline.xml" );
	elseif renderingMode == RENDERING_HDR then
	    PipeRes = Horde:AddResource( "Pipeline", "hdr.pipeline.xml" );
	end
	LogoRes = Horde:AddResource( "Material", "logo.material.xml" );
	local randAns = math.random();
	if randAns < 0.2 then
	    SplashRes = Horde:AddResource( "Material", "splash/combined_inflate.material.xml" );
	elseif randAns < 0.4 then
	    SplashRes = Horde:AddResource( "Material", "splash/transplant_screen.material.xml" );
	elseif randAns < 0.6 then
	    SplashRes = Horde:AddResource( "Material", "splash/pick_up_throw_screen.material.xml" );
	elseif randAns < 0.7 then
	    SplashRes = Horde:AddResource( "Material", "splash/Grando_combine_screen.material.xml" );
	else
	    SplashRes = Horde:AddResource( "Material", "splash/revolutionary_weedunk_loading_screen.material.xml" );
	end
	
	FontRes = Horde:AddResource( "Material", "font.material.xml" );
	Horde:LoadResourcesFromDisk( "data" );
	
	Camera:Create(PipeRes, 45.0, WindowWidth/WindowHeight, 1.0, 10000.0, "MainCamera");
	Camera:LookNorth();
	
	Horde:ShowOverlay(0, 0,   --  x,y of bot left on screen
			  0, 0,   --  u,v of above
			  1, 0,   -- top left
			  1, 0,
			  1, 1,   -- top right
			  1, 1,
			  0, 1,   -- bot right
			  0, 1,
			  7,   -- layer, 0-7
			  SplashRes );
			  
	Camera:Update();	
	Renderer:UpdateScreen();
end

function disableSplash()
	Horde:RemoveResource(SplashRes);
end
