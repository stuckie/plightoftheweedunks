-- Plight of The Weedunks
-- (c) Team Caffiene 2008
-------------------------- 
MENU_PAUSE_CONTINUE = 0;
MENU_PAUSE_RESTART = 1;
MENU_PAUSE_OPTIONS = 2;
MENU_PAUSE_EXIT = 3;

CurrentPauseMenu = MENU_PAUSE_CONTINUE;

function Update_PAUSEMENU()	  
    drawPauseMenu();
    userInteractPauseMenu();
end

function drawPauseMenu()    
    if CurrentPauseMenu == MENU_PAUSE_CONTINUE then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuPauseContinue );
    elseif CurrentPauseMenu == MENU_PAUSE_RESTART then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuPauseRestart );
    elseif CurrentPauseMenu == MENU_PAUSE_OPTIONS then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuPauseOptions );
    elseif CurrentPauseMenu == MENU_PAUSE_EXIT then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuPauseExit );
    else
        CurrentPauseMenu = MENU_PAUSE_CONTINUE;
    end
end

function userInteractPauseMenu()
    if menuDown() == true then
        CurrentPauseMenu = CurrentPauseMenu+1;
        if CurrentPauseMenu > 3 then
            CurrentPauseMenu = 3;
        end
    end
    
    if menuUp() == true then
        CurrentPauseMenu = CurrentPauseMenu-1;
        if CurrentPauseMenu < 0 then
            CurrentPauseMenu = 0;
        end
    end
    
    if menuSelect() == true then        
        if CurrentPauseMenu == MENU_PAUSE_CONTINUE then
            CurrentMenu = MENU_NONE;
        elseif CurrentPauseMenu == MENU_PAUSE_RESTART then
            ChangeLevelOnNextUpdate(CurrentLevel);
            CurrentMenu = MENU_NONE;
        elseif CurrentPauseMenu == MENU_PAUSE_OPTIONS then 
            CurrentMenu = MENU_OPTIONS_PAUSED;
        elseif CurrentPauseMenu == MENU_PAUSE_EXIT then
            CurrentMenu = MENU_MAIN;
            AudioMan:FadeInMUS("Title", 1000, -1);
        end        
    end
    
    if menuBack() then
        CurrentMenu = MENU_NONE;
    end
end