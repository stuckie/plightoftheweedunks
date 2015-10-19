function KohiHitsdoor()
	ODE:Hit();
	if doorOpen == false then
	    openDoor = true;
	end
end

function KohiHitstoothysTeeth()
	ODE:Hit();
end

function KohiHitstoothysFloor()
	ODE:Hit();
end

function KohiHitsconveyorBeltBoundary()
	ODE:Hit();
end

function KohiHitstoothysWall()
	ODE:Hit();
end

function KohiHitsloadFactoryLevel()
	KohiHitsNextLevel = true;
end

function KohiHitsconveyorForceSouth()
	ODE:Hit();
	if doorOpen==true then
		ODE:ApplyHitForce(0.0, 0.0, -converyorForce);
	end
end