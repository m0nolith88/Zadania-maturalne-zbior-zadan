#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define OSOBNIKI 1000
#define GENOM 500

char geny[OSOBNIKI][GENOM];
char najdluzszy[GENOM];
int naj=0;

void policz(char gen[]);

void policz(char gen[]) {
	bool in=false;
	int len=0,current=0;
	for(int i=0;i<=strlen(gen);i++) {
		if(gen[i]=='A' && gen[i+1]=='A') {
			in=true;
			current++;	
		}	
		if(gen[i]=='B' && gen[i+1]=='B') {
			if(in==true) {
				if(naj<current) {
					naj=current;
				}
				in=false;
				current=0;
			}
		}
		if(in==true) {
			current++;
		}
	}
	return;
}

int main(){
	FILE *fp = fopen("dane_geny.txt","rb");
	if(fp==NULL) {
		return 0;
	}
	for(int i=0;i<=OSOBNIKI;i++){
		fgets(geny[i],GENOM,fp);
	}
	for(int i=0;i<=OSOBNIKI;i++){
		policz(geny[i]);
	}
	printf("Najdluzszy genom ma dlugosc:%d\n",naj);
	return 0;
}
