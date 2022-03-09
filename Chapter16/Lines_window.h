#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title );
	//data:
	Open_polyline lines;

	bool wait_for_button();

private:
	// widgets:
    Button next_button; // add (next_x,next_y) to lines
    Button quit_button; // end program
    
    In_box next_x;
    In_box next_y;
    
    Out_box xy_out;
    
    Menu color_menu;
    Button color_menu_button;

    Menu style_menu;
    Button style_menu_button;

    //color changer:
    void change_color(Color c) { lines.set_color(c); }
    void hide_color_menu() { color_menu.hide(); color_menu_button.show(); }

    //style changer:
    void change_style(Line_style s){lines.set_style(s);}
    void hide_style_menu() {style_menu.hide(); style_menu_button.show(); }

    // actions invoked by callbacks:
    //color:
    void red_pressed() { change_color(Color::red); hide_color_menu(); }
    void blue_pressed() { change_color(Color::blue); hide_color_menu(); }
    void black_pressed() { change_color(Color::black); hide_color_menu(); }

    void color_menu_pressed() { color_menu_button.hide(); color_menu.show(); }

    //style:
    void dot_pressed() { change_style(Line_style::dot); hide_style_menu(); }
    void dash_pressed() { change_style(Line_style::dash); hide_style_menu(); }
    void solid_pressed() { change_style(Line_style::solid); hide_style_menu(); }

    void style_menu_pressed() { style_menu_button.hide(); style_menu.show(); }

    void next();
    void quit();

    // callback functions:
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_color_menu(Address, Address);
    static void cb_solid(Address,Address);
    static void cb_dash(Address,Address);
    static void cb_dot(Address,Address);
    static void cb_style_menu(Address, Address);
};
