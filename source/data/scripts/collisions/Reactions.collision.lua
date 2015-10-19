-- Plight of the Weedunks
-- What cause's ones reaction

function KohiHitsWeedunkErnieThrow()
	KohiExploshionCnt = 0;
	killWeedunk(ODE:KillerHit(KohiODE));
	if GrandoDunkInHand > 0 then
		Horde:RemoveNodes(GrandoDunkInHand);
		GrandoDunkInHand = 0;
	end
end

function GrandoHitsWeedunkBertThrow()
    if GrandoFloatCnt > GrandoFloatTimeMax then
	    GrandoFloatCnt = 0;
	    changeGrandoAnimations(GrandoAnimInflate, GrandoAnimInflate);
	end
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, BertDieParticleEffect);
	killWeedunk(ODE:KillerHit(GrandoODE));
	if KohiDunkInHand > 0  then
		Horde:RemoveNodes(KohiDunkInHand);
		KohiDunkInHand = 0;
	end
end