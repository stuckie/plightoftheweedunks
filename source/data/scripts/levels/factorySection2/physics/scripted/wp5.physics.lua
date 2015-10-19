-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for wp5.
function wp5_OBJECT ()
	wp5_scripted = ODE:CreateMovingBox( 2, 2, 2, -32.5338, 49.5015, 137.919, 0, -90, -0, "weedunkPortal" );
	Horde:FindNodes( LevelMod, "wp5", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = wp5_scripted };
	wp5_posX = -32.5338;
	wp5_posY = 49.5015;
	wp5_posZ = 137.919;
	wp5_rotX = 0;
	wp5_rotY = -90;
	wp5_rotZ = -0;
end

