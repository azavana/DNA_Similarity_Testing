/* DNA Sequence Alignment - November 2018

Implemented under Linux Ubuntu 16.04 LTS - GCC (G++) version 6.4.0 and GDB version 8.2

Author: Andry Rafam Andrianjafy */

#include <iostream>
#include <new>
#include "DNA.h"

using namespace std;

int main (int argc, char **argv)
{
	DNA *dna = new (nothrow) DNA;
	char *resultStr;
	
	if (argc != 3)
	{
		cout << endl;
		cout <<"Usage: " << argv[0] << " <DNA_Sequence1> <DNA_Sequence2> " << endl << endl;
		return -1;
	}
	const std::string yellow("\033[1;33m"); // Define the color yellow
	const std::string reset("\033[0m");      
	
	cout << yellow;
	cout <<"\n\n========== DNA similiraty testing ==========\n\n";
	cout << reset;
	
	cout << yellow <<"[ RESULT ]\n\n";
	cout << reset;
	cout <<"Similarity between the two DNA sequences in terms of LCS is >> ";
	cout << yellow << dna->DNA_LCS (argv[1], argv[2]) << endl << endl;
	
	resultStr = dna->DNA_LCS (argv[1], argv[2]);
	
	dna->print_result (resultStr);
	cout << reset;
	
	cout << endl;
	
	cout <<"The levenshtein distance between the two DNA sequences is >> " << yellow << dna->levenshtein_distance(argv[1], argv[2]);
	cout <<"\n\n\n";
	
	return EXIT_SUCCESS;
}

