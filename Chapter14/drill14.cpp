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
   virtual void pvf() = 0;
};

class D1:B1
{
    public:
    void vf() override {cout<<"D1::vf()\n";};
    //void f(){cout<<"D1::f()\n";};
};

class D2:D1
{
    public:
        void pvf() {cout<<"D2::pvf()\n";};
};

int main()
{
    B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();
}