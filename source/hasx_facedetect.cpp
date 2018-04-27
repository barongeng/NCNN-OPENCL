//by hpc
#include "hasx_facedetect.h"
#include "mtcnn.h"
#include <opencv2/core/core.hpp>
#include <vector>
#include <sys/time.h>

using namespace cv;

static mtcnn* mtcnn_find = NULL;

bool facedetect_init()
{
	if(NULL == mtcnn_find)
	{
		mtcnn_find = new mtcnn();
	}
	return true;
}

bool facedetect_onet(Mat &bgrimg)
{
	mtcnn_find->ONet_test(bgrimg);
	return true;
}

