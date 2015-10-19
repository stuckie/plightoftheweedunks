function WeedunkErnieHitsdoor()
	ODE:Hit();
end

function WeedunkErnieHitstoothysTeeth()
	ODE:Hit();
end

function WeedunkErnieHitstoothysFloor()
	ODE:Hit();
end

function WeedunkErnieHitsconveyorBeltBoundary()
	ODE:Hit();
end

function WeedunkErnieHitstoothysWall()
	ODE:Hit();
end

function WeedunkErnieHitsconveyorForceSouth()
	ODE:Hit();
	if doorOpen==true then
		ODE:ApplyHitForce(0.0, 0.0, -weedunkConveryorForce);
	end
end

function WeedunkErnieHitsweedunkConverForce()
	ODE:Hit();
	if doorOpen==true then
		ODE:ApplyHitForce(0.0, 10.0, -weedunkConveryorForce);
	end
end
