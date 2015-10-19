-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe67.
function mulchPipe67_OBJECT ()
	mulchPipe67_scripted = ODE:CreateMovingBox( 3.47753, 1.95393, 1.45391, -42.4079, 52.6415, 138.789, 0, -90, -0, "mulchValveNorth" );
	Horde:FindNodes( LevelMod, "mulchPipe67", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe67_scripted };
	mulchPipe67_posX = -42.4079;
	mulchPipe67_posY = 52.6415;
	mulchPipe67_posZ = 138.789;
	mulchPipe67_rotX = 0;
	mulchPipe67_rotY = -90;
	mulchPipe67_rotZ = -0;
end

