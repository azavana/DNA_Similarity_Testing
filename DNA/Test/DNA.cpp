/* DNA.c November 2018

Author: Andry Rafam Andrianjafy */

#include <iostream>
#include <cstring>
#include <new>
#include "DNA.h"

using namespace std;

char table[4] = {'A','C','G','T'};

// Function which return the longest common subsequence between two DNA sequence
char *DNA::DNA_LCS (char *Sequence1, char *Sequence2)
{
	m = strlen(Sequence1);
	n = strlen(Sequence2);
	
	int L[m+1][n+1];
	
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (Sequence1[i-1] == Sequence2[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	
	index = L[m][n];
	
	char *lcs_DNA = new (nothrow) char[index+1]; // Store the lcs string result
	
	// Start from the right-most-bottom-most corner and store characters one by one n lcs_DNA
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (Sequence1[i-1] == Sequence2[j-1])
		{
			lcs_DNA[index-1] = Sequence1[i-1];
			i--; j--; index--;
		}
		else if (L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}
	return lcs_DNA;
}

// Function used to return the levenshtein distance between two DNA sequence
int DNA::levenshtein_distance (char *Sequence1, char *Sequence2)
{
	m = strlen(Sequence1);
	n = strlen(Sequence2);
	
	int distance[m+1][n+1];
	
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
				distance[i][j] = j;
			else if (j == 0)
				distance[i][j] = i;
			else if (Sequence1[i-1] == Sequence2[j-1])
				distance[i][j] = distance[i-1][j-1];
			else
				distance[i][j] = min(min(1 + distance[i-1][j], 1 + distance[i][j-1]), 1 + distance[i-1][j-1]);
		}
	}
	return distance[m][n];
}

void DNA::print_result (char *LCS_DNA)
{
	char first, second;
	int pos = 0;
	lcs_len = strlen(LCS_DNA) / 2;
	
	if (strlen(LCS_DNA) % 2 == 0)
	{
		for (int i = 1; i <= lcs_len; i++)
		{
			first = LCS_DNA[pos];
			second = LCS_DNA[pos + 1];
			pos += 2;
		
			for (int j = lcs_len - i; j >=1; j--)
				cout << " ";
			cout << first;
			for (int j = 1; j < i; j++)
				cout << "--";
			cout << second << endl;
		}
	}
	else
	{
		for (int i = 1; i <= lcs_len; i++)
		{
			first = LCS_DNA[pos];
			second = LCS_DNA[pos + 1];
			pos += 2;
		
			for (int j = lcs_len - i; j >=1; j--)
				cout << " ";
			cout << first;
			for (int j = 1; j < i; j++)
				cout << "--";
			cout << second << endl;
		}
		cout << LCS_DNA[strlen(LCS_DNA)-1] << endl;
	}
}




