-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

amBX = SGZamBX();
amBXframeCnt = 0;
amBXeffects = List:new();
amBXambientMin = 0.5;
amBXKohiDieOn = false;
amBXGrandoDieOn = false;
amBXToothysDoorOn = false;
amBXRisingStepsOn = false;
amBXShockWeedunkOn = false;

function setupAmBX()
	amBX:Start();
	amBX:SetFade(0.5, "All");
	amBX:Update();
end

function amBXLoadFade()
	amBX:SetFade(0, "All");
	amBX:SetLight(1.0, 1.0, 1.0, "All");
	amBX:Update();
end

function updateAmBX()
	amBXframeCnt = amBXframeCnt + 1;
	if amBXframeCnt > 5 then
		amBXframeCnt = 0.0;
		amBXDoEffects();
		amBX:Update();
	end
end

function amBXDoEffects()
    if CurrentMenu == MENU_NONE then
        if CurrentLevel == "Toothy" then
            amBXAmbientToothy();
        elseif CurrentLevel == "FactorySection1" then
            amBXAmbientFS1();
        elseif CurrentLevel == "FactorySection2" then
            amBXAmbientFS2();
        else
            amBXAmbientgeneral();
        end
    else
	    amBXAmbientMenu();
	end
	
	for i,effects in ipairs(amBXeffects) do
		if effects.cnt > 0 then
			effects.cnt = effects.cnt - 1;
			if effects.effect == "kohiDie" then
				amBXKohiDie();
			elseif effects.effect == "grandoDie" then
				amBXGrandoDie();
			elseif effects.effect == "kohiOnFan" then
				amBXKohiOnFan();
			elseif effects.effect == "grandoOnFan" then
				amBXGrandoOnFan();
			elseif effects.effect == "toothyOpenDoor" then
			    amBXToothyDoorOpen();
			elseif effects.effect == "wallDestroy" then
			    amBXWallDestroy();
			elseif effects.effect == "risingSteps" then
			    amBXRisingSteps();
			elseif effects.effect == "stepsUnlocked" then
			    amBXStepsUnlocked();
			elseif effects.effect == "shockWeedunk" then
			    amBXShockWeedunk();
			elseif effects.effect == "mulchValveBroke" then
			    amBXMulchValveBroken();
			end
		end
		if effects.cnt == 0 then
		    amBXeffects:remove(effects);
		end
	end
end

function amBXAmbientgeneral()
    amBXAmbientMenu();
end

function amBXAmbientToothy()
    amBXAmbientMenu();
end

function amBXAmbientFS1()
    amBXAmbientMenu();
end

function amBXAmbientFS2()
    amBXAmbientMenu();
end

function amBXAmbientMenu()
	amBX:SetFade(0.5, "All");
	
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "N");
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "S");
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "E");
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "W");
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "NE");
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "SW");
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "SE");
	amBX:SetLight(0.0, amBXambientMin+(math.random()*(1.0 - amBXambientMin)), 0.0, "NW");
	
	if (math.random() < 0.5) then
	    local flashPos = math.random();
	    if flashPos < 0.125 then
	        amBX:SetFade(0.1, "N");
	        amBX:SetLight(1.0, 0.0, 0.0, "N");
	    elseif flashPos < 0.25 then
	        amBX:SetFade(0.1, "S");
	        amBX:SetLight(1.0, 0.0, 0.0, "S");
	    elseif flashPos < 0.375 then
	        amBX:SetFade(0.1, "E");
	        amBX:SetLight(1.0, 0.0, 0.0, "E");
	    elseif flashPos < 0.5 then
	        amBX:SetFade(0.1, "W");
	        amBX:SetLight(1.0, 0.0, 0.0, "W");
	    elseif flashPos < 0.625 then
	        amBX:SetFade(0.1, "NE");
	        amBX:SetLight(1.0, 0.0, 0.0, "NE");
	    elseif flashPos < 0.75 then
	        amBX:SetFade(0.1, "NW");
	        amBX:SetLight(1.0, 0.0, 0.0, "NW");
	    elseif flashPos < 0.875 then
	        amBX:SetFade(0.1, "SE");
	        amBX:SetLight(1.0, 0.0, 0.0, "SE");
	    else
	        amBX:SetFade(0.1, "SW");
	        amBX:SetLight(1.0, 0.0, 0.0, "SW");
	    end
	end
	    
	amBX:SetFan(0.0, "All");
end

function amBXKohiDie()
	amBX:SetFade(0.1, "W");
	
	if amBXKohiDieOn == true then
		amBX:SetLight(0.0, 0.0, 1.0, "W");
	else
		amBX:SetLight(0.0, 0.0, 0.25, "W");
	end
	
	amBXKohiDieOn = not amBXKohiDieOn;
end

function amBXGrandoDie()
	amBX:SetFade(0.1, "E");
	
	if amBXGrandoDieOn == true then
		amBX:SetLight(1.0, 0.0, 0.0, "E");
	else
		amBX:SetLight(0.25, 0.0, 0.0, "E");
	end
	
	amBXGrandoDieOn = not amBXGrandoDieOn;
end

function amBXKohiOnFan()
	amBX:SetFan(1.0, "NW");
end

function amBXGrandoOnFan()
	amBX:SetFan(1.0, "NE");
end

function amBXToothyDoorOpen()
	amBX:SetFade(0.1, "All");
	
	if amBXToothysDoorOn == true then
		amBX:SetLight(1.0, 1.0, 1.0, "All");
	else
		amBX:SetLight(0.25, 0.25, 0.25, "All");
	end
	
	amBXToothysDoorOn = not amBXToothysDoorOn;
end

function amBXWallDestroy()
    amBX:SetLight(1.0, 1.0, 0.0, "All");
end

function amBXRisingSteps()
	amBX:SetFade(0.25, "All");
	
	if amBXRisingStepsOn == true then
		amBX:SetLight(0.0, 0.0, 1.0, "All");
	else
		amBX:SetLight(0.0, 0.0, 0.25, "All");
	end
	
	amBXRisingStepsOn = not amBXRisingStepsOn;
end

function amBXStepsUnlocked()
    amBX:SetLight(0.0, 1.0, 0.25, "All");
end

function amBXShockWeedunk()
	amBX:SetFade(0.1, "All");
	
	if amBXShockWeedunkOn == true then
		amBX:SetLight(0.0, 0.0, 1.0, "All");
	else
		amBX:SetLight(0.0, 0.0, 0.25, "All");
	end
	
	amBXShockWeedunkOn = not amBXShockWeedunkOn;
end

function amBXMulchValveBroken()
    amBX:SetLight(1.0, 0.0, 0.0, "N");
    amBX:SetLight(1.0, 0.0, 0.0, "NE");
    amBX:SetLight(1.0, 0.0, 0.0, "NW");
end
