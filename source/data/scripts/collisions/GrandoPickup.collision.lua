--Plight of the Weedunks

-- Combined reaction
function GrandoPickupBoxHitsKohi()
    if GrandoCarryingWeedunk == true then
        GrandoCanCombine = true;
    end
	if GrandoCombine == true and GrandoCarryingWeedunk == true then
		KohiExploshionCnt = 0;
		ODE:ApplyForce(GrandoODE, 0,GrandoRocketForce,0);
		Horde:AddParticleEffect(GrandoMod, GrandoRocketParticleEffect);
		GrandoCarryingWeedunk = false;
		if GrandoDunkInHand > 0 then
			Horde:RemoveNodes(GrandoDunkInHand);
			GrandoDunkInHand = 0;
		end
	end
end

-- Pickup or take over a weedunk
function GrandoPickupBoxHitsWeedunkErnie()
    GrandoBesideWeedunk = true;
	if GrandoPickup == true and GrandoCarryingWeedunk == false then
		killWeedunk(ODE:KillerHit(GrandoPickupBox));
		GrandoPickupAnimChange = true;
		GrandoCarryingWeedunk = true;
	elseif GrandoTransplant == true then
		killWeedunk(ODE:KillerHit(GrandoPickupBox));
		changeGrandoAnimations(GrandoAnimTransplant, GrandoAnimTransplant);
		WeedunkGrandoSpawnX, WeedunkGrandoSpawnY, WeedunkGrandoSpawnZ = ODE:GetPointOfContact();
		WeedunkGrandoSpawn = true;
		GrandoControlingWeedunk = true;
		GrandoTransplant = false;
	end
end
