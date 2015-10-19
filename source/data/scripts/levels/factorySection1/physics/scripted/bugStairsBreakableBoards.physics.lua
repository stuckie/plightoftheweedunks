-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for bugStairsBreakableBoards.
function bugStairsBreakableBoards_OBJECT ()
	bugStairsBreakableBoards_scripted = ODE:CreateMovingBox( 0.458319, 15.7544, 2.69178, -26.4676, 6.15359, 156.416, -90, -0, -90, "bugStairsBreakableBoards" );
	nodeHandle = bugStairsBreakableBoards;
	factorySection1_SCRIPTED = { next = factorySection1_SCRIPTED, node = nodeHandle, physics = bugStairsBreakableBoards_scripted };
	bugStairsBreakableBoards_posX = -26.4676;
	bugStairsBreakableBoards_posY = 6.15359;
	bugStairsBreakableBoards_posZ = 156.416;
	bugStairsBreakableBoards_rotX = -90;
	bugStairsBreakableBoards_rotY = -0;
	bugStairsBreakableBoards_rotZ = -90;
end

