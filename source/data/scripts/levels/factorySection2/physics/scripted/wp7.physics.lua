-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for wp7.
function wp7_OBJECT ()
	wp7_scripted = ODE:CreateMovingBox( 2, 2, 2, 3.29947, 54.3644, 145.157, 0, -90, -0, "weedunkPortal" );
	Horde:FindNodes( LevelMod, "wp7", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = wp7_scripted };
	wp7_posX = 3.29947;
	wp7_posY = 54.3644;
	wp7_posZ = 145.157;
	wp7_rotX = 0;
	wp7_rotY = -90;
	wp7_rotZ = -0;
end

