-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw04.
function gw04_OBJECT ()
	gw04_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, 77.3, -3.48072, 155.5, 0, -0, -0, "gw04" );
	Horde:FindNodes( goldenweedunks, "gw04", "Mesh" );
	gw04 = Horde:GetNodeFindResult(0);
	gw04_posX = 77.3;
	gw04_posY = -3.48072;
	gw04_posZ = 155.5;
	gw04_rotX = 0;
	gw04_rotY = -0;
	gw04_rotZ = -0;
end

