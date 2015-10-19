function WeedunkErnieHitsaimableFan()
    ODE:Hit();
end
function WeedunkErnieHitsbtnFan1()
    ODE:Hit();
end
function WeedunkErnieHitsbtnFan2()
    ODE:Hit();
end
function WeedunkErnieHitsbtnFan3()
    ODE:Hit();
end
function WeedunkErnieHitsbtnFan4()
    ODE:Hit();
end
function WeedunkErnieHitsbtnFanAimedIn()
    ODE:Hit();
end
function WeedunkErnieHitsbtnFanAimedOff()
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceEast()
    ODE:ApplyHitForce(-converyorForce, 0.0, 0.0);
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceEastTurnOnable()
    if sludgeEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF, 0.0, 0.0);
    end
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, converyorForce);
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceNorthTurnOnable()
    if sludgeNDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, sludgeConverF);
    end
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceNorthWest()
    if sludgeNWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, sludgeConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceSouth()
    if sludgeSDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, -sludgeConverF);
    end
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceSouthEast()
    if sludgeSEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceSouthWest()
    if sludgeSWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceWest()
    if sludgeWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF, 0.0, 0.0);
    end
    ODE:Hit();
end
function WeedunkErnieHitsconveyorTower()
    ODE:Hit();
end
function WeedunkErnieHitsdeathMincer()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end
function WeedunkErnieHitsdeathTower()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end
function WeedunkErnieHitsdoor()
    if shockerEastFilled == false or shockerWestFilled == false then
        ODE:Hit();
    end
end
function WeedunkErnieHitsexplodeUnderPlatform()
   ODE: Hit();
end
function WeedunkErnieHitsfallingBlueSquare()
    --blue falls through red hehe
end
function WeedunkErnieHitsfallingRedSquare()
    ODE:Hit();
end
function WeedunkErnieHitsfan()
    ODE:Hit();
end
function WeedunkErnieHitsfanForce1()
    if fan1On == true then
        ODE:ApplyHitForce(0.0, fan1Force, 0.0);
    end
end
function WeedunkErnieHitsfanForce2()
    if fan2On == true then
        ODE:ApplyHitForce(0.0, fan2Force, 0.0);
    end
end
function WeedunkErnieHitsfanForce3()
    if fan3On == true then
        ODE:ApplyHitForce(fan3ForceH, 0.0, 0.0);
        ODE:HitKillVVel();
    end
end
function WeedunkErnieHitsfanForce4()
    if fan4On == true then
        ODE:ApplyHitForce(0.0, 0.0, fan4ForceH);
        ODE:HitKillVVel();
    end
end
function WeedunkErnieHitsfanForceAimedIn()
    if aimableFan == AMIBLE_FAN_IN then
        ODE:ApplyHitForce(0.0, amibleFanWeedunk, 0.0);
    end
end
function WeedunkErnieHitsfanForceAimedOut()
    if aimableFan == AMIBLE_FAN_OUT then
        ODE:ApplyHitForce(amibleFanWeedunk*0.6936, amibleFanWeedunk*0.7071, -amibleFanWeedunk*0.1228);
    end
end
function WeedunkErnieHitsloadToothyTunnel2Level()
    ODE:Hit();
end
function WeedunkErnieHitsloadWeedunkBangLevel()
    ODE:Hit();
end
function WeedunkErnieHitsmincer()
    ODE:Hit();
end
function WeedunkErnieHitsmulchPipe()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveEast()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveNorth()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveNorthEast()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveNorthWest()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveSouth()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveSouthEast()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveSouthWest()
    ODE:Hit();
end
function WeedunkErnieHitsmulchValveWest()
    ODE:Hit();
end
function WeedunkErnieHitsraisedConveyorForceNorthEast()
    if sludgeNEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-fallingConverF*0.7071, 0.0, fallingConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkErnieHitsweedunkShocker()
end
function WeedunkErnieHitsweedunkShockerEast()
    if ODE:GetDynamicID() == GrandoWeedunkODE then
        GrandoControlingWeedunk = false;
    end
    shockerEastFilled = true;
end
function WeedunkErnieHitsweedunkShockerWest()
    if ODE:GetDynamicID() == GrandoWeedunkODE then
        GrandoControlingWeedunk = false;
    end
    shockerWestFilled = true;
end
