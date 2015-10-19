Plight of the Weedunks
----------------------

Min Sys Reqs:
For Windows - 2Ghz CPU, 512mb Ram, Windows XP, Vista, 128mb Graphics Card with Shader Model 2.0 support ( roughly the equiv of OpenGL 2.0 support ), RECENT GRAPHICS DRIVERS
For Linux - Recent Linux Distro. such as Ubuntu Hardy Heron ( which it was tested on ) and see README.linux for more info.

For Linux users, please run gameStart.sh so you can use the local libHorde soft objects provided!


-- Config Options --


In data/scripts/config.sgz you can set the screen res amongst other things. 
The two main things here are Ansiotropic Filtering and Shadowmap Size. 
For the filtering, your options are 0, 1, 2, 4 and 8 and Shadowmaps range from 128, 256, 512, 1024 and 2048.

In data/scripts/controllers/controllerConfig.lua you can change the button config. 
It's made specifically for the PS2 pads so that's why it's PS2_TRI and so on. 
You can get the button mappings from the game controller bit in Control Panel.. the only diff is that you remove 1 from the button number Windows gives you as we count from 0 rather than 1 .. oh and analog control is the first stick it finds with X/Y axes :)

In data/scripts/outgameConfig.lua you can set a FAST renderer or "HDR"
It's not actual HDR, but just forward rendering, the HDR-ness was removed.
The FAST renderer just copies exact pixel data from texture to the screen, whereas the other one renders some lights and shadows too.

-- Known Issues --

ATi cards really seem to hate it... your best bet is nVidia to be honest. It will run with ATi cards, just it may stutter now and then.
Nothing we can do, I'm afraid.. it's due to odd OpenGL support from ATi.

You will require a high end machine to run it, as well.. this is due to the graphics engine being shader-based and requiring OpenGL 2.0 compliancy by default. Though with the config options we've left open, you should be able to get it running to some degree - especially in FAST rendering.

-- Thanks --

I'd like to again thank the Horde3D community for all the support they gave us, especially Nicolas Schulz.
Mark Hobbs from Philips amBX for putting up with us destroying their DLL files and causing interesting crashes ;)
Grant Clarke for the mass amount of help he gave us in regards to ODE and debugging some rather odd bugs.
The Realtime Worlds guys who got roped into our debugging session!
Everyone else that helped us in regards to code, or otherwise :)

-- Steven "Stuckie" Campbell
