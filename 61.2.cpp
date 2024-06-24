#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[]){
  ifstream plik("bledne.txt");
  int ciagi[1000],roznice[1000];
  if(plik.is_open()){
    for(int q=0;q<40;q++){
      int dlugosc;
      plik>>dlugosc;
      for(int i=0;i<dlugosc;i++){
        plik>>ciagi[i];
      }
      for(int j=0;j<dlugosc;j++){
        roznice[j] = ciagi[j+1] - ciagi[j];
      }
      for(int i=0;i+1<dlugosc;i++){
        if(roznice[i]!=roznice[0]) {
          cout<<ciagi[i+1]<<endl;
        }
      }
    }
  }
    return 0;
}
