#include "header.h"

int main( int argc, char* argv[] )
{
	srand( (unsigned int)time( NULL ) );

	tree T = tree();

	for( int i = 1; i <= 8; i++ )
	{
		node* tmp = new node( rand() % 100 );

		T.RB_insert( tmp );
	}

	T.print_RB_tree();

	system("pause");

	return 0;
}