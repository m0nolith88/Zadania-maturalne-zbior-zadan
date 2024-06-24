#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int osemkowy(string liczba){
  return (int) strtol(liczba.c_str(),NULL,8);
}

int main(int argc,char *argv[]) {
  int liczby2,licznik1=0,licznik2=0; //licznik1 zlicza liczby o takiej samej wartosci
  string liczba1; 
  fstream plik1("liczby1.txt");
  fstream plik2("liczby2.txt");
  if(plik1.is_open() && plik2.is_open()){
     for(int i=0; i<1000; i++){ 
      plik1>>liczba1;
      plik2>>liczby2;
      if(osemkowy(liczba1) == liczby2) {
        licznik1++;
      } else if(osemkowy(liczba1)>liczby2) {
        licznik2++;
      }
     }
  } else {
    cout<<"Nie mozna otworzyc pliku!"<<endl;
    return -1;
  }
  plik1.close();
  plik2.close();

  cout<<licznik1<<endl;
  cout<<licznik2<<endl;

  return 0;
}
