#include "Simple_window.h"
#include "Graph.h"
#include <vector>
#include <random>

enum Points
{
    FIVE,
    SIX
};

struct Star : Shape
{
    Star(Point xy, Points star_point, int d);
    void draw_lines() const;

    int distance() const { return d; }

private:
    Points star_point;
    int d;
};

Star::Star(Point xy, Points star_point, int d) : star_point(star_point), d(d)
{
    if (d <= 0)
        throw std::runtime_error("too short");

    // Add the center point
    add(xy);
}

void Star::draw_lines() const
{
    if (color().visibility())
    {
        fl_color(color().as_int());

        std::vector<Point> star_points;
        Point center = point(0);

        int inner_points = (star_point == FIVE) ? 5 : 6;
        int outer_points = (star_point == FIVE) ? 5 : 6;

        double angle = (star_point == FIVE) ? 360.0 / (inner_points + outer_points) : 360.0 / (inner_points * 2);
        double startAngle = 0;

        // Calculate inner and outer points alternately
        for (int i = 0; i < inner_points; ++i)
        {
            int inner_x = center.x + int(d * cos(startAngle * M_PI / 180.0));
            int inner_y = center.y + int(d * sin(startAngle * M_PI / 180.0));
            star_points.push_back(Point{inner_x, inner_y});

            int outer_x = center.x + int((d * 2) * cos((startAngle + angle) * M_PI / 180.0));
            int outer_y = center.y + int((d * 2) * sin((startAngle + angle) * M_PI / 180.0));
            star_points.push_back(Point{outer_x, outer_y});

            startAngle += 2 * angle;
        }
        fl_line_style(FL_SOLID, 2);
        // Draw lines
        for (int i = 0; i < inner_points * 2 - 1; ++i)
        {
            fl_line(star_points[i].x, star_points[i].y, star_points[i + 1].x, star_points[i + 1].y);
        }
        fl_line(star_points[star_points.size() - 1].x, star_points[star_points.size() - 1].y, star_points[0].x, star_points[0].y);
        fl_line_style(FL_SOLID);
        // Fill color
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for (const auto &p : star_points)
            fl_vertex(p.x, p.y);
        fl_end_complex_polygon();
    }
}

void example(Simple_window &win)
{
    std::random_device rd;                       // Obtain a random seed from the hardware
    std::mt19937 gen(rd());                      // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(5, 170); // Define the range

    const int length = 30;
    const int window_w = 1600;
    const int window_v = 700;

    Vector_ref<Star> tiles;
    for (int i = 50; i < window_w - 200; i += length * 8)
    {
        for (int j = 50; j < window_v; j += length * 4)
        {
            tiles.push_back(new Star(Point{i, j}, SIX, length));
            tiles[tiles.size() - 1].set_fill_color(Color{dis(gen)});
            tiles[tiles.size() - 1].set_color(Color{dis(gen)});
            win.attach(tiles[tiles.size() - 1]);

            tiles.push_back(new Star(Point{i + 120, j}, FIVE, length));
            tiles[tiles.size() - 1].set_fill_color(Color{dis(gen)});
            tiles[tiles.size() - 1].set_color(Color{dis(gen)});
            win.attach(tiles[tiles.size() - 1]);
        }
    }

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    // Create a window
    Simple_window win(Point{0, 0}, 1600, 700, "My Window");

    example(win);

    return 0;
}
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex19_Star.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
