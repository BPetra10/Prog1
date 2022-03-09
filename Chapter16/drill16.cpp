/*
    g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o drill16 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Lines_window.h"
#include "Graph.h"

int main()
try {
    Lines_window win {Point{100,100},600,400,"Lines"};
    return gui_main(); //call Fl::run();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}