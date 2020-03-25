#include <iostream>
#include<cmath>
using namespace std;

class Numar_Complex
{
    double im;
    double re;

public:

    Numar_Complex();
    Numar_Complex(double a, double b);
    Numar_Complex(const Numar_Complex& );
    ~Numar_Complex();
    void setez(double re, double im);
    double get_re();
    double get_im();
    void afisare();
    double modul ();
    friend Numar_Complex operator+ (const Numar_Complex &a, const Numar_Complex &b);
    friend Numar_Complex operator- (const Numar_Complex &a, const Numar_Complex &b);
    friend Numar_Complex operator* (const Numar_Complex &a, const Numar_Complex &b);
    friend Numar_Complex operator* (const Numar_Complex &a, int b);
    friend Numar_Complex operator/ (const Numar_Complex &a, const Numar_Complex &b);
    friend Numar_Complex operator- (Numar_Complex a);
    Numar_Complex sqrt1 (Numar_Complex a);

};

Numar_Complex::Numar_Complex()
{
    re=0;im=0;
    cout<<"S-a initializat1 \n";
}

Numar_Complex::Numar_Complex(double re, double im)
{
    this->re=re;
    this->im=im;
    cout<<"S-a initializat2 \n";
}

Numar_Complex::Numar_Complex(const Numar_Complex& a)
{
    re=a.re;
    im=a.im;
}

Numar_Complex::~Numar_Complex()
{
   cout<<"S-a distrus \n";
}

void Numar_Complex::setez(double re, double im)
{
    this->re=re;
    this->im=im;
}

double Numar_Complex::get_re()
{
    return this->re;
}

double Numar_Complex::get_im()
{
    return this->im;
}

void Numar_Complex::afisare()
{
    if (im==0)
        cout<<re;
    else if (im<0)
           cout<<re<<im<<"i"<<"\n";
        else cout<<re<<"+"<<im<<"i"<<"\n";

}
Numar_Complex operator+ (const Numar_Complex &a, const Numar_Complex &b)
{
    Numar_Complex rez;
    rez.re = a.re + b.re;
    rez.im = a.im + b.im;
    return rez;
}

Numar_Complex operator- (const Numar_Complex &a, const Numar_Complex &b)
{
    Numar_Complex rez;
    rez.re = a.re - b.re;
    rez.im = a.im - b.im;
    return rez;
}

Numar_Complex operator* (const Numar_Complex &a, const Numar_Complex &b)
{
    Numar_Complex rez;
    rez.re = a.re*b.re - a.im*b.im;
    rez.im = a.re*b.im + a.im*b.re;
    return rez;
}

Numar_Complex operator* (const Numar_Complex &a, int b)//inmultirea unui nr complex cu un nr real
{
    Numar_Complex rez;
    rez.re = a.re * b;
    rez.im = a.im * b;
    return rez;
}

Numar_Complex operator/ (const Numar_Complex &a, const Numar_Complex &b)
{
    Numar_Complex rez;
    rez.re =((a.re * b.re)+(a.im * b.im))/(b.re*b.re + b.im*b.im);
    rez.im =((a.im * b.re)-(a.re * b.im))/(b.re*b.re + b.im*b.im);
    return rez;
}

Numar_Complex operator- (Numar_Complex a)//opusul numarului
{
    a.re = -a.re;
    a.im = -a.im;
    return a;
}

double Numar_Complex::modul ()
{
    double p;
    p= sqrt((this->re)(this->re)+(this->im)(this->im));
    return p;


Numar_Complex Numar_Complex::sqrt1 (Numar_Complex a)
{
    Numar_Complex rez;
    rez.re = sqrt((a.re + sqrt(a.re*a.re + a.im*a.im) /2));
    rez.im = (a.im/2) * sqrt(2/(a.re + sqrt(a.re*a.re + a.im*a.im)));
    return rez;

}

int main()
{
    Numar_Complex  A(2,1), B(2,5), C(1,-3), delta, D;
    Numar_Complex  x1, x2;
    delta = B*B -(A*C)*4;
    D=-B;
    x1=(D+delta.sqrt1)/(A*2);
    x2=(D-delta.sqrt1)/(A*2);
    x1.afisare();
    x2.afisare();
    return 0;
}
