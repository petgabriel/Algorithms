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

node* tree::tree_minimum(node* &z)
{
	node* x = z;

	while (x->left != NULL)
	{
		x = x->left;
	}

	return x;
}

node* tree::tree_maximum(node* &z)
{
	node* x = z;

	while (x->right != NULL)
	{
		x = x->right;
	}

	return x;
}

node* tree::tree_successor(node* &z)
{
	if (z->right != NULL)
	{
		return tree_minimum(z->right);
	}

	node* y = z->p;
	node* ptr = z;

	while (y != NULL && ptr == y->right)
	{
		ptr = y;
		y = y->p;
	}

	return y;
}

void tree::transplant(node* &u, node* &v)
{
	if (u->p == NULL)
	{
		root = v;
	}
	
	else if (u == u->p->left)
	{
		u->p->left = v;
	}

	else
	{
		u->p->right = v;
	}

	if (v != NULL)
	{
		v->p = u->p;
	}
}

void tree::tree_delete(node* &z)
{
	if (z->left == NULL)
	{
		transplant(z, z->right);
	}

	else if (z->right == NULL)
	{
		transplant(z, z->left);
	}

	else
	{
		node* y = tree_minimum(z->right);

		if (y->p != z)
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->p = y;
		}

		node* ptr = z;
		transplant(ptr, y);
		y->left = ptr->left;
		y->left->p = y;
	}
}

int tree::tree_height(node* &z)
{
	if (z == NULL)
	{
		return 0;
	}

	return max(tree_height(z->left), tree_height(z->right)) + 1;
}

void tree::inorder_walk(node* &z)
{
	if (z != NULL)
	{
		inorder_walk(z->left);
		cout << z->key << " ";
		inorder_walk(z->right);
	}
}

void tree::postorder_walk(node* &z)
{
	if (z != NULL)
	{
		inorder_walk(z->left);
		inorder_walk(z->right);
		cout << z->key << " ";
	}
}

void tree::preorder_walk(node* &z)
{
	if (z != NULL)
	{
		cout << z->key << " ";
		inorder_walk(z->left);
		inorder_walk(z->right);
	}
}

void tree::print_Util(node* root, int space)
{
	if (root == NULL) return;

	space += COUNT;

	print_Util(root->right, space);

	cout << endl;
	
	for (int i = COUNT; i < space; i++)
	{
		cout << " ";
	}

	cout << root->key << endl;

	print_Util(root->left, space);
}

void tree::print_tree()
{
	print_Util(root, 0);
}
