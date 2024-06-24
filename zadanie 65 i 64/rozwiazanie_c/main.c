#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct obrazek{
 char obraz[41][20]; 
};

int main(int argc,char *argv[]){
  FILE *fp = fopen("dane_obrazki.txt","rb");
  int k=0;
  int bialy=0,czarny=0,rewersy=0;
  struct obrazek p[220];
  char c[41][20];
  if(fp==NULL){
    printf("Nie mozna zaladowac pliku!");
    return -1;
  }
  for(int q=0; q<111; q++){  
    for(int i=0; i<41; i++){
      for(int j=0; j<21; j++) {  
        fgets(&p[q].obraz[i][j],20,fp); 
         if (p[q].obraz[i][j]=='0'){
          bialy++;
        } else if(p[q].obraz[i][j]=='1'){
          czarny++;
        }
      }
    }
    if(czarny>bialy){
      rewersy++;
    }
    bialy=czarny=0;
  }
  printf("Rewersy %d \n",rewersy);
  return 0;
}
