//Implementation for session1_seq_search.h

#include "ss.h"
//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
int seqsearch(int *arr, int n, int key) 
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(arr[i]==key)
				return i+1;
		}
		return -1;
	}
