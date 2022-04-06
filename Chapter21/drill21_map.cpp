#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
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
    for(const auto& p : msi)
        cout<<p.first<<" "<<p.second <<'\n';
    //4.
    msi.erase(msi.begin(),msi.end());
    cout<<"Erease ok! \n";
    for(const auto& p : msi)
        cout<<p.first<<" "<<p.second <<'\n';
    
    
}