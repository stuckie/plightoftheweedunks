-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for factorySection2.
function factorySection2_STATIC_PHYSICS()
	wall14_static = ODE:CreateStaticBox( 43.1807, 45.7505, 32.5276, -70.2099, 0.121393, 60.3807, 0, -45, -0, "wall" );

	floor101_static = ODE:CreateStaticBox( 20, 0.05, 47.8638, -66.0265, 36.6873, 66.0519, 0, 135, -0, "death" );

	floor102_static = ODE:CreateStaticBox( 20, 0.05, 47.8637, -65.9201, 36.6873, 65.9241, 0, -180, -0, "death" );

	floor100_static = ODE:CreateStaticBox( 20, 0.05, 47.8638, -65.9484, 36.6873, 65.8967, 0, -135, -0, "death" );

	floor99_static = ODE:CreateStaticBox( 20, 0.05, 47.8637, -65.9536, 36.6873, 66.0674, 0, -90, -0, "death" );

	floor98_static = ODE:CreateStaticBox( 31.39, 0.05, 31.7324, -66.005, 35.9092, 65.9297, 0, -45, -0, "death" );

	conveyorBelt6_static = ODE:CreateStaticBox( 16.3028, 0.2, 1.09797, -57.7304, 15.4871, 1.53201, 0, -0, -0, "conveyorForceEast" );

	conveyorTowerPipe4_static = ODE:CreateStaticBox( 1.8, 15.8255, 1.8, -66.2912, 30.3823, 41.8526, 0, -0, -0, "mulchPipe" );

	floor24_static = ODE:CreateStaticBox( 20, 0.85, 5.45004, -65.9636, 38.1297, 44.5991, 0, -0, -0, "floor" );

	floor25_static = ODE:CreateStaticBox( 19.9782, 0.85, 4.5, -81.4238, 38.1297, 50.508, 0, -45, -0, "floor" );

	floor23_static = ODE:CreateStaticBox( 19.5317, 0.85, 4.5, -50.6762, 38.1384, 50.6754, 0, 45, -0, "floor" );

	mulchPipe39_static = ODE:CreateStaticBox( 1.8, 41.6413, 1.8, -78.9808, 56.085, 82.0639, 0, -0, -0, "mulchPipe" );

	mulchPipe40_static = ODE:CreateStaticBox( 1.8, 41.6413, 1.8, -52.71, 56.085, 82.0639, 0, -0, -0, "mulchPipe" );

	wall29_static = ODE:CreateStaticBox( 20, 3.27764, 3.42723, -66.5448, 36.9169, 90.2912, 0, -180, -0, "wall" );

	floor104_static = ODE:CreateStaticBox( 200, 20, 308.982, -45.4861, -14.3165, 44.9899, 0, -0, -0, "death" );

	mulchPipe51_static = ODE:CreateStaticBox( 1.8, 11.5633, 1.8, -43.5519, 17.6966, 1.72266, 0, -0, -98.5364, "mulchPipe" );

	wall13_static = ODE:CreateStaticBox( 20.1651, 19.8728, 43.2781, -40.1089, 3.47469, 54.2058, 0, -0, -0, "wall" );

	wall12_static = ODE:CreateStaticBox( 47.7548, 19.8728, 74.546, -73.0625, 5.34304, 26.8857, 0, -0, -0, "wall" );

	wall5_static = ODE:CreateStaticBox( 24.3098, 26.4757, 48.9389, -28.1627, -11.6667, 1.7851, 0, -90, -0, "wall" );

	wall6_static = ODE:CreateStaticBox( 24.3098, 2, 43.3782, -31.6738, 2.52055, 1.7851, 0, -90, -0, "wall" );

	wall7_static = ODE:CreateStaticBox( 24.3098, 2, 37.6379, -35.2259, 4.45781, 1.7851, 0, -90, -0, "wall" );

	wall9_static = ODE:CreateStaticBox( 24.3098, 2, 37.6379, -48.1888, 8.43648, 1.7851, 0, -90, -0, "wall" );

	wall8_static = ODE:CreateStaticBox( 24.3098, 2, 37.6379, -41.6902, 6.45209, 1.7851, 0, -90, -0, "wall" );

	wall10_static = ODE:CreateStaticBox( 24.3098, 2, 37.6379, -54.6118, 10.4321, 1.7851, 0, -90, -0, "wall" );

	wall11_static = ODE:CreateStaticBox( 24.3098, 2, 37.6379, -61.0691, 12.4165, 1.7851, 0, -90, -0, "wall" );

	wall4_static = ODE:CreateStaticBox( 24.3098, 26.4757, 48.9389, -21.1253, -13.392, 1.7851, 0, -90, -0, "wall" );

	westWall4_static = ODE:CreateStaticBox( 12.2602, 64.8011, 18.7535, 43.0711, 14.5542, -6.43672, -45, -180, 90, "wall" );

	westWall5_static = ODE:CreateStaticBox( 12.2602, 64.7256, 18.7535, 43.0333, 14.5689, 9.72466, -45, -0, -90, "wall" );

	westWall2_static = ODE:CreateStaticBox( 23.4731, 127.89, 2, 11.6571, 59.0441, 1.53747, 0, -90, -0, "wall" );

	westWall3_static = ODE:CreateStaticBox( 30, 130.212, 208.033, 25.6839, 59.5145, 113.239, 0, -180, -0, "wall" );

	westWall1_static = ODE:CreateStaticBox( 30.0756, 130.54, 111.809, 25.7217, 59.4266, -61.4094, 0, -180, -0, "wall" );

	wall1_static = ODE:CreateStaticBox( 4, 65.6001, 0.85, 43.5393, -0.498287, -5.9286, -90, -0, -90, "wall" );

	wall3_static = ODE:CreateStaticBox( 4, 65.6001, 0.85, 43.5393, -0.498287, 9.41192, -90, -0, -90, "wall" );

	wall62_static = ODE:CreateStaticBox( 4, 17.4364, 0.85, 8.7285, -0.498287, 16.1299, -90, -0, 0, "wall" );

	wall2_static = ODE:CreateStaticBox( 4, 17.4364, 0.85, 8.7285, -0.498287, -12.6482, -90, -0, 0, "wall" );

	wall59_static = ODE:CreateStaticBox( 30, 63.7017, 21.8982, -3.02869, 27.1835, 187.954, 0, -180, -0, "wall" );

	EastWall_static = ODE:CreateStaticBox( 2, 129.253, 307.143, -145.854, 59.0351, 44.5183, 0, -180, -0, "wall" );

	wall61_static = ODE:CreateStaticBox( 15.0853, 63.7017, 41.9785, 3.60215, 23.4195, 144.381, 0, -180, -0, "wall" );

	wall60_static = ODE:CreateStaticBox( 15.0853, 63.7017, 14.0729, 3.60215, 25.4335, 171.823, 0, -180, -0, "wall" );

	floor3_static = ODE:CreateStaticBox( 4, 65.6001, 0.1, 43.5393, -0.053771, 9.41192, -90, -0, -90, "floor" );

	floor1_static = ODE:CreateStaticBox( 4, 65.6001, 0.1, 43.5393, -0.041952, -5.9286, -90, -0, -90, "floor" );

	wall32_static = ODE:CreateStaticBox( 6.91799, 5.72732, 2.86523, -42.2741, 53.3834, 134.081, 0, 45, -0, "wall" );

	wall30_static = ODE:CreateStaticBox( 40, 100, 40, -42.2596, 0.366917, 134.196, 0, -0, -0, "wall" );

	mulchPipe_static = ODE:CreateStaticBox( 2.99106, 2.72482, 7.27643, -43.804, 19.8701, 139.489, -90, -0, 45, "mulchPipe" );

	mulchPipe33_static = ODE:CreateStaticBox( 1.26689, 21.5819, 1.36673, -42.3912, 66.1293, 133.964, 0, -45, -0, "mulchPipe" );

	mulchPipe34_static = ODE:CreateStaticBox( 1.28265, 34.4808, 1.8, -53.8406, 75.998, 122.518, 0, -135, -90, "mulchPipe" );

	floor28_static = ODE:CreateStaticBox( 40, 0.1, 40, -42.2596, 50.4148, 134.196, 0, -0, -0, "wall" );

	deathMincer2_static = ODE:CreateStaticBox( 5.7417, 4.40198, 2.69533, -101.026, 42.6327, 134.349, 0, -180, -0, "deathMincer" );

	mulchPipe3_static = ODE:CreateStaticBox( 5.7235, 6.28547, 48.5742, -100.795, 17.119, 134.157, -90, -0, 90, "mulchPipe" );

	conveyorBelt31_static = ODE:CreateStaticBox( 17.5, 0.2, 1.13055, -42.4501, 50.4904, 146.254, 0, -90, -0, "conveyorForceNorthTurnOnable" );

	conveyorBelt30_static = ODE:CreateStaticBox( 54.4652, 0.2, 1.11771, -73.0842, 50.5592, 134.018, 0, -0, -0, "conveyorForceEastTurnOnable" );

	conveyorBelt21_static = ODE:CreateStaticBox( 25, 0.2, 1.19677, -53.5872, 50.5586, 122.912, 0, -135, -0, "conveyorForceSouthEast" );

	conveyorBelt23_static = ODE:CreateStaticBox( 17.6798, 0.2, 1.11081, -42.1308, 50.5571, 121.691, 0, -90, -0, "conveyorForceSouth" );

	conveyorBelt25_static = ODE:CreateStaticBox( 26.7836, 0.2, 1.16133, -31.128, 50.5625, 122.907, 0, -45, -0, "conveyorForceSouthWest" );

	conveyorBelt17_static = ODE:CreateStaticBox( 28.0546, 0.2, 1.15499, -30.8517, 50.5609, 145.712, 0, -135, -0, "conveyorForceNorthWest" );

	conveyorBelt28_static = ODE:CreateStaticBox( 19.077, 0.2, 1.17869, -30.4472, 50.5656, 134.104, 0, -0, -0, "conveyorForceWest" );

	wall33_static = ODE:CreateStaticBox( 6.918, 5.72732, 2.86522, -42.274, 53.3834, 134.081, 0, -0, -0, "wall" );

	wall34_static = ODE:CreateStaticBox( 6.91799, 5.72732, 2.86523, -42.2741, 53.3834, 134.081, 0, -45, -0, "wall" );

	wall31_static = ODE:CreateStaticBox( 6.918, 5.72732, 2.86522, -42.2744, 53.3834, 134.082, 0, 90, -0, "wall" );

	wall42_static = ODE:CreateStaticBox( 8.73664, 1, 9.60371, -99.7209, -1.98592, 182.009, 0, 45, -0, "wall" );

	wall48_static = ODE:CreateStaticBox( 5.63799, 6.73405, 7.20086, -73.4382, 41.3072, 188.092, 0, 45, -180, "wall" );

	northWall3_static = ODE:CreateStaticBox( 55.7272, 129.164, 51.6706, -120.304, 59.0642, 225.344, 0, -90, -0, "wall" );

	northWall1_static = ODE:CreateStaticBox( 55.6023, 129.164, 98.5175, -36.5932, 59.0642, 225.282, 0, -90, -0, "wall" );

	northWall2_static = ODE:CreateStaticBox( 55.9581, 64.0224, 8.91587, -90.1562, 91.6114, 225.46, 0, -90, -0, "wall" );

	wall44_static = ODE:CreateStaticBox( 5.59486, 10.3058, 30, -81.4769, 32.8585, 196.219, 0, 45, -0, "wall" );

	wall54_static = ODE:CreateStaticBox( 21.5446, 2, 12.2561, -54.2982, 50.2234, 192.668, 0, -0, -0, "wall" );

	wall56_static = ODE:CreateStaticBox( 8, 2, 10.4971, -47.5316, 54.2234, 196.584, 0, -0, -180, "wall" );

	wall57_static = ODE:CreateStaticBox( 6, 2, 10.4971, -46.5316, 56.2234, 198.297, 0, -0, -0, "wall" );

	wall58_static = ODE:CreateStaticBox( 4, 2, 10.4971, -45.5316, 58.2234, 199.899, 0, -0, -180, "wall" );

	wall55_static = ODE:CreateStaticBox( 10, 2, 10.4971, -48.5258, 52.2234, 194.741, 0, -0, -0, "wall" );

	mulchPipe38_static = ODE:CreateStaticBox( 1.8, 28.0632, 1.8, -65.8359, 76.0484, 82.0624, 0, -0, -90, "mulchPipe" );

	mulchPipe37_static = ODE:CreateStaticBox( 1.8, 29.8, 1.34178, -65.7846, 75.9968, 96.081, -90, -0, 0, "mulchPipe" );

	conveyorBelt37_static = ODE:CreateStaticBox( 32.188, 0.2, 1.1333, -66.4306, 15.4871, 17.0773, 0, 90, -0, "conveyorForceNorth" );

	mincer1_static = ODE:CreateStaticBox( 6.24383, 6.64301, 2.29342, -68.1781, 18.6441, 34.6648, 0, 90, -0, "mincer" );

	mincer3_static = ODE:CreateStaticBox( 4.4706, 2.72697, 2.69533, -66.4503, 20.5931, 33.7782, 0, 90, -0, "mincer" );

	mincer_static = ODE:CreateStaticBox( 6.24383, 6.63886, 2.15665, -64.5663, 18.6462, 34.6648, 0, 90, -0, "mincer" );

	deathMincer_static = ODE:CreateStaticBox( 2.84784, 5.07387, 2.69533, -66.4084, 17.9066, 34.0381, 0, 90, -0, "deathMincer" );

	wall18_static = ODE:CreateStaticBox( 9.97323, 2, 3, -91.8754, 16.2711, 55.8243, 0, -45, -0, "wall" );

	wall19_static = ODE:CreateStaticBox( 7.40184, 2, 3.86237, -92.4749, 18.2675, 57.0336, 0, -45, -0, "wall" );

	wall20_static = ODE:CreateStaticBox( 4.99999, 2, 3.86237, -93.3225, 20.2695, 57.8811, 0, -45, -0, "wall" );

	wall17_static = ODE:CreateStaticBox( 9.97323, 2, 3.91118, -58.0041, 16.2711, 39.5334, 0, -135, -0, "wall" );

	wall16_static = ODE:CreateStaticBox( 7.40184, 2, 3.86237, -57.112, 18.2675, 40.4501, 0, -135, -0, "wall" );

	wall15_static = ODE:CreateStaticBox( 23.0176, 8.21517, 3.86237, -49.8942, 17.1619, 47.6678, 0, -135, -0, "wall" );

	conveyorTower2_static = ODE:CreateStaticBox( 4.5, 6.47726, 2.02698, -44.4331, 53.6204, 152.087, 0, -90, -0, "conveyorTower" );

	conveyorTower3_static = ODE:CreateStaticBox( 4.5, 3.30357, 2.8802, -42.3425, 55.2038, 152.087, 0, -90, -0, "conveyorTower" );

	conveyorTower1_static = ODE:CreateStaticBox( 4.5, 6.47726, 1.95598, -40.2895, 53.6204, 152.087, 0, -90, -0, "conveyorTower" );

	death1_static = ODE:CreateStaticBox( 3.96656, 2.6, 2.39693, -42.3863, 52.2076, 152.41, 0, -90, -0, "deathTower" );

	mulchPipe46_static = ODE:CreateStaticBox( 1.8, 77.554, 1.8, -42.6605, 34.0271, 196.623, 0, -180, -180, "mulchPipe" );

	mulchPipe47_static = ODE:CreateStaticBox( 1.8, 38.2772, 1.8, -62.6991, 71.9041, 196.623, 0, -180, 90, "mulchPipe" );

	mulchPipe48_static = ODE:CreateStaticBox( 1.8, 4.49323, 1.4635, -81.1957, 71.9041, 193.477, 0, 90, 90, "mulchPipe" );

	mulchPipe49_static = ODE:CreateStaticBox( 1.8, 9.30239, 1.50705, -85.1168, 71.9041, 190.502, 0, -180, 90, "mulchPipe" );

	mulchPipe50_static = ODE:CreateStaticBox( 1.8, 10.207, 1.3933, -90.3992, 71.9041, 194.817, 0, -90, 90, "mulchPipe" );

	metalPlatform59_static = ODE:CreateStaticBox( 0.2, 0.2, 100, -33.4236, 112.05, 96.6051, -90, -0, 0, "wall" );

	metalPlatform58_static = ODE:CreateStaticBox( 0.2, 0.2, 100, -38.8675, 112.133, 96.5737, -90, -0, 0, "wall" );

	fanPlatform2_static = ODE:CreateStaticBox( 7.5, 7.5, 0.85, -36.3277, 55.903, 99.6655, -90, -0, 180, "wall" );

	fanPlatform1_static = ODE:CreateStaticBox( 7.5, 7.5, 0.85, -66.6349, 55.9281, 100.1, -90, -0, 90, "wall" );

	metalPlatform57_static = ODE:CreateStaticBox( 0.2, 0.2, 100, -69.6178, 112.05, 103.038, -90, -0, 0, "wall" );

	metalPlatform56_static = ODE:CreateStaticBox( 0.2, 0.2, 100, -69.6302, 112.05, 97.3246, -90, -0, 0, "wall" );

	wall21_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -65.9802, 16.7934, 41.8806, 0, -0, -0, "wall" );

	wall28_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -48.9799, 16.7934, 48.9224, 0, 45, -0, "wall" );

	wall22_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -82.9806, 16.7934, 48.9245, 0, -45, -0, "wall" );

	wall23_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -90.0224, 16.7934, 65.9228, 0, -90, -0, "wall" );

	wall27_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -41.9381, 16.7934, 65.9228, 0, 90, -0, "wall" );

	wall26_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -49.012, 16.7934, 82.9552, 0, 135, -0, "wall" );

	wall25_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -65.9802, 16.7934, 89.9649, 0, -180, -0, "wall" );

	wall24_static = ODE:CreateStaticBox( 20, 43.5401, 0.2, -82.9806, 16.7934, 82.9231, 0, -135, -0, "wall" );

	mulchPipe52_static = ODE:CreateStaticBox( 1.8, 15.7101, 1.8, -30.426, 17.1657, 1.72266, 0, -0, -79.7904, "mulchPipe" );

	mulchPipe53_static = ODE:CreateStaticBox( 1.8, 25.0116, 1.8, -10.4097, 16.8662, 1.72266, 0, -0, -94.6546, "mulchPipe" );

	mulchPipe54_static = ODE:CreateStaticBox( 1.8, 25.0115, 1.8, 13.9604, 17.0101, 1.72266, 0, -0, -86.2126, "mulchPipe" );

	mincer16_static = ODE:CreateStaticBox( 6.66432, 5.53182, 2.29763, -100.778, 42.2432, 131.98, 0, -180, -0, "mincer" );

	mincer17_static = ODE:CreateStaticBox( 1.74746, 5.28754, 2.29763, -98.3195, 42.3654, 134.074, 0, -180, -0, "mincer" );

	mincer18_static = ODE:CreateStaticBox( 6.66432, 5.53182, 2.29763, -100.778, 42.2432, 136.069, 0, -180, -0, "mincer" );

	mincer19_static = ODE:CreateStaticBox( 1.74746, 5.52192, 2.29763, -103.236, 42.2482, 134.074, 0, -180, -0, "mincer" );

	wall72_static = ODE:CreateStaticBox( 9.02067, 1.29191, 3.73609, -42.4588, 51.0072, 134.081, 0, -0, -0, "wall" );

	wall73_static = ODE:CreateStaticBox( 9.02067, 1.29191, 3.73608, -42.4589, 51.0072, 134.082, 0, 45, -0, "wall" );

	wall74_static = ODE:CreateStaticBox( 9.02067, 1.29191, 3.73609, -42.4592, 51.0072, 134.082, 0, 90, -0, "wall" );

	wall75_static = ODE:CreateStaticBox( 9.02067, 1.29191, 3.73608, -42.4589, 51.0072, 134.081, 0, -45, -0, "wall" );

	mulchPipe55_static = ODE:CreateStaticBox( 1.8, 1.8, 12.7639, -107.713, 28.045, 134.302, 0, -90, -0, "mulchPipe" );

	mulchPipe56_static = ODE:CreateStaticBox( 5.54175, 5.54176, 13.1635, -95.5471, 26.3934, 66.6502, -17.0058, -90, -0, "mulchPipe" );

	mulchPipe57_static = ODE:CreateStaticBox( 5.54175, 5.54176, 7.39208, -104.028, 27.4511, 66.6502, 12.4336, -90, -0, "mulchPipe" );

	mulchPipe58_static = ODE:CreateStaticBox( 5.54175, 5.54175, 7.39208, -25.9006, 17.8629, 66.6502, 6.87192, 90, -180, "mulchPipe" );

	mulchPipe59_static = ODE:CreateStaticBox( 5.54175, 4.88952, 6.30046, -39.2019, 17.9352, 66.6502, -0.47418, 90, -180, "mulchPipe" );

	mulchPipe60_static = ODE:CreateStaticBox( 5.54175, 5.54176, 4.96855, -20.203, 17.3499, 66.6502, 1.11883, 90, -180, "mulchPipe" );

	mulchPipe61_static = ODE:CreateStaticBox( 5.54175, 4.88952, 7.67035, -32.7594, 18.268, 66.6502, -5.21787, 90, -180, "mulchPipe" );

	pasted__wire61_static = ODE:CreateStaticBox( 0.849585, 0.15, 0.15, -92.1601, 44.088, 189.763, 0, 1.42566, -22.7603, "floor" );

	pasted__wire62_static = ODE:CreateStaticBox( 2.11487, 0.15, 0.15, -93.5272, 43.9193, 190.076, 0, -18.0311, -0, "floor" );

	pasted__wire63_static = ODE:CreateStaticBox( 2.11487, 0.15, 0.15, -95.5552, 43.9193, 190.376, 0, 1.74244, -0, "floor" );

	wall81_static = ODE:CreateStaticBox( 3.4686, 1.90665, 3.27901, -42.3473, 56.8115, 134.008, 0, -45, -0, "wall" );

	wall38_static = ODE:CreateStaticBox( 9.81582, 32, 8.78051, -104.593, 11.8891, 187.684, 0, 45, -0, "wall" );

	wall40_static = ODE:CreateStaticBox( 9.91536, 1, 9.00881, -80.6667, -1.99317, 182.234, 0, 45, -0, "wall" );

	wall46_static = ODE:CreateStaticBox( 19.0158, 15.9013, 19.0158, -90.1496, 34.9548, 187.688, 0, 45, -0, "wall" );

	floor60_static = ODE:CreateStaticBox( 7.91732, 5.76392, 10.6926, -83.3915, 40.9588, 188.535, 0, 45, -0, "floor" );

	wall43_static = ODE:CreateStaticBox( 17.152, 10.4204, 30, -94.7801, 25.7421, 182.905, 0, 45, -0, "wall" );

	wall49_static = ODE:CreateStaticBox( 14.2211, 1.44574, 10.4971, -76.0828, 43.9359, 192.788, 0, -0, -180, "wall" );

	wall53_static = ODE:CreateStaticBox( 3.50101, 0.85, 10.3584, -82.8693, 44.2359, 193.003, 0, 15.1937, -180, "wall" );

	wall52_static = ODE:CreateStaticBox( 7.09213, 0.85, 16.4221, -100.009, 44.3244, 190.56, 0, -15.194, -180, "wall" );

	wall51_static = ODE:CreateStaticBox( 13.8723, 0.85, 10.4971, -104.425, 44.3176, 192.793, 0, -180, -180, "wall" );

	wall50_static = ODE:CreateStaticBox( 13.0402, 0.85, 4.8218, -105.053, 44.3241, 184.618, 0, 135, -180, "wall" );

	wall41_static = ODE:CreateStaticBox( 18.4243, 1, 28.2528, -90.2132, -1.98592, 189.672, 0, -0, -0, "wall" );

	wall36_static = ODE:CreateStaticBox( 19.6163, 5.45086, 26.2476, -78.8065, 0.954324, 200.663, 0, -0, -0, "wall" );

	wall37_static = ODE:CreateStaticBox( 20.3849, 5.45086, 26.2476, -101.132, 0.954324, 200.663, 0, -0, -0, "wall" );

	wall45_static = ODE:CreateStaticBox( 5.54143, 14.0331, 30, -81.561, 23.9005, 196.338, 0, 45, -0, "wall" );

	wall35_static = ODE:CreateStaticBox( 42.303, 48.235, 65.6641, -90.2132, 19.7168, 220.371, 0, -0, -0, "wall" );

	wall47_static = ODE:CreateStaticBox( 16.9144, 5.76392, 30, -94.778, 40.9588, 182.913, 0, 45, -0, "wall" );

	wall39_static = ODE:CreateStaticBox( 7.18109, 29.8251, 18.4592, -78.1132, 10.4836, 191.589, 0, 45, -0, "wall" );

	pasted__wire38_static = ODE:CreateStaticBox( 2.11487, 0.15, 0.15, -86.2745, 43.9372, 189.508, 0, 161.969, -0, "floor" );

	pasted__wire37_static = ODE:CreateStaticBox( 2.11487, 0.15, 0.15, -84.2465, 43.9372, 189.208, 0, -178.258, -0, "floor" );

	pasted__wire39_static = ODE:CreateStaticBox( 0.671277, 0.15, 0.15, -89.9336, 43.9149, 189.79, 0, 179.967, -0, "floor" );

	pasted__wire60_static = ODE:CreateStaticBox( 0.849585, 0.15, 0.15, -90.6032, 44.0719, 189.776, 0, -178.607, -22.7603, "floor" );

	pasted__wire58_static = ODE:CreateStaticBox( 0.849585, 0.15, 0.15, -87.6416, 44.1059, 189.822, 0, -178.574, -22.7603, "floor" );

	pasted__wire57_static = ODE:CreateStaticBox( 0.849584, 0.15, 0.15, -89.2371, 44.0707, 189.797, 0, -178.574, 22.3498, "floor" );

	wall80_static = ODE:CreateStaticBox( 9.91536, 1, 9.00881, -99.702, -1.99317, 182.171, 0, 135, -0, "wall" );

	wall82_static = ODE:CreateStaticBox( 8.4605, 9.25461, 10.887, -79.2536, 25.1514, 184.927, 0, 45, -0, "wall" );

	respawn_1_static = ODE:CreateStaticBox( 61.8314, 36.9143, 36.9143, -18.5509, 0, -4.68652, 0, -0, -0, "respawn1" );

	respawn_2_static = ODE:CreateStaticBox( 50.5564, 36.9143, 68.0119, -75.3502, 12.7493, 11.0768, 0, -0, -0, "respawn2" );

	respawn_3_static = ODE:CreateStaticBox( 37, 16.3285, 59.5252, -71.5132, 45.486, 56.607, 0, -90, -0, "respawn3" );

	respawn_4_static = ODE:CreateStaticBox( 50.5564, 16.3285, 50.525, -44.3817, 45.486, 134.639, 0, -90, -0, "respawn4" );

	respawn_5_static = ODE:CreateStaticBox( 7.34074, 16.3285, 36.2776, -54.4303, 45.486, 93.8488, 0, -90, -0, "respawn5" );

	respawn_6_static = ODE:CreateStaticBox( 74.4434, 16.3285, 29.7535, -3.33388, 51.8038, 160.363, 0, -90, -0, "respawn6" );

	respawn_7_static = ODE:CreateStaticBox( 28.4731, 17.1833, 32.4849, -89.0893, 45.486, 187.446, 0, -45, -0, "respawn7" );

	respawn_8_static = ODE:CreateStaticBox( 50.5564, 16.3285, 37.5141, -46.8648, 51.9682, 211.504, 0, -90, -0, "respawn8" );
	
	drJunkheadScreenRight_static = ODE:CreateStaticBox( 2.39594, 1.29576, 1.38885, -56.0437, 15.593, 34.1194, 0, 53.8039, -17.9629, "wall" );

	drJunkheadScreenLeft_static = ODE:CreateStaticBox( 1.2951, 1.45062, 2.50038, -50.4947, 15.5687, 34.2253, 17.4607, 34.1921, -2.80296, "wall" );

	drJunkheadScreen_static = ODE:CreateStaticBox( 4.24237, 4.91149, 0.42, -53.0727, 17.2566, 35.7188, 0, -0, -0, "wall" );

	drJunkheadScreen1_static = ODE:CreateStaticBox( 0.622169, 5.71421, 0.5064, -52.2418, 19.7216, 35.6857, 0, -0, 69.5697, "wall" );

	drJunkheadScreen2_static = ODE:CreateStaticBox( 2.93784, 0.656677, 0.4956, -54.3666, 19.6287, 35.6937, 0, -0, 6.24484, "wall" );

	drJunkheadScreen3_static = ODE:CreateStaticBox( 0.501465, 4.60561, 0.4784, -50.7119, 18.6224, 35.6857, 0, -0, 21.6288, "wall" );

	drJunkheadScreenRight1_static = ODE:CreateStaticBox( 6.89279, 1.02693, 1.39891, -53.2699, 15.8521, 35.0679, 0, -0, -0, "wall" );

end

