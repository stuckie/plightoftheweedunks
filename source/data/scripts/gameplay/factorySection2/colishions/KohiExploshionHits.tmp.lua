function KohiExploshionHitsexplodeUnderPlatform()
    platfromState = PLATFORM_UP;
end

function KohiExploshionHitsmulchValveEast() 
    if sludgeEDestroyedTime > sludgeHealTime then
        sludgeEDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
function KohiExploshionHitsmulchValveNorth() 
    if sludgeNDestroyedTime > sludgeHealTime then
        sludgeNDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
function KohiExploshionHitsmulchValveNorthEast() 
    if sludgeNEDestroyedTime > sludgeHealTime and converFallen == true then
        sludgeNEDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
function KohiExploshionHitsmulchValveNorthWest() 
    if sludgeNWDestroyedTime > sludgeHealTime then
        sludgeNWDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
function KohiExploshionHitsmulchValveSouth() 
    if sludgeSDestroyedTime > sludgeHealTime then
        sludgeSDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
function KohiExploshionHitsmulchValveSouthEast() 
    if sludgeSEDestroyedTime > sludgeHealTime then
        sludgeSEDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
function KohiExploshionHitsmulchValveSouthWest() 
    if sludgeSWDestroyedTime > sludgeHealTime then
        sludgeSWDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
function KohiExploshionHitsmulchValveWest() 
    if sludgeWDestroyedTime > sludgeHealTime then
        sludgeWDestroyedTime=0;
        amBXeffects:append({cnt = 5; effect = "mulchValveBroke"});
        AudioMan:PlaySFX("mulchValveBroken");
    end
end
