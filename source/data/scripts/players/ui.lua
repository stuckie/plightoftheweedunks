UIHeight = 0.375;
UIWidth = 0.275;
GrandoRightClip = 0.7;
GrandoBotClip = 0.25;
KohiLeftClip = 0.3;
KohiBotClip = 0.25;

function LoadUI()
	KohiUIControl = Horde:AddResource( "Material", "ui/Kohi/bell_weedunk_solid.material.xml" );
	KohiUICircle = Horde:AddResource( "Material", "ui/Kohi/circle_button_solid.material.xml" );
	KohiUICircleT = Horde:AddResource( "Material", "ui/Kohi/circle_button_trans.material.xml" );
	KohiUICombine = Horde:AddResource( "Material", "ui/Kohi/combine.material.xml" );
	KohiUIFrame = Horde:AddResource( "Material", "ui/Kohi/frame_solid.material.xml" );
	KohiUIFrameT = Horde:AddResource( "Material", "ui/Kohi/frame_trans.material.xml" );
	KohiUIWithWeedunk = Horde:AddResource( "Material", "ui/Kohi/holding_weedunk.material.xml" );
	KohiUIKohi = Horde:AddResource( "Material", "ui/Kohi/kohi_solid.material.xml" );
	KohiUIKohiT = Horde:AddResource( "Material", "ui/Kohi/kohi_trans.material.xml" );
	KohiUIPickUp = Horde:AddResource( "Material", "ui/Kohi/pick_up.material.xml" );
	KohiUITarget = Horde:AddResource( "Material", "ui/Kohi/R2_button_solid.material.xml" );
	KohiUITargetT = Horde:AddResource( "Material", "ui/Kohi/R2_button_trans.material.xml" );
	KohiUIRelease = Horde:AddResource( "Material", "ui/Kohi/release.material.xml" );
	KohiUISquare = Horde:AddResource( "Material", "ui/Kohi/square_solid.material.xml" );
	KohiUISquareT = Horde:AddResource( "Material", "ui/Kohi/square_trans.material.xml" );
	KohiUITargetting = Horde:AddResource( "Material", "ui/Kohi/target_grando.material.xml" );
	KohiUIThrow = Horde:AddResource( "Material", "ui/Kohi/throw.material.xml" );
	KohiUITransplant = Horde:AddResource( "Material", "ui/Kohi/transplant.material.xml" );
	KohiUITriangle = Horde:AddResource( "Material", "ui/Kohi/triangle_button_solid.material.xml" );
	KohiUITriangleT = Horde:AddResource( "Material", "ui/Kohi/triangle_button_trans.material.xml" );
	KohiUIGrandoTarget = Horde:AddResource( "Material", "ui/Kohi/grando_target.material.xml" );
	KohiUIP1 = Horde:AddResource( "Material", "ui/Kohi/power_meter/1.material.xml" );
	KohiUIP2 = Horde:AddResource( "Material", "ui/Kohi/power_meter/2.material.xml" );
	KohiUIP3 = Horde:AddResource( "Material", "ui/Kohi/power_meter/3.material.xml" );
	KohiUIP4 = Horde:AddResource( "Material", "ui/Kohi/power_meter/4.material.xml" );
	KohiUIP5 = Horde:AddResource( "Material", "ui/Kohi/power_meter/5.material.xml" );
	KohiUIP6 = Horde:AddResource( "Material", "ui/Kohi/power_meter/6.material.xml" );
	KohiUIP7 = Horde:AddResource( "Material", "ui/Kohi/power_meter/7.material.xml" );
	KohiUIP8 = Horde:AddResource( "Material", "ui/Kohi/power_meter/8.material.xml" );
	KohiUIP9 = Horde:AddResource( "Material", "ui/Kohi/power_meter/9.material.xml" );
	KohiUIPEmpty = Horde:AddResource( "Material", "ui/Kohi/power_meter/empty_trans.material.xml" );
	KohiUIPFull = Horde:AddResource( "Material", "ui/Kohi/power_meter/full.material.xml" );

	GrandoUIControl = Horde:AddResource( "Material", "ui/Grando/brain_weedunk_solid.material.xml" );
	GrandoUICircle = Horde:AddResource( "Material", "ui/Grando/circle_solid.material.xml" );
	GrandoUICircleT = Horde:AddResource( "Material", "ui/Grando/circle_trans.material.xml" );
	GrandoUICombine = Horde:AddResource( "Material", "ui/Grando/combine.material.xml" );
	GrandoUIFrame = Horde:AddResource( "Material", "ui/Grando/frame_solid.material.xml" );
	GrandoUIFrameT = Horde:AddResource( "Material", "ui/Grando/frame_trans.material.xml" );
	GrandoUIGrando = Horde:AddResource( "Material", "ui/Grando/grando_solid.material.xml" );
	GrandoUIGrandoT = Horde:AddResource( "Material", "ui/Grando/grando_trans.material.xml" );
	GrandoUIWeedunk = Horde:AddResource( "Material", "ui/Grando/holding_weedunk_solid.material.xml" );
	GrandoUIPickUp = Horde:AddResource( "Material", "ui/Grando/pick_up.material.xml" );
	GrandoUITarget = Horde:AddResource( "Material", "ui/Grando/R2_solid.material.xml" );
	GrandoUITargetT = Horde:AddResource( "Material", "ui/Grando/R2_trans.material.xml" );
	GrandoUIRelease = Horde:AddResource( "Material", "ui/Grando/release.material.xml" );
	GrandoUISquare = Horde:AddResource( "Material", "ui/Grando/square_solid.material.xml" );
	GrandoUISquareT = Horde:AddResource( "Material", "ui/Grando/square_trans.material.xml" );
	GrandoUITargeting = Horde:AddResource( "Material", "ui/Grando/target_kohi.material.xml" );
	GrandoUIThrow = Horde:AddResource( "Material", "ui/Grando/throw.material.xml" );
	GrandoUITransplant = Horde:AddResource( "Material", "ui/Grando/transplant.material.xml" );
	GrandoUITriangle = Horde:AddResource( "Material", "ui/Grando/triangle_solid.material.xml" );
	GrandoUITriangleT = Horde:AddResource( "Material", "ui/Grando/triangle_trans.material.xml" );
	GrandoUIKohiTarget = Horde:AddResource( "Material", "ui/Grando/kohi_target.material.xml" );
	GrandoUIP1 = Horde:AddResource( "Material", "ui/Grando/Power_meter/1.material.xml" );
	GrandoUIP2 = Horde:AddResource( "Material", "ui/Grando/Power_meter/2.material.xml" );
	GrandoUIP3 = Horde:AddResource( "Material", "ui/Grando/Power_meter/3.material.xml" );
	GrandoUIP4 = Horde:AddResource( "Material", "ui/Grando/Power_meter/4.material.xml" );
	GrandoUIP5 = Horde:AddResource( "Material", "ui/Grando/Power_meter/5.material.xml" );
	GrandoUIP6 = Horde:AddResource( "Material", "ui/Grando/Power_meter/6.material.xml" );
	GrandoUIP7 = Horde:AddResource( "Material", "ui/Grando/Power_meter/7.material.xml" );
	GrandoUIP8 = Horde:AddResource( "Material", "ui/Grando/Power_meter/8.material.xml" );
	GrandoUIP9 = Horde:AddResource( "Material", "ui/Grando/Power_meter/9.material.xml" );
	GrandoUIPEmpty = Horde:AddResource( "Material", "ui/Grando/Power_meter/empty_trans.material.xml" );
	GrandoUIPFull = Horde:AddResource( "Material", "ui/Grando/Power_meter/full.material.xml" );

end 

function ShowUIOverlays()
    if KohiControlingWeedunk == true then
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 2, KohiUIFrame );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIControl );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITargetT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIRelease );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUISquareT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITriangle );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUICircleT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIPEmpty );
    elseif KohiAndGrandoCombinedCnt < KohiAndGrandoCombinedMax then
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 2, KohiUIFrame );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIKohi );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITargetT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUISquareT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITriangleT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUICircleT );
       kohiPower(1.0-(KohiAndGrandoCombinedCnt/KohiAndGrandoCombinedMax));
    elseif KohiCarryingWeedunk == true then
    
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 2, KohiUIFrame );
       if getAction(KohiControl, ACT_AIM) then
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 4, KohiUIGrandoTarget );
       else
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIWithWeedunk );
       end
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITarget );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITargetting );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUISquareT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUICircle );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIThrow );
       if KohiCanCombine == true then
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITriangle );
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUICombine );
       else
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITriangleT );
       end
       if KohiExploshionCnt<KohiFastMoveTime then
            kohiPower(1.0-(KohiExploshionCnt/KohiFastMoveTime));
       else
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIPEmpty );
       end
    elseif KohiBesideWeedunk == true then
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 2, KohiUIFrame );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIKohi );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITargetT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITransplant );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUISquare );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITriangleT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIPickUp );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUICircle );
       if KohiExploshionCnt<KohiFastMoveTime then
            kohiPower(1.0-(KohiExploshionCnt/KohiFastMoveTime));
       else
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIPEmpty );
       end
    else
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 2, KohiUIFrameT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIKohiT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITargetT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUISquareT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUITriangleT );
       Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUICircleT );
       if KohiExploshionCnt<KohiFastMoveTime then
            kohiPower(1.0-(KohiExploshionCnt/KohiFastMoveTime));
       else
            Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIPEmpty );
       end
    end

    if GrandoControlingWeedunk == true then
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 2, GrandoUIFrame );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIControl );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITargetT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUISquareT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIRelease );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITriangle );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICircleT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIPEmpty ); 
	elseif KohiAndGrandoCombinedCnt < KohiAndGrandoCombinedMax then
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 2, GrandoUIFrame );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIGrando );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITargetT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUISquareT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITriangleT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICircleT );
	    grandoPower(1.0 - (KohiAndGrandoCombinedCnt/KohiAndGrandoCombinedMax));
	elseif GrandoFloatCnt < GrandoFloatTimeMax then
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 2, GrandoUIFrame );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUISquareT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITriangle );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIRelease );
	    if GrandoCarryingWeedunk == true then
	        if getAction(GrandoControl, ACT_AIM) then
	            Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 4, GrandoUIKohiTarget );
	        else
	            Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIWeedunk );
	        end
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICircle );
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIThrow );
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITarget );
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITargeting );
	    else
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIGrando );
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICircleT );
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITargetT );
	    end
	    grandoPower(1.0 - (GrandoFloatCnt/GrandoFloatTimeMax));
	elseif GrandoCarryingWeedunk == true then 
        if getAction(GrandoControl, ACT_AIM) then
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 4, GrandoUIKohiTarget );
	    else
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIWeedunk );
	    end
 	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 2, GrandoUIFrame );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUISquareT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIPEmpty );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICircle );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIThrow );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITarget );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITargeting );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIPEmpty );
	    if GrandoCanCombine == true then
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITriangle );
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICombine );
	    else
	        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITriangleT );
	    end
	elseif GrandoBesideWeedunk == true then    
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 2, GrandoUIFrame );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIGrando );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITargetT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUISquare );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITransplant );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITriangleT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICircle );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIPickUp );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIPEmpty );
	else
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 2, GrandoUIFrameT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIGrandoT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITargetT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUISquareT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUITriangleT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUICircleT );
	    Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIPEmpty );
	end
    
end

function kohiPower( filled )
    if filled >0.9 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIPFull );
    elseif filled >0.8 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP9 );
    elseif filled >0.7 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP8 );
    elseif filled >0.6 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP7 );
    elseif filled >0.5 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP6 );
    elseif filled >0.4 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP5 );
    elseif filled >0.3 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP4 );
    elseif filled >0.2 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP3 );
    elseif filled >0.1 then
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP2 );
    else
        Horde:ShowOverlay(0, 0, KohiLeftClip, KohiBotClip, UIWidth, 0, 1, KohiBotClip, UIWidth, UIHeight, 1, 1, 0, UIHeight, KohiLeftClip, 1, 3, KohiUIP1 );
    end
end

function grandoPower( filled )
    if filled >0.9 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIPFull );
    elseif filled >0.8 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP9 );
    elseif filled >0.7 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP8 );
    elseif filled >0.6 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP7 );
    elseif filled >0.5 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP6 );
    elseif filled >0.4 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP5 );
    elseif filled >0.3 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP4 );
    elseif filled >0.2 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP3 );
    elseif filled >0.1 then
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP2 );
    else
        Horde:ShowOverlay(1.0-UIWidth, 0, 0, GrandoBotClip, 1, 0, GrandoRightClip, GrandoBotClip, 1, UIHeight, GrandoRightClip, 1, 1.0-UIWidth, UIHeight, 0, 1, 3, GrandoUIP1 );
    end
end
