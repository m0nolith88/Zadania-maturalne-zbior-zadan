#include <stdio.h>
#include <stdbool.h>

int NWD(int a, int b);

bool sprawdz(int a,int b){
  if(a>b){
    if(NWD(a,b)==1){
      return true;
    }
  } else if(b>a){
    if(NWD(b,a)==1){
      return true;
    }
  }
  return false;
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
  int a, b, licznik;
  if(fp==NULL){
    printf("Nie mozna otworzyc wskazanego pliku!\n");
    return -1;
  }
  for(int i=0;i<1000;i++){
    fgets(c,20,fp);
    sscanf(c,"%d %d", &a, &b);
    if(sprawdz(a,b)==true) {  
      licznik++;
    }
  }
  printf("Jest takich: %d liczb.\n",licznik);
  return 0;
}
