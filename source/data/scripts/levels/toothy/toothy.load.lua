-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Load Level Data
dofile ("data/scripts/levels/toothy/toothy.spawners.lua");
dofile ("data/scripts/levels/toothy/toothy.waypoints.lua");
dofile("data/scripts/levels/toothy/toothy.unload.lua");
dofile ("data/scripts/levels/toothy/cameras/toothy.camera.lua");
dofile ("data/scripts/levels/toothy/lights/toothy.lights.lua");
dofile ("data/scripts/levels/toothy/physics/static/toothy.physics.static.lua");
dofile ("data/scripts/levels/toothy/physics/dynamic/toothy.physics.dynamic.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/teeth8.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/teeth9.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/teeth10.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/death3.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/death4.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/death5.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/teeth11.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/teeth12.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/teeth13.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/teeth14.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/death6.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/botLeftToothyDoor.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/topRightToothyDoor.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/botRightToothyDoor.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/topLeftToothyDoor.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/death2.physics.lua");
dofile ("data/scripts/levels/toothy/physics/scripted/death1.physics.lua");
dofile("data/scripts/gameplay/toothy/_setup.lua");


-- Call Function

function toothy_LOAD()
	toothy_CAMERAS();
	toothy_LIGHTS();
	toothy_STATIC_PHYSICS();
	toothy_DYNAMIC_PHYSICS();
	setWaypoints();
	createSpawners();
	teeth8_OBJECT();
	teeth9_OBJECT();
	teeth10_OBJECT();
	death3_OBJECT();
	death4_OBJECT();
	death5_OBJECT();
	teeth11_OBJECT();
	teeth12_OBJECT();
	teeth13_OBJECT();
	teeth14_OBJECT();
	death6_OBJECT();
	botLeftToothyDoor_OBJECT();
	topRightToothyDoor_OBJECT();
	botRightToothyDoor_OBJECT();
	topLeftToothyDoor_OBJECT();
	death2_OBJECT();
	death1_OBJECT();
	toothySetup();
end
