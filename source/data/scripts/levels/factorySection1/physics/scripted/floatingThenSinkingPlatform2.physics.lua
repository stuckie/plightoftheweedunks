-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for floatingThenSinkingPlatform2.
function floatingThenSinkingPlatform2_OBJECT ()
	floatingThenSinkingPlatform2_scripted = ODE:CreateMovingBox( 8, 1, 6, -66.7946, 12.8643, 239.78, 0, -0, -0, "floor" );
	nodeHandle = floatingThenSinkingPlatform2;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = floatingThenSinkingPlatform2_scripted };
	floatingThenSinkingPlatform2_posX = -66.7946;
	floatingThenSinkingPlatform2_posY = 12.8643;
	floatingThenSinkingPlatform2_posZ = 239.78;
	floatingThenSinkingPlatform2_rotX = 0;
	floatingThenSinkingPlatform2_rotY = -0;
	floatingThenSinkingPlatform2_rotZ = -0;
end

