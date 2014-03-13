/* 
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   ���������MaxGap.cpp
*   ���⣺���� n ��ʵ������ n ��ʵ��������������Ԫ�ص�����ֵ��Ҫ���㷨��ʱ�临�Ӷ�Ϊ O��n��.
	������ ����Ͱ������O(n)ʱ�����������ͨ�����Բ��������������ʱ�临�Ӷ�ΪO(n).
	��̲��ԣ� ����ֻ���������������������������һ�����������ͬһ��Ͱ�У�ֻ��������Ͱ����СԪ�غ����Ԫ�صĲ
               ��ʵ�ʲ�����Ҫ����Ͱ�е�����Ԫ�أ�ֻ���¼Ͱ���±꣬ÿ��Ͱ�����ֵ����Сֵ���ɡ�
*/

#include<iostream>
#include<fstream>

using namespace std;

// ����x�����е����ֵ
double MaxValue(double *x, int n)
{
	double maxvalue = x[0];
	for (int i = 1; i < n; i++)
	{
		if (maxvalue < x[i])
		{
			maxvalue = x[i];
		}
	}
	return maxvalue;
}

//����x�����е���Сֵ
double MinValue(double* x, int n)
{
	double minvalue = x[0];
	for (int i = 1; i < n; i++)
	{
		if (minvalue > x[i])
		{
			minvalue = x[i];
		}
	}
	return minvalue;
}

/*MaxGap��double* x, int n��
   �����������
   x: �������飬δ������
   n�� ����Ĵ�С
   ����x����ʵ�������ڵ���Ԫ�ص�����ֵ
*/
double MaxGap(double *x, int n)
{
	double max_x = MaxValue(x,n);
	double min_x = MinValue(x,n);

	// �½� n+1 ��Ͱ������ÿ��Ͱֻ��Ҫ��¼Ԫ�صĸ�����Ͱ�е���Сֵ�����ֵ
	int *count = new int[n+1];
	double *low = new double[n+1];
	double *high = new double[n+1];
	int bucket_i = 0; //��¼Ͱ���

	//��ʼ��Ͱ
	for (int i = 0; i < n+1 ; i++)
	{
		count[i] = 0;
		low[i] = max_x;
		high[i] = min_x;
	}

	//Ͱ���򣬼�¼ÿ��Ͱ��Ԫ�ظ�������ֵ
	for (int i = 0; i < n; i++)
	{
		bucket_i = int(n*(x[i]-min_x)/(max_x-min_x)); //��x[i]��һ����[0,1],�������Ӧ��Ͱ��
		count[bucket_i]++;
		if (low[bucket_i]>x[i]) low[bucket_i] = x[i];  //ʵ��ֻ������ÿ��Ͱ�е����Ԫ�غ���СԪ��
		if (high[bucket_i] < x[i]) high[bucket_i] = x[i];

	}

	//���������
	double maxgap = 0;
	double temp_gap = 0;
	double pre_high = high[0];
	for (int i = 1; i < n+1 ; i++)
	{
		if (count[i]>0)
		{
			temp_gap = low[i] - pre_high;
			if (maxgap < temp_gap)
			{
				maxgap = temp_gap;
			}
			pre_high = high[i];
		}
	}

	return maxgap;
}

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
	 else
	 {
		 file >> n;  //�ļ���һ�е����ݱ�ʾ����Ԫ���ܸ����������n��
		// cout << n;
	 }
	 double *x = new double[n];
	 int count = 0;
	 file.seekg(1, ios::cur); //�ļ�ָ�����һλ����ʼ��ȡ����
	 while (!file.eof())
	 {
		 file >> x[count];
		 count++;
	 }
	//int n = 5;
	//double x[5] = { 2.3 ,3.1 ,7.5 ,1.5 ,6.3 };
	 double maxgag = MaxGap(x,n);

	 //�����������output.txt��
	 ofstream out;
	 out.open("data\\output.txt", ios::out);
	 out << maxgag << "\n";

	 cout <<"The max gap is : "<< maxgag << endl;
	 system("pause");
}
