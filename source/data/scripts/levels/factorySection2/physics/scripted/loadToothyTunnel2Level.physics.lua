-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for loadToothyTunnel2Level.
function loadToothyTunnel2Level_OBJECT ()
	loadToothyTunnel2Level_scripted = ODE:CreateMovingBox( 5.7246, 12.8864, 8.48315, -90.1486, 50.2241, 205.646, 0, -90, -0, "loadToothyTunnel2Level" );
	Horde:FindNodes( LevelMod, "loadToothyTunnel2Level", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = loadToothyTunnel2Level_scripted };
	loadToothyTunnel2Level_posX = -90.1486;
	loadToothyTunnel2Level_posY = 50.2241;
	loadToothyTunnel2Level_posZ = 205.646;
	loadToothyTunnel2Level_rotX = 0;
	loadToothyTunnel2Level_rotY = -90;
	loadToothyTunnel2Level_rotZ = -0;
end

