--Plight of the Weedunks

-- Combine
function GrandoHitsKohiPickupBox()
    if KohiCarryingWeedunk == true then
        KohiCanCombine = true;
    end
	if KohiCombine == true and KohiCarryingWeedunk == true then
		KohiAndGrandoCombinedCnt = 0;
		KohiCarryingWeedunk = false;
	end
end

-- Pickup or take control of weedunk
function KohiPickupBoxHitsWeedunkBert()
    KohiBesideWeedunk = true;
	if KohiPickup == true and KohiCarryingWeedunk == false then
		killWeedunk(ODE:KillerHit(KohiPickupBox));
		KohiPickupAnimChange = true;
		KohiCarryingWeedunk = true;
	elseif KohiTransplant == true then
		changeKohiAnimations(KohiAnimTransplant, KohiAnimTransplant);
		WeedunkKohiSpawnX, WeedunkKohiSpawnY, WeedunkKohiSpawnZ = ODE:GetPointOfContact();
		WeedunkKohiSpawn = true;
		killWeedunk(ODE:KillerHit(KohiPickupBox));
		KohiControlingWeedunk = true;
		KohiTransplant = false;
	end
end