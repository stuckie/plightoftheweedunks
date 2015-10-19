-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

function gameCameraUpdate(obj1, obj2)
--[[	obj1X, obj1Y, obj1Z = Horde:GetNodeTransform(obj1);
	obj2X, obj2Y, obj2Z = Horde:GetNodeTransform(obj2);]]--
	obj1X, obj1Y, obj1Z = ODE:GetDynamicPos(obj1);
	obj2X, obj2Y, obj2Z = ODE:GetDynamicPos(obj2);
	
	Camera:FitPointsInView(obj1X, obj1Y, obj1Z , obj2X, obj2Y, obj2Z );
end