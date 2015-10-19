-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnFan3On.
function btnFan3On_OBJECT ()
	btnFan3On_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -63.7272, 56.4773, 102.887, 0, -0, -0, "btnFan3" );--[[
	Horde:FindNodes( LevelMod, "btnFan3On", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = btnFan3On_scripted };]]--
	btnFan3On_posX = -63.7272;
	btnFan3On_posY = 56.4773;
	btnFan3On_posZ = 102.887;
	btnFan3On_rotX = 0;
	btnFan3On_rotY = -0;
	btnFan3On_rotZ = -0;
end

