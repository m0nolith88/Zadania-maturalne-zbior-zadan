#include <stdio.h>
#include <stdbool.h>

bool czyMoznaZbudowac(int a,int b,int c){
  if((a+b>c)&&(c+a>b)&&(b+c>a)){
    return true;
  } else {
    return false;
  }
}

int main(){
  FILE *fp = fopen("trojki.txt","rb");
  char in[50]; int a,b,c; long licznik=0,dlugosc=0,najdluzszy=0;
  if(fp==NULL){
    printf("Nie mozna otworzyc pliku %s\n","trojki.txt");
    return EOF;
  }
  while(fgets(in,50,fp)){
    sscanf(in,"%d %d %d",&a,&b,&c);
    if(czyMoznaZbudowac(a,b,c)){
      licznik++;
      dlugosc++;
    } else {
      if(dlugosc>najdluzszy){
        dlugosc=najdluzszy;
      }
      dlugosc=0;
    } 
  }
  printf("Jest %ld takich trojek.Najwieksza dlugosc ciagu to: %ld \n",licznik,dlugosc);
  return 0;
}
