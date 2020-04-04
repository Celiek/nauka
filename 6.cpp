#include <iostream>
#include <fstream>
#include <cstring>
std::ifstream plik;

void szyfrowanie(int klucz, char tablica[]){

  if(klucz > 26){
    klucz = klucz%26;
  }

  std::string pomocnicza;
  for(int i=0;i<100;i++){
    pomocnicza = tablica[i];
    int rozmiar = sizeof(pomocnicza);
    for(int j=0;j<=rozmiar;j++){
      if(pomocnicza[j]>'A'){
        pomocnicza[j]=pomocnicza[j]+klucz;
      }
      if(pomocnicza[j]<'Z'){
        pomocnicza[j] = pomocnicza[j]-klucz;
      }
    }
    tablica[i] = pomocnicza[i];
  }
}

int main(){
    char tablica[100];
    int klucz;
    std::cout << "Podaj klucz :" << '\n';
    std::cin>>klucz;
    std::string linijka;


    plik.open("dane_6_1.txt");
    if(plik.good()){
      std::cout << "Plik otwarto" << '\n';

      std::cout << "Pliki przed konwersją : " << '\n';

      while(!plik.eof()){
        getline(plik,linijka);
        std::cout << linijka << '\n';
      }
    }
    else{
      std::cout << "Błąd otwarcia pliku." << '\n';
    }

    plik.close();

    std::cout << "Pliki po konwersji : " << '\n';

    szyfrowanie(klucz,tablica);

    for(int i=0;i<100;i++){
        std::cout << tablica[i] << '\n';
    }

      return 0;
}
