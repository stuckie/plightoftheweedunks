-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fanForceAimedOut2.
function fanForceAimedOut2_OBJECT ()
	fanForceAimedOut2_scripted = ODE:CreateMovingBox( 28.6215, 5, 5, -54.4679, 60.1083, 100.187, 0, -0, -0, "fanForce3" );
	Horde:FindNodes( LevelMod, "fanForceAimedOut2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fanForceAimedOut2_scripted };
	fanForceAimedOut2_posX = -54.4679;
	fanForceAimedOut2_posY = 60.1083;
	fanForceAimedOut2_posZ = 100.187;
	fanForceAimedOut2_rotX = 0;
	fanForceAimedOut2_rotY = -0;
	fanForceAimedOut2_rotZ = -0;
end

