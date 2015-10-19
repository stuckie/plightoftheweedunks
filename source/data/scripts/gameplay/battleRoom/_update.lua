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

function factorySection1Update() 

--	if ControlMan:Get_t() == true then Horde:SetNodeActivation( LevelMod, false ); end
--	if ControlMan:Get_y() == true then Horde:SetNodeActivation( LevelMod, true ); end

	if ControlMan:Get_t() == true then Horde:RemoveNodes( LevelMod ); end
	if ControlMan:Get_y() == true then Horde:AddNodes( 0, LevelMod ); end

    ODE:SetMovingRot(grinderWheels_mov_scripted, 0, 0, grinderRot);
    grinderRot = grinderRot + 5.0;
    deathTowerRot = deathTowerRot + 15.0;
    
    if deathTowerFalling == true then
        deathTowerHeight = deathTowerHeight - 0.1;
        if deathTowerHeight < 0.0 then
            deathTowerFalling = false;
        end
    end
    if deathTowerFalling == false then
        deathTowerHeight = deathTowerHeight + 0.01;
        if deathTowerHeight > 3.3 then
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
        breakableWallDestroyed = true;
    end
    
    if breakableTunnelGrateBroken == true and breakableTunnelGrateDestroyed == false then
        ODE:KillMoving(breakableTunnelGrate_scripted);
        Camera:TurnOnShakeCam(5, 1.5);
        breakableTunnelGrateDestroyed = true;
    end
    
    if conveyorTowerButtonPressed == true and platform1Raised == false and raisePlatform1 == false then
        raisePlatform1 = true;
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
		Camera:TurnOnShakeCam(10, 0.5);
		btnHiddenStepsPressed = false;
	end
		
    if bugStairsBreakableBoardsBroken == true then
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
        Horde:AddParticleEffect(-91.4013, 14.5333, 211.195, shockerFilledParticle);
        shockerEastTwoStreams = true;
    end
    if shockerWestFilled==true and shockerWestTwoStreams==false then 
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
    
    if grandoHitLoadSection2 == true and kohiHitLoadSection2 == true then
        ChangeLevelOnNextUpdate("FactorySection2");
    end
    
    grandoHitLoadSection2 = false;
    kohiHitLoadSection2 = false;
end
