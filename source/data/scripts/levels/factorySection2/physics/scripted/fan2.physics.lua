-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fan2.
function fan2_OBJECT ()
	fan2_scripted = ODE:CreateMovingBox( 5.743, 1.5, 19.7, -66.653, 37.8, 94.7, 0, -90, -0, "fan" );
	Horde:FindNodes( LevelMod, "fan2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fan2_scripted };
	fan2_posX = -65.7943;
	fan2_posY = 37.8;
	fan2_posZ = 93.6005;
	fan2_rotX = 0;
	fan2_rotY = -90;
	fan2_rotZ = -0;
end

