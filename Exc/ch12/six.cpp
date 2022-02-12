// g++ six.cpp ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp -o six `fltk-config --ldflags --use-images`

#include "../../GUI/Graph.h"
#include "../../GUI/Simple_window.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    //Too large window:
    int win_width = 8800;
    int win_height =8800;
    //Set the size of the window to the maximum screen size +malfunction window
 
    Simple_window win {tl,win_width,win_height,"My window"};

    Rectangle r {Point{80,90},100,30};
    win.attach(r); //the object will be cut off, or you will not see at all
    win.wait_for_button();
}