
#include "globals.h"

static UINT    tmrCountA = 0;

void Cls_OnTimer(HWND hwnd, UINT uTimerID) {
  HWND       hwndGetById;
  SYSTEMTIME time;
  UINT       mm, ss, hh;
  TCHAR       msgbuf[256];
 
    switch(uTimerID) {
      case ID_TIMER_A:
/*
          GetSystemTime(&time);
          hh = (UINT)time.wHour;
          hh = hh + 3;
          mm = (UINT)time.wMinute;
          ss = (UINT)time.wSecond;
          sprintf(msgbuf, "%u:%u:%u", hh, mm, ss);
*/ 
        swprintf(msgbuf, sizeof(msgbuf), _TEXT("TMR_A = %d"), tmrCountA);
///        sprintf(msgbuf, "TMR_A = %d", tmrCountA);
        hwndGetById = GetDlgItem(hwnd, IDST_STATUS);
        SendMessage(hwndGetById, SB_SETTEXT, (WPARAM)1, (LPARAM)msgbuf);
////        hwndGetById = GetDlgItem(hwnd, IDED_STRING_01);
////        SendMessage(hwndGetById, WM_SETTEXT, 0, (LPARAM)msgbuf);  
        tmrCountA++;
        break;
      case ID_TIMER_B:

///        CaptureCamFrame(pcvdt);
        break;
    } /// switch(uTimerID) {

} /// void Cls_OnTimer
 

