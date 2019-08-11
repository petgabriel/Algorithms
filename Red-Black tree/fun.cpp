#include "header.h"

node::node(int key)
{
	this->key = key;
	left = right = p = NULL;
	c = RED;
}

tree::tree()
{
	root = NULL;
}

void tree::RB_insert(node* &z)
{
	node* y = NULL;
	node* x = this->root;

	while( x != NULL )
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
		this->root = z;
	}
	
	else if (z->key < y->key)
	{
		y->left = z;
	}

	else
	{
		y->right = z;
	}

	z->left = NULL;
	z->right = NULL;
	z->c = RED;
}

void tree::RB_insert_fixup(node* &z)
{

}

void tree::left_rotate(node* &x)
{

}

void tree::right_rotate(node* &x)
{

}

void print_RB_Util(node* root, int space)
{
	if (root == NULL) return;
	
	space += COUNT;
	
	print_RB_Util(root->right, space);

	cout << endl;
	for( int i = COUNT; i < space; i++ )
		cout << " ";
	cout << root->key <<":" << root->c << endl;

	print_RB_Util(root->left, space);
}
 
void tree::print_RB_tree()
{
	print_RB_Util(this->root, 0);
}