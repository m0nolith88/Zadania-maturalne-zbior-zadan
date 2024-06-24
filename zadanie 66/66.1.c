#include <stdio.h>
#include <stdbool.h>

int rozloz(int n){
  int suma=0;
  while(n){
    suma=suma+n%10;
    n=n/10;
  }
  return suma;
}

bool sprawdz(int liczba1, int liczba2,int liczba3){
  if((rozloz(liczba1)+rozloz(liczba2))==liczba3){
    return true;
  } else {
    return false;
  }
}

int main(){
  FILE *fp = fopen("trojki.txt","rb");
  int a,b,c;
  char in[50];
  if(fp==NULL){
    printf("Nie mozna otworzyc wskazanego pliku!\n");
    return 0;
  }
  while(fgets(in,50,fp)){
      sscanf(in,"%d %d %d",&a, &b, &c);
      if(sprawdz(a,b,c)) {  
        printf("%d %d %d \n",a,b,c);
      }
  }
  return 0;
}
