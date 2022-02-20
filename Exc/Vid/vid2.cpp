// g++ vid2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o vid2 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win {Point{100,100},600,400,"Graphics classes"};

	Line l (Point{400,200}, Point{300,300});
	win.attach(l);

	Lines lines = {
		Point{100,100}, {200,100},{150,50},{150,150}
	}; //A Point megjelölés elhagyható
	win.attach(lines);
	lines.add(Point{400,340},Point{450,250});
	lines.set_color(Color::red);

	Open_polyline opl ={
		{80,100}, {150,200},{250,250},{300,200}
	};
	opl.set_color(Color::blue);
	win.attach(opl);

	Closed_polyline poly; //using default constructor 
	poly.add(Point{500,100});
	poly.add(Point{500,250});
	poly.add(Point{600,200});
	poly.set_color(Color::green);
	win.attach(poly);

	win.wait_for_button();
}