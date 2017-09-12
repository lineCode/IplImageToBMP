
#include "globals.h"

static unsigned pcnt = 0;

void Cls_OnPaint(HWND hwnd)
{
  TCHAR       msgbuf[256];
  HDC  hDc;  
  PAINTSTRUCT   ps;
  HWND hwndGetById;

  BeginPaint(hwnd, &ps);
  EndPaint(hwnd, &ps);


  if(cvdt.hbFrame)
  {
    hDc = BeginPaint(glhWnd00, &ps);
///    BitBlt(hDc, 0, 0, cvdt.bm.bmWidth, cvdt.bm.bmHeight, cvdt.memDc, 0, 0, SRCCOPY);
    double ratio = (double)cvdt.bm.bmHeight/cvdt.bm.bmWidth;
    int w = _duc(screen_height/ratio);   
    StretchBlt(hDc, 0, 0, w/*glwnd00X*/, screen_height, cvdt.memDc, 0, 0, cvdt.bm.bmWidth, cvdt.bm.bmHeight, SRCCOPY);
    EndPaint(glhWnd00, &ps);
  } 
  

} /// void Cls_OnPaint


 

