-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

dofile ("data/scripts/controllers/controllerConfig.lua");

--------------------------
--  Physics Properties  --
--------------------------

g = -70;					-- Gravity for the world
kohiExploshionForce = 750;
weedunkSpawnForce = 0.1;
normalDamping = 0.7         -- the higher the value the more slipping ocours
weedunkCullDist = 20.0;
weedunkCullDistSquared = weedunkCullDist*weedunkCullDist;

-------------------------
--   Player Properties  --
--------------------------

KohiMoveForce = 50;
KohiJumpForce = 500;
KohiThrowForce = 300;
KohiFastMoveForce = 70;
KohiFastMoveTime = 50;
KohiWeedunkMoveForce = 5;

GrandoMoveForce = 50;
GrandoJumpForce = 500;
GrandoThrowForce = 300;
GrandoWeedunkMoveForce = 5;

GrandoRocketForce = 1150;
GrandoFloatTimeMax = 400;
GrandoFloatBoost = 12;           -- the amount added to move grando up
GrandoFloatMoveForce = 40;      -- grandos horizontal move force durring float
GrandoFloatTimeLoss = 2;        -- the time loss for when boosting, this is added to 1 which is the common time loss
GrandoMaxVertVelFloating = 2.5;
grandoConstantFloatForce = 34.1;

GrandoHMoveRedMinSpeed = 1;	-- the speed which the reduction in horizontal speed is applied
GrandoHMoveRedSpeed = 100;	-- the force to apply when the player is in the reduced speed
KohiHMoveRedMinSpeed = 1;	-- the speed which the reduction in horizontal speed is applied
KohiHMoveRedSpeed = 100;	-- the force to apply when the player is in the reduced speed

KohiAndGrandoCombinedMax = 250;
combinedHMoveF = 35;

timeBetweenPickupAndThrow = 25	-- the min time between a player picking up a weedunk and throwing it

---------------------------
--    Level Properties   --
---------------------------

StartLevel = "Factory";

---------------------------
--  Renderer Properties  --
---------------------------

HordeDebugView = 0;				-- 1 - on / 0 - off
HordeWireframeView = 0;			-- 1 - on / 0 - off

---------------------------
-- Controller Properties --
---------------------------

JoyAxisDeadZone = 0.3;			-- float from 0 -> 1.0 .. percentage of stick as "dead"

-------------
-- Cheats --
-------------

iceRink = false;		-- turn on the ice :)
