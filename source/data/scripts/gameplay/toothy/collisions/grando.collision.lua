function GrandoHitsdoor()
	ODE:Hit();
	if doorOpen == false then
	    openDoor = true;
	end
end

function GrandoHitstoothysTeeth()
	ODE:Hit();
end

function GrandoHitstoothysFloor()
	ODE:Hit();
end

function GrandoHitsconveyorBeltBoundary()
	ODE:Hit();
end

function GrandoHitstoothysWall()
	ODE:Hit();
end

function GrandoHitsloadFactoryLevel()
	GrandoHitsNextLevel = true;
end

function GrandoHitsconveyorForceSouth()
	ODE:Hit();
	if doorOpen==true then
		ODE:ApplyHitForce(0.0, 0.0, -converyorForce);
	end
end
