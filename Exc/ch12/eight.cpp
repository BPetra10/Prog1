// g++ eight.cpp ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp -o eight `fltk-config --ldflags --use-images`

#include "../../GUI/Graph.h"
#include "../../GUI/Simple_window.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    int win_width = 600;
    int win_height = 400;
 
    Simple_window win {tl,win_width,win_height,"My window"};

    // Olympic rings
    int r = 70;
    int distance = r*2+20; //d+20
    Circle c1 {Point{100,100},r};
    c1.set_color(Color::blue);
    c1.set_style(Line_style(Line_style::solid,10));
    win.attach(c1);

    Circle c2 {Point{180,170},r};
    c2.set_color(Color::yellow);
    c2.set_style(Line_style(Line_style::solid,10));
    win.attach(c2);

    Circle c3 {Point{100+distance,100},r};
    c3.set_style(Line_style(Line_style::solid,10));
    win.attach(c3);

    Circle c4 {Point{180+distance,170},r};
    c4.set_color(Color::green);
    c4.set_style(Line_style(Line_style::solid,10));
    win.attach(c4);

    Circle c5 {Point{100+distance*2,100},r};
    c5.set_color(Color::red);
    c5.set_style(Line_style(Line_style::solid,10));
    win.attach(c5);

    win.wait_for_button();
}