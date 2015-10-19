-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for floatingPlatform1.
function floatingPlatform1_OBJECT ()
	floatingPlatform1_scripted = ODE:CreateMovingBox( 8, 1, 6, 90.5132, -4.92281, 96.765, 0, -90, -0, "floatingPlatform1" );
	nodeHandle = floatingPlatform1;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = floatingPlatform1_scripted };
	floatingPlatform1_posX = 90.5132;
	floatingPlatform1_posY = -4.92281;
	floatingPlatform1_posZ = 96.765;
	floatingPlatform1_rotX = 0;
	floatingPlatform1_rotY = -90;
	floatingPlatform1_rotZ = -0;
end

