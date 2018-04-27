#ifndef MTCNN_H
#define MTCNN_H

#include <vector>
#include <net.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

struct Bbox
{
    float score;
    int x1;
    int y1;
    int x2;
    int y2;
    float area;
    bool exist;
    float ppoint[10];
    float regreCoord[4];
};

struct orderScore
{
    float score;
    int oriOrder;
};

bool cmpScore(orderScore lsh, orderScore rsh);

class mtcnn
{
public:
    mtcnn();
	void ONet_test(Mat &image);		
private:
    ncnn::Net Onet;
};


#endif
