-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for pasted__weedunkShockPlate2.
function pasted__weedunkShockPlate2_OBJECT ()
	pasted__weedunkShockPlate2_scripted = ODE:CreateMovingBox( 0.149204, 0.285015, 0.4, -88.0255, 44.2515, 189.827, 0, -178.574, -0, "weedunkShocker" );
	Horde:FindNodes( LevelMod, "pasted__weedunkShockPlate2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = pasted__weedunkShockPlate2_scripted };
	pasted__weedunkShockPlate2_posX = -88.0255;
	pasted__weedunkShockPlate2_posY = 44.2515;
	pasted__weedunkShockPlate2_posZ = 189.827;
	pasted__weedunkShockPlate2_rotX = 0;
	pasted__weedunkShockPlate2_rotY = -178.574;
	pasted__weedunkShockPlate2_rotZ = -0;
end

