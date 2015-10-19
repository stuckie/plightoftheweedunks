function WeedunkBertHitsaimableFan()
    ODE:Hit();
end
function WeedunkBertHitsbtnFan1()
    ODE:Hit();
end
function WeedunkBertHitsbtnFan2()
    ODE:Hit();
end
function WeedunkBertHitsbtnFan3()
    ODE:Hit();
end
function WeedunkBertHitsbtnFan4()
    ODE:Hit();
end
function WeedunkBertHitsbtnFanAimedIn()
    ODE:Hit();
end
function WeedunkBertHitsbtnFanAimedOff()
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceEast()
    ODE:ApplyHitForce(-converyorForce, 0.0, 0.0);
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceEastTurnOnable()
    if sludgeEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF, 0.0, 0.0);
    end
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, converyorForce);
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceNorthTurnOnable()
    if sludgeNDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, sludgeConverF);
    end
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceNorthWest()
    if sludgeNWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, sludgeConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceSouth()
    if sludgeSDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(0.0, 0.0, -sludgeConverF);
    end
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceSouthEast()
    if sludgeSEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceSouthWest()
    if sludgeSWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF*0.7071, 0.0, -sludgeConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceWest()
    if sludgeWDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(sludgeConverF, 0.0, 0.0);
    end
    ODE:Hit();
end
function WeedunkBertHitsconveyorTower()
    ODE:Hit();
end
function WeedunkBertHitsdeathMincer()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end
function WeedunkBertHitsdeathTower()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end
function WeedunkBertHitsdoor()
    if shockerEastFilled == false or shockerWestFilled == false then
        ODE:Hit();
    end
end
function WeedunkBertHitsexplodeUnderPlatform()
    ODE:Hit();
end
function WeedunkBertHitsfallingBlueSquare()
    ODE:Hit();
end
function WeedunkBertHitsfallingRedSquare()
    --blue falls through red hehe
end
function WeedunkBertHitsfan()
    ODE:Hit();
end
function WeedunkBertHitsfanForce1()
    if fan1On == true then
        ODE:ApplyHitForce(0.0, fan1Force, 0.0);
    end
end
function WeedunkBertHitsfanForce2()
    if fan2On == true then
        ODE:ApplyHitForce(0.0, fan2Force, 0.0);
    end
end
function WeedunkBertHitsfanForce3()
    if fan3On == true then
        ODE:ApplyHitForce(fan3ForceH, 0.0, 0.0);
        ODE:HitKillVVel();
    end
end
function WeedunkBertHitsfanForce4()
    if fan4On == true then
        ODE:ApplyHitForce(0.0, 0.0, fan4ForceH);
        ODE:HitKillVVel();
    end
end
function WeedunkBertHitsfanForceAimedIn()
    if aimableFan == AMIBLE_FAN_IN then
        ODE:ApplyHitForce(0.0, amibleFanWeedunk, 0.0);
    end
end
function WeedunkBertHitsfanForceAimedOut()
    if aimableFan == AMIBLE_FAN_OUT then
        ODE:ApplyHitForce(amibleFanWeedunk*0.6936, amibleFanWeedunk*0.7071, -amibleFanWeedunk*0.1228);
    end
end
function WeedunkBertHitsloadToothyTunnel2Level()
    ODE:Hit();
end
function WeedunkBertHitsloadWeedunkBangLevel()
    ODE:Hit();
end
function WeedunkBertHitsmincer()
    ODE:Hit();
end
function WeedunkBertHitsmulchPipe()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveEast()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveNorth()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveNorthEast()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveNorthWest()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveSouth()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveSouthEast()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveSouthWest()
    ODE:Hit();
end
function WeedunkBertHitsmulchValveWest()
    ODE:Hit();
end
function WeedunkBertHitsraisedConveyorForceNorthEast()
    if sludgeNEDestroyedTime < sludgeHealTime then
        ODE:ApplyHitForce(-fallingConverF*0.7071, 0.0, fallingConverF*0.7071);
    end
    ODE:Hit();
end
function WeedunkBertHitsweedunkShocker()
end
function WeedunkBertHitsweedunkShockerEast()
    if ODE:GetDynamicID() == KohiWeedunkODE then
        KohiControlingWeedunk = false;
    end
if shockerEastFilled == false then
Horde:RemoveNodes(KohiBellMod);
	    KohiBellMod = Horde:AddNodes(KohiBellNode, KohiBellRes);
    shockerEastFilled = true;
end
end
function WeedunkBertHitsweedunkShockerWest()
    if ODE:GetDynamicID() == KohiWeedunkODE then
        KohiControlingWeedunk = false;
    end
if shockerWestFilled == false then
Horde:RemoveNodes(KohiBellMod);
	    KohiBellMod = Horde:AddNodes(KohiBellNode, KohiBellRes);
    shockerWestFilled = true;
end
end
