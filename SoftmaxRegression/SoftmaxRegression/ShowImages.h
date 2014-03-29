

#include "./opencv/cxcore.h"
#include "./opencv/highgui.h"

#ifdef _DEBUG
#pragma comment(lib, "./opencv/opencv_core247d.lib")
#pragma comment(lib, "./opencv/opencv_highgui247d.lib")
#else
#pragma comment(lib, "./opencv/opencv_core247.lib")
#pragma comment(lib, "./opencv/opencv_highgui247.lib")
#endif // _DEBUG

void ShowImg(double *data, int cols, int rows);