-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------
--- This is such a horrid hack!
--------------------------------

GrandoAnimRun = 0;
GrandoAnimTransplant = 1;
GrandoAnimDeath = 2;
GrandoAnimFloat = 3;
GrandoAnimBraindead = 4;
GrandoAnimIdle = 5;
GrandoAnimIdleDunk = 6;
GrandoAnimInflate = 7;
GrandoAnimJump = 8;
GrandoAnimJumpInAir = 9;
GrandoAnimJumpDunk = 10;
GrandoAnimPickup = 11;
GrandoAnimRunDunk = 12;
GrandoAnimThrowDunk = 13;
GrandoAnimAirDunk = 14;
GrandoAnimCombine = 15;
GrandoIdleTimer = SGZTimer();

prevGrandoAnimation = GrandoAnimIdle;
currentGrandoAnimation = GrandoAnimIdle;
nextGrandoAnimation = GrandoAnimIdle;

prevGrandoAnimTimer = 0.0;
currentGrandoAnimTimer = 0.0;
nextGrandoAnimTimer = 0.0;

changeGrandoAnimation = false;

prevGrandoAnimWeight = 0.0;
currentGrandoAnimWeight = 0.0;
nextGrandoAnimWeight = 1.0;

GrandoAnim_Run_Length  = 16;
GrandoAnim_Transplant_Length  = 24;
GrandoAnim_Death_Length  = 1;
GrandoAnim_Float_Length = 22;
GrandoAnim_Braindead_Length  = 24;
GrandoAnim_Idle_Length = 24;
GrandoAnim_IdleDunk_Length  = 24;
GrandoAnim_Inflate_Length  = 18;
GrandoAnim_Jump_Length  = 8;
GrandoAnim_JumpInAir_Length = 8;
GrandoAnim_JumpDunk_Length = 8;
GrandoAnim_AirDunk_Length = 8;
GrandoAnim_Pickup_Length  = 12;
GrandoAnim_RunDunk_Length = 16;
GrandoAnim_ThrowDunk_Length = 8;
GrandoAnim_Combine_Length = 1;

function GrandoAnimTime(anim)
	if anim == GrandoAnimRun then return GrandoAnim_Run_Length end;
	if anim == GrandoAnimTransplant then return GrandoAnim_Transplant_Length end;
	if anim == GrandoAnimDeath then return GrandoAnim_Death_Length end;
	if anim == GrandoAnimFloat then return GrandoAnim_Float_Length end;
	if anim == GrandoAnimBraindead then return GrandoAnim_Braindead_Length end;
	if anim == GrandoAnimIdle then return GrandoAnim_Idle_Length end;
	if anim == GrandoAnimIdleDunk then return GrandoAnim_IdleDunk_Length end;
	if anim == GrandoAnimInflate then return GrandoAnim_Inflate_Length end;
	if anim == GrandoAnimJump then return GrandoAnim_Jump_Length end;
	if anim == GrandoAnimJumpInAir then return GrandoAnim_JumpInAir_Length end;
	if anim == GrandoAnimJumpDunk then return GrandoAnim_JumpDunk_Length end;
	if anim == GrandoAnimPickup then return GrandoAnim_Pickup_Length end;
	if anim == GrandoAnimRunDunk then return GrandoAnim_RunDunk_Length end;
	if anim == GrandoAnimThrowDunk then return GrandoAnim_ThrowDunk_Length end;
	if anim == GrandoAnimAirDunk then return GrandoAnim_AirDunk_Length end;
	if anim == GrandoAnimCombine then return GrandoAnim_Combine_Length end;
end

function setupGrandoAnimations()
	Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Idle , "", false );
	Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Idle , "", false );
	Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_Idle , "", false );
	GrandoIdleTimer:Start();
end

function changeGrandoAnimations(animIn, animOut)

    prevGrandoAnimation = currentGrandoAnimation;
	prevGrandoAnimWeight = currentGrandoAnimWeight;
	currentGrandoAnimation = nextGrandoAnimation;
	currentGrandoAnimWeight = nextGrandoAnimWeight;
	nextGrandoAnimation = animOut;
	nextGrandoAnimWeight = 1.0;
	
	prevGrandoAnimTimer = 0.0;
    currentGrandoAnimTimer = 0.0;
    nextGrandoAnimTimer = 0.0;

	if prevGrandoAnimation == GrandoAnimRun then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Run , "", false ); end
	if prevGrandoAnimation == GrandoAnimTransplant then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Transplant , "", false ); end
	if prevGrandoAnimation == GrandoAnimDeath then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Death , "", false ); end
	if prevGrandoAnimation == GrandoAnimFloat then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Float , "", false ); end
	if prevGrandoAnimation == GrandoAnimBraindead then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Braindead , "", false ); end
	if prevGrandoAnimation == GrandoAnimIdle then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Idle , "", false ); end
	if prevGrandoAnimation == GrandoAnimIdleDunk then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_IdleDunk , "", false ); end
	if prevGrandoAnimation == GrandoAnimInflate then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Inflate , "", false ); end
	if prevGrandoAnimation == GrandoAnimJump then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Jump , "", false ); end
	if prevGrandoAnimation == GrandoAnimJumpInAir then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_JumpInAir , "", false ); end
	if prevGrandoAnimation == GrandoAnimJumpDunk then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_JumpDunk , "", false ); end
	if prevGrandoAnimation == GrandoAnimPickup then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Pickup , "", false ); end
	if prevGrandoAnimation == GrandoAnimRunDunk then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_RunDunk , "", false ); end
	if prevGrandoAnimation == GrandoAnimThrowDunk then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_ThrowDunk , "", false ); end
	if prevGrandoAnimation == GrandoAnimAirDunk then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_AirDunk , "", false ); end
	if prevGrandoAnimation == GrandoAnimCombine then Horde:SetupModelAnimStage( GrandoMod, 0, GrandoAnim_Transplant , "", false ); end
	
	if currentGrandoAnimation == GrandoAnimRun then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Run , "", false ); end
	if currentGrandoAnimation == GrandoAnimTransplant then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Transplant , "", false ); end
	if currentGrandoAnimation == GrandoAnimDeath then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Death , "", false ); end
	if currentGrandoAnimation == GrandoAnimFloat then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Float , "", false ); end
	if currentGrandoAnimation == GrandoAnimBraindead then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Braindead , "", false ); end
	if currentGrandoAnimation == GrandoAnimIdle then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Idle , "", false ); end
	if currentGrandoAnimation == GrandoAnimIdleDunk then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_IdleDunk , "", false ); end
	if currentGrandoAnimation == GrandoAnimInflate then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Inflate , "", false ); end
	if currentGrandoAnimation == GrandoAnimJump then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Jump , "", false ); end
	if currentGrandoAnimation == GrandoAnimJumpInAir then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_JumpInAir , "", false ); end
	if currentGrandoAnimation == GrandoAnimJumpDunk then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_JumpDunk , "", false ); end
	if currentGrandoAnimation == GrandoAnimPickup then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Pickup , "", false ); end
	if currentGrandoAnimation == GrandoAnimRunDunk then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_RunDunk , "", false ); end
	if currentGrandoAnimation == GrandoAnimThrowDunk then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_ThrowDunk , "", false ); end
	if currentGrandoAnimation == GrandoAnimAirDunk then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_AirDunk , "", false ); end
	if currentGrandoAnimation == GrandoAnimCombine then Horde:SetupModelAnimStage( GrandoMod, 1, GrandoAnim_Transplant , "", false ); end

	
	if nextGrandoAnimation == GrandoAnimRun then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_Run , "", false ); end
	if nextGrandoAnimation == GrandoAnimTransplant then Horde:SetupModelAnimStage( GrandoMod,2, GrandoAnim_Transplant , "", false ); end
	if nextGrandoAnimation == GrandoAnimDeath then Horde:SetupModelAnimStage( GrandoMod,2, GrandoAnim_Death , "", false ); end
	if nextGrandoAnimation == GrandoAnimFloat then Horde:SetupModelAnimStage( GrandoMod,2, GrandoAnim_Float , "", false ); end
	if nextGrandoAnimation == GrandoAnimBraindead then Horde:SetupModelAnimStage( GrandoMod,2, GrandoAnim_Braindead , "", false ); end
	if nextGrandoAnimation == GrandoAnimIdle then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_Idle , "", false ); end
	if nextGrandoAnimation == GrandoAnimIdleDunk then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_IdleDunk , "", false ); end
	if nextGrandoAnimation == GrandoAnimInflate then Horde:SetupModelAnimStage( GrandoMod,2, GrandoAnim_Inflate , "", false ); end
	if nextGrandoAnimation == GrandoAnimJump then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_Jump , "", false ); end
	if nextGrandoAnimation == GrandoAnimJumpInAir then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_JumpInAir , "", false ); end
	if nextGrandoAnimation == GrandoAnimJumpDunk then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_JumpDunk , "", false ); end
	if nextGrandoAnimation == GrandoAnimPickup then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_Pickup , "", false ); end
	if nextGrandoAnimation == GrandoAnimRunDunk then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_RunDunk , "", false ); end
	if nextGrandoAnimation == GrandoAnimThrowDunk then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_ThrowDunk , "", false ); end
	if nextGrandoAnimation == GrandoAnimAirDunk then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_AirDunk , "", false ); end
	if nextGrandoAnimation == GrandoAnimCombine then Horde:SetupModelAnimStage( GrandoMod, 2, GrandoAnim_Transplant , "", false ); end
end


function playGrandoAnimations()
    Horde:SetModelAnimParams( GrandoMod, 0, prevGrandoAnimTimer, 0.0);
	Horde:SetModelAnimParams( GrandoMod, 1, currentGrandoAnimTimer, 0.0);
	Horde:SetModelAnimParams( GrandoMod, 2, nextGrandoAnimTimer, 1.0);
		
	if GrandoCarryingWeedunk then
	    Horde:FindNodes( GrandoMod, "weedunk_attach", "Joint" );
	    GrandoHand = Horde:GetNodeFindResult( 0 );
	    tx,ty,tz, rx,ry,rz, sx,sy,sz = Horde:GetNodeTransform(GrandoHand);
	    if nextGrandoAnimation == GrandoAnimRunDunk then
	        Horde:SetNodeTransform(GrandoDunkInHand, tx+2.0, ty+0.45, tz+0, sx+0, sy+0, sz-90, 1,1,1);
	    elseif nextGrandoAnimation == GrandoAnimIdleDunk then
	        Horde:SetNodeTransform(GrandoDunkInHand, tx+4.0, ty-4.0, tz+2.0, sx+0, sy+0, sz-0, 1,1,1);
	    else
	        Horde:SetNodeTransform(GrandoDunkInHand, tx, ty, tz, sx, sy, sz-90, 1,1,1);
	    end
	    Horde:SetModelAnimParams( GrandoDunkInHand, 0, GrandoDunkTimer, 1.0);
	    if GrandoWeedunkTimer >= 12 then GrandoWeedunkTimer = 0.0; end
	    GrandoWeedunkTimer = GrandoWeedunkTimer + 1.0;
	end

	if prevGrandoAnimTimer < GrandoAnimTime(prevGrandoAnimation) then
		prevGrandoAnimTimer = prevGrandoAnimTimer + 0.5
	else
		prevGrandoAnimTimer = 0;
	end
	
	if currentGrandoAnimTimer < GrandoAnimTime(currentGrandoAnimation) then
		currentGrandoAnimTimer = currentGrandoAnimTimer + 0.5
	else
		currentGrandoAnimTimer = 0;
	end
	
	if nextGrandoAnimTimer < GrandoAnimTime(nextGrandoAnimation) then
		nextGrandoAnimTimer = nextGrandoAnimTimer + 0.5
		if nextGrandoAnimation == GrandoAnimPickup and GrandoCarryingWeedunk == true and GrandoDunkInHand == 0 then
			GrandoDunkInHand = Horde:AddNodes( GrandoHand, WeedunkErnieRes );
			Horde:SetupModelAnimStage( GrandoDunkInHand , 0, WeedunkAnim_Wiggle , "", false );
			Horde:SetNodeTransform(GrandoDunkInHand, 0, 0, 0, -90, 0, 0, 1,1,1);
		end
	else
		nextGrandoAnimTimer = 0;
		if nextGrandoAnimation == GrandoAnimJump then
		    AudioMan:PlaySFX("grandoFinishJump");
		    changeGrandoAnimations(GrandoAnimJumpInAir, GrandoAnimJumpInAir);
		end
		if nextGrandoAnimation == GrandoAnimJumpDunk then
		    AudioMan:PlaySFX("grandoFinishJump");
		    changeGrandoAnimations(GrandoAnimAirDunk, GrandoAnimAirDunk);
		end
		if nextGrandoAnimation == GrandoAnimTransplant then
		    changeGrandoAnimations(GrandoAnimBraindead, GrandoAnimBraindead);
		end
		if nextGrandoAnimation == GrandoAnimBraindead then
		    --Horde:RemoveNodes(GrandoBrain);
		end
		if nextGrandoAnimation == GrandoAnimInflate then
		    changeGrandoAnimations(GrandoAnimFloat, GrandoAnimFloat);
		end
		if nextGrandoAnimation == GrandoAnimFloat and GrandoFloatCnt == GrandoFloatTimeMax then
		    changeGrandoAnimations(GrandoAnimJumpInAir,GrandoAnimJumpInAir);
		end
		if nextGrandoAnimation == GrandoAnimFloat and KohiAndGrandoAreCombined == true and KohiAndGrandoCombinedCnt >= KohiAndGrandoCombinedMax then
		    changeGrandoAnimations(GrandoAnimJumpInAir,GrandoAnimJumpInAir);
		end
		if nextGrandoAnimation == GrandoAnimJumpInAir then
			if not GrandoFalling then
				if GrandoIdle == true then 
					changeGrandoAnimations(GrandoAnimIdle, GrandoAnimIdle);
				else
					changeGrandoAnimations(GrandoAnimRun, GrandoAnimRun);
				end
			end
		end
		if nextGrandoAnimation == GrandoAnimAirDunk then
			if not GrandoFalling then
				if GrandoIdle == true then 
					changeGrandoAnimations(GrandoAnimIdleDunk, GrandoAnimIdleDunk);
				else
					changeGrandoAnimations(GrandoAnimRunDunk, GrandoAnimRunDunk);
				end
			end
		end
		if nextGrandoAnimation == GrandoAnimPickup and GrandoCarryingWeedunk == true then
			if GrandoIdle == true and GrandoDunkInHand > 0 then 
				changeGrandoAnimations(GrandoAnimIdleDunk, GrandoAnimIdleDunk);
			elseif GrandoIdle == false and GrandoDunkInHand > 0 then
				changeGrandoAnimations(GrandoAnimRunDunk, GrandoAnimRunDunk);
			elseif GrandoIdle == true and GrandoDunkInHand == 0 then
				changeGrandoAnimations(GrandoAnimIdle, GrandoAnimIdle);
			else
				changeGrandoAnimations(GrandoAnimRun, GrandoAnimRun);
			end
		end
		if nextGrandoAnimation == GrandoAnimThrowDunk then
			if GrandoIdle == true then 
				changeGrandoAnimations(GrandoAnimIdle, GrandoAnimIdle);
			else
				changeGrandoAnimations(GrandoAnimRun, GrandoAnimRun);
			end
		end
		if nextGrandoAnimation == GrandoAnimIdle then
	        if GrandoIdleTimer:Time() >= 12000 then
	            AudioMan:PlaySFX("grandoIdle");
	            GrandoIdleTimer:Reset();
	        end
	    end	
		if nextGrandoAnimation == GrandoAnimCombine and not GrandoFalling then
			if GrandoIdle == true then 
				changeGrandoAnimations(GrandoAnimIdle, GrandoAnimIdle);
			else
				changeGrandoAnimations(GrandoAnimRun, GrandoAnimRun);
			end
			Horde:RemoveNodes(GrandoDunkInHand);
			GrandoCarryingWeedunk = false
		    GrandoDunkInHand = 0;
		end

	end
end

