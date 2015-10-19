-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for raisedFloor3.
function raisedFloor3_OBJECT ()
	raisedFloor3_scripted = ODE:CreateMovingBox( 8, 4, 30, -26.9224, -19.9877, 62.2783, 0, 90, -0, "wall" );
	nodeHandle = raisedFloor3;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = raisedFloor3_scripted };
	raisedFloor3_posX = -26.9224;
	raisedFloor3_posY = -19.9877;
	raisedFloor3_posZ = 62.2783;
	raisedFloor3_rotX = 0;
	raisedFloor3_rotY = 90;
	raisedFloor3_rotZ = -0;
end

