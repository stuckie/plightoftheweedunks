-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for door1.
function door1_OBJECT ()
	door1_scripted = ODE:CreateMovingBox( 0.609889, 14.0985, 2.24525, -96.2112, 51.2531, 197.341, 0, -90, -0, "door" );
	Horde:FindNodes( LevelMod, "door1", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = door1_scripted };
	door1_posX = -96.2112;
	door1_posY = 51.2531;
	door1_posZ = 197.341;
	door1_rotX = 0;
	door1_rotY = -90;
	door1_rotZ = -0;
end

