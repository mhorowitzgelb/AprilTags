GPP=g++ -Wall
L=-I/usr/local/include/opencv -I/usr/local/include  -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal

all:
	$(GPP) main.cpp -o DisplayImage `pkg-config --cflags --libs opencv`
	chmod +x DisplayImage
clean:
	rm DisplayImage
