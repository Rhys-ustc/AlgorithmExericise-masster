#ifndef SOFTMAXREGRESSION_H
#define SOFTMAXREGRESSION_H
#include <math.h>
#include<iostream>
#include<iomanip>
#include"ShowImages.h"

using namespace std;

class Softmax {

public:
	int n_in;
	int n_out;

	Softmax(int in, int out);
	~Softmax();
private:
	double **W;
	double *b;

public:
	void Train(double *train_X, int *train_Y, int train_N, double lr, double lamda, int epochs);
	double Predict(double *test_X, int test_N, int *test_Y);
private:
	void softmax(double *x);

};

#endif