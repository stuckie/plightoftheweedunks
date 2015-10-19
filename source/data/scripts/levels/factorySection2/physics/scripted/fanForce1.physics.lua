-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fanForce1.
function fanForce1_OBJECT ()
	fanForce1_scripted = ODE:CreateMovingBox( 4.99999, 25, 6.11151, -86.8619, 28.7081, 48.1374, 0, -45, -0, "fanForce1" );
	Horde:FindNodes( LevelMod, "fanForce1", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fanForce1_scripted };
	fanForce1_posX = -86.8619;
	fanForce1_posY = 28.7081;
	fanForce1_posZ = 48.1374;
	fanForce1_rotX = 0;
	fanForce1_rotY = -45;
	fanForce1_rotZ = -0;
end

