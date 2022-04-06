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

//6.
class Erease_by_name
{
	string name;
public:
	//konstruktor
	Erease_by_name(string nname): name{nname}{}
	//függvényhívó operátor (function call) túlterhelése, 
	//mely elvégzi az összehasonlítást.
	bool operator()(Item& x) const {return x.name==name;}
};

//7.
class Erease_by_id
{
	int id;
public:
	//konstruktor
	Erease_by_id(int iid): id{iid}{}
	//függvényhívó operátor (function call) túlterhelése, 
	//mely elvégzi az összehasonlítást.
	bool operator()(Item& x) const {return x.iid==id;}
};

int main()
{
    vector<Item> vi;
    string iname {"items.txt"};
    ifstream ist {iname};
    if (!ist) runtime_error("can't open input file "+ iname);

    for (Item it; ist >> it; ) vi.push_back(it);

    cout<<"Original vector:"<<"\n";
    for(auto& x : vi)
        cout << x;
    cout<<endl;

    //2.
    string a,b;

    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.name < b.name;});
    
	cout << "After sort by name:\n";
    for(auto& x : vi)
        cout<< x;
    cout<<endl;

    //3.
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.iid < b.iid;});

    cout << "After sort by iid:\n";
    for(auto& x : vi)
        cout<< x;
    cout<<endl;

    //4.
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.value > b.value;});

    cout << "After sort by value:\n";
    for(auto& x : vi)
        cout<< x;
    cout<<endl;

    //5.
    Item horse {"horse shoe",99,12.34};
    Item canon {"Canon S400",9988,499.95};
    vi.insert(vi.begin(), horse);
    vi.insert(vi.begin(), canon);
    
    cout << "After insert:\n";
     for(auto& x : vi)
        cout<< x;
    cout<<endl;

    //6.
    string name="Józsi";
    vi.erase(find_if(vi.begin(),vi.end(),Erease_by_name(name)));
    cout << "Remove by name:\n";
     for(auto& x : vi)
        cout<< x;
    cout<<endl;

    //7.
    int id=1;
    vi.erase(find_if(vi.begin(),vi.end(),Erease_by_id(id)));
    cout << "Remove by id:\n";
     for(auto& x : vi)
        cout<< x;
    cout<<endl;

    //8. Repeat the excercise with list:
    //1.
    list<Item> li;
    string iname2 {"items.txt"};
    ifstream ist2 {iname2};
    if (!ist) runtime_error("can't open input file "+ iname2);

    for (Item it; ist2 >> it; ) li.push_back(it);

    cout<<"Original list:"<<"\n";
    for(auto& x : li)
        cout << x;
    cout<<endl;

    //2.
    string a2,b2;
    li.sort([](const Item& a2, const Item& b2){return a2.name < b2.name;});
	cout << "After sort by name:\n";
    for(auto& x : li)
        cout<< x;
    cout<<endl;

    //3.
    li.sort([](const Item& a2, const Item& b2){return a2.iid < b2.iid;});
    cout << "After sort by iid:\n";
    for(auto& x : li)
        cout<< x;
    cout<<endl;

    //4.
    li.sort([](const Item& a2, const Item& b2){return a2.value < b2.value;});
    cout << "After sort by value:\n";
    for(auto& x : li)
        cout<< x;
    cout<<endl;

    //5.
    li.insert(li.begin(), horse);
    li.insert(li.begin(), canon);
    cout << "After insert:\n";
     for(auto& x : li)
        cout<< x;
    cout<<endl;

    //6.
    string name2="András";
    // Creating iterator to point to the element wich we want to delete
    list<Item>::iterator itr = find_if(li.begin(),li.end(),Erease_by_name(name2));
    li.erase(itr);
    cout << "Remove by name:\n";
     for(auto& x : li)
        cout<< x;
    cout<<endl;

    //7.
    int id2=5;
    itr=find_if(li.begin(),li.end(),Erease_by_id(id2));
    li.erase(itr);
    cout << "Remove by id:\n";
     for(auto& x : li)
        cout<< x;
    cout<<endl;

    return 0;
}