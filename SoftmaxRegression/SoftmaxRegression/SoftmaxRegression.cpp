#include"SoftmaxRegression.h"

// Softmax
Softmax::Softmax( int in, int out) 
{
	n_in = in;
	n_out = out;
	// initialize W[n_out][n_in], b[n_out] 
	W = new double*[n_out];
	for (int i = 0; i<n_out; i++) W[i] = new double[n_in];
	b = new double[n_out];

	for (int i = 0; i<n_out; i++) 
	{
		for (int j = 0; j<n_in; j++) 
		{
			W[i][j] = 0;
		}
		b[i] = 0;
	}
}

Softmax::~Softmax() 
{
	for (int i = 0; i<n_out; i++) delete[] W[i];
	delete[] W;
	delete[] b;
}

/* Train()
   train the softmax via stochastic gradient descent

*/
void Softmax::Train(double *x, int *y, int N, double lr, double lamda, int epochs) 
{	

	double *p_y_given_x = new double[n_out];
	double *dy = new double[n_out];
	double *tmp_x = new double[n_in];

	for (int epoch = 0; epoch < epochs; epoch++)
	{
		cout << "epoch:" << setw(3) << epoch + 1 << endl;

		for (int n = 0; n < N; n++)
		{
			// choose one sample 
			for (int i = 0; i < n_in; i++)
			{
				tmp_x[i] = x[n*n_in + i];
			}
		    //ShowImg(tmp_x, 28, 28);
			//cout << y[n] << endl;
			
			// compute softmax value
			for (int i = 0; i<n_out; i++) 
			{
				p_y_given_x[i] = 0;
				for (int j = 0; j<n_in; j++) 
				{
					p_y_given_x[i] += W[i][j] * tmp_x[j];
				}
				p_y_given_x[i] += b[i];
			}
			softmax(p_y_given_x);

			// update the weight 
			// w_new = w_old + learningRate * differential (µ¼Êý)
			//		 = w_old + learningRate * x (1{y_i=y} - p_yi_given_x) 
			//		 = w_old + learningRate * x * (y - p_y_given_x)
			for (int i = 0; i<n_out; i++)
			{
				// compute the gradient 
				if (i == (y[n] % n_out))
				{
					dy[i] = 1 - p_y_given_x[i];
				}
				else
				{
					dy[i] = -p_y_given_x[i];
				}
				// update
				for (int j = 0; j<n_in; j++) 
				{
					W[i][j] += lr * (dy[i] * tmp_x[j] - lamda * W[i][j]);
				}

				b[i] += lr * dy[i];
			}
		}

	}
	
	delete[] p_y_given_x;
	delete[] dy;
}

/* softmax()
   get the softmax value

*/
void Softmax::softmax(double *x) 
{
	 
	double sum = 0.0;

	for (int i = 0; i<n_out; i++) 
	{
		x[i] = exp(x[i]);
		sum += x[i];
	}

	for (int i = 0; i<n_out; i++) x[i] /= sum;

}

// predict 
double Softmax::Predict(double *x, int test_N, int *y) 
{

	double precision = 0;
	double *tmp_y = new double[n_out];
	double tmp_max = 0;
	int tmp_Y = -1;

	for (int n = 0; n < test_N; n++)
	{

		for (int i = 0; i<n_out; i++)
		{
			tmp_y[i] = 0;
			for (int j = 0; j<n_in; j++)
			{
				tmp_y[i] += W[i][j] * x[n*n_in +j];
			}
			tmp_y[i] += b[i];
		}
		// find the index which has the max probability 
		tmp_max = tmp_y[0];
		tmp_Y = 0;
		for (int i = 1; i < n_out; i++)
		{
			if (tmp_y[i]>tmp_max)
			{
				tmp_max = tmp_y[i];
				tmp_Y = i;
			}
		}
		// compare the output label to the real label 
		if ((y[n] % n_out) == tmp_Y) { precision++; }

	}
    
	return precision/test_N;

}
