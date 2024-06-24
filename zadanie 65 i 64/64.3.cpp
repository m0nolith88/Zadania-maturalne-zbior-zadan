#include <iostream>
#include <fstream>
#include <string>

#define ROZMIAR 20

using namespace std;

struct obrazki{
  string dane[ROZMIAR+1];
};

int wertykalny[6] = {0,0,1,1,0,0};

bool test1(struct obrazki *obraz){
  int i,j,parzw,parzk;
  int ileBlWiersz, ileBlKol;

  ileBlWiersz=0;
  ileBlKol=0;
  for(i=0;i<20;i++){
    parzw=parzk=0;
    for(j=0;j<20;j++){
      if(obraz->dane[i][j]=='1'){
        parzw=parzw+stoi("1");
      } else {
        parzw=parzw+stoi("0");
      }
      if(obraz->dane[j][i]=='1'){
        parzk=parzk+stoi("1");
      } else {
        parzk=parzk+stoi("0");
      }
    }
    if((parzw%2) != obraz->dane[i][20]) ileBlWiersz++;
    if((parzk%2) != obraz->dane[20][i]) ileBlKol++;
  }
  if(ileBlWiersz+ileBlKol==0) return 0;
  if(ileBlWiersz<=1 && ileBlKol<-1) return 1;
}

/*bool test(struct obrazki *obraz){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(obraz->dane[i][j]!=obraz->dane[i+10][j]){
        return false;
      }
      if(obraz->dane[i][j]!=obraz->dane[i][j+10]){
        return false;
      }
      if(obraz->dane[i][j]!=obraz->dane[i+10][j+10]){
        return false;
      }
    }
  }
  return true;
}
*/
int main(int argc,char *argv[]){
  fstream plik("dane_obrazki.txt");
  struct obrazki lista[200];
  string obrazki;
  if(plik.is_open()){
    for(int i=0; i<200; i++){
      for(int q=0; q<ROZMIAR+1;q++){
        plik>>obrazki;
        lista[i].dane[q]=obrazki;
      }
    }
  }
  int licznik=0; struct obrazki lista_parzystych[200];
  for(int i=0;i<200;i++){
    if(test1(&lista[i])){
      cout<<"poprawny!"<<endl;
    } else {
      cout<<"niepoprawny!"<<endl;
    }
  }
  plik.close();
  return 0;
}
