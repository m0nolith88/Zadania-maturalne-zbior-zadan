#include <stdio.h>


int main(){
  FILE *fp = fopen("dane_ulamki.txt","rb");
  char c[18];
  float a, b;
  if(fp==NULL){
    printf("Nie mozna otworzyc wskazanego pliku!\n");
    return -1;
  }
  float najmniejszy=1;
  char *najmniejsza;
  for(int i=0;i<999;i++){
    
    fgets(c,18,fp);
    sscanf(c,"%f %f", &a, &b);
    if(najmniejszy>(a/b)){
      najmniejsza=c;
      najmniejszy=(a/b);
      printf("%s \n",najmniejsza);
    }
  }
  return 0;
}
