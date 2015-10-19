-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fanForceAimedOut.
function fanForceAimedOut_OBJECT ()
	fanForceAimedOut_scripted = ODE:CreateMovingBox( 4.99999, 15, 5, -76.6019, 37.6921, 181.749, 10, 45, -0, "fanForceAimedOut" );
	Horde:FindNodes( LevelMod, "fanForceAimedOut", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fanForceAimedOut_scripted };
	fanForceAimedOut_posX = -76.6019;
	fanForceAimedOut_posY = 37.6921;
	fanForceAimedOut_posZ = 181.749;
	fanForceAimedOut_rotX = 10;
	fanForceAimedOut_rotY = 45;
	fanForceAimedOut_rotZ = -0;
end

