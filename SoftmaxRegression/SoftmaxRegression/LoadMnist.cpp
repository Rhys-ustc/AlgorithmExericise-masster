#include "LoadMnist.h"

/*LoadMnistData()
将Mnist中的数据读入数组中
参数说明：
	imgPath----读取的mnist二进制数据文件路径（traindata.a或者testdata.a）
	labelPath----读取的mnist二进制标签文件路径（trainlabel.a或者testlabel.a）
	m_data----写入的数据
	m_label----写入的标签
	nRows----每个特征样本的维度
	nCols----读入的样本个数
*/
void LoadMnistData(string imgPath, string labelPath, double *m_data,int *m_label, int nRows, int nCols)
{
	FILE *fin;
	fopen_s(&fin, imgPath.c_str(), "rb");
	unsigned char b;
	for (int i=0;i<17;i++)
	{
		fread(&b, sizeof(unsigned char), 1, fin);
	}	
	for (int i=0; i<nCols*nRows; i++)
	{
		fread(&b, sizeof(unsigned char), 1, fin);
		m_data[i] = (double)b;
	}
	fclose(fin);
	FILE *finlabel;
	fopen_s(&finlabel, labelPath.c_str(), "rb");
	for(int i=0;i<8;i++)
	{
		fread(&b, sizeof(unsigned char), 1, finlabel);
	}
	for (int i=0; i<nCols; i++)
	{
		fread(&b, sizeof(unsigned char), 1, finlabel);
		m_label[i] = b == 0? 10 : (int) b;
	}
	fclose(finlabel);
}

/* LoadMnistFeatures()
   load the MNIST features from  2 layer SdA 
   
*/
void LoadMnistFeatures(string imgPath, string labelPath, double *m_data, int *m_label, int nRows, int nCols)
{

}
/*
   归一化数据
*/
void Normalize(double *data, int N)
{
	double maxval = 255;
	for (int i = 0; i < N; i++)
	{
		data[i] /= 255;
	}
}
