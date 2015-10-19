-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fanForceAimedIn.
function fanForceAimedIn_OBJECT ()
	fanForceAimedIn_scripted = ODE:CreateMovingBox( 4.99999, 15, 4.99999, -77.4634, 38.3968, 182.611, 0, 45, -0, "fanForceAimedIn" );
	Horde:FindNodes( LevelMod, "fanForceAimedIn", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fanForceAimedIn_scripted };
	fanForceAimedIn_posX = -77.4634;
	fanForceAimedIn_posY = 38.3968;
	fanForceAimedIn_posZ = 182.611;
	fanForceAimedIn_rotX = 0;
	fanForceAimedIn_rotY = 45;
	fanForceAimedIn_rotZ = -0;
end

