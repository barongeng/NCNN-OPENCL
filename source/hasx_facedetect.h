//by hpc
#ifndef _YT_MTCNN_H_
#define _YT_MTCNN_H_

#include <opencv2/core/core.hpp>
#include <vector>
using namespace std;


using namespace cv;
#ifdef __cplusplus
extern "C"{
#endif

bool facedetect_init();

bool facedetect_onet(Mat &bgrimg);	


#ifdef __cplusplus
}
#endif //end of extern "C"

#endif //end of "_YT_MTCNN_H_"
