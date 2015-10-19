-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe65.
function mulchPipe65_OBJECT ()
	mulchPipe65_scripted = ODE:CreateMovingBox( 3.47753, 1.95393, 1.45391, -37.8158, 52.6415, 134.002, 0, -180, -0, "mulchValveWest" );
	Horde:FindNodes( LevelMod, "mulchPipe65", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe65_scripted };
	mulchPipe65_posX = -37.8158;
	mulchPipe65_posY = 52.6415;
	mulchPipe65_posZ = 134.002;
	mulchPipe65_rotX = 0;
	mulchPipe65_rotY = -180;
	mulchPipe65_rotZ = -0;
end

