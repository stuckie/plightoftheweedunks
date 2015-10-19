-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for teeth14.
function teeth14_OBJECT ()
	teeth14_scripted = ODE:CreateMovingBox( 7.06488, 2.41313, 0.919286, 0, 4.45458, -115.832, 0, -0, -0, "toothysTeeth" );
	Horde:FindNodes( LevelMod, "teeth7", "Mesh" );
	teeth14_node = Horde:GetNodeFindResult(0);
	toothy_SCRIPTED = { next = toothy_SCRIPTED, node = teeth14_node, physics = teeth14_scripted };
	teeth14_posX = 0;
	teeth14_posY = 4.45458;
	teeth14_posZ = -115.832;
	teeth14_rotX = 0;
	teeth14_rotY = -0;
	teeth14_rotZ = -0;
end

