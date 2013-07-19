#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <unistd.h>

main( int argc, char* argv[] )
{
  //initialize variables
  double fps = 0, sec = 0;
  int counter=0;
  time_t startTime, endTime;
  //capture video from webcam
  CvCapture* capture = cvCreateCameraCapture(0);
  assert( capture != NULL ); 
  //initialize image pointers
  IplImage *frame, *output, *edge;
  //grab first frame to extract data
  frame = cvQueryFrame(capture);
  int width = frame->width;
  int height = frame->height;
  //start timer
  time(&startTime);
  output = cvCreateImage(cvSize(width, height), IPL_DEPTH_8u, 1);
  edge = cvCreateImage(cvSize(width, height), IPL_DEPTH_8u, 1);

  while(1)
  {
    frame = cvQueryFrame(capture);
    //break when out of frame
    if(!frame) break;

    ///------------------------------main loop---------------------------
    //Filters go here
    ///------------------------------end main loop-----------------------

    //take time
    time(&endTime);
    ++counter;
    if(counter%100==0)
    {
      sec=difftime(endTime,startTime);
      fps=counter/sec;
      printf("%f\n",fps);
    }

    //wait in mili seconds
    usleep(30000);
  }

  //cvReleaseImage(&frame);
  cvReleaseCapture(&capture);
  return(0);
}
