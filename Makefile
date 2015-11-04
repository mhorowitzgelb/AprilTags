GPP=g++
CFLAGS=-pipe -m64 -ansi -fPIC -g -O3 -fno-exceptions -fstack-protector -Wl,-z,relro -Wl,-z,now -fvisibility=hidden -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-unused-label -Wpointer-arith -Wformat -Wreturn-type -Wsign-compare -Wmultichar -Wformat-nonliteral -Winit-self -Wuninitialized -Wno-deprecated -Wformat-security -Werror
APRILTAG_OBJS = AprilTagSource/apriltag.o AprilTagSource/apriltag_quad_thresh.o AprilTagSource/tag16h5.o AprilTagSource/tag25h7.o AprilTagSource/tag25h9.o AprilTagSource/tag36h10.o AprilTagSource/tag36h11.o AprilTagSource/tag36artoolkit.o AprilTagSource/g2d.o AprilTagSource/common/zarray.o AprilTagSource/common/zhash.o AprilTagSource/common/zmaxheap.o AprilTagSource/common/unionfind.o AprilTagSource/common/matd.o AprilTagSource/common/image_u8.o AprilTagSource/common/pnm.o AprilTagSource/common/image_f32.o AprilTagSource/common/image_u32.o AprilTagSource/common/workerpool.o AprilTagSource/common/time_util.o AprilTagSource/common/svd22.o AprilTagSource/common/homography.o AprilTagSource/common/string_util.o AprilTagSource/common/getopt.o
L=-IAprilTagSource -IAprilTagSource/common -I/usr/local/include/opencv -I/usr/local/include  -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal
MAGICK= `Magick++-config --cppflags --cxxflags --ldflags --libs`
all:
	$(GPP) main.cpp -o DisplayImage `pkg-config --cflags --libs opencv`
	@chmod +x DisplayImage
test:
	$(GPP) -o Test testAprilTags.cpp $(L) $(APRILTAG_OBJS) $(MAGICK) $(CFLAGS)
	@chmod +x Test

clean:
	rm DisplayImage
