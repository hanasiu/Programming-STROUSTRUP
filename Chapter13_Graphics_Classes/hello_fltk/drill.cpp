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

    Mark m1{Point{100,200}, 'x'};
    Mark m2{Point{150,200}, 'y'};
    Mark m3{Point{200,200}, 'z'};

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);
    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_08(Simple_window &win)
{
    Ellipse e1{Point{200,200},50,50};
    Ellipse e2{Point{200,200},100,50};
    Ellipse e3{Point{200,200},100,150};

    e1.set_color(Color::red);
    e2.set_color(Color::blue);
    e3.set_color(Color::green);

    win.attach(e1);
    win.attach(e2);
    win.attach(e3);
    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_09(Simple_window &win)
{
    Marked_polyline mpl{"1234"};
    mpl.add(Point{100,100});
    mpl.add(Point{150,200});
    mpl.add(Point{250,250});
    mpl.add(Point{300,200});

    win.attach(mpl);

    Marked_polyline mpl2{"5678", {{300,300},{350,400},{450,450},{500,400}}};
    win.attach(mpl2);

    Marks pp{"x",{{500,500},{550,600},{750,750},{800,700}}};
    win.attach(pp);
    win.set_label("Canvas #1");
    win.wait_for_button();
}

void drill_10(Simple_window &win)
{
    Image rita{Point{0,0}, "rita.jpg"};
    Image path{Point{0,0}, "rita_path.gif"};
    path.set_mask(Point{50,250}, 600,400);

    win.attach(path);
    win.attach(rita);
    win.set_label("Canvas #1");
    win.wait_for_button();
}



int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    Point top_left{0, 0}; // will be top left corner of window
    Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};
    //g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp drill.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
    drill_10(win);
    return 0;
}

// make
// ./hello_fltk
