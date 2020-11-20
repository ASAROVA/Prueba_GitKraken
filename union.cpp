#include <iostream>
using namespace std;
#define SL cout<<endl

class VECTOR3D
{
public:
    // operations, etc...

    union
    {
        float m[3];

        struct
        {
            float x, y, z;
        };
    }; 
};

int main()
{
    SL;SL; cout<<"\t>> ASAROVA <<"; SL;SL;

    VECTOR3D v;

    // same effect
    v.m[2] = 1.0f;
    // v.x = 1.0f;

    // cout << v.m[0];
    cout << v.x; SL;
    cout << v.y; SL;
    cout << v.z; SL;

    SL;SL; return 86;
}


