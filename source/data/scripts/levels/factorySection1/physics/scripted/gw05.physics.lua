-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw05.
function gw05_OBJECT ()
	gw05_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, -26.9576, 6.44048, 163.741, 0, -0, -0, "gw05" );
	Horde:FindNodes( goldenweedunks, "gw05", "Mesh" );
	gw05 = Horde:GetNodeFindResult(0);
	gw05_posX = -26.9576;
	gw05_posY = 6.44048;
	gw05_posZ = 163.741;
	gw05_rotX = 0;
	gw05_rotY = -0;
	gw05_rotZ = -0;
end

