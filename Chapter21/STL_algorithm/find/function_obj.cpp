/*
mit tegyünk, ha nem csak 42-re akarjuk megnézni, 
hogy van-e nagyobb számunk?
Ahhoz, hogy tetszőleges számra működjön a larger, 
függvényobjektumot használunk, melynek paramétere lesz
a szám.

Tehát generikusan akarjuk keresni, hogy az adott szám nagyobb-e
mint bármelyik érték a vektorban.
*/

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

class Larger_than
{
	int v;
public:
	//konstruktor
	Larger_than(int vv): v{vv}{}
	//függvényhívó operátor (function call) túlterhelése, 
	//mely elvégzi az összehasonlítást.
	bool operator()(int x) const {return x> v;}
};
int main(){

	std::vector<int> v;
	int a, x=42;
	//a-ba olvassuk be az adatokat:
	while (std::cin >> a) v.push_back(a); //beolvasunk értékeket
	
	if(v.size()==0)
	{
		std::cout << "Nincs a vektorban elem!\n";
	}
	else
	{
		//Larger_than függvény átadása:
		auto p = find(v.begin(), v.end(), Larger_than(x));
	
		if (p != v.end())
			std::cout << "Van nagyobb szám, mint "<<x<<" a vektorban.\n";
		else
			std::cout << "Nincs nagyobb szám, mint "<<x<<" a vektorban.\n";
	}
	
	/*for (auto e : v)
		std::cout << e << std::endl;*/

	return 0;
}
