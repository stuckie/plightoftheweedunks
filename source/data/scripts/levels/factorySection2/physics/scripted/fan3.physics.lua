-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fan3.
function fan3_OBJECT ()
	fan3_scripted = ODE:CreateMovingBox( 7.5, 1.5, 7.5, -69.5678, 60.0819, 100.21, -90, -0, 90, "fan" );
	Horde:FindNodes( LevelMod, "fan3", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fan3_scripted };
	fan3_posX = -69.5678;
	fan3_posY = 60.0819;
	fan3_posZ = 100.21;
	fan3_rotX = -90;
	fan3_rotY = -0;
	fan3_rotZ = 90;
end

