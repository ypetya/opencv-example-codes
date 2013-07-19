#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;

int main (int argc, char * const argv[]){

  CvCapture* capture = cvCaptureFromCAM( CV_CAP_ANY );
  cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320); 
  cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);

  // Get one frame
  IplImage* frame;

//  cvWaitKey(1000);
  for (int i = 0; i < 25; i++) 
  {
    frame = cvQueryFrame( capture );
  }

  printf( "Image captured \n" );  
//  IplImage* RGB_frame = frame;
//  cvCvtColor(frame,RGB_frame,CV_YUV2RGB_YUY2);
  cvSaveImage("test.jpg" ,frame);
//  cvSaveImage("cam.jpg" ,RGB_frame);

  printf( "Image Saved \n" );

//  cvWaitKey(10);

  // Release the capture device housekeeping
  cvReleaseCapture( &capture );
  //cvDestroyWindow( "mywindow" );

}
