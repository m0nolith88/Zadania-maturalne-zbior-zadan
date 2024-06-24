#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[]){
  string ciag;
  fstream plik("ciagi.txt");
  if(plik.is_open()){
    for(int i=0;i<1000;i++){
      plik>>ciag;
      int dlugosc = ciag.length()/2;
      bool dwucykliczny = true;
      for(int i=0; i<dlugosc; i++){
        if(ciag[i]!=ciag[dlugosc+i]){
          dwucykliczny = false;
        } 
      }
      if(dwucykliczny){
        cout<<ciag<<endl;
      }
    }
  }
  plik.close();
  return 0;
}
