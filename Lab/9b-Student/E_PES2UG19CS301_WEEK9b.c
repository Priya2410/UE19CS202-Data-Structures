#include "heap.h"
heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    //TODO
    if(tmp==NULL)
    return;
    free(tmp);
}
int heap_get_capacity(heap* tmp){
    //TODO
    if(tmp)
    return tmp->capacity;
    else
    return -1;
}
int heap_get_size(heap* tmp){
    //TODO
    if(tmp)
    return tmp->size;
    else 
    return -1;
}

int heap_insert(heap* tmp,int data){
    //TODO
    int i;
    if(heap_get_size(tmp) >= heap_get_capacity(tmp))
    return 0;
    else
    {
        tmp->elements[heap_get_size(tmp)]=data;
        tmp->size+=1;
        int stored,child,parent,i;
        for(i=1;i<heap_get_size(tmp);i++)
        {
            child=i;
            stored=tmp->elements[child];
            parent=(child-1)/2;
            while((child>0) && tmp->elements[parent]>stored)
            {
                tmp->elements[child]=tmp->elements[parent];
                child=parent;
                parent=(child-1)/2;
            }
            tmp->elements[child]=stored;
        }
    }
    return 1;
}
int heap_get_min(heap* tmp){
    //TODO
    int min=tmp->elements[0];
    return min;
}
void heap_remove(heap* tmp){
    //TODO
    if(tmp!=NULL && heap_get_size(tmp)>0)
    {
    	int min = tmp->elements[0];
    	tmp->elements[0] = tmp->elements[(heap_get_size(tmp))-1];
    	tmp->size -= 1;
    	int child, parent, stored;
		parent = 0;
		stored = tmp->elements[parent];
		child = 2*parent+1;
		while (child < heap_get_size(tmp)) {
			if (child+1 < heap_get_size(tmp)) {
				if (tmp->elements[child+1] < tmp->elements[child]) {
					++child;
				}
			}
			if (stored > tmp->elements[child]) {
				tmp->elements[parent] = tmp->elements[child];
				parent = child;
				child = 2*parent+1;
			}
			else {
				break;
			}
		}
		tmp->elements[parent] = stored;
    }
    else return;
}


