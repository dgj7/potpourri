#include <stdio.h>		//for printf

#include <iostream>
using namespace std;

#include <windows.h>

//#include "simple.h"

int main()
{
	LoadLibrary ( "simple.dll" );

	int num;

	cout << "Enter an integer.\n";
	cin >> num;

	cout << "The square of that int is " << square( num );

	return 0;
}