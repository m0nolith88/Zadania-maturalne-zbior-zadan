#include <stdio.h>
#include <stdlib.h>

void sprawdz(int licz[1000],int mian[1000]){
  int mianS, liczS, nowyLicz;
  liczS=0;
  mianS=2*3*5*7*13;
  mianS=mianS*mianS/13;
  for(int i=0;i<1000;i++){
    nowyLicz = licz[i]*mianS/mian[i];
    liczS +=nowyLicz;
  }
  printf("Wynik to: %d\n",liczS);
}

int main(){
  FILE *fp = fopen("dane_ulamki.txt","rb");
  char c[20];
  int a, b,licznik,listaM[1000],listaL[1000];
  if(fp==NULL){
    printf("Nie mozna otworzyc wskazanego pliku!\n");
    return -1;
  }
  for(int i=0;i<1000;i++){
    fgets(c,20,fp);
    sscanf(c,"%d %d", &a, &b);
    listaM[i]=b; listaL[i]=a;
  }
  sprawdz(listaL,listaM);
  return 0;
}
