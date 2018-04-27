#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <sys/time.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <net.h>

#include<iostream>
#include<fstream>
using namespace std;
std::ofstream outfile;

#include "mtcnn.h"

#include "det3.id.h"
#include "det3.mem.h"

float mean_vals[3] = {127.5, 127.5, 127.5};
float norm_vals[3] = {0.0078125, 0.0078125, 0.0078125};

using namespace std;
using namespace cv;

mtcnn::mtcnn()
{
    Onet.load_param(det3_param_bin);
    Onet.load_model(det3_bin);
}

void mtcnn::ONet_test(Mat &image)
{  
	ncnn::Mat in = ncnn::Mat::from_pixels(image.data, ncnn::Mat::PIXEL_BGR2RGB, image.cols, image.rows);
    in.substract_mean_normalize(mean_vals, norm_vals);

	ncnn::Extractor ex = Onet.create_extractor();
	ex.set_num_threads(2);
	ex.set_light_mode(true);
	
	ex.input(det3_param_id::LAYER_data, in);

	//打印输入数据
	outfile.open("in_48x48x3.txt", ios::out);
	for(int i=0;i<in.c;i++)
	{
		for(int j=0;j<in.h;j++)
		{
			for(int k=0;k<in.w;k++)
			{
				outfile << in.channel(i)[in.w*j+k] << ",";
				if(k==(in.w-1))
				{
					outfile << endl;
				}
			}
		}
		outfile << endl;
	}
	outfile.close();

	ncnn::Mat out;
	ex.extract(det3_param_id::BLOB_conv1, out);

	//打印输出数据
	outfile.open("conv1_46x46x32.txt", ios::out);
	for(int i=0;i<out.c;i++)
	{
		for(int j=0;j<out.h;j++)
		{
			for(int k=0;k<out.w;k++)
			{
				outfile << out.channel(i)[out.w*j+k] << ",";
				if(k==(out.w-1))
				{
					outfile << endl;
				}
			}
		}
		outfile << endl;
	}
	outfile.close();
}














