-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile ("data/scripts/controllers/controllerConfig.lua");

-- Leave These Variables Alone, Jonny! ;)
DIR_UP = 0;
DIR_LEFT = 1;
DIR_RIGHT = 2;
DIR_DOWN = 3;
DIR_UPLEFT = 4;
DIR_UPRIGHT = 5;
DIR_DOWNLEFT = 6;
DIR_DOWNRIGHT = 7;

ACT_JUMP = 1;
ACT_USE = 2;
ACT_COMBINE = 3;
ACT_TRANSPLANT = 4;
ACT_AIM = 5;
-- ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

function getDirection( player, direction )
	if direction == DIR_UPRIGHT then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_UPRIGHT then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_UP) and ControlMan:Get_PadButton(player, PS2_PAD_RIGHT) then
			return true;
		elseif player == 1 and ControlMan:Get_Up() and ControlMan:Get_Right() then
			return true;
		end

	elseif direction == DIR_DOWNRIGHT then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_DOWNRIGHT then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_DOWN) and ControlMan:Get_PadButton(player, PS2_PAD_RIGHT) then
			return true;
		elseif player == 1 and ControlMan:Get_Down() and ControlMan:Get_Right() then
			return true;
		end
        
	elseif direction == DIR_DOWNLEFT then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_DOWNLEFT then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_DOWN) and ControlMan:Get_PadButton(player, PS2_PAD_LEFT) then
			return true;
		elseif player == 1 and ControlMan:Get_Down() and ControlMan:Get_Left() then
			return true;
		end
        
	elseif direction == DIR_UPLEFT then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_UPLEFT then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_UP) and ControlMan:Get_PadButton(player, PS2_PAD_LEFT) then
			return true;
		elseif player == 1 and ControlMan:Get_Up() and ControlMan:Get_Left() then
			return true;
		end

        elseif direction == DIR_UP then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_UP then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_UP) then
			return true;
		elseif player == 1 and ControlMan:Get_Up() then
			return true;
		end
        
        elseif direction == DIR_DOWN then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_DOWN then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_DOWN) then
			return true;
		elseif player == 1 and ControlMan:Get_Down() then
			return true;
		end

        elseif direction == DIR_RIGHT then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_RIGHT then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_RIGHT) then
			return true;
		elseif player == 1 and ControlMan:Get_Right() then
			return true;
		end

        elseif direction == DIR_LEFT then
		if ControlMan:Get_PadHat(player, 0)==PS2_HAT_LEFT then
			return true;
		elseif ControlMan:Get_PadButton(player, PS2_PAD_LEFT) then
			return true;
		elseif player == 1 and ControlMan:Get_Left() then
			return true;
		end
        end

        return false;
end

function getAction( player, action )
	if action == ACT_JUMP then
		if ControlMan:Get_PadButton(player, PS2_Cross) then
			return true;
		elseif player == 1 and ControlMan:Get_s() then
			return true;
		end
		
	elseif action == ACT_USE then
		if ControlMan:Get_PadButton(player, PS2_Circle) then
			return true;
		elseif player ==1 and ControlMan:Get_d() then
			return true;
		end
		
	elseif action == ACT_COMBINE then
		if ControlMan:Get_PadButton(player, PS2_Triangle) then
			return true;
		elseif player == 1 and ControlMan:Get_w() then
			return true;
		end
		
	elseif action == ACT_TRANSPLANT then
		if ControlMan:Get_PadButton(player, PS2_Square) then
			return true;
		elseif player ==1 and ControlMan:Get_a() then
			return true;
		end
			
	elseif action == ACT_AIMOBJECT then
		if ControlMan:Get_PadButton(player, PS2_L1) then
			return true;
		elseif player == 1 and ControlMan:Get_q() then
			return true;
		end
		
	elseif action == ACT_AIMPLAYER then
		if ControlMan:Get_PadButton(player, PS2_R1) then
			return true;
		elseif player == 1 and ControlMan:Get_e() then
			return true;
		end
		
    elseif action == ACT_AIM then
		if ControlMan:Get_PadButton(player, PS2_R1) then
			return true;
		end
		if ControlMan:Get_PadButton(player, PS2_R2) then
			return true;
		end
		if ControlMan:Get_PadButton(player, PS2_L1) then
			return true;
		end
		if ControlMan:Get_PadButton(player, PS2_L2) then
			return true;
		end
	end

	return false;
end
