/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*  ��̱༭���⣺
*  ���������� �����ַ�����Ҫ�������ٵĲ��������ַ���A��Ϊ�ַ���B.����������ɾ����������滻
*/

#include<iostream>
#include<fstream>
#include<vector>
#include <cstring>
using namespace std;

int ShotEditDistance(string a, string b)
{
	int m = a.size();
	int  n = b.size();
	vector<int>d(n+1,0);
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int y = i - 1;
		for (int j = 1; j <= n; j++)
		{
			int x = y;
			y = d[j];
			int z = j > 1 ? d[j - 1] : i;
			int del = a[i - 1] == b[j - 1] ? 0 : 1;
			if (x + del < y + 1)
			{
				d[j] = x + del;
			}
			else{ d[j] = y + 1; }
			if (d[j]>z + 1)
			{
				d[j] = z + 1;
			}
		}
	}

	return d[n];
}

int main()
{

	//��ȡtxt�ļ�����
	int n = 0;
	char a[100], b[100];
	ifstream file;
	file.open("data\\input.txt", ios::in);
	if (file.fail())
	{
		cout << "�ļ�������." << endl;
		file.close();
		cin.get();
		cin.get();
	}
	file >> a;
	file >> b;
	string aa = a;
	string bb = b;

	int d = ShotEditDistance(aa, bb);

	//�����������output.txt��
	ofstream out;
	out.open("data\\output.txt", ios::out);
	out << d << "\n";

	cout << "The shortest editing distance is : " << d << endl;
	system("pause");
}
