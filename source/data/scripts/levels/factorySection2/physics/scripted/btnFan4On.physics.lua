-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnFan4On.
function btnFan4On_OBJECT ()
	btnFan4On_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -33.5573, 56.4533, 102.43, 0, -0, -0, "btnFan4" );--[[
	Horde:FindNodes( LevelMod, "btnFan4On", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = btnFan4On_scripted };]]--
	btnFan4On_posX = -33.5573;
	btnFan4On_posY = 56.4533;
	btnFan4On_posZ = 102.43;
	btnFan4On_rotX = 0;
	btnFan4On_rotY = -0;
	btnFan4On_rotZ = -0;
end

