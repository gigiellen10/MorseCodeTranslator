/* Programmer name: Genevieve Kochel
Date: March 4th, 2024
File purpose: This file contins the main() driver for the program */

//#include "MorseCodeBST.hpp"
#include "BST.hpp"

int main(void)
{
	// main tree object 
	BST<char, std::string> MorseCodeTree;

	std::ifstream file;

	std::string output;
	
	// print tree
	std::cout << "Current tree using in-order traversal:\n" << std::endl;
	MorseCodeTree.printTree(MorseCodeTree.getmpRoot());

	// open file
	file.open("Convert.txt");

	if (file.is_open())
	{
		while (!file.eof())
		{
			output.clear();
			char search[100] = "";

			file.getline(search, 100);

			filterWhiteSpace(search);

			output = MorseCodeTree.searchTree(search);

			std::cout << '\n' << output << "   "; // print the string found followed by 3 spaces to indicate one full morse code str.

		}
		
		file.close(); // close file

	}
	else
	{
		std::cout << "\nERROR: \"Convert.txt\" could not be opened." << std::endl;
	} 

	
	return 0;
}