-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fan1.
function fan1_OBJECT ()
	fan1_scripted = ODE:CreateMovingBox( 7.5, 0.85, 7.5, -87.186, 15.7996, 47.7435, 0, -45, -0, "fan" );
	Horde:FindNodes( LevelMod, "fan1", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fan1_scripted };
	fan1_posX = -87.186;
	fan1_posY = 15.7996;
	fan1_posZ = 47.7435;
	fan1_rotX = 0;
	fan1_rotY = -45;
	fan1_rotZ = -0;
end

