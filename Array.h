#pragma once
#include <iostream>
#include <algorithm>
#include <functional>

void int_Check(int& x);

class Word
{
private:
	char* word = nullptr;

	static int CompareWords(const Word& word1, const Word& word2) // добавить перегрузки по заданию
	{
		return std::strcmp(word1.word, word2.word);
	}

public:

	Word(bool createEmpty = true)
	{
		if (!createEmpty)
		{
			char* tmpWord = new char[255];
			std::cout << "Enter  word: " << std::endl;
			std::cin >> tmpWord;
			word = new char[strlen(tmpWord) + 1];
			word[strlen(tmpWord)] = '\0';
			std::copy(tmpWord, tmpWord + strlen(tmpWord), word);
			delete[] tmpWord;
		}
	}

	Word(const char* input)//добавить валидацию на пробелы
	{
		int n = 0;
		for (int j = 0; j < strlen(input); j++)
		{
			if (input[j] != ' ' && input[j] != '\t')
			{
				n++;
			}
		}
		word = new char[n + 1];
		n = 0;
		for (int i = 0; i < strlen(input) + 1; i++)
		{
			if (input[i] != ' ' && input[i] != '\t')
			{
				word[n] = input[i];
				n++;
			}
		}
	}

	Word(char input[], int size1) //
	{
		int n = 0;
		for (int j = 0; j < size1; j++)
		{
			if (input[j] != ' ' && input[j] != '\t')
			{
				n++;
			}
		}
		word = new char[n+1];
		n = 0;
		for (int i = 0; i < size1; i++)
		{
			if (input[i] != ' ' && input[i] != '\t')
			{
				word[n] = input[i];
				n++;
			}
		}
		word[n+1] = '\0';
	}

	Word(Word&& other) noexcept : word(other.word)
	{
		other.word = nullptr;
	}

	Word(const Word& other) : word(nullptr)
	{
		if (other.word != nullptr)
		{
			int length = other.GetSize();
			word = new char[length + 1];
			std::copy(other.word, other.word + length + 1, word);
		}
	}

	int GetSize()  const
	{
		return (int)strlen(word);
	}

	char* GetWord(char* buffer, int Size) const//два параметра буфер и размер
	{
		if (strlen(word) <= Size)
		{
			std::copy(word, word + strlen(word) + 1, buffer);
		}
		return buffer;
	}
	
	void SetWord(const char* word1) // через копирование
	{
		delete[] word;
		word = nullptr;
		int n = 0;
		for (int j = 0; j < strlen(word1); j++)
		{
			if (word1[j] != ' ' && word1[j] != '\t')
			{
				n++;
			}
		}
		word = new char[n + 1];
		for (int i = 0; i < strlen(word1)+1; i++)
		{
			if (word1[i] != ' ' && word1[i] != '\t')
			{
				word[i] = word1[i];
			}
		}
		word[n + 1] = '\0';
	}

	bool operator==(const Word& other) const
	{
		return CompareWords(*this, other) == 0;
	}

	bool operator!=(const Word& other) const
	{
		return CompareWords(*this, other) != 0;
	}

	bool operator<(const Word& other) const
	{
		return CompareWords(*this, other) < 0;
	}

	bool operator>(const Word& other) const
	{
		return CompareWords(*this, other) > 0;
	}

	bool operator<=(const Word& other) const
	{
		return CompareWords(*this, other) <= 0;
	}

	bool operator>=(const Word& other) const
	{
		return CompareWords(*this, other) >= 0;
	}

	Word& operator=(const Word& other)
	{
		if (this != &other)
		{
			delete[] word;
			word = nullptr;
			if (other.word != nullptr)
			{
				int length = other.GetSize();
				word = new char[length + 1];
				std::copy(other.word, other.word + length + 1, word);
			}
			else
			{
				word = nullptr;
			}
		}
		return *this;
	}

	Word& operator=(Word&& other) noexcept
	{
		if (this != &other)
		{
			delete[] word;
			word = nullptr;
			word = other.word;
			other.word = nullptr;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Word& word);

	friend std::istream& operator>>(std::istream& is, Word& word);

	static bool compareArr(const Word a, const Word b)
	{
		return Word::CompareWords(a, b) < 0;
	}

	int Occurrence_check(const char* mini_str) const
	{
		int i=0;
		if (strlen(mini_str) > GetSize())
		{
			std::cout << "No, it is not" << std::endl;
			return -1;
		}
		while (word[i] == mini_str[i] && i < strlen(mini_str))
		{
			i++;
		}
		if (i == strlen(mini_str))
		{
			std::cout << "Yes, it is" << std::endl;
			return 1;
		}
		std::cout << i << " " << strlen(mini_str);
		std::cout << "No, it is not" << std::endl;
		return -1;
	}

	int Occurrence_check(const Word& mini_word) const
	{
		Occurrence_check(mini_word.word);
	}

	void Small_letter()
	{
		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] < 91)
			{
				word[i] += 32;
			}
		}
	}

	~Word()
	{
		delete[] word;
	}


};
// копирующий и перемещающий конструкторы + = copy and move

class Word_Array
{
private:
	Word* Arr = nullptr;
	int count = 0;
public:

	Word GetWord (int idx) const
	{
		if (idx <= count)
		{
			return Arr[idx];
		}
		throw std::exception("We haven't that idx");
		return Arr[0];
	}

	int GetCount() const
	{
		return count;
	}

	Word_Array(int count, const Word* Arr1)
	{
		Arr = new Word[1];
		Arr[0] = Arr1[0];
		this->count = 1;
		for (int j = 1; j < count; j++)
		{
			Add(Arr1[j]);
		}
	}

	Word_Array(const char* word) //Word Добавить массив указателей
	{
		Arr = new Word[1];
		this->count = 1;
		Arr[0] = Word(word);
	}

	Word_Array(const Word_Array& other)
		: count(other.count), Arr(new Word[other.count])
	{
		std::copy(other.Arr, other.Arr + count, Arr);
	}

	Word_Array(Word_Array&& other) noexcept
		: Arr(std::move(other.Arr)), count(other.count)
	{
		other.Arr = nullptr;
		other.count = 0;
	}

	Word_Array& operator=(Word_Array&& other) noexcept
	{
		if (this != &other)
		{
			delete[] Arr;
			Arr = std::exchange(other.Arr, nullptr);
			count = other.count;
			other.count = 0;
		}
		return *this;
	}

	Word_Array& operator=(const Word_Array& other)
	{
		if (this != &other)
		{
			delete[] Arr;
			count = other.count;
			Arr = new Word[count];
			std::copy(other.Arr, other.Arr + count, Arr);
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Word_Array& wordArray);

	friend std::istream& operator>>(std::istream& is, Word_Array& wordArray);

	void Add(const Word& new_one)
	{
		for (int i = 0; i < this->count; i++)
		{
			if (Arr[i] == new_one)
			{
				std::cout << "We have this word";
				return;
			}
		}
		Word* tmp = new Word[count + 1]();
		std::copy(this->Arr, this->Arr + this->count, tmp);
		tmp[count] = new_one;
		delete[] Arr;
		Arr=tmp;
		count++;
	}

	static Word_Array Fusion(const Word_Array& Arr1, const Word_Array& Arr2) //Добавить проверку на уникальность слов
	{
		Word* tmp = new Word[Arr1.GetCount() + Arr2.GetCount()];
		for (int i = 0; i < Arr1.GetCount(); i++)
		{
			tmp[i] = Word(Arr1.GetWord(i));
		}
		for (int i = 0; i < Arr2.GetCount(); i++)
		{
			bool duplicate = false;
			for (int j = 0; j < Arr1.GetCount(); j++)
			{
				if (Arr2.GetWord(i) == Arr1.GetWord(j))
				{
					duplicate = true;
					break;
				}
			}
			if (!duplicate)
			{
				tmp[Arr1.GetCount() + i] = Word(Arr2.GetWord(i));
			}
		}
		Word_Array Third_Array(Arr1.GetCount() + Arr2.GetCount(), tmp);
		delete[] tmp;
		return Third_Array;
	}

	int Search(const Word& s_word) const
	{
		int idx=0;
		for (int i = 0; i < count; i++)
		{
			if (Arr[i] == s_word)
			{
				idx = i;
				return idx;
			}
		}
		std::cout << "We don't have this word";
		return -1;
	}

	Word GetArrWord(int& idx) const
	{
		Word tmp = Arr[idx];
		return tmp;
	}

	Word_Array Letter_subset(char letter) const
	{
		int n=0;
		Word* Letter_Arr = new Word[count]();
		for (int i = 0; i < count; i++)
		{
			char* buffer = new char[Arr[i].GetSize()];
			if (Arr[i].GetWord(buffer, (int)strlen(buffer))[0] == letter || Arr[i].GetWord(buffer, (int)strlen(buffer))[0] == letter+32 || Arr[i].GetWord(buffer, (int)strlen(buffer))[0] == letter - 32)
			{
				Letter_Arr[n] = Arr[i];
				n++;
			}
			delete[] buffer;
		}
		Word_Array Letter(n, Letter_Arr);
		delete[] Letter_Arr;
		return Letter;
	}

	void Alph_sort()
	{
		std::sort(Arr, Arr + count, Word::compareArr);
	}

	~Word_Array()
	{
		delete[] Arr;
	}
};

void AddWordToArray(Word_Array& BaseArr);
void FusionArrays(Word_Array& BaseArr);
void SearchWordInArray(Word_Array& BaseArr);
void GetWordFromArray(Word_Array& BaseArr);
void LetterSubsetArray(Word_Array& BaseArr);
void Array_Functions(Word_Array Kazakh);
Word_Array CreateArrayWithCount();
Word_Array CreateArrayWithWord();
void Word_ArrayClass();
void CompareWords(Word& Kazakh);
void CheckOccurrence(Word& Kazakh);
void ConvertToLowercase(Word& Kazakh);
void Word_Functions(Word Kazakh);
Word WordConsructionConstChar();
Word WordConsructionCharSize();
void WordClass();
void Alph_sort_1(Word_Array& BaseArr);
