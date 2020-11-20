#include <iostream>
using namespace std;

class persona
{
    public:
    void que_eres() { cout<<"Soy una persona."<<endl; }
};

class estudiante: public persona
{
    public:
    void que_eres()
    {
        cout<<"Soy un estudiante."<<endl;
        persona::que_eres();
    }
};

class empleado: public persona
{
    public:
    void que_eres()
    {
        cout<<"Soy un empleado."<<endl;
        persona::que_eres();
    }
};

class practicante: public estudiante, public empleado
{
    public:
    void que_eres()
    {
        estudiante::que_eres();
        empleado::que_eres();
    }
};

int main()
{
    practicante jose;
    jose.que_eres();
}
