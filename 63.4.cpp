#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

  
int main(int argc,char *argv[]) {
  int licznik=0,liczby[1000];
  fstream plik1("liczby2.txt");
  if(plik1.is_open()){
     for(int i=0; i<1000; i++){ 
       plik1>>liczby[i]; 
       int tymczasowa = liczby[i];
       while(tymczasowa>0){
        if(tymczasowa%10==6){
          licznik++;
        }
       }
     }
  } else {
    cout<<"Nie mozna otworzyc pliku!"<<endl;
    return -1;
  }
  plik1.close();
  
  cout<<licznik<<endl;
  return EOF;
}
