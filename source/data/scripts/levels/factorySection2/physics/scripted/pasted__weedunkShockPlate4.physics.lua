-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for pasted__weedunkShockPlate4.
function pasted__weedunkShockPlate4_OBJECT ()
	pasted__weedunkShockPlate4_scripted = ODE:CreateMovingBox( 0.149204, 0.285015, 0.4, -91.0383, 44.2372, 189.775, 0, -178.607, -0, "weedunkShocker" );
	Horde:FindNodes( LevelMod, "pasted__weedunkShockPlate4", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = pasted__weedunkShockPlate4_scripted };
	pasted__weedunkShockPlate4_posX = -91.0383;
	pasted__weedunkShockPlate4_posY = 44.2372;
	pasted__weedunkShockPlate4_posZ = 189.775;
	pasted__weedunkShockPlate4_rotX = 0;
	pasted__weedunkShockPlate4_rotY = -178.607;
	pasted__weedunkShockPlate4_rotZ = -0;
end

