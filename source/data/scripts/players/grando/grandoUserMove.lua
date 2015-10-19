-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/players/grando/moveGrandoDir.lua");

GrandoCombine = false;
GrandoTransplant = false;
curGrandoMoveForce = 0;
GrandoIdleAnimChange = false;
GrandoRunAnimChange = false;
GrandoJumpAnimChange = false;
GrandoFloatAnimChange = false;
GrandoPickupAnimChange = false;
GrandoThrowAnimChange = false;
GrandoTransplantAnimChange = false;
GrandoInflateAnimChange = false;
GrandoIdle = true;
GrandoFalling = false;
GrandoControlPush = false;
GrandoFloat = false;
grandoJumpHeld = false;
grandoPickUpHeld = false;
GrandoDunkInHand = 0;

function userMoveGrando()
	local rotChanged = false;
	local rotChangedTo = 0.0;
	GrandoUserMoveAnimations();

	local vX, vY, vZ = ODE:GetVelocity(GrandoODE);		-- get the velocity in the v axis, ie is grando jumping/falling
	if vY < 0 then
		vY = 0 - vY;
	end

	GrandoFalling = ODE:HasJumpRayHit(GrandoJumpRay);
	GrandoFalling = not GrandoFalling;

	if GrandoFloatCnt < GrandoFloatTimeMax then
		curGrandoMoveForce = GrandoFloatMoveForce;
	elseif vY > GrandoHMoveRedMinSpeed then				-- if above the speed which allows the player to move with same h speed
		curGrandoMoveForce = GrandoHMoveRedSpeed;
	else
		curGrandoMoveForce = GrandoMoveForce;
	end

	if getDirection(GrandoControl, DIR_UPRIGHT) then
		GrandoRunAnimChange = true;
		moveGrandoFR(curGrandoMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_DOWNRIGHT) then
		GrandoRunAnimChange = true;
		moveGrandoBR(curGrandoMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_DOWNLEFT) then
		GrandoRunAnimChange = true;
		moveGrandoBL(curGrandoMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_UPLEFT) then
		GrandoRunAnimChange = true;
		moveGrandoFL(curGrandoMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_UP) then
		GrandoRunAnimChange = true;
		moveGrandoForward(curGrandoMoveForce);
	elseif getDirection(GrandoControl, DIR_DOWN) then
		GrandoRunAnimChange = true;
		moveGrandoBackward(curGrandoMoveForce);
	elseif getDirection(GrandoControl, DIR_RIGHT) then
		GrandoRunAnimChange = true;
		moveGrandoRight(curGrandoMoveForce);
	elseif getDirection(GrandoControl, DIR_LEFT) then
		GrandoRunAnimChange = true;
		moveGrandoLeft(curGrandoMoveForce);
	else
		if (GrandoIdle == false and GrandoFalling == false) and
		ControlMan:Get_PadAxis(GrandoControl, 0)<9850 and ControlMan:Get_PadAxis(GrandoControl, 0)>-9850 and
		   ControlMan:Get_PadAxis(GrandoControl, 1)<9850 and ControlMan:Get_PadAxis(GrandoControl, 1)>-9850 then
			GrandoIdleAnimChange = true;
		end
	end

	if gameCamera == 1 then
		rotChanged, rotChangedTo = ODE:ApplyAnalogueControl(
			GrandoODE,							--player handle
			ControlMan:Get_PadAxis(GrandoControl, 0),		--y axis
			ControlMan:Get_PadAxis(GrandoControl, 1),		--x axis
			curGrandoMoveForce,					--max force to apply
			JoyAxisDeadZone,						--dead zone
			Camera:GetCamLookDir()					--camera facing direction
		);

		if rotChanged == true then
    		GrandoRot = rotChangedTo;
		end

		if ControlMan:Get_PadAxis(GrandoControl, 0)>9850 or ControlMan:Get_PadAxis(GrandoControl, 0)<-9850 or
		   ControlMan:Get_PadAxis(GrandoControl, 1)>9850 or ControlMan:Get_PadAxis(GrandoControl, 1)<-9850 then
			GrandoRunAnimChange = true;
		end
	end

	if getAction( GrandoControl, ACT_JUMP ) then
		if GrandoFalling == false and GrandoFloatCnt > GrandoFloatTimeMax and grandoJumpHeld==false then
			ODE:Jump(GrandoODE, GrandoJumpForce);
			AudioMan:PlaySFX("grandoStartJump");
			GrandoJumpAnimChange = true;
		elseif GrandoFloatCnt < GrandoFloatTimeMax then
			ODE:ApplyForce(GrandoODE, 0, GrandoFloatBoost, 0);
			GrandoFloatCnt = GrandoFloatCnt + GrandoFloatTimeLoss;
			if grandoJumpHeld == false then
			    AudioMan:PlaySFX("grandoDeflate");
			end
		end
	end
	if getAction( GrandoControl, ACT_JUMP ) and grandoJumpHeld == false then
	    grandoJumpHeld = true;
	end
	if not getAction( GrandoControl, ACT_JUMP ) then
	    grandoJumpHeld = false;
	end

	if getAction ( GrandoControl, ACT_USE ) and grandoPickUpHeld == false then
		if GrandoCarryingWeedunk==false  then
			GrandoPickup = true;
		else
		    local thowRotH = GrandoRot;
            local throwRotV = 0;
		    if getAction(GrandoControl, ACT_AIM) and GrandoCarryingWeedunk==true then
	 	        thowRotH, throwRotV = ODE:GetRotationToFace(GrandoODE, KohiODE);
	        end
			local x,y,z = ODE:GetDynamicPos(GrandoODE);
			AudioMan:PlaySFX("weedunkThrown");
			spawnNode, spawnODE = spawnEntity( "WEEDUNK_ERNIE_THROW", x,y,z, 0, 0, 0 );
			ODE:ApplyForceWithRot(spawnODE, thowRotH, throwRotV, GrandoThrowForce);
			GrandoCarryingWeedunk = false;
			Horde:RemoveNodes(GrandoDunkInHand);
			GrandoThrowAnimChange = true;
			GrandoDunkInHand = 0;
		end
		GrandoControlPush = true;
	else
		GrandoPickup = false;
	end
	if getAction( GrandoControl, ACT_USE ) and grandoPickUpHeld == false then
	    grandoPickUpHeld = true;
	end
	if not getAction( GrandoControl, ACT_USE ) then
	    grandoPickUpHeld = false;
	end

	if getAction ( GrandoControl, ACT_COMBINE ) then
	    if GrandoFloatCnt < GrandoFloatTimeMax then
	        GrandoFloatCnt = GrandoFloatTimeMax+1;
			GrandoFloat = false;
	    end
		changeGrandoAnimations(GrandoAnimCombine, GrandoAnimCombine);
		GrandoCombine = true;
		GrandoControlPush = true;
	else
		GrandoCombine = false;
	end

	if getAction( GrandoControl, ACT_TRANSPLANT) then
		GrandoTransplantAnimChange = true;
		GrandoTransplant = true;
		--Horde:FindNodes( nodeHandle, "grando_Brain", "Joint" );
	    --GrandoHead = Horde:GetNodeFindResult( 0 );
		--GrandoBrain = Horde:AddNodes(GrandoHead, GrandoBrainRes);
		--Horde:SetNodeTransform(GrandoBrain, 0.0,0.0,0, 0,0,0, 1,1,1);
	else
		GrandoTransplant = false;
	end

	GrandoDebugButtons();
end

function GrandoUserMoveAnimations()
	if GrandoFloatCnt == 0 then
		changeGrandoAnimations(currentGrandoAnimation, GrandoAnimInflate);
		changeGrandoAnimation = true;
	end

	if GrandoTransplantAnimChange == true then
		changeGrandoAnimations(currentGrandoAnimation, GrandoAnimTransplant);
		changeGrandoAnimation = true;
		GrandoTransplantAnimChange = false;
	end

	if GrandoCombineAnimChange == true then
		changeGrandoAnimations(currentGrandoAnimation, GrandoAnimCombine);
		changeGrandoAnimation = true;
		GrandoCombineAnimChange = false;
	end

	if GrandoThrowAnimChange == true then
		changeGrandoAnimations(currentGrandoAnimation, GrandoAnimThrowDunk);
		changeGrandoAnimation = true;
		GrandoThrowAnimChange = false;
	end

	if GrandoIdleAnimChange == true and GrandoIdle == false and GrandoFloat == false then
		if GrandoCarryingWeedunk == false then
			changeGrandoAnimations(currentGrandoAnimation, GrandoAnimIdle);
		else
			changeGrandoAnimations(currentGrandoAnimation, GrandoAnimIdleDunk);
		end
		changeGrandoAnimation = true;
		GrandoIdleAnimChange = false;
		GrandoIdle = true;
	end

	if GrandoRunAnimChange == true and GrandoIdle == true and GrandoFalling == false and GrandoFloat == false then
		if GrandoCarryingWeedunk == false then
			changeGrandoAnimations(currentGrandoAnimation, GrandoAnimRun);
		else
			changeGrandoAnimations(currentGrandoAnimation, GrandoAnimRunDunk);
		end
		changeGrandoAnimation = true;
		GrandoRunAnimChange = false;
		GrandoIdle = false;
	end

	if GrandoJumpAnimChange == true then
		if GrandoCarryingWeedunk == false then
			changeGrandoAnimations(currentGrandoAnimation, GrandoAnimJump);
		else
			changeGrandoAnimations(currentGrandoAnimation, GrandoAnimJumpDunk);
		end
		changeGrandoAnimation = true;
		GrandoJumpAnimChange = false;
		GrandoFalling = true;
	end

	if GrandoPickupAnimChange == true then
		changeGrandoAnimations(currentGrandoAnimation, GrandoAnimPickup);
		changeGrandoAnimation = true;
		GrandoPickupAnimChange = false;
		GrandoIdle = true;
	end

	if GrandoInflateAnimChange == true then
		AudioMan:PlaySFX("grandoInflate");
		changeGrandoAnimations(currentGrandoAnimation, GrandoAnimInflate);
		changeGrandoAnimation = true;
		GrandoInflateAnimChange = false;
		GrandoIdle = false;
		GrandoFloat = true;
	end
end

o_held = false;
i_held = false;
function GrandoDebugButtons()
	if ControlMan:Get_z() == true then
		GrandoFloatCnt = 0;
		GrandoInflateAnimChange = true;
	elseif ControlMan:Get_z() == false then
		GrandoInflateAnimChange = false;
	end

	if ControlMan:Get_o() == false then
		o_held = false;
	end

	if ControlMan:Get_o() == true and o_held == false then
		ODE:ApplyForce(GrandoODE, 0,GrandoRocketForce,0);
		o_held = true;
	end

	if ControlMan:Get_i() == false then
		i_held = false;
	end

	if ControlMan:Get_i() == true and i_held == false then
		KohiAndGrandoCombinedCnt = 0;
		i_held = true;
	end
end

