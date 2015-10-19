-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/players/grando/moveGrandoDir.lua");

GrandoWeedunkTimer = 0.0;

function userMoveGrandoWeedunk()
	local rotChanged = false;
	local rotChangedTo = 0.0;

	if getDirection(GrandoControl, DIR_UPRIGHT) then					-- move charecter around
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0);
		moveGrandoFR(GrandoWeedunkMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_DOWNRIGHT) then
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		moveGrandoBR(GrandoWeedunkMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_DOWNLEFT) then
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		moveGrandoBL(GrandoWeedunkMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_UPLEFT) then
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		moveGrandoFL(GrandoWeedunkMoveForce * 0.7071);
	elseif getDirection(GrandoControl, DIR_UP) then
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		moveGrandoForward(GrandoWeedunkMoveForce);
	elseif getDirection(GrandoControl, DIR_DOWN) then
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		moveGrandoBackward(GrandoWeedunkMoveForce);
	elseif getDirection(GrandoControl, DIR_RIGHT) then
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		moveGrandoRight(GrandoWeedunkMoveForce);
	elseif getDirection(GrandoControl, DIR_LEFT) then
	    if GrandoWeedunkTimer >= 16 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		moveGrandoLeft(GrandoWeedunkMoveForce);
	else
	    if GrandoWeedunkTimer >= 40 then GrandoWeedunkTimer = 0; end
	    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 1.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 0.0); 
		Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
	end

	if gameCamera == 1 then
		rotChanged, rotChangedTo = ODE:ApplyAnalogueControl(
			GrandoWeedunkODE,						--player handle
			ControlMan:Get_PadAxis(GrandoControl, 0),		--y axis
			ControlMan:Get_PadAxis(GrandoControl, 1),		--x axis
			GrandoWeedunkMoveForce,					--max force to apply
			JoyAxisDeadZone,					--dead zone
			Camera:GetCamLookDir()				--camera facing dirrection
			);

		if rotChanged == true then
			GrandoWeedunkRot = rotChangedTo;
		end
		
		if ControlMan:Get_PadAxis(GrandoControl, 0)>9850 or ControlMan:Get_PadAxis(GrandoControl, 0)<-9850 or
		   ControlMan:Get_PadAxis(GrandoControl, 1)>9850 or ControlMan:Get_PadAxis(GrandoControl, 1)<-9850 then
		    Horde:SetModelAnimParams( GrandoWeedunk , 0, GrandoWeedunkTimer , 0.0); 
		    Horde:SetModelAnimParams( GrandoWeedunk , 1, GrandoWeedunkTimer , 1.0); 
		    Horde:SetModelAnimParams( GrandoWeedunk , 2, GrandoWeedunkTimer , 0.0); 
		end
	end

	--if getAction( GrandoControl, ACT_TRANSPLANT) then
	if getAction( GrandoControl, ACT_COMBINE) then
		GrandoControlingWeedunk = false;
		Horde:RemoveNodes(GrandoBrainMod);
	end
	
	GrandoWeedunkTimer = GrandoWeedunkTimer + 1.0;
end
