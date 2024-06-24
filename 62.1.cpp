#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

int main(int argc,char *argv[]){
  ifstream plik("liczby1.txt");
  int liczby[1000],max=0,min=INT_MAX;
  if(plik.is_open()){
    for(int i=0;i<1000;i++) {
      plik>>liczby[i];
      if(max < liczby[i]){
        max=liczby[i];
      }
      if(min > liczby[i]){
        min=liczby[i];
      }
    }
  } else {
    cout<<"Nie mozna otworzyc pliku"<<endl;
    return -1;
  }
  cout<<max<<endl;
  cout<<min<<endl;
  plik.close();
  return 0;
}
