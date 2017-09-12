

#include "globals.h"

TCHAR     appName[64];
TCHAR     appTitle[256];
UINT	    ui = 0;

CVDT      cvdt, cvdtpc;
PCVDT     pcvdt;

HBITMAP  hbStaticPic;
HDC      memDC;
BITMAP   bmsp;

int WINAPI   WinMain(HINSTANCE hInstance,  HINSTANCE hPrevInstance, LPSTR lpCmdLine,  int nCmdShow) {
	
   MSG      msg;
   HACCEL   hAccelTable;
   TCHAR    msgbuf[256];    

   LoadString(hInstance, IDS_APPNAME, appName, sizeof(appName));
   LoadString(hInstance, IDS_APPTITLE, appTitle, sizeof(appTitle));

   if (!hPrevInstance) {
     if (!InitApplication(hInstance)) {
	     return (FALSE);
      }
    }

    if (!InitInstance(hInstance, nCmdShow)) {
      return (FALSE);
    }

    hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(MYACCEL));

    while( GetMessage(&msg, NULL, 0, 0))  {
      if (!TranslateAccelerator (msg.hwnd, hAccelTable, &msg))  {
         TranslateMessage(&msg); 
         DispatchMessage(&msg); 
      }
    }    
    return (int)msg.wParam;
}

