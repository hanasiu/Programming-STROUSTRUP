#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace std;

class Octagon : public Shape
{
public:
    Octagon(Point center, int r);

    int distance() const { return r; }
    void draw_lines() const;

private:
    int r;
};

Octagon::Octagon(Point xy, int rr) : r(rr)
{
    if (r <= 0)
        throw std::runtime_error("Invalid size");
    add(xy);
}

void Octagon::draw_lines() const
{
    if (fill_color().visibility())
    {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for (int angle = 0; angle < 360; angle += 360 / 8)
        {
            int x = point(0).x + distance() * cos(angle * M_PI / 180);
            int y = point(0).y + distance() * sin(angle * M_PI / 180);
            fl_vertex(x, y);
        }
        fl_end_complex_polygon();
    }

    if (color().visibility())
    {
        fl_color(color().as_int());
        Point center = point(0); // Get the xy point as the center

        // Calculate the vertices of the octagon
        vector<Point> vertices;
        for (int angle = 0; angle < 360; angle += 360 / 8)
        {
            int x = center.x + distance() * cos(angle * M_PI / 180);
            int y = center.y + distance() * sin(angle * M_PI / 180);
            vertices.push_back(Point{x, y});
        }

        // Draw lines between the vertices
        for (size_t i = 0; i < vertices.size(); ++i)
        {
            size_t j = (i + 1) % vertices.size();
            fl_line(vertices[i].x, vertices[i].y, vertices[j].x, vertices[j].y);
        }
    }
}

// void example(Simple_window &win)
// {
//     Octagon i(Point{100, 100}, 50);
//     i.set_color(Color::blue);
//     i.set_fill_color(Color::green);
//     win.attach(i);

//     win.set_label("Canvas #1");
//     win.wait_for_button();
// }

// int main()
// {
//     // Create a window
//     Simple_window win(Point{100, 100}, 800, 600, "My Window");

//     example(win);

//     return 0;
// }
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex08_Octagon.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
