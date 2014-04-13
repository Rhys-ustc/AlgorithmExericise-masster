/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*  磁盘文件最优存储问题：
*  描述：给定 n 个文件及其被检索的概率，将其存储在磁盘的n个磁道上，检索文件i和j的时间为t[i,j] = p[i]*p[j]*d[i,j]. 编程使得总的期望检索时间最短。
*  贪心策略： 将n个文件按概率由大到小排序，概率最大的放在最中间磁道，依次将文件在其左右存储，...f4 f2 f1 f3 f5...
*/

#include<iostream>
#include<fstream>
#include "GreadyDiskStore.h"

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
	int *p = new int[n];
	int count = 0;
	file.seekg(1, ios::cur); //文件指针后移一位，开始读取数据
	while (!file.eof())
	{
		file >> p[count];
		count++;
	}

	// 计算期望检索时间
	InsertSort(p,n);

	double t = GreadyDiskStore(p, n);

	//将结果保存在output.txt中
	ofstream out;
	out.open("data\\output.txt", ios::out);
	out << t << "\n";
	cout << "The minimum expected search time is : " << t << endl;
	system("pause");
}
