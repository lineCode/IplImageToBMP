

#include "globals.h"


LRESULT CALLBACK  MainWndProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{

  switch(uMsg)
  { 
    HANDLE_MSG(hwnd, WM_CREATE, Cls_OnCreate );
    HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand );
    HANDLE_MSG(hwnd, WM_DESTROY, Cls_OnDestroy );
    HANDLE_MSG(hwnd, WM_TIMER, Cls_OnTimer);
    HANDLE_MSG(hwnd, WM_PAINT, Cls_OnPaint);

    default: 
      return DefWindowProc(hwnd, uMsg, wParam, lParam); 
  } 
  return 0; 
} 
 
