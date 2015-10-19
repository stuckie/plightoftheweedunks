-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnFan2.
function btnFan2_OBJECT ()
	btnFan2_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -71.0648, 38.6284, 90.9992, 0, -90, -0, "btnFan2" );--[[
	Horde:FindNodes( LevelMod, "btnFan2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = btnFan2_scripted };]]--
	btnFan2_posX = -71.0648;
	btnFan2_posY = 38.6284;
	btnFan2_posZ = 90.9992;
	btnFan2_rotX = 0;
	btnFan2_rotY = -90;
	btnFan2_rotZ = -0;
end

