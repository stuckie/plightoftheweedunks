-- Plight of The Weedunks
-- (c) Team Caffiene 2008
--------------------------

--------------------------
--   Pad Configuration  --
--------------------------

-- These correspond to what the Game Controller config says in Windows
-- To setup, just change the button numbers to what the config window states
-- HOWEVER, remove 1 from this number as SDL buttons counts from 0 rather than 1

-- Buttons are the the four face buttons ( /\ O [] X ) in a WASD layout, the four shoulder buttons, start, select, analogue clicks and two implementations of D-PAD ( HAT and PAD buttons )
-- Analog Stick 1 (X/Y and Z axes) is used for analog control

-- The pads are setup for the default PS2 controller along with a USB adapter.. so change these at your own risk

PS2_Triangle = 0;
PS2_Circle = 1;
PS2_Cross = 2;
PS2_Square = 3;
PS2_L2 = 4;
PS2_R2 = 5;
PS2_L1 = 6;
PS2_R1 = 7;
PS2_Select = 8;
PS2_Start = 9;
PS2_L3 = 10;
PS2_R3 = 11;

PS2_PAD_UP = 12;
PS2_PAD_RIGHT = 13;
PS2_PAD_DOWN = 14;
PS2_PAD_LEFT = 15;

PS2_HAT_UP = 1;
PS2_HAT_UPRIGHT = 3;
PS2_HAT_RIGHT = 2;
PS2_HAT_DOWNRIGHT = 6;
PS2_HAT_DOWN = 4;
PS2_HAT_DOWNLEFT = 12;
PS2_HAT_LEFT = 8;
PS2_HAT_UPLEFT = 9;