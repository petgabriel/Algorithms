#include "header.h"

rod::rod()
{

}

rod::rod(int n)
{
	srand((unsigned int)time(NULL));

	this->n = n;

	p = (int*)calloc(n, sizeof(int));
	r = (int*)calloc(n + 1, sizeof(int));
	s = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 100 + 1;
	}
}

rod::rod(int* p, int n)
{
	this->n = n;
	this->p = p;

	r = (int*)calloc(n + 1, sizeof(int));
	s = (int*)calloc(n, sizeof(int));
}

int rod::cut_rod(int n)
{
	if (n == 0)
	{
		return 0;
	}

	int q = INT_MIN;

	for (int i = 1; i <= n; i++)
	{
		q = max(q, p[i - 1] + cut_rod(n - i));
	}

	return q;
}

int rod::memoized_cut_rod(int n)
{
	for (int i = 0; i <= n; i++)
	{
		r[i] = INT_MIN;
	}
	
	return memoized_cut_rod_aux(n);
}

int rod::memoized_cut_rod_aux(int n)
{
	if (r[n] >= 0)
	{
		return r[n];
	}

	int q;

	if (n == 0)
	{
		q = 0;
	}

	else
	{
		q = INT_MIN;

		for (int i = 1; i <= n; i++)
		{
			q = max(q, p[i - 1] + memoized_cut_rod_aux(n - i));
		}
	}

	r[n] = q;

	return q;
}

void rod::print_prices()
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " -> " << p[i] << endl;
	}

	cout << endl;
}