#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace std;

class Striped_circle : public Circle
{
public:
    Striped_circle(Point center, int radius)
        : Circle(center, radius)
    {
    }

    void draw_lines() const;
};

void Striped_circle::draw_lines() const
{
        if (color().visibility()) {
        // Draw outline
        fl_color(color().as_int());
        fl_arc(point(0).x, point(0).y, radius() + radius(), radius() + radius(), 0, 360);

        // Draw stripes
        fl_color(fill_color().as_int());

        for (int angle = 0; angle < 360; angle += 7) {
            double radians = angle * M_PI / 180.0;
            int x = center().x + radius() * cos(radians);
            int y = center().y + radius() * sin(radians);
            fl_line(center().x, center().y, x, y);
        }
    }
}

void example(Simple_window &win)
{
    Striped_circle i(Point{200, 200}, 100);
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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex06_Striped_circle.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
