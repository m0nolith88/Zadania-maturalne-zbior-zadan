#include <iostream>
#include <fstream>

#define ROZMIAR 20

using namespace std;


struct obrazki{
  string dane[ROZMIAR+1]; 
};

int main(int argc,char *argv[]){
  fstream plik("dane_obrazki.txt");
  struct obrazki lista[200];
  string obrazki;
  if(plik.is_open()){
    for(int i=0;i<200; i++){
        for(int q=0;q<ROZMIAR+1;q++) {
            plik>>obrazki;
            lista[i].dane[q]=obrazki;
        }
      }
  }
  int czarne=0, biale=0,rewersy =1,najczar=0;
  for(int j=0; j<200; j++) {  
    czarne = biale = 0;
    for(int q=0; q<ROZMIAR+1; q++) {
      for(int i=0; i<ROZMIAR+1; i++){
        if(lista[j].dane[q][i]=='1'){
          czarne++; 
        } else {
          biale++;
        } 
      }
    }
    if(czarne>biale){
      rewersy++;
    }
    if(czarne>najczar){
      najczar=czarne;
    }
  } 
  cout<<rewersy<<endl;
  cout<<najczar<<endl;
  plik.close();
  return 0;
}
