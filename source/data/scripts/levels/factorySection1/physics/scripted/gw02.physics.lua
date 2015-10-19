-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw02.
function gw02_OBJECT ()
	gw02_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, -26.75, -0.965135, 26.46, 0, -0, -0, "gw02" );
	Horde:FindNodes( goldenweedunks, "gw02", "Mesh" );
	gw02 = Horde:GetNodeFindResult(0);
	gw02_posX = -26.75;
	gw02_posY = -0.965135;
	gw02_posZ = 26.46;
	gw02_rotX = 0;
	gw02_rotY = -0;
	gw02_rotZ = -0;
end

