-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe15.
function mulchPipe15_OBJECT ()
	mulchPipe15_scripted = ODE:CreateMovingBox( 3.47752, 1.95393, 1.45391, -45.9095, 52.6415, 137.471, 0, -45, -0, "mulchValveNorthEast" );
	Horde:FindNodes( LevelMod, "mulchPipe15", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe15_scripted };
	mulchPipe15_posX = -45.9095;
	mulchPipe15_posY = 52.6415;
	mulchPipe15_posZ = 137.471;
	mulchPipe15_rotX = 0;
	mulchPipe15_rotY = -45;
	mulchPipe15_rotZ = -0;
end

