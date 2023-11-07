#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void iki_boyutlu_dizi_olustur(int ***dizi, int satir, int sutun)
{
	int i,j;
	for(i=0; i<satir; i++)
	*dizi=(int**)malloc(sizeof(int*)*satir);
	for(i=0; i<satir; i++)
	{
		*(*dizi+i)=(int*)malloc(sizeof(int)*4);
		for(j=0; j<sutun; j++)
		*(*(*dizi+i)+j)=rand()%100;
	}
	for(i=0; i<satir; i++)
	{
		for(j=0; j<sutun; j++)
		printf("%5d",*(*(*dizi+i)+j));
		printf("\n");
	}
}

int main ()
{
	srand(time(NULL));
	int **dizi;
	int satir_sayisi=5;
	int sutun_sayisi=4;
	iki_boyutlu_dizi_olustur(&dizi,satir_sayisi,sutun_sayisi);
}
