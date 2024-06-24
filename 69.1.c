#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define DLUGOSC 500
#define ILOSC 1000

int licz[DLUGOSC];
char geny[ILOSC][DLUGOSC];

void sprawdz() {
	int ileg,najw;
	for(int i=0; i<DLUGOSC; i++) {
		licz[i]=0;
	}
	for(int i=0; i<ILOSC; i++) {
		licz[strlen(geny[i])]++;
	}
	ileg=najw=0;
	for(int i=1;i<DLUGOSC; i++) {
		if(licz[i]>0) {
			ileg++;
		}
		if(licz[i]>najw) {
			najw=licz[i];
		}
	}
	printf("Liczba gatunkow:%d \n",ileg);
	printf("Rozmiar najwiekszego gatunku:%d \n",najw);
}

int main(int argc,char *argv[]) {
	FILE *fp = fopen("dane_geny.txt","rb");
	if(fp==NULL) {
		printf("Nie mozna otworzyc wskazanego pliku!\n");
		return 0;
	}
	for(int i=0;i<DLUGOSC;i++) {
		fgets(geny[i],DLUGOSC,fp);
	}
	
	sprawdz();

	return 0;
}
