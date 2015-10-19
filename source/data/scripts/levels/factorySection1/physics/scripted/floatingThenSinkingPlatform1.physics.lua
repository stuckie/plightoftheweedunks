-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for floatingThenSinkingPlatform1.
function floatingThenSinkingPlatform1_OBJECT ()
	floatingThenSinkingPlatform1_scripted = ODE:CreateMovingBox( 8, 1, 6, -66.7946, 12.8643, 231.78, 0, -0, -0, "floor" );
	nodeHandle = floatingThenSinkingPlatform1;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = floatingThenSinkingPlatform1_scripted };
	floatingThenSinkingPlatform1_posX = -66.7946;
	floatingThenSinkingPlatform1_posY = 12.8643;
	floatingThenSinkingPlatform1_posZ = 231.78;
	floatingThenSinkingPlatform1_rotX = 0;
	floatingThenSinkingPlatform1_rotY = -0;
	floatingThenSinkingPlatform1_rotZ = -0;
end

