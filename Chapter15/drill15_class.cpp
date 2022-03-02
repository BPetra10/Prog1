/*
    g++ drill15_class.cpp -o drill15_class  
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

struct Person
{
    Person():name_var(""), age_var(0){};
    string name() const {return name_var;}
    int age() const {return age_var;}

    private:
        string name_var;
        int age_var;
};

int main()
{
    /* 
    Person p;
    p.name_var = "Goofy";
    p.age_var = 63;
    cout<<"2. The person is: "<<p.name_var<<" his age: "<<p.age_var<<"\n";
    */
}