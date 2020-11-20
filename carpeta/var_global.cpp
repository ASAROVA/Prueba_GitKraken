#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<void*> var;


float f0 () { return *(float*)var[0] + *(float*)var[1]; }
float f1 () { return *(float*)var[0] - *(float*)var[1]; }
float f2 () { return *(float*)var[0] * *(float*)var[1]; }


int main()
{




  //vector<float(*)(float, float)> fun;
  //unordered_map<int,int(*)(float, float)> fun;

  /*
  vector<float(*)()> fun;
  fun.push_back(f0);
  fun.push_back(f1);
  fun.push_back(f2);
  */

  float(*fun[])()  = {f0,f1,f2};

  var.push_back(new float(3.0));
  var.push_back(new float(4.0));

  //cout << *(float *)var[0];


  cout << fun[0]() << endl;
  cout << fun[1]() << endl;
  cout << fun[2]() << endl;

}
