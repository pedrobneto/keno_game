#include <iostream>
#include <string>
#include <fstream>
#include "t2m.h"

using std::cout;
using std::ofstream;
using std::string;

string text_to_morse(string texto) {
  
  int tamanho = texto.size();
  
  ofstream morse;
  
  morse.open("arquivo.txt");

  if(morse.is_open()) {
    for(int i = 0; i < tamanho; i++) {
      switch(texto[i]) {
      
      case 'a':
      case 'A':
        morse << ".- ";
        break;
      
      case 'b':
      case 'B':
        morse << "-... ";
        break;
      
      case 'c':
      case 'C':
        morse << "-.-. ";
        break;
      
      case 'd':
      case 'D':
        morse << "-.. ";
        break;
      
      case 'e':
      case 'E':
        morse << ". ";
        break;
      
      case 'f':
      case 'F':
        morse << "..-. ";
        break;
      
      case 'g':
      case 'G':
        morse << "--. ";
        break;
      
      case 'h':
      case 'H':
        morse << ".... ";
        break;
      
      case 'i':
      case 'I':
        morse << ".. ";
        break;
      
      case 'j':
      case 'J':
        morse << ".--- ";
        break;
      
      case 'k':
      case 'K':
        morse << "-.- ";
        break;
      
      case 'l':
      case 'L':
        morse << ".-.. ";
        break;
      
      case 'm':
      case 'M':
        morse << "-- ";
        break;
      
      case 'n':
      case 'N':
        morse << "-. ";
        break;
      
      case 'o':
      case 'O':
        morse << "--- ";
        break;
      
      case 'p':
      case 'P':
        morse << ".--. ";
        break;
      
      case 'q':
      case 'Q':
        morse << "--.- ";
        break;
      
      case 'r':
      case 'R':
        morse << ".-. ";
        break;
      
      case 's':
      case 'S':
        morse << "... ";
        break;
      
      case 't':
      case 'T':
        morse << "- ";
        break;
      
      case 'u':
      case 'U':
        morse << "..- ";
        break;
      
      case 'v':
      case 'V':
        morse << "...- ";
        break;
      
      case 'w':
      case 'W':
        morse << ".-- ";
        break;
      
      case 'x':
      case 'X':
        morse << "-..- ";
        break;
      
      case 'y':
      case 'Y':
        morse << "-.-- ";
        break;
      
      case 'z':
      case 'Z':
        morse << "--.. ";
        break;
      
      case '.':
        morse << ".-.-.- ";
        break;
      
      case ',':
        morse << "--..-- ";
        break;
      
      case ' ':
        morse << "/ ";     
        break;  
      }
    }
  
  morse.close();
  }
  return texto;
  
}
