#include "Simple_window.h"
#include "Graph.h"
#include <vector>

struct Poly : Shape
{
    Poly(vector<Point> i);
    void draw_lines() const;

    // int distance() const { return d; }

private:
    vector<Point> PointList;
};

Poly::Poly(vector<Point> i) : PointList(i)
{
    if (i.size() <= 2)
        throw std::runtime_error("more points needed");
    // add(i[0]);
}

void Poly::draw_lines() const
{

    if (color().visibility())
    {
        fl_color(fill_color().as_int());

        fl_line_style(FL_SOLID, 2); 
        // Draw lines
        fl_color(color().as_int());
        for (int i = 0; i < PointList.size() - 1; ++i)
            fl_line(PointList[i].x, PointList[i].y, PointList[i + 1].x, PointList[i + 1].y);
        fl_line(PointList[PointList.size() - 1].x, PointList[PointList.size() - 1].y, PointList[0].x, PointList[0].y);

        fl_line_style(FL_SOLID); 
        // Fill color
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for (int i = 0; i < PointList.size(); ++i)
            fl_vertex(PointList[i].x, PointList[i].y);
        fl_end_complex_polygon();
    }
}

void example(Simple_window &win)
{

    vector<Point> points = {Point{100, 100}, Point{100, 200}, Point{300, 200}, Point{200, 100}};
    Poly i(points);
    i.set_color(Color::blue);          
    i.set_fill_color(Color::yellow);   
    win.attach(i);

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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex18_Poly.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
