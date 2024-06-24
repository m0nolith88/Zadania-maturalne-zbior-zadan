#include <stdio.h>
#include <stdbool.h>

int NWD(int a, int b);

bool sprawdz(int a,int b){
}


int NWD(int a,int b){
  int pom;
  while(b!=0){
    pom=b;
    b = a%b;
    a = pom;
  }
  return a;
}

int main(){
  FILE *fp = fopen("dane_ulamki.txt","rb");
  char c[20];
  int a, b, licznik,lista_dzielnikow[1000],lista_liczb[1000],suma;
  if(fp==NULL){
    printf("Nie mozna otworzyc wskazanego pliku!\n");
    return -1;
  }
  for(int i=0;i<1000;i++){
    fgets(c,20,fp);
    sscanf(c,"%d %d", &a, &b);
    lista_dzielnikow[i]=NWD(a,b);
    lista_liczb[i]=a;
  }
  for(int i=0;i<1000;i++){
    
    suma=suma+lista_liczb[i]/lista_dzielnikow[i];
  }
  printf("Wynik to %d \n",suma);
  return 0;
}
