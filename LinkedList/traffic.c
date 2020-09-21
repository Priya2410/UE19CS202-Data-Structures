#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[]="Red";
	int time=5*60;
	int t=0;
	int choice;
	while(1)
	{
		printf("%s\n","Enter 0 to exit,1 for showing the traffic light");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
			exit(0);
			break;
			case 1:
			while(t!=time)
				{
					t++;
				}
					if(strcmp(a,"Green")==0)
					{
						printf("%s\n","The vechicle can move");
						strcpy(a,"Red");
						printf("%s\n","Enter 0 to exit");
						scanf("%d",&choice);
						if(choice==0)
							exit(0);
					}

					else if(strcmp(a,"Red")==0)
					{
						printf("%s\n","Red Light");
						strcpy(a,"Yellow");
					}
					else
					{
						printf("%s\n","Yellow Light");
						strcpy(a,"Green");
					}
					t=0;
			break;
		}
	}
	// printf("%s","The light you stopped on is");
	// printf("%s\n",a);
}