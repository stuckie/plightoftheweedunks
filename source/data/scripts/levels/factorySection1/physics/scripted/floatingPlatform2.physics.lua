-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for floatingPlatform2.
function floatingPlatform2_OBJECT ()
	floatingPlatform2_scripted = ODE:CreateMovingBox( 8, 1, 6, 100.129, -4.92281, 82.5429, 0, -90, -0, "floatingPlatform2" );
	nodeHandle = floatingPlatform2;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = floatingPlatform2_scripted };
	floatingPlatform2_posX = 100.129;
	floatingPlatform2_posY = -4.92281;
	floatingPlatform2_posZ = 82.5429;
	floatingPlatform2_rotX = 0;
	floatingPlatform2_rotY = -90;
	floatingPlatform2_rotZ = -0;
end

