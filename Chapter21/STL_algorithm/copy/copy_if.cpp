#include <iostream>
#include <vector>
#include <list>

//csak akkor fogunk másolni, amikor a predikátum teljesül
template<typename Iterator, typename Out, typename Pred>
//Out az a típus, amibe másolni fogunk
Out my_copy (Iterator first, Iterator last, Out res, Pred pred) //res: ahova másolunk
{
	while (first != last){
		if(pred(*first))
		{
			*res = *first;
			++res;
		}
		++first;
	}
	return res;
}

int main(){
	//listábol másolunk elemeket a vektorba
	std::vector<double> v(10);
	std::list<int> l = { 1, 2, 3, 4, 5 };

	if ( v.size() < l.size() )
	{
		std::cout << "Error, container too small!\n";
		return -1;
	}
	//intervallum megadás, hova másolunk át, milyen feltétellel
	my_copy(l.begin(), l.end(),
	v.begin(),[](int x)-> bool{return x > 3;});

	for (const auto& e : v)
		std::cout << e << " ";
	std::cout <<std::endl;
	
	return 0;
}