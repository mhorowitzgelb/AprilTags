#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>


using namespace cv;
using namespace std;
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: DisplayImage.out <Image_Path>\n");
    return -1;
  }
  Mat A;
  Mat imgTmp;

  A = imread(argv[1], CV_LOAD_IMAGE_COLOR);
  namedWindow("April", CV_WINDOW_AUTOSIZE); //create a window called "Control"
  namedWindow("Normal", CV_WINDOW_AUTOSIZE);
  //Capture a temporary image from the camera

  cvtColor(A, imgTmp, COLOR_BGR2RGBA);

  imwrite("./Converted_Image.jpg", imgTmp);

  imshow("April", imgTmp);
  imshow("Normal", A);
  waitKey(0);
  //Create a black image with the size as the camera output

  return 0;
}
