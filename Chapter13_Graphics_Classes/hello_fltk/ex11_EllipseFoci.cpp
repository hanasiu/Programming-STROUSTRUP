#include "Simple_window.h"
#include "Graph.h"


Point n (const Ellipse& e)
{
    int x = e.center().x;
    int y = e.center().y - e.minor();

    return Point{x, y};
}

Point s (const Ellipse& e)
{
    int x = e.center().x;
    int y = e.center().y + e.minor();

    return Point{x, y};
}

Point e (const Ellipse& e)
{
    int x = e.center().x + e.major();
    int y = e.center().y;

    return Point{x, y};
}

Point w (const Ellipse& e)
{
    int x = e.center().x - e.major();
    int y = e.center().y;

    return Point{x, y};
}


Point nw (const Ellipse& e)
{
    int x = e.center().x - e.major();
    int y = e.center().y - e.minor();

    return Point{x, y};
}

Point ne (const Ellipse& e)
{
    int x = e.center().x + e.major();
    int y = e.center().y - e.minor();

    return Point{x, y};
}

Point sw (const Ellipse& e)
{
    int x = e.center().x - e.major();
    int y = e.center().y + e.minor();

    return Point{x, y};
}

Point se (const Ellipse& e)
{
    int x = e.center().x + e.major();
    int y = e.center().y - e.minor();

    return Point{x, y};
}

// Point center(const Ellipse& e)
// {
    //library Ellipse has center() function
// }

void example(Simple_window& win) {
    Ellipse ellipse{Point{400,300},150,100};
    win.attach(ellipse);
    Text N {Point{n(ellipse)}, "n: " + to_string(n(ellipse).x) + ", " + to_string(n(ellipse).y)};
    win.attach(N);
    Text S {Point{s(ellipse)}, "s: " + to_string(s(ellipse).x) + ", " + to_string(s(ellipse).y)};
    win.attach(S);
    Text E {Point{e(ellipse)}, "e: " + to_string(e(ellipse).x) + ", " + to_string(e(ellipse).y)};
    win.attach(E);
    Text W {Point{w(ellipse)}, "w: " + to_string(w(ellipse).x) + ", " + to_string(w(ellipse).y)};
    win.attach(W);

    Line horizontal{Point{200,300},Point{600,300}};
    win.attach(horizontal);
    Line vertical{Point{400,150},Point{400,450}};
    win.attach(vertical);
// Calculate the foci
    double a = ellipse.major()/2.0;
    double b = ellipse.minor()/2.0;
    double e = std::sqrt(1.0 - (b * b) / (a * a));
    Point focus1{ellipse.center().x + static_cast<int>(a * e), ellipse.center().y};
    Point focus2{ellipse.center().x - static_cast<int>(a * e), ellipse.center().y};

    // Display the foci
    Circle foci1{focus1, 3};  // Adjust the size of the circle as needed
    foci1.set_fill_color(Color::red);  // Set the fill color of the circle
    win.attach(foci1);

    Circle foci2{focus2, 3};  // Adjust the size of the circle as needed
    foci2.set_fill_color(Color::red);  // Set the fill color of the circle
    win.attach(foci2);

    // Display the coordinates of the foci
    Text F1{Point{focus1}, to_string(Point{focus1}.x) + ", " + to_string(Point{focus1}.y)};
    F1.set_color(Color::red);  // Set the color of the text
    win.attach(F1);

    Text F2{Point{focus2}, to_string(Point{focus2}.x) + ", " + to_string(Point{focus2}.y)};
    F2.set_color(Color::red);  // Set the color of the text
    win.attach(F2);
    

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main() {
    Simple_window win(Point{ 100, 100 }, 800, 600, "My Window");

    example(win);
}

//g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex11_EllipseFoci.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
