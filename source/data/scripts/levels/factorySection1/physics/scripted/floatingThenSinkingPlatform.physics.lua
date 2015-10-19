-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for floatingThenSinkingPlatform.
function floatingThenSinkingPlatform_OBJECT ()
	floatingThenSinkingPlatform_scripted = ODE:CreateMovingBox( 8, 1, 6, -66.7946, 12.8643, 223.78, 0, -0, -0, "floor" );
	nodeHandle = floatingThenSinkingPlatform;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = floatingThenSinkingPlatform_scripted };
	floatingThenSinkingPlatform_posX = -66.7946;
	floatingThenSinkingPlatform_posY = 12.8643;
	floatingThenSinkingPlatform_posZ = 223.78;
	floatingThenSinkingPlatform_rotX = 0;
	floatingThenSinkingPlatform_rotY = -0;
	floatingThenSinkingPlatform_rotZ = -0;
end

