function KohiHitsconveyorForceEast()
    ODE:ApplyHitForce(-conveyorForce, 0.0, 0.0);
    ODE:Hit();
end
function KohiHitsconveyorForceNorth()
    ODE:ApplyHitForce(0.0, 0.0, conveyorForce);
    ODE:Hit();
end
function KohiHitsconveyorForceSouth()
    ODE:ApplyHitForce(0.0, 0.0, -conveyorForce);
    ODE:Hit();
end
function KohiHitsconveyorForceWest()
    ODE:ApplyHitForce(conveyorForce, 0.0, 0.0);
    ODE:Hit();
end
function KohiHitsconveyorTower()
    ODE:Hit();
end
function KohiHitsdeathMincer()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, KohiDieParticleEffect);
    if KohiDead == false then
	    AudioMan:PlaySFX("kohiDeathMincer");
	end
    KohiDead = true;
end
function KohiHitsdeathTower()
	local x,y,z = ODE:GetPointOfContact();
	Horde:AddParticleEffect(x,y,z, KohiDieParticleEffect);
    KohiDead = true;
end
function KohiHitsmincer()
    ODE:Hit();
end
function KohiHitsbreakableWall()
    ODE:Hit();
end
function KohiHitshiddenStep1()
	ODE:Hit();
end
function KohiHitshiddenStep2()
	ODE:Hit();
end
function KohiHitshiddenStep3()
	ODE:Hit();
end
function KohiHitshiddenStep4()
	ODE:Hit();
end
function KohiHitshiddenStep5()
	ODE:Hit();
end
function KohiHitshiddenStep6()
	ODE:Hit();
end
function KohiHitshiddenStep7()
	ODE:Hit();
end
function KohiHitshiddenStep8()
	ODE:Hit();
end
function KohiHitshiddenStep9()
	ODE:Hit();
end
function KohiHitshiddenStep10()
	ODE:Hit();
end
function KohiHitshiddenStep11()
	ODE:Hit();
end
function KohiHitshiddenStep12()
	ODE:Hit();
end
function KohiHitshiddenStep13()
	ODE:Hit();
end
function KohiHitshiddenStep14()
	ODE:Hit();
end
function KohiHitshiddenStep15()
	ODE:Hit();
end
function KohiHitshiddenStep16()
	ODE:Hit();
end
function KohiHitsmulchPipe()
	ODE:Hit();
end
function KohiHitsbtnHiddenSteps()
	btnHiddenSteps_posY = 12;
	btnHiddenStepsPressed = true;
end
function KohiHitsbugStairsBreakableBoards()
	ODE:Hit();
end
function KohiHitsfloatingPlatform1()
	ODE:ApplyHitForce(-20.7, 0.0, 0.0);
	ODE:Hit();
end
function KohiHitsfloatingPlatform2()
	ODE:ApplyHitForce(-20.7, 0.0, 0.0);
	ODE:Hit();
end
function KohiHitsfloatingPlatform3()
	ODE:ApplyHitForce(-20.7, 0.0, 0.0);
	ODE:Hit();
end
function KohiHitsbreakableTunnelGrate()
	ODE:Hit();
end
function KohiHitsendOfLevelFactory1()
    kohiHitLoadSection2 = true;
end
function KohiHitsbtnOpenGrate()
	ODE:Hit();
	--openGrateButtonPressed = true;
end
