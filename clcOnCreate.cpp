
#include "globals.h"


HWND	  hwndGb[32],	hwndBtn[16], hwndHlp[4];
HWND    glhWnd00, glhWnd01, hwndRegTest;
HWND*   p_glhWnd; 
UINT    idTmrA; ///, tmrCountA = 0;
UINT    idTmrB, tmrCountB = 0;
int     screen_width =  960; 
int     screen_height = 540;

HANDLE	hHeapNew, hHeapConv;

BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
  TCHAR   msgbuf[256];
  char    cmsgbuf[256];
  RECT    rc, rcgb; 
	int     statdiv[6];
	LONG    x, y;


  hHeapNew = HeapCreate(0, 0, 16777216);
  if (NULL == hHeapNew) {
///    swprintf(msgbuf, sizeof(msgbuf), _TEXT("HeapCreate() for hHeapNew filed, ErrorNo == %d\n Перезапустите программу"), GetLastError());
    swprintf(msgbuf, sizeof(msgbuf), _TEXT("HeapCreate() for hHeapNew filed, ErrorNo == %d\n"), GetLastError());
///sprintf(cmsgbuf, "HeapCreate() for hHeapNew filed, ErrorNo == %d\n Перезапустите программу", GetLastError());
    MessageBox(NULL, msgbuf, _TEXT("Error"), MB_OK|MB_ICONERROR);
    PostQuitMessage(0);
   }


  InitCommonControls(); 
/////////////////////  Create Gl window ///////////////////////////////////
///  p_glhWnd = &glhWnd;
  glhWnd00 =  CreateWindowEx
             (
                NULL,
                _TEXT("Static"),
                NULL,
                WS_TABSTOP| WS_CHILD| WS_VISIBLE|WS_BORDER|WS_CLIPCHILDREN,
                10,
                10,
                screen_width,
                screen_height,
                hwnd, 
                (HMENU)ID_GL00,
                hinstGlob,
                NULL
             );

// ===============================================================
	x = 10+screen_width+20;
	y = 50;
	hwndGb[0] = CreateWindowEx
              (
                WS_EX_CONTROLPARENT,
                _TEXT("Button"),
                _TEXT("Operation"),
                BS_GROUPBOX|WS_CHILD| WS_GROUP |WS_VISIBLE,
                x,
                y,
                250, 
                160,
                hwnd,
                (HMENU)IDGB_MATH,
                hinstGlob,
                NULL
              );

  hwndBtn[0] = CreateWindowEx
               (
                 WS_EX_CONTROLPARENT,
                 _TEXT("Button"),
                 _TEXT("Get camera frame "),
                 WS_TABSTOP| WS_CHILD| WS_VISIBLE| BS_PUSHBUTTON ,
                 x+8,
                 y+30,
                 160,
                 30,
                 hwnd,
                 (HMENU)IDBT_CAPTURE,
                 hinstGlob,
                 NULL
               );

  hwndBtn[1] = CreateWindowEx
               (
                 WS_EX_CONTROLPARENT,
                 _TEXT("Button"),
                 _TEXT("Save as BMP"),
                 WS_TABSTOP| WS_CHILD| WS_VISIBLE| BS_PUSHBUTTON ,
                 x+8,
                 y+80,
                 160,
                 30,
                 hwnd,
                 (HMENU)IDBT_SAVE_BMP,
                 hinstGlob,
                 NULL
               );


///***************************************************************************
    hwndHlp[0] = CreateWindow
                 (
                   STATUSCLASSNAME,
                   _TEXT(""),
                   WS_CHILD| WS_VISIBLE|SBARS_SIZEGRIP,
                   0,
                   0,
                   0,
                   0,
                   hwnd,
                   (HMENU)IDST_STATUS,
                   hinstGlob,
                   NULL
                 );

    GetClientRect(hwnd, &rc);

	  statdiv[0] = _duc((rc.right - rc.left)*0.14);
    statdiv[1] = _duc((rc.right - rc.left)*0.28);
    statdiv[2] = _duc((rc.right - rc.left)*0.44);
    statdiv[3] = _duc((rc.right - rc.left)*0.64);
    statdiv[4] = -1;

    SendMessage(hwndHlp[0], SB_SETPARTS, (WPARAM)5, (LPARAM)(LPINT)statdiv);

///***************************************************************************

   idTmrA = SetTimer(hwnd, ID_TIMER_A, 20, NULL);
///   idTmrB = SetTimer(hwnd, ID_TIMER_B, 15, NULL);

   pcvdt = &cvdt;
   cvdt.capture = NULL;
   cvdt.frame = 0;
   cvdt.picv = NULL;
   cvdt.hwnd = hwnd;

   InitCapture(pcvdt);

   return TRUE;

}	// BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct ) {

