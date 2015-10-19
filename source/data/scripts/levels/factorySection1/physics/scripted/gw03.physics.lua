-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw03.
function gw03_OBJECT ()
	gw03_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, 68, -0.288492, 48.9, 0, -0, -0, "gw03" );
	Horde:FindNodes( goldenweedunks, "gw03", "Mesh" );
	gw03 = Horde:GetNodeFindResult(0);
	gw03_posX = 68;
	gw03_posY = -0.288492;
	gw03_posZ = 48.9;
	gw03_rotX = 0;
	gw03_rotY = -0;
	gw03_rotZ = -0;
end

