-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for wp3.
function wp3_OBJECT ()
	wp3_scripted = ODE:CreateMovingBox( 2, 2, 2, -59.669, 37.6423, 44.0018, 0, -0, -0, "weedunkPortal" );
	Horde:FindNodes( LevelMod, "wp3", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = wp3_scripted };
	wp3_posX = -59.669;
	wp3_posY = 37.6423;
	wp3_posZ = 44.0018;
	wp3_rotX = 0;
	wp3_rotY = -0;
	wp3_rotZ = -0;
end

