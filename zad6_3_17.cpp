#include <iostream>
#include <fstream>
using namespace std;

int main(){
  int tablica[320][240];
  int roznica;
  int kontrastujace;
  int piksele;
  ifstream plik;
  plik.open("dane.txt");

  for(int i=0;i<200;i++){
      for(int j=0;j<320;j++){
      plik>>tablica[i][j];

      kontrastujace = 0;

        if(j>0){
          roznica = abs(tablica[i][j] - tablica[i][j-1]);
          if(roznica > 128) kontrastujace=1;
          }
        if(j<319){
          roznica = abs(tablica[i][j] - tablica[i][j+1]);
          if(roznica > 128) kontrastujace=1;
        }
        if(i>0){
          roznica = abs(tablica[i][j] - tablica[i-1][j]);
          if(roznica > 128) kontrastujace=1;
        }
        if(i <199){
          roznica = abs(tablica[i][j] - tablica[i+1][j]);
            if(roznica > 128) kontrastujace=1;
        }

      }
      if(kontrastujace==1) piksele++;
  }

  cout<<piksele<<"\n";
  return 0;
}
