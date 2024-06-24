#include <stdio.h>
#include <stdbool.h>

bool pierwsza(int n){
  if(n<2){
    return false;
  }
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

bool sprawdz(int a,int b,int c){
  if((pierwsza(a) && pierwsza(b))&&((a*b)==c)){
   return true; 
  } else {
   return false;
  }
}

int main(int argc,char *argv[]){
  FILE *fp = fopen("trojki.txt","rb");
  char in[50]; int a, b, c;
  if(fp == NULL){
    printf("Nie mozna otworzyc wskazanego pliku\n");
    return EOF;
  }
  while(fgets(in,50,fp)){
    sscanf(in,"%d %d %d",&a,&b,&c);
    if(sprawdz(a,b,c)){
      printf("%d %d %d\n",a,b,c);
    }
  }
  return 0;
}
