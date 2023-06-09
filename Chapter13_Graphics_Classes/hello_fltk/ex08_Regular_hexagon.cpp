#include "Simple_window.h"
#include "Graph.h"

struct Regular_hexagon : Shape
{
    Regular_hexagon(Point xy, int d);
    void draw_lines() const;

    int distance() const { return d; }

private:
    int d;
};

Regular_hexagon::Regular_hexagon(Point xy, int dd) : d(dd)
{
    if (d <= 0)
        throw std::runtime_error("Invalid box size");
    add(xy);
}

void Regular_hexagon::draw_lines() const
{
    const int distance = d;

    if (fill_color().visibility())
    {
        fl_color(fill_color().as_int());
    }

    if (color().visibility())
    {

        fl_color(color().as_int());
        Point p1, p2;
        double angleRad;

        for (int i = 0; i < 6; ++i)
        {
            angleRad = 2 * M_PI / 6 * i;
            p1.x = point(0).x + distance * std::cos(angleRad);
            p1.y = point(0).y + distance * std::sin(angleRad);

            angleRad = 2 * M_PI / 6 * (i + 1);
            p2.x = point(0).x + distance * std::cos(angleRad);
            p2.y = point(0).y + distance * std::sin(angleRad);

            fl_line(p1.x, p1.y, p2.x, p2.y);
        }
    }
}

void example(Simple_window &win)
{
    Vector_ref<Regular_hexagon> hexagon_vector;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            hexagon_vector.push_back(new Regular_hexagon{Point{i * 30 + 100, j * 26 + 100}, 15});
            hexagon_vector[hexagon_vector.size() - 1].set_color(Color::yellow);
            win.attach(hexagon_vector[hexagon_vector.size() - 1]);
        }
    }

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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex08_Regular_hexagon.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
