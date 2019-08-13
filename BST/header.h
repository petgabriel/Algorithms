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

	node* tree_minimum();
	node* tree_maximum();
	node* tree_search(node* &z, int key);
	void tree_insert(node* &z);
	void print_tree();
	void print_Util(node* root, int space);
};
