#include<iostream>
#include<vector>

template<typename Iterator, typename T>
//accumulate T típussal tér vissza
T accumulate(Iterator first, Iterator last, T init){

	while (first != last){
		init = init + *first; //sorban lévő elemek összeadása
		++first;
	}

	return init;
}

int main()
{
	std::vector<double> v {1.1,2.2,3.3,4.4,5.5};
	std::cout<< accumulate(v.begin(),v.end(),0.0)<<std::endl;
	//kezdés, vég, inicializáció
}