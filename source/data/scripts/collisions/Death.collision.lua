-- Plight of the Weedunks
-- death to the creature that hits death, how dare it

function GrandoHitsdeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, GrandoDieParticleEffect);
	if GrandoDead == false then
	    AudioMan:PlaySFX("grandoDeath");
	    amBXeffects:append({cnt = 10; effect = "grandoDie"});
	end
	GrandoDead = true;
end

function KohiHitsdeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, KohiDieParticleEffect);
	if KohiDead == false then
	    AudioMan:PlaySFX("kohiDeath");
	    amBXeffects:append({cnt = 10; effect = "kohiDie"});
	end
	KohiDead = true;
end

function GrandoHitsdeathPlane()
	GrandoDead = true;
end

function KohiHitsdeathPlane()
	KohiDead = true;
end

function KohiHitstoxicDeath()
    if KohiDead == false then
	    AudioMan:PlaySFX("kohiToxicDeath");
	end
end

function GrandoHitstoxicDeath()
	if GrandoDead == false then
	    AudioMan:PlaySFX("grandoToxicDeath");
	end
end

function WeedunkBertHitsdeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "death");
end

function WeedunkBertHitsdeathPlane()
	killWeedunk(ODE:KillerHit());
end

function WeedunkErnieHitsdeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "death");
end

function WeedunkErnieHitsdeathPlane()
	killWeedunk(ODE:KillerHit());
end

function WeedunkBertThrowHitsdeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "death");
end

function WeedunkErnieThrowHitsdeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "death");
end

function WeedunkBertHitstoxicDeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "toxicDeath");
end

function WeedunkErnieHitstoxicDeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "toxicDeath");
end

function WeedunkBertThrowHitstoxicDeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "toxicDeath");
end

function WeedunkErnieThrowHitstoxicDeath()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, ErnieDieParticleEffect);
	killWeedunk(ODE:KillerHit(), x,y,z, "toxicDeath");
end