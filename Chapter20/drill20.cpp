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

//template for printing:
template<typename T> void write(const T& t, string s)
{
  cout<< s <<" ";
  for(auto& x : t)
    cout<< x <<" ";
  cout<<"\n";
}

//template for summation:
template<typename T>
void increase(T& t, int plus)
{
    for (auto& a : t)
        a += plus;
}

//6. template for copy:
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
  write(array1,"Array:");
  //2.
  vector<int> v {0,1,2,3,4,5,6,7,8,9};
  write(v,"Vector:");
  //3.
  list<int> list1 = {0,1,2,3,4,5,6,7,8,9};
  write(list1,"List:");
  cout<<"\n";

  //4. copy with = 
  int array2[10];
  for(int i=0; i<10;++i)
    array2[i]=array1[i];
  
  vector<int> v2 = v;
  list<int> list2 = list1;

  write(array2,"Array copy:");
  write(v2,"Vector copy:");
  write(list2,"List copy:");
  cout<<"\n";

  //5.
  increase(array1,2);
  write(array1,"Array increased by 2:");
  increase(v,3);
  write(v,"Vector increased by 3:");
  increase(list1,5);
  write(list1,"List increased by 5:");
  cout<<"\n";

  /*for(int i=0;i<10;++i)
    array1[i]+=2;
  write(array1,"Array increased by 2:");
  
  for(int i=0; i<v.size(); ++i)
      v[i]+=3;
  write(v,"Vector increased by 3:");

  list<int>::iterator p = list1.begin();
  if(p==list1.end())
    cout<<"The list is empty.\n";
  else
  {
    while(p != list1.end()) 
    {*p = *p+5;
      p++;}
  }
  write(list1,"List increased by 5:");
  */
  
  //7.
  //copy array into vector
  vector<int> v3(10);
  array<int,10> array3 = {0,1,2,3,4,5,6,7,8,9}; 
  my_copy(array3.begin(),array3.end(),v3.begin());
  
  //copy list into array
  array<int,10> array4;
  my_copy(list1.begin(),list1.end(),array4.begin());

  write(v3,"Copy() array into vector:");
  write(array4,"Copy() list into array:");
  cout<<"\n";

  //8. find()
  auto f_3_vec = find(v.begin(),v.end(),3);
  auto f_27_list = find(list1.begin(),list1.end(),27);

  (f_3_vec!=v.end()) 
   ? cout << "Vector contains 3. \n"
   : cout << "Vector doesn't contain 3. \n";

  (f_27_list!=list1.end()) 
   ? cout << "List contains 27. \n" 
   : cout << "List doesn't contain 27. \n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Something went wrong! \n";
    return 2;
}