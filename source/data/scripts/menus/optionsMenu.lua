-- Plight of The Weedunks
-- (c) Team Caffiene 2008
-------------------------- 

MENU_OPTIONS_SFX = 0;
MENU_OPTIONS_MUSIC = 1;
MENU_OPTIONS_BACK = 2;

CurrentOptionsMenu = MENU_OPTIONS_SFX;

function Update_OPTIONSMENU()
    drawOptionsMenu();
    userInteractOptionsMenu();
end

function drawOptionsMenu()
    if CurrentMenu == MENU_OPTIONS_PAUSED then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuOptionsBackgroundPause );
    else
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuOptionsBackground );
    end
    
	Horde:ShowOverlay(0.5224, 0.605, 0, 0, -- bot left
                      0.5224+(soundVolume*0.2979), 0.605, 1, 0, -- top left
                      0.5224+(soundVolume*0.2979), 0.765, 1, soundVolume, -- top right
                      0.5224, 0.765, 0, soundVolume, -- bot right
                      3, MenuOptionsBar );  
     
	Horde:ShowOverlay(0.5224, 0.31, 0, 0, -- bot left
                      0.5224+(musicVolume*0.2979), 0.31, 1, 0, -- top left
                      0.5224+(musicVolume*0.2979), 0.47, 1, musicVolume, -- top right
                      0.5224, 0.47, 0, musicVolume, -- bot right
                      3, MenuOptionsBar );
                      
    if CurrentOptionsMenu == MENU_OPTIONS_SFX then
        if CurrentMenu == MENU_OPTIONS_PAUSED then
    	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                              1, 0, 1, 0.1885, -- top left
                              1, 1, 1, 0.8125, -- top right
                              0, 1, 0, 0.8125, -- bot right
                              4, MenuOptionsSFXPause );
        else
    	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                              1, 0, 1, 0.1885, -- top left
                              1, 1, 1, 0.8125, -- top right
                              0, 1, 0, 0.8125, -- bot right
                              4, MenuOptionsSFX );
        end
    elseif CurrentOptionsMenu == MENU_OPTIONS_MUSIC then
        if CurrentMenu == MENU_OPTIONS_PAUSED then
    	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                              1, 0, 1, 0.1885, -- top left
                              1, 1, 1, 0.8125, -- top right
                              0, 1, 0, 0.8125, -- bot right
                              4, MenuOptionsMusicPause );
        else
    	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                              1, 0, 1, 0.1885, -- top left
                              1, 1, 1, 0.8125, -- top right
                              0, 1, 0, 0.8125, -- bot right
                              4, MenuOptionsMusic );
        end
    elseif CurrentOptionsMenu == MENU_OPTIONS_BACK then
        if CurrentMenu == MENU_OPTIONS_PAUSED then
    	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                              1, 0, 1, 0.1885, -- top left
                              1, 1, 1, 0.8125, -- top right
                              0, 1, 0, 0.8125, -- bot right
                              4, MenuOptionsBackPause );
        else
    	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                              1, 0, 1, 0.1885, -- top left
                              1, 1, 1, 0.8125, -- top right
                              0, 1, 0, 0.8125, -- bot right
                              4, MenuOptionsBack );
        end
    end
end

function userInteractOptionsMenu()
    if menuUp() == true then
        CurrentOptionsMenu = CurrentOptionsMenu-1;
        if CurrentOptionsMenu < 0 then
            CurrentOptionsMenu = 0;
        end
    end
    
    if menuDown() == true then
        CurrentOptionsMenu = CurrentOptionsMenu+1;
        if CurrentOptionsMenu > 2 then
            CurrentOptionsMenu = 2;
        end
    end
    
    if menuRight() == true then
        if CurrentOptionsMenu == MENU_OPTIONS_MUSIC then
            musicVolume = musicVolume+0.1;
            if musicVolume>1.0 then
                musicVolume = 1.0
            end
            -- set music volume
            AudioMan:SetMUSVolume(musicVolume*128);
        elseif CurrentOptionsMenu == MENU_OPTIONS_SFX then
            soundVolume = soundVolume+0.1;
            if soundVolume>1.0 then
                soundVolume = 1.0
            end
            -- set sound volumes
            AudioMan:SetSFXVolume(-1, soundVolume*128);
            reloadCommonVolumes();
            -- play stupid sound
        end
    end
    
    if menuLeft() == true then
        if CurrentOptionsMenu == MENU_OPTIONS_MUSIC then
            musicVolume = musicVolume-0.1;
            if musicVolume<0.0 then
                musicVolume = 0.0
            end
            -- set music volume
            AudioMan:SetMUSVolume(musicVolume*128);
        elseif CurrentOptionsMenu == MENU_OPTIONS_SFX then
            soundVolume = soundVolume-0.1;
            if soundVolume<0.0 then
                soundVolume = 0.0
            end
            -- set sound volumes
            AudioMan:SetSFXVolume(-1, soundVolume*128);
            reloadCommonVolumes();
            -- play stupid sound
        end
    end
    
    if menuBack() == true then
        Interpret:WriteIngameConfig(musicVolume, soundVolume);
        if CurrentMenu == MENU_OPTIONS_PAUSED then
            CurrentMenu = MENU_PAUSE;
        else
            CurrentMenu = MENU_MAIN;
        end
    end
    
    if menuSelect() == true and CurrentOptionsMenu == MENU_OPTIONS_BACK then
        Interpret:WriteIngameConfig(musicVolume, soundVolume);
        if CurrentMenu == MENU_OPTIONS_PAUSED then
            CurrentMenu = MENU_PAUSE;
        else
            CurrentMenu = MENU_MAIN;
        end
    end
end
