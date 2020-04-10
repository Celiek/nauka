#include <iostream>
#include <fstream>
#include <cstring>
std::ifstream plik;

std::string szyfrowanie(std::string line, int klucz){
    std::string zahashowane;
    int j=-1;
    if(klucz>26){
      klucz=klucz%26;
    }

    int dlugosc = line.length();

      for(int i=0;dlugosc>=i;i++){
        if(i>'A'){
          if(line[i] == 'X'|| line[i]=='Y' || line[i]=='Z'){
              zahashowane+= line[i]+klucz-26;
          }
          else{
          zahashowane+= line[i]-klucz;
          }
        }
         else if(i<'Z'){
          zahashowane+= line[i]+klucz;
        }
      }
      return zahashowane;
}


int main(){
  int klucz = 107;
  plik.open("dane_6_1.txt");
    if(plik.good()){
      std::string line;
      while(std::getline(plik,line)){
        std::string newLine = szyfrowanie(line,klucz);
        std::cout << line << '\n';
        std::cout<<newLine<<std::endl;
      }

      std::cout << line << '\n';

    }
}
