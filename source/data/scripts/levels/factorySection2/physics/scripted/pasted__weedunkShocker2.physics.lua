-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for pasted__weedunkShocker2.
function pasted__weedunkShocker2_OBJECT ()
	pasted__weedunkShocker2_scripted = ODE:CreateMovingBox( 0.55, 0.45, 0.4, -88.426, 44.0795, 189.818, 0, -178.574, -0, "weedunkShockerWest" );
	Horde:FindNodes( LevelMod, "pasted__weedunkShocker2", "Mesh" );
	nodeHandle = Horde:GetNodeFindResult(0);
	factorySection2_SCRIPTED = { next = factorySection2_SCRIPTED, node = nodeHandle, physics = pasted__weedunkShocker2_scripted };
	pasted__weedunkShocker2_posX = -88.426;
	pasted__weedunkShocker2_posY = 44.0795;
	pasted__weedunkShocker2_posZ = 189.818;
	pasted__weedunkShocker2_rotX = 0;
	pasted__weedunkShocker2_rotY = -178.574;
	pasted__weedunkShocker2_rotZ = -0;
end

