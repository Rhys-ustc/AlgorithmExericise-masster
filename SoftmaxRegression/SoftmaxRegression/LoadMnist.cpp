#include "LoadMnist.h"

/*LoadMnistData()
��Mnist�е����ݶ���������
����˵����
	imgPath----��ȡ��mnist�����������ļ�·����traindata.a����testdata.a��
	labelPath----��ȡ��mnist�����Ʊ�ǩ�ļ�·����trainlabel.a����testlabel.a��
	m_data----д�������
	m_label----д��ı�ǩ
	nRows----ÿ������������ά��
	nCols----�������������
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
   ��һ������
*/
void Normalize(double *data, int N)
{
	double maxval = 255;
	for (int i = 0; i < N; i++)
	{
		data[i] /= 255;
	}
}
