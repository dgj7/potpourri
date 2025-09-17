#include <stdio.h>	//for output function printf

#include "simple.h"	//for the definition of our dll file

int main()
{
	int num = 0;

	printf ( "enter any number: ");

	scanf ( "%d", &num );

	printf ( "square of %d is %d.", num, square ( num ) );

	return 0;
}