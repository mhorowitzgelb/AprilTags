#include <Magick++.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>
#include <unistd.h>

#include "apriltag.h"
#include "image_u8.h"
#include "tag36h11.h"
#include "tag36h10.h"
#include "tag36artoolkit.h"
#include "tag25h9.h"
#include "tag25h7.h"
#include "zarray.h"

using namespace cv;
using namespace std;

int main(int argc, char **argv) {
  VideoCapture cap(0);
  if (!cap.isOpened()) {
      cout << "Cannot open the web cam" << endl;
      return -1;
  }

  apriltag_family_t *tf = tag36h11_create();
  apriltag_detector_t *td = apriltag_detector_create();
  apriltag_detector_add_family(td,tf);
  Mat imgTmp;
  Mat gray;
  while (true) {
    bool bSuccess = cap.read(imgTmp);
    if (!bSuccess) {
      cout << "Video Sux" << endl;
      break;
    }

    cvtColor(imgTmp, gray, COLOR_BGR2GRAY);
    if (!gray.isContinuous()) { // remove if it runs the first time
      cout << "Image Not continuous" << endl;
      break;
    }
    image_u8_t* img = image_u8_create(gray.cols, gray.rows);
    img->buf = gray.ptr<uint8_t>(0);

    zarray_t* detections = apriltag_detector_detect(td,img);
    if (zarray_size(detections) > 0) {
      apriltag_detection_t *det;
      zarray_get(detections, 0, &det);
      Point beautiful[4];
      beautiful[0] = Point(det->p[0][0], det->p[0][1]);
      beautiful[1] = Point(det->p[1][0], det->p[1][1]);
      beautiful[2] = Point(det->p[2][0], det->p[2][1]);
      beautiful[3] = Point(det->p[3][0], det->p[3][1]);
      Scalar b = Scalar(0,0,255,255);
      line(imgTmp, beautiful[0], beautiful[1], b, 40);
      line(imgTmp, beautiful[1], beautiful[2], b, 40);
      line(imgTmp, beautiful[2], beautiful[3], b, 40);
      line(imgTmp, beautiful[3], beautiful[0], b, 40);
    }
    zarray_destroy(detections);
    imshow("april tags", imgTmp);
    if (waitKey(30) == 27) { //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
      cout << "esc key is pressed by user" << endl;
      break;
    }
  }
  tag36h11_destroy(tf);
  apriltag_detector_destroy(td);
}
