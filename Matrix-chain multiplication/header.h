#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <time.h>
#include <memory.h>
#include <windows.h>

class MatrixChain
{
public:
	int n;

	int* p;
	
	int** m;
	int** s;

	MatrixChain(int n, int* p);

	int recursive_matrix_chain(int i, int j);
	int lookup_chain(int i, int j);
	int memoized_matrix_chain();

	void matrix_chain_order();
	void print_optimal_parens(int i, int j);
};
