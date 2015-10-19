-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for wp2.
function wp2_OBJECT ()
	wp2_scripted = ODE:CreateMovingBox( 2, 2, 2, -55.1111, 14.3881, 28.8685, 0, -0, -0, "weedunkPortal" );
	Horde:FindNodes( LevelMod, "wp2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = wp2_scripted };
	wp2_posX = -55.1111;
	wp2_posY = 14.3881;
	wp2_posZ = 28.8685;
	wp2_rotX = 0;
	wp2_rotY = -0;
	wp2_rotZ = -0;
end

