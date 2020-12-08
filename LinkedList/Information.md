<strong>
Difference between static and dynamic memory allocation

Static : Memory is allocated during compile time
Dynamic : Memory is allocated during run time

Static: Memory can't be reinitialized or reallocated.
Dynamic: Memory can be reallocated or reinitialized

Static:Memory is allocated in a more structured area called stack.
Dynamic : Memory is allocated in a less structured area called heap

Static : No pointers are required to access the data 
Dynamic : Pointers are required to access the data

Static : Can lead to over memory utilization if less memory is allocated ,
       : Can lead to under memory utilization if more memory is allocated
       
Difference between malloc and calloc 

Malloc : Memory Allocation
Calloc : Contiguous memory allocation

Malloc : Allocated memory is initialized to junk values
Calloc : Allocated memory is initialized to 0

Malloc : Takes in only one argument ie size
Calloc : Takes two arguments n,size

Malloc : faster than calloc

Linked list is preffered over array because efficient insertion and deletion , dynamic memory , random access is slow.

Applications of linked list :
Used to deal with large numbers
Used to implement other DS.
Polynomial addition implementation
struct Node { int coeff,int exp,struct Node *link}
Sparse Matrix 
Multilist

What is a sparse matrix ? 
2D Array with more zeros than non zero values.
Used in social media implementaion where a user has only a selected number of friends.
Can be represented by multilist also.

</strong>
