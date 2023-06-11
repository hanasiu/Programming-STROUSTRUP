#include "Simple_window.h"
#include "Graph.h"

void example(Simple_window &win)
{

    Circle circle{Point{400, 200}, 150};
    win.attach(circle);
    Circle first{Point{550, 200}, 3};
    win.attach(first);

    int angle = 0;

    while (angle <= 360000)
    {
        int x = circle.center().x + static_cast<int>(circle.radius() * cos(angle * M_PI / 180));
        int y = circle.center().y + static_cast<int>(circle.radius() * sin(angle * M_PI / 180));

        first.move(x - first.center().x, y - first.center().y);
        angle += 15;
        win.wait_for_button();
    }

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    Simple_window win(Point{100, 100}, 800, 600, "My Window");

    example(win);
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex12_AroundCircle.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
