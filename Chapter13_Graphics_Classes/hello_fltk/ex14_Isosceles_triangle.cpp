#include "Simple_window.h"
#include "Graph.h"

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


// void Isosceles_triangle::draw_lines() const
// {
//     if (color().visibility())
//     {
//         fl_color(color().as_int());
//         Point p1, p2, p3;

//         double angleRad = 2 * M_PI * d / 360.0; // Convert direction to radians

//         p1 = point(0); // Vertex with the specified angle

//         p2.x = p1.x + s * std::cos(angleRad + M_PI * a / 180.0); // Calculate the second vertex using angle
//         p2.y = p1.y + s * std::sin(angleRad + M_PI * a / 180.0);

//         p3.x = p1.x + s * std::cos(angleRad - M_PI * a / 180.0); // Calculate the third vertex using angle
//         p3.y = p1.y + s * std::sin(angleRad - M_PI * a / 180.0);

//         fl_line(p1.x, p1.y, p2.x, p2.y);
//         fl_line(p1.x, p1.y, p3.x, p3.y);
//         fl_line(p2.x, p2.y, p3.x, p3.y);
        
//         if (fill_color().visibility())
//         {
//             fl_color(fill_color().as_int());
//             fl_begin_polygon();
//             fl_vertex(p1.x, p1.y);
//             fl_vertex(p2.x, p2.y);
//             fl_vertex(p3.x, p3.y);
//             fl_end_polygon();
//         }
//     }
// }

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
    int side_length = 100;
    int angle_degrees = 22.5;

    Isosceles_triangle t1(Point{400, 300}, side_length, angle_degrees, 0);
    Isosceles_triangle t2(Point{400, 300}, side_length, angle_degrees, 45);
    Isosceles_triangle t3(Point{400, 300}, side_length, angle_degrees, 90);
    Isosceles_triangle t4(Point{400, 300}, side_length, angle_degrees, 135);
    Isosceles_triangle t5(Point{400, 300}, side_length, angle_degrees, 180);
    Isosceles_triangle t6(Point{400, 300}, side_length, angle_degrees, 225);
    Isosceles_triangle t7(Point{400, 300}, side_length, angle_degrees, 270);
    Isosceles_triangle t8(Point{400, 300}, side_length, angle_degrees, 315);


    t1.set_fill_color(Color{166});
    t2.set_fill_color(Color{177});
    t3.set_fill_color(Color{134});
    t4.set_fill_color(Color{150});
    t5.set_fill_color(Color{180});
    t6.set_fill_color(Color{210});
    t7.set_fill_color(Color{240});
    t8.set_fill_color(Color{111});
    win.attach(t1);
    win.attach(t2);
    win.attach(t3);
    win.attach(t4);
    win.attach(t5);
    win.attach(t6);
    win.attach(t7);
    win.attach(t8);

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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex14_Isosceles_triangle.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
