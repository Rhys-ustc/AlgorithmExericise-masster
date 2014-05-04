/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*  ���������㷨��
*  ��������InsertSort()
*  �鲢����MergeSort()
*  ��������QuickSort()
*  ������  HeapSort()
*/

#include<iostream>
#include<fstream>
#include<time.h>
#include"Sort.h"
using namespace std;

int main()
{
	//��ȡtxt�ļ�����
	int n = 0;
	ifstream file;
	file.open("data\\input.txt", ios::in);
	if (file.fail())
	{
		cout << "�ļ�������." << endl;
		file.close();
		cin.get();
		cin.get();
	}
	file >> n;
	int *x = new int[n];
	int count = 0;
	file.seekg(1, ios::cur); //�ļ�ָ�����һλ����ʼ��ȡ����
	while (!file.eof())
	{
		file >> x[count];
		count++;
	}

	// ������������ʱ��
	clock_t start, finish;
	start = clock();
	//InsertSort(x, n);
	MergeSort(x, n);
	//QuickSort(x, n);
	//HeapSort(x, n);
	finish = clock();

	cout<<"Sort time :"<<(double)(finish - start) / CLOCKS_PER_SEC <<" s."<< endl;

	//�����������output.txt��
	ofstream out;
	out.open("data\\output.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		out << x[i] << " ";
	}
	system("pause");
}
