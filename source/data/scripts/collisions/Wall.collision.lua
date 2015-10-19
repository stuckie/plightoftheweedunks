-- Plight of the Weedunks
-- What happens when I hit the wall, you bounce, unless your thrown hehe

function GrandoHitswall()
	ODE:Hit();
end

function KohiHitswall()
	ODE:Hit();
end

function WeedunkBertHitswall()
	ODE:Hit();
end

function WeedunkErnieHitswall()
	ODE:Hit();
end

function WeedunkBertThrowHitswall()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieThrowHitswall()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkBertThrowHitstoothysWall()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieThrowHitstoothysWall()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkBertThrowHitsdoor()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieThrowHitsdoor()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkBertThrowHitsloadFactoryLevel()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieThrowHitsloadFactoryLevel()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkBertThrowHitsdeathPlane()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieThrowHitsdeathPlane()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit());
end

