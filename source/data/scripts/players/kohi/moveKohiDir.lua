-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/players/kohi/moveKohiCompass.lua");

function moveKohiForward(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiNorth(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiSouth(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiEast(f);
	else
		moveKohiWest(f);
	end
end

function moveKohiBackward(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiSouth(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiNorth(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiWest(f);    
	else
		moveKohiEast(f);
	end
end

function moveKohiLeft(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiWest(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiEast(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiNorth(f);
	else
		moveKohiSouth(f);
	end
end

function moveKohiRight(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiEast(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiWest(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiSouth(f);
	else
		moveKohiNorth(f);
	end
end

function moveKohiFL(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiNW(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiSE(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiNE(f);
	else
		moveKohiSW(f);
	end
end

function moveKohiFR(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiNE(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiSW(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiSE(f);
	else
		moveKohiSW(f);
	end
end

function moveKohiBL(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiSW(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiNE(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiNW(f);
	else
		moveKohiSE(f);
	end
end

function moveKohiBR(f)
	if Camera:GetCamLookDir() == "N" then
		moveKohiSE(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveKohiNW(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveKohiSW(f);
	else
		moveKohiNE(f);
	end
end
