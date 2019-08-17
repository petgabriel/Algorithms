#include "header.h"

MatrixChain::MatrixChain(int n, int* p)
{
	this->n = n;
	this->p = p;

	m = (int**)calloc(n + 1, sizeof(int*));
	s = (int**)calloc(n + 1, sizeof(int*));

	for (int i = 0; i <= n; i++)
	{
		m[i] = (int*)calloc(n + 1, sizeof(int));
		s[i] = (int*)calloc(n + 1, sizeof(int));
	}
}

void MatrixChain::matrix_chain_order()
{
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}

	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;

			m[i][j] = INT_MAX;
		
			for (int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void MatrixChain::print_optimal_parens(int i, int j)
{
	if (i == j)
	{
		cout << "A[" << i << "]";
	}

	else
	{
		cout << "(";
		print_optimal_parens(i, s[i][j]);
		print_optimal_parens(s[i][j] + 1, j);
		cout << ")";
	}
}

int MatrixChain::recursive_matrix_chain(int i, int j)
{
	if (i == j)
	{
		return 0;
	}

	m[i][j] = INT_MAX;

	for (int k = i; k <= j - 1; k++)
	{
		int q = recursive_matrix_chain(i, k) + recursive_matrix_chain(k + 1, j) + p[i - 1] * p[k] * p[j];

		if (q < m[i][j])
		{
			m[i][j] = q;
		}
	}

	return m[i][j];
}

int MatrixChain::memoized_matrix_chain()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			m[i][j] = INT_MAX;
		}
	}

	return lookup_chain(1, n);
}

int MatrixChain::lookup_chain(int i, int j)
{
	if (m[i][j] < INT_MAX)
	{
		return m[i][j];
	}

	if (i == j)
	{
		m[i][j] = 0;
	}
	
	else
	{
		for (int k = i; k <= j - 1; k++)
		{
			int q = recursive_matrix_chain(i, k) + recursive_matrix_chain(k + 1, j) + p[i - 1] * p[k] * p[j];

			if (q < m[i][j])
			{
				m[i][j] = q;
			}
		}
	}

	return m[i][j];
}
