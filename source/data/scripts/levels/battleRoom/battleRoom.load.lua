-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Load Level Data
dofile ("data/scripts/levels/battleRoom/battleRoom.spawners.lua");
dofile ("data/scripts/levels/battleRoom/battleRoom.targets.lua");
dofile ("data/scripts/levels/battleRoom/battleRoom.waypoints.lua");
dofile ("data/scripts/levels/battleRoom/cameras/battleRoom.camera.lua");
dofile ("data/scripts/levels/battleRoom/lights/battleRoom.lights.lua");
dofile ("data/scripts/levels/battleRoom/physics/static/battleRoom.physics.static.lua");
dofile ("data/scripts/levels/battleRoom/physics/dynamic/battleRoom.physics.dynamic.lua");

-- Call Function

function battleRoom_LOAD()
	battleRoom_CAMERAS();
	battleRoom_LIGHTS();
	battleRoom_STATIC_PHYSICS();
	battleRoom_DYNAMIC_PHYSICS();
	setWaypoints();
	createSpawners();
	setTargetables();
end
