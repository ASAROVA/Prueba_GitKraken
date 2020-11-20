#include <iostream>
#define SL cout<<endl
#define TB cout<<"\t"
using namespace std;

int main(void)
{
	cout << "\n\t\t >> ASAROVA << \n\n";

    void* punico;
    int     i = 5;
    float   f = 0.5;
    char    c = 'c';
    string  s = "cadena";
    bool    b = true;

    punico = &i;
    cout << *(int*)punico; TB;
    *(int*)punico = 8; 
    cout << *(int*)punico; SL;

    punico = &f;
    cout << *(float*)punico; TB;
    *(float*)punico = .8; 
    cout << *(float*)punico; SL;

    punico = &c;
    cout << *(char*)punico; TB;
    *(char*)punico = 'a'; 
    cout << *(char*)punico; SL;

    punico = &s;
    cout << *(string*)punico; TB;
    *(string*)punico = "soda"; 
    cout << *(string*)punico; SL;
	  
    //SL; cin.get();
	return 86;
}


