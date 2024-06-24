#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[]){
  string liczba;
  int licznik=0;
  fstream plik("ciagi.txt");
  if(plik.is_open()){
    for(int i=0;i<1000;i++){
      plik>>liczba;
      bool jedynki = true;
      for(int i=0; i<liczba.length();i++){
        if(liczba[i]=='1' && liczba[i+1]=='1') {
          jedynki=false;
        }
      }
      if(jedynki){
        licznik++;
      }
    }
  }
  plik.close();
  cout<<licznik<<endl;
  return 0;
}
