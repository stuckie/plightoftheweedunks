dofile ("data/scripts/misc/volumes.lua");

function loadCommonSound()

--	Weedunk SFX

	AudioMan:LoadSFX("weedunkDance1", "data/sfx/weedunks/dance/weedunkDance1.ogg");	
    AudioMan:LoadSFX("weedunkDance2", "data/sfx/weedunks/dance/weedunkDance2.ogg");	
	AudioMan:LoadSFX("weedunkDance3", "data/sfx/weedunks/dance/weedunkDance3.ogg"); 	
	AudioMan:LoadSFX("weedunkDeath", "data/sfx/weedunks/death/weedunkDeath.ogg");  
	AudioMan:LoadSFX("weedunkWorking", "data/sfx/weedunks/working/weedunkWorking.ogg");    
	AudioMan:LoadSFX("weedunkStruggle", "data/sfx/weedunks/struggle/weedunkStruggle.ogg"); 	
	AudioMan:LoadSFX("weedunkThrown", "data/sfx/weedunks/thrown/weedunkThrown.ogg");    
	AudioMan:LoadSFX("weedunkToxicDeath", "data/sfx/weedunks/death/weedunkToxicDeath.ogg");    
	AudioMan:LoadSFX("weedunkTransplantWalking", "data/sfx/weedunks/transplant/weedunkTransplantWalking.ogg");    
	AudioMan:LoadSFX("weedunkWalkingMumble1", "data/sfx/weedunks/walking/weedunkWalkingMumble1.ogg");	
	AudioMan:LoadSFX("weedunkWalkingMumble2", "data/sfx/weedunks/walking/weedunkWalkingMumble2.ogg");

--	Kohi SFX

	AudioMan:LoadSFX("kohiDeath", "data/sfx/kohi/death/kohiDeath.ogg");
	AudioMan:LoadSFX("kohiDeathMincer", "data/sfx/kohi/death/kohiDeathMincer.ogg");
	AudioMan:LoadSFX("kohiToxicDeath", "data/sfx/kohi/death/kohiToxicDeath.ogg");
	AudioMan:LoadSFX("kohiIdle", "data/sfx/kohi/idle/kohiIdle.ogg");	
	AudioMan:LoadSFX("kohiStartJump", "data/sfx/kohi/jump/kohiStartJump.ogg");
    AudioMan:LoadSFX("kohiFinishJump", "data/sfx/kohi/jump/kohiFinishJump.ogg");
    AudioMan:LoadSFX("kohiExplode", "data/sfx/kohi/explode/kohiExplode.ogg");
    AudioMan:LoadSFX("kohiRunFast", "data/sfx/kohi/run/kohiRunFast.ogg");
	
--	Grando SFX

	AudioMan:LoadSFX("grandoDeath", "data/sfx/grando/death/grandoDeath.ogg");	
	AudioMan:LoadSFX("grandoDeathMincer", "data/sfx/grando/death/grandoDeathMincer.ogg");
	AudioMan:LoadSFX("grandoToxicDeath", "data/sfx/grando/death/grandoToxicDeath.ogg");
    AudioMan:LoadSFX("grandoIdle", "data/sfx/grando/idle/grandoIdle.ogg");	   
    AudioMan:LoadSFX("grandoStartJump", "data/sfx/grando/jump/grandoStartJump.ogg");	
    AudioMan:LoadSFX("grandoFinishJump", "data/sfx/grando/jump/grandoFinishJump.ogg");
	AudioMan:LoadSFX("grandoInflate", "data/sfx/grando/inflate/grandoInflate.ogg");
	AudioMan:LoadSFX("grandoDeflate", "data/sfx/grando/inflate/grandoDeflate.ogg");

-- Menu SFX

    AudioMan:LoadSFX("menuSelect", "data/sfx/effects/menuItemHighlight.ogg");    
    AudioMan:LoadSFX("menuChoose", "data/sfx/effects/menuItemSelected.ogg");
    
-- Common Environment

    AudioMan:LoadSFX("weedunkSpawner", "data/sfx/environment/weedunkSpawner.ogg");
    
    reloadCommonVolumes();
end


function positionSoundNode( sound, objectNode, loops )
    local t2x = 0.0;
	local t2y = 0.0;
	local t2z = 0.0;
	local t1x,t1y,t1z, r1x,r1y,r1z, s1x,s1y,s1z = Horde:GetNodeTransform( objectNode );
	if not GrandoDead and not KohiDead then
	     t2x = Gx+((Kx-Gx)*0.5);
	     t2y = Gy+((Ky-Gy)*0.5);
	     t2z = Gz+((Kz-Gz)*0.5);
	elseif GrandoDead then
	     t2x = Kx;
	     t2y = Ky;
	     t2z = Kz;
	elseif KohiDead then
	     t2x = Gx;
	     t2y = Gy;
	     t2z = Gz;
	else
	     t2x = 0.0;
	     t2y = 0.0;
	     t2z = 0.0;
	end

	local dx = t2x-t1x;
	local dy = t2y-t1y;
	local dz = t2z-t1z;

--		Interpret:LogDebug("DX - " .. dx .. "\n");

	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*10;
-- 		possibly div by 256 or some form of it... 

    if distance < 256 then
	    local soundChannel = AudioMan:CHANinGROUP("all");
	    AudioMan:SetDistance( soundChannel, distance );
	    AudioMan:PlaySFX(sound,loops,soundChannel);
	    return soundChannel;
	else
	    return -1;
	end
end

function calcSoundDistance( t1x, t1y, t1z )
    local t2x = 0.0;
	local t2y = 0.0;
	local t2z = 0.0;
    if not GrandoDead and not KohiDead then
	    t2x = Gx+((Kx-Gx)*0.5);
	    t2y = Gy+((Ky-Gy)*0.5);
	    t2z = Gz+((Kz-Gz)*0.5);
	elseif GrandoDead and not KohiDead then
	    t2x = Kx;
	    t2y = Ky;
	    t2z = Kz;
	else
	    t2x = Gx;
	    t2y = Gy;
	    t2z = Gz;
    end
	
    local dx = t2x-t1x;
	local dy = t2y-t1y;
	local dz = t2z-t1z;

--	Interpret:LogDebug("DX - " .. dx .. "\n");

	return math.sqrt(dx*dx+dy*dy+dz*dz)*10;
end

function calcSoundDistance2POS( t1x, t1y, t1z, t2x, t2y, t2z )
    local dx = t2x-t1x;
	local dy = t2y-t1y;
	local dz = t2z-t1z;

--	Interpret:LogDebug("DX - " .. dx .. "\n");

	return math.sqrt(dx*dx+dy*dy+dz*dz)*10;
end

function positionSoundXYZ( sound, t1x, t1y, t1z, loops )
    local t2x = 0.0;
	    local t2y = 0.0;
	    local t2z = 0.0;
	if not GrandoDead and not KohiDead then
	     t2x = Gx+((Kx-Gx)*0.5);
	     t2y = Gy+((Ky-Gy)*0.5);
	     t2z = Gz+((Kz-Gz)*0.5);
	elseif GrandoDead then
	     t2x = Kx;
	     t2y = Ky;
	     t2z = Kz;
	elseif KohiDead then
	     t2x = Gx;
	     t2y = Gy;
	     t2z = Gz;
	else
	    local t2x = 0.0;
	    local t2y = 0.0;
	    local t2z = 0.0;
	end

	local dx = t2x-t1x;
	local dy = t2y-t1y;
	local dz = t2z-t1z;

--	Interpret:LogDebug("DX - " .. dx .. "\n");

	local distance = math.sqrt(dx*dx+dy*dy+dz*dz)*10;
--	 possibly div by 256 or some form of it... 
		
    if distance < 256 then
	    local soundChannel = AudioMan:CHANinGROUP("all");
	    AudioMan:SetDistance( soundChannel, distance );
	    AudioMan:PlaySFX(sound,loops,soundChannel);
	    return soundChannel;
	else
	    return -1;
	end
end
	