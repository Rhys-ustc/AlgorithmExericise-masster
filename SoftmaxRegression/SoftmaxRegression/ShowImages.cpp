#include"ShowImages.h"


/*ShowImg()
   Show the input data as a Rows*Cols image

*/
void ShowImg(double *x, int Cols, int Rows)
{

	IplImage* Image;
	Image = cvCreateImage(cvSize(Cols, Rows), IPL_DEPTH_8U, 1);
	cvNamedWindow("One Sample Image", 1);
	
	// normalize the data into [0,255]
	double maxval = 0;
	for (int i = 0; i < Cols*Rows; i++)
	{
		if (x[i]>maxval)
		{
			maxval = x[i];
		}
	}

	for (int row = 0; row < Rows;row++)
	for (int col = 0; col < Cols; col++)
	{
		Image->imageData[row*Image->widthStep + col] = x[row*Cols + col]*255/maxval;
	}

	cvShowImage("One Sample Image", Image);
	cvWaitKey(100);
	cvDestroyWindow("One Sample Image");
	cvReleaseImage(&Image);

}