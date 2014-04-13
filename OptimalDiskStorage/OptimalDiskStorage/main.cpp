/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*  �����ļ����Ŵ洢���⣺
*  ���������� n ���ļ����䱻�����ĸ��ʣ�����洢�ڴ��̵�n���ŵ��ϣ������ļ�i��j��ʱ��Ϊt[i,j] = p[i]*p[j]*d[i,j]. ���ʹ���ܵ���������ʱ����̡�
*  ̰�Ĳ��ԣ� ��n���ļ��������ɴ�С���򣬸������ķ������м�ŵ������ν��ļ��������Ҵ洢��...f4 f2 f1 f3 f5...
*/

#include<iostream>
#include<fstream>
#include "GreadyDiskStore.h"

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
	int *p = new int[n];
	int count = 0;
	file.seekg(1, ios::cur); //�ļ�ָ�����һλ����ʼ��ȡ����
	while (!file.eof())
	{
		file >> p[count];
		count++;
	}

	// ������������ʱ��
	InsertSort(p,n);

	double t = GreadyDiskStore(p, n);

	//�����������output.txt��
	ofstream out;
	out.open("data\\output.txt", ios::out);
	out << t << "\n";
	cout << "The minimum expected search time is : " << t << endl;
	system("pause");
}
