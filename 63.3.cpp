#include <iostream>
#include <cmath>

using namespace std;

int bin(int liczba){
  int dec = 0, i = 0, rem;

  while(liczba!=0){
    rem = liczba % 10;
    liczba /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
  
  return dec;
}

int main(int argc,char *argv[]){
  
  return 0;
}
