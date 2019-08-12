#include "header.h"

int main( int argc, char* argv[] )
{
	srand( (unsigned int)time( NULL ) );

	tree T;

	node* tmp = new node(28);

	T.RB_insert(tmp);

	tmp = new node(37);

	T.RB_insert(tmp);

	tmp = new node(68);

	T.RB_insert(tmp);

	/*( int i = 1; i <= 8; i++ )
	{
		int t = rand() % 100 + 1;

		node* tmp = new node( t );

		T.RB_insert( tmp );
	}
	
	T.print_RB_tree();
	*/
	system("pause");

	return 0;
}