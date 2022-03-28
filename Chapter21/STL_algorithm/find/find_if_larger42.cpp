#include <iostream>
#include <vector>

template<typename Iterator, typename Predicate>
//Predikátumot adunk át, melyet kiértékelünk, hogy I vagy H
//find() iterátort ad vissza
Iterator find (Iterator first, Iterator last, Predicate pred){

	//ha a végére érünk, vagy a predikátum igaz lesz:
	while (first != last && !pred(*first)) ++first;

	return first; 
}

bool larger_than_42(int x){return x > 42;} //igaz, ha a szám>42

int main(){

	std::vector<int> v;
	int a;
	//a-ba olvassuk be az adatokat:
	while (std::cin >> a) v.push_back(a); //beolvasunk értékeket
	
	if(v.size()==0)
	{
		std::cout << "Nincs a vektorban elem!\n";
	}
	else
	{
		//larger_than_42 függvény átadása:
		auto p = find(v.begin(), v.end(), larger_than_42);
	
		if (p != v.end())
			std::cout << "Van nagyobb szám, mint 42 a vektorban.\n";
		else
			std::cout << "Nincs nagyobb szám, mint 42 a vektorban.\n";
	}
	
	/*for (auto e : v)
		std::cout << e << std::endl;*/

	return 0;
}
