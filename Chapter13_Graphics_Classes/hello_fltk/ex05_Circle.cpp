#include "Simple_window.h"
#include "Graph.h"


Point n (const Circle& c)
{
    int x = c.center().x;
    int y = c.center().y - c.radius();

    return Point{x, y};
}

Point s (const Circle& c)
{
    int x = c.center().x;
    int y = c.center().y + c.radius();

    return Point{x, y};
}

Point e (const Circle& c)
{
    int x = c.center().x + c.radius();
    int y = c.center().y;

    return Point{x, y};
}

Point w (const Circle& c)
{
    int x = c.center().x - c.radius();
    int y = c.center().y;

    return Point{x, y};
}

Point nw (const Circle& c)
{
    int x = c.center().x - c.radius();
    int y = c.center().y - c.radius();

    return Point{x, y};
}

Point ne (const Circle& c)
{
    int x = c.center().x + c.radius();
    int y = c.center().y - c.radius();

    return Point{x, y};
}

Point sw (const Circle& c)
{
    int x = c.center().x - c.radius();
    int y = c.center().y + c.radius();

    return Point{x, y};
}

Point se (const Circle& c)
{
    int x = c.center().x + c.radius();
    int y = c.center().y + c.radius();

    return Point{x, y};
}

// Point center(const Rectangle& r)
// {
    //library Circle has center() function
// }

void example(Simple_window& win) {
    Circle circle{Point{400, 200}, 150};
    win.attach(circle);
    Text NW {Point{nw(circle)}, "nw: " + to_string(nw(circle).x) + ", " + to_string(nw(circle).y)};
    win.attach(NW);
    Text N {Point{n(circle)}, "n: " + to_string(n(circle).x) + ", " + to_string(n(circle).y)};
    win.attach(N);
    Text NE {Point{ne(circle)}, "ne: " + to_string(ne(circle).x) + ", " + to_string(ne(circle).y)};
    win.attach(NE);
    Text W {Point{w(circle)}, "w: " + to_string(w(circle).x) + ", " + to_string(w(circle).y)};
    win.attach(W);
    Text CENTER {circle.center(), "c: " + to_string(circle.center().x) + ", " + to_string(circle.center().y)};
    win.attach(CENTER);
    Text E {Point{e(circle)}, "e: " + to_string(e(circle).x) + ", " + to_string(e(circle).y)};
    win.attach(E);
    Text SW {Point{sw(circle)}, "sw: " + to_string(sw(circle).x) + ", " + to_string(sw(circle).y)};
    win.attach(SW);
    Text S {Point{s(circle)}, "s: " + to_string(s(circle).x) + ", " + to_string(s(circle).y)};
    win.attach(S);
    Text SE {Point{se(circle)}, "se: " + to_string(se(circle).x) + ", " + to_string(se(circle).y)};
    win.attach(SE);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main() {
    Simple_window win(Point{ 100, 100 }, 800, 600, "My Window");

    example(win);
}

//g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex05_Circle.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
