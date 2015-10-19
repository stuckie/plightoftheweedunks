-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

KohiAnimIdle = 0;
KohiAnimRun = 1;
KohiAnimJump = 2;
KohiAnimJumpDunk = 3;
KohiAnimInAir = 4;
KohiAnimDeath = 5;
KohiAnimExplode = 6;
KohiAnimPickup = 7;
KohiAnimIdleDunk = 8;
KohiAnimBraindead = 9;
KohiAnimTransplant = 10;
KohiAnimRunDunk = 11;
KohiAnimThrowDunk = 12;
KohiAnimCombine = 13;
KohiIdleTimer = SGZTimer();
KohiDunkTimer = 0.0;
KohiDunkStrugglePlaying = 0;
KohiDunkStruggleChan = 0;

prevKohiAnimation = KohiAnimIdle;
currentKohiAnimation = KohiAnimIdle;
nextKohiAnimation = KohiAnimIdle;

prevKohiAnimWeight = 0.0;
currentKohiAnimWeight = 0.0;
nextKohiAnimWeight = 1.0;

prevKohiAnimTimer = 0.0;
currentKohiAnimTimer = 0.0;
nextKohiAnimTimer = 0.0;

changeKohiAnimation = false;

KohiAnim_Idle_Length = 24;
KohiAnim_Run_Length = 12;
KohiAnim_Jump_Length = 8;
KohiAnim_JumpDunk_Length = 8;
KohiAnim_InAir_Length = 12;
KohiAnim_Death_Length = 1;
KohiAnim_Explode_Length = 12;
KohiAnim_Pickup_Length = 16;
KohiAnim_IdleDunk_Length = 24;
KohiAnim_Braindead_Length = 24;
KohiAnim_Transplant_Length = 18;
KohiAnim_RunDunk_Length  = 12;
KohiAnim_ThrowDunk_Length = 12;
KohiAnim_Combine_Length = 24;

KohiAnim_Idle_Looping = true;
KohiAnim_Run_Looping = true;
KohiAnim_Jump_Looping = false;
KohiAnim_JumpDunk_Looping = false;
KohiAnim_InAir_Looping = true;
KohiAnim_Death_Looping = false;
KohiAnim_Explode_Looping = false;
KohiAnim_Pickup_Looping = false;
KohiAnim_IdleDunk_Looping = true;
KohiAnim_Braindead_Looping = true;
KohiAnim_Transplant_Looping = false;
KohiAnim_RunDunk_Looping = true;
KohiAnim_ThrowDunk_Looping = false;
KohiAnim_Combine_Looping = true;

function KohiAnimTime(anim)
	if anim == KohiAnimIdle then return KohiAnim_Idle_Length end;
	if anim == KohiAnimRun then return KohiAnim_Run_Length end;
	if anim == KohiAnimJump then return KohiAnim_Jump_Length end;
	if anim == KohiAnimJumpDunk then return KohiAnim_JumpDunk_Length end;
	if anim == KohiAnimInAir then return KohiAnim_InAir_Length end;
	if anim == KohiAnimDeath then return KohiAnim_Death_Length end;
	if anim == KohiAnimExplode then return KohiAnim_Explode_Length end;
	if anim == KohiAnimPickup then return KohiAnim_Pickup_Length end;
	if anim == KohiAnimIdleDunk then return KohiAnim_IdleDunk_Length end;
	if anim == KohiAnimBraindead then return KohiAnim_Braindead_Length end;
	if anim == KohiAnimTransplant then return KohiAnim_Transplant_Length end;
	if anim == KohiAnimRunDunk then return KohiAnim_RunDunk_Length end;
	if anim == KohiAnimThrowDunk then return KohiAnim_ThrowDunk_Length end;
	if anim == KohiAnimCombine then return KohiAnim_Combine_Length end;
end

function KohiAnimLoop(anim)
	if anim == KohiAnimIdle then return KohiAnim_Idle_Looping end;
	if anim == KohiAnimRun then return KohiAnim_Run_Looping end;
	if anim == KohiAnimJump then return KohiAnim_Jump_Looping end;
	if anim == KohiAnimJumpDunk then return KohiAnim_JumpDunk_Looping end;
	if anim == KohiAnimInAir then return KohiAnim_InAir_Looping end;
	if anim == KohiAnimDeath then return KohiAnim_Death_Looping end;
	if anim == KohiAnimExplode then return KohiAnim_Explode_Looping end;
	if anim == KohiAnimPickup then return KohiAnim_Pickup_Looping end;
	if anim == KohiAnimIdleDunk then return KohiAnim_IdleDunk_Looping end;
	if anim == KohiAnimBraindead then return KohiAnim_Braindead_Looping end;
	if anim == KohiAnimTransplant then return KohiAnim_Transplant_Looping end;
	if anim == KohiAnimRunDunk then return KohiAnim_RunDunk_Looping end;
	if anim == KohiAnimThrowDunk then return KohiAnim_ThrowDunk_Looping end;
	if anim == KohiAnimCombine then return KohiAnim_Combine_Looping end;
end

function setupKohiAnimations()
	Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Idle , "", false );
	Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Idle , "", false );
	Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Idle , "", false );
	KohiIdleTimer:Start();
end

function changeKohiAnimations(animIn, animOut)

	prevKohiAnimation = currentKohiAnimation;
	prevKohiAnimWeight = currentKohiAnimWeight;
	currentKohiAnimation = nextKohiAnimation;
	currentKohiAnimWeight = nextKohiAnimWeight;
	nextKohiAnimation = animOut;
	nextKohiAnimWeight = 1.0;
	
	prevKohiAnimTimer = 0.0;
    currentKohiAnimTimer = 0.0;
    nextKohiAnimTimer = 0.0;

	if prevKohiAnimation == KohiAnimIdle then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Idle , "", false ); end
	if prevKohiAnimation == KohiAnimRun then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Run , "", false ); end
	if prevKohiAnimation == KohiAnimJump then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Jump , "", false ); end
	if prevKohiAnimation == KohiAnimJumpDunk then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_JumpDunk, "", false ); end
	if prevKohiAnimation == KohiAnimInAir then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_InAir , "", false ); end
	if prevKohiAnimation == KohiAnimDeath then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Death , "", false ); end
	if prevKohiAnimation == KohiAnimExplode then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Explode , "", false ); end
	if prevKohiAnimation == KohiAnimPickup then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Pickup , "", false ); end
	if prevKohiAnimation == KohiAnimIdleDunk then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_IdleDunk , "", false ); end
	if prevKohiAnimation == KohiAnimBraindead then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Braindead , "", false ); end
	if prevKohiAnimation == KohiAnimTransplant then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Transplant , "", false ); end
	if prevKohiAnimation == KohiAnimRunDunk then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_RunDunk , "", false ); end
	if prevKohiAnimation == KohiAnimThrowDunk then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_ThrowDunk, "", false ); end
	if prevKohiAnimation == KohiAnimCombine then Horde:SetupModelAnimStage( KohiMod, 0, KohiAnim_Combine, "", false ); end
	
	if currentKohiAnimation == KohiAnimIdle then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Idle , "", false ); end
	if currentKohiAnimation == KohiAnimRun then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Run , "", false ); end
	if currentKohiAnimation == KohiAnimJump then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Jump , "", false ); end
	if currentKohiAnimation == KohiAnimJumpDunk then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_JumpDunk, "", false ); end
	if currentKohiAnimation == KohiAnimInAir then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_InAir , "", false ); end
	if currentKohiAnimation == KohiAnimDeath then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Death , "", false ); end
	if currentKohiAnimation == KohiAnimExplode then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Explode , "", false ); end
	if currentKohiAnimation == KohiAnimPickup then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Pickup , "", false ); end
	if currentKohiAnimation == KohiAnimIdleDunk then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_IdleDunk , "", false ); end
	if currentKohiAnimation == KohiAnimBraindead then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Braindead , "", false ); end
	if currentKohiAnimation == KohiAnimTransplant then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Transplant , "", false ); end
	if currentKohiAnimation == KohiAnimRunDunk then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_RunDunk , "", false ); end
	if currentKohiAnimation == KohiAnimThrowDunk then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_ThrowDunk, "", false ); end
	if currentKohiAnimationg == KohiAnimCombine then Horde:SetupModelAnimStage( KohiMod, 1, KohiAnim_Combine, "", false ); end
	
	if nextKohiAnimation == KohiAnimIdle then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Idle , "", false ); end
	if nextKohiAnimation == KohiAnimRun then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Run , "", false ); end
	if nextKohiAnimation == KohiAnimJump then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Jump , "", false ); end
	if nextKohiAnimation == KohiAnimJumpDunk then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_JumpDunk, "", false ); end
	if nextKohiAnimation == KohiAnimInAir then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_InAir , "", false ); end
	if nextKohiAnimation == KohiAnimDeath then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Death , "", false ); end
	if nextKohiAnimation == KohiAnimExplode then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Explode , "", false ); end
	if nextKohiAnimation == KohiAnimPickup then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Pickup , "", false ); end
	if nextKohiAnimation == KohiAnimIdleDunk then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_IdleDunk , "", false ); end
	if nextKohiAnimation == KohiAnimBraindead then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Braindead , "", false ); end
	if nextKohiAnimation == KohiAnimTransplant then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Transplant , "", false ); end
	if nextKohiAnimation == KohiAnimRunDunk then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_RunDunk , "", false ); end
	if nextKohiAnimation == KohiAnimThrowDunk then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_ThrowDunk, "", false ); end
	if nextKohiAnimation == KohiAnimCombine then Horde:SetupModelAnimStage( KohiMod, 2, KohiAnim_Combine, "", false ); end
end


function playKohiAnimations()
	Horde:SetModelAnimParams( KohiMod, 0, prevKohiAnimTimer, 0.0);
	Horde:SetModelAnimParams( KohiMod, 1, currentKohiAnimTimer, 0.0);
	Horde:SetModelAnimParams( KohiMod, 2, nextKohiAnimTimer, 1.0);
	
	if KohiCarryingWeedunk then
	    Horde:FindNodes( KohiMod, "Weedunk_Mover", "Joint" );
	    KohiHand = Horde:GetNodeFindResult( 0 );
	    if KohiIdle then
	        Horde:SetNodeTransform(KohiDunkInHand, 0,-1.5,-0.0, 0,0,0, 1,1,1);
	    else
	        Horde:SetNodeTransform(KohiDunkInHand, 0,-1.5,-1.0, 0,0,0, 1,1,1);
	    end
	    
	    Horde:SetModelAnimParams( KohiDunkInHand, 0, KohiDunkTimer, 1.0);
	    if KohiDunkTimer >= 12 then KohiDunkTimer = 0.0; end
	    KohiDunkTimer = KohiDunkTimer + 1.0;
	    if KohiDunkStrugglePlaying == 0 then
            KohiDunkStruggleChan = AudioMan:CHANinGROUP("all");
            AudioMan:PlaySFX("weedunkStruggle",0,KohiDunkStruggleChan);
		    KohiDunkStrugglePlaying = 1;
		end
		if KohiDunkStrugglePlaying == 1 then
			KohiDunkStrugglePlaying = AudioMan:CHANPlaying(KohiDunkStruggleChan);
		end
	end

	if prevKohiAnimTimer < KohiAnimTime(prevKohiAnimation) then
		prevKohiAnimTimer = prevKohiAnimTimer + 0.5
	else
		prevKohiAnimTimer = 0;
	end
	
	if currentKohiAnimTimer < KohiAnimTime(currentKohiAnimation) then
		currentKohiAnimTimer = currentKohiAnimTimer + 0.5
	else
		currentKohiAnimTimer = 0;
	end
	
	if nextKohiAnimTimer < KohiAnimTime(nextKohiAnimation) then
		nextKohiAnimTimer = nextKohiAnimTimer + 0.5;
		if nextKohiAnimation == KohiAnimPickup and KohiCarryingWeedunk == true and KohiDunkInHand == 0 then
			KohiDunkInHand = Horde:AddNodes( KohiHand, WeedunkBertRes );
			Horde:SetupModelAnimStage( KohiDunkInHand , 0, WeedunkAnim_Wiggle , "", false );
		end	
	else
		nextKohiAnimTimer = 0;
		if nextKohiAnimation == KohiAnimJump or nextKohiAnimation == KohiAnimJumpDunk then
		    AudioMan:PlaySFX("kohiFinishJump");
			changeKohiAnimations(KohiAnimInAir, KohiAnimInAir);
		end
		if nextKohiAnimation == KohiAnimInAir then
			if not KohiFalling then
				if KohiIdle == true then 
					changeKohiAnimations(KohiAnimIdle, KohiAnimIdle);
				else
					changeKohiAnimations(KohiAnimRun, KohiAnimRun);
				end
			end
		end
		if nextKohiAnimation == KohiAnimTransplant then
			changeKohiAnimations(KohiAnimBraindead, KohiAnimBraindead);
		end
		if nextKohiAnimation == KohiAnimExplode then
		    AudioMan:PlaySFX("kohiRunFast");
			if KohiIdle == true then 
				changeKohiAnimations(KohiAnimIdle, KohiAnimIdle);
			else
				changeKohiAnimations(KohiAnimRun, KohiAnimRun);
			end
		end
		if nextKohiAnimation == KohiAnimPickup and KohiCarryingWeedunk == true and KohiDunkInHand > 0 then
			if KohiIdle == true then 
				changeKohiAnimations(KohiAnimIdleDunk, KohiAnimIdleDunk);
			else
				changeKohiAnimations(KohiAnimRunDunk, KohiAnimRunDunk);
			end
		end
		if nextKohiAnimation == KohiAnimThrowDunk then
			if KohiIdle == true then 
				changeKohiAnimations(KohiAnimIdle, KohiAnimIdle);
			else
				changeKohiAnimations(KohiAnimRun, KohiAnimRun);
			end
		end
		if nextKohiAnimation == KohiAnimCombine and KohiAndGrandoCombinedCnt >= KohiAndGrandoCombinedMax then
            changeKohiAnimations(KohiAnimInAir,KohiAnimInAir);
		    Horde:RemoveNodes(KohiDunkInHand);
		    KohiDunkInHand = 0;
		    KohiCarryingWeedunk = false;
		end
        if nextKohiAnimation == KohiAnimIdle then
	        if KohiIdleTimer:Time() >= 12000 then
	            AudioMan:PlaySFX("kohiIdle");
	            KohiIdleTimer:Reset();
	        end
	    end	
	end
end
