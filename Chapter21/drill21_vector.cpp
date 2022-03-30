#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct Item 
{
    string name;
    int iid;
    double value;
};

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

int main()
{
    vector<Item> vi;
    string iname {"items.txt"};
    ifstream ist {iname};
    if (!ist) runtime_error("can't open input file "+ iname);

    for (Item it; ist >> it; ) vi.push_back(it);

    cout<<"Original vector:"<<"\n";
    for(auto x : vi)
        cout<< x.name <<" "<<x.iid <<" "<< x.value <<"\n";
    cout<<endl;

    //2.
    string a,b;

    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.name < b.name;});
    
	cout << "After sort by name:\n";
    for(auto x : vi)
        cout<< x.name <<" "<<x.iid <<" "<< x.value <<"\n";
    cout<<endl;

    //3.
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.iid < b.iid;});

    cout << "After sort by iid:\n";
    for(auto x : vi)
        cout<< x.name <<" "<<x.iid <<" "<< x.value <<"\n";
    cout<<endl;

    //4.
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.value > b.value;});

    cout << "After sort by value:\n";
    for(auto x : vi)
        cout<< x.name <<" "<<x.iid <<" "<< x.value <<"\n";
    cout<<endl;

    //5.
    Item horse {"horse shoe",99,12.34};
    Item canon {"Canon S400",9988,499.95};
    vi.insert(vi.begin(), horse);
    vi.insert(vi.begin(), canon);
    
    cout << "After insert:\n";
     for(auto x : vi)
        cout<< x.name <<" "<<x.iid <<" "<< x.value <<"\n";
    cout<<endl;

    return 0;
}