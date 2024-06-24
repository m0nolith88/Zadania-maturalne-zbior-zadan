#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream plik("liczby2.txt");
    int liczba,poprzednia=-1,dlugosc=0,najdluzszy=0,pierwsza=-1, pierwsza_najwiekszej=-1;
    if(plik.is_open()){
      for (int i=0;i<1000;i++){
        plik>>liczba;
        if(poprzednia>=liczba){
          dlugosc++;
        } else {
          dlugosc=1;
          pierwsza = liczba;
        }
        if(dlugosc>=najdluzszy){
          najdluzszy = dlugosc;
          pierwsza = pierwsza_najwiekszej;
        }
        poprzednia = liczba;
      }
    }  else {
        cout<<"Nie mozna otworzyc pliku"<<endl;
        return -1;
    }
    cout<<najdluzszy<<endl;
    cout<<pierwsza_najwiekszej<<endl;
    return 0;
}

