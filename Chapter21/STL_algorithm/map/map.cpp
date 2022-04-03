//használat: g++ map.cpp -o map
// ./map <tesztszoveg.txt

#include <iostream>
#include <map>
//A map implementációja piros fekete fa.
int main(){
	//egy szövegben a szó hányszor fordul elő:
	std::map<std::string, int> words;

	for (std::string s; std::cin>>s; )
		++words[s];

	for (const auto& p : words)
		std::cout << p.first << ": " << p.second << std::endl;

	std::cout<<" 'the' word in this input: ";
	std::cout<<words["the"]<<std::endl;

	return 0;
}
