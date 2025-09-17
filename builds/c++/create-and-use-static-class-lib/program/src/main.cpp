#include <iostream>
#include "LibraryClass.hpp"

int main(int argc, char** argv)
{
	std::cout << "\nentering main..\n";
	LibraryClass libclass;
	libclass.printMessage();
	std::cout << "\nend.";
}