-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

function moveGrandoNorth(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, 0.0, 0.0, -f);
		GrandoWeedunkRot = 180.0;
	else
		ODE:ApplyForce(GrandoODE, 0.0, 0.0, -f);
		GrandoRot = 180.0
	end
end

function moveGrandoSouth(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, 0.0, 0.0, f);
		GrandoWeedunkRot = 0.0;
	else
		ODE:ApplyForce(GrandoODE, 0.0, 0.0, f);
		GrandoRot = 0.0;
	end

end

function moveGrandoEast(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, f, 0.0, 0.0);
		GrandoWeedunkRot = 270.0;
	else
		ODE:ApplyForce(GrandoODE, f, 0.0, 0.0);
		GrandoRot = 270.0;
	end
end

function moveGrandoWest(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, -f, 0.0, 0.0);
		GrandoWeedunkRot = 90.0;
	else
		ODE:ApplyForce(GrandoODE, -f, 0.0, 0.0);
		GrandoRot = 90.0;
	end
end

function moveGrandoNE(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, f, 0.0, -f);
		GrandoWeedunkRot = 225.0;
	else
		ODE:ApplyForce(GrandoODE, f, 0.0, -f);
		GrandoRot = 225.0;
	end
end

function moveGrandoNW(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, -f, 0.0, -f);
		GrandoWeedunkRot = 135.0;
	else
		ODE:ApplyForce(GrandoODE, -f, 0.0, -f);
		GrandoRot = 135.0;
	end
end

function moveGrandoSE(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, f, 0.0, f);
		GrandoWeedunkRot = 315.0;
	else
		ODE:ApplyForce(GrandoODE, f, 0.0, f);
		GrandoRot = 315.0;
	end
end

function moveGrandoSW(f)
	if GrandoControlingWeedunk == true then
		ODE:ApplyForce(GrandoWeedunkODE, -f, 0.0, f);
		GrandoWeedunkRot = 45.0;
	else
		ODE:ApplyForce(GrandoODE, -f, 0.0, f);
		GrandoRot = 45.0;
	end
end

