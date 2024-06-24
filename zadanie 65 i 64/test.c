#include <stdio.h>

int obraz[6][6]={
    {0,1,1,0,0,0},
    {1,1,1,0,1,0},
    {1,1,1,1,1,1},
    {0,1,1,0,0,0},
    {1,1,0,0,1,1},
    {1,1,0,1,1,0},
};

int stanPoprawnosci(int pobraz[6][6]){
    // 0 poprawny
    // 1 naprawialny
    // >1 nienaprawialny, wynik to liczba blednych parzystosci
    int i,j,parzw,parzk;
    int ileBlWiersz, ileBlKol;

    ileBlWiersz=0;
    ileBlKol=0;
    for(i=0;i<6;i++){
        parzw=parzk=0;
        for(j=0;j<6;j++){
            parzw=parzw+pobraz[i][j];
            parzk=parzk+pobraz[j][i];
        }
        printf("%d\n",parzw);
        printf("%d\n",parzk);
        if ((parzw%2)!=pobraz[i][5]) ileBlWiersz++;
        if ((parzk%2)!=pobraz[5][i]) ileBlKol++;
    }

    if (ileBlWiersz+ileBlKol==0) return 0;
    if (ileBlWiersz<=1 && ileBlKol<=1) return 1;
    return ileBlWiersz+ileBlKol;

}

int main()
{
  if(stanPoprawnosci(obraz)){
    printf("Poprawny!\n");
  } else {
    printf("Bledny!\n");
  }
}
