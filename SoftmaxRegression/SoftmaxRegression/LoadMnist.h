#ifndef LOADMNIST_H
#define LOADMNIST_H

#include <iostream>
using namespace std;

void LoadMnistData(string imgPath, string labelPath, double *m_data, int *m_label, int nRows, int nCols);
void Normalize(double *data, int N);

#endif