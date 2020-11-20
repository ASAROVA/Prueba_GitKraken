    #include <iostream>
    #include <variant>

    using namespace std;
    #define SL cout<<endl

    class DATO
    {
        variant<int,float,char,bool,string> v;

        public:
        DATO() {}
        DATO(int    i)  { v = i; }
        DATO(float  f)  { v = f; }
        DATO(char   c)  { v = c; }
        DATO(bool   b)  { v = b; }
        DATO(string s)  { v = s; }

        DATO(double d)  { v = float(d); }
        DATO(char c[])  { string s = c; v = s; }

        operator int()    const { return *(get_if<int>   (&v)); }
        operator float()  const { return *(get_if<float> (&v)); }
        operator char()   const { return *(get_if<char>  (&v)); }
        operator bool()   const { return *(get_if<bool>  (&v)); }
        operator string() const { return *(get_if<string>(&v)); }

        friend ostream &operator<<(ostream &, DATO const &);

    };

    ostream &operator<<(ostream &os, DATO const &d)
    {
        switch (d.v.index())
        {
            case 0:  return os << get<int>   (d.v);
            case 1:  return os << get<float> (d.v);
            case 2:  return os << get<char>  (d.v);
            case 3:  return os << get<bool>  (d.v);
            case 4:  return os << get<string>(d.v);
            default: return os << "";
        }
    }

    int main(void)
    {
        cout << "\n\t\t >> ASAROVA << \n\n";

        DATO d;

        d = 9;
        int i=d;
        d = i-2*i;
        cout << i; SL;
        cout << d; SL;SL;

        d = 1.618034;
        float f = d;
        d = 1/f;
        cout << f; SL;
        cout << d; SL;SL;

        d = 'a';
        char c = d;
        d = char(int(c) - 32);
        cout << c; SL;
        cout << d; SL;SL;

        d = true;
        bool b = d;
        d = b && false;
        cout << b; SL;
        cout << d; SL;SL;

        d = "Hola desbordadores de pila";
        string s=d;
        s = s + ".";
        cout << d; SL;
        cout << s; SL;SL;

        SL;SL;

        return 86;
    }


