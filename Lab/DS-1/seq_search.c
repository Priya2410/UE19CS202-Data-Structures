// Client code 
#include <stdio.h>
#include <stdlib.h>
#include "ss.h"

int main(int argc, char const *argv[]) 
{
	int n; //size of the array
	int *arr; //array of size n
	int key; //key to be searched
	int res; //location of key in arr
	int i;

	scanf("%d", &n);
	arr = (int *) malloc(n * sizeof(n));

	for (i = 0; i < n; ++i) 
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &key);
	res = seqsearch(arr, n, key); //to get the first occurrence of key in arr
	printf("%d\n", res);
	
	free(arr);
	return 0;
}

//returns the duration from start to end times in sec

