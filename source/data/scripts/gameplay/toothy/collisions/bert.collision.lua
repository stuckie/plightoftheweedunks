-- Plight of the Weedunks

function WeedunkBertHitsdoor()
	ODE:Hit();
end

function WeedunkBertHitstoothysTeeth()
	ODE:Hit();
end

function WeedunkBertHitstoothysFloor()
	ODE:Hit();
end

function WeedunkBertHitsconveyorBeltBoundary()
	ODE:Hit();
end

function WeedunkBertHitstoothysWall()
	ODE:Hit();
end

function WeedunkBertHitsconveyorForceSouth()
	ODE:Hit();
	if doorOpen==true then
		ODE:ApplyHitForce(0.0, 0.0, -weedunkConveryorForce);
	end
end

function WeedunkBertHitsweedunkConverForce()
	ODE:Hit();
	if doorOpen==true then
		ODE:ApplyHitForce(0.0, 10.0, -weedunkConveryorForce);
	end
end