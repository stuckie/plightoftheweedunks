-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Load Level Data
dofile ("data/scripts/levels/bilgeRoom/bilgeRoom.spawners.lua");
dofile ("data/scripts/levels/bilgeRoom/bilgeRoom.targets.lua");
dofile ("data/scripts/levels/bilgeRoom/bilgeRoom.waypoints.lua");
dofile ("data/scripts/levels/bilgeRoom/cameras/bilgeRoom.camera.lua");
dofile ("data/scripts/levels/bilgeRoom/lights/bilgeRoom.lights.lua");
dofile ("data/scripts/levels/bilgeRoom/physics/static/bilgeRoom.physics.static.lua");
dofile ("data/scripts/levels/bilgeRoom/physics/dynamic/bilgeRoom.physics.dynamic.lua");

-- Call Function

function bilgeRoom_LOAD()
	bilgeRoom_CAMERAS();
	bilgeRoom_LIGHTS();
	bilgeRoom_STATIC_PHYSICS();
	bilgeRoom_DYNAMIC_PHYSICS();
	setWaypoints();
	createSpawners();
	setTargetables();
end
