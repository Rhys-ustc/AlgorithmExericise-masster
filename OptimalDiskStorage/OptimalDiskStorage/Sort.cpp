#include"Sort.h"

void InsertSort(int *x, int n)
{
	int key = 0;
	for (int i = 1; i < n; i++)
	{
		key = x[i];
		int j = i - 1;
		for ( ; j >= 0; j--)
		{
			if (key < x[j])
			{
				x[j + 1] = x[j];
			}
			else
			{
				break;
			}
		}
		x[j + 1] = key;
	}

}


