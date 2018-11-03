/* DNA Sequence Alignment - November 2018

Implemented under Linux Ubuntu 16.04 LTS - GCC (G++) version 6.4.0 and GDB version 8.2

Author: Andry Rafam Andrianjafy */

#include <iostream>
#include <new>
#include <ctime>
#include "DNA.h"

using namespace std;

char nucleotid[4] ={'A','C','G','T'};

int main ()
{
	DNA *dna = new (nothrow) DNA;
	char *resultStr;
	
	
	const std::string yellow("\033[1;33m"); // Define the color yellow
	const std::string reset("\033[0m");      
	
	cout << yellow;
	cout <<"\n\n========== DNA similarity testing ==========\n\n";
	cout << reset;
	
	srand(time(NULL));
	int DNA1_len = rand() % 20 + 5;
	int DNA2_len = rand() % 20 + 5;
	
	char *DNA1 = new (nothrow) char[DNA1_len+1];
	char *DNA2 = new (nothrow) char[DNA2_len+1];
	
	// Generate randomly the two DNA sequences
	for (int i = 0; i < DNA1_len; i++)
	{
		int x = rand() % 4;
		DNA1[i] = nucleotid[x];
	}
	
	for (int j = 0; j < DNA2_len; j++)
	{
		int y = rand() % 4;
		DNA2[j] = nucleotid[y];
	}
	
	cout <<"DNA Sequence1 >> " << DNA1 <<"\n\n";
	cout <<"DNA Sequence2 >> " << DNA2 <<"\n\n";
	
	cout << yellow <<"[ RESULT ]\n\n";
	cout << reset;
	cout <<"Similarity between the two DNA sequences in terms of LCS is >> ";
	cout << yellow << dna->DNA_LCS (DNA1, DNA2) << endl << endl;
	
	resultStr = dna->DNA_LCS (DNA1, DNA2);
	
	dna->print_result (resultStr);
	cout << reset;
	
	cout << endl;
	
	cout <<"The levenshtein distance between the two DNA sequences is >> " << yellow << dna->levenshtein_distance(DNA1, DNA2);
	cout <<"\n\n\n";
	
	delete [] DNA1;
	delete [] DNA2;
	
	return EXIT_SUCCESS;
}

