-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for door.
function door_OBJECT ()
	door_scripted = ODE:CreateMovingBox( 0.609889, 12.8864, 8.77911, -90.1339, 50.1917, 197.483, 0, -90, -0, "door" );
	Horde:FindNodes( LevelMod, "door", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = door_scripted };
	door_posX = -90.1339;
	door_posY = 50.1917;
	door_posZ = 197.483;
	door_rotX = 0;
	door_rotY = -90;
	door_rotZ = -0;
end

