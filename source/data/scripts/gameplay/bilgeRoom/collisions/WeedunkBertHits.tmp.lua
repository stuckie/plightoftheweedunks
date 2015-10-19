function WeedunkBertHitsconveyorForceEast()
    ODE:ApplyHitForce(-conveyorForce, 0.0, 0.0);
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, conveyorForce);
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceSouth()
    ODE:ApplyHitForce(0.0, 0.0, -conveyorForce);
    ODE:Hit();
end
function WeedunkBertHitsconveyorForceWest()
    ODE:ApplyHitForce(conveyorForce, 0.0, 0.0);
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
function WeedunkBertHitsmincer()
	ODE:Hit();
end
function WeedunkBertHitsbreakableWall()
    ODE:Hit();
end
function WeedunkBertHitsfloatingThenSinkingPlatform()
    ODE:Hit();
end
function WeedunkBertHitsweedunkShocker()
end
function WeedunkBertHitsweedunkShockerEast()
    if ODE:GetDynamicID() == KohiWeedunkODE then
        KohiControlingWeedunk = false;
    end
    shockerEastFilled = true;
end
function WeedunkBertHitsweedunkShockerWest()
    if ODE:GetDynamicID() == KohiWeedunkODE then
        KohiControlingWeedunk = false;
    end
    shockerWestFilled = true;
end
function WeedunkBertHitsmulchPipe()
    ODE:Hit();
end
function WeedunkBertHitsbreakableTunnelGrate()
    ODE:Hit();
end
