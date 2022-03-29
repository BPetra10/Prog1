#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

struct Record 
{
	std::string name;
	std::string address;
};

//Függvényobjektumok:

//sorbarendezés név szerint
/*struct Compare_by_name {
	bool operator()(const Record& a, const Record& b) const
	{ return a.name < b.name; } //std::string operator<
};

//sorbarendezés cím szerint
struct Compare_by_address {
	bool operator()(const Record& a, const Record& b) const
	{ return a.address < b.address; } //std::string operator<
};*/

int main(){

	std::vector<Record> records;
	std::string a, b;
	
	//q-val lehet kilépni ha a névnél címnél q van
	for ( std::string a, b; std::cin >> a >> b && ( a != "q" || b != "q"); )
	{
		Record first;
		first.name = a;
		first.address = b;
		records.push_back(first);
	}

	std::cout << "Before sort:\n";

	for (auto e : records)
		std::cout << e.name << " " << e.address << std::endl;

	//sorbarendezés név szerint
	//std::sort(records.begin(), records.end(), Compare_by_name());
	//lambda kifejezéssel:
	std::sort(records.begin(), records.end(),
		[](const Record& a, const Record& b){return a.name < b.name;});
	std::cout << "After sort by name:\n";

	for (auto e : records)
		std::cout << e.name << " " << e.address << std::endl;

	//sorbarendezés cím szerint
	//std::sort(records.begin(), records.end(), Compare_by_address());
	//lambda kifejezéssel:
	std::sort(records.begin(), records.end(),
		[](const Record& a, const Record& b){return a.address < b.address;});
	std::cout << "Before sort by address:\n";

	for (auto e : records)
		std::cout << e.name << " " << e.address << std::endl;

	return 0;
}