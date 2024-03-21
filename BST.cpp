/* Programmer name: Genevieve Kochel 
Date: March 7th 2024
File purpose: This file contains some common utility functions used to manipulate strings and input to 
ensure they are in the correct form for searching a BST */

#include "BST.hpp"

void clearArray(char* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = '\0';
	}

}


// removes all whitespace from given STRING
void filterWhiteSpace(char* string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			for (int j = i; string[j] != '\0'; ++j)
			{
				// shift all elements over to overwrite whitespace
				if (!((j + 1) > strlen(string) + 1))
				{
					string[j] = string[j + 1];
				}
				
			}
		}

		++i;
	}
}