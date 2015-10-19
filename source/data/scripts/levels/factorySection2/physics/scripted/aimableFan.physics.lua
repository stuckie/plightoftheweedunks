-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for aimableFan.
function aimableFan_OBJECT ()
	aimableFan_scripted = ODE:CreateMovingBox( 7.00753, 0.304818, 7.00753, -77.4605, 30.4896, 182.815, 0, 45, -0, "aimableFan" );
	Horde:FindNodes( LevelMod, "aimableFan", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = aimableFan_scripted };
	aimableFan_posX = -77.4605;
	aimableFan_posY = 30.4896;
	aimableFan_posZ = 182.815;
	aimableFan_rotX = 0;
	aimableFan_rotY = 45;
	aimableFan_rotZ = -0;
end

