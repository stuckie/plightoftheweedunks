-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for teeth11.
function teeth11_OBJECT ()
	teeth11_scripted = ODE:CreateMovingBox( 9.22222, 3.15, 1.2, 0, 8.29067, 2.06736, 0, -0, -0, "toothysTeeth" );
	Horde:FindNodes( LevelMod, "teeth4", "Mesh" );
	teeth11_node = Horde:GetNodeFindResult(0);
	toothy_SCRIPTED = { next = toothy_SCRIPTED, node = teeth11_node, physics = teeth11_scripted };
	teeth11_posX = 0;
	teeth11_posY = 8.29067;
	teeth11_posZ = 2.06736;
	teeth11_rotX = 0;
	teeth11_rotY = -0;
	teeth11_rotZ = -0;
end

