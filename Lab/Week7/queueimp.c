#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
	node *newnode=(node *)malloc(sizeof(node));
	newnode->id=id;
	newnode->time=time;
	newnode->link=link;
	return newnode;
}
void list_initialize(List *ptr_list)
{
//TODO
	ptr_list=(List *)malloc(sizeof(List));
	ptr_list->head=NULL;
	ptr_list->tail=NULL;
	ptr_list->number_of_nodes=0;
}
const int node_get_id(node *node_ptr)
{
//TODO	
	return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
//TODO		
	return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO	
	node *newnode=create_node(id,time,NULL);
	node *temp;
	if(ptr_list->head==NULL)
	{
		ptr_list->head=newnode;
		ptr_list->tail=newnode;
		ptr_list->number_of_nodes++;
	}
	else
	{
		temp=ptr_list->head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;
		ptr_list->tail=newnode;
		ptr_list->number_of_nodes++;
	}
}

void list_delete_front(List *ptr_list)
{
//TODO	
	node *temp;
	if(ptr_list->head==NULL)
		return;
	else
	{
		temp=ptr_list->head;
		ptr_list->head=temp->link;
		ptr_list->number_of_nodes--;
		free(temp);
	}
}

void list_destroy(List *ptr_list)
{
//TODO	
	node *temp,*prev;
	if(ptr_list->head==NULL)
		return;
	else
	{
		temp=ptr_list->head;
		while(temp!=NULL)
		{
			prev=temp;
			temp=temp->link;
			free(prev);
		}
		ptr_list=NULL;
		free(ptr_list);
	}
}

void queue_initialize(Queue *queue_list)
{
//TODO	
	queue_list=(Queue *)malloc(sizeof(Queue));
	List *list=(List*) malloc(sizeof(List));
	queue_list->ptr_list=list;
}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO
	list_insert_rear(ptr->ptr_list,id,time);	
}

void queue_dequeue(Queue *ptr)
{
//TODO	
	list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
//TODO
	if(ptr->ptr_list->number_of_nodes==0)
		return 1;
	else
		return 0;		
}

void queue_peek(Queue *ptr)
{
//TODO	
	if(ptr->ptr_list->head==NULL)
		printf("Empty queue\n");
	else
		printf("%d %d\n",node_get_id(ptr->ptr_list->head),node_get_time(ptr->ptr_list->head));	
}

void queue_destroy(Queue *ptr)
{
//TODO		
	list_destroy(ptr->ptr_list);
	ptr=NULL;
	free(ptr);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO		
	node *temp;
	int totalTime=0;
	if(ptr_queue->ptr_list->head==NULL)
	{
		printf("Empty Queue\n");
	}
	else
	{
		temp=ptr_queue->ptr_list->head;
		while(temp!=NULL)
		{
			totalTime+= temp->time;
			if(t==totalTime)
			{
				if(temp->link==NULL)
				{
				printf("Empty Queue\n");
				queue_dequeue(ptr_queue);
				break;
				}
				if(temp->link==ptr_queue->ptr_list->head->link)
				{
					queue_dequeue(ptr_queue);
					temp=temp->link;
					printf("%d\n",temp->id);
					break;
				}
				printf("%d\n",temp->link->id);
				break;
			}
			else if(t<totalTime)
			{
				printf("%d\n",temp->id);
				break;
			}
			queue_dequeue(ptr_queue);
			temp=temp->link;
		}
		if(t>totalTime)
			printf("Empty Queue\n");
	}
}
