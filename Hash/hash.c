//for student record srn,name,cgpa
// we have to apply hash function on srn and extract last three digits of it and apply the hash function.

#include<stdio.h>

typedef struct student
{
    char srn[15];
    char name[25];
    float cgpa;
}STUD;

int hf(char *srn)
{
    char temp[5];
    int k=0;
    //Extract the digits 
    //PES2UG19CS301 pick index 10 to 12
    for(int i=10;i<13;i++)
    {
        temp[k++]=srn[i];
    }
    temp[k]='\0';
    //To convert to integer
    //Ascii to integer
    //Division by prime number this is a hash function
    return (atoi(temp) % 47);
}

int search(STUD ht[50],char *srn)
{
    int hashkey=hf(srn);
    if(strcmp(ht[hashkey].srn,'\0')==0)
    return 0; //srn isnt present here deletion isnt considered
    else
    return 1;

}
int main()
{
    char temp[25];
    int wish;
    //  50 student records
    STUD ht[50];
    //to initialize the records with null to tell that they are empty
    for(int i=0;i<50;i++)
    {
        //Initializing the srn position with Null string
        strcpy(ht[i].srn,'\0');
    }
    do
    {
    printf("Enter srn \n");
    scanf("%s",temp);
    int hashkey;
    //Apply hash function on srn ie temp here
    hashkey=hf(temp);
    //to check if the hash key is null or not
    //if hashkey location is empty
        if(strcmp(ht[hashkey].srn,'\0')==0)
        {   
            //copy the srn
            strcpy(ht[hashkey].srn,temp);
            //Now ask for name and gpa
            printf("Enter the name of the student\n");
            scanf("%s",ht[hashkey].name);
            printf("Enter the cgpa of the student\n");
            scanf("%f",ht[hashkey].cgpa);
        }
        //if the position isnt empty proceed with linear probing
        {
            //to find the next value where it is vacant
            int j=(hashkey+1)%47;
            //I have to find till one round till prev hashkey isnt completed 
            while(j!=hashkey && (strcmp(ht[hashkey].srn,'\0')==0))
            {
                j=(hashkey+1)%47;
            }
            if(j==hashkey)
            {
                printf("Its full");
            }
            else
            {
                strcpy(strcmp(ht[hashkey].srn,temp);
                printf("Enter the name of the student\n");
                scanf("%s",ht[hashkey].name);
                printf("Enter the cgpa of the student\n");
                scanf("%f",ht[hashkey].cgpa);
            }
            }
        }
        printf("Do you want to add new record yes/1 no/0");
        scanf("%d",&wish);
    }while(wish);



    //Search 
    printf("Enter the srn to be searched \n");
    scanf("%s",temp1);
    if(search(ht,temp1))
    printf("Yes found it !");
    else
    printf("did not find it !");
}
