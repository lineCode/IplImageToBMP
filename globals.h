#pragma once

#ifndef _GLOBALS_H
#define _GLOBALS_H

#define UNICODE

#ifdef UNICODE
#define _UNICODE
#endif


#define VC_EXTRALEN
#define WINVER 0x600

#include <windows.h>
#include <winuser.h>
#include <windowsx.h>
#include <commctrl.h>
#include <commdlg.h>
#include <shellapi.h>
#include <Mmsystem.h>
#include <winioctl.h>
#include <cstdlib>
#include <stdio.h>
#include <Wingdi.h>
#include <math.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <locale>

/// OpenCV include

#include <cv.h>
#include <highgui.h>

#include "CV_data.h"
#include "res.h"

#pragma comment(lib, "libcmt.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "SHELL32.LIB")
#pragma comment(lib, "Winmm.lib")
/// #pragma comment(lib, "")

#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
#pragma comment(lib, "opencv_imgproc2413.lib")
#pragma comment(lib, "opencv_video2413.lib")
#pragma comment(lib, "opencv_ml2413.lib")
#pragma comment(lib, "opencv_calib3d2413.lib")
#pragma comment(lib, "opencv_objdetect2413.lib")
#pragma comment(lib, "opencv_features2d2413.lib")
#pragma comment(lib, "opencv_contrib2413.lib")
#pragma comment(lib, "opencv_ts2413.lib")
#pragma comment(lib, "opencv_legacy2413.lib")
#pragma comment(lib, "opencv_flann2413.lib")
#pragma comment(lib, "opencv_gpu2413.lib")


extern HWND           hwndMain;
extern HINSTANCE      hinstGlob;
extern TCHAR          appName[];
extern TCHAR          appTitle[];
extern CREATESTRUCT   CreateStruct;
extern WNDPROC	      lpfnEditWndProc;

extern HWND          glhWnd00, glhWnd01;
extern HWND*         p_glhWnd;
extern HGLRC         ghRC;
extern HDC           ghDC;
extern BITMAPINFO    bminfo;

///extern UINT          tmrCountA;
extern UINT          tmrCountB;
extern int           screen_width;
extern int           screen_height;

extern HBITMAP  hbStaticPic;
extern HDC      memDC;
extern BITMAP   bmsp;

extern CVDT     cvdt, cvdtpc/*Pattern to compare*/;
extern PCVDT    pcvdt;

BOOL  InitApplication(HINSTANCE);
BOOL  InitInstance(HINSTANCE, int);
LRESULT CALLBACK  MainWndProc( HWND, UINT, WPARAM, LPARAM);

int  _duc(double);

//void	ini_write(BYTE, BYTE);
void	ini_write(BYTE);
int CaptureCamFrame(PCVDT);
int InitCapture(PCVDT);

int MakeBMPfromIplImage(PCVDT);
int writeBMPintoFile(PCVDT);
///void  SetTimeString(TCHAR*, uint64_t);
void  SetTimeString(TCHAR*, size_t, size_t);


BOOL Cls_OnCreate(HWND, LPCREATESTRUCT); 
void Cls_OnCommand(HWND, int, HWND, UINT);
void Cls_OnDestroy(HWND);
void Cls_OnPaint(HWND);
void Cls_OnTimer( HWND, UINT);

//void Cls_OnSize( HWND, UINT, int, int);
//BOOL Cls_OnNotify(HWND, int, NMHDR*);
//void Cls_OnMouseMove(HWND, int, int, UINT);
//void Cls_OnKey(HWND, UINT, BOOL, int, UINT);
//void Cls_OnMWheel(HWND, int, int, UINT);
//void Cls_OnHscroll(HWND, HWND, int, int);


#endif
