#include "hasx_facedetect.h"
#include <stdio.h>
#include <vector>
#include <sys/time.h>
#include <opencv2/opencv.hpp>
#include <net.h>

int main(int argc, char** argv)
{
	facedetect_init();

	cv::Mat cv_img = cv::imread("ONet_test.bmp");
		
	facedetect_onet(cv_img);
		
	return 0;
}