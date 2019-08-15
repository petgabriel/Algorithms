#include "header.h"

int main(int argc,char* argv[])
{
	rod R;

#ifdef USERS_DATA

	int i = 0;
	int n;
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

	int n;

	cout << "Size of price array: ";
	cin >> n;

	R = rod(n);

#endif

	int N = 4;

	cout << "Cut rod: " << R.cut_rod(N) << endl;
	cout << "Memoized cut rod: " << R.memoized_cut_rod(N) << endl;

	system("pause");

	return 0;
}