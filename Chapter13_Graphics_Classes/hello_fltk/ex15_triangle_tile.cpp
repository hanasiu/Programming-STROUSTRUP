#include "Simple_window.h"
#include "Graph.h"
#include <random>

struct Isosceles_triangle: Shape
{
    Isosceles_triangle(Point xy, int s, int a, int d);
    void draw_lines() const;

    int direction() const { return d; }
    int side() const { return s; }
    int angle() const { return a; }

private:
    int s;
    int a;
    int d;
};

Isosceles_triangle::Isosceles_triangle(Point xy, int ss, int aa, int dd) : s(ss), a(aa), d(dd)
{
    if (d < 0 || d > 360)
        throw std::runtime_error("Invalid direction");
    if (s >= 1000)
        throw std::runtime_error("Side is too long");
    if (a >= 180)
        throw std::runtime_error("Invalid angle");
    add(xy);
}


void Isosceles_triangle::draw_lines() const
{
    if (fill_color().visibility()) // Draw only if fill color is visible
    {
        fl_color(fill_color().as_int());
        Point p1, p2, p3;

        double angleRad = 2 * M_PI * d / 360.0; // Convert direction to radians

        p1 = point(0); // Vertex with the specified angle

        p2.x = p1.x + s * std::cos(angleRad + M_PI * a / 180.0); // Calculate the second vertex using angle
        p2.y = p1.y + s * std::sin(angleRad + M_PI * a / 180.0);

        p3.x = p1.x + s * std::cos(angleRad - M_PI * a / 180.0); // Calculate the third vertex using angle
        p3.y = p1.y + s * std::sin(angleRad - M_PI * a / 180.0);

        fl_begin_polygon(); // Use simple polygon

        fl_vertex(p1.x, p1.y); // Add vertices
        fl_vertex(p2.x, p2.y);
        fl_vertex(p3.x, p3.y);

        fl_end_polygon();
    }
}



void example(Simple_window &win)
{
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(5, 170);  // Define the range

    const int side_length = 50;
    const int angle_degrees = 45;
    const int window_w = 1600;
    const int window_v = 700;

    Vector_ref<Isosceles_triangle> tiles;
    for(int i = 0; i<window_w; i+=side_length) {
        for(int j = 0; j<window_v; j+=side_length) {
            tiles.push_back(new Isosceles_triangle{Point{i, j}, side_length, angle_degrees, 45});
            tiles[tiles.size()-1].set_fill_color(Color{dis(gen)});
            win.attach(tiles[tiles.size()-1]);
            tiles.push_back(new Isosceles_triangle{Point{50+i,50+j}, side_length, angle_degrees, 225});
            tiles[tiles.size()-1].set_fill_color(Color{dis(gen)});
            win.attach(tiles[tiles.size()-1]);
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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex15_triangle_tile.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
