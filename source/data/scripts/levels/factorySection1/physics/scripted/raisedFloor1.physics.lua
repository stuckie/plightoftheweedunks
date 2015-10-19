-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for raisedFloor1.
function raisedFloor1_OBJECT ()
	raisedFloor1_scripted = ODE:CreateMovingBox( 8.54417, 0.85, 5, -27.1168, -16.4661, 70.5708, 0, 90, -0, "wall" );
	nodeHandle = raisedFloor1;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = raisedFloor1_scripted };
	raisedFloor1_posX = -27.1168;
	raisedFloor1_posY = -16.4661;
	raisedFloor1_posZ = 70.5708;
	raisedFloor1_rotX = 0;
	raisedFloor1_rotY = 90;
	raisedFloor1_rotZ = -0;
end

