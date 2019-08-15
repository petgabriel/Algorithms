#pragma once

#include <iostream>
#include <string>
#include <memory.h>
#include <time.h>
#include <windows.h>

using namespace std;

#define USERS_DATA

class rod
{
public:
	int n;
	int* p;
	int* r;
	int* s;

	rod();
	rod(int n);
	rod(int* p, int n);

	int cut_rod(int n);
	int memoized_cut_rod(int n);
	int memoized_cut_rod_aux(int n);
	int bottom_up_cut_rot(int n);
	
	void extended_bottom_up_cut_road(int n);
	void print_cut_rod_solution(int n);
	void print_prices();

};
