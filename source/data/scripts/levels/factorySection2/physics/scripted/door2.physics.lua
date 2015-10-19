-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for door2.
function door2_OBJECT ()
	door2_scripted = ODE:CreateMovingBox( 0.609889, 14.0985, 2.24525, -83.2719, 51.2531, 197.341, 0, -90, -0, "door" );
	Horde:FindNodes( LevelMod, "door2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = door2_scripted };
	door2_posX = -83.2719;
	door2_posY = 51.2531;
	door2_posZ = 197.341;
	door2_rotX = 0;
	door2_rotY = -90;
	door2_rotZ = -0;
end

