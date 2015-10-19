-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------
dofile("data/scripts/gameplay/factorySection1/collisions/collisions.lua");

bugSteps = 0;

function factorySection1Setup()
    AudioMan:RemoveMUS("toothyMusic");
    AudioMan:LoadMUS("factoryMusic", "data/msx/factoryMusic.ogg");
    AudioMan:FadeInMUS("factoryMusic",1000);
    
    -- only for this level
    AudioMan:LoadSFX("breakableBoard", "data/sfx/environment/breakableBoard.ogg");
    AudioMan:LoadSFX("bugSteps", "data/sfx/environment/bugSteps.ogg");
    AudioMan:LoadSFX("bugStepsLock", "data/sfx/environment/bugStepsLock.ogg");
    AudioMan:LoadSFX("bugStepsWithWood", "data/sfx/environment/bugStepsWithWood.ogg");
    AudioMan:LoadSFX("openGrate", "data/sfx/environment/openGrate.ogg");
    AudioMan:LoadSFX("risingFloor", "data/sfx/environment/risingFloor.ogg");
    AudioMan:LoadSFX("wallExploding", "data/sfx/environment/wallExploding.ogg");
    
    -- Junkhead Dialogue
    AudioMan:LoadSFX("Junkhead1", "data/sfx/junkhead/DrJunkheadDialogue1.ogg");
    AudioMan:LoadSFX("Tip1", "data/sfx/junkhead/junkheadTip1.ogg");
    AudioMan:LoadSFX("Tip2", "data/sfx/junkhead/junkheadTip2.ogg");
    AudioMan:LoadSFX("Tip3", "data/sfx/junkhead/junkheadTip3.ogg");
    
    -- common to section 2
    AudioMan:LoadSFX("button", "data/sfx/environment/button.ogg");
    AudioMan:LoadSFX("conveyorBelt", "data/sfx/environment/conveyorBelt.ogg");
    AudioMan:LoadSFX("conveyorTower", "data/sfx/environment/conveyorTower.ogg");
    AudioMan:LoadSFX("junkheadScreenOn", "data/sfx/environment/junkheadScreenOn.ogg");
    AudioMan:LoadSFX("junkheadScreenOff", "data/sfx/environment/junkheadScreenOff.ogg");
    AudioMan:LoadSFX("lumpsBeingMulched", "data/sfx/environment/lumpsBeingMulched.ogg");
    AudioMan:LoadSFX("mincer", "data/sfx/environment/mincer.ogg");
    AudioMan:LoadSFX("mulchPipe", "data/sfx/environment/mulchPipe.ogg");
    AudioMan:LoadSFX("weedunkShockerShocking", "data/sfx/environment/weedunkShockerShocking.ogg");
    AudioMan:LoadSFX("weedunkShockerCurrent", "data/sfx/environment/weedunkShockerCurrent.ogg");
    
	Camera:LookSouth();
	Camera:SetCameraParams(15.0, 0.1, 1.0, 1.0);
	conveyorForce = 20;
    AI:SetWaypointSize(0.5);
	AI:SetIdleDanceTime(1000);
	AI:SetIdleChangeDir(50);
	AI:SetWeedunkHeight(0.45);

	Horde:FindNodes( LevelMod, "bugSteps", "Mesh" );
	bugSteps = Horde:GetNodeFindResult(0);
	ODE:SetStepsPerFrame(4);

	floatingThenSinkingPlatform_posZ = 220;
	floatingThenSinkingPlatform1_posZ = 230;
	floatingThenSinkingPlatform3_posZ = 240;
	  
	KohiDead = false;
	GrandoDead = false;  
	GrandoHitszone1()
	KohiHitszone1();
	KohiDead = true;
	GrandoDead = true;  
    GrandoInLimbo = 1;
    KohiInLimbo = 1;
    
	Horde:AddParticleEffect(-45.8468, 14.5333, 211.195, shockerParticle);
	Horde:AddParticleEffect(-91.4013, 14.5333, 211.195, shockerParticle);
	    
end
