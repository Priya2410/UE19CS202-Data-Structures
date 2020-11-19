#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10
struct data
{
	int key;
	int value;
};
struct hash_table
{
	int flag;
	struct data *item;
};
struct hash_table *array;
int size=0;
int prime=3;
void init_array()
{
	for(int i=0;i<MAX;i++)
	{
		array[i].flag=0;
		array[i].item=NULL;
	}
}
int hashfun1(int key)
{
	return(key%MAX);
}
int hashfun2(int key)
{
	return(prime-(key%prime));
}
void insert(int key,int value)
{
	int hash1=hashfun1(key);
	int hash2=hashfun2(key);
	int index=hash1,i=1;
	struct data *newele=(struct data*)malloc(sizeof(struct data));
	newele->key=key;
	newele->value=value;
	if(size==MAX)
	{
		printf("hash table is full\n");
		return;
	}
	while(array[index].flag==1)
	{
		if(array[index].item->key==key)
		{
			printf("key already exist\n");
			array[index].item->value=value;
			return;
		}
		index=(index+i*hash2)%MAX;
	}
	array[index].item=newele;
	array[index].flag=1;
	size++;
	i++;
	printf("key(%d) has been inserted\n",key);
}
void remov(int key)
{
	int hash1=hashfun1(key);
	int hash2=hashfun2(key);
	int index=hash1,i=1;
	if(size==0)
	{
		printf("hash table is empty\n");
		return;
	}
	while(array[index].flag!=0)
	{
		if(array[index].flag==1 && array[index].item->key==key)
		{
			array[index].item=NULL;
			array[index].flag=2;
			size--;
			printf("\n element %d is removed\n",key);
			return;
		}
		index=(index+i*hash2)%MAX;
		i++;
	}
	printf("element not found\n");
}
int size_of_hashtable()
{
	return(size);
}
void display()
{
	for(int i=0;i<MAX;i++)
	{
		if(array[i].flag!=1)
		{
			printf("\n array[%d] has no elements\n",i);
		}
		else{
			printf("\n array[%d] has elements\n key(%d) and value(%d)\n",i,array[i].item->key,array[i].item->value);
		}
	}
}
		
		
	
		
		
		
void main()
{
	int choice, key, value, n, c;
	
 
	array = (struct hash_table*) malloc(MAX * sizeof(struct hash_table));
	init_array();
 
	do {
		printf("Implementation of Hash Table in C with Doubling.\n\n");
		printf("MENU-: \n1.Inserting item in the Hash table" 
                              "\n2.Removing item from the Hash table" 
                              "\n3.Check the size of Hash table" 
                              "\n4.Display Hash table"
		       "\n\n Please enter your choice-:");
 
		scanf("%d", &choice);
 
		switch(choice)
                { 
		case 1:
 
		      printf("Inserting element in Hash table \n");
		      printf("Enter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);
 
		      break;
 
		case 2:
 
		      printf("Deleting in Hash table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remov(key);
 
		      break;
 
		case 3:
 
		      n = size_of_hashtable();
		      printf("Size of Hash table is-:%d\n", n);
 
		      break;
 
		case 4:
 
		      display();
 
		      break;
 
		default:
 
		       printf("Wrong Input\n");
 
		}
 
		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
 
	}while(c == 1);
 
	
 
}