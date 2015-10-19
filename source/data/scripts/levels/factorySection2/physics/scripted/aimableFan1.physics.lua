-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for aimableFan1.
function aimableFan1_OBJECT ()
	aimableFan1_scripted = ODE:CreateMovingBox( 5.38482, 0.1, 6.17316, -77.4929, 30.6703, 182.647, 0, 45, -0, "aimableFan" );
	Horde:FindNodes( LevelMod, "aimableFan1", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = aimableFan1_scripted };
	aimableFan1_posX = -77.4929;
	aimableFan1_posY = 30.6703;
	aimableFan1_posZ = 182.647;
	aimableFan1_rotX = 0;
	aimableFan1_rotY = 45;
	aimableFan1_rotZ = -0;
end

