function WeedunkBertHitsweedunkPortal()
	--ODE:Hit();
end

function WeedunkErnieHitsweedunkPortal()
	--ODE:Hit();
end

function WeedunkBertThrowHitsweedunkPortal()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieThrowHitsweedunkPortal()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function GrandoHitsweedunkPortal()
	--ODE:Hit();
	ODE:ApplyDampingForceHorizontally(GrandoODE, 0.99);
end

function KohiHitsweedunkPortal()
	--ODE:Hit();
	ODE:ApplyDampingForceHorizontally(KohiODE, 0.99);
end

