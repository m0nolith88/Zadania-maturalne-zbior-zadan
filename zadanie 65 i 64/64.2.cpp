#include <iostream>
#include <fstream>

#define ROZMIAR 20

using namespace std;

struct obrazki{
  string dane[ROZMIAR+1];
};

bool test(struct obrazki *obraz){
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
    if(test(&lista[i])){
      licznik++; 
      lista_parzystych[i] = lista[i];
    } 
  }
  cout<<licznik<<endl;
  plik.close();
  return 0;
}
