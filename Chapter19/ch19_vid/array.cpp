/*
    g++ array.cpp -o array  
*/
#include "header.h"

//template függvény:
//Azon adatszerkezetekhez jó kiíratás, ahol van [] és size():
template<typename C>
void printout(const C& c)
{
  for (int i = 0; i < c.size(); ++i)
    cout<<c[i]<<endl;
}

template <typename T, int N>
struct my_array 
{
  //szinonimák/alias bevezetése. pl.: value_type alatt értjük a T típust
  using value_type = T;
  using iterator = T*; //pointer
  using const_iterator = const T*;
  using size_type = unsigned int; //unsigned int = előjel nélküli int.

  T elems[N]; // T típusú array N db elemnek
  //fordítási idejű polimorfizmus lesz a fentbbi N elem db-nek megadása

  //Iterátor függvények:
  //első elem:
  iterator begin() { return elems; }
  const_iterator begin() const { return elems; }
  //utolsó (utáni) elem:
  iterator end() { return elems+N; }
  const_iterator end() const { return elems+N; }
  
  //subscript operátor: N-edik elemre hivatkozó T referencia
  T& operator[](int n) { return elems[n]; } 
  const T& operator[] (int n) const { return elems[n]; }

  //méret kezelése:
  int size() const {return N;}
};

int main()
{
  my_array<int,2> int_array = {10,100};
  my_array<double,5> double_array ={0.1,0.2,0.3,0.4,0.5};
  
  for (int i = 0; i < int_array.size(); ++i)
  {
    cout<<int_array[i]<<endl;
  }

  for (int i = 0; i < double_array.size(); ++i)
  {
    cout<<double_array[i]<<endl;
  }

  printout(int_array);
  printout(double_array);
  vector<int> iv = {10,20,30,40,50};
  printout(iv);

  cout<<"Range for loop:"<<endl;
  for(const auto& e : double_array)
    cout<<e<<endl;
}
