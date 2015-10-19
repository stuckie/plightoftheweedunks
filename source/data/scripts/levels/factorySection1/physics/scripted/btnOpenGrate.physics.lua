-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnOpenGrate.
function btnOpenGrate_OBJECT ()
	btnOpenGrate_scripted = ODE:CreateMovingBox( 1, 0.1, 1, 60.55, -0.4, 57.327, 0, -90, 0, "btnOpenGrate" );
	btnOpenGrate_posX = 60.55;
	btnOpenGrate_posY = -0.4;
	btnOpenGrate_posZ = 57.327;
	btnOpenGrate_rotX = 0;
	btnOpenGrate_rotY = -90;
	btnOpenGrate_rotZ = 0;
	
	btnOpenGrateMod = Horde:AddNodes ( 0, ButtonRes );
    Horde:SetupModelAnimStage(btnOpenGrateMod, 0, WeedunkPortalAnim, "", false);
    Horde:SetNodeTransform( btnOpenGrateMod, btnOpenGrate_posX, btnOpenGrate_posY, btnOpenGrate_posZ, 0,0,0 ,1,1,1 );
end

