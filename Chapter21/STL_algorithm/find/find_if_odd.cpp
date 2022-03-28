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

bool odd(int x){return x % 2;} //igaz, ha a szám páratlan

int main(){

	std::vector<int> v;
	//keressük meg a páratlan számokat a v-ben.
	int a;
	//a-ba olvassuk be az adatokat:
	while (std::cin >> a) v.push_back(a); //beolvasunk értékeket
	
	if(v.size()==0)
	{
		std::cout << "Nincs a vektorban elem!\n";
	}
	else
	{
		//odd függvény átadása:
		auto p = find(v.begin(), v.end(), odd);
	
		if (p != v.end())
			std::cout << "Van páratlan szám a vektorban.\n";
		else
			std::cout << "Nincs páratlan szám a vektorban.\n";
	}
	
	/*for (auto e : v)
		std::cout << e << std::endl;*/

	return 0;
}
