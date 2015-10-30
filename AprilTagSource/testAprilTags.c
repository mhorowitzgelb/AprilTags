
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>
#include <unistd.h>

#include "getopt.h"
#include "apriltag.h"
#include "image_u8.h"
#include "tag36h11.h"
#include "tag36h10.h"
#include "tag36artoolkit.h"
#include "tag25h9.h"
#include "tag25h7.h"
#include "zarray.h"


int main(int argc, char **argv){
	printf("one\n");
	apriltag_family_t *tf = tag36h11_create();
	printf("two\n");
	apriltag_detector_t *td = apriltag_detector_create();
	printf("three\n");
	apriltag_detector_add_family(td,tf);
	printf("four\n");
	image_u8_t* img = image_u8_create_from_pnm("../WillTagged.pnm");
	printf("five\n");
	zarray_t* detections = apriltag_detector_detect(td,img);
	printf("%i",zarray_size(detections)); 
	printf("\n");
	
} 
