#include "Lines_window.h"

//buttons (next,quit,menus), fields (In_box, Out_box) constructor
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-150,0}, 70, 20, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{x_max()-310,0}, 50, 20, "next x:"}, 
    next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
    xy_out{Point{100,0}, 100, 20, "current (x,y):"},
    color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"},
    color_menu_button{Point{x_max()-80,30}, 80, 20, "color menu", cb_color_menu},
    style_menu{Point{x_max()-70,100},70,20,Menu::vertical,"style"},
    style_menu_button{Point{x_max()-80,100},80,20,"style menu",cb_style_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");

    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(color_menu_button);

    style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"dashed",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"dotted",cb_dot});
    attach(style_menu);
    style_menu.hide();
    attach(style_menu_button);

    attach(lines);
}

//callbacks to color changes:
void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_color_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).color_menu_pressed();
}

//callbacks to style changes:
void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_style_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).style_menu_pressed();
}

//quit and next button:
void Lines_window::quit()
{
    hide(); // curious FLTK idiom to delete window
}

/*
next point: 
reads a pair of coordinates, updates the Open_polyline, 
updates the position readout, and redraws the window
*/
void Lines_window::next()
{
    //Get integers from In_boxes, using get_int()
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    //Update current position readout: 
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    //put the output int Out_box:
    xy_out.put(ss.str()); //str() string format

    redraw();
}