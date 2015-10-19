-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for raisedFloor4.
function raisedFloor4_OBJECT ()
	raisedFloor4_scripted = ODE:CreateMovingBox( 4, 2, 30, -26.9224, -17.1291, 64.2784, 0, 90, -0, "wall" );
	nodeHandle = raisedFloor4;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = raisedFloor4_scripted };
	raisedFloor4_posX = -26.9224;
	raisedFloor4_posY = -17.1291;
	raisedFloor4_posZ = 64.2784;
	raisedFloor4_rotX = 0;
	raisedFloor4_rotY = 90;
	raisedFloor4_rotZ = -0;
end

