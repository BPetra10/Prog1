/*
    g++ drill14.cpp -o drill14  
*/

#include <iostream>
#include <string>

using std::cout;
using std::string; 

class B1
{
 public:
   virtual void vf(){cout<<"B1::vf()\n";};
   void f(){cout<<"B1::f()\n";};
   //5.
   virtual void pvf() = 0;
};

//2.
class D1:public B1
{
    public:
    void vf() override {cout<<"D1::vf()\n";};
    //4.
    void f(){cout<<"D1::f()\n";};
};

//6.
class D2:public D1
{
    public:
        void pvf() {cout<<"D2::pvf()\n";};
};

//7.
class B2
{
    public:
        virtual void pvf()=0;
};

class D21: public B2
{
    public:
        string d21_string;
        void pvf() {cout<< d21_string <<"\n";};
};

class D22: public D21
{
    public:
        int d22_int;
        void pvf() {cout<< d22_int <<"\n";};        
};

void f(B2& b)
{
    b.pvf();
}

int main()
{
    /* Ez azt az eredményt adja, amíg nincs a D1-ben f() 1-3
    B1::vf()
    B1::f()
    D1::vf()
    B1::f()
    D1::vf()
    B1::f()

    4. feladat után:
    Ahol már a D1-ben megírt az f():
    B1::vf()
    B1::f()
    D1::vf()
    D1::f() 
    D1::vf()
    D1::f()
    */

    //1.
    /*
    B1 b1;
    b1.vf();
    b1.f();

    //2.
    D1 d1;
    d1.vf();
    d1.f();

    //3.
    B1& ref = d1;
    d1.vf();
    d1.f();
    */
    
    //5. pure virtual function
    /*
    B1, D1 = absztrakt
    B1 absztrakt pvf(),
    a D1 pedig nem írja felül a B1 pvf-ét.
    */

    //6.
    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();
    /* 6. feladat utáni lefutás:
    D1::vf()
    D1::f()
    D2::pvf()
    */

    //7.
    D21 d21;
    d21.d21_string="write D21 string";

    D22 d22;
    d22.d22_int=6;
    f(d21);
    f(d22);
}