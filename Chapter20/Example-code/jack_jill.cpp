#include <iostream>
#include <vector>

//memóriafoglalás, feltöltés, visszaadjuk az array-t
double* get_from_jack(int* count)
{
	double* jack_array = new double[6];
	for (int i = 0; i < 6; i++)
		jack_array[i] = i*3;

	*count = 6; //6 elemű tömb
	return jack_array; //heapből visszaadott double tömb első elemére mutat
}

//double vektor pointer:
std::vector<double>* get_from_jill()
{
	std::vector<double>* jill_vector = new std::vector<double>;

	*jill_vector = {100,200,300,400,100,150};

	return jill_vector;
}

//legnagyobb elem megkeresése:
/*double* high(double* first, double* last)
{
	double h = -1;
	double* high;
	
	for (double* p = first; p!=last; ++p)
		if (h<*p) { high = p; h = *p; }
	
	return high;
}*/

//generikus high()
template<typename Iterator>
Iterator high(Iterator f, Iterator l)
{
	Iterator high = f;
	for (Iterator p = f; p != l; ++p)
		if(*high < *p) high = p;
	return high;
}

int main(){

	//Jack
	int jack_count = 0;

	double* jack_data = get_from_jack(&jack_count);

	std::cout << "Jack data:" << std::endl;
	for (int i = 0; i < jack_count; i++)
		std::cout << jack_data[i] << std::endl;

	//Jill:
	std::vector<double>* jill_data = get_from_jill();

	std::cout << "Jill data:" << std::endl;
	for (auto v: *jill_data)
		std::cout << v << std::endl;		

	//legnagyobb elem kiíratása:
	double h = -1;

	//jack:
	double* jack_high;
	double* jill_high;
	for (int i = 0; i < jack_count; i++)
		if (h<jack_data[i]) {
			jack_high = &jack_data[i];
			h = jack_data[i];
		}

	//jill:
	h = -1;
	for (int i = 0; i < jill_data->size(); i++)
		if (h<(*jill_data)[i]){
			jill_high = &(*jill_data)[i];
			h = (*jill_data)[i];
		}

	std::cout << "Jill's max: " << *jill_high << "\nJack's max: " << *jack_high << std::endl;

	//Referencia használat jill:
	std::vector<double>& v = *jill_data;
	for (int i = 0; i < v.size(); i++)
		if (h < v[i]){
			jill_high = &v[i];
			h = v[i];
		}

	std::cout << "Reference!\nJill's max: " << *jill_high << "\nJack's max: " << *jack_high << std::endl;

	//függvénnyel keresés:
	jack_high = high(jack_data, jack_data+jack_count);
	jill_high = high(&v[0], &v[0]+v.size());

	std::cout << "Function!\nJill's max: " << *jill_high << "\nJack's max: " << *jack_high << std::endl;

	//középső elem címe:
	double* jack_middle = jack_data+jack_count/2;
	//első, második felében lévő legnagyobb érték keresése:
	double* jack_high_first_half = high(jack_data, jack_middle);
	double* jack_high_second_half = high(jack_middle, jack_data+jack_count);

	double* jill_middle = &v[0]+v.size()/2;
	double* jill_high_first_half = high(&v[0], jill_middle);
	double* jill_high_second_half = high(jill_middle, &v[0]+v.size());

	std::cout << "Half!\nJill's max (first): " << *jill_high_first_half 
		<< "\nJill's max (second): " << *jill_high_second_half 
		<< "\nJack's max (first): " << *jack_high_first_half
		<< "\nJack's max (second): " << *jack_high_second_half << std::endl;

	delete[] jack_data;
	delete jill_data;

	return 0;
}