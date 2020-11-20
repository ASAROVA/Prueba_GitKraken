#include <iostream>
using namespace std;
#define SL cout<<endl

int main(int argc, char *argv[])
{
	cout << "\n\t\t>> ASAROVA << "; SL;SL;

	int coef = 5;
	auto fun = [&coef](int a) { return a * coef; }; 
	cout << fun(2); SL;

	coef = 15;
	cout << fun(2); SL; SL;

	auto rutina = [&] { cout << coef; SL; };
	rutina();
	rutina();

	return 86;
}