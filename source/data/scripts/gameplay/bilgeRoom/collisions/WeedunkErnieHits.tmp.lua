function WeedunkErnieHitsconveyorForceEast()
    ODE:ApplyHitForce(-conveyorForce, 0.0, 0.0);
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, conveyorForce);
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceSouth()
    ODE:ApplyHitForce(0.0, 0.0, -conveyorForce);
    ODE:Hit();
end
function WeedunkErnieHitsconveyorForceWest()
    ODE:ApplyHitForce(conveyorForce, 0.0, 0.0);
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
function WeedunkErnieHitsmincer()
	ODE:Hit();
end
function WeedunkErnieHitsbreakableWall()
    ODE:Hit();
end
function WeedunkErnieHitsfloatingThenSinkingPlatform()
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
function WeedunkErnieHitsmulchPipe()
    ODE:Hit();
end
function WeedunkErnieHitsbreakableTunnelGrate()
    ODE:Hit();
end
