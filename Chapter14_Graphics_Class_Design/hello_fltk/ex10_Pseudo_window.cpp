#include "Simple_window.h"
#include "Graph.h"
#include <Fl_Button.H>

using namespace Graph_lib;

struct Box : Shape
{
    Box(Point xy, int ww, int hh);
    Box(Point x, Point y);
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }

private:
    int h;
    int w;
};

Box::Box(Point xy, int ww, int hh) : w(ww), h(hh)
{
    if (h <= 0 || w <= 0)
        throw std::runtime_error("Invalid box size");
    add(xy);
}

Box::Box(Point x, Point y) : w(y.x - x.x), h(y.y - x.y)
{
    if (h <= 0 || w <= 0)
        throw std::runtime_error("Invalid box size");
    add(x);
}

void Box::draw_lines() const
{
    const int radius = std::min(w, h) / 4; // Increase the radius for a more rounded appearance

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
}

struct Pseudo_window : Box
{
    Pseudo_window(Point xy, int ww, int hh, const string &label);

    void draw_lines() const override;
    // void draw_contents() const;

    // private:
    //     string window_label;
};

Pseudo_window::Pseudo_window(Point xy, int ww, int hh, const string &label)
    : Box(xy, ww, hh)
{
    set_fill_color(Color::white);
    set_color(Color::black);
}

void Pseudo_window::draw_lines() const
{
    Box::draw_lines();

    Point close_top_left{point(0).x + width() - 20, point(0).y + 5};
    Point close_bottom_right{point(0).x + width() - 5, point(0).y + 20};
    Rectangle close_button(close_top_left, close_bottom_right);
    close_button.set_fill_color(Color::red); // Set the color of the close button
    close_button.draw_lines();

    Point minimize_top_left{point(0).x + width() - 40, point(0).y + 5};
    Point minimize_bottom_right{point(0).x + width() - 25, point(0).y + 20};
    Rectangle minimize_button(minimize_top_left, minimize_bottom_right);
    minimize_button.set_fill_color(Color::yellow); // Set the color of the minimize button
    minimize_button.draw_lines();

    Point maximize_top_left{point(0).x + width() - 60, point(0).y + 5};
    Point maximize_bottom_right{point(0).x + width() - 45, point(0).y + 20};
    Rectangle maximize_button(maximize_top_left, maximize_bottom_right);
    maximize_button.set_fill_color(Color::green); // Set the color of the maximize button
    maximize_button.draw_lines();

    Text i({point(0).x + width() / 3, point(0).y - 5}, "Pseudo window");
    i.draw_lines();
}

void example(Simple_window &win)
{
    Pseudo_window pseudo_win{Point{100, 100}, 400, 300, "Pseudo Window"};

    // Add the Pseudo_window to the Simple_window
    win.attach(pseudo_win);

    // Add contents to the Pseudo_window
    // pseudo_win.draw_contents();

    win.wait_for_button();
}

int main()
{
    // Create a window
    Simple_window win(Point{100, 100}, 800, 600, "My Window");

    example(win);

    return 0;
}
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex10_Pseudo_window.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
