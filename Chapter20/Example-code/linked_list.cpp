#include <iostream>

//elemhez valamilyen értéket
//és a megelőző, rákövetkező memória címet tároljuk
template<typename Elem>
struct Link 
{
	//konstruktor:
	Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0)
		:prev(p), succ(s), val(v) {}

	Link* prev;
	Link* succ;
	Elem val;
};

//lista:
template<typename Elem>
class my_list
{
public:
	//konstruktor
	my_list(): first(new Link<Elem>()), last(first) { }
	
	class iterator;

	iterator begin() { return iterator(first); }
	iterator end() { return iterator(last); }

	//további (nem definiált) függvények:
	iterator insert(iterator p, const Elem& v);
	iterator erase (iterator p);
	void push_back(const Elem& v);
	void push_front(const Elem& v); //=> ezt definiáltuk
	Elem& front() { return *first; };
	Elem& back();

	//link pointer első utolsó elemre
	Link<Elem>* first;
    Link<Elem>* last;
};

//iterátor osztály külső definiálása:
template<typename Elem>
class my_list<Elem>::iterator 
{
	
	Link<Elem>* curr; //aktuális elem címe

public:
	//konstruktor:
	iterator(Link<Elem>*p): curr{p}{}
	//műveletek:
	//léptetés előre, hátra, * => érték lekérdezés
	iterator& operator++() { curr = curr->succ; return *this; }
	iterator& operator--() { curr = curr->prev; return *this; }
	Elem& operator*() { return curr->val; }
	//összehasonlító operátorok:
	bool operator==(const iterator& b) const { return curr==b.curr; }
	bool operator!=(const iterator& b) const { return curr!=b.curr; }
};

template<class Elem>
void my_list<Elem>::push_front(const Elem& v)
{
	first = new Link<Elem>(v,0,first);
}

template<typename Iter>
Iter high (Iter first, Iter last)
{

	Iter high = first;
	for (Iter p = first; p != last; ++p)
		if (*high<*p) high = p;
	return high;

}

int main()
{
	my_list<int> lst;
	for (int x; std::cin >> x; )
		lst.push_front(x);

	my_list<int>::iterator p = high (lst.begin(), lst.end());

	std::cout << "The highest value was " << *p << '\n';

	return 0;
}