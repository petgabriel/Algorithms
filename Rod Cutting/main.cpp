#include "header.h"

int main(int argc,char* argv[])
{
	rod R;

	int n;

#ifdef USERS_DATA

	int i = 0;
	int* p;

	cout << "Size of price array: ";
	cin >> n;

	int tmp = n;

	p = (int*)calloc(n, sizeof(int));
	
	cout << endl;

	while (tmp--)
	{
		int k;
		
		cout << "Price for length " << i + 1 << ": ";
		cin >> k;

		p[i] = k;
		i++;
	}

	R = rod(p, n);
	
#else

	cout << "Size of price array: ";
	cin >> n;

	R = rod(n);

#endif

	int N;
	cout << "Enter number to find solution: ";
	cin >> N;

	if (N > n)
	{
		cout << "Solution doesn't exist!" << endl;
	}

	cout << endl << "Cut rod: " << R.cut_rod(N) << endl;
	cout << "Memoized top-down cut rod: " << R.memoized_cut_rod(N) << endl;
	cout << "Memoized bottom-up cut rod: " << R.bottom_up_cut_rot(N) << endl << endl;
	cout << "Solution to length " << N <<": ";
	R.print_cut_rod_solution(N);
	cout << endl;

	system("pause");

	return 0;
}
