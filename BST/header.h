#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

#define COUNT 10

struct node
{
	int key;

	node* left;
	node* right;
	node* p;

	node(int key);
};

class tree
{
public:
	node* root;

	tree();

	int tree_height(node* &z);

	node* tree_minimum(node* &z);
	node* tree_maximum(node* &z);
	node* tree_search(node* &z, int key);
	node* tree_successor(node* &z);

	void inorder_walk(node* &z);
	void postorder_walk(node* &z);
	void preorder_walk(node* &z);
	void tree_insert(node* &z);
	void print_tree();
	void print_Util(node* root, int space);
	void transplant(node* u, node* &v);
	void tree_delete(node* &z);
};
