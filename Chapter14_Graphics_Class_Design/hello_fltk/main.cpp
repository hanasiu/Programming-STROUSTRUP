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
        {100, 100}, {150, 200}, {250, 250}, {300, 200}};
    win.attach(opl);

    Closed_polyline cpl = {
        {300, 100}, {350, 200}, {450, 250}, {500, 200}};
    win.attach(cpl);

    Polygon poly = {
        {500, 100}, {550, 200}, {650, 250}, {700, 200}};
    win.attach(poly);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_05(Simple_window &win)
{
    // Draw an arc of points
    fl_begin_points();
    fl_arc(100.0, 100.0, 50.0, 0.0, 180.0);
    fl_end_points();

    //win.attach();

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    Point top_left{0, 0}; // will be top left corner of window
    Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};
    // g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp main.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk

    drill_05(win);
    return 0;
}

// make
// ./hello_fltk
