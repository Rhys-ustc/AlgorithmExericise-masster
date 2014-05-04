/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*  �����������⣺
*  ������
*/
#include<iostream>
#include<fstream>

int m, n, sum;
int a[200][200];

using namespace std;

void swap(int &x, int &y)
{
	int temp;
	temp = x; x = y; y = temp;

}

bool bound(int r, int c)
{
	int i;
	for (i = 1; i<r; i++)
	if (a[i][c] == a[r][c])  return false;
	return true;
}

void backtrack(int r, int c)
{
	int i, j;
	if (r>m)          //������ݹ�����Ҫ����r��c��ͬ������r����У�c�����
	{
		sum++;
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
		printf("\n");
		return;
	}
	if (c>n)
	{
		backtrack(r + 1, 1);
	}
	for (j = c; j <= n; j++)
	{
		swap(a[r][c], a[r][j]);
		if (bound(r, c))   backtrack(r, c + 1);
		swap(a[r][c], a[r][j]);
	}
}

int main()
{

	//��ȡtxt�ļ�����

	ifstream file;
	file.open("data\\input.txt", ios::in);
	if (file.fail())
	{
		cout << "�ļ�������." << endl;
		file.close();
		cin.get();
		cin.get();
	}
	file >> m;
	file >> n;

	// ��ʼ��boad���飬�����ʯ
	sum = 0;

	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		a[i][j] = j;

	for (int i = 2; i <= n; i++)
		swap(a[i][1], a[i][i]);

	backtrack(1, 1);	

	//�����������output.txt��
	ofstream out;
	out.open("data\\output.txt", ios::out);
	out << sum << "\n";

	cout << sum << endl;
	//system("pause");
}