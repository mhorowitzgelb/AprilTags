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



int main(int argc, char **argv) {
  apriltag_family_t *tf = tag36h11_create();
  apriltag_detector_t *td = apriltag_detector_create();
  apriltag_detector_add_family(td,tf);
  image_u8_t* img = image_u8_create_from_pnm("WillTagged.jpg");
  zarray_t* detections = apriltag_detector_detect(td,img);
  printf("%i\n",zarray_size(detections));
}
