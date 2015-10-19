-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fanForce2.
function fanForce2_OBJECT ()
	fanForce2_scripted = ODE:CreateMovingBox( 5, 21.638, 5, -65.7783, 49.4282, 93.7954, 0, -0, -0, "fanForce2" );
	Horde:FindNodes( LevelMod, "fanForce2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fanForce2_scripted };
	fanForce2_posX = -65.7783;
	fanForce2_posY = 49.4282;
	fanForce2_posZ = 93.7954;
	fanForce2_rotX = 0;
	fanForce2_rotY = -0;
	fanForce2_rotZ = -0;
end

