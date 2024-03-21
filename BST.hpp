/* Programmer name: Genevieve Kochel
Date: March 4th, 2024
File purpose: This file contains the function prototypes, function definitions (since template) and class 
template declaration for the BST (binary search tree) class */

#include "BSTNode.hpp" 
#include "MorseCodeBST.hpp"


template <class T1, class T2>
class BST {
public:
	/* constructor (open and closes file) */
	BST(void);

	/* setter and getter */
	BSTNode<T1, T2>* getmpRoot(void);
	void setmpRoot(BSTNode<T1, T2>* newmpRoot);

	/* member functions - insert, print, search */
	bool insert(BSTNode<T1, T2>* pTree, const T1& englishData, const T2& morseData);
	void printTree(BSTNode<T1, T2>* pTree);
	std::string searchTree(const char string[]);
	std::string searchCharacter(BSTNode<T1, T2>* pTree, char target);

	/* destructor */
	~BST(void);


private:

	BSTNode<T1, T2>* mpRoot;

};

// utility functions
void clearArray(char* arr, int size);
void filterWhiteSpace(char* arr);


/* constructor */
template <class T1, class T2>
BST<T1, T2>::BST(void)
{
	this->mpRoot = nullptr; // init to null

	// declare file stream and open
	std::ifstream file;
	file.open("MorseTable.txt");

	if (file.is_open())
	{
		// read from file and construct BST here while not at end of file
		while (!file.eof())
		{
			char tempChar = '\0';
			char tempStr[100] = "";

			// read character
			file.getline(tempStr, 100);
			tempChar = tempStr[0];

			// read morse string
			file.getline(tempStr, 100);

			insert(mpRoot, tempChar, tempStr); // insert data into tree

		}

		file.close();
	}

}

template <class T1, class T2>
BSTNode<T1, T2>* BST<T1, T2>::getmpRoot(void)
{
	return mpRoot;
}

template <class T1, class T2>
void BST<T1, T2>::setmpRoot(BSTNode<T1, T2>* newmpRoot)
{
	mpRoot = newmpRoot;
}

template <class T1, class T2>
bool BST<T1, T2>::insert(BSTNode<T1, T2>* pTree, const T1& englishData, const T2& morseData)
{
	int success = 0;

	if (pTree == nullptr)
	{
		mpRoot = new BSTNode<T1, T2>(englishData, morseData);

	}
	else if (englishData < pTree->getmEnglish())
	{
		if (pTree->getmpLeft() == nullptr)
		{
			// insert 
			BSTNode<T1, T2>* pMem = new BSTNode<T1, T2>(englishData, morseData);

			if (pMem != nullptr)
			{
				success = 1;
				pTree->setmpLeft(pMem);
			}
		}
		else
		{
			// recursive step - move down left side of subtree
			insert(pTree->getmpLeft(), englishData, morseData);
		}
	}
	else if (englishData > pTree->getmEnglish())
	{
		if (pTree->getmpRight() == nullptr)
		{
			// insert 
			BSTNode<T1, T2>* pMem = new BSTNode<T1, T2>(englishData, morseData);
			
			if (pMem != nullptr)
			{
				success = 1;
				pTree->setmpRight(pMem);
			}
		}
		else
		{
			// recursive step - move down right side of subtree
			insert(pTree->getmpRight(), englishData, morseData);
		}

	}
	else
	{
		// duplicate 
		success = 0;
	}

	return success;

}

template <class T1, class T2>
void BST<T1, T2>::printTree(BSTNode<T1, T2>* pTree)
{
	if (pTree != nullptr)
	{
		printTree(pTree->getmpLeft());
		std::cout << pTree->getmEnglish() << "  " << pTree->getmMorse() << std::endl;
		printTree(pTree->getmpRight());
	}

}

template <class T1, class T2>
std::string BST<T1, T2>::searchTree(const char string[])
{

	std::string morse, temp;
	int i = 0;

	/* while not at the end of the string containing target characters,
	   search for the tree and append the corresponding morse string to string being returned */
	while (string[i] != '\0')
	{
		if (mpRoot == nullptr) // edge case
		{
			return ""; // indicates that no characters matching string entered
		}
		else if (toupper(string[i]) < mpRoot->getmEnglish())
		{
			// first we should check if the searchChar() function returned empty string - char not found and this function shouldn't return a valid morse string

			temp.clear(); // clear temp for each iteration

			temp = searchCharacter(mpRoot->getmpLeft(), toupper(string[i]));

			if (temp == "")
			{
				return temp; // return an empty string to indicate at least one of the characters searched for was not found in tree
			}
			else
			{
				// we found the corresponding character, so append to the morse string we will return at the end
				morse += temp + ' ';

			}
		}
		else if (toupper(string[i]) > mpRoot->getmEnglish())
		{
			// first we should check if the searchChar() function returned empty string - char not found and this function shouldn't return a valid morse string

			temp.clear(); // clear temp for each iteration

			temp = searchCharacter(mpRoot->getmpRight(), toupper(string[i]));

			if (temp == "")
			{
				return temp; // return an empty string to indicate at least one of the characters searched for was not found in tree
			}
			else
			{
				// we found the corresponding character, so append to the morse string we will return at the end
				morse += temp + ' ';

			}

		}
		else 
		{
			// mpRoot is the character we are searching for
			morse += mpRoot->getmMorse();

		}
		

		++i; // increment index in the string
	}

	return morse;
}

template <class T1, class T2>
std::string BST<T1, T2>::searchCharacter(BSTNode<T1, T2>* pTree, char target)
{
	std::string morseString;

	if (pTree != nullptr)
	{
		if (target < pTree->getmEnglish())
		{
			// navigate to the left in the tree to search for target character
			pTree->getmpLeft();
			morseString = searchCharacter(pTree->getmpLeft(), target);
		}
		else if (target > pTree->getmEnglish())
		{
			// navigate to the right in the tree to search for target character
			morseString = searchCharacter(pTree->getmpRight(), target);
		}
		else
		{
			// found node with character we are searching for, so return the corresponding morse string
			return pTree->getmMorse();
		}
	}
	

	return morseString;
}



/* destructor for BST */
template <class T1, class T2>
BST<T1, T2>::~BST(void)
{
	// recursive delete tree function since delete will call destructor of node!
	if (mpRoot != nullptr)
	{
		delete mpRoot;
	}
	
}

