function GrandoHitsconveyorForceEast()
    ODE:ApplyHitForce(-conveyorForce, 0.0, 0.0);
    ODE:Hit();
end
function GrandoHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, conveyorForce);
    ODE:Hit();
end
function GrandoHitsconveyorForceSouth()
    ODE:ApplyHitForce(0.0, 0.0, -conveyorForce);
    ODE:Hit();
end
function GrandoHitsconveyorForceWest()
    ODE:ApplyHitForce(conveyorForce, 0.0, 0.0);
    ODE:Hit();
end
function GrandoHitsconveyorTower()
    ODE:Hit();
end
function GrandoHitsdeathMincer()
    if GrandoDead == false then
	    AudioMan:PlaySFX("grandoDeathMincer");
	end
    GrandoDead = true;
end
function GrandoHitsdeathTower()
    GrandoDead = true;
end
function GrandoHitsmincer()
    ODE:Hit();
end
function GrandoHitsbreakableWall()
    ODE:Hit();
end
function GrandoHitsbtnConveyorTower()
    ODE:Hit();
    conveyorTowerButtonPressed = true;
end
function GrandoHitshiddenStep1()
	ODE:Hit();
end
function GrandoHitshiddenStep2()
	ODE:Hit();
end
function GrandoHitshiddenStep3()
	ODE:Hit();
end
function GrandoHitshiddenStep4()
	ODE:Hit();
end
function GrandoHitshiddenStep5()
	ODE:Hit();
end
function GrandoHitshiddenStep6()
	ODE:Hit();
end
function GrandoHitshiddenStep7()
	ODE:Hit();
end
function GrandoHitshiddenStep8()
	ODE:Hit();
end
function GrandoHitshiddenStep9()
	ODE:Hit();
end
function GrandoHitshiddenStep10()
	ODE:Hit();
end
function GrandoHitshiddenStep11()
	ODE:Hit();
end
function GrandoHitshiddenStep12()
	ODE:Hit();
end
function GrandoHitshiddenStep13()
	ODE:Hit();
end
function GrandoHitshiddenStep14()
	ODE:Hit();
end
function GrandoHitshiddenStep15()
	ODE:Hit();
end
function GrandoHitshiddenStep16()
	ODE:Hit();
end
function GrandoHitsmulchPipe()
	ODE:Hit();
end
function GrandoHitsbtnHiddenSteps()
	btnHiddenSteps_posY = 12;
	btnHiddenStepsPressed = true;
end	
function GrandoHitsbugStairsBreakableBoards()
	ODE:Hit();
end
function GrandoHitsfloatingPlatform1()
	ODE:ApplyHitForce(-27.778, 0.0, 0.0);
	ODE:Hit();
end
function GrandoHitsfloatingPlatform2()
	ODE:ApplyHitForce(-27.778, 0.0, 0.0);
	ODE:Hit();
end
function GrandoHitsfloatingPlatform3()
	ODE:ApplyHitForce(-27.778, 0.0, 0.0);
	ODE:Hit();
end
function GrandoHitsbreakableTunnelGrate()
	ODE:Hit();
end
function GrandoHitsendOfLevelFactory1()
    grandoHitLoadSection2 = true;
end
function KohiHitsbtnOpenGrate()
	ODE:Hit();
	--openGrateButtonPressed = true;
end