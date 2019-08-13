#include "header.h"

int main(int argc, char* argv[])
{
	srand( (unsigned int)time( NULL ) );

	tree T;

	for (int i = 1; i <= 8; i++)
	{
		int t = rand() % 1000 + 1;
		node* tmp = new node(t);
		cout << t << " ";
		T.tree_insert(tmp);
	}

	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

	T.print_tree();

	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

	cout << "minimum: " << T.tree_minimum()->key << endl;
	cout << "maximum: " << T.tree_maximum()->key << endl;

	int k = rand() % 1000 + 1;

	cout << "searching for: " << k << " -> ";

	node* z = T.tree_search(T.root, k);

	if (z != NULL)
	{
		cout << "found! " << endl;
	}
	else
	{
		cout << "No node with this key!" << endl;
	}
	
	system("pause");
	return 0;
}
