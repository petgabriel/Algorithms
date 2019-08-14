#include "header.h"

int main(int argc, char* argv[])
{
	srand( (unsigned int)time( NULL ) );

	tree T;

	node* a = new node(500);

	T.tree_insert(a);

	for (int i = 1; i <= 10; i++)
	{
		int t = rand() % 1000 + 1;
		node* tmp = new node(t);
		cout << t << " ";
		T.tree_insert(tmp);
	}

	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

	T.print_tree();

	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

	cout << "Minimum: " << T.tree_minimum(T.root)->key << endl;
	cout << "Maximum: " << T.tree_maximum(T.root)->key << endl << endl;

	cout << "Height of tree: " << T.tree_height(T.root) << endl << endl;

	cout << "Inorder walk: ";
	T.inorder_walk(T.root);
	cout << endl;

	cout << "Preorder walk: ";
	T.preorder_walk(T.root);
	cout << endl;

	cout << "Postorder walk: ";
	T.postorder_walk(T.root);
	cout << endl << endl;

	int k = rand() % 1000 + 1;

	cout << "Searching for: " << k << " -> ";

	node* z = T.tree_search(T.root, k);

	if (z != NULL)
	{
		cout << "Found! " << endl;
	}
	else
	{
		cout << "No node with this key!" << endl;
	}

	node* successor = T.tree_successor(T.root);
	
	if (successor != NULL)
	{
		cout << "Successor of root: " << successor->key << endl;
	}

	else
	{
		cout << "There is no successor of root!" << endl;
	}

	cout << endl << "Deleting root: " << endl;

	T.tree_delete(T.root);

	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

	T.print_tree();

	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

	system("pause");

	return 0;
}
