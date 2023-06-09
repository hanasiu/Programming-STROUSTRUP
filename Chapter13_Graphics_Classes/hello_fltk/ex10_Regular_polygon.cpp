#include "Simple_window.h"
#include "Graph.h"

struct Regular_polygon : Shape//center, sides, distance
{
    Regular_polygon(Point xy, int d, int s);
    void draw_lines() const;

    int distance() const { return d; }
    int side() const { return s; }

private:
    int d;
    int s;
};

Regular_polygon::Regular_polygon(Point xy, int dd, int ss) : d(dd), s(ss)
{
    if (d <= 0)
        throw std::runtime_error("Invalid box size");
    if (s <= 2)
        throw std::runtime_error("Invalid number of sides");
    add(xy);
}

// Box::Box(Point x, Point y) : w(y.x - x.x), h(y.y - x.y)
// {
//     if (h <= 0 || w <= 0)
//         throw std::runtime_error("Invalid box size");
//     add(x);
// }

void Regular_polygon::draw_lines() const
{
    if (fill_color().visibility())
        fl_color(fill_color().as_int());

    if (color().visibility())
    {
        fl_color(color().as_int());
        Point p1, p2;
        double angleRad = 2 * M_PI / s; // Calculate the angle between each side

        for (int i = 0; i < s; ++i)
        {
            p1.x = point(0).x + d * std::cos(angleRad * i);
            p1.y = point(0).y + d * std::sin(angleRad * i);

            p2.x = point(0).x + d * std::cos(angleRad * (i + 1));
            p2.y = point(0).y + d * std::sin(angleRad * (i + 1));

            fl_line(p1.x, p1.y, p2.x, p2.y);
        }
    }
}



void example(Simple_window &win)
{
    Regular_polygon i(Point{400,300}, 50, 11);
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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex10_Regular_polygon.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
