function reloadCommonVolumes()
    AudioMan:SetSFXVolume("menuChoose", 30*soundVolume);
    AudioMan:SetSFXVolume("menuSelect", 30*soundVolume);
    
    AudioMan:SetSFXVolume("weedunkDance1", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkDance2", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkDance3", 20*soundVolume);
    --AudioMan:SetSFXVolume("weedunkDeath", 10*soundVolume);
    AudioMan:SetSFXVolume("weedunkWorking", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkStruggle", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkThrown", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkToxicDeath", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkTransplantWalking", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkWalkingMumble1", 20*soundVolume);
    AudioMan:SetSFXVolume("weedunkWalkingMumble2", 20*soundVolume);
    
    AudioMan:SetSFXVolume("kohiDeath", 20*soundVolume);
    AudioMan:SetSFXVolume("kohiDeathMincer", 20*soundVolume);
    AudioMan:SetSFXVolume("kohiToxicDeath", 20*soundVolume);
    AudioMan:SetSFXVolume("kohiIdle", 20*soundVolume);
    AudioMan:SetSFXVolume("kohiStartJump", 20*soundVolume);
    AudioMan:SetSFXVolume("kohiFinishJump", 20*soundVolume);
    AudioMan:SetSFXVolume("kohiExplode", 80*soundVolume);
    AudioMan:SetSFXVolume("kohiRunFast", 20*soundVolume);
    
    AudioMan:SetSFXVolume("grandoDeath", 20*soundVolume);
    AudioMan:SetSFXVolume("grandoDeathMincer", 20*soundVolume);
    AudioMan:SetSFXVolume("grandoToxicDeath", 20*soundVolume);
    --AudioMan:SetSFXVolume("grandoIdle", 20*soundVolume);
    --AudioMan:SetSFXVolume("grandoDeflate", 20*soundVolume);
    --AudioMan:SetSFXVolume("grandoInflate", 20*soundVolume);    
    --AudioMan:SetSFXVolume("grandoFinishJump", 20*soundVolume);
	--AudioMan:SetSFXVolume("grandoStartJump", 20*soundVolume);
	
	AudioMan:SetSFXVolume("weedunkSpawner", 20*soundVolume);
	
	if CurrentLevel == "Toothy" then
	    AudioMan:SetSFXVolume("conveyorBelt", 45*soundVolume);
	    AudioMan:SetSFXVolume("teethChomp", 45*soundVolume);  
	    AudioMan:SetSFXVolume("toothyDoor", 45*soundVolume);  
	    
	    AudioMan:SetSFXVolume("junkheadToothy1", 45*soundVolume);  
	    AudioMan:SetSFXVolume("junkheadToothy2", 45*soundVolume);  
	    AudioMan:SetSFXVolume("junkheadToothy3", 45*soundVolume);  
	    
	elseif CurrentLevel == "FactorySection1" then
	    AudioMan:SetSFXVolume("breakableBoard",45*soundVolume);
	    AudioMan:SetSFXVolume("bugSteps",45*soundVolume);
	    AudioMan:SetSFXVolume("bugStepsLock",45*soundVolume);
	    AudioMan:SetSFXVolume("bugStepsWithWood",45*soundVolume);
	    AudioMan:SetSFXVolume("openGrate",45*soundVolume);
	    AudioMan:SetSFXVolume("risingFloor",45*soundVolume);
	    AudioMan:SetSFXVolume("wallExploding",45*soundVolume);
	    
	    AudioMan:SetSFXVolume("Junkhead1",45*soundVolume);
	    AudioMan:SetSFXVolume("Tip1",45*soundVolume);
	    AudioMan:SetSFXVolume("Tip2",45*soundVolume);
	    AudioMan:SetSFXVolume("Tip3",45*soundVolume);
	    
	    AudioMan:SetSFXVolume("button",45*soundVolume);
	    AudioMan:SetSFXVolume("conveyorBelt",45*soundVolume);
	    AudioMan:SetSFXVolume("conveyorTower",45*soundVolume);
	    AudioMan:SetSFXVolume("junkheadScreenOn",45*soundVolume);
	    AudioMan:SetSFXVolume("junkheadScreenOff",45*soundVolume);
	    AudioMan:SetSFXVolume("lumpsBeingMulched",45*soundVolume);
	    AudioMan:SetSFXVolume("mincer",45*soundVolume);
	    AudioMan:SetSFXVolume("mulchPipe",45*soundVolume);
	    AudioMan:SetSFXVolume("weedunkShockerShocking",45*soundVolume);
	    AudioMan:SetSFXVolume("weedunkShockerCurrent",45*soundVolume);
	    
	elseif CurrentLevel == "FactorySection2" then
	    AudioMan:SetSFXVolume("allergicBlockLong",45*soundVolume);
	    AudioMan:SetSFXVolume("allergicBlockShort",45*soundVolume);
	    AudioMan:SetSFXVolume("fanStart",45*soundVolume);
	    AudioMan:SetSFXVolume("fanLooping",45*soundVolume);
	    AudioMan:SetSFXVolume("fanFinish",45*soundVolume);
	    AudioMan:SetSFXVolume("mulchValveBroken",45*soundVolume);
	    AudioMan:SetSFXVolume("mulchValveBrokenLoop",45*soundVolume);
	    AudioMan:SetSFXVolume("mulchValveBrokenStop",45*soundVolume);
	    AudioMan:SetSFXVolume("fallingConveyor",45*soundVolume);
	    AudioMan:SetSFXVolume("doorOpening",45*soundVolume);
	    
	    AudioMan:SetSFXVolume("button",45*soundVolume);
	    AudioMan:SetSFXVolume("conveyorBelt",45*soundVolume);
	    AudioMan:SetSFXVolume("conveyorTower",45*soundVolume);
	    AudioMan:SetSFXVolume("junkheadScreenOn",45*soundVolume);
	    AudioMan:SetSFXVolume("junkheadScreenOff",45*soundVolume);
	    AudioMan:SetSFXVolume("lumpsBeingMulched",45*soundVolume);
	    AudioMan:SetSFXVolume("mincer",45*soundVolume);
	    AudioMan:SetSFXVolume("mulchPipe",45*soundVolume);
	    AudioMan:SetSFXVolume("weedunkShockerShocking",45*soundVolume);
	    AudioMan:SetSFXVolume("weedunkShockerCurrent",45*soundVolume);
	    AudioMan:SetSFXVolume("junkHead2", 45*soundVolume);
	    AudioMan:SetSFXVolume("junkHead3", 45*soundVolume);
	end
end
