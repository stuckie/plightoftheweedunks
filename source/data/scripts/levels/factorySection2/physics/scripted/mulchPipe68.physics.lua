-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for mulchPipe68.
function mulchPipe68_OBJECT ()
	mulchPipe68_scripted = ODE:CreateMovingBox( 3.47753, 1.95393, 1.45391, -42.1199, 52.6415, 129.358, 0, 90, -0, "mulchValveSouth" );
	Horde:FindNodes( LevelMod, "mulchPipe68", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = mulchPipe68_scripted };
	mulchPipe68_posX = -42.1199;
	mulchPipe68_posY = 52.6415;
	mulchPipe68_posZ = 129.358;
	mulchPipe68_rotX = 0;
	mulchPipe68_rotY = 90;
	mulchPipe68_rotZ = -0;
end

