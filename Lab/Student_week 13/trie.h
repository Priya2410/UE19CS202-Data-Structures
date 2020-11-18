#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
  struct trienode *m;
  int index;
};
struct trienode
{
   struct trienode* child[26];
   int endofword;
};
struct trienode *getnode();
void insert(struct trienode *, char *);
void display(struct trienode*);
void delete_trie(struct trienode*,char*);
int search(struct trienode *,char *);
int check(struct trienode *);
void push(struct trienode*,int);
void printnewline();
void printfun(int);
struct stack pop();

char word[100];
int length;
int top;
struct stack s[100];//stack
