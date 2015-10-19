-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnFan1.
function btnFan1_OBJECT ()
	btnFan1_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -79.1589, 38.6453, 47.8989, 0, -45, -0, "btnFan1" );
	--[[Horde:FindNodes( LevelMod, "btnFan1", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = btnFan1_scripted };]]--
	btnFan1_posX = -79.1589;
	btnFan1_posY = 38.6453;
	btnFan1_posZ = 47.8989;
	btnFan1_rotX = 0;
	btnFan1_rotY = -45;
	btnFan1_rotZ = -0;
end

