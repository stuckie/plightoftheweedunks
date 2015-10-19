-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------
KohiWeedunkTimer = 0.0;
--------------------------
-- Kohi Player Control  --
--------------------------

dofile("data/scripts/players/kohi/kohiAnimations.lua");
dofile("data/scripts/players/kohi/kohiUserMove.lua");
dofile("data/scripts/players/kohi/kohiWeedunkUserMove.lua");

--------------------------
-- Grando Player Control--
--------------------------

dofile("data/scripts/players/grando/grandoAnimations.lua");
dofile("data/scripts/players/grando/grandoUserMove.lua");
dofile("data/scripts/players/grando/grandoWeedunkUserMove.lua");

--------------------------
-- combined float Player Control--
--------------------------

dofile("data/scripts/players/userMoveCombinedFloat.lua");

--------------------------
-- Spawn Creation Utils --
--------------------------

dofile ("data/scripts/players/spawn.lua");

--------------------------
-- UI --
--------------------------

dofile ("data/scripts/players/ui.lua");

--------------------------
--  Player Information  --
--------------------------

KohiAndGrandoAreCombined = false;
KohiControl = 1;
GrandoControl = 2;
animTime = 0.0;
animTime2 = 0.0;
GrandoPickup = false;
GrandoCarryingWeedunk = false;
KohiPickup = false;
KohiCarryingWeedunk = false;
KohiExploshionCnt = 99999999999999;
GrandoFloatCnt = 99999999999999;
KohiAndGrandoCombinedCnt = 99999999999999;
KohiDead = false;
GrandoDead = false;
spaceP = false;
GrandoControlingWeedunk = false;		-- when the grando player is controling a weedunk
GrandoWeedunkODE = 0;
KohiControlingWeedunk = false;		-- when kohi is controling a weedunk
KohiWeedunkODE = 0;
KohiDunkInHand = 0;
GrandoDunkInHand = 0;
WeedunkGrandoSpawn = false;		-- if grando has just taken control of a weedunk
WeedunkGrandoSpawnX = 0;
WeedunkGrandoSpawnY = 0;
WeedunkGrandoSpawnZ = 0;
WeedunkKohiSpawn = false;
WeedunkKohiSpawnX = 0;
WeedunkKohiSpawnY = 0;
WeedunkKohiSpawnZ = 0;
GrandoBesideWeedunk = false; -- when grando is beside a weedunk
GrandoCanCombine = false; -- when grando is beside a kohi
KohiBesideWeedunk = false; -- when Kohi is beside a weedunk
KohiCanCombine = false; -- when Kohi is beside a Grando

-- the possition players will spawn at should they be killed
grandoSpawnX = 0;
grandoSpawnY = 0;
grandoSpawnZ = 0;
kohiSpawnX = 0;
kohiSpawnY = 0;
kohiSpawnZ = 0;

KohiInLimbo = 0;
GrandoInLimbo = 0;
weedunkToLookAt = 0;

KohiBell = 0;
GrandoBrainMod = 0;
KohiFloatMod = 0;
floating = false;

Gx = 0;
Gy = 0;
Gz = 0;
Kx = 0;
Ky = 0;
Kz = 0;

--------------------------
--  Player Update Func  --
--------------------------

function loadCharData()
	KohiRes = Horde:AddResource( "SceneGraph", "Kohi.scene.xml" );
	KohiBellRes = Horde:AddResource( "SceneGraph", "kohi_BELLMESH.scene.xml");
	KohiAnim_Idle = Horde:AddResource("Animation", "kohi_Idle.anim" );
	KohiAnim_Run = Horde:AddResource("Animation", "kohi_RunCycle.anim" );
	KohiAnim_Jump = Horde:AddResource("Animation", "kohi_Jump.anim" );
	KohiAnim_JumpDunk = Horde:AddResource("Animation", "kohi_JumpWithWeedunk.anim" );
	KohiAnim_Explode = Horde:AddResource("Animation", "kohi_Explode.anim" );
	KohiAnim_Pickup = Horde:AddResource("Animation", "kohi_PickUp.anim" );
	KohiAnim_Death = Horde:AddResource("Animation", "kohi_Death.anim" );
	KohiAnim_Braindead = Horde:AddResource("Animation", "kohi_Braindead.anim" );
	KohiAnim_IdleDunk = Horde:AddResource("Animation", "kohi_IdleWithWeedunk.anim" );
	KohiAnim_InAir = Horde:AddResource("Animation", "kohi_InAir.anim" );
	KohiAnim_Transplant = Horde:AddResource("Animation", "kohi_Transplant.anim" );
	KohiAnim_RunDunk = Horde:AddResource("Animation", "kohi_RunWithWeedunk.anim" );
	KohiAnim_ThrowDunk = Horde:AddResource("Animation", "kohi_ThrowWeedunk.anim" );
	KohiAnim_Combine = Horde:AddResource("Animation", "kohi_CombineFloat.anim" );

	GrandoRes = Horde:AddResource( "SceneGraph", "grando.scene.xml" );
	GrandoBrainRes = Horde:AddResource( "SceneGraph", "grando_brain.scene.xml");
	GrandoAnim_Idle = Horde:AddResource( "Animation", "grando_Idle.anim" );
	GrandoAnim_Run = Horde:AddResource( "Animation", "grando_RunCycle.anim" );
	GrandoAnim_Jump = Horde:AddResource ( "Animation", "grando_Jump.anim" );
	GrandoAnim_JumpInAir = Horde:AddResource ( "Animation", "grando_inAir.anim" );
	GrandoAnim_AirDunk = Horde:AddResource ( "Animation", "grando_inAirDunk.anim" );
	GrandoAnim_Death = Horde:AddResource ( "Animation", "grando_Death.anim" );
	GrandoAnim_Inflate = Horde:AddResource ( "Animation", "grando_Inflate.anim" );
	GrandoAnim_Pickup = Horde:AddResource ( "Animation", "grando_PickupDunk.anim" );
	GrandoAnim_IdleDunk = Horde:AddResource ( "Animation", "grando_IdleDunk.anim" );
	GrandoAnim_Braindead = Horde:AddResource ( "Animation", "grando_Braindead.anim" );
	GrandoAnim_Transplant = Horde:AddResource ( "Animation", "grando_Transplant.anim" );
	GrandoAnim_RunDunk = Horde:AddResource ( "Animation", "grando_RunDunk.anim" );
	GrandoAnim_Float = Horde:AddResource ( "Animation", "grando_Float.anim" );
	GrandoAnim_ThrowDunk = Horde:AddResource ( "Animation", "grando_ThrowDunk.anim" );
	GrandoAnim_JumpDunk = Horde:AddResource ( "Animation", "grando_JumpDunk.anim");
	
	WeedunkBertRes = Horde:AddResource( "SceneGraph", "WeedunkBLU.scene.xml" );
	WeedunkErnieRes = Horde:AddResource( "SceneGraph", "WeedunkRED.scene.xml" );
	WeedunkAnim_Idle = Horde:AddResource( "Animation", "weedunk_Idle.anim");
	WeedunkAnim_Walk = Horde:AddResource( "Animation", "weedunk_Walk.anim");
	WeedunkAnim_Work = Horde:AddResource( "Animation", "weedunk_Work.anim");
	WeedunkAnim_Wiggle = Horde:AddResource( "Animation", "weedunk_Wiggle.anim");
	WeedunkAnim_InAir = Horde:AddResource( "Animation", "weedunk_InAir.anim");
	
	bugLockAnim = Horde:AddResource( "Animation", "buglockBolt.anim" );

    LoadUI();
end

function setupCharData()
	KohiMod  = Horde:AddNodes( 0, KohiRes);
	KohiODE = ODE:CreateDynamicCapsule(0.55, 1.20, 0, 0.20, 0.20, 0.5, "Kohi");
	KohiPickupBox = ODE:CreateMovingBox(1.4, 1.4, 1.4, 0, 0.0, 0.0, 0,0,0, "KohiPickupBox");
	ODE:SetOffset(KohiODE, 0.0, 6, 0.0);    --gets scaled
	KohiExploshionSphere = ODE:CreateDynamicSphere(2.5, -9999.0, -9999.0, -9999.0, 1.0, "KohiExploshion");
	ODE:TurnOffGravityFor(KohiExploshionSphere);
	KohiJumpRay = ODE:AddJumpRay(0.7, 0, 0, 0, KohiODE);
	Horde:FindNodes( KohiMod, "Bell_Mover", "Joint" );
	KohiBellNode = Horde:GetNodeFindResult( 0 );
	KohiBellMod = Horde:AddNodes ( KohiBellNode, KohiBellRes );

	GrandoMod  = Horde:AddNodes( 0, GrandoRes);
	GrandoODE = ODE:CreateDynamicCapsule(0.65, 1.80, 0, 2.0, -2.0, 0.5, "Grando");
	GrandoPickupBox = ODE:CreateMovingBox(1.8, 2, 1.8, 0, 0.0, 0.0, 0,0,0, "GrandoPickupBox");
	ODE:SetOffset(GrandoODE, 0.0, 9, 0.0);  --gets scaled
	GrandoJumpRay = ODE:AddJumpRay(1.0, 0, 0, 0, GrandoODE);
	
	setupKohiAnimations();
	setupGrandoAnimations();

	PlayerOneModel = KohiODE;
	PlayerTwoModel = GrandoODE;

	AI:SetWeedunkMoveForce(5);
	AI:SetWaypointSize(1);         -- play with
	AI:SetMaxDistToWalk(120);       --played with
	AI:SetIdleDanceTime(500);
	AI:SetIdleChangeDir(25);
	AI:SetWeedunkHeight(0.45);
	
	ODE:AddNoJumpMaterial("KohiPickupBox");
	ODE:AddNoJumpMaterial("KohiExploshion");
	ODE:AddNoJumpMaterial("GrandoPickupBox");
	ODE:AddNoJumpMaterial("weedunkPortal");
end

function UpdatePlayers()
	KohiExplodes();
	GrandoFloats();
	GrandoFloatsWithKohi()
	SpawnPlayerWeedunks();
	ShowUIOverlays();

	UpdateWeedunkMovement();

	if iceRink == true then
		ODE:ApplyDampingForceHorizontally(KohiODE, 0.999);		-- damping ie, fritional forces being applied to kill slipping
		ODE:ApplyDampingForceHorizontally(GrandoODE, 0.999);
	else
		ODE:ApplyDampingForceHorizontally(KohiODE, normalDamping);		-- damping ie, fritional forces being applied to kill slipping
		ODE:ApplyDampingForceHorizontally(GrandoODE, normalDamping);     -- TODO make tweekable
	end

	if KohiAndGrandoCombinedCnt < KohiAndGrandoCombinedMax then	-- if there combined and floating a different control mech is in place
		userMoveCombinedFloat();
		PlayerOneModel = GrandoODE;
		PlayerTwoModel = GrandoODE;
		ODE:LimitVertVel(GrandoODE, GrandoMaxVertVelFloating);
		ODE:LimitVertVel(KohiODE, GrandoMaxVertVelFloating);
	else
		if GrandoControlingWeedunk == true then
			userMoveGrandoWeedunk();
			PlayerTwoModel = GrandoWeedunkODE;
		else
			userMoveGrando();
			PlayerTwoModel = GrandoODE;
		end
		if KohiControlingWeedunk == true then
			userMoveKohiWeedunk();
			PlayerOneModel = KohiWeedunkODE;
		else
			userMoveKohi();
			PlayerOneModel = KohiODE;
		end
	end
	if GrandoFloatCnt < GrandoFloatTimeMax then
	    ODE:LimitVertVel(GrandoODE, GrandoMaxVertVelFloating);
	end

	ODE:SetDynamicRot(KohiODE, 90.0, 0.0, 0.0);			-- reset rotations meening that the capsuals are always upright
	ODE:SetDynamicRot(GrandoODE, 90.0, 0.0, 0.0);

	Horde:SetPlayerTransform( KohiMod, KohiODE, KohiRot, 0.1 );		-- set graphics to match physics
	Horde:SetPlayerTransform( GrandoMod, GrandoODE, GrandoRot, 0.1 );

	playKohiAnimations();
	playGrandoAnimations();

	Kx,Ky,Kz = ODE:GetDynamicPos(KohiODE);			-- misc other objects
	ODE:SetMovingPos(KohiPickupBox, Kx,Ky,Kz);
	ODE:SetJumpRayPos(KohiJumpRay, Kx,Ky,Kz);

	Gx,Gy,Gz = ODE:GetDynamicPos(GrandoODE);
	ODE:SetMovingPos(GrandoPickupBox, Gx,Gy,Gz);
	ODE:SetJumpRayPos(GrandoJumpRay, Gx,Gy,Gz);
	
    RespawnPlayersIfDead(); 

	if (ControlMan:Get_space()==true or ControlMan:Get_PadButton(1, PS2_Select)) and spaceP == false then
		local tmp = GrandoControl;
		GrandoControl = KohiControl;
		KohiControl = tmp;
		Horde:ShowText("Changing Players!", 0, 0.04, 0.03, 7, FontRes);
		spaceP = true;
	end

	if (ControlMan:Get_space()==false or ControlMan:Get_PadButton(1, PS2_Select)==false) and spaceP == true then
		spaceP = false;
	end
	
	GrandoBesideWeedunk = false; -- when grando is beside a weedunk
    GrandoCanCombine = false; -- when grando is beside a kohi
    KohiBesideWeedunk = false; -- when Kohi is beside a weedunk
    KohiCanCombine = false; -- when Kohi is beside a Grando
    
    if GrandoInLimbo>0 and KohiInLimbo == 0 then
        if KohiControlingWeedunk == true then
            PlayerOneModel = KohiWeedunkODE;
            PlayerTwoModel = KohiWeedunkODE;
        else
            PlayerOneModel = KohiODE;
            PlayerTwoModel = KohiODE;
        end
    elseif GrandoInLimbo == 0 and KohiInLimbo > 0 then
        if GrandoControlingWeedunk == true then
            PlayerOneModel = GrandoWeedunkODE;
            PlayerTwoModel = GrandoWeedunkODE;
        else
            PlayerOneModel = GrandoODE;
            PlayerTwoModel = GrandoODE;
        end
    end
end

function KohiExplodes()
	if KohiExploshionCnt == 0 then
		Horde:AddParticleEffect(KohiMod, ExploshionParticleEffect);
		Horde:AddParticleEffect(KohiMod, KohiRunEffect);
		
		local tmpX, tmpY, tmpZ;
		tmpX, tmpY, tmpZ = Horde:GetNodeTransform(KohiMod);
		ODE:SetDynamicPos(KohiExploshionSphere, tmpX, tmpY, tmpZ);

		changeKohiAnimations(KohiAnimExplode, KohiAnimExplode);
		changeKohiAnimation = true;
		KohiExplodeAnimChange = false;
		KohiIdle = true;
		
		AudioMan:PlaySFX("kohiExplode");
		
		Camera:TurnOnShakeCam(5, 1.0);
	end

	if KohiExploshionCnt > 0 then
		ODE:SetDynamicPos(KohiExploshionSphere, -9999.0, -9999.0, -9999.0);
	end

	KohiExploshionCnt = KohiExploshionCnt+1;
end

function GrandoFloats()
	
	if GrandoFloatCnt < GrandoFloatTimeMax then
		GrandoFloat = true;
		ODE:ApplyForce(GrandoODE, 0, grandoConstantFloatForce, 0);
	end
	if GrandoFloatCnt == GrandoFloatTimeMax then
		changeGrandoAnimations(GrandoAnimJumpInAir,GrandoAnimJumpInAir);
		GrandoFloat = false;
	end
	GrandoFloatCnt = GrandoFloatCnt + 1;
end

function GrandoFloatsWithKohi()
    if KohiAndGrandoCombinedCnt == 0 then
        changeGrandoAnimations(GrandoAnimInflate,GrandoAnimInflate);
        changeKohiAnimations(KohiAnimInAir, KohiAnimInAir);
        ODE:SetDynamicPos(GrandoODE, Gx,Gy+2.0,Gz);
        KohiFloatMod = Horde:AddNodes(GrandoMod, KohiRes);
	    Horde:SetNodeTransform(KohiFloatMod, 0.0, 2.0, 0.0, 0,0,0, 1,1,1);
	    if KohiDunkInHand > 0  then
			Horde:RemoveNodes(KohiDunkInHand);
			KohiDunkInHand = 0;
		end
	KohiAndGrandoAreCombined = true;
    end
	if KohiAndGrandoCombinedCnt < KohiAndGrandoCombinedMax then
	    Horde:SetNodeActivation(KohiMod, false);
	    Horde:SetupModelAnimStage( KohiFloatMod, 0, KohiAnim_Combine, "", false );
	    Horde:SetModelAnimParams( KohiFloatMod, 0, nextGrandoAnimTimer, 1.0);
	    ODE:ApplyForce(GrandoODE, 0, 35, 0);
	    ODE:ApplyForce(KohiODE, 0, 35, 0);
	    floating = true;
	end
	if KohiAndGrandoCombinedCnt == KohiAndGrandoCombinedMax and floating == true then
	    Horde:SetNodeActivation(KohiMod, true);
        Horde:RemoveNodes(KohiFloatMod);
        floating = false;
		KohiAndGrandoAreCombined = false;
    end
	KohiAndGrandoCombinedCnt = KohiAndGrandoCombinedCnt + 1;
end

function SpawnPlayerWeedunks()	-- will spaw player contoled weedunks as required
	if WeedunkGrandoSpawn == true then
		spawnEntity("WEEDUNK_GRANDO", WeedunkGrandoSpawnX, WeedunkGrandoSpawnY, WeedunkGrandoSpawnZ, 0,0,0, "Grando");
		WeedunkGrandoSpawn = false;
	end
	if WeedunkKohiSpawn == true then
		spawnEntity("WEEDUNK_KOHI", WeedunkKohiSpawnX, WeedunkKohiSpawnY, WeedunkKohiSpawnZ, 0,0,0, "Kohi");
		WeedunkKohiSpawn = false;
	end
end

function UpdateWeedunkMovement()
	local Kx,Ky,Kz = ODE:GetDynamicPos(KohiODE);
	local Gx,Gy,Gz = ODE:GetDynamicPos(GrandoODE);

    for i,weedunklist in ipairs(WEEDUNKS) do
        if weedunklist.weedunk == weedunkBert or weedunklist.weedunk == weedunkErnie then
			if iceRink == true then
				ODE:ApplyDampingForceHorizontally(weedunklist.physics, 0.999);		-- damping ie, fritional forces being applied to kill slipping
			else
				ODE:ApplyDampingForceHorizontally(weedunklist.physics, normalDamping);		-- damping ie, fritional forces being applied to kill slipping
			end

			ODE:SetDynamicRot(weedunklist.physics, 90.0, 0.0, 0.0);
			Horde:SetPlayerTransform( weedunklist.node, weedunklist.physics, AI:GetWeedunkRot(weedunklist.ai), 0.1 );
			if AI:GetWeedunkState(weedunklist.ai) == "Idle" then 
				Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 0.0); 
				Horde:SetModelAnimParams( weedunklist.node , 1, weedunklist.animTime, 1.0); 
				Horde:SetModelAnimParams( weedunklist.node , 2, weedunklist.animTime, 0.0);
				if weedunklist.soundPlay == 0 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                    AudioMan:SetDistance( weedunklist.soundChan, dist );
	                    AudioMan:PlaySFX("weedunkWalkingMumble1",0,weedunklist.soundChan);
				        weedunklist.soundPlay = 1;
				    end
				end
				if weedunklist.soundPlay == 1 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        AudioMan:SetDistance( weedunklist.soundChan, dist );
				    else
				        weedunklist.soundPlay = 0;
				        AudioMan:StopCHAN(weedunklist.soundChan);
				    end
				    weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
				end
				if weedunklist.animTime >= 16 then weedunklist.animTime = 0; end
			end
			if AI:GetWeedunkState(weedunklist.ai) == "Walking" then 
				Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 0.0); 
				Horde:SetModelAnimParams( weedunklist.node , 1, weedunklist.animTime, 1.0); 
				Horde:SetModelAnimParams( weedunklist.node , 2, weedunklist.animTime, 0.0);
                if weedunklist.soundPlay == 0 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                    AudioMan:SetDistance( weedunklist.soundChan, dist );
	                    AudioMan:PlaySFX("weedunkWalkingMumble2",0,weedunklist.soundChan);
				        weedunklist.soundPlay = 1;
				    end
				end
				if weedunklist.soundPlay == 1 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        AudioMan:SetDistance( weedunklist.soundChan, dist );
				    else
				        weedunklist.soundPlay = 0;
				        AudioMan:StopCHAN(weedunklist.soundChan);
				    end
				    weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
				end 
				if weedunklist.animTime >= 16 then weedunklist.animTime = 0; end
			end
			if AI:GetWeedunkState(weedunklist.ai) == "Working" then 
				Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 0.0); 
				Horde:SetModelAnimParams( weedunklist.node , 1, weedunklist.animTime, 0.0); 
				Horde:SetModelAnimParams( weedunklist.node , 2, weedunklist.animTime, 1.0); 
				if weedunklist.soundPlay == 0 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                    AudioMan:SetDistance( weedunklist.soundChan, dist );
	                    AudioMan:PlaySFX("weedunkWorking",0,weedunklist.soundChan);
				        weedunklist.soundPlay = 1;
				    end
				end
				if weedunklist.soundPlay == 1 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        AudioMan:SetDistance( weedunklist.soundChan, dist );
				    else
				        weedunklist.soundPlay = 0;
				        AudioMan:StopCHAN(weedunklist.soundChan);
				    end
				    weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
				end
				if weedunklist.animTime >= 39 then weedunklist.animTime = 0; end
			end
			if AI:GetWeedunkState(weedunklist.ai) == "Dancing" then 
				Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 1.0); 
				Horde:SetModelAnimParams( weedunklist.node , 1, weedunklist.animTime, 0.0); 
				Horde:SetModelAnimParams( weedunklist.node , 2, weedunklist.animTime, 0.0); 
				if weedunklist.soundPlay == 0 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                    AudioMan:SetDistance( weedunklist.soundChan, dist );
	                    local randAns = math.random();
	                    if randAns < 0.333 then
	                        AudioMan:PlaySFX("weedunkDance1",0,weedunklist.soundChan);
	                    elseif randAns < 0.666 then
	                        AudioMan:PlaySFX("weedunkDance2",0,weedunklist.soundChan);
	                    else
	                        AudioMan:PlaySFX("weedunkDance3",0,weedunklist.soundChan);
	                    end
				        weedunklist.soundPlay = 1;
				    end
				end
				if weedunklist.soundPlay == 1 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    --local dist = 300;
				    if dist < 255 then
				        AudioMan:SetDistance( weedunklist.soundChan, dist );
				    else
				        weedunklist.soundPlay = 0;
				        AudioMan:StopCHAN(weedunklist.soundChan);
				    end
				    weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
				end
				if weedunklist.animTime >= 40 then weedunklist.animTime = 0; end
			end
			
			local x,y,z  = ODE:GetDynamicPos(weedunklist.physics);
			local Gdist = (x-Gx)*(x-Gx) +(y-Gy)*(y-Gy) +(z-Gz)*(z-Gz);
			local Kdist = (x-Kx)*(x-Kx) +(y-Ky)*(y-Ky) +(z-Kz)*(z-Kz);
			
			if Gdist > weedunkCullDistSquared and Kdist > weedunkCullDistSquared then 
                killWeedunk(weedunklist.physics); 			    
			end
        elseif weedunklist.spawner == "Kohi" or weedunklist.spawner == "Grando" then	-- if the charecter was spawned from either kohi or grando taking control then the rotation stays the same
			if weedunklist.physics == GrandoWeedunkODE then	-- if currently under control rotate weedunk
			    weedunklist.rot = GrandoWeedunkRot;
			    GrandoWeedunk = weedunklist.node;
			    if GrandoControlingWeedunk then
			        weedunklist.animTime = GrandoWeedunkTimer;
			    else
			        Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 1.0); 
			        Horde:SetModelAnimParams( weedunklist.node , 1, weedunklist.animTime, 0.0); 
			        Horde:SetModelAnimParams( weedunklist.node , 2, weedunklist.animTime, 0.0); 
			        if weedunklist.soundPlay == 0 then
				        local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				        local dist = calcSoundDistance( tx,ty,tz );
				        if dist < 255 then
				            weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                        AudioMan:SetDistance( weedunklist.soundChan, dist );
	                        AudioMan:PlaySFX("weedunkTransplantWalking",0,weedunklist.soundChan);
				            weedunklist.soundPlay = 1;
				        end
				    end
				    if weedunklist.soundPlay == 1 then
				        local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				        local dist = calcSoundDistance( tx,ty,tz );
				        if dist < 255 then
    				        AudioMan:SetDistance( weedunklist.soundChan, dist );
	    			    else
		    		        weedunklist.soundPlay = 0;
			    	        AudioMan:StopCHAN(weedunklist.soundChan);
				        end
				        weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
				    end
			        if weedunklist.animTime >= 40 then weedunklist.animTime = 0; end
			    end
			elseif weedunklist.physics == KohiWeedunkODE then	-- if currently under control rotate weedunk
			    weedunklist.rot = KohiWeedunkRot;
			    KohiWeedunk = weedunklist.node;
			    if KohiControlingWeedunk then
			        weedunklist.animTime = KohiWeedunkTimer;
			    else
			        Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 1.0); 
			        Horde:SetModelAnimParams( weedunklist.node , 1, weedunklist.animTime, 0.0); 
			        Horde:SetModelAnimParams( weedunklist.node , 2, weedunklist.animTime, 0.0); 
			        if weedunklist.soundPlay == 0 then
				        local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				        local dist = calcSoundDistance( tx,ty,tz );
				        if dist < 255 then
				            weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                        AudioMan:SetDistance( weedunklist.soundChan, dist );
	                        AudioMan:PlaySFX("weedunkTransplantWalking",0,weedunklist.soundChan);
				            weedunklist.soundPlay = 1;
				        end
				    end
				    if weedunklist.soundPlay == 1 then
				        local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				        local dist = calcSoundDistance( tx,ty,tz );
				        if dist < 255 then
    				        AudioMan:SetDistance( weedunklist.soundChan, dist );
	    			    else
		    		        weedunklist.soundPlay = 0;
			    	        AudioMan:StopCHAN(weedunklist.soundChan);
				        end
				        weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
				    end
			        if weedunklist.animTime >= 40 then weedunklist.animTime = 0; end
			    end
			else
			    Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 1.0); 
			    Horde:SetModelAnimParams( weedunklist.node , 1, weedunklist.animTime, 0.0); 
			    Horde:SetModelAnimParams( weedunklist.node , 2, weedunklist.animTime, 0.0); 
			    if weedunklist.soundPlay == 0 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    if dist < 255 then
				        weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                    AudioMan:SetDistance( weedunklist.soundChan, dist );
	                    AudioMan:PlaySFX("weedunkTransplantWalking",0,weedunklist.soundChan);
				        weedunklist.soundPlay = 1;
				    end
				end
				if weedunklist.soundPlay == 1 then
				    local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
				    local dist = calcSoundDistance( tx,ty,tz );
				    if dist < 255 then
    			     AudioMan:SetDistance( weedunklist.soundChan, dist );
	    		    else
		    	        weedunklist.soundPlay = 0;
			   	        AudioMan:StopCHAN(weedunklist.soundChan);
			        end
			        weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
			    end
			    if weedunklist.animTime >= 40 then weedunklist.animTime = 0; end
			end
			ODE:SetDynamicRot(weedunklist.physics, 90.0, 0.0, 0.0);
			if iceRink == true then
				ODE:ApplyDampingForceHorizontally(weedunklist.physics, 0.999);		-- damping ie, fritional forces being applied to kill slipping
			else
				ODE:ApplyDampingForceHorizontally(weedunklist.physics, normalDamping);		-- damping ie, fritional forces being applied to kill slipping
			end
			Horde:SetPlayerTransform( weedunklist.node, weedunklist.physics,  weedunklist.rot, 0.1 );		-- set graphics to match physics
		else
		   	Horde:SetNodeTransformODEDynamicWithScale( weedunklist.node, weedunklist.physics , 0.1);	-- thrown weedunks rotate under physics
			Horde:SetModelAnimParams( weedunklist.node , 0, weedunklist.animTime, 1.0);
			if weedunklist.animTime >= 12 then weedunklist.animTime = 0; end
			if weedunklist.soundPlay == 0 then
				local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
		        local dist = calcSoundDistance( tx,ty,tz );
		        if dist < 255 then
		            weedunklist.soundChan = AudioMan:CHANinGROUP("all");
	                AudioMan:SetDistance( weedunklist.soundChan, dist );
                    AudioMan:PlaySFX("weedunkTransplantWalking",0,weedunklist.soundChan);
		            weedunklist.soundPlay = 1;
		        end
		    end
		    if weedunklist.soundPlay == 1 then
		        local tx,ty,tz = ODE:GetDynamicPos(weedunklist.physics);
		        local dist = calcSoundDistance( tx,ty,tz );
		        if dist < 255 then
 		            AudioMan:SetDistance( weedunklist.soundChan, dist );
	   		    else
	   		        weedunklist.soundPlay = 0;
	    	        AudioMan:StopCHAN(weedunklist.soundChan);
		        end
			        weedunklist.soundPlay = AudioMan:CHANPlaying(weedunklist.soundChan);
		    end
		end
	    weedunklist.animTime = weedunklist.animTime + 1.0;
	end
end

function RespawnPlayersIfDead()
	if GrandoDead == true and GrandoInLimbo == 0 then
	    GrandoInLimbo = 150;
	    ODE:SetDynamicPos(GrandoODE, 9999, 9999, 9999);
	end
	
	if KohiDead == true and KohiInLimbo == 0 then
	    KohiInLimbo = 150;
	    ODE:SetDynamicPos(KohiODE, 9999, 9999, 9999);
	end

	if KohiDead and KohiInLimbo == 1 then
		spawnEntity( "KOHI", kohiSpawnX, kohiSpawnY, kohiSpawnZ, 0, 0, 0 );
		amBXeffects:append({cnt = 10; effect = "kohiDie"});
		KohiControlingWeedunk = false;
		KohiTransplant = false;
		KohiCombine = false;
		if KohiDunkInHand > 0 then
			Horde:RemoveNodes(KohiDunkInHand);
		end
		KohiCarryingWeedunk = false;
		KohiPickup = false;
		KohiAndGrandoCombinedCnt = KohiAndGrandoCombinedMax;
		KohiDead = false;
		KohiDunkInHand = 0;
	end
	
	if GrandoDead == true and GrandoInLimbo == 1 then
		spawnEntity( "GRANDO", grandoSpawnX, grandoSpawnY, grandoSpawnZ, 0, 0, 0 );
		amBXeffects:append({cnt = 10; effect = "grandoDie"});
		GrandoControlingWeedunk = false;
		GrandoTransplant = false;
		GrandoCombine = false;
		if GrandoDunkInHand > 0 then
			Horde:RemoveNodes(GrandoDunkInHand);
		end
		GrandoCarryingWeedunk = false;
		GrandoPickup = false;
		GrandoFloatCnt = GrandoFloatTimeMax;
		KohiAndGrandoCombinedCnt = KohiAndGrandoCombinedMax;
		GrandoDead = false;
		GrandoDunkInHand = 0;
	end
	
	if GrandoInLimbo>0 then
	    GrandoInLimbo = GrandoInLimbo - 1;
	end
	if KohiInLimbo>0 then
	    KohiInLimbo = KohiInLimbo - 1;
	end
end		
