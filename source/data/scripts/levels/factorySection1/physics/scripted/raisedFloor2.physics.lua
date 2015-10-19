-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for raisedFloor2.
function raisedFloor2_OBJECT ()
	raisedFloor2_scripted = ODE:CreateMovingBox( 12, 6, 30, -26.9224, -22.8927, 60.2783, 0, 90, -0, "wall" );
	nodeHandle = raisedFloor2;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = raisedFloor2_scripted };
	raisedFloor2_posX = -26.9224;
	raisedFloor2_posY = -22.8927;
	raisedFloor2_posZ = 60.2783;
	raisedFloor2_rotX = 0;
	raisedFloor2_rotY = 90;
	raisedFloor2_rotZ = -0;
end

