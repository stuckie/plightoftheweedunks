-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for wp6.
function wp6_OBJECT ()
	wp6_scripted = ODE:CreateMovingBox( 1.99999, 2, 1.99999, -104.941, 30.0034, 184.96, 0, -45, -0, "weedunkPortal" );
	Horde:FindNodes( LevelMod, "wp6", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = wp6_scripted };
	wp6_posX = -104.941;
	wp6_posY = 30.0034;
	wp6_posZ = 184.96;
	wp6_rotX = 0;
	wp6_rotY = -45;
	wp6_rotZ = -0;
end

