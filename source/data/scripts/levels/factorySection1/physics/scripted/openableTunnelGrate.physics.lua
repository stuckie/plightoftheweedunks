-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for openableTunnelGrate.
function openableTunnelGrate_OBJECT ()
	openableTunnelGrate_scripted = ODE:CreateMovingBox( 0.56752, 19.2956, 28.0283, 86.226, 3.25933, 89.4048, 0, -0, -0, "openableTunnelGrate" );
	nodeHandle = openableTunnelGrate;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = openableTunnelGrate_scripted };
	openableTunnelGrate_posX = 86.226;
	openableTunnelGrate_posY = 3.25933;
	openableTunnelGrate_posZ = 89.4048;
	openableTunnelGrate_rotX = 0;
	openableTunnelGrate_rotY = -0;
	openableTunnelGrate_rotZ = -0;
end

