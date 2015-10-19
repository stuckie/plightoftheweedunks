-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for teeth12.
function teeth12_OBJECT ()
	teeth12_scripted = ODE:CreateMovingBox( 9.22222, 3.15, 1.2, 0, 8.2342, 22.1217, 0, -0, -0, "toothysTeeth" );
	Horde:FindNodes( LevelMod, "teeth5", "Mesh" );
	teeth12_node = Horde:GetNodeFindResult(0);
	toothy_SCRIPTED = { next = toothy_SCRIPTED, node = teeth12_node, physics = teeth12_scripted };
	teeth12_posX = 0;
	teeth12_posY = 8.2342;
	teeth12_posZ = 22.1217;
	teeth12_rotX = 0;
	teeth12_rotY = -0;
	teeth12_rotZ = -0;
end

