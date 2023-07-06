#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace std;

class Immobile_Circle : public Circle
{
public:
    Immobile_Circle(Point center, int radius)
        : Circle(center, radius)
    {
    }

    void move(int dx, int dy) override;

private:
    //using Circle::move; // this is possible solution with compile time error;
};

void Immobile_Circle::move(int dx, int dy)
{
    cerr << "Do not move this immobile circle" << endl;
}

void example(Simple_window &win)
{
    Immobile_Circle i(Point{400, 300}, 50);
    i.move(100, 100);
    win.attach(i);

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
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex04_Immobile_Circle.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
