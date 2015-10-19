-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

function debugCameraUpdate()
	if ControlMan:Get_PadAxis(1, 1)>10000 or ControlMan:Get_PadAxis(2, 1)>10000 or ControlMan:Get_s() == true then
		Camera:Backward(1.0);
	end
	if ControlMan:Get_PadAxis(1, 1)<-10000 or ControlMan:Get_PadAxis(2, 1)<-10000 or ControlMan:Get_w() == true then
		Camera:Forward(1.0);
	end
	
	if ControlMan:Get_PadAxis(1, 0)<-10000 or ControlMan:Get_PadAxis(2, 0)<-10000 or ControlMan:Get_a() == true then
		Camera:Left(1.0);
	end
	if ControlMan:Get_PadAxis(1, 0)>10000 or ControlMan:Get_PadAxis(2, 0)>10000 or ControlMan:Get_d() == true then
		Camera:Right(1.0);
	end
	
	if ControlMan:Get_PadAxis(1, 2)<-10000 or ControlMan:Get_PadAxis(2, 2)<-10000 or ControlMan:Get_Up() == true then
		Camera:RotateAroundX(-1.0);
	end
	if ControlMan:Get_PadAxis(1, 2)>10000 or ControlMan:Get_PadAxis(2, 2)>10000 or ControlMan:Get_Down() == true then
		Camera:RotateAroundX(1.0);
	end	

	if ControlMan:Get_PadAxis(1, 3)<-10000 or ControlMan:Get_PadAxis(2, 3)<-10000 or ControlMan:Get_Left() == true then
		Camera:RotateAroundY(1.0);
	end
	if ControlMan:Get_PadAxis(1, 3)>10000 or ControlMan:Get_PadAxis(2, 3)>10000 or ControlMan:Get_Right() == true then
		Camera:RotateAroundY(-1.0);
	end
end