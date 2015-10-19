-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnFanAimedOut.
function btnFanAimedOut_OBJECT ()
	btnFanAimedOut_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -80.1015, 43.812, 178.259, 0, -45, -0, "btnFanAimedOut" );
	Horde:FindNodes( LevelMod, "btnFanAimedOut", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = btnFanAimedOut_scripted };
	btnFanAimedOut_posX = -80.1015;
	btnFanAimedOut_posY = 43.812;
	btnFanAimedOut_posZ = 178.259;
	btnFanAimedOut_rotX = 0;
	btnFanAimedOut_rotY = -45;
	btnFanAimedOut_rotZ = -0;
end

