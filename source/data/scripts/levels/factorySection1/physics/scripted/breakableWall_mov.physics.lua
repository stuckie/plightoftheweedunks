-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for breakableWall_mov.
function breakableWall_mov_OBJECT ()
	breakableWall_mov_scripted = ODE:CreateMovingBox( 1.85975, 25.1905, 31.3137, -27.3924, 10.8691, 34.9753, 0, 90, -0, "breakableWall" );
	nodeHandle = breakableWall_mov;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = breakableWall_mov_scripted };
	breakableWall_mov_posX = -27.3924;
	breakableWall_mov_posY = 10.8691;
	breakableWall_mov_posZ = 34.9753;
	breakableWall_mov_rotX = 0;
	breakableWall_mov_rotY = 90;
	breakableWall_mov_rotZ = -0;
end

