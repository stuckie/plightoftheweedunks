-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for loadWeedunkBangLevel.
function loadWeedunkBangLevel_OBJECT ()
	loadWeedunkBangLevel_scripted = ODE:CreateMovingBox( 3.61672, 4.18332, 4, -89.8102, 0.343409, 189.361, 0, -0, -90, "loadWeedunkBangLevel" );
	Horde:FindNodes( LevelMod, "loadWeedunkBangLevel", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = loadWeedunkBangLevel_scripted };
	loadWeedunkBangLevel_posX = -89.8102;
	loadWeedunkBangLevel_posY = 0.343409;
	loadWeedunkBangLevel_posZ = 189.361;
	loadWeedunkBangLevel_rotX = 0;
	loadWeedunkBangLevel_rotY = -0;
	loadWeedunkBangLevel_rotZ = -90;
end

