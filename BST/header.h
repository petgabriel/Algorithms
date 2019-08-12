#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

#define COUNT 10

enum color {RED, BLACK};

struct node
{
	color c;
	
	node* p;
	node* left;
	node* right;

	int key;

	node( int key );
};

class tree
{
public:

	node* root;
	node* nil;

	tree();

	void RB_insert(node* &z);
	void RB_insert_fixup(node* &z);
	void left_rotate(node* &x);
	void right_rotate(node* &x);
	void print_RB_tree();
	void print_RB_Util(node* root, int space);
};