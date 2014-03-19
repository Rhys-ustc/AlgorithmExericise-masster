/* 
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   整数因子分解IntegerFactorize.cpp
*   问题：给定 正整数n ，求 n 的所有因式分解（如6=3*2,6=2*3,6=6）.
    输出：给出n的分解种类数（如输入6，输出3）。
	方法： 递归，总分解数目等于每个因子的分解种类数相加

*/

#include<iostream>
#include<fstream>

using namespace std;

/* Factorize（ int n）
   正整数因子分解函数
   n:输入正整数 n>0
   返回：n的所有因子分解种类数
*/
int Factorize(int n)
{
	
	int count = 0;

	if (n <= 0)
	{
		cout << "The input number must be positive : n >0" << endl;
	}
	//边界条件
	if (1 == n) return  1;
	//递归调用
	for (int i = 2; i <= n / 2; i++)
	{
		//得到 1个因子，该因子一定小于等于n/2
		if ( n%i ==0)
		{
			//加上该因子的分解种类数（递归过程）
			count = count + Factorize(i);
		}

	}
	// n 自身也为因子，+1
	count++;
	return count;
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
		 file >> n;  //文件第一行的数据存放在n中
		// cout << n;
	 }

	 //调用因子分解计算函数
	 int count = Factorize(n);

	 //将结果保存在output.txt中
	 ofstream out;
	 out.open("data\\output.txt", ios::out);
	 out << count << "\n";
	 //终端输出结果
	 cout <<" result is : "<< count << endl;
	 system("pause");
}
