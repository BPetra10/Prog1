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
#include <algorithm>

using namespace std; 

//6.
template<typename Iter1, typename Iter2> Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
  if(f1!=e1)
  {
    while(f1!=e1)
    {
      *f2 = *f1;
      ++f1;
      ++f2;
    }
  }
  return f2;
}

int main()
try{
  //1.
  int array1 [10] = {0,1,2,3,4,5,6,7,8,9};
  cout<<"Array: ";
  for(auto x : array1)
    cout<< x <<" ";
  cout<<"\n";
  
  //2.
  vector<int> v {0,1,2,3,4,5,6,7,8,9};
  cout<<"Vector: ";
  for(auto velem : v)
    cout<< velem <<" ";
  cout<<"\n";

  //3.
  list<int> list1 = {0,1,2,3,4,5,6,7,8,9};
  cout<<"List: ";
  for(auto lelem : list1)
    cout<< lelem <<" ";
  cout<<"\n \n";

  //4.
  int array2[10];
  for(int i=0; i<10;++i)
    array2[i]=array1[i];
  
  vector<int> v2 = v;
  list<int> list2 = list1;

  cout<<"Array copy: ";
  for(auto x2 : array2)
    cout<< x2 <<" ";
  cout<<"\n";

  cout<<"Vector copy: ";
  for(auto velem2 : v2)
    cout<< velem2 <<" ";
  cout<<"\n";

  cout<<"List copy: ";
  for(auto lelem2 : list2)
    cout<< lelem2 <<" ";
  cout<<"\n \n";

  //5.
  for(int i=0;i<10;++i)
    array1[i]+=2;

  cout<<"Array increased by 2: ";
  for(auto x : array1)
    cout<< x <<" ";
  cout<<"\n";

  for(int i=0; i<v.size(); ++i)
      v[i]+=3;

  cout<<"Vector increased by 3: ";
  for(auto x : v)
    cout<< x <<" ";
  cout<<"\n";

  list<int>::iterator p = list1.begin();
  if(p==list1.end())
    cout<<"The list is empty.\n";
  else
  {
    while(p != list1.end()) 
    {
      *p = *p+5;
      p++;
    }
  }
  cout<<"List increased by 5: ";
  for(auto x : list1)
    cout<< x <<" ";
  cout<<"\n \n";
  //7.
  //copy array into vector
  vector<int> v3(10);
  array<int,10> array3 = {0,1,2,3,4,5,6,7,8,9}; 
  my_copy(array3.begin(),array3.end(),v3.begin());
  
  //copy list into array
  array<int,10> array4;
  my_copy(list1.begin(),list1.end(),array4.begin());

  cout<<"Copy() array into vector: ";
  for(auto x : v3)
    cout<< x <<" ";
  cout<<"\n";

  cout<<"Copy() list into array: ";
  for(auto x : array4)
    cout<< x <<" ";
  cout<<"\n \n";

  //8.
  auto f_3_vec = find(v.begin(),v.end(),3);
  auto f_27_list = find(list1.begin(),list1.end(),27);

  if(f_3_vec!=v.end()) 
    cout << "Vector contains 3. \n";
  else 
    cout << "Vector doesn't contain 3. \n";

  if(f_27_list!=list1.end()) 
    cout << "List contains 27. \n";
  else 
    cout << "List doesn't contain 27. \n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Something went wrong! \n";
    return 2;
}