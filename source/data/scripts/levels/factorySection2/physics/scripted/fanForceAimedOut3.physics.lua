-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fanForceAimedOut3.
function fanForceAimedOut3_OBJECT ()
	fanForceAimedOut3_scripted = ODE:CreateMovingBox( 5, 5, 18.5229, -36.3297, 60.1083, 106.771, 0, -0, -0, "fanForce4" );
	Horde:FindNodes( LevelMod, "fanForceAimedOut3", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fanForceAimedOut3_scripted };
	fanForceAimedOut3_posX = -36.3297;
	fanForceAimedOut3_posY = 60.1083;
	fanForceAimedOut3_posZ = 106.771;
	fanForceAimedOut3_rotX = 0;
	fanForceAimedOut3_rotY = -0;
	fanForceAimedOut3_rotZ = -0;
end

