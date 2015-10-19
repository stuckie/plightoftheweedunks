-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for conveyorTowerPipe5.
function conveyorTowerPipe5_OBJECT ()
	conveyorTowerPipe5_scripted = ODE:CreateMovingBox( 4.49845, 0.3, 3.21363, -66.3152, 25.3809, 40.2074, 0, -0, -0, "explodeUnderPlatform" );
	Horde:FindNodes( LevelMod, "conveyorTowerPipe5", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = conveyorTowerPipe5_scripted };
	conveyorTowerPipe5_posX = -66.3152;
	conveyorTowerPipe5_posY = 25.3809;
	conveyorTowerPipe5_posZ = 40.2074;
	conveyorTowerPipe5_rotX = 0;
	conveyorTowerPipe5_rotY = -0;
	conveyorTowerPipe5_rotZ = -0;
end

