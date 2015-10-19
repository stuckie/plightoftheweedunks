-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnFanAimedIn.
function btnFanAimedIn_OBJECT ()
	btnFanAimedIn_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -82.7532, 43.812, 180.888, 0, -45, -0, "btnFanAimedIn" );
	Horde:FindNodes( LevelMod, "btnFanAimedIn", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = btnFanAimedIn_scripted };
	btnFanAimedIn_posX = -82.7532;
	btnFanAimedIn_posY = 43.812;
	btnFanAimedIn_posZ = 180.888;
	btnFanAimedIn_rotX = 0;
	btnFanAimedIn_rotY = -45;
	btnFanAimedIn_rotZ = -0;
end

