#include <iostream>
#include <vector>

template<typename Iterator, typename T>
//T: típusparamétere a keresett változónak
//find() iterátort ad vissza
Iterator find (Iterator first, Iterator last, const T& val){

	//ha a végére érünk, vagy megtaláljuk az értéket:
	while (first != last && *first != val) ++first;

	return first; 
	//ha nincs keresett érték, akkor end()-el tér vissza
	//máskülönben a keresett elemre mutató iterátort.
}

int main(){

	std::vector<int> v;
	int a, x = 10; //keressük az x értéket, ami 10.
	//a-ba olvassuk be az adatokat:
	while (std::cin >> a) v.push_back(a); //beolvasunk értékeket
	
	if(v.size()==0)
	{
		std::cout << "Nincs a vektorban elem!\n";
	}
	else
	{
		auto p = find(v.begin(), v.end(), x);
	
		//ha a p-ben nincs benne az x, akkor a p end()-del tér vissza
		if (p != v.end())
			std::cout << "Megtaláltuk a keresett értéket:"<<x<<"\n";
		else
			std::cout << "Nem találtuk meg a keresett értéket:"<<x<<"\n";
	}
	
	/*for (auto e : v)
		std::cout << e << std::endl;*/

	return 0;
}
