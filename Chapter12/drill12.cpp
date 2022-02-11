/*
    g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    int win_width = 600;
    int win_height = 400;
 
    Simple_window win {tl,win_width,win_height,"My window"};

    //Axis
    Axis x {Axis::x,Point{20,300},250,10,"x axis"};
    Axis y {Axis::y,Point{20,300},250,10,"y axis"};
    x.label.set_color(Color::dark_red);
    y.label.set_color(Color::dark_red);
    win.attach(x);
    win.attach(y);

    win.set_label("My window label change");

    //Sine
    Function sine {sin,0,100,Point{20,150},1000,20,20};
    sine.set_color(Color::dark_blue);
    win.attach(sine);

    //Poly
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::dark_green);
    poly.set_style(Line_style(Line_style::dot,4));
    win.attach(poly);

    //Rectangle
    Rectangle rec {Point{180,180},100,50};
    rec.set_color(Color::dark_magenta);
    rec.set_fill_color(Color::magenta);
    win.attach(rec);

    //5 point poly
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    poly_rect.set_color(Color::yellow);
    poly_rect.set_fill_color(Color::dark_cyan);
    poly_rect.set_style(Line_style(Line_style::dashdotdot,3));
    win.attach(poly_rect);

    //Text 
    Text t {Point{300,50},"Hello graphical world!"};
    t.set_font(Font::courier_italic);
    t.set_font_size(20);
    win.attach(t);

    //IMG
    Image img {Point(390,190),"typo.jpg"};
    win.attach(img);

    //Other shapes
    Circle cir {Point{100,230},50};
    Ellipse el {Point{100,230},75,25};
    el.set_color(Color::red);
    Mark m {Point{100,230},'x'};
    win.attach(cir);
    win.attach(el);
    win.attach(m);

    win.wait_for_button();
}
