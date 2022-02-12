// g++ sev.cpp ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp -o sev `fltk-config --ldflags --use-images`

#include "../../GUI/Graph.h"
#include "../../GUI/Simple_window.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    int win_width = 600;
    int win_height = 400;

    Simple_window win {tl,win_width,win_height,"My window"};

    Rectangle grass {Point{0,300},600,100};
    grass.set_fill_color(Color::green);
    win.attach(grass);

    Rectangle sky {Point{0,20},600,280};
    sky.set_fill_color(Color::cyan);
    win.attach(sky);

    Rectangle base {Point{120,200},100,100};
    base.set_fill_color(Color::yellow);
    win.attach(base);

    Polygon roof;
    roof.add(Point{120,200});
    roof.add(Point{170,130});
    roof.add(Point{220,200});
    roof.set_fill_color(Color::red);
    win.attach(roof);

    Polygon chimney;
    chimney.add(Point{200,170});
    chimney.add(Point{200,160});
    chimney.add(Point{219,160});
    chimney.add(Point{219,200});
    chimney.set_fill_color(Color::red);
    win.attach(chimney);

    Function dust {sin,0,9.5,Point{170,158},800,5,5};
    win.attach(dust);

    Function dust_1 {cos,0,9,Point{165,155},800,5,5};
    win.attach(dust_1);

    Rectangle door {Point{192,248},25,50};
    door.set_fill_color(Color::black);
    win.attach(door);

    Circle d_handle {Point{200,275},4};
    d_handle.set_fill_color(Color::green);
    win.attach(d_handle);

    Rectangle window1 {Point{130,220},25,25};
    window1.set_fill_color(Color::white);
    win.attach(window1);

    Rectangle window2 {Point{155,220},25,25};
    window2.set_fill_color(Color::white);
    win.attach(window2);

    Rectangle sidewalk {Point{192,300},25,100};
    sidewalk.set_fill_color(Color::white);
    win.attach(sidewalk);

    Polygon fence;
    fence.add(Point{220,300});
    fence.add(Point{220,260});
    fence.add(Point{225,255});
    fence.add(Point{230,260});
    fence.add(Point{230,300});
    fence.set_fill_color(Color::white);
    win.attach(fence);

    Polygon fence1;
    fence1.add(Point{230,300});
    fence1.add(Point{230,260});
    fence1.add(Point{235,255});
    fence1.add(Point{240,260});
    fence1.add(Point{240,300});
    fence1.set_fill_color(Color::white);
    win.attach(fence1);

    Polygon fence2;
    fence2.add(Point{240,300});
    fence2.add(Point{240,260});
    fence2.add(Point{245,255});
    fence2.add(Point{250,260});
    fence2.add(Point{250,300});
    fence2.set_fill_color(Color::white);
    win.attach(fence2);

    Polygon fence3;
    fence3.add(Point{250,300});
    fence3.add(Point{250,260});
    fence3.add(Point{255,255});
    fence3.add(Point{260,260});
    fence3.add(Point{260,300});
    fence3.set_fill_color(Color::white);
    win.attach(fence3);

    win.wait_for_button();
}