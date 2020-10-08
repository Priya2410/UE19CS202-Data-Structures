//Implementation for session1_seq_search.h

#include "ss.h"
//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
int seqsearch(int *arr, int n, int key) 
	{
		int k;
		for(k=0;k<n;k++)
		{
			if(arr[k]==key)
				return k+1;
		}
		return -1;
	}
