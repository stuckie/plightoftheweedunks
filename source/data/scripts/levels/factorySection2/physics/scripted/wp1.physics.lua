-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for wp1.
function wp1_OBJECT ()
	wp1_scripted = ODE:CreateMovingBox( 2, 2, 2, -89.5973, 14.3874, 17.2075, 0, -0, -0, "weedunkPortal" );
	Horde:FindNodes( LevelMod, "wp1", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = wp1_scripted };
	wp1_posX = -89.5973;
	wp1_posY = 14.3874;
	wp1_posZ = 17.2075;
	wp1_rotX = 0;
	wp1_rotY = -0;
	wp1_rotZ = -0;
end

