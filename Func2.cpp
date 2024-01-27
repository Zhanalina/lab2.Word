#pragma once
#include <iostream>
#include <functional>
#include "Array.h"
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const Word_Array& wordArray)
{
	for (int i = 0; i < wordArray.count; ++i)
	{
		os << wordArray.Arr[i] << " ";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Word_Array& wordArray)
{
	int count;
	is >> count;
	Word* words = new Word[count];
	for (int i = 0; i < count; ++i)
	{
		is >> words[i];
	}
	for (int i = 0; i < count; ++i)
	{
		wordArray.Add(words[i]);
	}
	delete[] words;
	return is;
}

void AddWordToArray(Word_Array& BaseArr)
{
	Word wordishe(WordConsructionConstChar());
	BaseArr.Add(wordishe);
	for (int i = 0; i < BaseArr.GetCount(); i++)
	{
		char* buffer = new char[BaseArr.GetWord(i).GetSize()];
		std::cout << "Line " << i << " ";
		std::cout << BaseArr.GetWord(i).GetWord(buffer, (int)strlen(buffer));
		std::cout << std::endl;
		delete[] buffer;
	}
}

void FusionArrays(Word_Array& BaseArr)
{
	char* buffer = new char[255];
	Word_Array Arr_n = CreateArrayWithCount();
	Word_Array Third_Array = Word_Array(Word_Array::Fusion(Arr_n, BaseArr));
	for (int i = 0; i < Third_Array.GetCount(); i++)
	{
		char* buffer = new char[255];
		std::cout << "Line " << i << " ";
		std::cout << Third_Array.GetWord(i).GetWord(buffer, (int)strlen(buffer));
		std::cout << std::endl;
	}
	delete[] buffer;
}

void SearchWordInArray(Word_Array& BaseArr)
{
	Word slovo(WordConsructionConstChar());
	int n = BaseArr.Search(slovo);
	std::cout << "Index: " << n << std::endl;
}

void GetWordFromArray(Word_Array& BaseArr)
{
	int n;
	std::cout << "Enter the index: ";
	int_Check(n);
	char* buffer = new char[BaseArr.GetWord(n).GetSize()];
	std::cout << BaseArr.GetWord(n).GetWord(buffer, (int)strlen(buffer));
	std::cout << std::endl;
	delete[] buffer;
}

void LetterSubsetArray(Word_Array& BaseArr)
{
	char l;
	std::cout << "Enter the starting letter: ";
	std::cin >> l;
	Word_Array Letter_Arr(BaseArr.Letter_subset(l));
	for (int i = 0; i < Letter_Arr.GetCount(); i++)
	{
		char* buffer = new char[Letter_Arr.GetWord(i).GetSize()];
		std::cout << "Line " << i << " ";
		std::cout << Letter_Arr.GetWord(i).GetWord(buffer, (int)strlen(buffer)) << std::endl;
		delete[] buffer;
	}
}

void Alph_sort_1(Word_Array& BaseArr)
{
	
	BaseArr.Alph_sort();
	for (int i = 0; i < BaseArr.GetCount(); i++)
	{
		char* buffer = new char[BaseArr.GetWord(i).GetSize()];
		std::cout << "Line " << i << " ";
		std::cout << BaseArr.GetWord(i).GetWord(buffer, (int)strlen(buffer)) << std::endl;
		delete[] buffer;
	}
}

void Array_Functions(Word_Array BaseArr)
{
	int num;
	std::cout << "1. Add" << std::endl <<
				 "2. Fusion" << std::endl <<
				 "3. Search" << std::endl <<
				 "4. Letter_subset" << std::endl <<
				 "5. GetArrWord" << std::endl <<
				 "6. Alph_sort" << std::endl <<
				 "0. Exit" << std::endl <<
		"Press: ";
	int_Check(num);
	do {
		switch (num) {
		case 1:
			AddWordToArray(BaseArr);
			break;
		case 2:
			FusionArrays(BaseArr); break;
		case 3:
			SearchWordInArray(BaseArr); break;
		case 4:
			LetterSubsetArray(BaseArr); break;
		default:
			GetWordFromArray(BaseArr); break;
		case 6:
			Alph_sort_1(BaseArr); break;
		}
		std::cout << "1. Add" << std::endl <<
			"2. Fusion" << std::endl <<
			"3. Search" << std::endl <<
			"4. Letter_subset" << std::endl <<
			"5. GetArrWord" << std::endl <<
			"6. Alph_sort" << std::endl <<
			"0. Exit" << std::endl <<
			"Press: ";
		int_Check(num);
	} while (num != 0);
}

Word_Array CreateArrayWithCount()
{
    int count;
    std::cout << "Enter the count of words: ";
    int_Check(count);
    Word* Array = new Word[count];
	for (int i = 0; i < count; i++)
	{
		Array[i] = WordConsructionConstChar();
	}
    Word_Array Arrayka(count, Array);
	return Arrayka;
}

Word_Array CreateArrayWithWord()
{
	Word Kz(WordConsructionConstChar());
	char* buffer = new char[255]();
	Word_Array Mephi(Kz.GetWord(buffer, Kz.GetSize()));
	delete[] buffer;
	return Mephi;
}

void Word_ArrayClass()
{
	std::cout << "1. Create_Word_OneArray" << std::endl <<
				 "2. Create_Word_CountArray" << std::endl <<
		"0. Exit" << std::endl <<
		"Press: ";
	int num;
	int_Check(num);
	do {
		switch(num)
		{
		case 1:
			Array_Functions(CreateArrayWithWord());
			break;
		default:
			Array_Functions(CreateArrayWithCount());
			break;
		}
		std::cout << "1. Create_Word_OneArray" << std::endl <<
			"2. Create_Word_CountArray" << std::endl <<
			"0. Exit" << std::endl <<
			"Press: ";
		int_Check(num);
	} while (num != 0);
}