#include <stdio.h>
#include <stdbool.h>

bool sprawdz(int a,int b,int c){
  if(((a*a)+(b*b))==(c*c)){
    return true;
  } else {
    return false;
  }
}

int main(){
  FILE *fp = fopen("trojki.txt","rb");
  char in[50]; int a,b,c;
  if(fp==NULL){
    printf("Nie mozna otworzyc pliku %s\n","trojki.txt");
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
