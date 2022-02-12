// g++ sec.cpp ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp -o sec `fltk-config --ldflags --use-images`

#include "../../GUI/Graph.h"
#include "../../GUI/Simple_window.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    int win_width = 600;
    int win_height = 400;
 
    Simple_window win {tl,win_width,win_height,"My window"};

    Rectangle r {Point{120,200},100,30};
    win.attach(r);

    Text t {Point{145,220},"Howdy!"};
    win.attach(t);

    win.wait_for_button();
}