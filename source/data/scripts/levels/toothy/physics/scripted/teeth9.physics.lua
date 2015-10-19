-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for teeth9.
function teeth9_OBJECT ()
	teeth9_scripted = ODE:CreateMovingBox( 9.22222, 3.15, 1.2, 0, 8.23419, -58.1733, 0, -0, -0, "toothysTeeth" );
	Horde:FindNodes( LevelMod, "teeth2", "Mesh" );
	teeth9_node = Horde:GetNodeFindResult(0);
	toothy_SCRIPTED = { next = toothy_SCRIPTED, node = teeth9_node, physics = teeth9_scripted };
	teeth9_posX = 0;
	teeth9_posY = 8.23419;
	teeth9_posZ = -58.1733;
	teeth9_rotX = 0;
	teeth9_rotY = -0;
	teeth9_rotZ = -0;
end

