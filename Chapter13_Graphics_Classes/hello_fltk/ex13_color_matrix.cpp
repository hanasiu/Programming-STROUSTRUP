#include "Simple_window.h"
#include "Graph.h"

void example(Simple_window &win)
{
    Vector_ref<Rectangle> vr;

    for(int i = 0; i<16; ++i) {
        for(int j = 0; j<16; ++j) {
            vr.push_back(new Rectangle{Point{i*20, j*20}, 20, 20});
            vr[vr.size()-1].set_fill_color(Color{i*16+j});
            vr[vr.size()-1].set_color(Color::invisible);
            win.attach(vr[vr.size()-1]);
        }
    }

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    Simple_window win(Point{100, 100}, 800, 600, "My Window");

    example(win);
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex13_color_matrix.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
