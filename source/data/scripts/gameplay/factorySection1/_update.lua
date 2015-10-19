-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

breakableWallDestroyed = false;
destroyBreakableWall = false;
breakableTunnelGrateBroken = false;
breakableTunnelGrateDestroyed= false;

conveyorTowerButtonPressed = false;
platform1Raised = false;
raisePlatform1 = false;

openGateButtonePressed = false;
floatySidePlatformsMoving = false;
floatySidePlatformsReset = false;
floatySidePlatformsRising = false;

floatyExitPlatformsMoving = false;
floatyExitPlatform1Reset = false;
floatyExitPlatform1Rising = false;
floatyExitPlatform2Reset = false;
floatyExitPlatform2Rising = false;
floatyExitPlatform3Reset = false;
floatyExitPlatform3Rising = false;

btnHiddenStepsPressed = false;
bugStairsBreakableBoardsBroken = false;
bugStairsBreakableBoardsDestroyed = false;
bugStepsMoving = false;

shockerWestFilled = false;
shockerEastFilled = false;

grinderRot = 0.0;
deathTowerFalling = false    
deathTowerHeight = 0.0;
deathTowerRot = 0.0;

grandoHitLoadSection2 = false;
kohiHitLoadSection2 = false;
    
shockerEastTwoStreams = false;
shockerWestTwoStreams = false;    
hiddenPlatformShake = false;
startJunkheadDialogue = false;
doJunkheadDialogue = false;
endJunkheadDialogue = false;
junkheadDialogueFin = false;
startJunkheadTip1 = false
doJunkheadTip1 = false;
endJunkheadTip1 = false;
startJunkheadTip2 = false
doJunkheadTip2 = false;
endJunkheadTip2 = false;
startJunkheadTip3 = false
doJunkheadTip3 = false;
endJunkheadTip3 = false;
junkheadDialogueTip1Fin = false;
junkheadDialogueTip2Fin = false;
junkheadDialogueTip3Fin = false;

function factorySection1Update() 

    ODE:SetMovingRot(grinderWheels_mov_scripted, 0, 0, grinderRot);
    grinderRot = grinderRot + 5.0;
    deathTowerRot = deathTowerRot + 15.0;
    
    
    if startJunkheadTip1 == true then
        AudioMan:StopCHAN(59);
        AudioMan:PlaySFX("junkheadScreenOn", 0, 59);
        startJunkheadTip1 = false;
        doJunkheadTip1  = true;
    end
    
    if doJunkheadTip1 == true and AudioMan:CHANPlaying(59) == 0 then
        AudioMan:PlaySFX("Tip1", 0, 59);
        doJunkheadTip1 = false;
        endJunkheadTip1 = true;
    end
    
    if endJunkheadTip1 == true and AudioMan:CHANPlaying(59) == 0 and junkheadDialogueTip1Fin == false then
        AudioMan:PlaySFX("junkheadScreenOff", 0, 59);
        junkheadDialogueTip1Fin = true;
    end
    
    if startJunkheadTip2 == true then
        AudioMan:StopCHAN(59);
        AudioMan:PlaySFX("junkheadScreenOn", 0, 59);
        startJunkheadTip2 = false;
        doJunkheadTip2  = true;
    end
    
    if doJunkheadTip2 == true and AudioMan:CHANPlaying(59) == 0 then
        AudioMan:PlaySFX("Tip2", 0, 59);
        doJunkheadTip2 = false;
        endJunkheadTip2 = true;
    end
    
    if endJunkheadTip2 == true and AudioMan:CHANPlaying(59) == 0 and junkheadDialogueTip2Fin == false then
        AudioMan:PlaySFX("junkheadScreenOff", 0, 59);
        junkheadDialogueTip2Fin = true;
    end
    
    if startJunkheadTip3 == true then
        AudioMan:StopCHAN(59);
        AudioMan:PlaySFX("junkheadScreenOn", 0, 59);
        startJunkheadTip3 = false;
        doJunkheadTip3  = true;
    end
    
    if doJunkheadTip3 == true and AudioMan:CHANPlaying(59) == 0 then
        AudioMan:PlaySFX("Tip3", 0, 59);
        doJunkheadTip3 = false;
        endJunkheadTip3 = true;
    end
    
    if endJunkheadTip3 == true and AudioMan:CHANPlaying(59) == 0 and junkheadDialogueTip3Fin == false then
        AudioMan:PlaySFX("junkheadScreenOff", 0, 59);
        junkheadDialogueTip3Fin = true;
    end
    
    if junkheadDialogue1Played == false then
       	    startJunkheadDialogue = true;
      	    junkheadDialogue1Played = true;
    end
    
    if startJunkheadDialogue == true then
        AudioMan:StopCHAN(59);
        AudioMan:PlaySFX("junkheadScreenOn", 0, 59);
        startJunkheadDialogue = false;
        doJunkheadDialogue  = true;
    end
    
    if doJunkheadDialogue == true and AudioMan:CHANPlaying(59) == 0 then
        AudioMan:PlaySFX("Junkhead1", 0, 59);
        doJunkheadDialogue = false;
        endJunkheadDialogue = true;
    end
    
    if endJunkheadDialogue == true and AudioMan:CHANPlaying(59) == 0 and junkheadDialogueFin == false then
        AudioMan:PlaySFX("junkheadScreenOff", 0, 59);
        junkheadDialogueFin = true;
        startJunkheadTip1 = true;
    end
    
    if junkheadDialogue1Played == false then
       	    startJunkheadDialogue = true;
      	    junkheadDialogue1Played = true;
    end
    
    
    if convey1Played == false then
        convey1Chan = AudioMan:PlaySFX("conveyorBelt",-1);

        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundConveyor_section_1 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( convey1Chan, distance );
        convey1Played = true;
    elseif convey1Played == true then
        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundConveyor_section_1 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( convey1Chan, distance );
    end
    
    if convey2Played == false then
        convey2Chan = AudioMan:PlaySFX("conveyorBelt",-1);
		local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundConveyor_section_2 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( convey2Chan, distance );
        convey2Played = true;
    elseif convey2Played == true then
        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundConveyor_section_2 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( convey2Chan, distance );
    end
    
    if convey3Played == false then
        convey3Chan = AudioMan:PlaySFX("mincer",-1);
	local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundConveyor_section_3 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( convey3Chan, distance );
        convey3Played = true;
    elseif convey3Played == true then
        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundConveyor_section_3 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( convey3Chan, distance );
    end
    
    if conveyTower1Played == false then
        conveyTower1Chan = AudioMan:PlaySFX("mincer",-1);
	local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundDeathTower1 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( conveyTower1Chan, distance );
        conveyTower1Played = true;
    elseif conveyTower1Played == true then
        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundDeathTower1 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( conveyTower1Chan, distance );
    end
    
    if conveyTower2Played == false then
        conveyTower2Chan = AudioMan:PlaySFX("mincer",-1);
	local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundDeathTower2 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( conveyTower2Chan, distance );
        conveyTower2Played = true;
    elseif conveyTower2Played == true then
        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundDeathTower2 );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( conveyTower2Chan, distance );
    end
    
    if conveyTower3Played == false then
        conveyTower3Chan = AudioMan:PlaySFX("mincer",-1);
	local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundMincer );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( conveyTower3Chan, distance );
        conveyTower3Played = true;
    elseif conveyTower3Played == true then
        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundMincer );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( conveyTower3Chan, distance );
    end
    
    if mincerPlayed == false then
        mincerChan = AudioMan:PlaySFX("mincer",-1);

        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundGrinder );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( mincerChan, distance );
        mincerPlayed = true;
    elseif mincerPlayed == true then
        local t2x = Gx+((Kx-Gx)*0.5);
	    local t2y = Gy+((Ky-Gy)*0.5);
	    local t2z = Gz+((Kz-Gz)*0.5);

	    local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( soundGrinder );
	    
	    local dx = t2x-t1x;
	    local dy = t2y-t1y;
	    local dz = t2z-t1z;

      	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*12.8;
       	if distance > 255 then distance = 255 end
        AudioMan:SetDistance( mincerChan, distance );
    end

    if deathTowerFalling == true then
        deathTowerHeight = deathTowerHeight - 0.1;
        if deathTowerHeight < 0.0 and deathTowerFalling == true then
            deathTowerFalling = false;
            positionSoundNode("lumpsBeingMulched", soundDeathTower1 );
        end
    end
    if deathTowerFalling == false then
        deathTowerHeight = deathTowerHeight + 0.01;
        if deathTowerHeight > 3.0 then
            deathTowerFalling = true;
        end
    end
    
    ODE:SetMovingPos(deathTower1_scripted, deathTower1_posX, deathTower1_posY+deathTowerHeight, deathTower1_posZ);
    --ODE:SetMovingPos(deathTower2_scripted, deathTower2_posX, deathTower2_posY+deathTowerHeight, deathTower2_posZ);
    ODE:SetMovingRot(deathTower1_scripted, deathTower1_rotX+deathTowerRot, deathTower1_rotY, deathTower1_rotZ);
    ODE:SetMovingRot(deathTower2_scripted, deathTower2_rotX+deathTowerRot, deathTower2_rotY, deathTower2_rotZ);   
    
    Horde:SetNodeTransformODEScriptedNoScaleUsingOriginalPos( deathTower1, deathTower1_scripted );
    Horde:SetNodeTransformODEScriptedNoScaleUsingOriginalPos( deathTower2, deathTower2_scripted );
    Horde:SetNodeTransformODEScriptedNoScaleUsingOriginalPos( grinderWheels_mov, grinderWheels_mov_scripted );
    Horde:SetNodeTransformODEScriptedNoScaleUsingOriginalPos( bugSteps1, bugStep1_scripted );
    
    if destroyBreakableWall == true and breakableWallDestroyed == false then
        ODE:KillMoving(breakableWall_mov_scripted);
        Camera:TurnOnShakeCam(5, 1.5);
        AudioMan:PlaySFX("wallExploding");
        
        amBXeffects:append({cnt = 15; effect = "wallDestroy"});
        breakableWallDestroyed = true;
    end
    
    if breakableTunnelGrateBroken == true and breakableTunnelGrateDestroyed == false then
        ODE:KillMoving(breakableTunnelGrate_scripted);
        Camera:TurnOnShakeCam(5, 1.5);
        AudioMan:PlaySFX("breakableBoard");
        amBXeffects:append({cnt = 15; effect = "wallDestroy"});
        breakableTunnelGrateDestroyed = true;
    end
    
    if conveyorTowerButtonPressed == true and platform1Raised == false and raisePlatform1 == false then
        raisePlatform1 = true;
        AudioMan:PlaySFX( "button" );
        AudioMan:PlaySFX( "risingFloor" );
        amBXeffects:append({cnt = 15; effect = "risingSteps"});
        startJunkheadTip2 = true;
    end
    
    local list = SPAWNERS;
	while list do
        Horde:SetModelAnimParams( list.node, 0, list.anim, 1.0);
        list.anim = list.anim + 0.5;
		list = list.next;
	end
	    
    if raisePlatform1 == true and platform1Raised == false then
        Camera:TurnOnShakeCam(1, 0.5);
        raisedFloor1_posY = raisedFloor1_posY + 0.2;
        raisedFloor2_posY = raisedFloor2_posY + 0.2;
        raisedFloor3_posY = raisedFloor3_posY + 0.2;
        raisedFloor4_posY = raisedFloor4_posY + 0.2;
        ODE:SetMovingPos(raisedFloor1_scripted, raisedFloor1_posX, raisedFloor1_posY, raisedFloor1_posZ);
        ODE:SetMovingPos(raisedFloor2_scripted, raisedFloor2_posX, raisedFloor2_posY, raisedFloor2_posZ);
        ODE:SetMovingPos(raisedFloor3_scripted, raisedFloor3_posX, raisedFloor3_posY, raisedFloor3_posZ);
        ODE:SetMovingPos(raisedFloor4_scripted, raisedFloor4_posX, raisedFloor4_posY, raisedFloor4_posZ);
        if raisedFloor1_posY >= 3.0 then
            platform1Raised = true;
            raisePlatform1 = false;
        end
    end

	if btnHiddenStepsPressed == true then
		bugStairsLock_posX = 9999;
		bugStairsLock_posY = 9999;
		bugStairsLock_posZ = 9999;
		ODE:SetMovingPos(bugStairsLock_scripted, bugStairsLock_posX, bugStairsLock_posY, bugStairsLock_posZ);
		bugStepsMoving = true;
		if hiddenPlatformShake == false then
		    startJunkheadTip3 = true;
		    Camera:TurnOnShakeCam(10, 0.5);
            AudioMan:PlaySFX( "button" );
            AudioMan:PlaySFX("bugStepsLock");
            AudioMan:PlaySFX("bugStepsWithWood");
            amBXeffects:append({cnt = 15; effect = "stepsUnlocked"});
            Horde:SetModelAnimParams( buglockBolt, 0, 10, 1.0);
            hiddenPlatformShake = true;
        end
		btnHiddenStepsPressed = false;
	end
		
    if bugStairsBreakableBoardsBroken == true then
        positionSoundNode( "breakableBoard", bugSteps1 );
        positionSoundNode( "bugSteps", bugSteps1 );
        bugStairsBreakableBoards_posX = 9999;
		bugStairsBreakableBoards_posY = 9999;
		bugStairsBreakableBoards_posZ = 9999;
		ODE:SetMovingPos(bugStairsBreakableBoards_scripted, bugStairsBreakableBoards_posX, bugStairsBreakableBoards_posY, bugStairsBreakableBoards_posZ);
		bugStairsBreakableBoardsDestroyed = true;
		bugStairsBreakableBoardsBroken = false;
	end

	if bugStepsMoving == true then
		if bugStairsBreakableBoardsDestroyed == false and bugStep1_posZ > 160 then
		bugStep1_posZ = bugStep1_posZ - 0.2;
		bugStep2_posZ = bugStep2_posZ - 0.2;
		bugStep3_posZ = bugStep3_posZ - 0.2;
		bugStep4_posZ = bugStep4_posZ - 0.2;
		bugStep5_posZ = bugStep5_posZ - 0.2;
		bugStep6_posZ = bugStep6_posZ - 0.2;
		bugStep7_posZ = bugStep7_posZ - 0.2;	
		Horde:FindNodes( LevelMod, "bugSteps", "Mesh" );
	    local node = Horde:GetNodeFindResult(0);
	    tx,ty,tz, rx,ry,rz, sx,sy,sz = Horde:GetNodeTransform(node);
	    Horde:SetNodeTransform(node, tx,ty,tz-0.2, rx,ry,rz, sx,sy,sz);
		ODE:SetMovingPos(bugStep1_scripted, bugStep1_posX, bugStep1_posY, bugStep1_posZ);
        ODE:SetMovingPos(bugStep2_scripted, bugStep2_posX, bugStep2_posY, bugStep2_posZ);
        ODE:SetMovingPos(bugStep3_scripted, bugStep3_posX, bugStep3_posY, bugStep3_posZ);
        ODE:SetMovingPos(bugStep4_scripted, bugStep4_posX, bugStep4_posY, bugStep4_posZ);
		ODE:SetMovingPos(bugStep5_scripted, bugStep5_posX, bugStep5_posY, bugStep5_posZ);
        ODE:SetMovingPos(bugStep6_scripted, bugStep6_posX, bugStep6_posY, bugStep6_posZ);
        ODE:SetMovingPos(bugStep7_scripted, bugStep7_posX, bugStep7_posY, bugStep7_posZ);
				
		elseif bugStairsBreakableBoardsDestroyed == true and bugStep1_posZ > 152 then
		bugStep1_posZ = bugStep1_posZ - 0.2;
		bugStep2_posZ = bugStep2_posZ - 0.2;
		bugStep3_posZ = bugStep3_posZ - 0.2;
		bugStep4_posZ = bugStep4_posZ - 0.2;
		bugStep5_posZ = bugStep5_posZ - 0.2;
		bugStep6_posZ = bugStep6_posZ - 0.2;
		bugStep7_posZ = bugStep7_posZ - 0.2;
		ODE:SetMovingPos(bugStep1_scripted, bugStep1_posX, bugStep1_posY, bugStep1_posZ);
        ODE:SetMovingPos(bugStep2_scripted, bugStep2_posX, bugStep2_posY, bugStep2_posZ);
        ODE:SetMovingPos(bugStep3_scripted, bugStep3_posX, bugStep3_posY, bugStep3_posZ);
        ODE:SetMovingPos(bugStep4_scripted, bugStep4_posX, bugStep4_posY, bugStep4_posZ);
		ODE:SetMovingPos(bugStep5_scripted, bugStep5_posX, bugStep5_posY, bugStep5_posZ);
        ODE:SetMovingPos(bugStep6_scripted, bugStep6_posX, bugStep6_posY, bugStep6_posZ);
        ODE:SetMovingPos(bugStep7_scripted, bugStep7_posX, bugStep7_posY, bugStep7_posZ);
        Horde:FindNodes( LevelMod, "bugSteps", "Mesh" );
	    local node = Horde:GetNodeFindResult(0);
	    tx,ty,tz, rx,ry,rz, sx,sy,sz = Horde:GetNodeTransform(node);
	    Horde:SetNodeTransform(node, tx,ty,tz-0.2, rx,ry,rz, sx,sy,sz);
		elseif bugStep1_posZ <= 152 then
		    bugStepsMoving = false;
		end
	end
		 
	if openGrateButtonPressed == true then
		if grateButtonSoundPlayed == false then
		    AudioMan:PlaySFX("button");
		    AudioMan:PlaySFX("openGrate");
		    amBXeffects:append({cnt = 15; effect = "wallDestroy"});
		    grateButtonSoundPlayed = true;
		end
		if openableTunnelGrate_posY < 6 then
		    openableTunnelGrate_posY = openableTunnelGrate_posY + 0.1;
		    ODE:SetMovingPos(openableTunnelGrate_scripted, openableTunnelGrate_posX, openableTunnelGrate_posY, openableTunnelGrate_posZ);
		elseif openableTunnelGrate_posY >= 6 and floatySidePlatformsReset == false then
		        floatingPlatform1_posX = floatingPlatform1_posX - 0.05;	 
		        floatingPlatform2_posX = floatingPlatform2_posX - 0.05;
		        floatingPlatform3_posX = floatingPlatform3_posX - 0.05;
		        ODE:SetMovingPos(floatingPlatform1_scripted, floatingPlatform1_posX, floatingPlatform1_posY, floatingPlatform1_posZ);
		        ODE:SetMovingPos(floatingPlatform2_scripted, floatingPlatform2_posX, floatingPlatform2_posY, floatingPlatform2_posZ);
		        ODE:SetMovingPos(floatingPlatform3_scripted, floatingPlatform3_posX, floatingPlatform3_posY, floatingPlatform3_posZ);
		end
		if floatingPlatform1_posX <= -90 then floatySidePlatformsReset = true end;
		if floatySidePlatformsReset == true and floatingPlatform1_posY > -8.0 then
		    floatingPlatform1_posY = floatingPlatform1_posY - 0.05;	 
		    floatingPlatform2_posY = floatingPlatform2_posY - 0.05;
		    floatingPlatform3_posY = floatingPlatform3_posY - 0.05;
		    ODE:SetMovingPos(floatingPlatform1_scripted, floatingPlatform1_posX, floatingPlatform1_posY, floatingPlatform1_posZ);
		    ODE:SetMovingPos(floatingPlatform2_scripted, floatingPlatform2_posX, floatingPlatform2_posY, floatingPlatform2_posZ);
		    ODE:SetMovingPos(floatingPlatform3_scripted, floatingPlatform3_posX, floatingPlatform3_posY, floatingPlatform3_posZ);
		end
		if floatingPlatform1_posY <= -8.0 and floatySidePlatformsRising == false and floatySidePlatformsReset == true then 
		    floatingPlatform1_posX = 90.5132;
	        floatingPlatform1_posY = -8.0;
		    floatingPlatform3_posX = 117.575;
	        floatingPlatform3_posY = -8.0;
		    floatingPlatform2_posX = 100.129;
	        floatingPlatform2_posY = -8.0;
		    ODE:SetMovingPos(floatingPlatform1_scripted, floatingPlatform1_posX, floatingPlatform1_posY, floatingPlatform1_posZ);
		    ODE:SetMovingPos(floatingPlatform2_scripted, floatingPlatform2_posX, floatingPlatform2_posY, floatingPlatform2_posZ);
		    ODE:SetMovingPos(floatingPlatform3_scripted, floatingPlatform3_posX, floatingPlatform3_posY, floatingPlatform3_posZ);
		end
		if floatySidePlatformsRising == true and floatySidePlatformsReset == true then
		    floatingPlatform1_posY = floatingPlatform1_posY + 0.01;	 
		    floatingPlatform2_posY = floatingPlatform2_posY + 0.01;
		    floatingPlatform3_posY = floatingPlatform3_posY + 0.01;
		    ODE:SetMovingPos(floatingPlatform1_scripted, floatingPlatform1_posX, floatingPlatform1_posY, floatingPlatform1_posZ);
		    ODE:SetMovingPos(floatingPlatform2_scripted, floatingPlatform2_posX, floatingPlatform2_posY, floatingPlatform2_posZ);
		    ODE:SetMovingPos(floatingPlatform3_scripted, floatingPlatform3_posX, floatingPlatform3_posY, floatingPlatform3_posZ);
		    if floatingPlatform1_posY >= -4.92281 then 
                floatySidePlatformsRising = false;
                floatySidePlatformsReset = false;
            end
		end
    end
    
    if shockerEastFilled == true and shockerWestFilled == true then floatyExitPlatformsMoving = true end;
    if shockerEastFilled==true and shockerEastTwoStreams==false then 
	  AudioMan:PlaySFX("weedunkShockerShocking");
        Horde:AddParticleEffect(-91.4013, 14.5333, 211.195, shockerFilledParticle);
        shockerEastTwoStreams = true;
        amBXeffects:append({cnt = 15; effect = "shockWeedunk"});
    end
    if shockerWestFilled==true and shockerWestTwoStreams==false then 
	  AudioMan:PlaySFX("weedunkShockerShocking");
	    amBXeffects:append({cnt = 15; effect = "shockWeedunk"});
        Horde:AddParticleEffect(-45.8468, 14.5333, 211.195, shockerFilledParticle);
        shockerWestTwoStreams = true;
    end    
    
    --- Platform 1
    if floatyExitPlatformsMoving == true and floatyExitPlatform1Reset == false then
        floatingThenSinkingPlatform_posZ = floatingThenSinkingPlatform_posZ - 0.05;	 
		ODE:SetMovingPos(floatingThenSinkingPlatform_scripted, floatingThenSinkingPlatform_posX, floatingThenSinkingPlatform_posY, floatingThenSinkingPlatform_posZ);
    end
    if floatingThenSinkingPlatform_posZ <= 200 then floatyExitPlatform1Reset = true end;
    
    if floatyExitPlatform1Reset == true and floatyExitPlatform1Rising == false then
        floatingThenSinkingPlatform_posY = floatingThenSinkingPlatform_posY - 0.01;	 
		ODE:SetMovingPos(floatingThenSinkingPlatform_scripted, floatingThenSinkingPlatform_posX, floatingThenSinkingPlatform_posY, floatingThenSinkingPlatform_posZ);
	end
	if floatingThenSinkingPlatform_posY <= 10.0 and floatyExitPlatform1Rising == false then
		floatingThenSinkingPlatform_posY = 10.0;
	    floatingThenSinkingPlatform_posZ = 223.78;
	    floatyExitPlatform1Rising = true;
	end
    if floatyExitPlatform1Rising == true and floatyExitPlatform1Reset == true then
        floatingThenSinkingPlatform_posY = floatingThenSinkingPlatform_posY + 0.01;
		ODE:SetMovingPos(floatingThenSinkingPlatform_scripted, floatingThenSinkingPlatform_posX, floatingThenSinkingPlatform_posY, floatingThenSinkingPlatform_posZ);
        if floatingThenSinkingPlatform_posY >= 12.8 then
            floatyExitPlatform1Rising = false;
            floatyExitPlatform1Reset = false;
        end
    end
    
    --- Platform 2
    if floatyExitPlatformsMoving == true and floatyExitPlatform2Reset == false then
        floatingThenSinkingPlatform1_posZ = floatingThenSinkingPlatform1_posZ - 0.05;	 
		ODE:SetMovingPos(floatingThenSinkingPlatform1_scripted, floatingThenSinkingPlatform1_posX, floatingThenSinkingPlatform1_posY, floatingThenSinkingPlatform1_posZ);
    end
    if floatingThenSinkingPlatform1_posZ <= 200 then floatyExitPlatform2Reset = true end;
    
    if floatyExitPlatform2Reset == true and floatyExitPlatform2Rising == false then
        floatingThenSinkingPlatform1_posY = floatingThenSinkingPlatform1_posY - 0.01;	 
		ODE:SetMovingPos(floatingThenSinkingPlatform1_scripted, floatingThenSinkingPlatform1_posX, floatingThenSinkingPlatform1_posY, floatingThenSinkingPlatform1_posZ);
	end
	if floatingThenSinkingPlatform1_posY <= 10.0 and floatyExitPlatform2Rising == false then
		floatingThenSinkingPlatform1_posY = 10.0;
	    floatingThenSinkingPlatform1_posZ = 223.78;
	    floatyExitPlatform2Rising = true;
	end
    if floatyExitPlatform2Rising == true and floatyExitPlatform2Reset == true then
        floatingThenSinkingPlatform1_posY = floatingThenSinkingPlatform1_posY + 0.01;
		ODE:SetMovingPos(floatingThenSinkingPlatform1_scripted, floatingThenSinkingPlatform1_posX, floatingThenSinkingPlatform1_posY, floatingThenSinkingPlatform1_posZ);
        if floatingThenSinkingPlatform1_posY >= 12.8 then
            floatyExitPlatform2Rising = false;
            floatyExitPlatform2Reset = false;
        end
    end
    
    --- Platform 3
    if floatyExitPlatformsMoving == true and floatyExitPlatform3Reset == false then
        floatingThenSinkingPlatform3_posZ = floatingThenSinkingPlatform3_posZ - 0.05;	 
		ODE:SetMovingPos(floatingThenSinkingPlatform3_scripted, floatingThenSinkingPlatform3_posX, floatingThenSinkingPlatform3_posY, floatingThenSinkingPlatform3_posZ);
    end
    if floatingThenSinkingPlatform3_posZ <= 200 then floatyExitPlatform3Reset = true end;
    
    if floatyExitPlatform3Reset == true and floatyExitPlatform3Rising == false then
        floatingThenSinkingPlatform3_posY = floatingThenSinkingPlatform3_posY - 0.01;	 
		ODE:SetMovingPos(floatingThenSinkingPlatform3_scripted, floatingThenSinkingPlatform3_posX, floatingThenSinkingPlatform3_posY, floatingThenSinkingPlatform3_posZ);
	end
	if floatingThenSinkingPlatform3_posY <= 10.0 and floatyExitPlatform3Rising == false then
		floatingThenSinkingPlatform3_posY = 10.0;
	    floatingThenSinkingPlatform3_posZ = 223.78;
	    floatyExitPlatform3Rising = true;
	end
    if floatyExitPlatform3Rising == true and floatyExitPlatform3Reset == true then
        floatingThenSinkingPlatform3_posY = floatingThenSinkingPlatform3_posY + 0.01;
		ODE:SetMovingPos(floatingThenSinkingPlatform3_scripted, floatingThenSinkingPlatform3_posX, floatingThenSinkingPlatform3_posY, floatingThenSinkingPlatform3_posZ);
        if floatingThenSinkingPlatform3_posY >= 12.8 then
            floatyExitPlatform3Rising = false;
            floatyExitPlatform3Reset = false;
        end
    end
    
    if grandoHitLoadSection2 == true or kohiHitLoadSection2 == true then
        ChangeLevelOnNextUpdate("FactorySection2");
    end
    
    grandoHitLoadSection2 = false;
    kohiHitLoadSection2 = false;
    
    if gw01Hit == true then
        ODE:SetMovingPos(gw01_scripted, 9999,9999,9999);
        ODE:KillMoving(gw01_scripted);
        gwsHit = gwsHit + 1;
        gw01Hit = false;
        Horde:RemoveNodes(gw01);
    end
    if gw02Hit == true then
        ODE:SetMovingPos(gw02_scripted, 9999,9999,9999);
        ODE:KillMoving(gw02_scripted);
        gwsHit = gwsHit + 1;
        gw02Hit = false;
        Horde:RemoveNodes(gw02);
    end
    if gw03Hit == true then
        ODE:SetMovingPos(gw03_scripted, 9999,9999,9999);
        ODE:KillMoving(gw03_scripted);
        gwsHit = gwsHit + 1;
        gw03Hit = false
        Horde:RemoveNodes(gw03);
    end
    if gw04Hit == true then
        ODE:SetMovingPos(gw04_scripted, 9999,9999,9999);
        ODE:KillMoving(gw04_scripted);
        gwsHit = gwsHit + 1;
        gw04Hit = false;
        Horde:RemoveNodes(gw04);
    end
    if gw05Hit == true then
        ODE:SetMovingPos(gw05_scripted, 9999,9999,9999);
        ODE:KillMoving(gw05_scripted);
        gwsHit = gwsHit + 1;
        gw05Hit = false;
        Horde:RemoveNodes(gw05);
    end
    if gw06Hit == true then
        ODE:SetMovingPos(gw06_scripted, 9999,9999,9999);
        ODE:KillMoving(gw06_scripted);
        gwsHit = gwsHit + 1;
        gw06Hit = false;
        Horde:RemoveNodes(gw06);
    end
    if gw07Hit == true then
        ODE:SetMovingPos(gw07_scripted, 9999,9999,9999);
        ODE:KillMoving(gw07_scripted);
        gwsHit = gwsHit + 1;
        gw07Hit = false
        Horde:RemoveNodes(gw07);
    end
    if gw08Hit == true then
        ODE:SetMovingPos(gw08_scripted, 9999,9999,9999);
        ODE:KillMoving(gw08_scripted);
        gwsHit = gwsHit + 1;
        gw08Hit = false;
        Horde:RemoveNodes(gw08);
    end
    if gw09Hit == true then
        ODE:SetMovingPos(gw09_scripted, 9999,9999,9999);
        ODE:KillMoving(gw09_scripted);
        gwsHit = gwsHit + 1;
        gw09Hit = false;
        Horde:RemoveNodes(gw09);
    end
    if gw10Hit == true then
        ODE:SetMovingPos(gw10_scripted, 9999,9999,9999);
        ODE:KillMoving(gw10_scripted);
        gwsHit = gwsHit + 1;
        gw10Hit = false;
        Horde:RemoveNodes(gw10);
    end
end
