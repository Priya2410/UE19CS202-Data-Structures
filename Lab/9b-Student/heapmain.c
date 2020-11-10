#include<stdio.h>
#include "heap.h"
int main() {
	int choice, loop = 1;
	int initial_size = 0;
	scanf("%d", &initial_size);
	heap *my_heap = heap_construct(initial_size);
	while(loop) {
		scanf("%d", &choice);
		switch(choice) {
			int number_of_elements, element, index;
			int data;
			case 1:
				/* Insert elements */ 
					scanf("%d", &element);
					if(!heap_insert(my_heap, element))
						printf("OVERFLOW\n");

				break;
				
			case 2:
				/* Print elements in sorted order, and empties the heap. */
				heap_print(my_heap);		
				heap_destruct(my_heap);
				loop = 0;
				break;
			
			default: 
				heap_destruct(my_heap);
				loop = 0;
		}
	}
	return 0;
}
void heap_print(heap *my_heap)
{
	while(heap_get_size(my_heap) != 0) {
		printf("%d\n", heap_get_min(my_heap));
		heap_remove(my_heap);
	}

}
