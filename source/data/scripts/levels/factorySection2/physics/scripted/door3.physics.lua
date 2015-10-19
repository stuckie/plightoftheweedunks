-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for door3.
function door3_OBJECT ()
	door3_scripted = ODE:CreateMovingBox( 0.609889, 12.3542, 5.07389, -90.1429, 57.8844, 197.341, 90, -0, -90, "door" );
	Horde:FindNodes( LevelMod, "door3", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = door3_scripted };
	door3_posX = -90.1429;
	door3_posY = 57.8844;
	door3_posZ = 197.341;
	door3_rotX = 90;
	door3_rotY = -0;
	door3_rotZ = -90;
end

