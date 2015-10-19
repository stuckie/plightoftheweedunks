-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnFanAimedOff.
function btnFanAimedOff_OBJECT ()
	btnFanAimedOff_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -81.4266, 43.812, 179.562, 0, -45, -0, "btnFanAimedOff" );
	Horde:FindNodes( LevelMod, "btnFanAimedOff", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = btnFanAimedOff_scripted };
	btnFanAimedOff_posX = -81.4266;
	btnFanAimedOff_posY = 43.812;
	btnFanAimedOff_posZ = 179.562;
	btnFanAimedOff_rotX = 0;
	btnFanAimedOff_rotY = -45;
	btnFanAimedOff_rotZ = -0;
end

