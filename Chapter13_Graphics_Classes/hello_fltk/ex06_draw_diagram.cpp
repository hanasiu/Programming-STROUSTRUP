#include "Simple_window.h"
#include "Graph.h"
#include "ex03_Arrow.cpp";

struct Box : Shape
{
    Box(Point xy, int ww, int hh, const string& lbl);
    Box(Point x, Point y, const string& lbl);
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }

private:
    int h;
    int w;
    Text label;
};

Box::Box(Point xy, int ww, int hh, const string& lbl) : w(ww), h(hh), label(xy, lbl)
{
    if (h <= 0 || w <= 0)
        throw std::runtime_error("Invalid box size");
    add(xy);
}

Box::Box(Point x, Point y, const string& lbl) : w(y.x - x.x), h(y.y - x.y), label(x, lbl)
{
    if (h <= 0 || w <= 0)
        throw std::runtime_error("Invalid box size");
    add(x);
}

void Box::draw_lines() const
{
     const int radius = std::min(w, h) / 4;  // Increase the radius for a more rounded appearance

    if (fill_color().visibility())
    {
        // fill box by two rectangles and four quarter circles.
        fl_color(fill_color().as_int());
        fl_rectf(point(0).x + radius, point(0).y, w - radius * 2, h);
        fl_rectf(point(0).x, point(0).y + radius, w, h - radius * 2);
        fl_pie(point(0).x, point(0).y, radius + radius, radius + radius, 90, 180);
        fl_pie(point(0).x + w - radius * 2, point(0).y, radius + radius, radius + radius, 0, 90);
        fl_pie(point(0).x, point(0).y + h - radius * 2, radius + radius, radius + radius, 180, 270);
        fl_pie(point(0).x + w - radius * 2, point(0).y + h - radius * 2, radius + radius, radius + radius, 270, 360);
    }

    if (color().visibility())
    {
        // Draw horizontal lines
        fl_line(point(0).x + radius, point(0).y, point(0).x + w - radius, point(0).y);
        fl_line(point(0).x + radius, point(0).y + h, point(0).x + w - radius, point(0).y + h);

        // Draw vertical lines
        fl_line(point(0).x, point(0).y + radius, point(0).x, point(0).y + h - radius);
        fl_line(point(0).x + w, point(0).y + radius, point(0).x + w, point(0).y + h - radius);

        // Draw arcs
        fl_arc(point(0).x, point(0).y, radius + radius, radius + radius, 90, 180);
        fl_arc(point(0).x + w - radius * 2, point(0).y, radius + radius, radius + radius, 0, 90);
        fl_arc(point(0).x, point(0).y + h - radius * 2, radius + radius, radius + radius, 180, 270);
        fl_arc(point(0).x + w - radius * 2, point(0).y + h - radius * 2, radius + radius, radius + radius, 270, 360);
    }
    if (label.color().visibility())
    {
        const int label_width = fl_width(label.label().c_str());
        const int label_x = point(0).x + w / 2 - label_width / 2;
        const int label_y = point(0).y + h / 2 + fl_height() / 4;

        fl_color(label.color().as_int());

        // Set the position and draw the label
        fl_draw(label.label().c_str(), label_x, label_y);
    }
}

void example(Simple_window &win)
{
    // Create a box object
    Box box(Point{100, 100}, 90, 60, "^^");
    box.set_fill_color(Color::green);
    Box box1(Point{100,300}, 90, 60, "ㅠㅠ");
    box1.set_fill_color(Color::green);

    // Attach the box to the window
    win.attach(box);
    win.attach(box1);

    Arrow a(Point{ 145, 300 }, Point{ 145, 160 });
    a.set_color(Color::red);
    // Attach the arrow to the window
    win.attach(a);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    // Create a window
    Simple_window win(Point{100, 100}, 800, 600, "My Window");

    // Call the drill_05 function
    example(win);

    return 0;
}
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex06_draw_diagram.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
