function KohiHitsaimableFan() 
    ODE:Hit();
end
function KohiHitsbtnFan1()
    btnFan1Hit = true;
end
function KohiHitsbtnFan2()
    btnFan2Hit = true;
end
function KohiHitsbtnFan3()
    btnFan3Hit = true;
end
function KohiHitsbtnFan4()
    btnFan4Hit = true;
end
function KohiHitsbtnFanAimedIn() 
    FanAimedInHit = true;
end
function KohiHitsbtnFanAimedOff() 
    FanAimedOffHit = true;
end
function KohiHitsbtnFanAimedOut()
    FanAimedOutHit = true;
end
function KohiHitsconveyorForceEast()
    ODE:ApplyHitForce(-converyorForce, 0.0, 0.0); 
    ODE:Hit();
end
function KohiHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, converyorForce); 
    ODE:Hit();
end
function KohiHitsconveyorForceEastTurnOnable() 
    if sludgeEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF, 0.0, 0.0); 
    end
    ODE:Hit();
end
function KohiHitsconveyorForceNorthTurnOnable() 
    if sludgeNDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, sludgeConverF); 
    end
    ODE:Hit();
end
function KohiHitsconveyorForceNorthWest() 
    if sludgeNWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, sludgeConverF*0.7071); 
    end
    ODE:Hit();
end
function KohiHitsconveyorForceSouth() 
    if sludgeSDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, -sludgeConverF); 
    end
    ODE:Hit();
end
function KohiHitsconveyorForceSouthEast() 
    if sludgeSEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071); 
    end
    ODE:Hit();
end
function KohiHitsconveyorForceSouthWest() 
    if sludgeSWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071); 
    end
    ODE:Hit();
end
function KohiHitsconveyorForceWest() 
    if sludgeWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF, 0.0, 0.0); 
    end
    ODE:Hit();
end
function KohiHitsconveyorTower() 
    ODE:Hit();
end
function KohiHitsdeathMincer()
	local x,y,z = ODE:GetPointOfContact();
	AudioMan:PlaySFX("kohiDeathMincer");
	Horde:AddParticleEffect(x,y,z, KohiDieParticleEffect); 
    KohiDead = true;
end
function KohiHitsdeathTower()
	local x,y,z = ODE:GetPointOfContact();
	AudioMan:PlaySFX("kohiDeathMincer");
	Horde:AddParticleEffect(x,y,z, KohiDieParticleEffect); 
    KohiDead = true;
end
function KohiHitsdoor() 
    if shockerEastFilled == false or shockerWestFilled == false then
        ODE:Hit();
    end
end
function KohiHitsexplodeUnderPlatform()
    ODE:Hit();
end
function KohiHitsfallingBlueSquare() 
--    AudioMan:PlaySFX("allergicBlockShort");
    ODE:Hit();
end
function KohiHitsfallingRedSquare() 
    AudioMan:PlaySFX("allergicBlockLong");
    -- nothing kohi falls through these
end
function KohiHitsfan() 
    ODE:Hit();
end
function KohiHitsfanForce1() 
    if fan1On == true then
        ODE:ApplyHitForce(0.0, fan1Force, 0.0);
        amBXeffects:append({cnt = 1; effect = "kohiOnFan"});
    end
end
function KohiHitsfanForce2() 
    if fan2On == true then
        ODE:ApplyHitForce(0.0, fan2Force, 0.0);
        amBXeffects:append({cnt = 1; effect = "kohiOnFan"});
    end
end
function KohiHitsfanForce3() 
    if fan3On == true then
        ODE:HitKillVVel();        
        ODE:ApplyHitForce(fan3ForceH, fan3ForceV, 0.0);
        amBXeffects:append({cnt = 1; effect = "kohiOnFan"});
    end
end
function KohiHitsfanForce4()
    if fan4On == true then
        ODE:HitKillVVel();
        ODE:ApplyHitForce(0.0, fan4ForceV, fan4ForceH);
        amBXeffects:append({cnt = 1; effect = "kohiOnFan"});
    end
end
function KohiHitsfanForceAimedIn()
    if aimableFan == AMIBLE_FAN_IN then
        ODE:ApplyHitForce(0.0, amibleFanPlayer, 0.0); 
        amBXeffects:append({cnt = 1; effect = "kohiOnFan"});
    end
end
function KohiHitsfanForceAimedOut()
    if aimableFan == AMIBLE_FAN_OUT then
        ODE:ApplyHitForce(amibleFanPlayer*0.6936, amibleFanPlayer*0.7071, -amibleFanPlayer*0.1228); 
        amBXeffects:append({cnt = 1; effect = "kohiOnFan"});
    end
end
function KohiHitsloadToothyTunnel2Level() 
    KohiLoadToothy2 = true;
end
function KohiHitsloadWeedunkBangLevel() 
    KohiLoadBang = true;
end
function KohiHitsmincer() 
    ODE:Hit();
end
function KohiHitsmulchPipe() 
    ODE:Hit();
end
function KohiHitsmulchValveEast() 
    ODE:Hit();
end
function KohiHitsmulchValveNorth() 
    ODE:Hit();
end
function KohiHitsmulchValveNorthEast()  
    ODE:Hit();
end
function KohiHitsmulchValveNorthWest()  
    ODE:Hit();
end
function KohiHitsmulchValveSouth()  
    ODE:Hit();
end
function KohiHitsmulchValveSouthEast()  
    ODE:Hit();
end
function KohiHitsmulchValveSouthWest()  
    ODE:Hit();
end
function KohiHitsmulchValveWest()  
    ODE:Hit();
end
function KohiHitsraisedConveyorForceNorthEast()
    if converFalling == false and converFallen == false then
        converFalling = true;
    end

    if sludgeNEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-fallingConverF*0.7071, 0.0, fallingConverF*0.7071); 
    end
    ODE:Hit();
end
function KohiHitsweedunkShocker() 
    ODE:Hit();
end
function KohiHitsweedunkShockerEast() 
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, KohiDieParticleEffect);
    KohiDead = true;
end
function KohiHitsweedunkShockerWest() 
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, KohiDieParticleEffect);
    KohiDead = true;
end
