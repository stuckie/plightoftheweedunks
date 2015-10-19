-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/players/kohi/moveKohiDir.lua");

KohiWeedunkTimer = 0.0;

function userMoveKohiWeedunk()
	local rotChanged = false;
	local rotChangedTo = 0.0;

	if getDirection(KohiControl, DIR_UPRIGHT) then					-- move character around
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiFR(KohiWeedunkMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_DOWNRIGHT) then
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiBR(KohiWeedunkMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_DOWNLEFT) then
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiBL(KohiWeedunkMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_UPLEFT) then
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiFL(KohiWeedunkMoveForce * 0.7071);
	elseif getDirection(KohiControl, DIR_UP) then
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiForward(KohiWeedunkMoveForce);
	elseif getDirection(KohiControl, DIR_DOWN) then
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiBackward(KohiWeedunkMoveForce);
	elseif getDirection(KohiControl, DIR_RIGHT) then
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiRight(KohiWeedunkMoveForce);
	elseif getDirection(KohiControl, DIR_LEFT) then
	    if KohiWeedunkTimer >= 16 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0);
		moveKohiLeft(KohiWeedunkMoveForce);
	else
	    if KohiWeedunkTimer >= 40 then KohiWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0); 
	end

	if gameCamera == 1 then
		rotChanged, rotChangedTo = ODE:ApplyAnalogueControl(
			KohiWeedunkODE,						    -- player handle
			ControlMan:Get_PadAxis(KohiControl, 0),	-- y axis
			ControlMan:Get_PadAxis(KohiControl, 1),	-- x axis
			KohiWeedunkMoveForce,					-- max force to apply
			JoyAxisDeadZone,					    -- dead zone
			Camera:GetCamLookDir()				    -- camera facing dirrection
			);

		if rotChanged == true then
			KohiWeedunkRot = rotChangedTo;
		end
		
		if ControlMan:Get_PadAxis(KohiControl, 0)>9850 or ControlMan:Get_PadAxis(KohiControl, 0)<-9850 or
		   ControlMan:Get_PadAxis(KohiControl, 1)>9850 or ControlMan:Get_PadAxis(KohiControl, 1)<-9850 then
		    Horde:SetModelAnimParams( KohiWeedunk , 0, KohiWeedunkTimer , 0.0); 
		    Horde:SetModelAnimParams( KohiWeedunk , 1, KohiWeedunkTimer , 1.0); 
		    Horde:SetModelAnimParams( KohiWeedunk , 2, KohiWeedunkTimer , 0.0); 
		end
	end

	--if getAction( KohiControl, ACT_TRANSPLANT) then
	if getAction( KohiControl, ACT_COMBINE) then
		changeKohiAnimations(KohiAnimIdle, KohiAnimIdle);
	    Horde:RemoveNodes(KohiBellMod);
	    KohiBellMod = Horde:AddNodes(KohiBellNode, KohiBellRes);
		KohiControlingWeedunk = false;
	end
	
	KohiWeedunkTimer = KohiWeedunkTimer + 1.0;
end
