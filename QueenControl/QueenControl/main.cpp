/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   main.cpp
*   问题：设计一个拉斯维加斯算法，对于给定的自然数n 计算在 nxn个方格组成的棋盘上最少要放置多少个皇后才能控制棋盘上的所有方格，且放置的皇后互不攻击。
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