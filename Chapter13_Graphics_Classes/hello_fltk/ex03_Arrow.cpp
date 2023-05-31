#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Arrow : Shape {
    Arrow(Point tail, Point head);
    void draw_lines() const;

private:
    Point head;
    Point tail;
};

Arrow::Arrow(Point tail, Point head)
    : head(head), tail(tail)
{
}

void Arrow::draw_lines() const {
    fl_line(tail.x, tail.y, head.x, head.y);

    // Calculate the direction vector of the arrow
    double dx = head.x - tail.x;
    double dy = head.y - tail.y;
    double angle = atan2(dy, dx);

    // Calculate the arrowhead points
    double arrow_size = 10.0;
    double arrow_angle = M_PI / 6.0;  // 30 degrees
    double angle1 = angle + arrow_angle;
    double angle2 = angle - arrow_angle;
    int x1 = head.x - arrow_size * cos(angle1);
    int y1 = head.y - arrow_size * sin(angle1);
    int x2 = head.x - arrow_size * cos(angle2);
    int y2 = head.y - arrow_size * sin(angle2);

    fl_line(head.x, head.y, x1, y1);
    fl_line(head.x, head.y, x2, y2);
}

//for ex_06
// void example(Simple_window& win) {
//     Arrow a(Point{ 400, 400 }, Point{ 500, 500 });
//     a.set_color(Color::red);
//     Arrow b(Point{ 400, 400 }, Point{ 300, 300 });
//     b.set_color(Color::green);
//     Arrow c(Point{ 400, 400 }, Point{ 500, 300 });
//     c.set_color(Color::blue);
//     Arrow d(Point{ 400, 400 }, Point{ 300, 500 });
//     d.set_color(Color::yellow);

//     // Attach the arrow to the window
//     win.attach(a);
//     win.attach(b);
//     win.attach(c);
//     win.attach(d);

//     win.set_label("Canvas #1");
//     win.wait_for_button();
// }

//for ex06..
// int main() {
//     Simple_window win(Point{ 100, 100 }, 800, 600, "My Window");

//     example(win);

//     return 0;
// }



// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex03_Arrow.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk

