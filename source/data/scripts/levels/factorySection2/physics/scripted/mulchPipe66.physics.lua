-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe66.
function mulchPipe66_OBJECT ()
	mulchPipe66_scripted = ODE:CreateMovingBox( 3.47753, 1.95393, 1.45391, -46.9784, 52.6415, 134.105, 0, -0, -0, "mulchValveEast" );
	Horde:FindNodes( LevelMod, "mulchPipe66", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe66_scripted };
	mulchPipe66_posX = -46.9784;
	mulchPipe66_posY = 52.6415;
	mulchPipe66_posZ = 134.105;
	mulchPipe66_rotX = 0;
	mulchPipe66_rotY = -0;
	mulchPipe66_rotZ = -0;
end

