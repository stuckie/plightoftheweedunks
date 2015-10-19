-- Plight of The Weedunks
-- (c) Team Caffiene 2008
-------------------------- 
MENU_MAIN_STORY = 0;
MENU_MAIN_BONUS = 1;
MENU_MAIN_OPTIONS = 2;
MENU_MAIN_CREDITS = 3;

CurrentMainMenu = MENU_MAIN_STORY;
MainMenuQuit = false;

function Update_MAINMENU()	  
    drawMainMenu();
    userInteractMainMenu();
end

function drawMainMenu()
    if MainMenuQuit == true then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuMainQuit );
        return;
    end
    
    if CurrentMainMenu == MENU_MAIN_STORY then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuMainStory );
    elseif CurrentMainMenu == MENU_MAIN_BONUS then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuMainBonus );
    elseif CurrentMainMenu == MENU_MAIN_OPTIONS then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuMainOptions );
    elseif CurrentMainMenu == MENU_MAIN_CREDITS then
	    Horde:ShowOverlay(0, 0, 0, 0.1885, -- bot left
                          1, 0, 1, 0.1885, -- top left
                          1, 1, 1, 0.8125, -- top right
                          0, 1, 0, 0.8125, -- bot right
                          2, MenuMainCredits );
    else
        CurrentMainMenu = MENU_MAIN_STORY;
    end
end

function userInteractMainMenu()
    if menuUp() == true and MainMenuQuit == true then
        MainMenuQuit = false;
    end
    if menuDown() == true and MainMenuQuit == false then
        MainMenuQuit = true;
    end

    if menuRight() == true and MainMenuQuit == false then
        CurrentMainMenu = CurrentMainMenu+1;
        if CurrentMainMenu > 3 then
            CurrentMainMenu = 3;
        end
    end
    
    if menuLeft() == true and MainMenuQuit == false then
        CurrentMainMenu = CurrentMainMenu-1;
        if CurrentMainMenu < 0 then
            CurrentMainMenu = 0;
        end
    end
    
    if menuSelect() == true then
        if MainMenuQuit == true then
            Interpret:Quit();
            return;
        end
        
        if CurrentMainMenu == MENU_MAIN_STORY then
            ChangeLevel("Toothy");            
            CurrentMenu = MENU_NONE;
        elseif CurrentMainMenu == MENU_MAIN_BONUS then
            --CurrentMenu = MENU_BONUS;
        elseif CurrentMainMenu == MENU_MAIN_OPTIONS then
            CurrentMenu = MENU_OPTIONS;
        elseif CurrentMainMenu == MENU_MAIN_CREDITS then
		    CurrentMenu = MENU_CREDITS;
        end        
    end
end
