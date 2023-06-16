#include "Simple_window.h"
#include "Graph.h"
#include <random>

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
        throw std::runtime_error("Invalid size");
    add(xy);
}


void Regular_hexagon::draw_lines() const
{
    const int distance = d;

    if (color().visibility())
    {
        fl_color(fill_color().as_int());
        Point center = point(0);

        // Calculate the coordinates of the six vertices of the regular hexagon
        Point p1{center.x - distance, center.y};
        Point p2{center.x - distance / 2, center.y - int(distance * std::sqrt(3) / 2)};
        Point p3{center.x + distance / 2, center.y - int(distance * std::sqrt(3) / 2)};
        Point p4{center.x + distance, center.y};
        Point p5{center.x + distance / 2, center.y + int(distance * std::sqrt(3) / 2)};
        Point p6{center.x - distance / 2, center.y + int(distance * std::sqrt(3) / 2)};

        fl_begin_polygon(); // Use simple polygon

        fl_vertex(p1.x, p1.y); // Add vertices
        fl_vertex(p2.x, p2.y);
        fl_vertex(p3.x, p3.y);
        fl_vertex(p4.x, p4.y);
        fl_vertex(p5.x, p5.y);
        fl_vertex(p6.x, p6.y);

        fl_end_polygon();
    }
}


void example(Simple_window &win)
{
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(5, 170);  // Define the range

    const int length = 50;
    const int window_w = 1600;
    const int window_v = 700;

    Vector_ref<Regular_hexagon> tiles;
    for(int i = 50; i<window_w-200; i+=length*2) {
       for (int j = 50; j < window_v; j += (length * std::sqrt(3))) {
            tiles.push_back(new Regular_hexagon(Point{i, j}, length));
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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex16_Hexagon_tile.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
