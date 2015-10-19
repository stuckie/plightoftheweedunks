creditsCnt = 0;

function Update_CREDITSMENU()
    if menuBack() == true then 
        CurrentMenu = MENU_MAIN;
    end
    
    creditsCnt = creditsCnt + 1;
    if creditsCnt > 1000 then
        creditsCnt=0;
    end
    
    if creditsCnt < 500 then
    	Horde:ShowOverlay(0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 7, MenuCredits1 );
    elseif creditsCnt < 1000 then
    	Horde:ShowOverlay(0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 7, MenuCredits2 );
    end
end
