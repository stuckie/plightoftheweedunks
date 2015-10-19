-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

--------------------------
--  Current Level Info  --
--------------------------

CurrentLevel = "None";
ChangeLevelNextUpdate = false;
ChangeLevelTo = "None";
SPAWNERS = nil;
TARGETS = nil;
WAYPOINTS = nil;
WEEDUNKS = List:new();

--------------------------
-- Level Load Functions --
--------------------------

function LoadLevel ()
    if CurrentLevel == "Toothy" then
		LevelRes = Horde:AddResource( "SceneGraph", "toothy.scene.xml" );
		toothyDoorAnim = Horde:AddResource("Animation", "toothy.anim" );
		ToothyParticleEffect = Horde:AddResource( "SceneGraph", "particles/exploshionParticle.scene.xml" );
	end

	if CurrentLevel == "FactorySection1" then
	      LevelRes = Horde:AddResource( "SceneGraph", "factorySection1.scene.xml" );
		dofile("data/scripts/levels/factorySection1/loadmeshres.lua");
		shockerParticle = Horde:AddResource( "SceneGraph", "particles/shocker.scene.xml" );
		shockerFilledParticle = Horde:AddResource( "SceneGraph", "particles/shockerFilled.scene.xml" );
		Score1 = Horde:AddResource( "Material", "score/1.material.xml" );
		Score2 = Horde:AddResource( "Material", "score/2.material.xml" );
		Score3 = Horde:AddResource( "Material", "score/3.material.xml" );
		Score4 = Horde:AddResource( "Material", "score/4.material.xml" );
		Score5 = Horde:AddResource( "Material", "score/5.material.xml" );
		Score6 = Horde:AddResource( "Material", "score/6.material.xml" );
		Score7 = Horde:AddResource( "Material", "score/7.material.xml" );
		Score8 = Horde:AddResource( "Material", "score/8.material.xml" );
		Score9 = Horde:AddResource( "Material", "score/9.material.xml" );
		Score10 = Horde:AddResource( "Material", "score/10.material.xml" );
		loadAllMeshes();
	end

	if CurrentLevel == "FactorySection2" then
		LevelRes = Horde:AddResource( "SceneGraph", "factorySection2.scene.xml" );
		shockerParticle = Horde:AddResource( "SceneGraph", "particles/shocker.scene.xml" );
		shockerFilledParticle = Horde:AddResource( "SceneGraph", "particles/shockerFilled.scene.xml" );
		fanParticle = Horde:AddResource( "SceneGraph", "particles/fanParticle.scene.xml" );
		dofile("data/scripts/levels/factorySection2/loadmeshres.lua");
		loadAllMeshes();
	end

	if CurrentLevel == "bilgeRoom" then
		LevelRes = Horde:AddResource( "SceneGraph", "bilgeRoom.scene.xml");
	end
	
	if CurrentLevel == "battleRoom" then
	    LevelRes = Horde:AddResource( "SceneGraph", "battleRoom.scene.xml");
	end

	-- Common Effects
	ExploshionParticleEffect = Horde:AddResource( "SceneGraph", "particles/exploshionParticle.scene.xml" );
	KohiRunEffect = Horde:AddResource( "SceneGraph", "particles/kohiRunParticle.scene.xml" );
	KohiDieParticleEffect = Horde:AddResource( "SceneGraph", "particles/kohiDieParticle.scene.xml" );
	GrandoDieParticleEffect = Horde:AddResource( "SceneGraph", "particles/grandoDieParticle.scene.xml" );
	GrandoRocketParticleEffect = Horde:AddResource( "SceneGraph", "particles/grandoRocketParticle.scene.xml" );
	BertDieParticleEffect = Horde:AddResource( "SceneGraph", "particles/bertDieParticle.scene.xml" );
	ErnieDieParticleEffect = Horde:AddResource( "SceneGraph", "particles/ernieDieParticle.scene.xml" );
	WallParticleEffect = Horde:AddResource( "SceneGraph", "particles/wallParticle.scene.xml" );
	SludgeParticleEffect = Horde:AddResource( "SceneGraph", "particles/sludgeParticle.scene.xml" );
	SludgePipeParticleEffect = Horde:AddResource( "SceneGraph", "particles/sludgePipeParticle.scene.xml" );

	LightMat = Horde:AddResource( "Material", "light.material.xml" );
	ButtonRes = Horde:AddResource( "SceneGraph", "buttonMesh.scene.xml" );

	-- Common Level Elements
	SPAWNERS = nil;
	TARGETS = nil;
	WAYPOINTS = nil;
	WEEDUNKS:clear();

	ODE:CreateStaticPlane(0, 1, 0, -250, "deathPlane");
	ODE:CreateStaticPlane(0, -1, 0, -250, "deathPlane");
	ODE:CreateStaticPlane(1, 0, 0, -250, "deathPlane");
	ODE:CreateStaticPlane(-1, 0, 0, -250, "deathPlane");
	ODE:CreateStaticPlane(0, 0, 1, -250, "deathPlane");
	ODE:CreateStaticPlane(0, 0, -1, -250, "deathPlane");

end

function UnloadLevel()
    if CurrentLevel == "Toothy" then
        toothy_UNLOAD();
    end
    if CurrentLevel == "FactorySection1" then
        factorySection1_UNLOAD();
    end
    if CurrentLevel == "FactorySection2" then
        factorySection2_UNLOAD();
    end
    if CurrentLevel == "bilgeRoom" then
        bilgeRoom_UNLOAD();
    end
    if CurrentLevel == "battleRoom" then
        battleRoom_UNLOAD();
    end
end

function LoadLevelScripts()

	Interpret:LogDebug("Adding Level Nodes\n");
	LevelMod = Horde:AddNodes ( 0, LevelRes );
	Interpret:LogDebug("Moving Level\n");
	Horde:SetNodeTransform( LevelMod, 0,0,0 ,0,0,0 ,1,1,1 );

	if CurrentLevel == "Toothy" then	
		dofile ("data/scripts/levels/toothy/toothy.load.lua");
		dofile ("data/scripts/levels/toothy/toothy.update.lua");
		toothy_LOAD();
	end

	if CurrentLevel == "FactorySection1" then
		dofile ("data/scripts/levels/factorySection1/factorySection1.load.lua");
		dofile ("data/scripts/levels/factorySection1/factorySection1.update.lua");
		factorySection1_LOAD();
	end

	if CurrentLevel == "FactorySection2" then
		dofile ("data/scripts/levels/factorySection2/factorySection2.load.lua");
		dofile ("data/scripts/levels/factorySection2/factorySection2.update.lua");
		factorySection2_LOAD();
	end

	if CurrentLevel == "bilgeRoom" then
		dofile ("data/scripts/levels/bilgeRoom/bilgeRoom.load.lua");
		dofile ("data/scripts/levels/bilgeRoom/bilgeRoom.update.lua");
		bilgeRoom_LOAD();
	end
	
	if CurrentLevel == "battleRoom" then
		dofile ("data/scripts/levels/battleRoom/battleRoom.load.lua");
		dofile ("data/scripts/levels/battleRoom/battleRoom.update.lua");
		battleRoom_LOAD();
	end
end

function UpdateLevel ()

	if CurrentLevel == "Toothy" then
		toothy_UPDATE();
	end

	if CurrentLevel == "FactorySection1" then
		factorySection1_UPDATE();
	end

	if CurrentLevel == "FactorySection2" then
		factorySection2_UPDATE();
	end

	if CurrentLevel == "bilgeRoom" then
		bilgeRoom_UPDATE();
	end
	
	if CurrentLevel == "battleRoom" then
		battleRoom_UPDATE();
	end

	-- Common Level Updates
	local list = SPAWNERS;
	while list do
		if ( list.bert < list.numofbert ) and ( list.timer > list.delay ) then
			spawnEntity( "WEEDUNK_BERT", list.x, list.y, list.z, 0, weedunkSpawnForce, 0, list.name );
			list.timer = 0;
			list.bert = list.bert + 1;
		end
		if ( list.ernie < list.numofernie ) and ( list.timer > list.delay ) then
			spawnEntity( "WEEDUNK_ERNIE", list.x, list.y, list.z, 0, weedunkSpawnForce, 0, list.name );
			list.timer = 0;
			list.ernie = list.ernie + 1;
		end
		list.timer = list.timer + 1;
		list = list.next;
	end

end

function ChangeLevel ( NewLevel )
	UnloadLevel();
	Horde:ClearOverlays();
	Horde:EmptySceneGraph();
	
    CurrentLevel = NewLevel;

	ODE:KillEverything();
	AI:Reset();
	ODE:SetGravity(g);
	engineSetup();
	reloadMainResources();
	loadCharData();
	SetupMenus();
	LoadLevel();
	Horde:LoadResourcesFromDisk( "data" );
	setupCharData();
	LoadLevelScripts();
	disableSplash();
end

function ChangeLevelOnNextUpdate( NewLevel )
    ChangeLevelNextUpdate = true;
    ChangeLevelTo = NewLevel;
end
