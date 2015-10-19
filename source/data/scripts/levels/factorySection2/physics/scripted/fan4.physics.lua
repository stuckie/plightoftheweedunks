-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for fan4.
function fan4_OBJECT ()
	fan4_scripted = ODE:CreateMovingBox( 7.5, 1.5, 7.5, -36.3277, 60.0819, 96.6577, -90, -0, 180, "fan" );
	Horde:FindNodes( LevelMod, "fan4", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = fan4_scripted };
	fan4_posX = -36.3277;
	fan4_posY = 60.0819;
	fan4_posZ = 96.6577;
	fan4_rotX = -90;
	fan4_rotY = -0;
	fan4_rotZ = 180;
end

