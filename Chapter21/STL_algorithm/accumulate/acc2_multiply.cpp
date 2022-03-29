#include<iostream>
#include<vector>

template<typename Iterator, typename T, typename BinOp>
//BinOp az adott műveletet adja meg
T accumulate(Iterator first, Iterator last, T init, BinOp op){

	while (first != last){
		init = op(init,*first); 
		++first;
	}

	return init;
}
//függvény objektumként:
template<class T>
struct my_multiply
{
	T operator()(const T& a, const T& v) const {return a*v;}	
};

double multiply (double a, double v)
{
	return a * v;
}

int main()
{
	std::vector<double> v {1.1,2.2,3.3,4.4,5.5};
	//init 1, mivel szorzáskor 0 nem lehet a kezdőérték, mert 0 lenne az eredmény
	std::cout<< accumulate(v.begin(),v.end(),1.0, multiply)<<std::endl;
	//kezdés, vég, függvény
	//függvény objektummal:
	std::cout<< accumulate(v.begin(),v.end(),1.0, my_multiply<double>())<<std::endl;
}