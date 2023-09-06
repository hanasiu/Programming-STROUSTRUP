#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib; // our graphics facilities are in Graph_lib (defined in Graph.h)

int fac(int n)
{
    int r = 1;
    while (n > 1)
    {
        r *= n;
        --n;
    }
    return r;
}
double term(double x, int n) { return pow(x, n) / fac(n); }

double expe(double x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += term(x, i);
    return sum;
}

void drill_02()
{
    constexpr int xmax = 1200;
    constexpr int ymax = 800;
    Simple_window win{Point{100, 100}, xmax, ymax, "Function graphing"};
    constexpr int x_orig = xmax / 2;
    constexpr int y_orig = ymax / 2;
    constexpr Point orig{x_orig, y_orig};
    constexpr int r_min = -10;
    constexpr int r_max = 11;
    constexpr int n_points = 400;
    constexpr int x_scale = 50;
    constexpr int y_scale = 50;
    constexpr int xlength = xmax - 40;
    constexpr int ylength = ymax - 40;
    Axis x{Axis::x, Point{20, y_orig}, xlength, xlength / x_scale, "one notch == 1"};
    Axis y{Axis::y, Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
    // range [-10:11)
    // number of points used in range // scaling factors

    Function real_exp{exp, r_min, r_max, orig, 200, x_scale, y_scale};
    real_exp.set_color(Color::blue);
    win.attach(real_exp);
    for (int n = 0; n < 50; ++n)
    {
        ostringstream ss;
        ss << "exp approximation; n==" << n;
        win.set_label(ss.str());
        Function e{[n](double x)
                   { return expe(x, n); },
                   r_min, r_max, orig, 200, x_scale, y_scale};
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }
}

int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    // Point top_left{0, 0}; // will be top left corner of window
    // Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};
    // g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp book_code.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
    drill_02();
    return 0;
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp book_code2.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
