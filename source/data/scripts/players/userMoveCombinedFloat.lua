function userMoveCombinedFloat()
	if getDirection(KohiControl, DIR_UPRIGHT) then					-- move charecter around
		moveKohiFR(combinedHMoveF * 0.7071);
		moveGrandoFR(combinedHMoveF * 0.7071);
	elseif getDirection(KohiControl, DIR_DOWNRIGHT) then
		moveKohiBR(combinedHMoveF * 0.7071);	
		moveGrandoBR(combinedHMoveF * 0.7071);	
	elseif getDirection(KohiControl, DIR_DOWNLEFT) then
		moveKohiBL(combinedHMoveF * 0.7071);	
		moveGrandoBL(combinedHMoveF * 0.7071);	
	elseif getDirection(KohiControl, DIR_UPLEFT) then
		moveKohiFL(combinedHMoveF * 0.7071);	
		moveGrandoFL(combinedHMoveF * 0.7071);	
	elseif getDirection(KohiControl, DIR_UP) then
		moveKohiForward(combinedHMoveF);
		moveGrandoForward(combinedHMoveF);
	elseif getDirection(KohiControl, DIR_DOWN) then
		moveKohiBackward(combinedHMoveF);
		moveGrandoBackward(combinedHMoveF);
	elseif getDirection(KohiControl, DIR_RIGHT) then
		moveKohiRight(combinedHMoveF);
		moveGrandoRight(combinedHMoveF);
	elseif getDirection(KohiControl, DIR_LEFT) then
		moveKohiLeft(combinedHMoveF);
		moveGrandoLeft(combinedHMoveF);
	end
	
	if getDirection(GrandoControl, DIR_UPRIGHT) then					-- move charecter around
		moveKohiFR(combinedHMoveF * 0.7071);
		moveGrandoFR(combinedHMoveF * 0.7071);
	elseif getDirection(GrandoControl, DIR_DOWNRIGHT) then
		moveKohiBR(combinedHMoveF * 0.7071);	
		moveGrandoBR(combinedHMoveF * 0.7071);	
	elseif getDirection(GrandoControl, DIR_DOWNLEFT) then
		moveKohiBL(combinedHMoveF * 0.7071);	
		moveGrandoBL(combinedHMoveF * 0.7071);	
	elseif getDirection(GrandoControl, DIR_UPLEFT) then
		moveKohiFL(combinedHMoveF * 0.7071);	
		moveGrandoFL(combinedHMoveF * 0.7071);	
	elseif getDirection(GrandoControl, DIR_UP) then
		moveKohiForward(combinedHMoveF);
		moveGrandoForward(combinedHMoveF);
	elseif getDirection(GrandoControl, DIR_DOWN) then
		moveKohiBackward(combinedHMoveF);
		moveGrandoBackward(combinedHMoveF);
	elseif getDirection(GrandoControl, DIR_RIGHT) then
		moveKohiRight(combinedHMoveF);
		moveGrandoRight(combinedHMoveF);
	elseif getDirection(GrandoControl, DIR_LEFT) then
		moveKohiLeft(combinedHMoveF);
		moveGrandoLeft(combinedHMoveF);
	end
	
	if gameCamera == 1 then
		ODE:ApplyAnalogueControl(	
			GrandoODE,							--player handle
			ControlMan:Get_PadAxis(KohiControl, 0),			--y axis
			ControlMan:Get_PadAxis(KohiControl, 1),			--x axis
			combinedHMoveF,						--max force to apply
			JoyAxisDeadZone,						--dead zone
			Camera:GetCamLookDir()					--camera facing direction
		);
		ODE:ApplyAnalogueControl(	
			KohiODE,								--player handle
			ControlMan:Get_PadAxis(KohiControl, 0),			--y axis
			ControlMan:Get_PadAxis(KohiControl, 1),			--x axis
			combinedHMoveF,						--max force to apply
			JoyAxisDeadZone,						--dead zone
			Camera:GetCamLookDir()					--camera facing direction
		);
		ODE:ApplyAnalogueControl(	
			GrandoODE,							--player handle
			ControlMan:Get_PadAxis(GrandoControl, 0),		--y axis
			ControlMan:Get_PadAxis(GrandoControl, 1),		--x axis
			combinedHMoveF,						--max force to apply
			JoyAxisDeadZone,						--dead zone
			Camera:GetCamLookDir()					--camera facing direction
		);
		ODE:ApplyAnalogueControl(	
			KohiODE,								--player handle
			ControlMan:Get_PadAxis(GrandoControl, 0),		--y axis
			ControlMan:Get_PadAxis(GrandoControl, 1),		--x axis
			combinedHMoveF,						--max force to apply
			JoyAxisDeadZone,						--dead zone
			Camera:GetCamLookDir()					--camera facing direction
		);
	end
end