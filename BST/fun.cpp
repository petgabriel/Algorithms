#include "header.h"

node::node(int key)
{
	this->key = key;
	left = right = p = NULL;
	c = RED;
}

tree::tree()
{
	nil = new node(-1);
	nil->c = BLACK;
	root = nil;
}

void tree::RB_insert(node* &z)
{
	node* y = nil;
	node* x = root;

	while( x != nil )
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

	if (y == nil)
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

	z->left = nil;
	z->right = nil;
	z->c = RED;

	cout << z->key << endl;

	print_RB_tree();
	RB_insert_fixup(z);	
}

void tree::RB_insert_fixup(node* &z)
{
	while ((z->p != nil) && (z->p->c == RED))
	{
		if (z->p == z->p->p->left)
		{
			node* y = z->p->p->right;

			if (y->c == RED)
			{
				z->p->c = BLACK;
				y->c = BLACK;
				z->p->p->c = RED;
				z = z->p->p;
			}

			else
			{
				if (z == z->p->right)
				{
					z = z->p;
					left_rotate(z);
				}

				z->p->c = BLACK;
				z->p->p->c = RED;
				right_rotate(z->p->p);
			}
		}

		else
		{
			node* y = z->p->p->left;

			if (y->c == RED)
			{
				z->p->c = BLACK;
				y->c = BLACK;
				z->p->p->c = RED;
				z = z->p->p;
			}

			else
			{
				if (z == z->p->left)
				{
					z = z->p;
					right_rotate(z);
				}

				z->p->c = BLACK;
				z->p->p->c = RED;
				left_rotate(z->p->p);
			}
		}
	}

	root->c = BLACK;
}

void tree::left_rotate(node* &x)
{
	node* y = x->right;
	x->right = y->left;

	if (y->left != nil)
	{
		y->left->p = x;
	}

	y->p = x->p;

	if (x->p == nil)
	{
		root = y;
	}

	else if (x == x->p->left)
	{
		x->p->left = y;
	}

	else
	{
		x->p->right = y;
	}

	y->left = x;
	x->p = y;
}

void tree::right_rotate(node* &x)
{
	node* y = x->left;
	x->left = y->right;

	if (y->right != nil)
	{
		y->right->p = x;
	}

	y->p = x->p;

	if (x->p == nil)
	{
		root = y;
	}

	else if (x == x->p->right)
	{
		x->p->right = y;
	}

	else
	{
		x->p->left = y;
	}

	y->right = x;
	x->p = y;
}

void tree::print_RB_Util(node* root, int space)
{
	if (root == nil) return;
	
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
	print_RB_Util(root, 0);
}