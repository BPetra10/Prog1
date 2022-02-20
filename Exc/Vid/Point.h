#ifndef POINT_GUARD //Ne include-oljunk be többször egy headert
#define POINT_GUARD //Ha nincs definiálva, definiáljuk

namespace Graph_lib {

struct Point {
	int x, y;
	Point(): x(0), y(0) { } //x,y kinullázó alap konstruktor
	Point(int xx, int yy): x(xx), y(yy) { } //két paraméteres konstruktor
};

//inline: vezérlés folytatólagos lesz, nem ugrásos a vezérlés
//Két pont megegyezik-e:
inline bool operator==(Point a, Point b)
	{ return a.x==b.x && a.y==b.y; }
//Két pont nem egyezik meg:
inline bool operator!=(Point a, Point b)
	{ return !(a==b); }
}

#endif
