
// A dictionary implemented using hashtable in C++. 
// Contains only few words, to make it fully functional, place word-meanings in a file, iterate over every word, insert it and it's meaning and y
// you should be good to go with your own mini dictionary, cheers!

#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;
#define HASH_FN_CONSTANT	5 
#define BIG_PRIME			24593

class HashTableImpl
{

public:
	HashTableImpl() 
	{
		for (int i = 0; i < BIG_PRIME; i++)
		{
			HashTable[i] = new(std::nothrow) ListNode;
			HashTable[i]->dict.theWord = "";
			HashTable[i]->dict.itsmeaning = "";
			HashTable[i]->next = NULL;
		}
	}
	~HashTableImpl() 
	{
		/*for (int i = 0; i < BIG_PRIME; i++) 
		{
			ListNode* head = HashTable[i];
			while (head->next != NULL) {
				
			}
		}*/
	}

	struct WordMeaningDictionary
	{
		std::string theWord;
		std::string itsmeaning;
	};
	
	struct ListNode 
	{
		WordMeaningDictionary dict;
		ListNode* next;
	};

	int Get_No_of_entrires() 
	{
		return no_of_entries; 
	}
	
	int Compute_LoadFactor() 
	{
		no_of_entries > 0 ? no_of_entries / BIG_PRIME : 0; 
	}
	
	int _TheHashFunction(const string& inputstring)
	{
		int hash = 0;
		int stringlength = inputstring.length();
		for (int i = 0; i < stringlength; i++) 
		{
			hash = hash * HASH_FN_CONSTANT + inputstring[i];
		}
		return hash % BIG_PRIME;
	}
	
	void Insert_Word(const string& inputWord, const string &wordMeaning) 
	{
		int index = _TheHashFunction(inputWord);
		ListNode* head = HashTable[index];
		if (HashTable[index]->dict.theWord == "")
		{

			HashTable[index]->dict.theWord = inputWord;
			HashTable[index]->dict.itsmeaning = wordMeaning;
			HashTable[index]->next = NULL;
		}
		else
		{
			ListNode* currentitem = new ListNode;
			currentitem->dict.theWord = inputWord;
			currentitem->dict.itsmeaning = wordMeaning;
			currentitem->next = NULL;
			while (head->next != NULL)
			{
				head = head->next;
			}
			head->next = currentitem;
		}
		return;
	}

	bool Is_Word_Present(const string& inputWord, string & wordMeaning)
	{
		int index = _TheHashFunction(inputWord);
		ListNode * head = HashTable[index];
		while (head != NULL) 
		{
			if (head->dict.theWord == inputWord) 
			{
				wordMeaning = head->dict.itsmeaning;
				return true;
			}
			else 
			{
				head = head->next;
			}
		}
		return false;
	}

	int Get_itemsCountinBucket(int bucket) 
	{
		int count = 0;
		if (HashTable[bucket]->next == NULL) 
		{
			return 1;
		}
		else
		{
			count++;
			ListNode * temp = HashTable[bucket]->next;
			while (temp != NULL) 
			{
				temp = temp->next;
				count++;
			}
		}
		return count;
	};

	void Get_WordMeaning( const string& inputWord) 
	{
		
		std::string Meaning;
		if (Is_Word_Present(inputWord, Meaning)) 
		{
			cout << "Meaning of "<< inputWord.c_str()<< " is: " << Meaning.c_str() << endl;
		}
		else {
			cout << "Sorry, word not found in dictionary" << endl;
		}
	}

	ListNode * HashTable[BIG_PRIME];
	int no_of_entries;
};

/*int main() 
{
	HashTableImpl* ptrHashTable = new HashTableImpl();
	ptrHashTable->Insert_Word("Hello World", "This is the traditional first program that you write when you learn any programming concept or Language");
	ptrHashTable->Get_WordMeaning("Hello World");
	ptrHashTable->Insert_Word("Best Shot", "Adding Additional word");
	ptrHashTable->Get_WordMeaning("Best Shot");
	///*delete ptrHashTable;*/
	//return 0;
//}*/
