#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bir_boyutlu_dizi_olustur(int **dizi, int eleman_sayisi)
{
	int i;
	*dizi = (int*)malloc(sizeof(int)*eleman_sayisi);
	for(i=0; i<eleman_sayisi; i++)
		*(*dizi+i)=rand()%100;
	for(i=0; i<eleman_sayisi; i++)
		printf("%5d",*(*dizi+i));
}

int main ()
{
	srand(time(NULL));
	int *dizi;
	int eleman_sayisi=6;
	bir_boyutlu_dizi_olustur(&dizi,eleman_sayisi);
	
	/*
	FONKSIYON KULLANMADAN MAIN ICINDE YAPILAN YONTEM
	
	int i;
	int *dizi;
	int eleman_sayisi=6;
	dizi = (int*)malloc(eleman_sayisi*sizeof(int));
	for(i=0; i<eleman_sayisi; i++)
		*(dizi+i) = rand()%100;
	for(i=0; i<eleman_sayisi; i++)
		printf("%5d",*(dizi+i));
	*/
}
