-- Plight of the Weedunks

dofile ("data/scripts/gameplay/toothy/collisions/collision.lua");

function toothySetup()
    conveyPlayed = false;
    converyorForce = 25;		-- Force applied whilst on a conveyor belt
    weedunkConveryorForce = 5;
    
    AudioMan:SetChannels(60);

    ODE:AddNoJumpMaterial("respawnZone1");
    ODE:AddNoJumpMaterial("respawnZone2");
    ODE:AddNoJumpMaterial("respawnZone3");
    ODE:AddNoJumpMaterial("respawnZone4");
    ODE:AddNoJumpMaterial("respawnZone5");
    ODE:AddNoJumpMaterial("respawnZone6");

    openDoor = false;
    doorOpen = false;
    doorOpenTimer = 0.0;
    teeth8Falling = false;
    teeth9Falling = false;
    teeth10Falling = false;
    teeth11Falling = false;
    teeth12Falling = false;
    teeth13Falling = false;
    teeth14Falling = false;

	teeth8_posY = 9.8;
	teeth9_posY = 8.8;
	teeth10_posY = 7.8;
	teeth11_posY = 6.8;
	teeth12_posY = 5.8;
	teeth13_posY = 4.8;
	teeth14_posY = 3.8;
	Camera:LookNorth();
	Camera:SetCameraParams(5.0, 0.3, 0.1, 4.0);
	Horde:SetupModelAnimStage(LevelMod, 0, toothyDoorAnim, "toothyDoorRootJoint", false);
	Horde:SetModelAnimParams(LevelMod, 0, 2, 1.0);
	
	AudioMan:FadeOutMUS(1000);
    AudioMan:LoadMUS("toothyMusic", "data/msx/toothyMusic.ogg");
    AudioMan:LoadSFX("teethChomp", "data/sfx/toothy/teethChomp.ogg"); 
    AudioMan:LoadSFX("conveyorBelt", "data/sfx/environment/conveyorBelt.ogg");
	AudioMan:LoadSFX("toothyDoor", "data/sfx/environment/toothyDoor.ogg");
	
    AudioMan:LoadSFX("junkheadToothy1", "data/sfx/junkhead/junkheadToothy1.ogg");
	AudioMan:LoadSFX("junkheadToothy2", "data/sfx/junkhead/junkheadToothy2.ogg");
    AudioMan:LoadSFX("junkheadToothy3", "data/sfx/junkhead/junkheadToothy3.ogg");	
	
	reloadCommonVolumes();
	
	KohiDead = false;
	GrandoDead = false;  
	GrandoHitsrespawnZone2()
	KohiHitsrespawnZone2();
	KohiDead = true;
	GrandoDead = true;  
    GrandoInLimbo = 1;
    KohiInLimbo = 1;
    
    Zone5Switch = false;
    Zone6Switch = false;
    Zone7Switch = false;
    
    grandoHitZone5 = false;
    kohiHitZone5 = false;
    grandoHitZone6 = false;
    kohiHitZone6 = false;
    grandoHitZone7 = false;
    kohiHitZone7 = false;

	AI:SetWeedunkHeight(10);
	ODE:SetStepsPerFrame(2);
end
