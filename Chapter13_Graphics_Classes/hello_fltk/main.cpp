#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib; // our graphics facilities are in Graph_lib (defined in Graph.h)

void drill_01(Simple_window &win)
{
    // Lines x;
    // x.add(Point{100,100}, Point{200,100});
    // x.add(Point{150,50}, Point{150,150});

    int x_size = win.x_max();
    int y_size = win.y_max();
    int x_grid = 80;
    int y_grid = 40;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);
    grid.set_style(Line_style{Line_style::dash, 1});

    win.attach(grid);

    win.set_label("Canvas #1");
    win.wait_for_button();
}



void drill_02(Simple_window &win)
{
    Lines x = {
        {{100, 100}, {200, 100}},
        {{150, 50}, {150, 150}}};
    win.attach(x);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_03(Simple_window &win)
{
    Lines horizontal = {
        {{100, 100}, {200, 100}}};
    Lines vertical = {
        {{150, 50}, {150, 150}}};
    horizontal.set_color(Color::red);
    vertical.set_color(Color::green);
    win.attach(horizontal);
    win.attach(vertical);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_04(Simple_window &win)
{
    Open_polyline opl = {
        {100, 100}, {150, 200}, {250, 250}, {300, 200}
    };
    win.attach(opl);

    Closed_polyline cpl = {
        {300, 100}, {350, 200}, {450, 250}, {500, 200}
    };
    win.attach(cpl);

    Polygon poly = {
        {500, 100}, {550, 200}, {650, 250}, {700, 200}
    };
    win.attach(poly);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_05(Simple_window &win)
{
    Rectangle rect00{Point{150,100},200,100};
    Rectangle rect11{Point{50,50}, Point{250,150}};
    Rectangle rect12{Point{50,150},Point{250,250}};
    Rectangle rect21{Point{250,50},200,100};
    Rectangle rect22{Point{250,150},200,100};
    
    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    rect11.move(400,0);
    rect11.set_fill_color(Color::white);

    rect00.set_color(Color::invisible);
    rect11.set_color(Color::invisible);
    rect12.set_color(Color::invisible);
    rect21.set_color(Color::invisible);
    rect22.set_color(Color::invisible);

    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);
    win.attach(rect22);

    win.put_on_top(rect00);


    win.set_label("Canvas #1");
    win.wait_for_button();
}


int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    Point top_left{0, 0}; // will be top left corner of window
    Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};
    // g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp main.cpp `fltk-config --ldflags --use-images` -o hello_fltk && ./hello_fltk

    drill_05(win);
    return 0;
}

// make
// ./hello_fltk
