-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for pasted__weedunkShocker3.
function pasted__weedunkShocker3_OBJECT ()
	pasted__weedunkShocker3_scripted = ODE:CreateMovingBox( 0.55, 0.45, 0.4, -91.4011, 44.0652, 189.766, 0, -178.607, -0, "weedunkShockerEast" );
	Horde:FindNodes( LevelMod, "pasted__weedunkShocker3", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = pasted__weedunkShocker3_scripted };
	pasted__weedunkShocker3_posX = -91.4011;
	pasted__weedunkShocker3_posY = 44.0652;
	pasted__weedunkShocker3_posZ = 189.766;
	pasted__weedunkShocker3_rotX = 0;
	pasted__weedunkShocker3_rotY = -178.607;
	pasted__weedunkShocker3_rotZ = -0;
end

