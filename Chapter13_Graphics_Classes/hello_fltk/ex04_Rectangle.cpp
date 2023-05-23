#include "Simple_window.h"
#include "Graph.h"


Point n (const Rectangle& r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y;

    return Point{x, y};
}

Point s (const Rectangle& r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point e (const Rectangle& r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

Point w (const Rectangle& r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

Point nw (const Rectangle& r)
{
    int x = r.point(0).x;
    int y = r.point(0).y;
    return Point{x, y};
}

Point ne (const Rectangle& r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y;
    return Point{x, y};
}

Point sw (const Rectangle& r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point se (const Rectangle& r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point center(const Rectangle& r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

void example(Simple_window& win) {
    Rectangle example{Point{150,100}, 200, 100};
    win.attach(example);
    Text NorthWest {Point{nw(example)}, "north west point is " + to_string(nw(example).x) + ", " + to_string(nw(example).y)};
    win.attach(NorthWest);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main() {
    Simple_window win(Point{ 100, 100 }, 800, 600, "My Window");

    example(win);
}

//g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex04_Rectangle.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
