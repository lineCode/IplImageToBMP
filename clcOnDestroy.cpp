
# include "globals.h"


void Cls_OnDestroy(HWND hwnd) {

         cvReleaseCapture(&cvdt.capture);

         if(NULL != cvdt.hbFrame){ 
           DeleteObject(cvdt.hbFrame);
           }
         if(NULL != hbStaticPic){ 
           DeleteObject(hbStaticPic);
           }
///MessageBox(NULL, _TEXT("BY-BY"), _TEXT("Cls_OnDestroy"), MB_OK);
    PostQuitMessage(0);
  }
 

