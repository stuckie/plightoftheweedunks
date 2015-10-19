-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw08.
function gw08_OBJECT ()
	gw08_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, -67.623, 19.1542, 158, 0, -0, -0, "gw08" );
	Horde:FindNodes( goldenweedunks, "gw08", "Mesh" );
	gw08 = Horde:GetNodeFindResult(0);
	gw08_posX = -67.623;
	gw08_posY = 19.1542;
	gw08_posZ = 158;
	gw08_rotX = 0;
	gw08_rotY = -0;
	gw08_rotZ = -0;
end

