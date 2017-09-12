
#include "globals.h"
////#include "OpenCV_headers.h"

static uint32_t  FrameCounter = 0;

int InitCapture(PCVDT pcvdt)
{
  HWND      hwndGetById;
  TCHAR     msgbuf[1024];

  using namespace cv;

  pcvdt->capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );

  if(NULL == pcvdt->capture)
  { 
    MessageBox(NULL, _TEXT("cvCreateCameraCapture() filed str 12"), _TEXT("InitCapture()"), MB_OK);
    return (-3);
  }

/*
  if(!pcvdt->capture.isOpened())  //  Проверка корректности отработки
	{
    MessageBox(NULL, _TEXT("cvCreateCameraCapture() filed str 12"), _TEXT("InitCapture()"), MB_OK);
    return (-3);
	}
*/


////******************************************************************

/*
// get frame resolution
  double width = cvGetCaptureProperty(pcvdt->capture, CV_CAP_PROP_FRAME_WIDTH);
  double height = cvGetCaptureProperty(pcvdt->capture, CV_CAP_PROP_FRAME_HEIGHT);
  swprintf(msgbuf, sizeof(msgbuf), _TEXT("CaptureCamFrame()X = %5.3f Y = %5.3f\n"), width, height);
  MessageBox(NULL, msgbuf, _TEXT("DEBUG"), MB_OK);
// set frame resolution
  cvSetCaptureProperty(pcvdt->capture, CV_CAP_PROP_FRAME_WIDTH, 1600); 
  cvSetCaptureProperty(pcvdt->capture, CV_CAP_PROP_FRAME_HEIGHT, 1200);

// get frame resolution
  double width01 = cvGetCaptureProperty(pcvdt->capture, CV_CAP_PROP_FRAME_WIDTH);
  double height01 = cvGetCaptureProperty(pcvdt->capture, CV_CAP_PROP_FRAME_HEIGHT);
  swprintf(msgbuf, sizeof(msgbuf), _TEXT("CaptureCamFrame()X = %5.3f Y = %5.3f\n"), width01, height01);
  MessageBox(NULL, msgbuf, _TEXT("AFTER SET"), MB_OK);


  hwndGetById = GetDlgItem(cvdt.hwnd, IDED_STRING_01);
  swprintf(msgbuf, sizeof(msgbuf), _TEXT("OK cvCreateCameraCapture()"));
  SendMessage(hwndGetById, WM_SETTEXT, 0, (LPARAM)msgbuf);
*/
  return (1);
} ///  InitCapture(CVDT cvdt){

///////////////////////////////////////////////////////////////////////

int CaptureCamFrame(PCVDT pcvdt)
{
  HWND      hwndGetById, hwndGetById00;
  TCHAR     msgbuf[1024];
  char      filename[512], msgch[512];
  HDC       hDc;
  HBITMAP   hOldBMP;

///  using namespace cv;

  hwndGetById = GetDlgItem(pcvdt->hwnd, IDST_STATUS);


  pcvdt->frame = cvQueryFrame(pcvdt->capture);
  if(0 == pcvdt->frame)
  { 
    swprintf(msgbuf, sizeof(msgbuf), _TEXT("filed cvQueryFrame()") );
    MessageBox(NULL, msgbuf, _TEXT("DEBUG"), MB_OK);
    return (-2);
  }

  if(NULL == pcvdt->picv) 
  { 
    pcvdt->picv = (BYTE*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, pcvdt->frame->imageSize);
    if(NULL == pcvdt->picv)
    {
      swprintf(msgbuf, sizeof(msgbuf), _TEXT(" pcvdt->picv = (BYTE*)HeapAlloc() filed\nGetLastError() == %d"), GetLastError()); 
      MessageBox(NULL, msgbuf, _TEXT("DEBUG"), MB_OK);
      return (-6);
    }
  }

    hDc = GetDC(glhWnd00);
    if(NULL == hDc)
    {
      swprintf(msgbuf, sizeof(msgbuf), _TEXT("NULL == hDc\nGetLastError() == %d"), GetLastError()); 
      MessageBox(NULL, msgbuf, _TEXT("DEBUG"), MB_OK);
      return (-15);
    }
    pcvdt->memDc = CreateCompatibleDC(hDc);
    if(NULL == pcvdt->memDc)
    {
      swprintf(msgbuf, sizeof(msgbuf), _TEXT("NULL == memDc\nGetLastError() == %d"), GetLastError()); 
      MessageBox(NULL, msgbuf, _TEXT("DEBUG"), MB_OK);
      return (-16);
    }

    pcvdt->bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    pcvdt->bmi.bmiHeader.biWidth = pcvdt->frame->width;
    pcvdt->bmi.bmiHeader.biHeight = pcvdt->frame->height;
    pcvdt->bmi.bmiHeader.biPlanes = 1 ;
    pcvdt->bmi.bmiHeader.biBitCount = pcvdt->frame->depth * pcvdt->frame->nChannels;
    pcvdt->bmi.bmiHeader.biCompression = BI_RGB;
    pcvdt->bmi.bmiHeader.biSizeImage = pcvdt->frame->imageSize;
    pcvdt->bmi.bmiHeader.biXPelsPerMeter = 0;
    pcvdt->bmi.bmiHeader.biYPelsPerMeter = 0;
    pcvdt->bmi.bmiHeader.biClrUsed = 0;
    pcvdt->bmi.bmiHeader.biClrImportant = 0;

    pcvdt->bm.bmWidth = pcvdt->frame->width;
    pcvdt->bm.bmHeight = pcvdt->frame->height;

///    swprintf(msgbuf, sizeof(msgbuf), _TEXT("resolution : %i x %i\n"), pcvdt->frame->width, pcvdt->frame->height); 
    swprintf(msgbuf, sizeof(msgbuf), L"resolution : %i x %i\n", pcvdt->frame->width, pcvdt->frame->height);
    SendMessage(hwndGetById, SB_SETTEXT, (WPARAM)2, (LPARAM)msgbuf);

 
    pcvdt->hbFrame = CreateDIBSection(pcvdt->memDc, &pcvdt->bmi, DIB_RGB_COLORS, (void**)&pcvdt->picv, NULL, 0);

    if(NULL == pcvdt->hbFrame)
    {
      swprintf(msgbuf, sizeof(msgbuf), _TEXT("CreateDIBitmap() filed\nGetLastError() == %d"), GetLastError()); 
      MessageBox(NULL, msgbuf, _TEXT("DEBUG CaptureCamFrame() str 253"), MB_OK);
      return (-13);
    }


/// Need turn over image from OpenCV to Windows bitmap
///
  int j = pcvdt->frame->imageSize-1;
  int strlen = (pcvdt->frame->width * pcvdt->frame->nChannels);
  int strlim = 0;
  int strcnt = strlen;
  int i=0;

  do{
    for(int k=strcnt-1; k>=strlim; k--) {
      pcvdt->picv[k] = pcvdt->frame->imageData[j];
      j--; i++;
      }
    strlim = strcnt;
    strcnt += strlen;

    } while(i<pcvdt->frame->imageSize);

  hOldBMP = (HBITMAP)SelectObject(pcvdt->memDc, pcvdt->hbFrame);
  if(NULL == hOldBMP)
  {
    swprintf(msgbuf, sizeof(msgbuf), _TEXT("NULL == SelectObject()\nGetLastError() == %d"), GetLastError()); 
    MessageBox(NULL, msgbuf, _TEXT("CaptureCamFrame() str 253"), MB_OK);
    return (-14);
  }

  FrameCounter++;

///cvReleaseCapture(&cvdt.capture);
  DeleteObject(hOldBMP);
  ReleaseDC(glhWnd00, hDc);
  InvalidateRgn(pcvdt->hwnd,NULL,TRUE);

  return (0);
}

////////////////////////////////////////////////////////////////

int writeBMPintoFile(PCVDT pcvdt)
{
  size_t   sz=512;    
  TCHAR    msgbuf[512], path[512];
  DWORD    dwWr;
  BITMAPFILEHEADER bfhd;
  WBBUNI   wordb;

  if(0 == pcvdt->frame)
  {
///    swprintf(msgbuf, sizeof(msgbuf), _TEXT("nothing to save"));
    swprintf_s(msgbuf, sizeof(msgbuf), _TEXT("nothing to save"));
    MessageBox(NULL, msgbuf, _TEXT("writeBMPintoFile() module CV_function.cpp str. 193"), MB_OK);
    return -11;
  }
  
  wordb.bytes.Lo = 'M';
  wordb.bytes.Hi = 'B'; 

  bfhd.bfType = wordb.word; ///static_cast<WORD>("BM");  // WORD 
  bfhd.bfSize = 54+pcvdt->frame->imageSize;  /// DWORD 
  bfhd.bfReserved1 = 0;  /// WORD
  bfhd.bfReserved2 = 0;  /// WORD
  bfhd.bfOffBits = 54;   /// DWORD

  SetTimeString(msgbuf, sz, 1);

  swprintf(path, sizeof(path), _TEXT(".\\"));
  wcscat(path, msgbuf);
  wcscat(path, _TEXT(".bmp\0"));
///  MessageBox(NULL, path, _TEXT("writeBMPintoFile() module CV_function.cpp str. 201"), MB_OK);

  HANDLE hFile = CreateFile(path, GENERIC_READ|GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
  { 
    swprintf(msgbuf, sizeof(msgbuf), _TEXT("CreateFile() filed\n GetLastError == %d"), GetLastError());
    MessageBox(NULL, msgbuf, _TEXT("writeBMPintoFile() module CV_function.cpp str. 199"), MB_OK|MB_ICONHAND);
    return -1;
  }
  WriteFile(hFile, &bfhd, sizeof(BITMAPFILEHEADER), &dwWr, NULL);
  WriteFile(hFile, &pcvdt->bmi, sizeof(BITMAPINFOHEADER), &dwWr, NULL);
  WriteFile(hFile, pcvdt->picv, pcvdt->bmi.bmiHeader.biSizeImage, &dwWr, NULL);

///  swprintf(msgbuf, sizeof(msgbuf), _TEXT("sizeof bihd == %d\nsizeof BITMAPFILEHEADER == %d"), sizeof(bihd), sizeof(BITMAPINFOHEADER));
///  MessageBox(NULL, path, _TEXT("writeBMPintoFile() module CV_function.cpp str. 216"), MB_OK);

/// Save in file by OpenCV method
  char   filename[256];
  sprintf(filename, "Image%d.bmp", FrameCounter);
  cvSaveImage(filename, pcvdt->frame);

  CloseHandle(hFile);
  return 0;
}

////////////////////////////////////////////////////////////////

int MakeBMPfromIplImage(PCVDT pcvdt)
{

  return 0;
}
