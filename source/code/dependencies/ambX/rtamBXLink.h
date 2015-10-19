#ifndef _RTAMBXLINKH_
#define _RTAMBXLINKH_

extern "C"
{
	int FunctionOne(); 							//Setup - Returns NULL if OK
	int FunctionTwo(char* script);				//Send Script - A standard amBX script as a char*. Returns NULL if OK
	int FunctionThree();						//Shutdown - Returns NULL if OK
	char* FunctionFour();						//GetVersion - Returns amBX Version as a char* or a char* stating amBX is not avaiable
	int FunctionFive(char* mutexname); 			//Check if another running
	int FunctionSix(char* location, float r, float g, float b);				            //Set Light - Float values from 0.0f - 1.0f Returns NULL of OK
	int FunctionSeven(char* location, float fade);						                //Set Fade - Float from 0.0f - 1.0f Returns NULL if OK
	int FunctionEight(char* location, float intensity);                                 //SetFan - Float from 0.0f - 1.0f Returns NULL if OK
	int FunctionNine(char* location, char* rumbleType, float intensity, float speed);   //SetRumble - RumbleType Intensity Float from 0.0f - 1.0f Speed Float from 0.1f - 10.0f Returns NULL if OK
	int FunctionTen(bool autoUpdate);           //Update - (Autoupdate used to set automatic update function, best not to use this)Returns NULL if OK
}
#endif
