#include "header.h"

node::node(int key)
{
	this->key = key;
	left = right = p = NULL;
}

tree::tree()
{
	root = NULL;
}

void tree::tree_insert(node* &z)
{
	node* y = NULL;
	node* x = root;

	while (x != NULL)
	{
		y = x;

		if (z->key < x->key)
		{
			x = x->left;
		}

		else
		{
			x = x->right;
		}
	}

	z->p = y;

	if (y == NULL)
	{
		root = z;
	}

	else if (z->key < y->key)
	{
		y->left = z;
	}

	else
	{
		y->right = z;
	}
}

node* tree::tree_search(node* &z, int k)
{
	if (z == NULL or k == z->key)
	{
		return z;
	}

	if (k < z->key)
	{
		return tree_search(z->left, k);
	}

	else
	{
		return tree_search(z->right, k);
	}
}

node* tree::tree_minimum()
{
	node* x = root;

	while (x->left != NULL)
	{
		x = x->left;
	}

	return x;
}

node* tree::tree_maximum()
{
	node* x = root;

	while (x->right != NULL)
	{
		x = x->right;
	}

	return x;
}

void tree::print_Util(node* root, int space)
{
	if (root == NULL) return;

	space += COUNT;

	print_Util(root->right, space);

	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->key << endl;

	print_Util(root->left, space);
}

void tree::print_tree()
{
	print_Util(root, 0);
}
