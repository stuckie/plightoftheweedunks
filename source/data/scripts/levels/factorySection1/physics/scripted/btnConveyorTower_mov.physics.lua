-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

-- Physics Information for btnConveyorTower_mov.
function btnConveyorTower_mov_OBJECT ()
	btnConveyorTower_mov_scripted = ODE:CreateMovingBox( 1, 0.1, 1, -26.7667, 5.19414, 43.2609, 0, 90, -0, "btnConveyorTower" );
	btnConveyorTower_mov_posX = -26.7667;
	btnConveyorTower_mov_posY = 5.19414;
	btnConveyorTower_mov_posZ = 43.2609;
	btnConveyorTower_mov_rotX = 0;
	btnConveyorTower_mov_rotY = 90;
	btnConveyorTower_mov_rotZ = -0;
	
	btnConveyorTowerMod = Horde:AddNodes ( 0, ButtonRes );
    Horde:SetupModelAnimStage(btnConveyorTowerMod, 0, WeedunkPortalAnim, "", false);
    Horde:SetNodeTransform( btnConveyorTowerMod, btnConveyorTower_mov_posX, btnConveyorTower_mov_posY, btnConveyorTower_mov_posZ, 0,0,0 ,1,1,1 );
end

