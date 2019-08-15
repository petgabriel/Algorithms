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
	s = (int*)calloc(n + 1, sizeof(int));

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
	s = (int*)calloc(n + 1, sizeof(int));
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

int rod::bottom_up_cut_rot(int n)
{
	r[0] = 0;

	for (int j = 1; j <= n; j++)
	{
		int q = INT_MIN;

		for (int i = 1; i <= j; i++)
		{
			q = max(q, p[i - 1] + r[j - i]);
		}

		r[j] = q;
	}

	return r[n];
}

void rod::extended_bottom_up_cut_road(int n)
{
	r[0] = 0;

	for (int j = 1; j <= n; j++)
	{
		int q = INT_MIN;

		for (int i = 1; i <= j; i++)
		{
			if (q < p[i - 1] + r[j - i])
			{
				q = p[i - 1] + r[j - i];
				s[j] = i;
			}
		}

		r[j] = q;
	}
}

void rod::print_cut_rod_solution(int n)
{
	extended_bottom_up_cut_road(n);

	while (n > 0)
	{
		cout << s[n] << " ";
		n = n - s[n];
	}

	cout << endl;
}

void rod::print_prices()
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " -> " << p[i] << endl;
	}

	cout << endl;
}
