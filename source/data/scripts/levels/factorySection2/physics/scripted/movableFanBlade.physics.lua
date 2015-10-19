-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for movableFanBlade.
function movableFanBlade_OBJECT ()
	movableFanBlade_scripted = ODE:CreateMovingBox( 0.5, 0.5, 0.5, -77.4519, 31.117, 182.899, 0, -0, -0, "fan" );
	Horde:FindNodes( LevelMod, "movableFanBlade", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = movableFanBlade_scripted };
	movableFanBlade_posX = -77.4519;
	movableFanBlade_posY = 31.117;
	movableFanBlade_posZ = 182.899;
	movableFanBlade_rotX = 0;
	movableFanBlade_rotY = -0;
	movableFanBlade_rotZ = -0;
end

