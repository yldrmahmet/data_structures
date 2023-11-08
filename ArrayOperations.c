#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create (int **p, int size) 
{
	int i;
	*p=(int*)malloc(sizeof(int)*size);
	for(i=0; i<size; i++)
	*(*p+i)=rand()%20+1; // 1 ile 20 arasinda rastgele sayi dondurur 
}

void print (int *p, int size) {
	int i;
	printf("\nARRAY : \n");
	for(i=0; i<size; i++)
	{
	if(i%10==0)
	printf("\n");
	printf("%5d", *(p+i));
	}
	printf("\n");
}

void insert (int **p, int size) 
{
	*(*p+(size-1))=rand()%20+1;
}

int main () 
{
	srand(time(0)); // for random number production
	int *p;
	int arraySize;
	printf("enter a number\n");
	scanf("%d",&arraySize);
	create(&p,arraySize);
	print(p,arraySize);
	insert(&p,++arraySize);
	print(p,arraySize);
	/*
	CREATE APP
	while(1)
	{
		printf("\n(for quit enter -1)\nplease enter array size: ");
		scanf("%d",&arraySize);
		if(arraySize>100)
		printf("\nmax size must be less than 100, please try again\n\n");
		else if (arraySize==-1)
		{
		printf("\nthanks for using");
		break;
		}
		else
		{
		create(&p,arraySize);
		print(p,arraySize);
		}
	}
	*/
	return(0);
}
