/* 
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   最大间隔函数MaxGap.cpp
*   问题：给定 n 个实数，求 n 个实数在数轴上相邻元素的最大差值。要求算法的时间复杂度为 O（n）.
	方法： 利用桶排序在O(n)时间完成排序，再通过线性查找最大间隔，故总时间复杂度为O(n).
	编程策略： 由于只需输出相邻数的最大间隔，而最大间隔一定不会出现在同一个桶中，只会是相邻桶的最小元素和最大元素的差。
               故实际并不需要保存桶中的所有元素，只需记录桶的下标，每个桶的最大值和最小值即可。
*/

#include<iostream>
#include<fstream>

using namespace std;

// 查找x数组中的最大值
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

//查找x数组中的最小值
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

/*MaxGap（double* x, int n）
   求最大间隔函数
   x: 输入数组，未经排序
   n： 数组的大小
   返回x中在实轴上相邻的两元素的最大差值
*/
double MaxGap(double *x, int n)
{
	double max_x = MaxValue(x,n);
	double min_x = MinValue(x,n);

	// 新建 n+1 个桶，其中每个桶只需要记录元素的个数，桶中的最小值和最大值
	int *count = new int[n+1];
	double *low = new double[n+1];
	double *high = new double[n+1];
	int bucket_i = 0; //记录桶标号

	//初始化桶
	for (int i = 0; i < n+1 ; i++)
	{
		count[i] = 0;
		low[i] = max_x;
		high[i] = min_x;
	}

	//桶排序，记录每个桶的元素个数和最值
	for (int i = 0; i < n; i++)
	{
		bucket_i = int(n*(x[i]-min_x)/(max_x-min_x)); //将x[i]归一化到[0,1],并放入对应的桶中
		count[bucket_i]++;
		if (low[bucket_i]>x[i]) low[bucket_i] = x[i];  //实际只保存了每个桶中的最大元素和最小元素
		if (high[bucket_i] < x[i]) high[bucket_i] = x[i];

	}

	//查找最大间隔
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
	 else
	 {
		 file >> n;  //文件第一行的数据表示数据元素总个数，存放在n中
		// cout << n;
	 }
	 double *x = new double[n];
	 int count = 0;
	 file.seekg(1, ios::cur); //文件指针后移一位，开始读取数据
	 while (!file.eof())
	 {
		 file >> x[count];
		 count++;
	 }
	//int n = 5;
	//double x[5] = { 2.3 ,3.1 ,7.5 ,1.5 ,6.3 };
	 double maxgag = MaxGap(x,n);

	 //将结果保存在output.txt中
	 ofstream out;
	 out.open("data\\output.txt", ios::out);
	 out << maxgag << "\n";

	 cout <<"The max gap is : "<< maxgag << endl;
	 system("pause");
}
