#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main() {

	int m = 20;
	std::ostream& os = std::cout;
		auto Greater_print = [&os, m]<typename K>(K x) { if (x > m ) os << x << '\n'; };

	std::vector<int> v = { 10, 20, 30, 40, 50 };
	std::list<double> l = { 10.5, 20.5, 30.5, 40.5, 50.5 };

	std::for_each(v.begin(), v.end(), Greater_print);

	std::for_each(l.begin(), l.end(), Greater_print);

	return 0;
}
