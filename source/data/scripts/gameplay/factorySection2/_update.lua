-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

junkhead1start = true;
junkhead1do = false;
junkhead1end = false;
junkhead2start = false;
junkhead2do = false;
junkhead2end = false;

function factorySection2Update()   

    if junkhead1start == true then
        AudioMan:StopCHAN(59);
        AudioMan:PlaySFX("junkheadScreenOn", 0, 59);
        junkhead1start = false;
        junkhead1do = true;
    end
    
    if junkhead1do  == true and AudioMan:CHANPlaying(59) == 0 then
        AudioMan:PlaySFX("junkHead2", 0, 59);
        junkhead1do = false;
        junkhead1end = true;
    end
    
    if junkhead1end == true and AudioMan:CHANPlaying(59) == 0  then
        AudioMan:PlaySFX("junkheadScreenOff", 0, 59);
        junkhead1end = false;
    end
    
    if junkhead2start == true then
        AudioMan:StopCHAN(59);
        AudioMan:PlaySFX("junkheadScreenOn", 0, 59);
        junkhead2start = false;
        junkhead2do = true;
    end
    
    if junkhead2do  == true and AudioMan:CHANPlaying(59) == 0 then
        AudioMan:PlaySFX("junkHead3", 0, 59);
        junkhead2do = false;
        junkhead2end = true;
    end
    
    if junkhead2end == true and AudioMan:CHANPlaying(59) == 0  then
        AudioMan:PlaySFX("junkheadScreenOff", 0, 59);
        junkhead2end = false;
    end

    local x,y,z = ODE:GetDynamicPos(KohiODE);
    
    if fan1On == true then
        fanBlade1_rotY = fanBlade1_rotY +15;
    end
    if fan2On == true then
        fanBlade2_rotY = fanBlade2_rotY +15;
    end
    if fan3On == true then
        fanBlade3_rotX = fanBlade3_rotX +15;
    end
    if fan4On == true then
        fanBlade4_rotZ = fanBlade4_rotZ +15;
    end
    if aimableFan == AMIBLE_FAN_IN then
	    aimableFan_rotX = 0;
	    aimableFan_rotY = 45;
	    aimableFan_rotZ = -0;        
	    movableFanBlade_rotX = 0;
	    movableFanBlade_rotY = movableFanBlade_rotY + 15;
	    movableFanBlade_rotZ = -0;        
    elseif aimableFan == AMIBLE_FAN_OUT then
    	aimableFan_rotX = 0;
	    aimableFan_rotY = 45;
	    aimableFan_rotZ = 10;
	    movableFanBlade_rotX = 0;
	    movableFanBlade_rotY = movableFanBlade_rotY + 15;
	    movableFanBlade_rotZ = 10; 
    end
    
    ODE:SetMovingRot(fanBlade1_scripted, fanBlade1_rotX, fanBlade1_rotY, fanBlade1_rotZ);
    ODE:SetMovingRot(fanBlade2_scripted, fanBlade2_rotX, fanBlade2_rotY, fanBlade2_rotZ);
    ODE:SetMovingRot(fanBlade3_scripted, fanBlade3_rotX, fanBlade3_rotY, fanBlade3_rotZ);
    ODE:SetMovingRot(fanBlade4_scripted, 270, fanBlade4_rotZ, 0);
    ODE:SetMovingRot(aimableFan_scripted, aimableFan_rotX, aimableFan_rotY, aimableFan_rotZ);
    ODE:SetMovingRot(movableFanBlade_scripted, movableFanBlade_rotX, movableFanBlade_rotY, movableFanBlade_rotZ);
    
    Horde:SetNodeTransformODEScriptedNoScale( fanBlade1Horde, fanBlade1_scripted );
    Horde:SetNodeTransformODEScriptedNoScale( fanBlade2Horde, fanBlade2_scripted );
    Horde:SetNodeTransformODEScriptedNoScale( fanBlade3Horde, fanBlade3_scripted );
    Horde:SetNodeTransformODEScriptedNoScale( fanBlade4Horde, fanBlade4_scripted );

    -- platform moving up    
    if platfromState == PLATFORM_UP then
        if conveyorTowerPipe5_posY<38 then
            conveyorTowerPipe5_posY = conveyorTowerPipe5_posY +0.05;
        else
            platfromState = PLATFORM_TOP;
            platformCnt = 0;
        end
        ODE:SetMovingPos(conveyorTowerPipe5_scripted, conveyorTowerPipe5_posX,conveyorTowerPipe5_posY,conveyorTowerPipe5_posZ);
    elseif platfromState == PLATFORM_TOP then
        if platformCnt < platformStopTime then
            platformCnt = platformCnt+1;
        else
            platfromState = PLATFORM_DOWN;
        end
    elseif platfromState == PLATFORM_DOWN then
        if conveyorTowerPipe5_posY>25 then
            conveyorTowerPipe5_posY = conveyorTowerPipe5_posY - 0.05;
        else
            platfromState = PLATFORM_BOT;
            platformCnt = 0;
        end
        ODE:SetMovingPos(conveyorTowerPipe5_scripted, conveyorTowerPipe5_posX,conveyorTowerPipe5_posY,conveyorTowerPipe5_posZ);
    elseif platfromState == PLATFORM_BOT then
        if platformCnt < platformStopTime then
            platformCnt = platformCnt+1;
        else
            platfromState = PLATFORM_UP;
        end
    end
    
    -- toggle fans on and off
    if btnFan1Hit == true and btnFan1HitLastFrame == false then
        AudioMan:PlaySFX("button"); 
        fan1On = not fan1On;
    end
    if btnFan2Hit == true and btnFan2HitLastFrame == false then
        AudioMan:PlaySFX("button"); 
        fan2On = not fan2On;
    end
    if btnFan3Hit == true and btnFan3HitLastFrame == false then
        AudioMan:PlaySFX("button"); 
        fan3On = not fan3On;
    end
    if btnFan4Hit == true and btnFan4HitLastFrame == false then
        AudioMan:PlaySFX("button"); 
        fan4On = not fan4On;
    end
    
    -- making buttons togglable, oh the fun
    btnFan1HitLastFrame = btnFan1Hit;
    btnFan2HitLastFrame = btnFan2Hit;
    btnFan3HitLastFrame = btnFan3Hit;
    btnFan4HitLastFrame = btnFan4Hit;
    btnFan1Hit = false;
    btnFan2Hit = false;
    btnFan3Hit = false;
    btnFan4Hit = false;

    -- allow sluge things to heal
    if sludgeNDestroyedTime < sludgeHealTime+1 then
        sludgeNDestroyedTime = sludgeNDestroyedTime + 1;
        Horde:SetNodeTransform(NorthMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(NorthMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(NorthMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(NorthMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
    if sludgeSDestroyedTime < sludgeHealTime+1 then
        sludgeSDestroyedTime = sludgeSDestroyedTime + 1;
        Horde:SetNodeTransform(SouthMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(SouthMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(SouthMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(SouthMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
    if sludgeEDestroyedTime < sludgeHealTime+1 then
        sludgeEDestroyedTime = sludgeEDestroyedTime + 1;
        Horde:SetNodeTransform(EastMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(EastMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(EastMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(EastMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
    if sludgeWDestroyedTime < sludgeHealTime+1 then
        sludgeWDestroyedTime = sludgeWDestroyedTime + 1;
        Horde:SetNodeTransform(WestMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(WestMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(WestMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(WestMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
    if sludgeNEDestroyedTime < sludgeHealTime+1 then
        sludgeNEDestroyedTime = sludgeNEDestroyedTime + 1;
        Horde:SetNodeTransform(NorthEastMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(NorthEastMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(NorthEastMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(NorthEastMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
    if sludgeNWDestroyedTime < sludgeHealTime+1 then
        sludgeNWDestroyedTime = sludgeNWDestroyedTime + 1;
        Horde:SetNodeTransform(NorthWestMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(NorthWestMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(NorthWestMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(NorthWestMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
    if sludgeSEDestroyedTime < sludgeHealTime+1 then
        sludgeSEDestroyedTime = sludgeSEDestroyedTime + 1;
        Horde:SetNodeTransform(SouthEastMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(SouthEastMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(SouthEastMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(SouthEastMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
    if sludgeSWDestroyedTime < sludgeHealTime+1 then
        sludgeSWDestroyedTime = sludgeSWDestroyedTime + 1;
        Horde:SetNodeTransform(SouthWestMulch, 9999,9999,9999,0,0,0,1,1,1);
        Horde:SetNodeTransform(SouthWestMulchBroke, 0,0,0,0,0,0,1,1,1);
    else
        Horde:SetNodeTransform(SouthWestMulch, 0,0,0,0,0,0,1,1,1);
        Horde:SetNodeTransform(SouthWestMulchBroke, 9999,9999,9999,0,0,0,1,1,1);
    end
       
    -- once grando or kohi hit the falling conver belt it will fall to the ground and be able to be turned on
    if converFalling == true then
        if conveyorBelt20_posY > 51.0 then
            conveyorBelt20_posY = conveyorBelt20_posY - 0.5;
            ODE:SetMovingPos(conveyorBelt20_scripted, conveyorBelt20_posX,conveyorBelt20_posY,conveyorBelt20_posZ);
            Horde:SetNodeTransformODEScriptedNoScale( conveyorBelt20, conveyorBelt20_scripted );
            AudioMan:PlaySFX("fallingConveyor");
        else
            converFallen = true;
            converFalling = false;
        end
    end
    
    -- amible fans
    if FanAimedInHit == true and FanAimedInHitLast == false then
        aimableFan = AMIBLE_FAN_IN;
    end
    if FanAimedOutHitLast == true and FanAimedOutHit == false then
        aimableFan = AMIBLE_FAN_OUT;
    end
    if FanAimedOffHitLast == true and FanAimedOffHit == false then
        aimableFan = AMIBLE_FAN_OFF;
    end
    
    FanAimedInHitLast = FanAimedInHit;
    FanAimedOutHitLast = FanAimedOutHit;
    FanAimedOffHitLast = FanAimedOffHit;    
    FanAimedInHit = false;
    FanAimedOutHit = false;
    FanAimedOffHit = false;
    
    if KohiLoadToothy2 == true or GrandoLoadToothy2 == true then
        CurrentMenu = MENU_CREDITS;
    end
    if KohiLoadBang == true then
        KohiDead = false;
        KohiHitsrespawn7();	
        KohiDead = true;
        KohiInLimbo = 1;  
    end
    if GrandoLoadBang == true then
	    GrandoDead = false;  
        GrandoHitsrespawn7();
        GrandoDead = true;  
        GrandoInLimbo = 1;
    end
    
    KohiLoadToothy2 = false;
    GrandoLoadToothy2 = false;
    KohiLoadBang = false;
    GrandoLoadBang = false;
    
    if shockerEastFilled == true and shockerWestFilled == true then
        if doorOpened == false then
            ODE:KillMoving(door_scripted);
            doorOpened = true;
            AudioMan:PlaySFX("openDoor");
            junkhead2start = true;
        end
    end
    
    if shockerEastFilled == true and shockerEastTwoStreams == false then
        AudioMan:PlaySFX("weedunkShockerShocking");
        amBXeffects:append({cnt = 15; effect = "shockWeedunk"});
        Horde:AddParticleEffect(-91.4011, 44.0652, 189.766, shockerFilledParticle);
        shockerEastTwoStreams = true;
    end
    if shockerWestFilled == true and shockerWestTwoStreams == false then
        AudioMan:PlaySFX("weedunkShockerShocking");
        amBXeffects:append({cnt = 15; effect = "shockWeedunk"});
        Horde:AddParticleEffect(-88.426, 44.0795, 189.818, shockerFilledParticle);
        shockerWestTwoStreams = true;
    end
end
