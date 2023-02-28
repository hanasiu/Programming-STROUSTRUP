#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib; // our graphics facilities are in Graph_lib (defined in Graph.h)

void ex01(Simple_window &win)
{
    Rectangle r{Point{200, 200}, 100, 50};
    r.set_color(Color::blue);
    win.attach(r);
    win.set_label("Canvas #1-1");
    win.wait_for_button();

    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);
    win.attach(poly);
    win.set_label("Canvas #1-2");
    win.wait_for_button();
}

int main()
{
    Point top_left{500, 100}; // will be top left corner of window
    Simple_window win{top_left, 600, 400, "Canvas"};

    ex01(win);

    return 0;
}