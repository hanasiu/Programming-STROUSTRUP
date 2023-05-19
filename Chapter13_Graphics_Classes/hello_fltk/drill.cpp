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

void drill_06(Simple_window &win)
{
    Vector_ref<Rectangle> vr;
    
    for(int i = 0; i<16; ++i) {
        for(int j = 0; j<16; ++j) {
            vr.push_back(new Rectangle{Point{i*20, j*20}, 20, 20});
            vr[vr.size()-1].set_fill_color(Color{i*16+j});
            win.attach(vr[vr.size()-1]);
        }
    }

    Text t{Point{0, 340}, "color matrix"};
    t.set_color(Color::blue);

    win.attach(t);
    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_07(Simple_window &win)
{
    Circle c1 {Point{100,200},50};
    Circle c2{Point{150,200},100};
    Circle c3{Point{200,200},150};

    c1.set_color(Color::red);
    c2.set_color(Color::blue);
    c3.set_color(Color::green);

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    Point top_left{0, 0}; // will be top left corner of window
    Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};
    // g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp drill.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk

    drill_05(win);
    return 0;
}

// make
// ./hello_fltk
