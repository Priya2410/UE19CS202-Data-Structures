#include "hash.h"
HashTable *create_table(int size)
{
    //TODO
    HashTable *newHashTable=(HashTable *)malloc(sizeof(HashTable));
    newHashTable->size=size;
    newHashTable->table=(int *)malloc(size * sizeof(int));
    for(int i=0;i<size;i++)
    {
    	newHashTable->table[i]=-1;
    }
    return newHashTable;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int in, c=1;
    in = element % (htable->size); 
    while((htable->table[in]!=-1) && (htable->table[in]!=element) && (c<=(htable->size)))
    {
        in++;
        in= in % (htable->size);
        c++;
    }
    if(htable->table[in]==-1)
    	htable->table[in]=element;
    else 
    	return;
}

int search(HashTable *htable, int element)
{
    //TODO
    int temp, in, c = 1;
	in = (element)%(htable->size);
	temp = htable->table[in];
	while((temp!=element) && (c<=(htable->size)))
	{
		c++;
		if(in == (htable->size - 1))
			in = 0;
		else
			in++;
		temp = htable->table[in];
	}
	if(temp == element)
		return 1;
	else 
		return 0;
    
}

void delete (HashTable *htable, int element)
{
    //TODO
    int temp, in, c = 1;
	in = (element)%(htable->size);
	temp = htable->table[in];
	while((temp!=element) && (c<=(htable->size)))
	{
		c++;
		if(in == ((htable->size) - 1))
			in = 0;
		else
			in++;
		temp = htable->table[in];
	}
	if(temp == element)
		htable->table[in] = -1;
	else 
		return;
}


void destroy_table(HashTable *htable)
{
    //TODO
    free(htable->table);
    free(htable);
}
