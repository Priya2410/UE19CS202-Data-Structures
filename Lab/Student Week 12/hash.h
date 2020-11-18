#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *table;
    int size;
} HashTable;

// Create a hash table of the required size
HashTable *create_table(int size);

// Search for an element in the hash table
// Return 1 if the element is present in the table
// Return 0 otherwise
int search(HashTable *htable, int element);

// Insert the element into the hash table
void insert(HashTable *htable, int element);

// Delete the element from the hash table if present
void delete (HashTable *htable, int element);

// Display all the hash table elements
void display_table(HashTable *htable);

// Destroy the hash table
void destroy_table(HashTable *htable);



