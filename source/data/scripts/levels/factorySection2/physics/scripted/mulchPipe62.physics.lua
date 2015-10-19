-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe62.
function mulchPipe62_OBJECT ()
	mulchPipe62_scripted = ODE:CreateMovingBox( 3.47752, 1.95393, 1.45391, -39.1892, 52.6415, 130.864, 0, 135, -0, "mulchValveSouthWest" );
	Horde:FindNodes( LevelMod, "mulchPipe62", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe62_scripted };
	mulchPipe62_posX = -39.1892;
	mulchPipe62_posY = 52.6415;
	mulchPipe62_posZ = 130.864;
	mulchPipe62_rotX = 0;
	mulchPipe62_rotY = 135;
	mulchPipe62_rotZ = -0;
end

