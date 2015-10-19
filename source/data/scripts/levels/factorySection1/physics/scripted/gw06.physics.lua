-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for gw06.
function gw06_OBJECT ()
	gw06_scripted = ODE:CreateMovingBox( 0.305591, 0.305591, 0.305591, 84.2381, 14.5072, 214.818, 0, -0, -0, "gw06" );
	Horde:FindNodes( goldenweedunks, "gw06", "Mesh" );
	gw06 = Horde:GetNodeFindResult(0);
	gw06_posX = 84.2381;
	gw06_posY = 14.5072;
	gw06_posZ = 214.818;
	gw06_rotX = 0;
	gw06_rotY = -0;
	gw06_rotZ = -0;
end

