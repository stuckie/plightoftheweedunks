-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/menus/mainMenu.lua");
dofile("data/scripts/menus/pauseMenu.lua");
dofile("data/scripts/menus/creditsMenu.lua");
dofile("data/scripts/menus/optionsMenu.lua");

MENU_NONE = 0;
MENU_MAIN = 1;
MENU_OPTIONS = 2;
MENU_PAUSE = 3;
MENU_CREDITS = 4;
MENU_OPTIONS_PAUSED = 5;
MENU_BONUS = 6;

CurrentMenu = MENU_MAIN;

function SetupMenus()   -- might want to tidy up so all menus arn't in memory at the same time and all the time
    MenuMainStory = Horde:AddResource( "Material", "menus/main/story.material.xml" );
    MenuMainBonus = Horde:AddResource( "Material", "menus/main/bonus.material.xml" );
    MenuMainCredits = Horde:AddResource( "Material", "menus/main/credits.material.xml" );
    MenuMainOptions = Horde:AddResource( "Material", "menus/main/options.material.xml" );
    MenuMainQuit = Horde:AddResource( "Material", "menus/main/quit.material.xml" );
    
    MenuPauseContinue = Horde:AddResource( "Material", "menus/pause/continue.material.xml" );
    MenuPauseRestart = Horde:AddResource( "Material", "menus/pause/restart.material.xml" );
    MenuPauseOptions = Horde:AddResource( "Material", "menus/pause/options.material.xml" );
    MenuPauseExit = Horde:AddResource( "Material", "menus/pause/exit.material.xml" );
    
    MenuOptionsBack = Horde:AddResource( "Material", "menus/options/back.material.xml" );
    MenuOptionsBackPause = Horde:AddResource( "Material", "menus/options/backPause.material.xml" );
    MenuOptionsBackground = Horde:AddResource( "Material", "menus/options/background.material.xml" );
    MenuOptionsBackgroundPause = Horde:AddResource( "Material", "menus/options/backgroundPause.material.xml" );
    MenuOptionsBar = Horde:AddResource( "Material", "menus/options/bar.material.xml" );
    MenuOptionsMusic = Horde:AddResource( "Material", "menus/options/music.material.xml" );
    MenuOptionsMusicPause = Horde:AddResource( "Material", "menus/options/musicPause.material.xml" );
    MenuOptionsSFX = Horde:AddResource( "Material", "menus/options/sfx.material.xml" );
    MenuOptionsSFXPause = Horde:AddResource( "Material", "menus/options/sfxPause.material.xml" );

    MenuCredits1 = Horde:AddResource( "Material", "menus/credits/1.material.xml" );
    MenuCredits2 = Horde:AddResource( "Material", "menus/credits/2.material.xml" );
end

function UpdateMenus()
	if CurrentMenu == MENU_MAIN then
		Update_MAINMENU();
	elseif CurrentMenu == MENU_PAUSE then
		Update_PAUSEMENU();
	elseif CurrentMenu == MENU_OPTIONS then
	    Update_OPTIONSMENU();
	elseif CurrentMenu == MENU_OPTIONS_PAUSED then
	    Update_OPTIONSMENU();
	elseif CurrentMenu == MENU_CREDITS then
	    Update_CREDITSMENU();
	end
end

menuUpHeld = false;
function menuUp()
    local tmp = false;
    if (ControlMan:Get_Up() or getDirection(GrandoControl, DIR_UP) or getDirection(KohiControl, DIR_UP) or ControlMan:Get_PadAxis(GrandoControl, 1)<-9850 or ControlMan:Get_PadAxis(KohiControl, 1)<-9850)
    and menuUpHeld == false then
        tmp = true;
        menuUpHeld = true;
        AudioMan:PlaySFX("menuSelect");
    end
    
    if
    not ControlMan:Get_Up()  and not getDirection(GrandoControl, DIR_UP) and not getDirection(KohiControl, DIR_UP) and ControlMan:Get_PadAxis(GrandoControl, 1)>-9850 and ControlMan:Get_PadAxis(KohiControl, 1)>-9850
    then
          menuUpHeld = false;  
    end
    
    return tmp;
end

menuDownHeld = false;
function menuDown()
    local tmp = false;
    if (ControlMan:Get_Down() or getDirection(GrandoControl, DIR_DOWN) or getDirection(KohiControl, DIR_DOWN) or ControlMan:Get_PadAxis(GrandoControl, 1)>9850 or ControlMan:Get_PadAxis(KohiControl, 1)>9850)
    and menuDownHeld == false then
        tmp = true;
        menuDownHeld = true;
        AudioMan:PlaySFX("menuSelect");
    end
    
    if
    not ControlMan:Get_Down() and not getDirection(GrandoControl, DIR_DOWN) and not getDirection(KohiControl, DIR_DOWN) and ControlMan:Get_PadAxis(GrandoControl, 1)<9850 and ControlMan:Get_PadAxis(KohiControl, 1)<9850
    then
          menuDownHeld = false;  
    end
    
    return tmp;
end

menuLeftHeld = false;
function menuLeft()
    local tmp = false;
    if (ControlMan:Get_Left() or getDirection(GrandoControl, DIR_LEFT) or getDirection(KohiControl, DIR_LEFT) or ControlMan:Get_PadAxis(GrandoControl, 0)<-9850 or ControlMan:Get_PadAxis(KohiControl, 0)<-9850)
    and menuLeftHeld == false then
        tmp = true;
        menuLeftHeld = true;
        AudioMan:PlaySFX("menuSelect");
    end
    
    if
    not ControlMan:Get_Left()  and not getDirection(GrandoControl, DIR_LEFT) and not getDirection(KohiControl, DIR_LEFT) and ControlMan:Get_PadAxis(GrandoControl, 0)>-9850 and ControlMan:Get_PadAxis(KohiControl, 0)>-9850
    then
          menuLeftHeld = false;  
    end
    
    return tmp;
end

menuRightHeld = false;
function menuRight()
    local tmp = false;
    if (ControlMan:Get_Right() or getDirection(GrandoControl, DIR_RIGHT) or getDirection(KohiControl, DIR_RIGHT) or ControlMan:Get_PadAxis(GrandoControl, 0)>9850 or ControlMan:Get_PadAxis(KohiControl, 0)>9850)
    and menuRightHeld == false then
        tmp = true;
        menuRightHeld = true;
        AudioMan:PlaySFX("menuSelect");
    end
    
    if
    not ControlMan:Get_Right()  and not getDirection(GrandoControl, DIR_RIGHT) and not getDirection(KohiControl, DIR_RIGHT) and ControlMan:Get_PadAxis(GrandoControl, 0)<9850 and ControlMan:Get_PadAxis(KohiControl, 0)<9850
    then
          menuRightHeld = false;  
    end
    
    return tmp;
end

menuSelectHeld = false;
function menuSelect()
    local tmp = false;
    if (ControlMan:Get_return() or ControlMan:Get_PadButton(GrandoControl, PS2_Cross) or ControlMan:Get_PadButton(KohiControl, PS2_Cross))
    and menuSelectHeld == false then
        tmp = true;
        menuSelectHeld = true;
        AudioMan:PlaySFX("menuChoose");
    end
    
    if
    not ControlMan:Get_return()  and not ControlMan:Get_PadButton(GrandoControl, PS2_Cross) and not ControlMan:Get_PadButton(KohiControl, PS2_Cross)
    then
          menuSelectHeld = false;  
    end
    
    return tmp;
end

menuBackHeld = false;
function menuBack()
    local tmp = false;
    if (ControlMan:Get_backspace() or ControlMan:Get_PadButton(GrandoControl, PS2_Circle) or ControlMan:Get_PadButton(KohiControl, PS2_Circle) or ControlMan:Get_PadButton(KohiControl, PS2_Triangle)or ControlMan:Get_PadButton(GrandoControl, PS2_Triangle))
    and menuBackHeld == false then
        tmp = true;
        menuBackHeld = true;
        AudioMan:PlaySFX("menuSelect");
    end
    
    if
    not ControlMan:Get_backspace()  and not ControlMan:Get_PadButton(GrandoControl, PS2_Circle) and not ControlMan:Get_PadButton(KohiControl, PS2_Circle) and not ControlMan:Get_PadButton(KohiControl, PS2_Triangle) and not ControlMan:Get_PadButton(GrandoControl, PS2_Triangle)
    then
          menuBackHeld = false;  
    end
    
    return tmp;
end

menuPauseHeld = false;
function menuPausePressed()
    local tmp = false;
    if (ControlMan:Get_p() or ControlMan:Get_PadButton(GrandoControl, PS2_Start) or ControlMan:Get_PadButton(KohiControl, PS2_Start))
    and menuPauseHeld == false then
        tmp = true;
        menuPauseHeld = true;
        AudioMan:PlaySFX("menuChoose");
    end
    
    if
    not ControlMan:Get_p()  and not ControlMan:Get_PadButton(GrandoControl, PS2_Start) and not ControlMan:Get_PadButton(KohiControl, PS2_Start)
    then
          menuPauseHeld = false;  
    end
    
    return tmp;
end



