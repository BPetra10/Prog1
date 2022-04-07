#include<iostream>
#include<string>
#include <stdexcept>
#include <map>
#include<numeric>

using namespace std;

//5.
void read(map<string,int>& map)
{
    string text;
    int number;
    cin>>text>>number;
    map.insert(pair<string,int>(text,number));
}

template <typename First, typename Second>
void write(const map<First,Second>& map)
{
    cout<<"Map pairs:\n";
    for(const auto& p : map)
        cout<<p.first<<" "<<p.second <<'\n';
}

int main()
try{
    //1.
    map<string,int> msi;
    
    //2.
    msi["lecture"]=21;
    msi["time"]=26;
    msi["stuff"]=30;
    msi["other"]=33;
    msi["game"]=25;
    msi["late"]=29;
    msi["map"]=50;
    msi["tee"]=72;
    
    //3.
    write(msi);
    
    //4.
    msi.erase(msi.begin(),msi.end());
    cout<<"Erease ok! \n";
    write(msi);

    //6.
    cout<<"Give 10 string,int pair for map:\n";
    while(msi.size()!=10)
    {
        read(msi);
    }

    //7.
    write(msi);

    //8.
    int sum = accumulate(msi.begin(),msi.end(),0,
     [](auto prev_sum, auto &msi_entry){return prev_sum+msi_entry.second;});
    cout<<"Map ints sum: "<<sum<<"\n";

    //9.
    map<int,string> mis;

    //10.
    for(auto& mapentry: msi)
        mis[mapentry.second] = mapentry.first;
    
    //11.
    write(mis);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Something went wrong! \n";
    return 2;
}