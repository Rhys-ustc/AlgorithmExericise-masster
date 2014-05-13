#include <iostream>   
#include <fstream>   
#include <time.h>   
#include <math.h>   
#include <stdlib.h>   

using namespace std;

const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;

//�������   
class RandomNumber
{
public:
	//���캯����ȱʡֵ0��ʾ��ϵͳ�Զ���������   
	RandomNumber(unsigned long s = 0);
	//����0:n-1֮����������   
	unsigned short Random(unsigned long n);
	//����[0,1)֮������ʵ��   
	double fRandom(void);
private:
	//��ǰ����   
	unsigned long randSeed;
};

//2ά������   
template <class T>
void Make2DArray(T** &x, int rows, int cols)
{
	//������ָ��   
	x = new T*[rows];
	//Ϊÿ�з���ռ�   
	for (int j = 0; j < rows; j++)
	{
		x[j] = new T[cols];
	}
}

template <class T>
void Delete2DArray(T** &x, int rows)
{
	//�ͷ�Ϊÿ��������Ŀռ�   
	for (int j = 0; j < rows; j++)
	{
		delete[] x[j];
	}
	//ɾ����ָ��   
	delete[] x;
	x = NULL;
}

class Queen
{
	friend bool nQueen(int);
private:
	bool Place(int k);//���Իʺ�k���ڵ�x[k]�еĺϷ���   
	bool Backtrack(int t);//��n������Ļ��ݷ�   
	bool ddBacktrack(int t);//������   
	int Placenum(int k);//��ʱ����,�����ѷ��ûʺ����   
	int QueensLV(int stopVegas);//�������n���ʺ����˹ά��˹�㷨   
	bool ctrl(int m);//���Իʺ��Ƿ��ѿ�������   
	int n,//�ʺ����   
		*x, *y, *a, **z;//x[k]��ʾ����k�лʺ����ڵ�x[k]��   
	//y��������¼ÿ�лʺ����λ��   
	//a��������¼���Ž�ʺ�λ��   
	//z��������¼�ʺ���Ƶķ���   
	int cmin, c;//cmin��¼���Żʺ������cΪ��ǰ����   
	RandomNumber rnd;//���������������������,���Ч������   
};