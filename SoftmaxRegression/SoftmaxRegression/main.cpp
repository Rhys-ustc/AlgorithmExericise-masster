/*********************************************************************************
* Copyright (c) 2014.  Huaiyu Ruan.
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
* File �� main.cpp
* Description��softmax regression for MNIST classification
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
	int nCol = 60000;  //ѵ�����ݵ�����������������
	int nRow = 28 * 28; //���ݵ���������һ��������ά��ΪnRow
	int Num_out = 10;

	double *train_X = new double[nRow*nCol];
	int * train_Y = new int[nCol];
	
	string path_train_X = "data\\trainimage.a"; //ѵ�����ݼ�·��
	string path_train_Y = "data\\trainlabel.a"; //ѵ�����ݼ���ǩ·��

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

	nCol = 10000;  //�������ݵ���������������������

	double *test_X = new double[nRow*nCol];
	int * test_Y = new int[nCol];

	string path_test_X = "data\\testimage.a"; //�������ݼ�·��
	string path_test_Y = "data\\testlabel.a"; //�������ݼ���ǩ·��

	LoadMnistData(path_test_X, path_test_Y, test_X, test_Y, nRow, nCol);
	Normalize(test_X, nCol*nRow);

	// softmax predict
	precision = softmax.Predict(test_X, nCol, test_Y);

	cout << "precision: " << precision << endl;
	system("pause");
	return 0;
}