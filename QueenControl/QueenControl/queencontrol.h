#include <iostream>   
#include <fstream>   
#include <time.h>   
#include <math.h>   
#include <stdlib.h>   

using namespace std;

const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;

//随机数类   
class RandomNumber
{
public:
	//构造函数，缺省值0表示由系统自动产生种子   
	RandomNumber(unsigned long s = 0);
	//产生0:n-1之间的随机整数   
	unsigned short Random(unsigned long n);
	//产生[0,1)之间的随机实数   
	double fRandom(void);
private:
	//当前种子   
	unsigned long randSeed;
};

//2维数组类   
template <class T>
void Make2DArray(T** &x, int rows, int cols)
{
	//创建行指针   
	x = new T*[rows];
	//为每行分配空间   
	for (int j = 0; j < rows; j++)
	{
		x[j] = new T[cols];
	}
}

template <class T>
void Delete2DArray(T** &x, int rows)
{
	//释放为每行所分配的空间   
	for (int j = 0; j < rows; j++)
	{
		delete[] x[j];
	}
	//删除行指针   
	delete[] x;
	x = NULL;
}

class Queen
{
	friend bool nQueen(int);
private:
	bool Place(int k);//测试皇后k置于第x[k]列的合法性   
	bool Backtrack(int t);//解n后问题的回溯法   
	bool ddBacktrack(int t);//迭代法   
	int Placenum(int k);//暂时不用,计算已放置皇后个数   
	int QueensLV(int stopVegas);//随机放置n个皇后的拉斯维加斯算法   
	bool ctrl(int m);//测试皇后是否已控制棋盘   
	int n,//皇后个数   
		*x, *y, *a, **z;//x[k]表示：第k行皇后置于第x[k]列   
	//y是用来记录每行皇后可行位置   
	//a是用来记录最优解皇后位置   
	//z是用来记录皇后控制的方格   
	int cmin, c;//cmin记录最优皇后个数，c为当前个数   
	RandomNumber rnd;//随机数产生器定义在类里,随机效果更好   
};