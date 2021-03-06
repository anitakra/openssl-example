#include "crypto.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  cout << "SHA-1 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha1("Test")) << endl << endl;
  
  cout << "SHA-1 with two iterations" << endl;
  cout << Crypto::hex(Crypto::sha1(Crypto::sha1("Test"))) << endl;

  cout << "The derived key from the PBKDF2 algorithm" << endl;
  cout << Crypto::hex(Crypto::pbkdf2("Password", "Salt")) << endl;
  
  // Oving 8 oppg 3
  string salt = "Saltet til Ola";
  char passord[3];

  for(int i = 65; i <= 122; i++) {
    for(int j = 65; j <= 122; j++) {
      for(int k = 65; k <= 122; k++) {
        
        passord[0] = i;
        passord[1] = j;
        passord[2] = k;
        
        if (Crypto::hex(Crypto::pbkdf2(passord, salt, 2048, 160 / 8))== "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6"){
          cout << "Passordet er: " << passord;
        }
      }
    }
  }
}