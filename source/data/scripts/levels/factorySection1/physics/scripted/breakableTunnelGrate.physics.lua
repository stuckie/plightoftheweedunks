-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for breakableTunnelGrate.
function breakableTunnelGrate_OBJECT ()
	breakableTunnelGrate_scripted = ODE:CreateMovingBox( 19.2515, 10.6045, 0.308113, -66.8373, 19.02, 215.596, 0, -0, -0, "breakableTunnelGrate" );
	nodeHandle = breakableTunnelGrate;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = breakableTunnelGrate_scripted };
	breakableTunnelGrate_posX = -66.8373;
	breakableTunnelGrate_posY = 19.02;
	breakableTunnelGrate_posZ = 215.596;
	breakableTunnelGrate_rotX = 0;
	breakableTunnelGrate_rotY = -0;
	breakableTunnelGrate_rotZ = -0;
end

