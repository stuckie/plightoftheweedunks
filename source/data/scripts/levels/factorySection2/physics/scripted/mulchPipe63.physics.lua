-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe63.
function mulchPipe63_OBJECT ()
	mulchPipe63_scripted = ODE:CreateMovingBox( 3.47752, 1.95393, 1.45391, -45.2246, 52.6415, 131.148, 0, 45, -0, "mulchValveSouthEast" );
	Horde:FindNodes( LevelMod, "mulchPipe63", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe63_scripted };
	mulchPipe63_posX = -45.2246;
	mulchPipe63_posY = 52.6415;
	mulchPipe63_posZ = 131.148;
	mulchPipe63_rotX = 0;
	mulchPipe63_rotY = 45;
	mulchPipe63_rotZ = -0;
end

