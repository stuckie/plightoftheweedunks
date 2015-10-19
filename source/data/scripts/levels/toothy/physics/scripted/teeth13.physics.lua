-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for teeth13.
function teeth13_OBJECT ()
	teeth13_scripted = ODE:CreateMovingBox( 9.22222, 3.15, 1.2, 0, 8.23419, -98.4187, 0, -0, -0, "toothysTeeth" );
	Horde:FindNodes( LevelMod, "teeth6", "Mesh" );
	teeth13_node = Horde:GetNodeFindResult(0);
	toothy_SCRIPTED = { next = toothy_SCRIPTED, node = teeth13_node, physics = teeth13_scripted };
	teeth13_posX = 0;
	teeth13_posY = 8.23419;
	teeth13_posZ = -98.4187;
	teeth13_rotX = 0;
	teeth13_rotY = -0;
	teeth13_rotZ = -0;
end

