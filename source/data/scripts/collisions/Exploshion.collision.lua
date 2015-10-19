-- Plight of the Weedunks
-- make weedunks fly when hit with kohi's exploshion

function KohiExploshionHitsWeedunkBert()
	ODE:ApplyHitForce(KohiODE, kohiExploshionForce);
end


function KohiExploshionHitsWeedunkErnie()
	ODE:ApplyHitForce(KohiODE, kohiExploshionForce);
end