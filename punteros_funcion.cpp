#include <iostream>
using namespace std;
#define SL cout<<endl

typedef int (*TPF)(int);
typedef int TF(int);
TF f;


int main(void)
{
	cout << "\n\t\t >> ASAROVA << \n\n";

	TF* pf1 = f;
	TF* pf2 = &f;
	TPF pf3 = f;

    cout << f(4);   SL;
    cout << pf1(4); SL;
    cout << pf2(4); SL;
    cout << pf3(4); SL;

    SL;
	return 86;
}

int f(int x) { return x*x; }


