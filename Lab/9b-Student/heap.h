#include <stdlib.h>
#include <stdio.h>

typedef struct heap {
    int capacity;
    int size;
    int elements[1];
} heap;

heap* heap_construct(int initial_capacity);
void  heap_destruct(heap* heap);
int  heap_get_capacity(heap *heap);
int  heap_get_size(heap *heap);

/* 
	insert data into heap 
	return 1 if inserted.
	return 0 if size > capacity

*/
int heap_insert(heap *heap, int data);
/*return the min value without deleting it*/
int  heap_get_min(heap *heap);
/*delete the min value in the heap*/
void heap_remove(heap *heap);
/*Print the values(data) in ascending order by deleting the min value node from the heap each time*/
void heap_print(heap *heap);



