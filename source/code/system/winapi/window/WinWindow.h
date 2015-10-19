    /** For Registering newly created windows with Windows */
    void RegisterMyWindow(HINSTANCE hInstance)
    {
        WNDCLASSEX  wcex;					                //!< Pointer to the window class

        wcex.cbSize        = sizeof (wcex);			        //!< Size of the Window Class
        wcex.style         = CS_HREDRAW | CS_VREDRAW;		//!< Style (IE: Horizontal and Vertical redraw)
        wcex.lpfnWndProc   = WndProc;				        //!< Which WNDPROC it belongs to (we only got one)
        wcex.cbClsExtra    = 0;					            //!< No extra bytes for the class
        wcex.cbWndExtra    = 0;					            //!< No extra bytes for the window either
        wcex.hInstance     = hInstance;				        //!< The instance this belongs to
        wcex.hIcon         = 0;					            //!< Icon in the top left of the window
        wcex.hCursor       = LoadCursor (NULL, IDC_ARROW);	//!< Which cursor we use
        wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);		//!< Default Background colour
        wcex.lpszMenuName  = NULL;				            //!< We don't have a menu...
        wcex.lpszClassName = "MainWindow";			        //!< Name of this Class
        wcex.hIconSm       = 0;					            //!< The small icon in the taskbar

        RegisterClassEx (&wcex);				            //!< Register this class to Windows
    }

    /** We need to actually initialise the window by filling out a window handle struct */
    bool InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
    {
        HWND hwnd;                                          //!< Create a window handle instance to fill out
        hwnd = CreateWindow ("MainWindow",	                //!< Name of the Window Class we just generated
                "stuckieGAMEZ",                             //!< What the TITLE BAR says
                WS_OVERLAPPED | WS_CAPTION | WS_BORDER | WS_SYSMENU | WS_MINIMIZEBOX,
                /** Set style to only have a caption, border, sys_menu and a minimize box.. no resize */
                CW_USEDEFAULT,		                        //!< Default X start - lets windows decide
                CW_USEDEFAULT,		                        //!< Default Y start - lets windows decide
                1024,			                            //!< Set width 1024
                768,			                            //!< Set height 768
                NULL,			                            //!< It has no parents (aww shame)
                NULL,			                            //!< It has no menu
                hInstance,		                            //!< Which instance it belongs to
                NULL);			                            //!< And we don't want to pass anything to WNDPROC just now

        if (!hwnd)				                            //!< Now, if we don't have a windows handler
            return FALSE;			                        //!< We die...

        ShowWindow (hwnd, nCmdShow);		                //!< Show our beautiful window to the world!
        UpdateWindow (hwnd);			                    //!< And update it!
        ghwnd = hwnd;				                        //!< Tell Windows to receive messages on THIS window

        return TRUE;				                        //!< Job's done, and all done well :)

    }

    /** The Windows Message Processor */
    LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        /** As Windows tends to fire a lot of messages at us, we need some way of dealing with them.
        *   This function does that, and the following switch block allows us to deal with the ones we want,
        *   and ignore the rest of the junk Windows likes to send us ;)                                   */

        switch (message)
        {
            case WM_CREATE:	                                //!< When the window is created, do this:
//                loadBackground();
                startupEngine();                                //!< Do Game Init stuff
                break;

            case WM_SIZE:	                                //!< When the window is resized, do this:

                break;

            case WM_KEYDOWN:                                //!< When a key is pressed:
//                keys[wParam]=true;                          //!< mark it true in the key array
                break;

            case WM_KEYUP:	                                //!< And ofcourse, when it's released:
//                keys[wParam]=false;                         //!< mark it false.
                break;

            case WM_MOUSEMOVE:                              //!< When the mouse is moved:
//                MousePos.x = LOWORD (lParam);               //!< update the X co-ord
//                MousePos.y = HIWORD (lParam);               //!< update the Y co-ord
                break;

            case WM_PAINT:	                                //!< When we get a PAINT call:
                break;

            case WM_DESTROY:                                //!< When the Window dies:
                PostQuitMessage(0);                         //!< Quit gracefully
                break;
        }

        return DefWindowProc (  hwnd,                       //!< Else, windows should know what to do with it
                                message,
                                wParam,
                                lParam);
    }

    /** The ACTUAL Windows Entry Point */
    int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)
    {
        MSG	msg;		                                    //!< Pointer to the messages Windows likes to throw at us.

        RegisterMyWindow(hInstance);	                    //!< Register the window to THIS instance.

        if (!InitialiseMyWindow(hInstance, nCmdShow))	    //!< If there's been a bug creating the window..
            return FALSE;					                //!< PANIC!!!

        try
        {
            if(GameInterpret.Start(2, "127.0.0.1", 6869))	    //!< Start the game with the gameMode, ServerIP and Port number
            {
                SGZLogger.debug("\nGame started\n");		        //!< Print debug message to console
                SGZLogger.debug("\nEntering Game Loop\n");	        //!< Print debug message to console
            }
            else
            {
                SGZLogger.debug("\nStartup Failed - Main.cpp\n");	//!< If we can't start, print a debug message to the console.
                return 1;                                           //!< And bail out.
            }
        }
        catch(...)
        {
            SGZLogger.warn("Interpretor failed to start with WinAPI\n");
            SGZLogger.quit("Interpretor failed to start with WinAPI\n");
        }

        while (TRUE)					                    //!< And carry on :)
        {

            if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))       //!< has Windows got a message for us?
            {
                if (msg.message==WM_QUIT)		            //!< if it's quit,
                    break;			                        //!< just die..

                TranslateMessage (&msg);	                //!< Else, figure out what Windows wants
                DispatchMessage (&msg);		                //!< And fire it to our WNDPROC above to deal with.
		}

		else try				                            //!< If there's not a message, DO STUFF!! :D
		{
            if(GameInterpret.Running())			            //!< If the game is running....
                GameInterpret.Loop();				            //!< Do the Game Loop ** dances a jig **
            else
            {
                SGZLogger.debug("\nGame has stopped running\n");    //!< Otherwise, let us know it's not running
                break;
            }
		}
		catch(...)
		{
		    SGZLogger.warn("Engine has Crashed under WinAPI\n");
		    SGZLogger.quit("Engine has Crashed under WinAPI\n");
		}
	}

    SGZLogger.debug("\nLeaving Game Loop\n");	    		//!< Print debug message to console
    SGZLogger.debug("\nGame stopping\n");			        //!< Print a debug message that everything stopped alright.

    GameInterpret.Stop();	    	                        //!< Then Stop the Game Instance
	return msg.wParam ;	                                    //!< And tell windows the reason we died.. be it proper quit or an oops!
}
