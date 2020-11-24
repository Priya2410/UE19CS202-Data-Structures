#include<stdio.h>
#include<stdlib.h>

struct item
{
    int key;
    int value;
};

struct hash_table
{
    int flag;
    //flag =0 data doesnt exist
    //flag =1 data exists
    //flag=2 data was deleted
    struct item *data;
    //each data has a key and value
}

struct hashtable *array;
int size=0;
int max=10;//Max size of the hash table

void initialize_array()
{
    for(int i=0;i<max;i++)
    {
        array[i].flag=0;
        array[i].data=NULL;
    }
}
