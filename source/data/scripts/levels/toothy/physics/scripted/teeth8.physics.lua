-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for teeth8.
function teeth8_OBJECT ()
	teeth8_scripted = ODE:CreateMovingBox( 9.22222, 3.15, 1.2, 0, 8.23419, -17.9551, 0, -0, -0, "toothysTeeth" );
	Horde:FindNodes( LevelMod, "teeth1", "Mesh" );
	teeth8_node = Horde:GetNodeFindResult(0);
	toothy_SCRIPTED = { next = toothy_SCRIPTED, node = teeth8_node, physics = teeth8_scripted };
	teeth8_posX = 0;
	teeth8_posY = 8.23419;
	teeth8_posZ = -17.9551;
	teeth8_rotX = 0;
	teeth8_rotY = -0;
	teeth8_rotZ = -0;
end

