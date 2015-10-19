-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/players/grando/moveGrandoCompass.lua");

function moveGrandoForward(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoNorth(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoSouth(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoEast(f);
	else
		moveGrandoWest(f);
	end
end

function moveGrandoBackward(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoSouth(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoNorth(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoWest(f);    
	else
		moveGrandoEast(f);
	end
end

function moveGrandoLeft(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoWest(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoEast(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoNorth(f);
	else
		moveGrandoSouth(f);
	end
end

function moveGrandoRight(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoEast(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoWest(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoSouth(f);
	else
		moveGrandoNorth(f);
	end
end

function moveGrandoFL(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoNW(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoSE(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoNE(f);
	else
		moveGrandoSW(f);
	end
end

function moveGrandoFR(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoNE(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoSW(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoSE(f);
	else
		moveGrandoSW(f);
	end
end

function moveGrandoBL(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoSW(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoNE(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoNW(f);
	else
		moveGrandoSE(f);
	end
end

function moveGrandoBR(f)
	if Camera:GetCamLookDir() == "N" then
		moveGrandoSE(f);
	elseif Camera:GetCamLookDir() == "S" then
		moveGrandoNW(f);
	elseif Camera:GetCamLookDir() == "E" then
		moveGrandoSW(f);
	else
		moveGrandoNE(f);
	end
end
