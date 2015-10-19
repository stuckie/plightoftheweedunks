-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for floatingThenSinkingPlatform3.
function floatingThenSinkingPlatform3_OBJECT ()
	floatingThenSinkingPlatform3_scripted = ODE:CreateMovingBox( 8, 1, 6, -66.7946, 12.8643, 247.78, 0, -0, -0, "floor" );
	nodeHandle = floatingThenSinkingPlatform3;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = floatingThenSinkingPlatform3_scripted };
	floatingThenSinkingPlatform3_posX = -66.7946;
	floatingThenSinkingPlatform3_posY = 12.8643;
	floatingThenSinkingPlatform3_posZ = 247.78;
	floatingThenSinkingPlatform3_rotX = 0;
	floatingThenSinkingPlatform3_rotY = -0;
	floatingThenSinkingPlatform3_rotZ = -0;
end

