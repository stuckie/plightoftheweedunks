-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for conveyorBelt20.
function conveyorBelt20_OBJECT ()
	conveyorBelt20_scripted = ODE:CreateMovingBox( 37.3068, 0.2, 2.85299, -58.5802, 62.2098, 150.46, 0.15054, -44.9997, -0, "raisedConveyorForceNorthEast" );
	Horde:FindNodes( LevelMod, "conveyorBelt20", "Mesh" );
	conveyorBelt20 = Horde:GetNodeFindResult(0);
	conveyorBelt20_posX = -58.5802;
	conveyorBelt20_posY = 62.2098;
	conveyorBelt20_posZ = 150.46;
	conveyorBelt20_rotX = 0.15054;
	conveyorBelt20_rotY = -44.9997;
	conveyorBelt20_rotZ = -0;
end