/*********************************************************************************
* Copyright (c) 2014.  Huaiyu Ruan.
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
* File ： main.cpp
* Description：softmax regression for MNIST classification
*
* HISTORY:   dd.mm.yyyy
* Ver. 1.0      29/3/2014
*/
/**********************************************************************************/

#include"LoadMnist.h"
#include"SoftmaxRegression.h"

int main()
{
	// load MNIST training data
	int nCol = 60000;  //训练数据的列数，即样本个数
	int nRow = 28 * 28; //数据的行数，即一个样本的维度为nRow
	int Num_out = 10;

	double *train_X = new double[nRow*nCol];
	int * train_Y = new int[nCol];
	
	string path_train_X = "data\\trainimage.a"; //训练数据集路径
	string path_train_Y = "data\\trainlabel.a"; //训练数据集标签路径

	LoadMnistData(path_train_X, path_train_Y, train_X, train_Y, nRow, nCol);
	Normalize(train_X, nCol*nRow);

	// softmax train
	double precision = 0;
	double lr = 0.0001;
	double lamda = 0.00001;
	int epochs = 200;
	double p_dropout = 0;
	Softmax softmax( nRow, Num_out, p_dropout);
	softmax.Train(train_X, train_Y, nCol, lr, lamda, epochs);

	//load test data
	delete[] train_X;
	delete[] train_Y;

	nCol = 10000;  //测试数据的列数，即测试样本个数

	double *test_X = new double[nRow*nCol];
	int * test_Y = new int[nCol];

	string path_test_X = "data\\testimage.a"; //测试数据集路径
	string path_test_Y = "data\\testlabel.a"; //测试数据集标签路径

	LoadMnistData(path_test_X, path_test_Y, test_X, test_Y, nRow, nCol);
	Normalize(test_X, nCol*nRow);

	// softmax predict
	precision = softmax.Predict(test_X, nCol, test_Y);

	cout << "precision: " << precision << endl;
	system("pause");
	return 0;
}