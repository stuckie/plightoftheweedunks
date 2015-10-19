-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw09.
function gw09_OBJECT ()
	gw09_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, -139.889, -3.53324, 107.025, 0, -0, -0, "gw09" );
	Horde:FindNodes( goldenweedunks, "gw09", "Mesh" );
	gw09 = Horde:GetNodeFindResult(0);
	gw09_posX = -139.889;
	gw09_posY = -3.53324;
	gw09_posZ = 107.025;
	gw09_rotX = 0;
	gw09_rotY = -0;
	gw09_rotZ = -0;
end

