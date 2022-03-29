#include <iostream>
#include <vector>
#include <list>

template<typename Iterator, typename Out>
//Out az a típus, amibe másolni fogunk
Out my_copy (Iterator first, Iterator last, Out res) //res: ahova másolunk
{
	while (first != last){
		*res = *first;
		++res;
		++first;
	}
	return res;
}

int main(){
	//listábol másolunk elemeket a vektorba
	std::vector<double> v(10);
	std::list<int> l = { 1, 2, 3, 4, 5 };

	if ( v.size() < l.size() ){
		std::cout << "Error, container too small!\n";
		return -1;
	}
	//intervallum megadás, és hogy hova másolunk át
	my_copy(l.begin(), l.end(), v.begin());

	for (const auto& e : v)
		std::cout << e << " ";
	std::cout <<std::endl;
	
	return 0;
}