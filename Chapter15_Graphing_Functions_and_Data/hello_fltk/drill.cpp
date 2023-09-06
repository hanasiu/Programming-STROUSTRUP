#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x) {
     return 1;
}

double slope(double x) {
    return x/2;
}

double square(double x) { return x*x; }

double cos_slope(double x) {
    return(cos(x) + slope(x));
}


void drill()
{
    constexpr int xmax = 600; // window size
    constexpr int ymax = 600;
    Simple_window win{Point{0, 0}, xmax, ymax, "Function graphs"};
    constexpr int xlength = 400; 
    constexpr int ylength = 400;

    Axis x{Axis::x, Point{100, 300}, xlength, 20, ""};
    x.label.move(-200, 0);
    Axis y{Axis::y, Point{300, 500}, ylength, 20, "1 = = 20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    y.label.set_color(Color::black);
    win.attach(x);
    win.attach(y);

    Function one_function{one, -10, 11, Point{300, 300}, 400, 20, 20};
    win.attach(one_function);
    
    Function slope_function{slope, -10, 11, Point{300, 300}, 400, 20, 20};
    win.attach(slope_function);
    Text slope_label {Point{100, 380}, "x/2"};
    win.attach(slope_label);

    Function square_function{square, -10, 11, Point{300, 300}, 400, 20, 20};
    win.attach(square_function);
    
    Function cos_function{cos, -10, 11, Point{300, 300}, 400, 20, 20};
    cos_function.set_color(Color::blue);
    win.attach(cos_function);

    Function cos_slope_function{cos_slope, -10, 11, Point{300, 300}, 400, 20, 20};
    cos_slope_function.set_color(Color::green);
    win.attach(cos_slope_function);
    
    win.wait_for_button();
}

int main()
{
    drill();
    return 0;
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp drill.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
