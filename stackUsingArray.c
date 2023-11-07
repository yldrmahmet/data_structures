// array kullanarak stack uygulamasi

#include <stdio.h>
#define MAX_SIZE 101

// global degiskenler
int myStack[MAX_SIZE]; 
int top=-1; //top = en son eklenen eleman

// stack eleman ekle
void push (int eklenecekSayi) 
{
	if(top==MAX_SIZE - 1)
	{
		printf("hata: stack owerflow (stack tamamen dolu)\n");
		return;
	}
	myStack[++top]=eklenecekSayi;  /* top++; A[top]=x; */
}

// stack eleman sil, parametre yok cunku topu silecek, top==en son eklenen eleman
void pop ()
{
	if(top==-1)
	{
		printf("hata: stackte eleman yok\n");
		return;
	}
	top--;
}

// en sonki elemani dondur
int TOPF ()
{
	return myStack[top];
}

// yazdir
void print ()
{
	int i;
	printf("STACK :");
	for (i=0; i<top+1; i++)
		printf("%5d",myStack[i]);
	printf("\n");
}

int main (){
	push(5);print();
	push(6);print();
	push(15);print();
	pop();print();
	pop();print();
	push(53);print();
	return 0;
}
