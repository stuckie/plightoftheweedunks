-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for pasted__weedunkShockPlate5.
function pasted__weedunkShockPlate5_OBJECT ()
	pasted__weedunkShockPlate5_scripted = ODE:CreateMovingBox( 0.149204, 0.285015, 0.4, -91.7762, 44.2336, 189.757, 0, 1.42552, -0, "weedunkShocker" );
	Horde:FindNodes( LevelMod, "pasted__weedunkShockPlate5", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = pasted__weedunkShockPlate5_scripted };
	pasted__weedunkShockPlate5_posX = -91.7762;
	pasted__weedunkShockPlate5_posY = 44.2336;
	pasted__weedunkShockPlate5_posZ = 189.757;
	pasted__weedunkShockPlate5_rotX = 0;
	pasted__weedunkShockPlate5_rotY = 1.42552;
	pasted__weedunkShockPlate5_rotZ = -0;
end

