/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*  基本排序算法：
*  插入排序：InsertSort()
*  归并排序：MergeSort()
*  快速排序：QuickSort()
*  堆排序：  HeapSort()
*/

#include<iostream>
#include<fstream>
#include<time.h>
#include"Sort.h"
using namespace std;

int main()
{
	//读取txt文件数据
	int n = 0;
	ifstream file;
	file.open("data\\input.txt", ios::in);
	if (file.fail())
	{
		cout << "文件不存在." << endl;
		file.close();
		cin.get();
		cin.get();
	}
	file >> n;
	int *x = new int[n];
	int count = 0;
	file.seekg(1, ios::cur); //文件指针后移一位，开始读取数据
	while (!file.eof())
	{
		file >> x[count];
		count++;
	}

	// 计算期望检索时间
	clock_t start, finish;
	start = clock();
	//InsertSort(x, n);
	MergeSort(x, n);
	//QuickSort(x, n);
	//HeapSort(x, n);
	finish = clock();

	cout<<"Sort time :"<<(double)(finish - start) / CLOCKS_PER_SEC <<" s."<< endl;

	//将结果保存在output.txt中
	ofstream out;
	out.open("data\\output.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		out << x[i] << " ";
	}
	system("pause");
}
