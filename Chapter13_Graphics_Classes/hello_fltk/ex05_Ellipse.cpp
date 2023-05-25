#include "Simple_window.h"
#include "Graph.h"


Point n (const Ellipse& e)
{
    int x = e.center().x;
    int y = e.center().y - e.minor();

    return Point{x, y};
}

Point s (const Ellipse& e)
{
    int x = e.center().x;
    int y = e.center().y + e.minor();

    return Point{x, y};
}

Point e (const Ellipse& e)
{
    int x = e.center().x + e.major();
    int y = e.center().y;

    return Point{x, y};
}

Point w (const Ellipse& e)
{
    int x = e.center().x - e.major();
    int y = e.center().y;

    return Point{x, y};
}


Point nw (const Ellipse& e)
{
    int x = e.center().x - e.major();
    int y = e.center().y - e.minor();

    return Point{x, y};
}

Point ne (const Ellipse& e)
{
    int x = e.center().x + e.major();
    int y = e.center().y - e.minor();

    return Point{x, y};
}

Point sw (const Ellipse& e)
{
    int x = e.center().x - e.major();
    int y = e.center().y + e.minor();

    return Point{x, y};
}

Point se (const Ellipse& e)
{
    int x = e.center().x + e.major();
    int y = e.center().y - e.minor();

    return Point{x, y};
}

// Point center(const Ellipse& e)
// {
    //library Ellipse has center() function
// }

void example(Simple_window& win) {
    Ellipse ellipse{Point{400,300},100,200};
    win.attach(ellipse);
    Text N {Point{n(ellipse)}, "n: " + to_string(n(ellipse).x) + ", " + to_string(n(ellipse).y)};
    win.attach(N);
    Text S {Point{s(ellipse)}, "s: " + to_string(s(ellipse).x) + ", " + to_string(s(ellipse).y)};
    win.attach(S);
    Text E {Point{e(ellipse)}, "e: " + to_string(e(ellipse).x) + ", " + to_string(e(ellipse).y)};
    win.attach(E);
    Text W {Point{w(ellipse)}, "w: " + to_string(w(ellipse).x) + ", " + to_string(w(ellipse).y)};
    win.attach(W);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main() {
    Simple_window win(Point{ 100, 100 }, 800, 600, "My Window");

    example(win);
}

//g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex05_Ellipse.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
