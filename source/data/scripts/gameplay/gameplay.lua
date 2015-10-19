-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

--dofile("data/scripts/gameplay/toothy/_setup.lua");
--dofile("data/scripts/gameplay/toothy/_update.lua");
dofile("data/scripts/gameplay/factory/_setup.lua");
dofile("data/scripts/gameplay/factory/_update.lua");
--dofile("data/scripts/gameplay/buglevel/_setup.lua");
--dofile("data/scripts/gameplay/buglevel/_update.lua");

function gameplay_SETUP()
	if CurrentLevel == "Toothy" then
		gameplay_SETUP_TOOTHY();
	end

	if CurrentLevel == "Factory" then
		gameplay_SETUP_FACTORY();
	end

	if CurrentLevel == "BugLevel" then
		gameplay_SETUP_BUGLEVEL();
	end
end

function gameplay_UPDATE()
	if CurrentLevel == "Toothy" then
		gameplay_UPDATE_TOOTHY();
	end

	if CurrentLevel == "Factory" then
		gameplay_UPDATE_FACTORY();
	end

	if CurrentLevel == "BugLevel" then
		gameplay_UPDATE_BUGLEVEL();
	end
end
