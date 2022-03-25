/*
    g++ drill20.cpp -o drill20  
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <array>
#include <list>
#include <iterator>

using namespace std; 

int main()
{
  //1.
  int array1 [10] = {0,1,2,3,4,5,6,7,8,9};
  cout<<"Array:\n";
  for(auto x : array1)
    cout<< x <<"\n";

  //2.
  vector<int> v {0,1,2,3,4,5,6,7,8,9};
  cout<<"Vector:\n";
  for(auto velem : v)
    cout<< velem <<"\n";

  //3.
  list<int> list1 = {0,1,2,3,4,5,6,7,8,9};
  cout<<"List:\n";
  for(auto lelem : list1)
    cout<< lelem <<"\n";

  //4.
  int array2[10];
  for(int i=0; i<10;++i)
    array2[i]=array1[i];
  
  vector<int> v2 = v;
  list<int> list2 = list1;

  cout<<"Array copy:\n";
  for(auto x2 : array2)
    cout<< x2 <<"\n";

  cout<<"Vector copy:\n";
  for(auto velem2 : v2)
    cout<< velem2 <<"\n";
  
  cout<<"List copy:\n";
  for(auto lelem2 : list2)
    cout<< lelem2 <<"\n";
  
  //5.
  for(int i=0;i<10;++i)
    array1[i]+=2;

  cout<<"Array increased by 2:\n";
  for(auto x : array1)
    cout<< x <<"\n";
  
  for(int i=0; i<v.size(); ++i)
      v[i]+=3;

  cout<<"Vector increased by 3:\n";
  for(auto x : v)
    cout<< x <<"\n";
  

  list<int>::iterator p = list1.begin();
  while(p != list1.end()) 
  {
    *p = *p+5;
    p++;
  }
  cout<<"List increased by 5:\n";
  for(auto x : list1)
    cout<< x <<"\n";
}