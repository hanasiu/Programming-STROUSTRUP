#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib; // our graphics facilities are in Graph_lib (defined in Graph.h)

double one(double) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }

double sloping_cos(double x) { return cos(x)+slope(x); }

void drill_01()
{
    constexpr int xmax = 1200;
    constexpr int ymax = 800;
    constexpr int x_orig = xmax / 2;
    constexpr int y_orig = ymax / 2;
    constexpr Point orig{x_orig, y_orig};
    constexpr int r_min = -10;
    constexpr int r_max = 11;
    constexpr int n_points = 400;
    constexpr int x_scale = 50;
    // range [-10:11)
    // number of points used in range // scaling factors
    constexpr int y_scale = 50;
    Simple_window win{Point{100, 100}, xmax, ymax, "Function graphing"};
    Function s{one, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function s2{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function s3{square, r_min, r_max, orig, n_points, x_scale, y_scale};
    win.attach(s);
    win.attach(s2);
    win.attach(s3);

    win.set_label("Function graphing: label functions");

    Text ts{Point{100, y_orig - 40}, "one"};
    Text ts2{Point{100, y_orig + y_orig / 2 - 20}, "x/2"};
    Text ts3{Point{x_orig - 100, 20}, "x*x"};
    win.attach(ts);
    win.attach(ts2);
    win.attach(ts3);
    constexpr int xlength = xmax - 40;
    constexpr int ylength = ymax - 40;
    Axis x{Axis::x, Point{20, y_orig}, xlength, xlength / x_scale, "one notch == 1"};
    Axis y{Axis::y, Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);

    Function s4 { cos, r_min, r_max, orig, 400, x_scale, y_scale};
    s4.set_color(Color::blue);
    win.attach(s4);
    //Function s5 { sloping_cos, r_min, r_max, orig, 400, x_scale, y_scale};
    Function s5 {static_cast<double(*)(double)>([](double x) { return cos(x) + slope(x); }),
     r_min, r_max, orig, 400, x_scale, y_scale};
    s5.set_color(Color::green);
    win.attach(s5);
    

    x.label.move(-160,0);
    x.notches.set_color(Color::dark_red);
    


    Function f1 { log, 0.000001, r_max, orig, 400, x_scale, y_scale};
    //f1.set_color(Color::violet);
    win.attach(f1);
    Function f2 { sin, r_min, r_max, orig, 400, x_scale, y_scale};
    f2.set_color(Color::blue);
    win.attach(f2);
    win.wait_for_button();
    Function f3 { cos, r_min, r_max, orig, 400, x_scale, y_scale};
    f3.set_color(Color::yellow);
    win.attach(f3);
    Function f4 { exp, r_min, r_max, orig, 400, x_scale, y_scale};
    f4.set_color(Color::yellow);
    win.attach(f4);
    

    win.wait_for_button();
}

int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    // Point top_left{0, 0}; // will be top left corner of window
    // Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};
    // g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp book_code.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
    drill_01();
    return 0;
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp book_code.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
