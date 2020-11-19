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
	struct item *data;
};
struct hash_table *array;
int size=0;
int max=10;
void init_array()
{
	for(int i=0;i<max;i++)
	{
		array[i].flag=0;
		array[i].data=NULL;
	}
}
int hashcode(int key)
{
	return(key%max);
}
void insert(int key,int value)
{
	int index=hashcode(key);
	int i=index;
	struct item *new_item=(struct item*)malloc(sizeof(struct item));
	new_item->key=key;
	new_item->value=value;
	while(array[i].flag==1)
	{
		if(array[i].data->key==key)
		{
			printf("dupliacte key");
			array[i].data->value=value;
			return;
		}
		i=(i+1)%max;
		if(i==index)
		{
			printf("hash is full\n");
			return;
		}
	}
	array[i].flag=1;
	array[i].data=new_item;
	size++;
	printf("\n key(%d) is inserted\n",key);
}
void remov(int key)
{
	int index=hashcode(key);
	int i= index;
	while(array[i].flag!=0)
	{
		if(array[i].flag==1 &&array[i].data->key==key)
		{
			array[i].flag=2;
			array[i].data=NULL;
			size--;
			printf("key (%d ) is deleted\n",key);
			return;
		}
		i=(i+1)%max;
		if(i==index)
		{
			break;
		}
	}
	printf("element not found");
}
void display()
{
	for(int i=0;i<max;i++)
	{
		struct item *cur=(struct item*)array[i].data;
		if(cur==NULL)
		{
			printf("\n Array[%d] has no elemets\n",i);
		}
		else{
			printf("\n Array[%d] has elemets\n %d key and %d value",i,cur->key,cur->value);
		}
	}
}
int sizeoftable()
{
	return(size);
}
void main()
{
	int choice,key,value,n,c;
	array=(struct hash_table*)malloc(max*sizeof(struct hash_table));
	init_array();
	while(1)
	{
		printf("1.insert\n 2.Delete 3.sizof hash table\n 4.Display\n 5.Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the ele\n");
					printf("enter the key and value\n");
					scanf("%d %d",&key,&value);
					insert(key,value);
					break;
			case 2:printf("enter the key to be deleted\n");
					scanf("%d",&key);
					remov(key);
					break;
			case 3: n=sizeoftable();
					printf("size=%d\n",n);
					break;
			case 4: display();
					break;
			
			default:exit(0);
		}
	}
}