-- Plight of the Weedunks
function toothyUpdate()
    if openDoor == false then
        if conveyPlayed == false then
            conveyChan = AudioMan:PlaySFX("conveyorBelt",-1);
            conveyPlayed = true;
        elseif doorOpen == false then
            local t2x = Gx+((Kx-Gx)*0.5);
	        local t2y = Gy+((Ky-Gy)*0.5);
	        local t2z = Gz+((Kz-Gz)*0.5);

	        local dx = t2x-0;
	        local dy = t2y-0;
	        local dz = t2z+38;

        	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*10;
        	if distance > 255 then distance = 255 end
        	AudioMan:SetDistance( conveyChan, distance );
        end
    end

	if openDoor == true then
		createMoreSpawners();
		setMoreWaypoints();
		doorOpen = true;
		openDoor = false;
		AudioMan:PlayMUS("toothyMusic", -1);
		AudioMan:PlaySFX("toothyDoor");
		ODE:KillMoving(botLeftToothyDoor_scripted);
		ODE:KillMoving(botRightToothyDoor_scripted);
		ODE:KillMoving(topLeftToothyDoor_scripted);
	    ODE:KillMoving(topRightToothyDoor_scripted);
	    amBXeffects:append({cnt = 15; effect = "toothyOpenDoor"});
	end

	if doorOpen == true then
		moveTeeth();
		if doorOpenTimer < 80 then
			Horde:SetModelAnimParams(LevelMod, 0, doorOpenTimer, 1.0);
			doorOpenTimer = doorOpenTimer + 2;
    	end
	end
	
	if GrandoHitsNextLevel == true or KohiHitsNextLevel == true then
	    if Zone7Switch == false then
            channel = AudioMan:PlaySFX("junkheadToothy3");
            Zone7Switch = true;
        end
	end
	if AudioMan:CHANPlaying(channel) == 0 and Zone7Switch == true then
            ChangeLevelOnNextUpdate("FactorySection1");
    end
	-- incase a player moves back into the game
	GrandoHitsNextLevel = false;
	KohiHitsNextLevel = false;
	
	if  kohiHitZone5 or grandoHitZone5 == true then
        if Zone5Switch == false then
            AudioMan:PlaySFX("junkheadToothy1");
            Zone5Switch = true;
        end
    end
    
    if  kohiHitZone6 or grandoHitZone6 == true then
        if Zone6Switch == false then
            AudioMan:PlaySFX("junkheadToothy2");
            Zone6Switch = true;
        end
    end
    
	--[[
    for i,weedunklist in ipairs(WEEDUNKS) do
        if weedunklist.weedunk == weedunkBert or weedunklist.weedunk == weedunkErnie then
	        if weedunklist.spawner == "spawn0" and not (grandoSpawnNum == 3 or kohiSpawnNum == 3) then
	            killWeedunk(weedunklist.physics);
	        elseif weedunklist.spawner == "spawn1" and not (grandoSpawnNum == 1 or kohiSpawnNum == 1) then
	            killWeedunk(weedunklist.physics);
	        elseif weedunklist.spawner == "spawn2" and not (grandoSpawnNum == 2 or kohiSpawnNum == 2) then
	            killWeedunk(weedunklist.physics);
	        elseif weedunklist.spawner == "spawn3" and not (grandoSpawnNum == 3 or kohiSpawnNum == 3) then
	            killWeedunk(weedunklist.physics);
	        elseif weedunklist.spawner == "spawn4" and not (grandoSpawnNum == 4 or kohiSpawnNum == 4) then
	            killWeedunk(weedunklist.physics);
	        elseif weedunklist.spawner == "spawn5" and not (grandoSpawnNum == 5 or kohiSpawnNum == 5) then
	            killWeedunk(weedunklist.physics);
	        elseif weedunklist.spawner == "spawn6" and not (grandoSpawnNum == 6 or kohiSpawnNum == 6) then
	            killWeedunk(weedunklist.physics);
	        end
		end
	end]]--
end

function createMoreSpawners()
	SPAWNERS = { next = SPAWNERS, x = 0.0, y = 7.5, z = 16, numofbert = 1, numofernie = 1, timer = 0, bert = 0, ernie = 0, delay = 10, name = "spawn1" };
	SPAWNERS = { next = SPAWNERS, x = 0.0, y = 7.5, z = -24, numofbert = 1, numofernie = 1, timer = 0, bert = 0, ernie = 0, delay = 10, name = "spawn3" };
	SPAWNERS = { next = SPAWNERS, x = 0.0, y = 7.5, z = 30, numofbert = 1, numofernie = 1, timer = 0, bert = 0, ernie = 0, delay = 10, name = "spawn4" };
	SPAWNERS = { next = SPAWNERS, x = 0.0, y = 7.5, z = -64, numofbert = 1, numofernie = 1, timer = 0, bert = 0, ernie = 0, delay = 10, name = "spawn5" };
end

function setMoreWaypoints()
	AI:AddWayPoint( WeedunkWayPoint, "teeth1", 0.0, 3.0, 22.1217, 90.0 );
	AI:AddWayPoint( WeedunkWayPoint, "teeth2", 0.0, 3.0, 2.06736, 90.0 );
	AI:AddWayPoint( WeedunkWayPoint, "teeth3", 0.0, 3.0, -17.9551, 90.0 );
	AI:AddWayPoint( WeedunkWayPoint, "teeth4", 0.0, 3.0, -58.1733, 90.0 );
	AI:AddWayPoint( WeedunkWayPoint, "teeth5", 0.0, 3.0, -78.3095, 90.0 );
	AI:AddWayPoint( WeedunkWayPoint, "teeth6", 0.0, 3.0, -98.4187, 90.0 );
end

function moveTeeth()
	local deathDepth = 1.735451;

	ODE:SetMovingPos(teeth8_scripted, teeth8_posX, teeth8_posY, teeth8_posZ);
	ODE:SetMovingPos(teeth9_scripted, teeth9_posX, teeth9_posY, teeth9_posZ);
	ODE:SetMovingPos(teeth10_scripted, teeth10_posX, teeth10_posY, teeth10_posZ);
	ODE:SetMovingPos(teeth11_scripted, teeth11_posX, teeth11_posY, teeth11_posZ);
	ODE:SetMovingPos(teeth12_scripted, teeth12_posX, teeth12_posY, teeth12_posZ);
	ODE:SetMovingPos(teeth13_scripted, teeth13_posX, teeth13_posY, teeth13_posZ);
	ODE:SetMovingPos(teeth14_scripted, teeth14_posX, teeth14_posY, teeth14_posZ);
	
	ODE:SetMovingPos(death1_scripted, teeth8_posX, teeth8_posY-deathDepth, teeth8_posZ);
	ODE:SetMovingPos(death2_scripted, teeth9_posX, teeth9_posY-deathDepth, teeth9_posZ);
	ODE:SetMovingPos(death3_scripted, teeth10_posX, teeth10_posY-deathDepth, teeth10_posZ);
	ODE:SetMovingPos(death4_scripted, teeth11_posX, teeth11_posY-deathDepth, teeth11_posZ);
	ODE:SetMovingPos(death5_scripted, teeth12_posX, teeth12_posY-deathDepth, teeth12_posZ);
	ODE:SetMovingPos(death6_scripted, teeth13_posX, teeth13_posY-deathDepth, teeth13_posZ);

	if teeth8_posY > 9.8 then teeth8Falling = true end;
	if teeth9_posY > 9.8 then teeth9Falling = true end;
	if teeth10_posY > 9.8 then teeth10Falling = true end;
	if teeth11_posY > 9.8 then teeth11Falling = true end;
	if teeth12_posY > 9.8 then teeth12Falling = true end;
	if teeth13_posY > 9.8 then teeth13Falling = true end;
	if teeth14_posY > 9.8 then teeth14Falling = true end;


	if teeth8Falling == true then teeth8_posY = teeth8_posY -1 end;
	if teeth9Falling == true then teeth9_posY = teeth9_posY -1 end;
	if teeth10Falling == true then teeth10_posY = teeth10_posY -1 end;
	if teeth11Falling == true then teeth11_posY = teeth11_posY -1 end;
	if teeth12Falling == true then teeth12_posY = teeth12_posY -1 end;
	if teeth13Falling == true then teeth13_posY = teeth13_posY -1 end;
	if teeth14Falling == true then teeth14_posY = teeth14_posY -1 end;
	if teeth8_posY < 2 then 
		if teeth8Falling == true then 
			teeth8Falling = false 
			Horde:AddParticleBox(teeth8_posX,teeth8_posY-1.575,teeth8_posZ, 9.22, 0.1, 1.2, 5, ToothyParticleEffect);
			positionSoundNode("teethChomp", teeth8_node);
		end
	end;
	if teeth9_posY < 2 then 
		if teeth9Falling == true then
			teeth9Falling = false 
			Horde:AddParticleBox(teeth9_posX,teeth9_posY-1.575,teeth9_posZ, 9.22, 0.1, 1.2, 5, ToothyParticleEffect);
			positionSoundNode("teethChomp", teeth9_node);
		end
	end;
	if teeth10_posY < 2 then 
		if teeth10Falling == true then
			teeth10Falling = false 
			Horde:AddParticleBox(teeth10_posX,teeth10_posY-1.575,teeth10_posZ, 9.22, 0.1, 1.2, 5, ToothyParticleEffect);
			positionSoundNode("teethChomp", teeth10_node);
		end
	end;
	if teeth11_posY < 2 then 
		if teeth11Falling == true then
			teeth11Falling = false 
			Horde:AddParticleBox(teeth11_posX,teeth11_posY-1.575,teeth11_posZ, 9.22, 0.1, 1.2, 5, ToothyParticleEffect);
			positionSoundNode("teethChomp", teeth11_node);	
		end
	end;
	if teeth12_posY < 2 then 
		if teeth12Falling == true then
			teeth12Falling = false 
			Horde:AddParticleBox(teeth12_posX,teeth12_posY-1.575,teeth12_posZ, 9.22, 0.1, 1.2, 5, ToothyParticleEffect);
			positionSoundNode("teethChomp", teeth12_node);
		end
	end;
	if teeth13_posY < 2 then 
		if teeth13Falling == true then
			teeth13Falling = false 
			Horde:AddParticleBox(teeth13_posX,teeth13_posY-1.575,teeth13_posZ, 9.22, 0.1, 1.2, 5, ToothyParticleEffect);
			positionSoundNode("teethChomp", teeth13_node);
		end
	end;
	if teeth14_posY < 1 then 
		if teeth14Falling == true then
			teeth14Falling = false 
			Horde:AddParticleBox(teeth14_posX,teeth14_posY-1.575,teeth14_posZ, 9.22, 0.1, 1.2, 5, ToothyParticleEffect);
			positionSoundNode("teethChomp", teeth14_node);
		end
	end;

	if teeth8Falling == false then teeth8_posY = teeth8_posY + 0.1 end;
	if teeth9Falling == false then teeth9_posY = teeth9_posY + 0.1 end;
	if teeth10Falling == false then teeth10_posY = teeth10_posY + 0.1 end;
	if teeth11Falling == false then teeth11_posY = teeth11_posY + 0.1 end;
	if teeth12Falling == false then teeth12_posY = teeth12_posY + 0.1 end;
	if teeth13Falling == false then teeth13_posY = teeth13_posY + 0.1 end;
	if teeth14Falling == false then teeth14_posY = teeth14_posY + 1 end;
end
