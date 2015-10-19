-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnHiddenSteps.
function btnHiddenSteps_OBJECT ()
	btnHiddenSteps_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -26.7591, 14.3649, 159.57, 0, 90, -0, "btnHiddenSteps" );
	btnHiddenSteps_posX = -26.7591;
	btnHiddenSteps_posY = 14.3649;
	btnHiddenSteps_posZ = 159.57;
	btnHiddenSteps_rotX = 0;
	btnHiddenSteps_rotY = 90;
	btnHiddenSteps_rotZ = -0;
	
	btnHiddenStepsMod = Horde:AddNodes ( 0, ButtonRes );
    Horde:SetupModelAnimStage(btnHiddenStepsMod, 0, WeedunkPortalAnim, "", false);
    Horde:SetNodeTransform( btnHiddenStepsMod, btnHiddenSteps_posX, btnHiddenSteps_posY, btnHiddenSteps_posZ, 0,0,0 ,1,1,1 );
end

