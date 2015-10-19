-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for pasted__weedunkShockPlate3.
function pasted__weedunkShockPlate3_OBJECT ()
	pasted__weedunkShockPlate3_scripted = ODE:CreateMovingBox( 0.149204, 0.285015, 0.4, -88.8363, 44.2515, 189.803, 0, -178.574, -0, "weedunkShocker" );
	Horde:FindNodes( LevelMod, "pasted__weedunkShockPlate3", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = pasted__weedunkShockPlate3_scripted };
	pasted__weedunkShockPlate3_posX = -88.8363;
	pasted__weedunkShockPlate3_posY = 44.2515;
	pasted__weedunkShockPlate3_posZ = 189.803;
	pasted__weedunkShockPlate3_rotX = 0;
	pasted__weedunkShockPlate3_rotY = -178.574;
	pasted__weedunkShockPlate3_rotZ = -0;
end

