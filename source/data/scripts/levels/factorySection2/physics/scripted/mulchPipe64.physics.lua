-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe64.
function mulchPipe64_OBJECT ()
	mulchPipe64_scripted = ODE:CreateMovingBox( 3.47752, 1.95393, 1.45391, -39.2486, 52.6415, 137.264, 0, -135, -0, "mulchValveNorthWest" );
	Horde:FindNodes( LevelMod, "mulchPipe64", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe64_scripted };
	mulchPipe64_posX = -39.2486;
	mulchPipe64_posY = 52.6415;
	mulchPipe64_posZ = 137.264;
	mulchPipe64_rotX = 0;
	mulchPipe64_rotY = -135;
	mulchPipe64_rotZ = -0;
end

