#include"GreadyDiskStore.h"


double GreadyDiskStore(int *p, int n)
{
	double t = 0;
	int sum = 0;
	int *x = new int[n];
	int  k = (n - 1) / 2;
	// sort the p
    InsertSort(p, n);
	// put the file from middle to the sides
	x[k] = p[n-1];
	for (int i = k - 1; i >=0; i--)
	{
		x[i] = p[n - 2 * (k - i) - 1];
	}
	for (int i = k+1; i < n; i++)
	{
		x[i] = p[n - 2 * (i - k)];
	}
	// compute the expected search time 
	for (int i = 0; i < n; i++)
	{
		sum += x[i];
		for (int j = i+1; j < n; j++)
		{
			t += x[i] * x[j] * (j-i);
		}
	}
	t = t / sum / sum;

	return t;
}
