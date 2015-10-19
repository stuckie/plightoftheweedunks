Source for Plight of the Weedunks
---------------------------------

This contains the source of the engine, and the uncompiled scripts ( though you'll also need the rest of the data from a binary release to run it )

There's a CodeBlocks project file for this, as this is what was used to code the game.
CodeBlocks is available from www.codeblocks.org for both Linux and Windows.

Everything is in this package to compile under Windows, Linux users require SDL, SDL_mixer, ODE and Lua5.1 to be installed.
ODE also requires to have been built with _double precision_

The CompileScripts.exe is just a very quick program that was written to recursively compile all lua scripts in the data folder, and effectively create a release build once the engine had been built for release mode.
It may run under Linux using WINE, but I haven't checked this.

Also, the amBX source files have been blanked so as not to incur the wrath of Philips.

Apologies for the state of some of the code, a vast majority of it was done in "crunch mode" near the end to get stuff done.

-- Steven "Stuckie" Campbell