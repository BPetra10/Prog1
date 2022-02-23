/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100},xmax,ymax,"My window"};

    //grid size
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
	grid.add(Point{x,0},Point{x,y_size});//vertical
	for (int y = y_grid; y<y_size; y+=y_grid)
	grid.add(Point{0,y},Point{x_size,y});//horizontal
	win.attach(grid);

	int eltol_X=0;
	int eltol_Y=0;

	//diagonal squares
	Vector_ref<Rectangle> rect;
	for(int i=0; i<8; ++i)
	{
		rect.push_back(new Rectangle{Point{eltol_X,eltol_Y},100,100}); 
		eltol_X+=100;
		eltol_Y+=100;
	}
	for(int i=0; i<8; ++i)
	{
		rect[i].set_color(Color::red);
		rect[i].set_fill_color(Color::red);
		rect[i].set_style(Line_style(Line_style::solid,4));
		win.attach(rect[i]);
	}

	Image kep {Point{0,200},"wifi.jpg"};
	win.attach(kep);

	Image kep1 {Point{300,0},"wifi.jpg"};
	win.attach(kep1);
	
	Image kep2 {Point{0,600},"wifi.jpg"};
	win.attach(kep2);

	Image kep3 {Point{0,0},"ana.jpg"};
	kep3.set_mask(Point{80,60},100,100);
	win.attach(kep3);

	int previousX = 0;
	int previousY = 0;
	int randomX = 0;
	int randomY = 0;
	
	while(true)
	{
		randomX = (rand() % 7 + 1) * 100;
		randomY = (rand() % 7 + 1) * 100;
		win.wait_for_button();
		kep3.move(randomX-previousX,randomY-previousY);
		previousX = randomX;
		previousY = randomY;
	}

    win.wait_for_button();
}
