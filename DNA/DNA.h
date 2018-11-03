/* DNA.h November 2018

Author: Andry Rafam Andrianjafy */

#ifndef DNA_H_
#define DNA_H_

class DNA
{
	private:
		int n;
		int m;
		int index;
		int lcs_len; // length of the longest common subsequence of the DNA 
		
	public:
		char *DNA_LCS (char *Sequence1, char *Sequence2); // Function which used to return the LCS of the two DNA
		int levenshtein_distance (char *Sequence1, char *Sequence2); // Function whic used to return the levenshtein distance between two DNA sequence
		void print_result (char *LCS_DNA);
};

#endif
