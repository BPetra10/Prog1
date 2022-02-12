// g++ first.cpp ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp -o first `fltk-config --ldflags --use-images`

#include "../../GUI/Graph.h"
#include "../../GUI/Simple_window.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    int win_width = 600;
    int win_height = 400;
 
    Simple_window win {tl,win_width,win_height,"My window"};

    Rectangle r {Point{120,200},50,50};
    r.set_color(Color::blue);
    win.attach(r);

    Polygon poly;
    poly.add({Point{240,200}});
    poly.add({Point{240,250}});
    poly.add({Point{290,250}});
    poly.add({Point{290,200}});
    poly.set_color(Color::red);
    win.attach(poly);

    win.wait_for_button();
}