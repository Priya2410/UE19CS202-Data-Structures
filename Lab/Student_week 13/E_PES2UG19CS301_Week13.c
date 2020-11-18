#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
  {
    //TODO
    int i;
    struct trienode * temp=(struct trienode *)malloc(sizeof(struct trienode));
    for(i=0;i<26;i++)
    {
      temp->child[i]= NULL;
    }
    temp->endofword = 0;
    return temp;
  }

  void insert(struct trienode *root, char *key)
  {
     //TODO
    struct trienode *c;
    int in,j;
    c=root;
    for(j=0;key[j]!='\0';j++)
      {
        in=(key[j]-97);
        if(c->child[in]==NULL)
        {
          c->child[in]=getnode();
        }
        c=c->child[in];
      }
      c->endofword=1;
  }
void display(struct trienode *curr)
  {
      //TODO: 
     //Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output 
     int i,j;
     for(int i=0;i<26;i++)
     {
       if(curr->child[i]!=NULL)
       {
         word[length++]=i;
         if(curr->child[j]->endofword == 1)
         {
           printnewline();
           for(j=0;j<length;j++)
           {
             printfun(word[j]);
           }
         }
         display(curr->child[i]);
       }
     }
    length--;
    return ;
 }

  int search(struct trienode * root,char *key)
  {
  //TODO
    int in,j;
    struct trienode *c;
    c=root;
    for(j=0;key[j]!='\0';++j)
    {
      in=(key[j]-97);
      if(c->child[in]==NULL)
      return 0;
      c=c->child[in];
    }
    if(c->endofword==1)
    return 1;
    return 0;
  }


 void delete_trie(struct trienode *root,char *key)
  {
    //TODO
    int in,k,j;
    struct stack st;
    struct trienode *c;
    c=root;
    for(j=0;key[j]!='\0';++j)
    {
      in=(key[j]-97);
      if(c->child[in]==NULL)
      {
        return;
      }
      push(c,in);
      c=c->child[in];
    }
    c->endofword=0;
    push(c,-1);
    while(1)
    {
      st=pop();
      if(st.index !=-1)
      {
        st.m->child[st.index]=NULL;
      }
      if(st.m==root)
      {
        break;
      }
      k=check(st.m);
      if((k>=1) || (st.m->endofword==1))
      break;
      else
      free(st.m);
      }
  }

  int check(struct trienode *x)
  {
    //TODO
    int j,c=0;
    for(j=0;j<26;j++)
    {
      if(x->child[j]!=NULL)
      {
        ++c;
      }
    }
    return c;
 }

  void push(struct trienode *x,int k)
  {
    //TODO
    ++top;
    s[top].m=x;
    s[top].index=k;
  } 

  struct stack pop()
  {
    //TODO
    struct stack temp;
    temp=s[top--];
    return temp;
  }





















 /*void display(struct trienode *curr)
 {
   int i,j;
   for(i=0;i<26;i++)
   {
     if(curr->child[i]!=NULL)
     {
       word[length++]=i+97;
       if(curr->child[i]->endofword==1)//if word found
       {
          printf("\n");//print the word
          for(j=0;j<length;j++)
             printf("%c",word[j]);
        }
       display(curr->child[i]);
     }
    }
    length--;
    return;
 }



 struct trienode *getnode()
 {
   int i;
   struct trienode *temp;
   temp=(struct trienode*)malloc(sizeof(struct trienode));
   for(i=0;i<26;i++)
    temp->child[i]=NULL;
  temp->endofword=0;
   return temp;
 }


 void insert(struct trienode * root, char *key)
 {
   int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        curr->child[index]=getnode();
      curr=curr->child[index];
    }
    curr->endofword=1;
  }


 int search(struct trienode * root,char *key)
  {

  int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];
    }
    if(curr->endofword==1)
       return 1;
   return 0;
  }

 void delete_trie(struct trienode *root,char *key)
  {
    int i,j,index,flag;
    struct trienode* curr;
    curr=root;
    flag=1;

    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
      {
         printf("Key not found\n");
         return;
      }
      curr=curr->child[index];
    }
      curr->endofword=0;
      return;
  }*/













 


 
 



















