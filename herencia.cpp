#include <iostream>
#include <string>
#define SL cout<<endl
using namespace std;

/// Vehiculo ///////////////////////////////////
class vehiculo
{
protected:
    string nombre;
    string tipo;
    //vehiculo() {}
public:
    vehiculo(string Nombre, string Tipo="vehiculo"):
        nombre(Nombre), tipo(Tipo)
    { cout<<"Se ha creado al "<<tipo<<" "<<nombre;SL; }
    void encender()   { cout<<nombre<<" encendido.";SL; }
    void acelerar()   { cout<<nombre<<" acelerando...";SL; }
    void retroceder() { cout<<nombre<<" retrocediendo...";SL; }
    void apagar()     { cout<<nombre<<" apagado.";SL; }
    void quien_soy()  { cout<<"Soy el "<<tipo<<" "<<nombre;SL;}
};
/// //////////////////////////////////////////*/


/// Automovil //////////////////////////////////
class automovil: virtual public vehiculo
{
protected:
    int ruedas;
public:
    automovil(string Nombre, int Ruedas=4):
        vehiculo(Nombre,"automovil"), ruedas(Ruedas)
    { cout<<"\tCon "<<ruedas<<" ruedas";SL; }

    void encender()     { cout<<"Caja en 1ra. ";
                          vehiculo::encender();  }
    void frenar()       { cout<<nombre<<" frenando "<<ruedas<<" ruedas...";SL; }
    void estacionar()   { cout<<nombre<<" estacionado.";SL; }
    void girar()        { cout<<nombre<<" girando volante de auto...";SL; }
    void cambiar(int N) { cout<< "Accionando embrague. Cambiando a "<<N<<
                                 "a. Caja en "<<N<<"a.";SL;           }

};
/// //////////////////////////////////////////*/


/// Embarcacion ////////////////////////////////
class embarcacion: virtual public vehiculo
{
protected:
    int propelas;
public:
    embarcacion(string nombre, int Propelas=2):
        vehiculo(nombre), propelas(Propelas)
    { cout<<"\tCon "<<propelas<<" propelas";SL; }
    void encender()     { cout<<"Alistando propelas. ";
                          vehiculo::encender();         }
    void zarpar()       { cout<<nombre<<" zarpando con "<<propelas<<" propelas";SL; }
    void anclar()       { cout<<nombre<<" anclado.";SL; }
    void girar()        { cout<<nombre<<" girando timon de barco...";SL; }
    void cambiar(int N) { cout<< "Cambiando a "<<N<<"a. Motor en "<<N<<"a.";SL; }
};
/// //////////////////////////////////////////*/


/// Anfibio ///////////////////////////////////
class anfibio: public automovil,
               public embarcacion
{
    bool navegando = true;
public:
    anfibio(string Nombre, int Ruedas=6, int Propelas=3):
        //automovil(Nombre,4),
        automovil   (Nombre,Ruedas),
        embarcacion (Nombre,Propelas),
        vehiculo    (Nombre,"anfibio")     // Se puede porque los padres usaron: virtual public vehiculo (herencia virtual)
        {}
    void zarpar()       { navegando = true;
                          embarcacion::zarpar(); }
    void encender()     { cout<<"Escurriendo motor. ";
                          embarcacion::encender();
                          automovil::encender();
                          vehiculo::encender();         }
    void encallar()     { cout<<nombre<<" encallando.";SL;
                          navegando = false;                }
    void cambiar(int N) { if(navegando) embarcacion::cambiar(N);
                          else          automovil::cambiar(N);  }
    void girar()        { if(navegando) embarcacion::girar();
                          else          automovil::girar();   }
};
/// //////////////////////////////////////////*/

int main(void)
{
	cout << "\n\t\t >> ASAROVA << \n\n";

    anfibio norman("Norman");
    norman.quien_soy();

    norman.encender();
    norman.zarpar();
    norman.cambiar(2);
    norman.girar();
    norman.encallar();
    norman.acelerar();
    norman.girar();
    norman.frenar();
    norman.retroceder();
    norman.estacionar();
    norman.apagar();

	cout << endl;
	return 86;
}

