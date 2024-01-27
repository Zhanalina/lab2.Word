#include <iostream>
#include <algorithm>
#include <functional>
#include "Array.h"


int main()
{
	/*Word word1;
	std::cout << "Enter a word: ";
	std::cin >> word1;
	std::cout << "You entered: " << word1 << std::endl;*/
	int num;
	std::cout << "1. Class Word" << std::endl << 
		"2. Class Word_Array" << std::endl <<
		"0. Exit" << std::endl <<
		"Press: ";
	int_Check(num);
	do {
		switch(num){
		case 1: WordClass();
		default : Word_ArrayClass();
		}
		std::cout << "1. Class Word" << std::endl <<
			"2. Class Word_Array" << std::endl <<
			"0. Exit" << std::endl <<
			"Press: ";
		int_Check(num);
	} while (num != 0);
	return 0;
}