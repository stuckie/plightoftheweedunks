-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile("data/scripts/camera/gameCamera.lua");
dofile("data/scripts/camera/debugCamera.lua");

debugCamera = 0;
gameCamera = 1;

function UpdateCamera()
	if ControlMan:Get_F12()==true and gameCamera == 1 then
		Camera:TurnOnFreeCam();
		debugCamera = 1;
		gameCamera = 0;
	end

	if ControlMan:Get_F11()==true and debugCamera == 1 then
		Camera:TurnOnGameCam();
		debugCamera = 0;
		gameCamera = 1;
	end

	if gameCamera == 1 then
	    if GrandoInLimbo > 0 and KohiInLimbo > 0 then
	        Camera:FitPointsInView(0,0,0,0,0,0);
	    else
		    gameCameraUpdate(PlayerOneModel,PlayerTwoModel);
		end
	elseif debugCamera == 1 then
		debugCameraUpdate();
	end

	Camera:Update();
end
