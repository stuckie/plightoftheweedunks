-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for factorySection1.
function factorySection1_STATIC_PHYSICS()
	conveyorTower5_static = ODE:CreateStaticBox( 4.5, 2.6, 2.68023, -26.7077, 2.44175, 43.1623, 0, 90, -0, "conveyorTower" );

	conveyorTower4_static = ODE:CreateStaticBox( 4.5, 24, 1.08146, -28.1687, -8.25825, 43.1623, 0, 90, -0, "conveyorTower" );

	spikesInCanalWest_static = ODE:CreateStaticBox( 2.37703, 38.77, 24.7673, 0.602213, 11.4708, 34.8395, 0, 90, -0, "wall" );

	floorSpecialWeedunk_static = ODE:CreateStaticBox( 10, 20, 10, -140.142, -13.8158, 110.427, 0, 90, -0, "wall" );

	floor2_static = ODE:CreateStaticBox( 28.7525, 26.4757, 37.6379, -30.4885, -14.6928, 9.94264, 0, 90, -0, "wall" );

	floor3_static = ODE:CreateStaticBox( 13.0318, 21.8615, 30, -26.6735, -12.3857, 34.7597, 0, 90, -0, "wall" );

	floorblock_static = ODE:CreateStaticBox( 8.73246, 58.7205, 30, -26.9224, -31.2016, 49.891, 0, 90, -0, "wall" );

	floor4_static = ODE:CreateStaticBox( 12.062, 21.9846, 55.0558, 42.4563, -11.5907, 52.896, 0, 90, -0, "wall" );

	drJunkheadScreenRight_static = ODE:CreateStaticBox( 2.39594, 1.29576, 1.38885, -47.8239, -1.19193, 21.8389, 0, 53.8039, -17.9629, "wall" );

	drJunkheadScreenLeft_static = ODE:CreateStaticBox( 1.2951, 1.45062, 2.50038, -42.2749, -1.21627, 21.9448, 17.4607, 34.1921, -2.80296, "wall" );

	drJunkheadScreen_static = ODE:CreateStaticBox( 4.24237, 4.91149, 0.42, -44.8528, 0.471602, 23.4382, 0, -0, -0, "wall" );

	deathMincer1_static = ODE:CreateStaticBox( 3.49142, 5.07387, 2.69533, -5.11365, 0.211473, 4.07828, 0, -0, -0, "deathMincer" );

	brokenBridge_static = ODE:CreateStaticBox( 8.54417, 0.85, 5, -26.728, 3.44587, 104.009, 0, -90, -0, "wall" );

	floor14_static = ODE:CreateStaticBox( 44.1462, 58.7205, 84.8831, -46.4043, -31.1529, 142.348, 0, -90, -0, "wall" );

	risingWall6_static = ODE:CreateStaticBox( 19.9888, 6, 30, -66.6952, -2.89274, 163.877, 0, -180, -0, "floor" );

	risingWall7_static = ODE:CreateStaticBox( 11.7788, 4, 30, -66.8288, 0.012296, 163.877, 0, -180, -0, "floor" );

	hiddenStep8_static = ODE:CreateStaticBox( 9.97898, 2.25215, 17.9022, -26.4929, 13.0754, 165.921, 0, -180, -0, "wall" );

	northWall4_static = ODE:CreateStaticBox( 12.2602, 64.8011, 18.7535, -58.6271, 28.8432, 248.924, -45, -90, 90, "wall" );

	northWall5_static = ODE:CreateStaticBox( 12.2602, 64.7256, 18.7535, -74.7885, 28.8579, 248.886, -45, 90, -90, "wall" );

	northWall2_static = ODE:CreateStaticBox( 23.4731, 68.0631, 43.9671, -66.6013, 58.8782, 238.493, 0, -0, -0, "wall" );

	floor20_static = ODE:CreateStaticBox( 146.795, 64.662, 55.8614, 22.8721, -13.715, 227.395, -90, -0, 180, "wall" );

	floor21_static = ODE:CreateStaticBox( 146.795, 64.662, 55.8614, -157.413, -13.715, 228.08, -90, -0, 180, "wall" );

	floor17_static = ODE:CreateStaticBox( 119.286, 17.759, 55.8614, -91.1189, -13.715, 165.892, -90, -0, 180, "wall" );

	floor19_static = ODE:CreateStaticBox( 45.5744, 38.9922, 55.8614, 66.6703, -13.715, 176.509, -90, -0, 180, "wall" );

	floor18_static = ODE:CreateStaticBox( 53.0591, 40.6615, 55.8614, -197.126, -13.715, 177.225, -90, -0, 180, "wall" );

	northWall3_static = ODE:CreateStaticBox( 44.0161, 100, 108.034, -130.474, 42.6227, 238.545, 0, -90, -0, "wall" );

	northWall1_static = ODE:CreateStaticBox( 43.943, 100, 148.148, 16.9515, 42.6227, 238.508, 0, -90, -0, "wall" );

	westWall3_static = ODE:CreateStaticBox( 30, 100, 115.547, 100.819, 42.888, 162.274, 0, -0, -0, "wall" );

	westWall1_static = ODE:CreateStaticBox( 30, 100, 158.487, 100.819, 42.888, -4.89807, 0, -0, -0, "wall" );

	westWall2_static = ODE:CreateStaticBox( 1, 80.5092, 33.4194, 86.3189, 52.6334, 89.2189, 0, -0, -0, "wall" );

	westWall5_static = ODE:CreateStaticBox( 1, 11.6871, 24.5906, 86.3189, 16.2105, 100.323, -45, -0, -0, "wall" );

	westWall4_static = ODE:CreateStaticBox( 1, 11.6871, 24.5906, 86.3189, 16.2105, 77.8627, 45, -0, -0, "wall" );

	EastWall_static = ODE:CreateStaticBox( 30, 100, 302.009, -198.183, 42.888, 66.9348, 0, -0, -0, "wall" );

	EastWall68_static = ODE:CreateStaticBox( 7.51664, 65.6001, 0.85, -57.1462, 13.7907, 252.48, -90, -0, 180, "wall" );

	EastWall69_static = ODE:CreateStaticBox( 8.36936, 65.6001, 0.85, -77.0014, 13.7907, 252.48, -90, -0, 180, "wall" );

	floor16_static = ODE:CreateStaticBox( 7.58622, 25.5345, 120.099, -179.251, -16.4544, 166.629, 0, -0, -0, "wall" );

	EastStep1_static = ODE:CreateStaticBox( 7.58622, 2, 34.9324, -179.251, -2.71638, 140.92, 0, -0, -0, "wall" );

	EastStep2_static = ODE:CreateStaticBox( 7.58622, 2, 30.3094, -179.251, -0.751193, 142.64, 0, -0, -0, "wall" );

	EastStep3_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 1.23505, 145.004, 0, -0, -0, "wall" );

	EastStep4_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 3.23411, 149.593, 0, -0, -0, "wall" );

	EastStep5_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 5.24885, 153.716, 0, -0, -0, "wall" );

	EastStep8_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 11.2863, 166.582, 0, -0, -0, "wall" );

	EastStep7_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 9.27152, 162.421, 0, -0, -0, "wall" );

	EastStep6_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 7.27247, 157.868, 0, -0, -0, "wall" );

	deathPlane1_static = ODE:CreateStaticBox( 76.0279, 26.8463, 173.837, -62.7319, -1.65023, 212.837, 0, 90, -0, "death" );

	floor12_static = ODE:CreateStaticBox( 12, 6, 30, -26.9224, -2.89274, 114.282, 0, -90, -0, "wall" );

	floor11_static = ODE:CreateStaticBox( 8, 4, 30, -26.9224, 0.012296, 112.282, 0, -90, -0, "wall" );

	floor10_static = ODE:CreateStaticBox( 4, 2, 30, -26.9224, 2.87087, 110.282, 0, -90, -0, "wall" );

	conveyorTowerPipeNorth_static = ODE:CreateStaticBox( 14.5784, 2.70163, 1.96571, -26.6872, -5.63979, 129.632, 0, -90, 90, "conveyorForceEast" );

	conveyorTower6_static = ODE:CreateStaticBox( 3.78332, 24, 0.784479, -28.3172, -8.25825, 132.5, 0, -90, -0, "conveyorTower" );

	conveyorTower7_static = ODE:CreateStaticBox( 2.63904, 3.94305, 4.33682, -26.7263, 2.73613, 132.646, 0, -90, -0, "conveyorTower" );

	conveyorTower8_static = ODE:CreateStaticBox( 3.54213, 24, 0.784479, -25.1168, -8.25825, 132.62, 0, -90, -0, "conveyorTower" );

	conveyor3_static = ODE:CreateStaticBox( 8.32125, 0.2, 1.15, -26.591, -1.62194, 135.404, 0, 90, -0, "conveyorForceNorth" );

	conveyor4_static = ODE:CreateStaticBox( 41.8126, 0.2, 1.11721, -46.916, -1.62194, 139.848, 0, -0, -0, "conveyorForceEast" );

	conveyor5_static = ODE:CreateStaticBox( 8.75252, 0.2, 1.15, -67.0904, -1.62194, 143.684, 0, 90, -0, "conveyorForceNorth" );

	mulchPipe1_static = ODE:CreateStaticBox( 1.20631, 11.962, 1.23315, -67.4002, 11.6697, 156.317, 0, 90, -0, "mulchPipe" );

	mulchPipe_static = ODE:CreateStaticBox( 1.32761, 10.4597, 1.36133, -67.1723, 6.1102, 151.778, -0.0638475, 93.1548, -89.9196, "mulchPipe" );

	suckingMulchPipeSouth_static = ODE:CreateStaticBox( 1.52272, 6.65529, 1.35821, -66.8903, 3.05521, 147.217, 0, 90, -0, "mulchPipe" );

	conveyor9_static = ODE:CreateStaticBox( 51.5374, 0.2, 1.12924, -98.1766, 14.3374, 185.276, 0, 90, -0, "conveyorForceNorth" );

	conveyor7_static = ODE:CreateStaticBox( 51.512, 0.2, 1.11595, -36.3826, 14.332, 185.335, 0, 90, -0, "conveyorForceNorth" );

	conveyor6_static = ODE:CreateStaticBox( 30.4889, 0.2, 1.11133, -51.9003, 14.332, 160.081, 0, -0, -0, "conveyorForceWest" );

	conveyor8_static = ODE:CreateStaticBox( 30.6138, 0.2, 1.08518, -82.497, 14.3374, 160.078, 0, -0, -0, "conveyorForceEast" );

	blowingMulchPipe_static = ODE:CreateStaticBox( 1.24716, 3.65174, 1.30959, -67.4093, 18.2031, 157.58, 0, 90, -90, "mulchPipe" );

	conveyor1_static = ODE:CreateStaticBox( 18.8999, 0.2, 1.14271, -16.8052, -1.35617, 4.01058, 0, -0, -0, "conveyorForceEast" );

	floor1_static = ODE:CreateStaticBox( 12.8223, 26.4757, 14.4113, -1.29771, -14.6928, 1.5822, 0, 90, -0, "wall" );

	tunnelWall_static = ODE:CreateStaticBox( 90.892, 6.08894, 6.99119, 41.6494, 9.29465, 4.37433, 0, -0, -0, "wall" );

	conveyorTunnel1_static = ODE:CreateStaticBox( 4.5, 24, 1.06858, -28.1751, -8.25825, 26.2406, 0, 90, -0, "conveyorTower" );

	conveyorTower2_static = ODE:CreateStaticBox( 4.5, 24, 1.19298, -25.321, -8.25825, 43.1623, 0, 90, -0, "conveyorTower" );

	EastWall82_static = ODE:CreateStaticBox( 7.58622, 2, 34.9324, -179.251, -2.71638, 140.92, 0, -0, -0, "wall" );

	EastWall83_static = ODE:CreateStaticBox( 7.58622, 2, 30.3094, -179.251, -0.751193, 142.64, 0, -0, -0, "wall" );

	EastWall84_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 1.23505, 145.004, 0, -0, -0, "wall" );

	EastWall85_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 3.23411, 149.593, 0, -0, -0, "wall" );

	EastWall86_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 5.24885, 153.716, 0, -0, -0, "wall" );

	EastWall87_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 7.27247, 157.868, 0, -0, -0, "wall" );

	EastWall88_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 9.27152, 162.421, 0, -0, -0, "wall" );

	EastWall89_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, -179.251, 11.2863, 166.582, 0, -0, -0, "wall" );

	westStep1_static = ODE:CreateStaticBox( 7.58622, 2, 34.9324, 82.4605, -2.71638, 140.92, 0, -0, -0, "wall" );

	westStep2_static = ODE:CreateStaticBox( 7.58622, 2, 30.3094, 82.4605, -0.751193, 142.64, 0, -0, -0, "wall" );

	westStep3_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, 82.4605, 1.23505, 145.004, 0, -0, -0, "wall" );

	westStep4_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, 82.4605, 3.23411, 149.593, 0, -0, -0, "wall" );

	westStep5_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, 82.4605, 5.24885, 153.716, 0, -0, -0, "wall" );

	westStep6_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, 82.4605, 7.27247, 157.868, 0, -0, -0, "wall" );

	westStep7_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, 82.4605, 9.27152, 162.421, 0, -0, -0, "wall" );

	westStep8_static = ODE:CreateStaticBox( 7.58622, 2, 27.6658, 82.4605, 11.2863, 166.582, 0, -0, -0, "wall" );

	mulchPipe4_static = ODE:CreateStaticBox( 1.8, 23.5, 1.8, -97.9863, 27.4235, 210.683, 0, 90, -0, "mulchPipe" );

	mulchPipe5_static = ODE:CreateStaticBox( 1.8, 23.5, 1.8, -36.6507, 27.4401, 210.683, 0, 90, -0, "mulchPipe" );

	mulchPipe6_static = ODE:CreateStaticBox( 1.8, 59.9592, 1.8, -67.2887, 38.2735, 210.683, -90, -0, -90, "mulchPipe" );

	mulchPipe7_static = ODE:CreateStaticBox( 1.8, 6.85317, 1.8, -67.2466, 38.2735, 213.252, 0, 90, 90, "mulchPipe" );

	toxicDeath1_static = ODE:CreateStaticBox( 135.843, 0.8, 221.022, -63.4036, 12.1021, 226.747, 0, 90, -0, "toxicDeath" );

	spikesInCanalEast_static = ODE:CreateStaticBox( 2.13513, 39.4114, 24.2377, -55.2209, 11.7915, 34.5973, 0, 90, -0, "wall" );

	conveyorTowerPipeSouth_static = ODE:CreateStaticBox( 14.5784, 1.84837, 1.96571, -26.7468, -6.05428, 46.0984, 0, 90, 90, "wall" );

	deathPlane_static = ODE:CreateStaticBox( 520.105, 41.1595, 517.533, -59.3952, -26.6912, 48.1115, 0, 90, -0, "death" );

	toxicDeath_static = ODE:CreateStaticBox( 449.425, 0.8, 492.737, -70.4143, -5.74545, 41.2783, 0, 90, -0, "toxicDeath" );

	conveyor2_static = ODE:CreateStaticBox( 38.4177, 0.2, 1.14424, -26.7352, -1.35617, 22.7194, 0, 90, -0, "conveyorForceNorth" );

	conveyorTunnel2_static = ODE:CreateStaticBox( 4.5, 24, 1.11446, -25.3187, -8.25825, 26.2406, 0, 90, -0, "conveyorTower" );

	conveyorTunnel3_static = ODE:CreateStaticBox( 4.5, 2.6, 2.62181, -26.7272, 2.44175, 26.2406, 0, 90, -0, "conveyorTower" );

	floor27_static = ODE:CreateStaticBox( 11.3174, 17, 13.1292, 38.2437, -10.7842, 64.3485, 0, 90, -0, "wall" );

	floor28_static = ODE:CreateStaticBox( 5.57161, 17, 13.1292, 38.2437, -12.2899, 72.793, 0, 90, -0, "wall" );

	floor29_static = ODE:CreateStaticBox( 50.7094, 17, 30.3679, 71.7434, -12.2899, 133.853, 0, 90, -0, "wall" );

	risingWall10_static = ODE:CreateStaticBox( 11.7788, 4, 30, -66.8288, 0.012296, 163.877, 0, -180, -0, "floor" );

	wire69_static = ODE:CreateStaticBox( 1.65632, 0.15, 0.15, -49.5177, 14.383, 214.269, 0, 102.513, -0, "floor" );

	wire70_static = ODE:CreateStaticBox( 1.32955, 0.15, 0.149999, -49.0732, 14.383, 212.867, 0, 113.94, -0, "floor" );

	wire71_static = ODE:CreateStaticBox( 1.32955, 0.15, 0.15, -48.3273, 14.383, 211.841, 0, 138.065, -0, "floor" );

	wire72_static = ODE:CreateStaticBox( 0.956576, 0.15, 0.15, -47.4021, 14.383, 211.283, 0, 164.309, -0, "floor" );

	wire73_static = ODE:CreateStaticBox( 0.849584, 0.15, 0.15, -46.6373, 14.533, 211.167, 0, -178.574, 22.3498, "floor" );

	weedunkShockPlate6_static = ODE:CreateStaticBox( 0.149204, 0.285015, 0.4, -46.2108, 14.7053, 211.179, 0, -178.574, -0, "weedunkShocker" );

	weedunkShocker4_static = ODE:CreateStaticBox( 0.203138, 0.166204, 0.147737, -45.8468, 14.5333, 211.195, 0, -178.575, -0, "weedunkShockerWest" );

	weedunkShockPlate7_static = ODE:CreateStaticBox( 0.149204, 0.285015, 0.4, -45.484, 14.7053, 211.204, 0, -178.574, -0, "weedunkShocker" );

	wire74_static = ODE:CreateStaticBox( 0.849585, 0.15, 0.15, -45.0489, 14.5401, 211.205, 0, -178.574, -22.7603, "floor" );

	wire75_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -44.2167, 14.383, 211.327, 0, -167.929, -0, "floor" );

	wire76_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -43.35, 14.383, 211.774, 0, -137.51, -0, "floor" );

	wire77_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -42.7106, 14.383, 212.565, 0, -120.395, -0, "floor" );

	wire78_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -42.2696, 14.383, 213.5, 0, -110.111, -0, "floor" );

	wire79_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -41.7638, 14.383, 214.407, 0, -128.281, -0, "floor" );

	wire80_static = ODE:CreateStaticBox( 1.44909, 0.15, 0.15, -40.8639, 14.3894, 215.273, -0.648986, -141.917, 0.484154, "floor" );

	wire81_static = ODE:CreateStaticBox( 1.65633, 0.15, 0.15, -49.7127, 14.383, 215.891, 0, 91.2029, -0, "floor" );

	wire82_static = ODE:CreateStaticBox( 1.98479, 0.15, 0.15, -39.4518, 14.3842, 216.178, -1.16204, -151.601, -0.0627129, "floor" );

	weedunkShockPlate5_static = ODE:CreateStaticBox( 0.149204, 0.285015, 0.4, -91.7654, 14.7053, 211.18, 0, -178.574, -0, "weedunkShocker" );

	wire60_static = ODE:CreateStaticBox( 0.849585, 0.15, 0.15, -90.6034, 14.5401, 211.206, 0, -178.574, -22.7603, "floor" );

	wire40_static = ODE:CreateStaticBox( 0.956576, 0.15, 0.15, -92.9567, 14.383, 211.284, 0, 164.309, -0, "floor" );

	wire39_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -89.7712, 14.383, 211.328, 0, -167.929, -0, "floor" );

	wire59_static = ODE:CreateStaticBox( 0.849584, 0.15, 0.15, -92.1918, 14.533, 211.167, 0, -178.574, 22.3498, "floor" );

	weedunkShocker3_static = ODE:CreateStaticBox( 0.23997, 0.19634, 0.174524, -91.4013, 14.5333, 211.195, 0, -178.574, -0, "weedunkShockerEast" );

	weedunkShockPlate4_static = ODE:CreateStaticBox( 0.149204, 0.285015, 0.4, -91.0386, 14.7053, 211.204, 0, -178.574, -0, "weedunkShocker" );

	wire61_static = ODE:CreateStaticBox( 1.32955, 0.15, 0.15, -93.8818, 14.383, 211.841, 0, 138.065, -0, "floor" );

	wire62_static = ODE:CreateStaticBox( 1.32955, 0.15, 0.149999, -94.6277, 14.383, 212.868, 0, 113.94, -0, "floor" );

	wire63_static = ODE:CreateStaticBox( 4.02872, 0.15, 0.15, -95.3292, 14.383, 215.428, 0, 102.513, -0, "floor" );

	wire64_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -88.9046, 14.383, 211.775, 0, -137.51, -0, "floor" );

	wire65_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -88.2651, 14.383, 212.566, 0, -120.395, -0, "floor" );

	wire66_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -87.8242, 14.383, 213.5, 0, -110.111, -0, "floor" );

	wire67_static = ODE:CreateStaticBox( 1.05123, 0.15, 0.15, -87.5734, 14.383, 214.479, 0, -99.3787, -0, "floor" );

	wire68_static = ODE:CreateStaticBox( 2.47874, 0.15, 0.15, -87.492, 14.383, 216.165, 0, -89.6723, -0, "floor" );

	mincer8_static = ODE:CreateStaticBox( 6.62722, 5.53182, 2.75993, -5.15455, 1.15733, 6.41445, 0, -0, -0, "mincer" );

	mincer11_static = ODE:CreateStaticBox( 1.73773, 5.52192, 2.75993, -2.70981, 1.16228, 3.89979, 0, -0, -0, "mincer" );

	mincer9_static = ODE:CreateStaticBox( 1.73773, 2.72697, 2.75993, -7.59929, 2.55976, 3.89979, 0, -0, -0, "mincer" );

	mincer10_static = ODE:CreateStaticBox( 6.62722, 5.53182, 2.75993, -5.15455, 1.15733, 1.50249, 0, -0, -0, "mincer" );

	toothyWallBracket_static = ODE:CreateStaticBox( 13.6581, 13.4906, 12.4729, 86.6458, 9.29465, 3.99891, 0, -0, -0, "wall" );

	drJunkheadScreen1_static = ODE:CreateStaticBox( 0.622169, 5.71421, 0.5064, -44.022, 2.93665, 23.4052, 0, -0, 69.5697, "wall" );

	drJunkheadScreen2_static = ODE:CreateStaticBox( 2.93784, 0.656677, 0.4956, -46.1468, 2.84371, 23.4132, 0, -0, 6.24484, "wall" );

	drJunkheadScreen3_static = ODE:CreateStaticBox( 0.501465, 4.60561, 0.4784, -42.492, 1.83746, 23.4052, 0, -0, 21.6288, "wall" );

	drJunkheadScreenRight1_static = ODE:CreateStaticBox( 6.89279, 1.02693, 1.39891, -45.0501, -0.932853, 22.7873, 0, -0, -0, "wall" );

	floor30_static = ODE:CreateStaticBox( 45.44, 17.7992, 55.8614, 1.26757, -13.715, 165.912, -90, -0, 180, "wall" );

	oldMulchPipeEast1_static = ODE:CreateStaticBox( 1.8, 3.92476, 1.8, -32.6351, -0.386958, 157.093, -90, -0, 0, "mulchPipe" );

	oldMulchPipeWest1_static = ODE:CreateStaticBox( 1.8, 3.92476, 1.8, -20.5068, -0.386958, 157.093, -90, -0, 0, "mulchPipe" );

	EndLevelTrigger_static = ODE:CreateStaticBox( 29.5828, 20.7086, 32.6277, -67.6496, 22.1385, 235.928, 0, -0, -0, "endOfLevelFactory1" );

	toothyPost1_static = ODE:CreateStaticBox( 0.900417, 11.3224, 0.97712, 19.5071, 0.205305, 3.98766, 0, 90, -0, "wall" );

	toothyPost_static = ODE:CreateStaticBox( 0.900417, 11.3224, 0.97712, 60.0921, 0.205305, 3.98766, 0, 90, -0, "wall" );

	toothyPost2_static = ODE:CreateStaticBox( 9.51409, 4.06432, 5.37134, 19.5071, 6.66907, 4.12542, 0, 90, -0, "wall" );

	toothyPost3_static = ODE:CreateStaticBox( 9.51409, 4.06432, 5.37134, 60.0374, 6.66907, 4.12542, 0, 90, -0, "wall" );

	toothyPost4_static = ODE:CreateStaticBox( 1.43225, 0.611795, 0.808601, -36.3804, 13.9921, 193.32, 0, -0, -0, "postsInCanal" );

	toothyPost5_static = ODE:CreateStaticBox( 0.118098, 1.48503, 0.128158, -36.3399, 13.0614, 193.305, 0, -0, -0, "postsInCanal" );

	toothyPost6_static = ODE:CreateStaticBox( 1.43225, 0.611795, 0.808601, -36.3804, 13.9921, 181.05, 0, -0, -0, "postsInCanal" );

	toothyPost7_static = ODE:CreateStaticBox( 0.118098, 1.48503, 0.128158, -36.3399, 13.0614, 181.036, 0, -0, -0, "postsInCanal" );

	conveyorTower9_static = ODE:CreateStaticBox( 4.7282, 2.08395, 6.19752, -26.7263, 3.58413, 132.646, 0, -90, -0, "conveyorTower" );

	conveyorTower10_static = ODE:CreateStaticBox( 4.99798, 2.00043, 5.94913, -26.7263, 3.81373, 26.1698, 0, -90, -0, "conveyorTower" );

	conveyorTower11_static = ODE:CreateStaticBox( 4.95968, 1.86408, 5.54364, -26.7263, 4.00979, 43.4144, 0, -90, -0, "conveyorTower" );

	conveyorTower12_static = ODE:CreateStaticBox( 3.05842, 3.94305, 3.82428, -26.7263, 3.08765, 43.5352, 0, -90, -0, "conveyorTower" );

	conveyorTower13_static = ODE:CreateStaticBox( 3.05842, 3.94305, 3.82428, -26.7263, 3.05976, 26.3235, 0, -90, -0, "conveyorTower" );

	toothyPost8_static = ODE:CreateStaticBox( 1.43225, 0.611795, 0.808601, -98.1632, 13.9921, 181.05, 0, -0, -0, "postsInCanal" );

	toothyPost9_static = ODE:CreateStaticBox( 0.118098, 1.48503, 0.128158, -98.1228, 13.0614, 181.036, 0, -0, -0, "postsInCanal" );

	toothyPost10_static = ODE:CreateStaticBox( 1.43225, 0.611795, 0.808601, -98.1632, 13.9921, 193.32, 0, -0, -0, "postsInCanal" );

	toothyPost11_static = ODE:CreateStaticBox( 0.118098, 1.48503, 0.128158, -98.1228, 13.0614, 193.305, 0, -0, -0, "postsInCanal" );

	pierBrokenBridgePiece1_static = ODE:CreateStaticBox( 8, 1, 6, -54.6363, 13.7163, 198.073, 0, -0, -0, "wall" );

	pierBrokenBridgePiece_static = ODE:CreateStaticBox( 8, 1, 6, -79.9986, 13.7163, 198.187, 0, -0, -0, "wall" );

	floor31_static = ODE:CreateStaticBox( 3.39622, 18.6077, 58.2749, -33.174, -14.5677, 165.892, -90, -0, 180, "wall" );

	floor32_static = ODE:CreateStaticBox( 3.39622, 18.6077, 58.2749, -19.9885, -14.5677, 165.892, -90, -0, 180, "wall" );

	mulchPipe8_static = ODE:CreateStaticBox( 3.23758, 0.130623, 0.201032, -67.367, 3.54535, 154.815, 0, 90, -90, "wall" );

	mulchPipe9_static = ODE:CreateStaticBox( 3.23758, 0.130623, 0.201032, -67.0218, 3.54535, 149.163, 0, 90, -90, "wall" );

	blowingMulchPipe1_static = ODE:CreateStaticBox( 1.24716, 1.30354, 1.30959, -67.4093, 17.8786, 159.245, 0, 90, 147.759, "mulchPipe" );

	arch_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -53.0005, 14.9891, 215.587, 0, -0, -0, "wall" );

	arch1_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -53.5489, 20.5307, 215.587, 0, -0, -10.0299, "wall" );

	arch2_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -55.2729, 25.4482, 215.587, 0, -0, -27.5146, "wall" );

	arch3_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -58.3295, 29.2763, 215.587, 0, -0, -49.2094, "wall" );

	arch4_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -62.6636, 31.8202, 215.587, 0, -0, -71.0635, "wall" );

	arch5_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -71.9538, 31.6663, 215.587, 0, -0, -108.519, "wall" );

	arch6_static = ODE:CreateStaticBox( 4.76217, 5.87972, 1.99676, -76.0994, 29.3079, 215.587, 0, -0, -130.925, "wall" );

	arch7_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -79.0784, 25.4647, 215.587, 0, -0, -153.651, "wall" );

	arch8_static = ODE:CreateStaticBox( 4.76216, 5.87971, 1.99676, -80.8595, 20.5088, 215.587, 0, -0, -167.807, "wall" );

	arch9_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, -81.5157, 15.1992, 215.587, 0, -0, -177.693, "wall" );

	arch10_static = ODE:CreateStaticBox( 4.76216, 5.87971, 1.99676, -67.1976, 32.6119, 215.587, 0, -0, -89.1791, "wall" );

	arch11_static = ODE:CreateStaticBox( 4.82128, 5.9527, 2.02155, -183.186, -2.82766, 103.92, 0, -90, -177.693, "wall" );

	arch12_static = ODE:CreateStaticBox( 4.82128, 5.9527, 2.02155, -183.186, 2.54783, 103.256, 0, -90, -167.807, "wall" );

	arch13_static = ODE:CreateStaticBox( 4.82127, 5.9527, 2.02155, -183.186, 7.56528, 101.453, 0, -90, -153.651, "wall" );

	arch14_static = ODE:CreateStaticBox( 4.82127, 5.9527, 2.02155, -183.186, 11.4562, 98.4366, 0, -90, -130.925, "wall" );

	arch15_static = ODE:CreateStaticBox( 4.82127, 5.9527, 2.02155, -183.186, 13.8439, 94.2396, 0, -90, -108.519, "wall" );

	arch16_static = ODE:CreateStaticBox( 4.82127, 5.9527, 2.02155, -183.186, 14.8012, 89.4243, 0, -90, -89.1791, "wall" );

	arch17_static = ODE:CreateStaticBox( 4.82128, 5.9527, 2.02155, -183.186, 13.9996, 84.8341, 0, -90, -71.0634, "wall" );

	arch18_static = ODE:CreateStaticBox( 4.82128, 5.9527, 2.02155, -183.186, 11.4242, 80.4462, 0, -90, -49.2094, "wall" );

	arch19_static = ODE:CreateStaticBox( 4.82128, 5.9527, 2.02155, -183.186, 7.5486, 77.3516, 0, -90, -27.5145, "wall" );

	arch20_static = ODE:CreateStaticBox( 4.82127, 5.9527, 2.02155, -183.186, 2.57002, 75.6062, 0, -90, -10.0299, "wall" );

	arch21_static = ODE:CreateStaticBox( 4.82127, 5.9527, 2.02155, -183.186, -3.04034, 75.051, 0, -90, -0, "wall" );

	arch22_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, -2.97508, 103.744, 0, -90, -177.693, "wall" );

	arch23_static = ODE:CreateStaticBox( 4.76216, 5.87971, 1.99676, 85.7859, 2.33449, 103.088, 0, -90, -167.807, "wall" );

	arch24_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, 7.29043, 101.307, 0, -90, -153.651, "wall" );

	arch25_static = ODE:CreateStaticBox( 4.76217, 5.87972, 1.99676, 85.7859, 11.1337, 98.3276, 0, -90, -130.925, "wall" );

	arch26_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, 13.492, 94.1821, 0, -90, -108.519, "wall" );

	arch27_static = ODE:CreateStaticBox( 4.76216, 5.87971, 1.99676, 85.7859, 14.4376, 89.4258, 0, -90, -89.1791, "wall" );

	arch28_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, 13.6459, 84.8919, 0, -90, -71.0635, "wall" );

	arch29_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, 11.1021, 80.5578, 0, -90, -49.2094, "wall" );

	arch30_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, 7.27395, 77.5011, 0, -90, -27.5146, "wall" );

	arch31_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, 2.35641, 75.7771, 0, -90, -10.0299, "wall" );

	arch32_static = ODE:CreateStaticBox( 4.76216, 5.87972, 1.99676, 85.7859, -3.18516, 75.2287, 0, -90, -0, "wall" );

	arch33_static = ODE:CreateStaticBox( 15.6333, 4.02156, 0.563331, -91.5304, 16.24, 216.295, 0, -0, -0, "wall" );

	arch34_static = ODE:CreateStaticBox( 15.6333, 4.02156, 0.563331, -43.2616, 16.24, 216.295, 0, -0, -0, "wall" );

	arch35_static = ODE:CreateStaticBox( 15.6333, 5.82891, 0.563331, -67.244, 39.1911, 216.295, 0, -0, -90, "wall" );

	arch36_static = ODE:CreateStaticBox( 15.6333, 5.63019, 0.563331, -85.541, 33.5286, 216.295, 0, -0, -141.587, "wall" );

	arch37_static = ODE:CreateStaticBox( 15.6333, 5.63019, 0.563331, -49.1547, 33.5519, 216.295, 0, -0, 141.146, "wall" );

	arch43_static = ODE:CreateStaticBox( 15.6333, 11.0412, 0.563331, -109.406, 19.7498, 216.295, 0, -0, -0, "wall" );

	arch44_static = ODE:CreateStaticBox( 15.6333, 11.0412, 0.563331, -161.283, 19.7498, 216.295, 0, -0, -0, "wall" );

	arch45_static = ODE:CreateStaticBox( 15.6333, 11.0412, 0.563331, 8.36585, 19.7498, 216.295, 0, -0, -0, "wall" );

	arch46_static = ODE:CreateStaticBox( 15.6333, 11.0412, 0.563331, 59.2453, 19.7498, 216.295, 0, -0, -0, "wall" );

	arch47_static = ODE:CreateStaticBox( 15.6333, 15.7142, 1.93937, 8.40225, 39.7148, 215.607, 0, -0, -0, "wall" );

	arch48_static = ODE:CreateStaticBox( 15.6333, 15.7142, 1.93937, 59.2453, 39.7148, 215.607, 0, -0, -0, "wall" );

	arch49_static = ODE:CreateStaticBox( 15.6333, 15.7142, 1.93937, -109.539, 39.7148, 215.607, 0, -0, -0, "wall" );

	arch50_static = ODE:CreateStaticBox( 15.6333, 15.7142, 1.93937, -161.257, 39.7148, 215.607, 0, -0, -0, "wall" );

	endWall_static = ODE:CreateStaticBox( 29.5828, 20.7086, 32.6277, -67.6496, 22.1385, 268.273, 0, -0, -0, "wall" );

	suctionForceEast_static = ODE:CreateStaticBox( 1.09114, 1.7045, 1.09114, -98.0879, 15.1679, 210.683, 0, 90, -0, "mulchPipe" );

	suctionForceEast1_static = ODE:CreateStaticBox( 1.09114, 1.7045, 1.09114, -36.4956, 15.1679, 210.683, 0, 90, -0, "mulchPipe" );

	deathPlane2_static = ODE:CreateStaticBox( 86.9828, 26.8463, 22.633, -160.257, -1.65023, 202.309, 0, 90, -0, "death" );

	deathPlane3_static = ODE:CreateStaticBox( 98.7397, 26.8463, 22.633, 34.6446, -1.65023, 208.188, 0, 90, -0, "death" );

	mulchPipe10_static = ODE:CreateStaticBox( 3.23758, 0.130623, 0.201032, -67.367, 16.3028, 157.781, 0, 90, -90, "wall" );

	zone1_static = ODE:CreateStaticBox( 55.6712, 20.5346, 29.7572, -21.7708, 0, 9.74894, 0, -0, -0, "zone1" );

	zone2_static = ODE:CreateStaticBox( 33.9383, 16.1093, 18.1406, -27.534, 2.44612, 44.8217, 0, -0, -0, "zone2" );

	zone3_static = ODE:CreateStaticBox( 55.4989, 16.1093, 29.2295, 41.9015, 2.44612, 61.3154, 0, -0, -0, "zone3" );

	zone4_static = ODE:CreateStaticBox( 44.6137, 16.1093, 56.815, -22.6572, 2.44612, 127.852, 0, -0, -0, "zone4" );

	zone5_static = ODE:CreateStaticBox( 44.6137, 16.1093, 39.3801, -68.263, 2.44612, 135.929, 0, -0, -0, "zone5" );

	zone6_static = ODE:CreateStaticBox( 64.4298, 11.8114, 22.7032, -4.51588, 17.7428, 168.617, 0, -0, -0, "zone6" );

	zone7_static = ODE:CreateStaticBox( 64.4298, 11.8114, 22.7032, -69.1986, 17.7428, 168.617, 0, -0, -0, "zone7" );

	zone8_static = ODE:CreateStaticBox( 49.5582, 11.8114, 22.7032, -126.475, 17.7428, 168.617, 0, -0, -0, "zone8" );

	zone9_static = ODE:CreateStaticBox( 63.0205, 11.8114, 22.7032, -106.899, 17.7428, 205.669, 0, -0, -0, "zone9" );

	zone10_static = ODE:CreateStaticBox( 63.0205, 11.8114, 22.7032, -27.873, 17.7428, 205.669, 0, -0, -0, "zone10" );

	zone11_static = ODE:CreateStaticBox( 31.5118, 11.8114, 33.7437, -167.867, 17.7428, 205.669, 0, -0, -0, "zone11" );

	zone12_static = ODE:CreateStaticBox( 19.5668, 29.8515, 40.8446, -175.552, 8.23502, 128.276, 0, -0, -0, "zone12" );

	zone13_static = ODE:CreateStaticBox( 31.6184, 29.8515, 40.8446, 71.1299, 8.23502, 128.276, 0, -0, -0, "zone13" );

	zone14_static = ODE:CreateStaticBox( 44.254, 29.8515, 48.0029, 64.2384, 8.23502, 194.006, 0, -0, -0, "zone14" );

end

