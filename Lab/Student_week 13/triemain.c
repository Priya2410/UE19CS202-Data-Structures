#include <stdio.h>
#include "trie.h"

 int main()
 {
  struct trienode *root;
  char key[100];
  int ch,k;
  int loop = 1;
  root=getnode();
  while(loop)
  {
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: /*printf("Enter word..\n");*/
              scanf("%s",key);
              insert(root,key);
              break;
    case 2: /*printf("Enter the word for deletion..\n");*/
               scanf("%s",key);
               top=0;
               delete_trie(root,key);
               break;
       case 3: /*printf("Enter the word to search..\n");*/
               scanf("%s",key);
               k=search(root,key);
               if(k)
                 printf("1\n");
               else
                 printf("-1\n");
               break;

        case 0:loop=0;
        		break;
    }
  }
 }
void printnewline()
{
	printf("\n");
}
 void printfun(int n)
{
	printf("%c",n);
}
