#include <iostream>
#include <sstream>
using namespace std;

#define SL cout<<endl

int main(void)
{
	cout << "\n\t\t >> ASAROVA << \n\n";

	int i = 86;
	string s;

    ostringstream oss;

    oss << "ASAROVA" << i << endl;
    s = oss.str();
    cout << s;

    istringstream iss;
    s = "25     48";
    iss.str(s);
    iss >> i;
    cout << i << endl;  // displays 25

    iss >> i;
    cout << i << endl;  // displays 25

	cout << endl;
	return 86;
}

