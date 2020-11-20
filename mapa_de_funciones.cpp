// MAPA DE FUNCIONES
// >> ASAROVA <<

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

float f1 (float x, float y) { return x+y; }
float f2 (float x, float y) { return x-y; }
float f3 (float x, float y) { return x*y; }

int main()
{
  unordered_map<int,float(*)(float, float)> diccfun;
  diccfun[1] = f1;
  diccfun[2] = f2;
  diccfun[3] = f3;

  cout << diccfun[1](3,4) << endl;
  cout << diccfun[2](3,4) << endl;
  cout << diccfun[3](3,4) << endl;
}
