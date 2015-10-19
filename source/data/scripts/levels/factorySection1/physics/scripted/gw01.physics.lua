-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw01.
function gw01_OBJECT ()
	gw01_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, 77, 12.645, 4, 0, -0, -0, "gw01" );
	Horde:FindNodes( goldenweedunks, "gw01", "Mesh" );
	gw01 = Horde:GetNodeFindResult(0);
	gw01_posX = 77;
	gw01_posY = 12.645;
	gw01_posZ = 4;
	gw01_rotX = 0;
	gw01_rotY = -0;
	gw01_rotZ = -0;
end

