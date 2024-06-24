#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DLUGOSC 500
#define ILOSC 1000

struct gen {
	int poczatek; //Poczatek sekwencji AA
	int koniec; //Koniec sekwencji BB
};

int znalezione=0;

const char mutacja[] = "BCDDC";
char gen[ILOSC][DLUGOSC];

void sprawdzPattern(char sekwencja[],int poczatek,int koniec);

void sprawdzGen(char geny[]){
	bool in=false;
	int wgenie=0,poczatek=0,koniec=0;
	struct gen *sekwencja = (struct gen *) malloc(sizeof(struct gen));
	for(int i=0; i<strlen(geny);i++) {
		if(geny[i]=='A' && geny[i+1]=='A') {
			sekwencja->poczatek=i;
			in=true;
		}
		if(strlen(geny)-4==0) {
			printf("Ciag jest za krotki(Sekwencja AABB)\n");
			break;
		}
		if(geny[i]=='B' && geny[i+1]=='B') {
			if(in==true) {	
				sekwencja->koniec=i+1;
				sprawdzPattern(geny,sekwencja->poczatek,sekwencja->koniec);
				in=false;
			}
		}
	}
	free(sekwencja);
	return;
}

void sprawdzPattern(char sekwencja[],int poczatek,int koniec) {
	int len=0;
	if((koniec-poczatek)>0) {
		len = (koniec-poczatek);
	} else {
		printf("Blad! %d\n",koniec-poczatek);
		return;
	}
	char wysekwencjonowany[len+1];
	strncpy(wysekwencjonowany,sekwencja+poczatek,len);
	wysekwencjonowany[len+1]='\0';
	if(strstr(wysekwencjonowany,mutacja)!=NULL) {
		printf("Znaleziono zmutowany gen w sekwencji: |%s|\n",wysekwencjonowany);
	  znalezione++;	
		return;
	}else{
		return;
	}
}

int main(int argc,char *argv[]) {
	FILE *fp = fopen("dane_geny.txt","rb");
	if(fp==NULL){
		printf("Nie mozna otworzyc wskazanego pliku!\n");
		return 0;
	}
	for(int i=0; i<ILOSC; i++) {
		fgets(gen[i],DLUGOSC,fp);
	}
	for(int i=0;i<ILOSC;i++) {
		sprawdzGen(gen[i]);
	}
	printf("Znalezionych ogółem %d\n",znalezione);
	return 0;
}
