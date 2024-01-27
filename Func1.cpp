#pragma once
#include <iostream>
#include <string>
#include <functional>
#include "Array.h"

std::ostream& operator<<(std::ostream& os, const Word& word)
{
	return os << word.word;
}

std::istream& operator>>(std::istream& is, Word& word)
{
	char buffer[255];
	is >> buffer;
	word.SetWord(buffer);
	return is;
}

void int_Check(int& x)
{
	std::cin >> x;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Not correct value" << std::endl;
		std::cout << "Enter again: ";
		std::cin >> x;
	}
	if (x < 0)
	{
		x *= (-1);
		std::cout << "x = " << x << std::endl;
	}
}

void CompareWords(Word& BaseWord)
{
	Word tmpWord = Word(false);
	if (Word::compareArr(tmpWord, BaseWord)==true)
	{
		std::cout << "0";
	}
	if (Word::compareArr(tmpWord, BaseWord)==false)
	{
		std::cout << "-1";
	}
}

void CheckOccurrence(Word& BaseWord)
{
	char* buffer = new char[255];
	std::cout << "Enter mini_str: " << std::endl;
	std::cin >> buffer;
	std::cout << std::endl << strlen(buffer) << std::endl;
	BaseWord.Occurrence_check(buffer);
}

void ConvertToLowercase(Word& BaseWord)
{
	char* buffer = new char[255];
	BaseWord.Small_letter();
	for (int j = 0; j < strlen(BaseWord.GetWord(buffer, (int)strlen(buffer))); j++)
	{
		std::cout << BaseWord.GetWord(buffer, (int)strlen(buffer))[j];
	}
	std::cout << std::endl;
}

void Word_Functions(Word BaseWord)
{
	int num;
	std::cout << "1. Comparison" << std::endl <<
		"2. Occurrence_check" << std::endl <<
		"3. Small_letter" << std::endl <<
		"0. Exit" << std::endl <<
		"Press: ";
	int_Check(num);
	do {
		switch (num) {
		case 1:
			CompareWords(BaseWord);
			break;
		case 2:
			CheckOccurrence(BaseWord);
			break;
		default:
			ConvertToLowercase(BaseWord);
			break;
		}
		std::cout << "1. Comparison" << std::endl <<
			"2. Occurrence_check" << std::endl <<
			"3. Small_letter" << std::endl <<
			"0. Exit" << std::endl <<
			"Press: ";
		int_Check(num);
	} while (num != 0);
}

Word WordConsructionConstChar()
{
	Word tmpWord = Word(false);
	char* a = new char[255];
	Word newWord(tmpWord.GetWord(a, (int)strlen(a)));
	delete[] a;
	return newWord;
}

Word WordConsructionCharSize()
{
	int size;
	std::cout << "Enter words size: ";
	int_Check(size);
	char* tmpWord = new char[255];
	std::cout << "Enter  word: " << std::endl;
	std::cin >> tmpWord;
	Word newWord(tmpWord, size+1);
	delete[] tmpWord;
	return newWord;
}

void WordClass()
{
	int num;
	std::cout << "1. Const char" << std::endl <<
		"2. Char + size" << std::endl <<
		"0. Exit" << std::endl <<
		"Press: ";
	int_Check(num);
	do {
		switch(num){
		case 1:
			Word_Functions(WordConsructionConstChar()); break;

		default :
			Word_Functions(WordConsructionCharSize()); break;
		}
		std::cout << "1. Const char" << std::endl <<
			"2. Char + size" << std::endl <<
			"0. Exit" << std::endl <<
			"Press: ";
		int_Check(num);
	} while (num != 0);
}