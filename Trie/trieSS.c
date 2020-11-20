#include<stdio.h>
#include<stdlib.h>

//Node structure of trie
typedef struct trie
{
    int isleaf;
    struct trie *child[26];
}TRIE;

TRIE* getnode()
{
    //Initialization 
    TRIE *temp=(TRIE *)malloc(sizeof(TRIE *));
    temp->isleaf=0;
    for(int i=0;i<26;i++)
    {
        temp->child[i]=NULL;
    }
    return temp;
}

void insert_string(TRIE *root,char *str)
{
    TRIE *cur=root;
    while(*str)   //Equivalent to str[i]!='\0'
    {
        //To get index of the current alphabet's ascii value
        //If the current alphabet doesnt exist already create a new node for it so that it can point to it
       if(cur->child[*str-'a']==NULL)
       {
           cur->child[*str-'a']=getnode();
       }
       //To move the pointer
       cur=cur->child[*str-'a'];
       str++;
    }
    cur->isleaf=1; //to mark the end of word 
}

int search(TREE *root,char *str)
{
    TRIE *cur=root;
    while(*str)
    {
        if(cur->child[*str-'a']==NULL)
        return 0;
        else
        {
        cur=cur->child[*str-'a'];
        str++;
        }
    }
    if(cur->isleaf == 0)
    return 0;
    else
    return 1;
}

//Multiple pattern search
//Here text is a article the result of the number of words found are stored in a array where we have 10 words 20 characters long
int mp_search(TRIE *root,char *text,char res[10][20])
{
    TRIE *cur;
    int i=0;
    char temp[20];
    //While there are characters in the text
    while(*text)
    {
        cur=root; //for every word //cur is set to the trie initially all the characters in first position are stored 
        g=text; 
        int k=0;
        while(*g)
        {
            if(cur->child[*g-'a']==NULL) //No pattern there
            {
                break;
            }
            cur=cur->child[*g-'a'];
            temp[k++]=*g; //Character is captured becuase we found one character
            //We have to check everytime that the cur is leaf so that we can store all the possible patterns 
            if(cur->isleaf==1)
            {
                temp[k]='\0';
                strcpy(res[i],temp);
                i++;
            }
            g++;
        }
        text++; //Equivalent to moving to next position
    }
    return --i;
}
int main()
{
    TRIE *root=getnode();
    insert(root,"pan");
    insert(root,"paneer");
    insert(root,"pat");
    insert(root,"test");
    insert(root,"banner");
    insert(root,"batter");
    if(search(root,"pat"))
        printf("Found !!\n");
    else
        printf("Not found :(\n");

    if(search(root,"pa"))
        printf("Found !!\n");
    else
        printf("Not found :(\n");
        
    if(search(root,"cow"))
        printf("Found !!\n");
    else
        printf("Not found :(\n");
}