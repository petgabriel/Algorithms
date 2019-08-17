#include "header.h"

int main(int argc, char* argv[])
{
	int N = 6;

	int* p;

	p = (int*)calloc(N + 1, sizeof(int));

	p[0] = 5;
	p[1] = 10;
	p[2] = 3;
	p[3] = 12;
	p[4] = 5;
	p[5] = 50;
	p[6] = 6;

	MatrixChain M = MatrixChain(N, p);

	M.matrix_chain_order();
	cout << M.recursive_matrix_chain(1, N) << endl;
	cout << M.memoized_matrix_chain() << endl;
	M.print_optimal_parens(1, N);
	
	cout << endl;

	system("pause");

	return 0;
}