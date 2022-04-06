#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>
#include <list>

using namespace std;

struct Item 
{
    string name;
    int iid;
    double value;
};

ostream& operator<<(ostream& os, Item& it)
{
    return os << it.name <<" "<<it.iid<<" "<<it.value<<"\n";
}

istream& operator>>(istream& is, Item& it)
{
    string ss;
    int ii;
    double dd;
    is>>ss>>ii>>dd;
    Item final_it {ss,ii,dd};
    it = final_it;
    return is;
}

//template for printing
template<typename C>
void write(C& c, string s)
{
    cout<<s<<"\n";
    for (auto p = c.begin();p!=c.end(); ++p)
        cout<<*p;
    cout<<"\n";
}

int main()
try{
    vector<Item> vi;
    string iname {"items.txt"};
    ifstream ist {iname};
    if (!ist) runtime_error("can't open input file "+ iname);

    for (Item it; ist >> it; ) vi.push_back(it);
    
    write(vi,"Original vector:");

    //2.
    string a,b;

    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.name < b.name;});

    write(vi,"After sort by name:");
	
    //3.
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.iid < b.iid;});
    
    write(vi,"After sort by id:");

    //4.
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.value > b.value;});
    
    write(vi,"After sort by value:");

    //5.
    Item horse {"horse shoe",99,12.34};
    Item canon {"Canon S400",9988,499.95};
    vi.insert(vi.begin(), horse);
    vi.insert(vi.begin(), canon);
    write(vi,"After insert:");

    //6.
    string name="horse shoe";
    vi.erase(find_if(vi.begin(),vi.end(),
        [name](const Item& a){return a.name == name;}));
    
    write(vi,"Remove by name:");

    //7.
    int id=9988;
    vi.erase(find_if(vi.begin(),vi.end(),
        [id](const Item& a){return a.iid == id;}));

    write(vi,"Remove by id:");

    //8. Repeat the excercise with list:
    //1.
    list<Item> li;
    string iname2 {"items.txt"};
    ifstream ist2 {iname2};
    if (!ist) runtime_error("can't open input file "+ iname2);

    for (Item it; ist2 >> it; ) li.push_back(it);
    
    write(li,"Original list:");

    //2.
    string a2,b2;
    li.sort([](const Item& a2, const Item& b2){return a2.name < b2.name;});
    write(li,"After sort by name:");

    //3.
    li.sort([](const Item& a2, const Item& b2){return a2.iid < b2.iid;});
    write(li,"After sort by id:");
    
    //4.
    li.sort([](const Item& a2, const Item& b2){return a2.value > b2.value;});
    write(li,"After sort by value:");

    //5.
    li.insert(li.begin(), horse);
    li.insert(li.begin(), canon);
    write(li,"After insert:");
    
    //6.
    string name2="András";

    list<Item>::iterator itr = 
    find_if(li.begin(),li.end(),
        [name2](const Item& a){return a.name == name2;});
    
    li.erase(itr);
    write(li,"Remove by name:");

    //7.
    int id2=5;

    itr=find_if(li.begin(),li.end(),
        [id2](const Item& a){return a.iid == id2;});

    li.erase(itr);
    write(li,"Remove by id:");

    return 0;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Something went wrong! \n";
    return 2;
}