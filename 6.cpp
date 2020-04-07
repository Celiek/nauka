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
          zahashowane+= line[i]-klucz;
        }
         else if(i<'Z'){
          zahashowane+= line[i]+klucz;
        }
        else if(i == 'X'){
        zahashowane+=(line[i]-26)+klucz;
        }
        else if(i =='Y'){
          zahashowane+=(line[i]-26)+klucz;
        }
        else if(i == 'Z'){
          zahashowane+=(line[i]-26)+klucz;
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
