-- Plight of the Weedunks
-- What happens when I hit the floor, you bounce, unless your thrown hehe

function GrandoHitsfloor()
	ODE:Hit();
end

function KohiHitsfloor()
	ODE:Hit();
end

function WeedunkBertHitsfloor()
	ODE:Hit();
end

function WeedunkErnieHitsfloor()
	ODE:Hit();
end

function WeedunkBertThrowHitsfloor()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieThrowHitsfloor()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end