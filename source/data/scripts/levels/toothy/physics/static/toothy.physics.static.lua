-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for toothy.
function toothy_STATIC_PHYSICS()
	conveyorBelt2_static = ODE:CreateStaticBox( 6.39855, 1, 60, 0, -0.657499, -68.1376, 0, -0, -0, "conveyorBeltBoundary" );

	floor_static = ODE:CreateStaticBox( 16.0114, 1, 146.873, 0.022611, -1.29863, -41.9785, 0, -0, -0, "toothysFloor" );

	westStrut_static = ODE:CreateStaticBox( 0.914328, 10, 1.5, -4.54567, 4.16741, 2.1894, 0, -0, -0, "toothysWall" );

	westStrut1_static = ODE:CreateStaticBox( 1, 10, 1.5, -4.52796, 4.16741, -17.8106, 0, -0, -0, "toothysWall" );

	westStrut2_static = ODE:CreateStaticBox( 1, 10, 1.5, -4.528, 4.22388, -37.7895, 0, -0, -0, "toothysWall" );

	westStrut3_static = ODE:CreateStaticBox( 1, 10, 1.5, -4.52796, 4.16741, -57.8106, 0, -0, -0, "toothysWall" );

	westStrut4_static = ODE:CreateStaticBox( 1, 10, 1.5, -4.52796, 4.16741, -77.8106, 0, -0, -0, "toothysWall" );

	eastStrut4_static = ODE:CreateStaticBox( 1, 10, 1.5, 4.53105, 4.16741, -77.8106, 0, -0, -0, "toothysWall" );

	eastStrut3_static = ODE:CreateStaticBox( 1, 10, 1.5, 4.53105, 4.16741, -57.8106, 0, -0, -0, "toothysWall" );

	eastStrut2_static = ODE:CreateStaticBox( 1, 10, 1.5, 4.53105, 4.16741, -37.8106, 0, -0, -0, "toothysWall" );

	eastStrut1_static = ODE:CreateStaticBox( 1, 10, 1.5, 4.53105, 4.16741, -17.8106, 0, -0, -0, "toothysWall" );

	eastStrut_static = ODE:CreateStaticBox( 1, 10, 1.5, 4.53105, 4.16741, 2.1894, 0, -0, -0, "toothysWall" );

	wallWest_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.58065, 4.16741, -3.42066, 0, -9.99999, -0, "toothysWall" );

	wallWest1_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.57023, 4.16741, -12.2095, 0, 9.99999, -0, "toothysWall" );

	wallWest2_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.58065, 4.16741, -23.4207, 0, -9.99999, -0, "toothysWall" );

	wallWest3_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.57023, 4.16741, -32.2095, 0, 9.99999, -0, "toothysWall" );

	wallWest4_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.58065, 4.16741, -43.4207, 0, -9.99999, -0, "toothysWall" );

	wallWest5_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.57023, 4.16741, -52.2095, 0, 9.99999, -0, "toothysWall" );

	wallWest6_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.58065, 4.16741, -63.4207, 0, -9.99999, -0, "toothysWall" );

	wallWest7_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.57023, 4.16741, -72.2095, 0, 9.99999, -0, "toothysWall" );

	wallWest8_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.58065, 4.16741, -83.4207, 0, -9.99999, -0, "toothysWall" );

	wallWest9_static = ODE:CreateStaticBox( 0.626472, 10, 28.6476, -4.038, 4.16741, -100.899, 0, 9.99999, -0, "toothysWall" );

	lowerTeeth_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, -17.8143, 0, -0, -0, "toothysTeeth" );

	lowerTeeth2_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, -57.8143, 0, -0, -0, "toothysTeeth" );

	lowerTeeth3_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, -77.8143, 0, -0, -0, "toothysTeeth" );

	wallEnd_static = ODE:CreateStaticBox( 10, 5.85727, 1, 0, 6.23564, -114.238, 0, -0, -0, "toothysWall" );

	loadFactoryLevel_static = ODE:CreateStaticBox( 100, 11.0868, 100, 0, 4.33555, -150, 0, -0, -0, "loadFactoryLevel" );

	ceilingWest_static = ODE:CreateStaticBox( 0.499999, 9, 119.046, -3.08431, 10.7209, -28.4614, 0, -0, 45, "toothysWall" );

	ceilingEast_static = ODE:CreateStaticBox( 0.499999, 9, 119.041, 3.16941, 10.6949, -28.4637, 0, -0, -45, "toothysWall" );

	ceilingEastEnd_static = ODE:CreateStaticBox( 0.5, 9, 29.2825, 3.16941, 8.33257, -100.926, 9.11697, -0, -45, "toothysWall" );

	ceilingWestEnd_static = ODE:CreateStaticBox( 0.5, 9, 29.2825, -3.0531, 8.3352, -100.918, 9.11702, -7.72859e-005, 45.0002, "toothysWall" );

	wallEast9_static = ODE:CreateStaticBox( 0.626472, 10, 28.6653, 4.06011, 4.16741, -100.857, 0, 170, -0, "toothysWall" );

	wallEast8_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.58347, 4.16741, -83.3698, 0, -170, -0, "toothysWall" );

	wallEast7_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.59388, 4.16741, -72.1586, 0, 170, -0, "toothysWall" );

	wallEast6_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.58347, 4.16741, -63.3698, 0, -170, -0, "toothysWall" );

	wallEast5_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.59388, 4.16741, -52.1586, 0, 170, -0, "toothysWall" );

	wallEast4_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.58347, 4.16741, -43.3698, 0, -170, -0, "toothysWall" );

	wallEast3_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.59388, 4.16741, -32.1586, 0, 170, -0, "toothysWall" );

	wallEast2_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.58347, 4.16741, -23.3698, 0, -170, -0, "toothysWall" );

	wallEast1_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.59388, 4.16741, -12.1586, 0, 170, -0, "toothysWall" );

	wallEast_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.58347, 4.16741, -3.36976, 0, -170, -0, "toothysWall" );

	wallEast10_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.58347, 4.16741, 16.7189, 0, -170, -0, "toothysWall" );

	wallEast11_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.59388, 4.16741, 7.93, 0, 170, -0, "toothysWall" );

	wallWest10_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.58065, 4.16741, 16.8562, 0, -9.99999, -0, "toothysWall" );

	wallWest11_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.57023, 4.16741, 8.06736, 0, 9.99999, -0, "toothysWall" );

	westStrut6_static = ODE:CreateStaticBox( 0.914328, 10, 1.5, -4.54567, 4.16741, 22.4629, 0, -0, -0, "toothysWall" );

	eastStrut6_static = ODE:CreateStaticBox( 1, 10, 1.5, 4.53105, 4.16741, 22.4629, 0, -0, -0, "toothysWall" );

	wallWest12_static = ODE:CreateStaticBox( 0.626472, 10, 11, -5.57023, 4.16741, 28.6073, 0, 9.99999, -0, "toothysWall" );

	wallEast12_static = ODE:CreateStaticBox( 0.626472, 10, 11, 5.59388, 4.16741, 28.4699, 0, 170, -0, "toothysWall" );

	wallStart_static = ODE:CreateStaticBox( 15.847, 15.7226, 1, 0, 6.05951, 31.3459, 0, -0, -0, "toothysWall" );

	conveyorForce4_static = ODE:CreateStaticBox( 5.7745, 0.079408, 17.8, -2.1e-005, -0.121527, -27.8985, 0, -0, -0, "conveyorForceSouth" );

	conveyorForce5_static = ODE:CreateStaticBox( 5.77446, 0.079408, 17.8, 0, -0.121527, -47.8545, 0, -0, -0, "conveyorForceSouth" );

	conveyorForce6_static = ODE:CreateStaticBox( 5.77446, 0.079408, 17.8, 0, -0.121527, -67.8705, 0, -0, -0, "conveyorForceSouth" );

	conveyorForce7_static = ODE:CreateStaticBox( 5.77446, 0.079408, 17.8, 0, -0.121527, -87.861, 0, -0, -0, "conveyorForceSouth" );

	lowerStaticTeeth2_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, 2.19001, 0, -0, -0, "toothysTeeth" );

	lowerStaticTeeth1_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, 22.4519, 0, -0, -0, "toothysTeeth" );

	conveyorForce3_static = ODE:CreateStaticBox( 5.77446, 0.079408, 17.8, 0, -0.121527, -7.79848, 0, -0, -0, "conveyorForceSouth" );

	conveyorForce2_static = ODE:CreateStaticBox( 5.77446, 0.079408, 17.8, 0, -0.121527, 12.3015, 0, -0, -0, "conveyorForceSouth" );

	conveyorForce1_static = ODE:CreateStaticBox( 5.77446, 0.079408, 17.8, 0, -0.121527, 32.4015, 0, -0, -0, "conveyorForceSouth" );

	lowerTeeth4_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, -98.5654, 0, -0, -0, "toothysTeeth" );

	lowerTeeth6_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, -115.664, 0, -0, -0, "toothysTeeth" );

	certainKillBox_static = ODE:CreateStaticBox( 6.72603, 3.84872, 0.875194, 0, 1.63065, -115.85, 0, -0, -0, "death" );

	conveyorBelt1_static = ODE:CreateStaticBox( 6.3985, 1, 77, 2.4e-005, -0.657499, 1.13287, 0, -0, -0, "conveyorBeltBoundary" );

-- Lachlan added
	
	lowerTeeth7_static = ODE:CreateStaticBox( 9.22222, 0.809344, 1.2, 0, -0.567924, -37.7817, 0, -0, -0, "weedunkConverForce" );

	toothyZone1_static = ODE:CreateStaticBox( 10.2869, 14.6994, 28.6601, 0, 4.58689, 17.3965, 0, -0, -0, "respawnZone1" );

	toothyZone2_static = ODE:CreateStaticBox( 10.2869, 14.6994, 18.2557, 0, 4.58689, -8.04671, 0, -0, -0, "respawnZone2" );

	toothyZone3_static = ODE:CreateStaticBox( 10.2869, 14.6994, 18.2557, 0, 4.58689, -28.2483, 0, -0, -0, "respawnZone3" );

	toothyZone4_static = ODE:CreateStaticBox( 10.2869, 14.6994, 18.2557, 0, 4.58689, -48.3499, 0, -0, -0, "respawnZone4" );

	toothyZone5_static = ODE:CreateStaticBox( 10.2869, 14.6994, 18.2557, 0, 4.58689, -68.5361, 0, -0, -0, "respawnZone5" );

	toothyZone6_static = ODE:CreateStaticBox( 10.2869, 14.6994, 18.2557, 0, 4.58689, -88.9338, 0, -0, -0, "respawnZone6" );
end

