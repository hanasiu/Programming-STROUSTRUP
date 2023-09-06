#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

struct Distribution
{
    int year, young, middle, old;
};

istream &
operator>>(istream &is, Distribution &d)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3)
    {
        if (ch1 != '(' || ch2 != ':' || ch3 != ')')
        {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
        return is;
    d = dd;
    return is;
}

class Scale
{
    int cbase;
    int vbase;
    double scale;

public:
    Scale(int b, int vb, double s) : cbase{b}, vbase{vb}, scale{s} {}
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

void drill3()
{

        constexpr int xmax = 600; // window size
    constexpr int ymax = 400;
    constexpr int xoffset = 100; // distance from left-hand side of window to y axis
    constexpr int yoffset = 60;  // distance from bottom of window to x axis
    constexpr int xspace = 40;   // space beyond axis
    constexpr int yspace = 40;
    constexpr int xlength = xmax-xoffset-xspace; // length of axes//600-100-40
    constexpr int ylength = ymax-yoffset-yspace;
    constexpr int base_year = 1960;
    constexpr int end_year = 2040;
    constexpr double xscale = double(xlength) / (end_year-base_year);
    constexpr double yscale = double(ylength) / 100;


    Simple_window win{Point{0, 0}, xmax, ymax, "Aging Japan"};
    string file_name = "japanese-age-data.txt";
    ifstream ifs{file_name};
    // if (!ifs)
    //     error("can't open ", file_name);
    // // . . .
    // for (Distribution d; ifs >> d;)
    // {
    //     if (d.year < base_year || end_year < d.year)
    //         error("year out of range");
    //     if (d.young + d.middle + d.old != 100)
    //         error("percentages don't add up"); // . . .
    // }

    Scale xs{xoffset, base_year, xscale};
    Scale ys{ymax-yoffset, 0,-yscale};
//    Axis(Orientation d, Point xy, int length,
//        int number_of_notches=0, string label = "");
    Axis x{Axis::x, Point{xoffset, ymax-yoffset}, xlength, (end_year-base_year) / 10,
           "year    1960      1970       1980       1990       "
           "2000       2010       2020       2030      2040"};
    x.label.move(-200, 0);
    Axis y{Axis::y, Point{xoffset, ymax-yoffset}, ylength, 10, "% of population"};
    Line current_year{Point{xs(2008), ys(0)}, Point{xs(2008), ys(100)}};
    current_year.set_style(Line_style::dash);

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;
    for (Distribution d; ifs >> d;)
    {
        if (d.year < base_year || end_year < d.year)
            error("year out of range");
        if (d.young + d.middle + d.old != 100)
            error("percentages don't add up");
        const int x = xs(d.year);
        children.add(Point{x, ys(d.young)});
        adults.add(Point{x, ys(d.middle)});
        aged.add(Point{x, ys(d.old)});
    }

    Text children_label{Point{20, children.point(0).y}, "age 0-14"};
    children.set_color(Color::red);
    children_label.set_color(Color::red);
    Text adults_label{Point{20, adults.point(0).y}, "age 15-64"};
    adults.set_color(Color::blue);
    adults_label.set_color(Color::blue);
    Text aged_label{Point{20, aged.point(0).y}, "age 65+"};
    aged.set_color(Color::dark_green);
    aged_label.set_color(Color::dark_green);

    win.attach(children);
    win.attach(adults);
    win.attach(aged);
    win.attach(children_label);
    win.attach(adults_label);
    win.attach(aged_label);
    win.attach(x);
    win.attach(y);
    win.attach(current_year);
    gui_main();
    win.wait_for_button();
}

int main()
{
    drill3();
    return 0;
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp book_code3.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
