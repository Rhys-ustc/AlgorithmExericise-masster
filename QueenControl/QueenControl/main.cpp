/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   main.cpp
*   ���⣺���һ����˹ά��˹�㷨�����ڸ�������Ȼ��n ������ nxn��������ɵ�����������Ҫ���ö��ٸ��ʺ���ܿ��������ϵ����з����ҷ��õĻʺ󻥲�������
*   
*/
#include"queencontrol.h"

int main()
{
	int n;
	ifstream infile("data\\input.txt");
	infile >> n;
	bool result =  nQueen(n);
	return 0;
}