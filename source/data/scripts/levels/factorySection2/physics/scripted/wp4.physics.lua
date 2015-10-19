-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for wp4.
function wp4_OBJECT ()
	wp4_scripted = ODE:CreateMovingBox( 2, 2, 2, -51.4841, 49.4976, 137.924, 0, -90, -0, "weedunkPortal" );
	Horde:FindNodes( LevelMod, "wp4", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = wp4_scripted };
	wp4_posX = -51.4841;
	wp4_posY = 49.4976;
	wp4_posZ = 137.924;
	wp4_rotX = 0;
	wp4_rotY = -90;
	wp4_rotZ = -0;
end

