#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib; // our graphics facilities are in Graph_lib (defined in Graph.h)

void drill(Simple_window &win)
{
    Lines grid;
    for (int x = 100; x <= 800; x += 100)
    {
        grid.add(Point{x, 0}, Point{x, 800});
    }
    for (int y = 100; y <= 800; y += 100)
    {
        grid.add(Point{0, y}, Point{800, y});
    }
    win.attach(grid);

    Vector_ref<Rectangle> vr;
    for (int x = 0; x <= 700; x += 100)
    {
        vr.push_back(new Rectangle{Point{x, x}, 100, 100});
        vr[vr.size() - 1].set_fill_color(Color::cyan);
        win.attach(vr[vr.size() - 1]);
    }

    Image cpp{Point{0, 300}, "snow_cpp.gif"};
    cpp.set_mask(Point{50, 0}, 200, 200);
    win.attach(cpp);

    Image cpp2{Point{300, 100}, "snow_cpp.gif"};
    cpp2.set_mask(Point{50, 0}, 200, 200);
    win.attach(cpp2);

    Image cpp3{Point{200, 500}, "snow_cpp.gif"};
    cpp3.set_mask(Point{50, 0}, 200, 200);
    win.attach(cpp3);

    Image cpp4{Point{500, 300}, "snow_cpp.gif"};
    cpp4.set_mask(Point{50, 0}, 200, 200);
    win.attach(cpp4);

    int x = 0, y = 0;
    Image rita{Point{y, x}, "rita.jpg"};
    rita.set_mask(Point{50, 100}, 100, 100);
    win.attach(rita);

    for (x = 0; x <= 700; x += 100)
    {
        for (y = 0; y <= 700; y += 100)
        {
            win.wait_for_button();
            rita.move(100, 0);
        }
        rita.move(-800, 100);
        y = 0;
    }
    win.set_label("Canvas #1");
    win.wait_for_button();
}
int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    Point top_left{0, 0}; // will be top left corner of window
    Simple_window win{top_left, 1000, 800, "Canvas"};
    // g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp drill.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
    drill(win);
    return 0;
}
