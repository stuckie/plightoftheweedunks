-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------
dofile("data/scripts/gameplay/factorySection2/colishions/collishions.lua");

function factorySection2Setup()
	AudioMan:SetChannels(60);
    shockerEastTwoStreams = false;
    shockerWestTwoStreams = false;

	Horde:AddParticleEffect(-88.426, 44.0795, 189.818, shockerParticle);
	Horde:AddParticleEffect(-91.4011, 44.0652, 189.766, shockerParticle);
	--Horde:AddParticleEffect(0, 0, 0, fanParticle);
		
    ODE:AddNoJumpMaterial("death");
    ODE:AddNoJumpMaterial("respawn1");
    ODE:AddNoJumpMaterial("respawn2");
    ODE:AddNoJumpMaterial("respawn3");
    ODE:AddNoJumpMaterial("respawn4");
    ODE:AddNoJumpMaterial("respawn5");
    ODE:AddNoJumpMaterial("respawn6");
    ODE:AddNoJumpMaterial("respawn7");
    ODE:AddNoJumpMaterial("respawn8");
    ODE:AddNoJumpMaterial("fanForce1");
    ODE:AddNoJumpMaterial("fanForce2");
    ODE:AddNoJumpMaterial("fanForce3");
    ODE:AddNoJumpMaterial("fanForce4");
    
    PLATFORM_BLOCKED = 0;
    PLATFORM_UP = 1;
    PLATFORM_TOP = 2;
    PLATFORM_DOWN = 3;
    PLATFORM_BOT = 4;
    platformCnt = 0;
    platformStopTime = 25;
    platfromState = PLATFORM_BLOCKED;

    btnFan1Hit = false;
    btnFan2Hit = false;
    btnFan3Hit = false;
    btnFan4Hit = false;
    btnFan1HitLastFrame = false;
    btnFan2HitLastFrame = false;
    btnFan3HitLastFrame = false;
    btnFan4HitLastFrame = false;
    fan1On = false;
    fan2On = false;
    fan3On = false;
    fan4On = false;

    fan1Force = 50;
    fan2Force = 50;
    fan3ForceH = 100;
    fan3ForceV = 15;
    fan4ForceH = 100;
    fan4ForceV = 15;
    amibleFanPlayer = 75;
    amibleFanWeedunk = 12.5;
    converyorForce = 20;

    sludgeNDestroyedTime = 9999;
    sludgeSDestroyedTime = 9999;
    sludgeEDestroyedTime = 9999;
    sludgeWDestroyedTime = 9999;
    sludgeNEDestroyedTime = 9999;
    sludgeNWDestroyedTime = 9999;
    sludgeSEDestroyedTime = 9999;
    sludgeSWDestroyedTime = 9999;

    sludgeHealTime = 500;
    fallingConverF = 50;
    sludgeConverF = 50;
    
    converFalling = false;
    converFallen = false;
    
    AMIBLE_FAN_OFF = 0;
    AMIBLE_FAN_IN = 1;
    AMIBLE_FAN_OUT = 2;
    aimableFan = AMIBLE_FAN_OFF;
    
    FanAimedInHit = false;
    FanAimedOutHit = false;
    FanAimedOffHit = false;
    FanAimedInHitLast = false;
    FanAimedOutHitLast = false;
    FanAimedOffHitLast = false;
    
    KohiLoadToothy2 = false;
    GrandoLoadToothy2 = false;
    KohiLoadBang = false;
    GrandoLoadBang = false;
    
    shockerEastFilled = false;
    shockerWestFilled = false;
    doorOpened = false;
    
	KohiDead = false;
	GrandoDead = false;  
    GrandoHitsrespawn1();
    KohiHitsrespawn1();	
    KohiDead = true;
    GrandoDead = true;  
    GrandoInLimbo = 1;
    KohiInLimbo = 1;  
    
    Camera:LookSouth();
	Camera:SetCameraParams(15.0, 0.1, 1.0, 1.0);
	ODE:SetStepsPerFrame(4);
		
	fanForceAimedOut_rotX = 10;
	fanForceAimedOut_rotY = 45;
	fanForceAimedOut_rotZ = -0;
	ODE:SetMovingRot(fanForceAimedOut_scripted, fanForceAimedOut_rotX,fanForceAimedOut_rotY,fanForceAimedOut_rotZ);
		
	conveyorBelt20_posY = 62;
	ODE:SetMovingPos(conveyorBelt20_scripted, conveyorBelt20_posX,conveyorBelt20_posY,conveyorBelt20_posZ);
	
	Horde:FindNodes( LevelMod, "fanBlade1", "Mesh" );
	fanBlade1Horde = Horde:GetNodeFindResult(0);
	Horde:FindNodes( LevelMod, "fanBlade2", "Mesh" );
	fanBlade2Horde = Horde:GetNodeFindResult(0);
	Horde:FindNodes( LevelMod, "fanBlade3", "Mesh" );
	fanBlade3Horde = Horde:GetNodeFindResult(0);
	Horde:FindNodes( LevelMod, "fanBlade4", "Mesh" );
	fanBlade4Horde = Horde:GetNodeFindResult(0);
	
	Horde:SetNodeTransform(NorthEastMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
	Horde:SetNodeTransform(SouthWestMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
	Horde:SetNodeTransform(SouthEastMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
	Horde:SetNodeTransform(NorthWestMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
	Horde:SetNodeTransform(WestMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
	Horde:SetNodeTransform(EastMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
	Horde:SetNodeTransform(NorthMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
	Horde:SetNodeTransform(SouthMulchBroke, 9999,9999,9999,0,0,0,1,1,1);		
	
--  Sounds only for factorySection2	
	AudioMan:LoadSFX("allergicBlockLong", "data/sfx/environment/allergicBlockLong.ogg");
	AudioMan:LoadSFX("allergicBlockShort", "data/sfx/environment/allergicBlockShort.ogg");
	AudioMan:LoadSFX("fanStart", "data/sfx/environment/fanStart.ogg");
	AudioMan:LoadSFX("fanLooping", "data/sfx/environment/fanLooping.ogg");
	AudioMan:LoadSFX("fanFinish", "data/sfx/environment/fanFinish.ogg");
	AudioMan:LoadSFX("mulchValveBroken", "data/sfx/environment/mulchValveBroken.ogg");
	AudioMan:LoadSFX("mulchValveBrokenLoop", "data/sfx/environment/mulchValveBrokenLoop.ogg");
	AudioMan:LoadSFX("mulchValveBrokenStop", "data/sfx/environment/mulchValveBrokenStop.ogg");
	AudioMan:LoadSFX("fallingConveyor", "data/sfx/environment/fallingConveyor.ogg");
	AudioMan:LoadSFX("doorOpening", "data/sfx/environment/doorOpening.ogg");
	AudioMan:LoadSFX("junkHead2", "data/sfx/junkhead/DrJunkheadDialogue2.ogg");
	AudioMan:LoadSFX("junkHead3", "data/sfx/junkhead/DrJunkheadDialogue3.ogg");
		
	reloadCommonVolumes();
			
end
