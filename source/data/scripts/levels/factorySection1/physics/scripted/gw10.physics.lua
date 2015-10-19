-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw10.
function gw10_OBJECT ()
	gw10_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, -26.9639, 5.45659, 25.8618, 0, -0, -0, "gw10" );
	Horde:FindNodes( goldenweedunks, "gw10", "Mesh" );
	gw10 = Horde:GetNodeFindResult(0);
	gw10_posX = -26.9639;
	gw10_posY = 5.45659;
	gw10_posZ = 25.8618;
	gw10_rotX = 0;
	gw10_rotY = -0;
	gw10_rotZ = -0;
end

