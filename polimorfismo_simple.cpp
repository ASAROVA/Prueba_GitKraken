#include<iostream>
using namespace std;
#define SL cout<<endl

class A
 { public: virtual void m() {cout<<"Soy A";} };
class B: public A
 { public: void m() {cout<<"Soy B";} };
class C: public A
 { public: void m() {cout<<"Soy C";} };

void f(A &a) { a.m(); }	    // referencia
void fv(A a) { a.m(); }	    // copia (o valor)
void fp(A*a) { a->m(); }	// puntero


int main(int argc, char *argv[])
{
	A *c = new C;
	B b;

	c->m(); SL;
	b.m(); SL;SL;

	f(*c); SL;
	f(b); SL;SL;

	fv(*c); SL;
	fv(b); SL; SL;

	fp(c); SL;
	fp(&b); SL; SL;

	return 86;
}
