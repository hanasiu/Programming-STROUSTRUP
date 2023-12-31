#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace std;

class Smiley : public Circle {
public:
    Smiley(Point p, int rr) : Circle(p, rr) {}
    void draw_lines() const;
};

void Smiley::draw_lines() const {
    // Call the base class draw_lines() to draw the circle
    Circle::draw_lines();

    // Calculate the eye positions relative to the center of the circle
    int eye_x = center().x - radius() / 3;
    int eye_y = center().y - radius() / 3;

    // Draw the eyes as small Circles
    fl_arc(eye_x, eye_y, radius() / 6, radius() / 6, 0, 360);
    fl_arc(eye_x + radius()*2/3, eye_y, radius() / 6, radius() / 6, 0, 360);

    // Draw the smile as an arc
    int smile_x = center().x - radius() / 2;
    int smile_y = center().y + radius() / 4;
    int smile_width = radius();
    int smile_height = radius() / 2;
    fl_arc(smile_x, smile_y, smile_width, smile_height, 180, 360);
}


class Frowny : public Circle {
public:
    Frowny(Point p, int rr) : Circle(p, rr) {}
    void draw_lines() const;
};

void Frowny::draw_lines() const {
    // Call the base class draw_lines() to draw the circle
    Circle::draw_lines();

    // Calculate the eye positions relative to the center of the circle
    int eye_x = center().x - radius() / 3;
    int eye_y = center().y - radius() / 3;

    // Draw the eyes as small Circles
    fl_arc(eye_x, eye_y, radius() / 6, radius() / 6, 0, 360);
    fl_arc(eye_x + radius()*2/3, eye_y, radius() / 6, radius() / 6, 0, 360);

    // Draw the smile as an arc
    int frown_x = center().x - radius() / 2;
    int frown_y = center().y + radius() / 4;
    int frown_width = radius();
    int frown_height = radius() / 2;
    fl_arc(frown_x, frown_y, frown_width, frown_height, 0, 180);
}

void example(Simple_window &win)
{
    Frowny i(Point{400,300}, 50);
    win.attach(i);
    
    Smiley j(Point{500,500}, 50);
    win.attach(j);

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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex01_Circle_Derived.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
