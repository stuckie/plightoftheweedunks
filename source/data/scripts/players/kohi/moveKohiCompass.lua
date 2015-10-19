-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

function moveKohiNorth(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, 0.0, 0.0, -f);
		KohiWeedunkRot = 180.0;
	else
		ODE:ApplyForce(KohiODE, 0.0, 0.0, -f);
		KohiRot = 180.0
	end
end

function moveKohiSouth(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, 0.0, 0.0, f);
		KohiWeedunkRot = 0.0;
	else
		ODE:ApplyForce(KohiODE, 0.0, 0.0, f);
		KohiRot = 0.0;
	end

end

function moveKohiEast(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, f, 0.0, 0.0);
		KohiWeedunkRot = 270.0;
	else
		ODE:ApplyForce(KohiODE, f, 0.0, 0.0);
		KohiRot = 270.0;
	end
end

function moveKohiWest(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, -f, 0.0, 0.0);
		KohiWeedunkRot = 90.0;
	else
		ODE:ApplyForce(KohiODE, -f, 0.0, 0.0);
		KohiRot = 90.0;
	end
end

function moveKohiNE(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, f, 0.0, -f);
		KohiWeedunkRot = 225.0;
	else
		ODE:ApplyForce(KohiODE, f, 0.0, -f);
		KohiRot = 225.0;
	end
end

function moveKohiNW(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, -f, 0.0, -f);
		KohiWeedunkRot = 135.0;
	else
		ODE:ApplyForce(KohiODE, -f, 0.0, -f);
		KohiRot = 135.0;
	end
end

function moveKohiSE(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, f, 0.0, f);
		KohiWeedunkRot = 315.0;
	else
		ODE:ApplyForce(KohiODE, f, 0.0, f);
		KohiRot = 315.0;
	end
end

function moveKohiSW(f)
	if KohiControlingWeedunk == true then
		ODE:ApplyForce(KohiWeedunkODE, -f, 0.0, f);
		KohiWeedunkRot = 45.0;
	else
		ODE:ApplyForce(KohiODE, -f, 0.0, f);
		KohiRot = 45.0;
	end
end

