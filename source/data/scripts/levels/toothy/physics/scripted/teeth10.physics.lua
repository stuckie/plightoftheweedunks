-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for teeth10.
function teeth10_OBJECT ()
	teeth10_scripted = ODE:CreateMovingBox( 9.22222, 3.15, 1.2, 0, 8.23419, -78.3095, 0, -0, -0, "toothysTeeth" );
	Horde:FindNodes( LevelMod, "teeth3", "Mesh" );
	teeth10_node = Horde:GetNodeFindResult(0);
	toothy_SCRIPTED = { next = toothy_SCRIPTED, node = teeth10_node, physics = teeth10_scripted };
	teeth10_posX = 0;
	teeth10_posY = 8.23419;
	teeth10_posZ = -78.3095;
	teeth10_rotX = 0;
	teeth10_rotY = -0;
	teeth10_rotZ = -0;
end

