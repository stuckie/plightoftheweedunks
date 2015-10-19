-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/players/kohi/moveKohiDir.lua");

KohiRot = 0.0;		--the rotation around the y(up) axis which kohi if rotated and thus facing
KohiCombine = false;
curKohiMoveForce = 0;
KohiIdleAnimChange = false;
KohiRunAnimChange = false;
KohiJumpAnimChange = false;
KohiFallAnimChange = false;
KohiPickupAnimChange = false;
KohiThrowAnimChange = false;
KohiTransplantAnimChange = false;
KohiExplodeAnimChange = false;
KohiIdle = true;
KohiTransplant = false;
KohiExplode = false;
KohiFalling = false;
KohiControlPush = false;
kohiJumpHeld = false
kohiPickUpHeld = false;
KohiDunkInHand = 0;

function userMoveKohi()
	local rotChanged = false;
	local rotChangedTo = 0.0;
		
	userMoveKohiAnimations();

	local vX, vY, vZ = ODE:GetVelocity(KohiODE);			-- get the velocity in the v axis, ie is Kohi jumping/falling

	if vY < 0 then
		vY = 0 - vY;
	end
		
	KohiFalling = ODE:HasJumpRayHit(KohiJumpRay);
	KohiFalling = not KohiFalling;
    
	if vY > KohiHMoveRedMinSpeed then				-- if above the speed which allows the player to move with same h speed
		curKohiMoveForce = KohiHMoveRedSpeed;
	elseif KohiExploshionCnt<KohiFastMoveTime then
		curKohiMoveForce = KohiFastMoveForce;
	else
		curKohiMoveForce = KohiMoveForce;
	end

	if getDirection(KohiControl, DIR_UPRIGHT) then					-- move charecter around
		KohiRunAnimChange = true;
		moveKohiFR(curKohiMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_DOWNRIGHT) then
		KohiRunAnimChange = true;
		moveKohiBR(curKohiMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_DOWNLEFT) then
		KohiRunAnimChange = true;
		moveKohiBL(curKohiMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_UPLEFT) then
		KohiRunAnimChange = true;
		moveKohiFL(curKohiMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_UP) then
		KohiRunAnimChange = true;
		moveKohiForward(curKohiMoveForce);
	elseif getDirection(KohiControl, DIR_DOWN) then
		KohiRunAnimChange = true;
		moveKohiBackward(curKohiMoveForce);
	elseif getDirection(KohiControl, DIR_RIGHT) then
		KohiRunAnimChange = true;
		moveKohiRight(curKohiMoveForce);
	elseif getDirection(KohiControl, DIR_LEFT) then
		KohiRunAnimChange = true;
		moveKohiLeft(curKohiMoveForce);
	else
		if (KohiIdle == false and KohiFalling == false) and
		ControlMan:Get_PadAxis(KohiControl, 0)<9850 and ControlMan:Get_PadAxis(KohiControl, 0)>-9850 and
		ControlMan:Get_PadAxis(KohiControl, 1)<9850 and ControlMan:Get_PadAxis(KohiControl, 1)>-9850 then
			KohiIdleAnimChange = true;
		end
	end

	if gameCamera == 1 then
		rotChanged, rotChangedTo = ODE:ApplyAnalogueControl(
			KohiODE,							--player handle
			ControlMan:Get_PadAxis(KohiControl, 0),		--y axis
			ControlMan:Get_PadAxis(KohiControl, 1),		--x axis
			curKohiMoveForce,					--max force to apply
			JoyAxisDeadZone,					--dead zone
			Camera:GetCamLookDir()				--camera facing dirrection
			);

		if rotChanged == true then
			KohiRot = rotChangedTo;
		end

		if ControlMan:Get_PadAxis(KohiControl, 0)>9850 or ControlMan:Get_PadAxis(KohiControl, 0)<-9850 or
		   ControlMan:Get_PadAxis(KohiControl, 1)>9850 or ControlMan:Get_PadAxis(KohiControl, 1)<-9850 then
			KohiRunAnimChange = true;
		end
	end

	if getAction( KohiControl, ACT_JUMP ) then
		if KohiFalling == false and kohiJumpHeld == false then
			ODE:Jump(KohiODE, KohiJumpForce);
			AudioMan:PlaySFX("kohiStartJump");
			KohiJumpAnimChange = true;
		end
	end
	if getAction( KohiControl, ACT_JUMP ) and kohiJumpHeld == false then
	    kohiJumpHeld = true;
	end
	if not getAction( KohiControl, ACT_JUMP ) then
	    kohiJumpHeld = false;
	end
		
	if getAction(KohiControl, ACT_USE) and kohiPickUpHeld==false then
		if KohiCarryingWeedunk==false then
			KohiPickup = true;
		else
		    local thowRotH = KohiRot;
            local throwRotV = 0;
		    if getAction(KohiControl, ACT_AIM) and KohiCarryingWeedunk==true then
	 	        thowRotH, throwRotV = ODE:GetRotationToFace(KohiODE, GrandoODE);
	        end
			local x,y,z = ODE:GetDynamicPos(KohiODE);
			changeKohiAnimations(KohiAnimThrowDunk, KohiAnimThrowDunk);
			AudioMan:PlaySFX("weedunkThrown");
			spawnNode, spawnODE = spawnEntity( "WEEDUNK_BERT_THROW", x,y,z, 0, 0, 0 );
			ODE:ApplyForceWithRot(spawnODE, thowRotH, throwRotV, KohiThrowForce);
			KohiCarryingWeedunk = false;
			Horde:RemoveNodes(KohiDunkInHand);
			KohiDunkInHand = 0;
		end
	else
		KohiPickup = false;
	end
    if getAction( KohiControl, ACT_USE ) and kohiPickUpHeld == false then
	    kohiPickUpHeld = true;
	end
	if not getAction( KohiControl, ACT_USE ) then
	    kohiPickUpHeld = false;
	end

	if getAction(KohiControl, ACT_COMBINE) then
		KohiCombineAnimChange = true;
		KohiCombine = true;
	else
		KohiCombine = false;
	end

	if getAction( KohiControl, ACT_TRANSPLANT) then
		KohiTransplantAnimChange = true;
		KohiTransplant = true;
	else
		KohiTransplant = false;
	end

	KohiDebugButtons();
end

function userMoveKohiAnimations()
	if KohiIdleAnimChange == true and KohiIdle == false then
		if KohiCarryingWeedunk == false then
			changeKohiAnimations(currentKohiAnimation, KohiAnimIdle);
		else
			changeKohiAnimations(currentKohiAnimation, KohiAnimIdleDunk);
		end
		changeKohiAnimation = true;
		KohiIdleAnimChange = false;
		KohiIdle = true;
	end

	if KohiRunAnimChange == true and KohiIdle == true and KohiFalling == false then
		if KohiCarryingWeedunk == false then
			changeKohiAnimations(currentKohiAnimation, KohiAnimRun);
		else
			changeKohiAnimations(currentKohiAnimation, KohiAnimRunDunk);
		end
		changeKohiAnimation = true;
		KohiRunAnimChange = false;
		KohiIdle = false;
	end

	if KohiJumpAnimChange == true then
		if KohiCarryingWeedunk == false then
			changeKohiAnimations(currentKohiAnimation, KohiAnimJump);
		else
			changeKohiAnimations(currentKohiAnimation, KohiAnimJumpDunk);
		end
		changeKohiAnimation = true;
		KohiJumpAnimChange = false;
		KohiFalling = true;
	end

	if KohiPickupAnimChange == true then
		changeKohiAnimations(currentKohiAnimation, KohiAnimPickup);
		changeKohiAnimation = true;
		KohiPickupAnimChange = false;
		KohiIdle = true;
	end

	if KohiTransplantAnimChange == true then
		changeKohiAnimations(currentKohiAnimation, KohiAnimTransplant);
		changeKohiAnimation = true;
		KohiTransplantAnimChange = false;
		KohiIdle = true;
	end

	if KohiThrowAnimChange == true then
		changeKohiAnimations(currentKohiAnimation, KohiAnimThrowDunk);
		changeKohiAnimation = true;
		KohiThrowAnimChange = false;
		KohiIdle = false;
	end
end

function KohiDebugButtons()
	if ControlMan:Get_x()==true and KohiExploshionCnt>KohiFastMoveTime  then	-- debug exploshion
		KohiExploshionCnt = 0;
	end
end
