-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw07.
function gw07_OBJECT ()
	gw07_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, -79.7357, 14.5113, 198.22, 0, -0, -0, "gw07" );
	Horde:FindNodes( goldenweedunks, "gw07", "Mesh" );
	gw07 = Horde:GetNodeFindResult(0);
	gw07_posX = -79.7357;
	gw07_posY = 14.5113;
	gw07_posZ = 198.22;
	gw07_rotX = 0;
	gw07_rotY = -0;
	gw07_rotZ = -0;
end

