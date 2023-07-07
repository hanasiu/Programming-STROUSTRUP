#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace std;

class Striped_rectangle : public Rectangle
{
public:
    Striped_rectangle(Point point, int w, int h)
        : Rectangle(point, w, h)
    {
    }
    void draw_lines() const;
};

void Striped_rectangle::draw_lines() const
{
    if (fill_color().visibility())
    {
        // Draw stripes
        fl_color(fill_color().as_int());

        // Draw filled rectangles with a smaller width to create the stripes
        for (int y = point(0).y; y < point(0).y + height(); y += 5)
        {
            fl_rectf(point(0).x, y, width(), 1);
        }
    }

    if (color().visibility())
    {
        // Draw outline
        fl_color(color().as_int());
        fl_rect(point(0).x, point(0).y, width(), height());
    }
}

void example(Simple_window &win)
{
    Striped_rectangle i(Point{200, 200}, 300, 200);
    i.set_color(Color::blue);
    i.set_fill_color(Color::green);
    i.move(100, 100);
    win.attach(i);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    // Create a window
    Simple_window win(Point{100, 100}, 800, 600, "My Window");

    example(win);

    return 0;
}
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex05_Striped_rectangle.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
