function GrandoHitsaimableFan() 
    ODE:Hit();
end
function GrandoHitsbtnFan1()
    btnFan1Hit = true;
end
function GrandoHitsbtnFan2()
    btnFan2Hit = true;
end
function GrandoHitsbtnFan3()
    btnFan3Hit = true;
end
function GrandoHitsbtnFan4()
    btnFan4Hit = true;
end
function GrandoHitsbtnFanAimedIn() 
    FanAimedInHit = true;
end
function GrandoHitsbtnFanAimedOff() 
    FanAimedOffHit = true;
end
function GrandoHitsbtnFanAimedOut()
    FanAimedOutHit = true;
end
function GrandoHitsconveyorForceEast()
    ODE:ApplyHitForce(-converyorForce, 0.0, 0.0); 
    ODE:Hit();
end
function GrandoHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, converyorForce); 
    ODE:Hit();
end
function GrandoHitsconveyorForceEastTurnOnable() 
    if sludgeEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF, 0.0, 0.0); 
    end
    ODE:Hit();
end
function GrandoHitsconveyorForceNorthTurnOnable() 
    if sludgeNDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, sludgeConverF); 
    end
    ODE:Hit();
end
function GrandoHitsconveyorForceNorthWest() 
    if sludgeNWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, sludgeConverF*0.7071); 
    end
    ODE:Hit();
end
function GrandoHitsconveyorForceSouth() 
    if sludgeSDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, -sludgeConverF); 
    end
    ODE:Hit();
end
function GrandoHitsconveyorForceSouthEast() 
    if sludgeSEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071); 
    end
    ODE:Hit();
end
function GrandoHitsconveyorForceSouthWest() 
    if sludgeSWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071); 
    end
    ODE:Hit();
end
function GrandoHitsconveyorForceWest() 
    if sludgeWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF, 0.0, 0.0); 
    end
    ODE:Hit();
end
function GrandoHitsconveyorTower() 
    ODE:Hit();
end
function GrandoHitsdeathMincer() 
    GrandoDead = true;
    AudioMan:PlaySFX("grandoDeathMincer");
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, GrandoDieParticleEffect);
end
function GrandoHitsdeathTower() 
    GrandoDead = true;
    AudioMan:PlaySFX("grandoDeathMincer");
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, GrandoDieParticleEffect);
end
function GrandoHitsdoor() 
    if shockerEastFilled == false or shockerWestFilled == false then
        ODE:Hit();
    end
end
function GrandoHitsexplodeUnderPlatform()
--    AudioMan:PlaySFX("allergicBlockShort");
    ODE:Hit();
end
function GrandoHitsfallingBlueSquare() 
    AudioMan:PlaySFX("allergicBlockLong");
    -- nothing Grando falls through these
end
function GrandoHitsfallingRedSquare() 
    ODE:Hit();
end
function GrandoHitsfan() 
    ODE:Hit();
end
function GrandoHitsfanForce1() 
    if fan1On == true then
        ODE:ApplyHitForce(0.0, fan1Force, 0.0);
        amBXeffects:append({cnt = 1; effect = "grandoOnFan"});
    end
end
function GrandoHitsfanForce2() 
    if fan2On == true then
        ODE:ApplyHitForce(0.0, fan2Force, 0.0);
        amBXeffects:append({cnt = 1; effect = "grandoOnFan"});
    end
end
function GrandoHitsfanForce3() 
    if fan3On == true then
        ODE:HitKillVVel();
        ODE:ApplyHitForce(fan3ForceH, fan3ForceV, 0.0);
        amBXeffects:append({cnt = 1; effect = "grandoOnFan"});
    end
end
function GrandoHitsfanForce4()
    if fan4On == true then
        ODE:HitKillVVel();
        ODE:ApplyHitForce(0.0, fan4ForceV, fan4ForceH);
        amBXeffects:append({cnt = 1; effect = "grandoOnFan"});
    end
end
function GrandoHitsfanForceAimedIn()
    if aimableFan == AMIBLE_FAN_IN then
        ODE:ApplyHitForce(0.0, amibleFanPlayer, 0.0); 
        amBXeffects:append({cnt = 1; effect = "grandoOnFan"});
    end
end
function GrandoHitsfanForceAimedOut()
    if aimableFan == AMIBLE_FAN_OUT then
        ODE:ApplyHitForce(amibleFanPlayer*0.6936, amibleFanPlayer*0.7071, -amibleFanPlayer*0.1228);
        amBXeffects:append({cnt = 1; effect = "grandoOnFan"});
    end
end
function GrandoHitsloadToothyTunnel2Level() 
    GrandoLoadToothy2 = true;
end
function GrandoHitsloadWeedunkBangLevel() 
    GrandoLoadBang = true;
end
function GrandoHitsmincer() 
    ODE:Hit();
end
function GrandoHitsmulchPipe() 
    ODE:Hit();
end
function GrandoHitsmulchValveEast() 
    ODE:Hit();
end
function GrandoHitsmulchValveNorth() 
    ODE:Hit();
end
function GrandoHitsmulchValveNorthEast()  
    ODE:Hit();
end
function GrandoHitsmulchValveNorthWest()  
    ODE:Hit();
end
function GrandoHitsmulchValveSouth()  
    ODE:Hit();
end
function GrandoHitsmulchValveSouthEast()  
    ODE:Hit();
end
function GrandoHitsmulchValveSouthWest()  
    ODE:Hit();
end
function GrandoHitsmulchValveWest()  
    ODE:Hit();
end
function GrandoHitsraisedConveyorForceNorthEast()
    if converFalling == false and converFallen == false then
        converFalling = true;
    end

    if sludgeNEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-fallingConverF*0.7071, 0.0, fallingConverF*0.7071); 
    end
    ODE:Hit();
end
function GrandoHitsweedunkShocker() 
    ODE:Hit();
end
function GrandoHitsweedunkShockerEast() 
    GrandoDead = true;
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, GrandoDieParticleEffect);
end
function GrandoHitsweedunkShockerWest() 
    GrandoDead = true;
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, GrandoDieParticleEffect);
end
