-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Make sure we reload in our configuration data
-- Should we have lost it from changing the Script context
dofile ("data/scripts/config.sgz");
dofile("data/scripts/misc/luaPythonList.lua");

-- game config files
dofile ("data/scripts/outgameConfig.lua");
dofile ("data/scripts/ingameConfig.lua");

-- Game Scripts
dofile ("data/scripts/amBX/amBX.lua");
dofile ("data/scripts/collisions/collisions.lua");
dofile ("data/scripts/levels/level.lua");
dofile ("data/scripts/players/players.lua");
dofile ("data/scripts/camera/camera.lua");
dofile ("data/scripts/menus/menus.lua");
dofile ("data/scripts/misc/engineSetup.lua");
dofile ("data/scripts/misc/tweakingVariables.lua");
dofile ("data/scripts/controllers/controller.lua");
dofile ("data/scripts/misc/commonSound.lua");

--------------------------
--  Setup Engine Links  --
--------------------------

-- The all important Interpreter.. we get access to debugging facilities and can update the engine from here
Interpret = SGZInterpreter();

-- The Renderer.. we need this to create/resize windows amongst other things like displaying graphics ;)
Renderer = SGZRenderer();

-- The Managers -- for Audio, Control, Entities and Textures
AudioMan = SGZAudioManager();
ControlMan = SGZControlManager();
EntityMan = SGZEntityManager();
LevelMan = SGZLevelManager();

-- Links to other Systems
Horde = SGZHorde();
ODE = SGZODE();
Camera = SGZCamera();
AI = SGZAI();
EventMan = SGZEvent();
PlaybackEvents = false;

-----------------------------
-- Main Function Loop Here --
-----------------------------

function main()					-- Main Start
	runMainLoop = true;
	initRenderer();
	mainSetup();

	FrameTime = SGZTimer();
	FrameTime:Start();

	AudioMan:LoadMUS("Title", "data/msx/introMusic.ogg");
	AudioMan:FadeInMUS("Title", 1000, -1);
	loadCommonSound();

	Interpret:Update();
	mainLoopCheck();

	amBX:End();
	Renderer:Stop();
end

function mainLoopCheck()			-- Checks whether to parse the Main Loop or not
   	running = true;
	while runMainLoop == true and running == true do
       		running = Interpret:Running();
		mainLoop();
	end
	Horde:EmptySceneGraph();
	ODE:KillEverything();
end

function mainLoop()				-- The actual Main Loop
	Interpret:Update();
	updateAmBX();
    DebugKeys();

	if CurrentMenu == MENU_NONE then	
		UpdateLevel();
		UpdatePlayers();
		UpdateCamera();
		if menuPausePressed() == true then
			CurrentMenu = MENU_PAUSE;
		end
		ODE:Pause(false);
	else
		UpdateMenus();
		Camera:Update();
		ODE:Pause(true);
	end

	Horde:ClearOverlays();

--	Horde:FrameInfo(FontRes);
	
	if ChangeLevelNextUpdate == true then
	    ChangeLevel(ChangeLevelTo);
	    ChangeLevelNextUpdate = false;
	end
end

function initRenderer()				-- Starts the renderer and creates Initial stuff, so only called once!
	if Interpret:Debug() == true then
		WindowWidth = 640;
		WindowHeight = 480;
		WindowBPP = 32;
	end

	Renderer:NewWindow("Plight of The Weedunks | "  .. Interpret:SystemInfo() .. " - " .. Interpret:RenderInfo(),WindowWidth,WindowHeight,WindowBPP);

	if Interpret:Debug() == false then
        Renderer:SetFullScreen(1);
    end
	Horde:Init();
	Horde:Resize(0, 0, WindowWidth, WindowHeight);
	engineSetup();
	reloadMainResources();
	if CurrentMenu == MENU_NONE then
        loadCharData();
    	LoadLevel();
    end
	SetupMenus();
	Horde:LoadResourcesFromDisk( "data" );
	disableSplash();
end

function mainSetup()
	ODE:SetGravity(g);
	setupAmBX();
	if CurrentMenu == MENU_NONE then
	    setupCharData();
	    LoadLevelScripts();
	end
	runMainLoop = true;
end

f1Held = false;
f2Held = false;
f3Held = false;
f5Held = false;

function DebugKeys()
--[[
	if ControlMan:Get_r()==true then
		KohiDead = true;
		GrandoDead = true;

		ODE:RemoveForces(KohiODE);
		ODE:RemoveForces(GrandoODE);

		ODE:SetDynamicRot(KohiODE, 0.0, 0.0, 0.0);
		ODE:SetDynamicRot(GrandoODE, 0.0, 0.0, 0.0);
	end
]]--
	if ControlMan:Get_F1()==true and f1Held == false then
		ChangeLevel("Toothy");
		CurrentMenu = MENU_NONE;
		f1Held = true;
	end
	if ControlMan:Get_F1()==false then
	    f1Held = false;
	end

	if ControlMan:Get_F2()==true and f2Held == false then
		ChangeLevel("FactorySection1");
		CurrentMenu = MENU_NONE;
		f2Held = true;
	end
	if ControlMan:Get_F2()==false then
	    f2Held = false;
	end

	if ControlMan:Get_F3()==true and f3Held == false then
		ChangeLevel("FactorySection2");
		CurrentMenu = MENU_NONE;
		f3Held = true;
	end
	if ControlMan:Get_F3()==false then
	    f3Held = false;
	end
--[[
	if ControlMan:Get_F5()==true and f5Held == false then
		ChangeLevel("bilgeRoom");
		CurrentMenu = MENU_NONE;
		f5Held = true;
	end
	if ControlMan:Get_F5()==false then
	    f5Held = false;
	end
	
	if ControlMan:Get_F6()==true and f6Held == false then
		ChangeLevel("battleRoom");
		CurrentMenu = MENU_NONE;
		f6Held = true;
	end
	if ControlMan:Get_F6()==false then
	    f6Held = false;
	end
]]--
end
