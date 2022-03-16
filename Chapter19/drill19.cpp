/*
    g++ drill19.cpp -o drill19  
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

template<typename T> 
struct S 
{
    //2. constructor
    S():val(T()){};
    S(T s):val(s){};

    //5.
    T& get();

    //7.
    private:
        T val;
};

//6.
template<typename T> T& S<T>::get() {return val;};

int main()
{
 //3.
  S<int> int_example {11};
  S<char> char_example {'c'};
  S<double> double_example {16.5};
  S<string> string_example {"this is a string"};
  vector<int> v {1,2,5,6};
  S<vector<int>> vector_example {v};

  //4.
  /*We set T private, so this print does not work:
  cout<<"int example: "<<int_example.val<<"\n";
  cout<<"char example: "<<char_example.val<<"\n";
  cout<<"double example: "<<double_example.val<<"\n";
  cout<<"string example: "<<string_example.val<<"\n";
  cout<<"Vector example:\n";
    for(int i=0;i<vector_example.val.size();++i)
        cout<<vector_example.val[i]<<"\n";
  */

  //8.
  cout<<"task 8:\n";
  cout<<"int example: "<<int_example.get()<<"\n";
  cout<<"char example: "<<char_example.get()<<"\n";
  cout<<"double example: "<<double_example.get()<<"\n";
  cout<<"string example: "<<string_example.get()<<"\n";
  cout<<"Vector example:\n";
    for(int i=0;i<vector_example.get().size();++i)
        cout<<vector_example.get()[i]<<"\n";
}
