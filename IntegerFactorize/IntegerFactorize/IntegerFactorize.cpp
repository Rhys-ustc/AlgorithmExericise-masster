/* 
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   �������ӷֽ�IntegerFactorize.cpp
*   ���⣺���� ������n ���� n ��������ʽ�ֽ⣨��6=3*2,6=2*3,6=6��.
    ���������n�ķֽ���������������6�����3����
	������ �ݹ飬�ֽܷ���Ŀ����ÿ�����ӵķֽ����������

*/

#include<iostream>
#include<fstream>

using namespace std;

/* Factorize�� int n��
   ���������ӷֽ⺯��
   n:���������� n>0
   ���أ�n���������ӷֽ�������
*/
int Factorize(int n)
{
	
	int count = 0;

	if (n <= 0)
	{
		cout << "The input number must be positive : n >0" << endl;
	}
	//�߽�����
	if (1 == n) return  1;
	//�ݹ����
	for (int i = 2; i <= n / 2; i++)
	{
		//�õ� 1�����ӣ�������һ��С�ڵ���n/2
		if ( n%i ==0)
		{
			//���ϸ����ӵķֽ����������ݹ���̣�
			count = count + Factorize(i);
		}

	}
	// n ����ҲΪ���ӣ�+1
	count++;
	return count;
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
		 file >> n;  //�ļ���һ�е����ݴ����n��
		// cout << n;
	 }

	 //�������ӷֽ���㺯��
	 int count = Factorize(n);

	 //�����������output.txt��
	 ofstream out;
	 out.open("data\\output.txt", ios::out);
	 out << count << "\n";
	 //�ն�������
	 cout <<" result is : "<< count << endl;
	 system("pause");
}
