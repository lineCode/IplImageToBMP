
# include "globals.h"


HWND          hwndMain;
HINSTANCE     hinstGlob;
CREATESTRUCT  CreateStruct;

BOOL  InitApplication(HINSTANCE hInstance) {
  
  WNDCLASSEX  wcex;

  wcex.cbSize        = sizeof(WNDCLASSEX);
  wcex.style         = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc   = (WNDPROC)MainWndProc;
  wcex.cbClsExtra    = 0;
  wcex.cbWndExtra    = 0;
  wcex.hInstance     = hInstance;
  wcex.hIcon         = LoadIcon(hInstance, (LPCTSTR)IDI_APPICON) ;
  wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW ) ;
  wcex.lpszMenuName  = NULL;
  wcex.lpszClassName = appName;
  wcex.hIconSm       = NULL;
    
  RegisterClassEx(&wcex);	

///MessageBox(NULL, L"InitApplication() str. 29", L"InitApplication() str. 29", MB_OK);
	
  return TRUE;
}	

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)  {

  HMENU    hMenu;
//  char	msgbuf[256];

  hinstGlob = hInstance;

  hMenu = LoadMenu(hInstance,MAKEINTRESOURCE(IDM_BASE));
 
/*
  fx =  (float)GetSystemMetrics(SM_CXSCREEN);
  fy =  (float)GetSystemMetrics(SM_CYSCREEN);
  k = fy/fx;
  x = _duc(fx-60);
  y = _duc(x*k);
*/  
  hwndMain = CreateWindowEx
             (
               WS_EX_OVERLAPPEDWINDOW|WS_EX_CONTROLPARENT,            
               appName,
               appTitle,
///               WS_SYSMENU|WS_MINIMIZEBOX|WS_EX_CONTROLPARENT,
////               WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX,
               WS_OVERLAPPEDWINDOW,
	             50,
               50,
               1280,
               720,
               NULL,
               hMenu,
               hInstance,
               (LPCREATESTRUCT) &CreateStruct
             );

  if (!hwndMain) 
    return (FALSE);
  

  ShowWindow(hwndMain, SW_SHOWNORMAL);
  UpdateWindow(hwndMain);
  
//sprintf(msgbuf, "hwndMain = %d", hwndMain) ;
//MessageBox(NULL, msgbuf, "hwndMain", MB_OK); 
///MessageBox(NULL, L"InitInstance() str. 62", L"InitInstance() str. 62", MB_OK);

  return (TRUE);
}
